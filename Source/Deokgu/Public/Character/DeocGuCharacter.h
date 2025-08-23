// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "DeocGuCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEOKGU_API ADeocGuCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	ADeocGuCharacter ( );

	virtual void PossessedBy ( AController* NewController ) override;
	virtual void OnRep_PlayerState ( ) override;

private:
	void InitAbilityActorInfo();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Camera")
	class UCameraComponent* CameraComp;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Camera")
	class USpringArmComponent* SpringArmComp;

	
};
