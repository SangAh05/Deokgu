// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DGEnemy.h"
#include "Deokgu/Deokgu.h"
#include "AbilitySystem/DGAbilitySystemComponent.h"
#include "AbilitySystem/DGAttributeSet.h"

ADGEnemy::ADGEnemy ( )
{
	GetMesh ( )->SetCollisionResponseToChannel ( ECC_Visibility , ECR_Block );

	AbilitySystemComponent = CreateDefaultSubobject<UDGAbilitySystemComponent> ( "AbilitySystemComponent" );
	AbilitySystemComponent->SetIsReplicated ( true ); // 복제에 관한일을 할 것이다.
	AbilitySystemComponent->SetReplicationMode ( EGameplayEffectReplicationMode::Minimal );


	AttributeSet = CreateDefaultSubobject<UDGAttributeSet> ( "AttributeSet" );
}

void ADGEnemy::HighlightActor ( )
{
	GetMesh ( )->SetRenderCustomDepth ( true );
	GetMesh ( )->SetCustomDepthStencilValue ( CUSTOM_DEPTH_RED );
	Weapon->SetRenderCustomDepth ( true );
	Weapon->SetCustomDepthStencilValue ( CUSTOM_DEPTH_RED );
}

void ADGEnemy::UnHighlightActor ( )
{
	GetMesh ( )->SetRenderCustomDepth ( false );
	Weapon->SetRenderCustomDepth ( false );
}

void ADGEnemy::BeginPlay ( )
{
	Super::BeginPlay ( );

	AbilitySystemComponent->InitAbilityActorInfo ( this , this );
}
