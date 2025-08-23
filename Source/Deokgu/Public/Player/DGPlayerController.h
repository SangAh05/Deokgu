// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


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

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> DeocGuContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

private:
	void CursorTrace ( );

private:

	/* Movement Variables - Turn */
	UPROPERTY(EditAnywhere, Category = "Move|Default")
	float minPitch = -60.f;

	UPROPERTY(EditAnywhere, Category = "Move|Default")
	float maxPitch = 20.f;

private:
	void GDMove(const FInputActionValue& InputActionValue);

	void GDLook(const FInputActionValue& InputActionValue);

	void GDJump();

};
