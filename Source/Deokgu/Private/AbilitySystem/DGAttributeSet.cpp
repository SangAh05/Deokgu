// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/DGAttributeSet.h"
#include "Net/UnrealNetwork.h"

UDGAttributeSet::UDGAttributeSet()
{
	InitHealth     ( 100.0f );
	InitMaxHealth  ( 100.0f );
				   
	InitStamina    ( 100.0f );
	InitMaxStamina ( 100.0f );
}

void UDGAttributeSet::GetLifetimeReplicatedProps ( TArray<class FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY ( UDGAttributeSet ,     Health, COND_None , REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY ( UDGAttributeSet ,  MaxHealth, COND_None , REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY ( UDGAttributeSet ,    Stamina, COND_None , REPNOTIFY_Always );
	DOREPLIFETIME_CONDITION_NOTIFY ( UDGAttributeSet , MaxStamina, COND_None , REPNOTIFY_Always );

}

void UDGAttributeSet::OnRep_Health ( const FGameplayAttributeData& OldHealth ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY ( UDGAttributeSet , Health , OldHealth );
}

void UDGAttributeSet::OnRep_MaxHealth ( const FGameplayAttributeData& OldMaxHealth ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY ( UDGAttributeSet , MaxHealth , OldMaxHealth );
}

void UDGAttributeSet::OnRep_Stamina ( const FGameplayAttributeData& OldStamina ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY ( UDGAttributeSet , Stamina, OldStamina );
}

void UDGAttributeSet::OnRep_MaxStamina ( const FGameplayAttributeData& OldMaxStamina ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY ( UDGAttributeSet , MaxStamina, OldMaxStamina );
}

