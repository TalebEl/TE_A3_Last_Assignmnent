// Fill out your copyright notice in the Description page of Project Settings.


#include "Flagpoint.h"

#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "PaperSprite.h"
#include "Game/SuperBlockioGameModeBase.h"
#include "Components/FlagComponent.h"

// Sets default values
AFlagpoint::AFlagpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    /*What kind of Flag is it*/
	//SET Flagtype to  EFlagEnum::Checkpoint
    

	//CREATE the BoxCollision Component
    
	//CALL SetCollisionProfileName() on BoxCollision passing in "OverlappAll"
    
	//CALL BoxCollision->OnComponentBeginOverlap.AddDynamic() passing in this, &AFlagpoint::OnOverlapBegin
    
	//SET the RootComponent to BoxCollision
    

	//CREATE the FlagSprite Component
    
	//CALL SetCollisionProfileName() on FlagSprite passing in "NoCollision"
    
	//CALL SetCollisionEnabled() on FlagSprite passing in ECollisionEnabled::NoCollision
    
	//CALL SetupAttachment() on FlagSprite passing in RootComponent
    

	//CREATE the FlagComponent
    

}

// Called when the game starts or when spawned
void AFlagpoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlagpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlagpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//IF OtherActor->ActorHasTag("Player") AND  NOT FlagComponent->CheckpointHasBeenReached()
    
    {
    	//IF Flagtype IS EFlagEnum::Checkpoint
    
        {
        	//CALL OnCheckpoint() on FlagComponent passing in this->GetActorLocation()
    
        	//CALL SetSprite() on FlagSprite passin in --> Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/Game/Textures/8Bit_Checkpoint_ON_Sprite")))
    
        }
    	//ELSE IF Flagtype IS EFlagEnum::Goal
    
        {
        	//CALL OnGoal() on FlagComponent
    
        }
    	//ENDIF
    }
}
