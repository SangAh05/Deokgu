// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ADeocGuCharacter;


/**
 * 
 */
UCLASS()
class DEOKGU_API ADGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ADGPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	UPROPERTY(EditAnywhere, Category = "player")
	class ADeocGuCharacter* me;

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> deocGuContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> lookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> walkAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> runAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> sprintAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> jumpAction;

private:
	void CursorTrace ( );

private:

	UPROPERTY(EditAnywhere, Category = "Move|Trun")
	float minPitch = -60.f;

	UPROPERTY(EditAnywhere, Category = "Move|Trun")
	float maxPitch = 20.f;

	UPROPERTY(EditAnywhere, Category = "Move|Speed")
	float walkSpeed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Move|Speed")
	float runSpeed = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Move|Speed")
	float sprintSpeed = 600.0f;

private:
	UPROPERTY(EditAnywhere, Category = "Move|State")
	bool bIsWalking = false; 

	UPROPERTY(EditAnywhere, Category = "Move|State")
	bool bIsRuning = false;

	UPROPERTY(EditAnywhere, Category = "Move|State")
	bool bIsSprinting = false;

private:
	void DGLook(const FInputActionValue& InputActionValue);
	void DGWalk(const FInputActionValue& InputActionValue);
	void DGRun (const FInputActionValue& InputActionValue);

	void DGSprintStart();
	void DGSprintEnd  ();

	void DGJump();

};
