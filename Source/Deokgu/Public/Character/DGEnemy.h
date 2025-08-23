// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "DGEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DEOKGU_API ADGEnemy : public ACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()


public:
	ADGEnemy();
	
	/* Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* end Enemy Interface */


	//UPROPERTY(BlueprintReadOnly)
	//bool bHighlighted = false;

protected:
	virtual void BeginPlay() override;
};
