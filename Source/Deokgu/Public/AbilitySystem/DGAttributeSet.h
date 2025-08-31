// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DGAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class DEOKGU_API UDGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UDGAttributeSet();
	virtual void GetLifetimeReplicatedProps ( TArray<class FLifetimeProperty>& OutLifetimeProps ) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "vital Attributes" )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , Health );

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "vital Attributes" )
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , MaxHealth );

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "vital Attributes" )
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , Stamina );

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "vital Attributes" )
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , MaxStamina );

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Lives, Category = "vital Attributes" )
	FGameplayAttributeData Lives;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , Lives );

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxLives, Category = "vital Attributes" )
	FGameplayAttributeData MaxLives;
	ATTRIBUTE_ACCESSORS ( UDGAttributeSet , MaxLives );

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth (const FGameplayAttributeData& OldMaxHealth ) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UFUNCTION()
	void OnRep_Lives(const FGameplayAttributeData& OldLives) const;

	UFUNCTION()
	void OnRep_MaxLives(const FGameplayAttributeData& OldMaxLives) const;
};
