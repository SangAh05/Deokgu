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
	virtual void PlayerTick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> DeocGuContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void GDMove ( const FInputActionValue& InputActionValue );


	void CursorTrace();
};
