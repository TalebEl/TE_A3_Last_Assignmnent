// Fill out your copyright notice in the Description page of Project Settings.


#include "ONOFFBlock.h"

#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/BoxComponent.h"

#include "Game/SuperBlockioGameStateBase.h"

// Sets default values
AONOFFBlock::AONOFFBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
    //SET BlockType to EBlockOnOff::Trigger
    

	//CREATE the BoxCollision Component
    
	//CALL SetCollisionProfileName() on BoxCollision passing in "BlockAll"
    
	//CALL  BoxCollision->OnComponentHit.AddDynamic() passing in this, &AONOFFBlock::OnHit
    
	//SET RootComponent to BoxCollision
    

	//CREATE the BlockSprite Component
    
	//CALL SetCollisionProfileName() on BlockSprite passing in "NoCollision"
    
	//CALL SetCollisionEnabled() on BlockSprite passing in ECollisionEnabled::NoCollision
    
	//CALL SetupAttachment() on BlockSprite passing in RootComponent
    

	//CREATE the OnOffComponent
    

	//SET Activated to false
    
}

// Called when the game starts or when spawned
void AONOFFBlock::BeginPlay()
{
	Super::BeginPlay();

	//IF BlockType IS EBlockOnOff::OnOff
    
    {
    
    	//CALL BoxCollision->OnComponentHit.RemoveDynamic() passing in this, &AONOFFBlock::OnHit
    
    }
	//ENDIF
}

// Called every frame
void AONOFFBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EBlockOnOff AONOFFBlock::GetType()
{
    return BlockType;
}

void AONOFFBlock::SwitchStates()
{
	//CALL SwitchStates() on OnOffComponent passing in this
    
	//IF BlockType IS EBlockOnOff::OnOff
    
    {
    	//IF OnOffComponent->GetState()
    
        {
        	//CALL SetSprite() on BlockSprite passing in --> Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/Game/Textures/8Bit_ONOFF_SwitchON_Sprite")))
    
        }
    	//ELSE
    
        {
        	//CALL SetSprite() on BlockSprite passing in --> StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/Game/Textures/8Bit_ONOFF_SwitchOFF_Sprite")))
    
        }
    	//ENDIF
    }
	//ELSE IF BlockType IS EBlockOnOff::Trigger
    
    {
    	//IF OnOffComponent->GetState()
    
        {
        	//CALL SetSprite() on BlockSprite passing in --> StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/Game/Textures/8Bit_ONOFF_TriggerON_Sprite")))
    
        }
    	//ELSE
    
        {
        	//CALL SetSprite() on BlockSprite passing in --> StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/Game/Textures/8Bit_ONOFF_TriggerOFF_Sprite")))
    
        }
    	//ENDIF
    }
	//ENDIF
}

void AONOFFBlock::ReactivationDelay()
{
	//SET Activated to false
    
	//CALL GetWorldTimerManager().ClearTimer() passing in ReactivationTimer
    
}



//This is only for the Switch Block, the Solid or Lined Block has no overlap other than a blocking
void AONOFFBlock::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//DECLARE a variable called gamestate of type ASuperBlockioGameStateBase* and assign it to the return value of GetWorld()->GetGameState<ASuperBlockioGameStateBase>()
    

	//IF gamestate NOT nullptr
    
    {
    	//IF OtherActor->ActorHasTag("Player") AND NOT Activated AND BlockType IS EBlockOnOff::Trigger
       
        {
            /*Ideally, if hit from below*/
        	//IF Hit.ImpactPoint.Z LESS THAN EQUAL to (BoxCollision->GetComponentLocation().Z - (BoxCollision->GetScaledBoxExtent().Z/2))
       
            {
            	//SET Activated to true
       
            	//CALL SwitchONOFFblocks() on gamestate
       
            }
        }
    	//ELSE IF OtherActor->ActorHasTag("Ball") AND NOT Activated AND BlockType == EBlockOnOff::Trigger
       
        {
            /*If it was hit by projectile, then anything goes. Try to make it so only player's projectile can turn ONOFF*/
        	//IF OtherActor->GetOwner()->ActorHasTag("Player")
       
            {
            	//SET Activated to true
       
            	//CALL SwitchONOFFblocks() on gamestate
       
            	//CALL Destroy() on OtherActor
       
            }
        	//ENDIF
        }
    	//ENDIF

    	//IF NOT GetWorldTimerManager().IsTimerActive(ReactivationTimer)
       
        {
        	//CALL GetWorldTimerManager().SetTimer() passing in ReactivationTimer, this, &AONOFFBlock::ReactivationDelay, .5, false
       
        }
    	//ENDIF
    }
	//ENDIF

}