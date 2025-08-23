// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DeocGuCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DGPlayerState.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ADeocGuCharacter::ADeocGuCharacter ( )
{
	GetCharacterMovement ( )->bOrientRotationToMovement = true;
	GetCharacterMovement ( )->RotationRate = FRotator ( 0.0f , 400.0f , 0.0f );

	GetCharacterMovement ( )->bConstrainToPlane = true;
	GetCharacterMovement ( )->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;
	bUseControllerRotationYaw   = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true; 
	SpringArmComp->bDoCollisionTest = false; 
	//SpringArmComp->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArmComp->SetRelativeLocation ( FVector ( 0.0f , -40.0f , 20.0f ) );
	SpringArmComp->TargetArmLength = 150.0f;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false; 
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
