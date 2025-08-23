// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DeokguAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEOKGU_API UDeokguAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:

	//UPROPERTY()
	//class ADeocGuCharacter* player;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "DeokGuAnimSettings")
	float direction = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeokGuAnimSettings")
	float speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeokGuAnimSettings")
	float pitch = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "DeokGuAnimSettings")
	bool isInAir = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "DeokGuAnimSettings")
	bool bIsCrouched = false; 


public:
	UPROPERTY(EditDefaultsOnly, Category = "DeokGuAnimSettings" )
	class UAnimMontage* AttackAnimMontage;

public:
	void PlayAttackAnim();
	
};
