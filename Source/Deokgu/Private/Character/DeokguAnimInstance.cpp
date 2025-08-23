// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DeokguAnimInstance.h"
#include "Character/DeocGuCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDeokguAnimInstance::NativeUpdateAnimation ( float DeltaSeconds )
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ADeocGuCharacter* player = Cast<ADeocGuCharacter>(TryGetPawnOwner());
	if (player == nullptr)
	{
		return;
	}
	FVector velocity = player->GetVelocity();
	FVector forwardVector = player->GetActorForwardVector();

	speed = FVector::DotProduct(forwardVector, velocity);

	FVector rightVector = player->GetActorRightVector();
	direction = FVector::DotProduct(rightVector, velocity);

	auto movement = player->GetCharacterMovement();
	
	if (movement != nullptr)
	{
		isInAir = movement->IsFalling();
	}

	pitch = player->GetBaseAimRotation().Pitch;
}

void UDeokguAnimInstance::PlayAttackAnim ( )
{
	if (AttackAnimMontage == nullptr) return;
	Montage_Play(AttackAnimMontage);
}
