#include "AV.h"
#include "avSpectatorPawn.h"


AavSpectatorPawn::AavSpectatorPawn(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//Disable Standard WASD Movement
	bAddDefaultMovementBindings = false;

	//Set Default Camera Values
	CameraRadius = 1000.0f;
	CameraZAnlge = 0.0f;
	CameraHeightAngle = 70.0f;
	CameraZoomSpeed = 32.0f;
	CameraRadiusMin = 750.0f;
	CameraRadiusMax = 2000.0f;
	CameraMovementSpeed = 2000.0f;
	CameraScrollBoundary = 25.0f;
	//TODO: While selecting units, the camera CANNOT move!
	bCanMoveCamera = true;

	//Intialize The Camera
	CameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("RTS Camera"));
	CameraComponent->AttachParent = this->GetRootComponent();
	CameraComponent->bUsePawnControlRotation = false;
	RepositionCamera();

	//Enable Tick function
	PrimaryActorTick.bCanEverTick = true;
}

void AavSpectatorPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	//Bind Mouse Wheel Zooming Actions
	InputComponent->BindAction("WheelMouseUp", IE_Pressed, this, &AavSpectatorPawn::ZoomIn);
	InputComponent->BindAction("WheelMouseDown", IE_Pressed, this, &AavSpectatorPawn::ZoomOut);

	//Bind WASD Movement
	//FOR TESTING PURPOSES ONLY!!!
	//InputComponent->BindAxis("MoveForward", this, &AavSpectatorPawn::MoveCameraForward);
	//InputComponent->BindAxis("MoveRight", this, &AavSpectatorPawn::MoveCameraRight);
}

void AavSpectatorPawn::ZoomIn()
{
	//Don't execute any further if the camera can't move
	if (!bCanMoveCamera)
		return;

	//Decrease the CameraRadius but clamp it between the min and max radii
	CameraRadius = FMath::Clamp(CameraRadius - CameraZoomSpeed, CameraRadiusMin, CameraRadiusMax);

	//Reposition the camera in the local space
	RepositionCamera();
}

void AavSpectatorPawn::ZoomOut()
{
	//Don't execute any further if the camera can't move
	if (!bCanMoveCamera)
		return;

	//Increase the CameraRadius but clamp it between the min and max radii
	CameraRadius = FMath::Clamp(CameraRadius + CameraZoomSpeed, CameraRadiusMin, CameraRadiusMax);

	//Reposition the camera in the local space
	RepositionCamera();
}

FRotator AavSpectatorPawn::GetIsolatedCameraYaw()
{
	//Return a FRotator containing (0, CameraYaw, 0)
	return FRotator(0.0f, CameraComponent->ComponentToWorld.Rotator().Yaw, 0.0f);
}

void AavSpectatorPawn::MoveCameraForward(float direction)
{
	//Don't execute any further if the camera can't move
	if (!bCanMoveCamera)
		return;

	//Calculate how much to move the camera by
	float movementValue = direction * CameraMovementSpeed;

	//Create a delta vector that moves by the movementValue in the direction of the camera's yaw
	FVector deltaMovement = movementValue * GetIsolatedCameraYaw().Vector();

	//Add the delta to a new vector
	FVector newLocation = this->GetActorLocation() + deltaMovement;

	//Set the new location of the pawn
	SetActorLocation(newLocation);
}

void AavSpectatorPawn::MoveCameraRight(float direction)
{
	//Don't execute any further if the camera can't move
	if (!bCanMoveCamera)
		return;

	//Calculate how much to move the camera by
	float movementValue = direction * CameraMovementSpeed;

	//Create a delta vector that moves by the movementValue in the direction of the right of the camera's yaw
	FVector deltaMovement = movementValue * (FRotator(0.0f, 90.0f, 0.0f) + GetIsolatedCameraYaw()).Vector();

	//Add the delta to a new vector
	FVector newLocation = this->GetActorLocation() + deltaMovement;

	//Set the new location of the pawn
	SetActorLocation(newLocation);
}

void AavSpectatorPawn::RepositionCamera()
{
	//Create variables to hold the new values
	FVector newLocation(0.0f, 0.0f, 0.0f);
	FRotator newRotation(0.0f, 0.0f, 0.0f);

	//Find Cos and Sin of the Camera Z Angle
	float sinCameraZAngle = FMath::Sin(FMath::DegreesToRadians(CameraZAnlge));
	float cosCameraZAngle = FMath::Cos(FMath::DegreesToRadians(CameraZAnlge));

	//Find the Cos and Sin of the Camera Height Angle
	float sinCameraHeightAngle = FMath::Sin(FMath::DegreesToRadians(CameraHeightAngle));
	float cosCameraHeightAngle = FMath::Cos(FMath::DegreesToRadians(CameraHeightAngle));

	//Set newLocation X to cosCameraZAngle * sinCameraHeightAngle * CameraRadius
	newLocation.X = cosCameraZAngle * cosCameraHeightAngle * CameraRadius;

	//Set newLocation Y to sinCameraZangle * sinCameraHeightAngle * CameraRadius
	newLocation.Y = sinCameraZAngle * cosCameraHeightAngle * CameraRadius;

	//Set newLocation Z to cosCameraHeightAngle * CameraRadius
	newLocation.Z = sinCameraHeightAngle * CameraRadius;

	//Set the new rotations
	newRotation = (FVector(0.0f, 0.0f, 0.0f) - newLocation).Rotation();


	//Set the camera's location and rotation to the new values
	CameraComponent->SetRelativeLocation(newLocation);
	CameraComponent->SetRelativeRotation(newRotation);
}

void AavSpectatorPawn::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	//Create variables to hold mouse position and screen size
	FVector2D mousePosition;
	FVector2D viewportSize;

	//Get mouse position and screen size
	UGameViewportClient* gameViewport = GEngine->GameViewport;

	//Make sure viewport exists
	check(gameViewport);
	gameViewport->GetViewportSize(viewportSize);

	//Make sure the viewport has focus(contains the mouse)
	if (gameViewport->IsFocused(gameViewport->Viewport) && gameViewport->GetMousePosition(mousePosition) && bCanMoveCamera)
	{
		//Check if the mouse is at the left or right edge of the screen and move accordingly
		if (mousePosition.X < CameraScrollBoundary)
		{
			MoveCameraRight(-1.0f * deltaSeconds);
		}
		else if (viewportSize.X - mousePosition.X < CameraScrollBoundary)
		{
			MoveCameraRight(1.0f * deltaSeconds);
		}

		//Check if the mouse is at the top or bottom edge of the screen and move accordingly
		if (mousePosition.Y < CameraScrollBoundary)
		{
			MoveCameraForward(1.0f * deltaSeconds);
		}
		else if (viewportSize.Y - mousePosition.Y < CameraScrollBoundary)
		{
			MoveCameraForward(-1.0f * deltaSeconds);
		}
	}
}