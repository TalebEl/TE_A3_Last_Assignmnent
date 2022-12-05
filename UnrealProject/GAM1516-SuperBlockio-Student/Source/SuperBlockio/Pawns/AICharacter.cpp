// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

#include "Actor/BounceProjectile.h"

#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

AAICharacter::AAICharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    /*Remove the Player is special case, it wont die when interacting with anything The player is responsible for death*/
	//CALL DestroyComponent() on the BoxComponent
    

	//CREATE the PawnSensingComponent
    
	//CALL PawnSensingComponent->OnSeePawn.AddDynamic() passing in this, &AAICharacter::OnPawnSeen
    
	//CALL PawnSensingComponent->OnHearNoise.AddDynamic() passing in this, &AAICharacter::OnNoiseHeard
    

	//CALL Empty() on Tags
    
	//CALL Add() on Tags passing in "Enemy"
    
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /* Patrol Checks */
	//IF CurrentPatrolPoint NOT NULL
    
    {
    	//DECLARE a variable called Delta of type FVector and SET it to GetActorLocation() - CurrentPatrolPoint->GetActorLocation()
    
    	//DECLARE a variable called DistanceToGoal of type float and SET it to the return value of Delta.Size()
    

        /* Check if we are within 50 .. 100(Better with 2D) units of our goal, if so - pick a new patrol point*/
    	//IF DistanceToGoal LESS THAN 100
    
        {
        	//CALL MoveToNextPatrolPoint()
    
        }
    	//ENDIF

    	//CALL SetActorLocation() passing in FMath::VInterpConstantTo(GetActorLocation(), CurrentPatrolPoint->GetActorLocation(), DeltaTime, 600.f)
    
    }
	//ENDIF
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
    Super::BeginPlay();

	//IF bPatrol IS true
    
    {
    	//CALL MoveToNextPatrolPoint()
    
    }
	//ENDIF

	//CALL GetWorldTimerManager().SetTimer() passing in SpawnProjectileTimer, this, &AAICharacter::Shoot, FireTimerDelay, true
    
}

void AAICharacter::OnPawnSeen(APawn* SeenPawn)
{
    
    if (SeenPawn == nullptr)
    {
        return;
    }

    //SET TargetActor to the SeenPawn (This can now be used to Implement a Chase behavior)
    

    //CALL DrawDebugSphere() passing in (GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Red, false, 10.0f)
    

}


void AAICharacter::OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{
    //CALL DrawDebugSphere() passing in (GetWorld(), Location, 32.0f, 12, FColor::Green, false, 10.0f)
    


    //DECLARE a variable called Direction of type FVector and Assign it to the result of Location -  GetActorLocation()
    

    //CALL Normalize() on Direction
    


    //DECLARE a variable called NewLookAt of type FRotator and SET it to the return value of FRotationMatrix::MakeFromX(Direction).Rotator()
    

    //SET NewLookAt.Pitch to 0.0f
    

    //SET NewLookAt.Roll to 0.0f
    

    //CALL SetActorRotation() passing in NewLookAt
    


}

void AAICharacter::Shoot()
{
    //IF Projectile NOT NULL
    
    {
        //DECLARE a variable called World of type UWorld* const and assign it to the return value of GetWorld()
    
        //IF World IS NOT NULL
    
        {
        	//IF TargetActor NOT NULL
    
            {
                /*Spawn Params for our Ball and AI*/
                //DECLARE a variable called SpawnParams of type FActorSpawnParameters
    
                //SET SpawnParams.Owner to this
    
                //SET SpawnParams.Instigator to the return value of GetInstigator()
    
                //SET SpawnParams.SpawnCollisionHandlingOverride to ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn
    

                //DECLARE a variable called SpawnLocation of type FVector and assign it to the return value of GetCapsuleComponent()->GetComponentLocation()
    

                /*AI Fires balls at the player*/
                //DECLARE a variable called BounceProjectile of type ABounceProjectile* and assign it to the return value of Cast<ABounceProjectile>(GetWorld()->SpawnActor<ABounceProjectile>(Projectile, SpawnLocation, FRotator(0, 0, 0), SpawnParams))
    

            	//DECLARE a variable called Direction of type FVector and assign it to the return value of TargetActor->GetActorLocation()
    
            	//SET Direction to Direction - SpawnLocation
    

               	//DECLARE a variable called Length of type float and assign it to the return value of Direction.Size()
    
            	//IF Length >= 1
    
                {
                	//DIVIDE Direction.X by Length i.e Direction.X /= Length
    
                	//DIVIDE Direction.Y by Length
    
                	//DIVIDE Direction.Z by Length
    
                }
            	//ENDIF

            	//CALL BounceProjectile->ShootThatProjectile() passing in Direction
    

            	//SET TargetActor to nullptr
    
            }
        	//ENDIF
        }
    	//ENDIF
    }
	//ENDIF
}

void AAICharacter::MoveToNextPatrolPoint()
{
    /*Assign next patrol point.*/
    //IF CurrentPatrolPoint IS nullptr OR CurrentPatrolPoint IS SecondPatrolPoint
    
    {
    	//SET CurrentPatrolPoint to FirstPatrolPoint
    
    }
	//ELSE
    
    {
    	//SET CurrentPatrolPoint to SecondPatrolPoint
    
    }
	//ENDIF

	//DECLARE a variable called direction of type FVector and assign it to --> GetActorLocation() - CurrentPatrolPoint->GetActorLocation()
    

    
    //DECLARE a variable called Length of type float and assign it to the return value of Direction.Size()
    
	//IF Length GREATER THAN OR EQUAL to 1
    
    {
        //DIVIDE Direction.X by Length and Assign it back to Direction.X 
    
        //DIVIDE Direction.Y by Length and Assign it back to Direction.Y
    
        //DIVIDE Direction.Z by Length and Assign it back to Direction.Z
    
    }
	//ENDIF

	//DECLARE a variable called NewLookAt of type FRotator and assign it to the return value of FRotationMatrix::MakeFromX(Direction).Rotator()
    
	//SET NewLookAt.Pitch to 0.0f
    
	//SET NewLookAt.Roll to 0.0f
    
	//INCREMENT NewLookAt.Yaw by -180.0f (+= -180.0f)
    
	//CALL SetActorRotation() passing in NewLookAt
    
}