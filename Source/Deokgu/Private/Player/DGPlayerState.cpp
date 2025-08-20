// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DGPlayerState.h"
#include "AbilitySystem/DGAbilitySystemComponent.h"
#include "AbilitySystem/DGAttributeSet.h"

ADGPlayerState::ADGPlayerState ( )
{
	AbilitySystemComponent = CreateDefaultSubobject<UDGAbilitySystemComponent> ( "AbilitySystemComponent" );
	AbilitySystemComponent->SetIsReplicated ( true );

	AttributeSet = CreateDefaultSubobject<UDGAttributeSet> ( "AttributeSet" );

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* ADGPlayerState::GetAbilitySystemComponent ( ) const
{
	return AbilitySystemComponent;
}
