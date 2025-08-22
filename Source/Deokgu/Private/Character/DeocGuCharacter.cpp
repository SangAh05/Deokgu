// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DeocGuCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DGPlayerState.h"

ADeocGuCharacter::ADeocGuCharacter ( )
{
	GetCharacterMovement ( )->bOrientRotationToMovement = true;
	GetCharacterMovement ( )->RotationRate = FRotator ( 0.0f , 400.0f , 0.0f );
	GetCharacterMovement ( )->bConstrainToPlane = true;
	GetCharacterMovement ( )->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;
	bUseControllerRotationYaw   = false;
}

void ADeocGuCharacter::PossessedBy(AController* NewController )
{
	Super::PossessedBy(NewController );

	InitAbilityActorInfo();
}

void ADeocGuCharacter::OnRep_PlayerState ( )
{
	Super::OnRep_PlayerState ( );

	//Init ability actor Info for the Client
	InitAbilityActorInfo ( );
}

void ADeocGuCharacter::InitAbilityActorInfo ( )
{
	ADGPlayerState* DGPlayerState = GetPlayerState<ADGPlayerState> ( );
	check(DGPlayerState);
	DGPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo (DGPlayerState, this );
	AbilitySystemComponent = DGPlayerState->GetAbilitySystemComponent();
	AttributeSet = DGPlayerState->GetAttributeSet();
}
