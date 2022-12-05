// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperBlockioGameModeBase.h"
#include "Pawns/PlayerCharacter.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Game/SuperBlockioGameStateBase.h"

ASuperBlockioGameModeBase::ASuperBlockioGameModeBase()
{
    
}

void ASuperBlockioGameModeBase::BeginPlay()
{
    Super::BeginPlay();

	//DECLARE a variable called World of type UWorld* const and assign it to the return value of GetWorld()
   
	//IF World NOT EQUAL to nullptr
   
    {
    	//SET PlayerCharacter to the return value of Cast<APlayerCharacter>(World->GetFirstPlayerController()->GetPawn())
   
    	//SET GameState to the return value of World->GetGameState<ASuperBlockioGameStateBase>()
   

    	//IF PlayerCharacter NOT nullptr
		{
			//CALL SetCheckpointLocation() on GameState passing in PlayerCharacter->GetActorLocation()
		}
    	//ENDIF
    }
}

void ASuperBlockioGameModeBase::OnCheckpoint(FVector FlagPos)
{
	//IF GameState NOT nullptr
   
     {
     	 //CALL SetCheckpointLocation() on GameState passing in FlagPos
   
     }
	//ENDIF
}

void ASuperBlockioGameModeBase::OnDeath()
{
	//IF GameState->GetLives() NOT EQUAL 0

    {
    	//CALL SetActorLocation() on PlayerCharacter passing in GameState->GetCheckpointLocation()

    	//CALL IncreaseLives() on GameState passing in -1

    }
    //ELSE

    {
        /* If world not null, then cast Aplayer, however if the condition is not met, nullptr */
    	//SET PlayerCharacter to the return of --> GetWorld() != nullptr ? Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()) : nullptr

    	//CALL Destroy() on PlayerCharacter

        /*Show GameOver*/
    	//CALL GameOver()

    }
}

void ASuperBlockioGameModeBase::GameOver()
{
	//CALL OnGameOver()

}

void ASuperBlockioGameModeBase::Goal()
{
	//CALL OnGoal()

}



void ASuperBlockioGameModeBase::OnGoal_Implementation()
{
    
}

void ASuperBlockioGameModeBase::OnGameOver_Implementation()
{
    
}





