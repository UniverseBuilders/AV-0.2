#pragma once

#include "GameFramework/SpectatorPawn.h"
#include "avSpectatorPawn.generated.h"

/** AavSpectatorPawn
* This Pawn Will Move Like An RTS Camera
*/
UCLASS()
class AV_API AavSpectatorPawn : public ASpectatorPawn
{
	GENERATED_UCLASS_BODY()

public:
	/** Camera Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		TSubobjectPtr<class UCameraComponent> CameraComponent;

	/** Camera Z Angle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraZAnlge;

	/** Camera Radius From Pawn Position */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraRadius;

	/** Camera Height Angle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraHeightAngle;

	/** Camera Zoom Speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraZoomSpeed;

	/** Camera Radius Max */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraRadiusMax;

	/** Camera Radius Min */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraRadiusMin;

	/** Camera Movement Speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraMovementSpeed;

	/** Camera Scroll Boundary */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraScrollBoundary;

	/** Should the camera move? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		bool bCanMoveCamera;

private:
	/** Sets up player inputs
	*    @param InputComponent - Input Component
	*/
	void SetupPlayerInputComponent(class UInputComponent* InputComponent);

public:
	/** Zooms In The Camera */
	UFUNCTION()
		void ZoomIn();

	/** Zooms Out The Camera */
	UFUNCTION()
		void ZoomOut();

	/** Gets the roatation of the camera with only the yaw value
	* @return - returns a rotator that is (0, yaw, 0) of the Camera
	*/
	UFUNCTION()
		FRotator GetIsolatedCameraYaw();

	/** Moves the camera forward
	* @param direcation - (1.0 for forward, -1.0 for backward)
	*/
	UFUNCTION()
		void MoveCameraForward(float direction);

	/** Moves the camera forward
	* @param direcation - (1.0 for right, -1.0 for left)
	*/
	UFUNCTION()
		void MoveCameraRight(float direction);

	/** Repositions The Camera */
	UFUNCTION()
		void RepositionCamera();

	/** Tick Function, Called Every Frame */
	UFUNCTION()
		virtual void Tick(float deltaSeconds) override;
};