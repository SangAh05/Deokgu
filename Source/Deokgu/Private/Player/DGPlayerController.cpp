// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerController.h"

ADGPlayerController::ADGPlayerController ( )
{
	bReplicates = true;
}

void ADGPlayerController::BeginPlay ( )
{
	Super::BeginPlay();
	check ( DeocGuContext );

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check ( Subsystem );
	Subsystem->AddMappingContext(DeocGuContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior ( EMouseLockMode::DoNotLock );
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode ( InputModeData );
}

void ADGPlayerController::SetupInputComponent ( )
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADGPlayerController::GDMove);
}

void ADGPlayerController::GDMove( const FInputActionValue& InputActionValue )
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

void ADGPlayerController::CursorTrace ( )
{

}
