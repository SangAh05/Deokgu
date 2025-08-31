// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/DGEffectActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../../../../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
#include "AbilitySystem/DGAttributeSet.h"

// Sets default values
ADGEffectActor::ADGEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	Sphere->SetupAttachment(GetRootComponent());
}

void ADGEffectActor::OnOverlap ( UPrimitiveComponent* OverlappedComponent , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult )
{
	// 인터페이스를 캐스팅하도록하겠다.플레이어에 있던 인터페이스를 캐스팅할 것이다.

		// TODO : Change this to apply a Gameplay Effect. For now, using const_cast a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface> ( OtherActor ))
	{
		// 어트리뷰트 세트가 있는 경우 세팅하는 것 우리가 만든 것으로 세팅하도록하겠다. 

		//우리가 만든것을 가지고 오기 때문에 앞에 const를 붙여주어야한다 그렇지 않으면 오류가 생긴다.
		const UDGAttributeSet* DGAttributeSet = Cast<UDGAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UDGAttributeSet::StaticClass()));

		// const_cast를 통해서 속성을 바꾸는 작업 
		UDGAttributeSet* MutableDGAttributeSet = const_cast<UDGAttributeSet*>(DGAttributeSet); // 가변 오라 속성세트
		MutableDGAttributeSet->SetHealth ( DGAttributeSet->GetHealth ( ) + 25.0f ); // const이기 문에 오류가 생길 것인데 이것은 하면 안되는 행동이지만 배우기 위해 잠시 할 거라고한다. 가변 속성세트를 만들어서 하도록한다.
		MutableDGAttributeSet->SetStamina ( DGAttributeSet->GetStamina ( ) - 25.0f );

		Destroy ( ); // 오버랩이 되었으니까 해당 메쉬를 지워주겠다. 
	}
}

void ADGEffectActor::EndOverlap ( UPrimitiveComponent* OverlappedComponent , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex )
{

}

// Called when the game starts or when spawned
void ADGEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic ( this , &ADGEffectActor::OnOverlap );
	Sphere->OnComponentEndOverlap.AddDynamic ( this , &ADGEffectActor::EndOverlap );
}


