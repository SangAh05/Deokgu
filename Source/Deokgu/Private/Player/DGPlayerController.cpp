// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Math/Vector2D.h" 
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Character/DeocGuCharacter.h"

ADGPlayerController::ADGPlayerController ( )
{
	bReplicates = true;
}

void ADGPlayerController::BeginPlay ( )
{
	Super::BeginPlay();
	check ( deocGuContext );

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check ( Subsystem );
	Subsystem->AddMappingContext(deocGuContext, 0);

	//bShowMouseCursor = true;
	//DefaultMouseCursor = EMouseCursor::Default;

	//FInputModeGameAndUI InputModeData;
	//InputModeData.SetLockMouseToViewportBehavior ( EMouseLockMode::DoNotLock );
	//InputModeData.SetHideCursorDuringCapture(false);
	//SetInputMode ( InputModeData );
}

void ADGPlayerController::SetupInputComponent ( )
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(lookAction  , ETriggerEvent::Triggered, this, &ADGPlayerController::DGLook       );
	EnhancedInputComponent->BindAction(walkAction  , ETriggerEvent::Started  , this, &ADGPlayerController::DGWalk       );
	EnhancedInputComponent->BindAction(runAction   , ETriggerEvent::Triggered, this, &ADGPlayerController::DGRun        );
	EnhancedInputComponent->BindAction(sprintAction, ETriggerEvent::Ongoing  , this, &ADGPlayerController::DGSprintStart);
	EnhancedInputComponent->BindAction(sprintAction, ETriggerEvent::Completed, this, &ADGPlayerController::DGSprintEnd  );

	EnhancedInputComponent->BindAction(jumpAction  , ETriggerEvent::Started  , this, &ADGPlayerController::DGJump       );
}


void ADGPlayerController::CursorTrace ( )
{

}

void ADGPlayerController::DGLook ( const FInputActionValue& InputActionValue )
{
	const FVector2D Turn = InputActionValue.Get<FVector2D> ( );

	FRotator Rot = GetControlRotation ( );
	Rot.Pitch = FMath::Clamp ( Rot.Pitch + Turn.Y , minPitch , maxPitch );
	Rot.Yaw += Turn.X;

	SetControlRotation ( Rot );
}

void ADGPlayerController::DGWalk( const FInputActionValue& InputActionValue )
{
	bIsWalking = true;

	if (me != nullptr)
	{
		UCharacterMovementComponent* Move = me->GetCharacterMovement();
		if (Move != nullptr)
		{
			Move->MaxWalkSpeed = walkSpeed; // 예: 220.f
		}
	}
}

void ADGPlayerController::DGRun ( const FInputActionValue& InputActionValue )
{
const FVector2D InputAxisVector = InputActionValue.Get<FVector2D> ( );

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation ( 0.0f , Rotation.Yaw , 0.0f );

	const FVector ForwardDirection = FRotationMatrix ( YawRotation ).GetUnitAxis ( EAxis::X );
	const FVector   RightDirection = FRotationMatrix ( YawRotation ).GetUnitAxis ( EAxis::Y );

	if (APawn* ControlledPawn = GetPawn<APawn> ( ))
	{
		ControlledPawn->AddMovementInput ( ForwardDirection , InputAxisVector.Y );
		ControlledPawn->AddMovementInput (   RightDirection , InputAxisVector.X );
	}
}

void ADGPlayerController::DGSprintStart ( )
{
	bIsWalking = false;

	if (me != nullptr)
	{
		UCharacterMovementComponent* Move = me->GetCharacterMovement ( );
		if (Move != nullptr)
		{
			Move->MaxWalkSpeed = sprintSpeed; 
		}
	}
}

void ADGPlayerController::DGSprintEnd ( )
{
	me = Cast<ADeocGuCharacter>(GetPawn());
	if (me != nullptr)
	{
		UCharacterMovementComponent* Move = me->GetCharacterMovement ( );
		if (Move != nullptr)
		{
			Move->MaxWalkSpeed = runSpeed;
		}
	}
}

void ADGPlayerController::DGJump()
{
	if (ACharacter* Char = Cast<ACharacter>(GetPawn()))
	{
		Char->Jump ( );
	}
}

