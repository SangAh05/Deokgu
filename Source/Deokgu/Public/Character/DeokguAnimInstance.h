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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyAnimSettings")
	float direction = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyAnimSettings")
	float speed = 0.0f;

public:

	UPROPERTY()
	class ADeocGuCharacter* player;
	
};
