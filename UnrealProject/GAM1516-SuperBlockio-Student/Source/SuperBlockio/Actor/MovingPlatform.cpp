// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SET StartingTarget to ETarget::First
    
    //CREATE Target1 Component
    
	//CALL SetCollisionProfileName() on Target1 passing in "NoCollision"
    
	//CALL SetCollisionEnabled() on Target1 passing in ECollisionEnabled::NoCollision
    
	//CALL SetupAttachment() on Target1 passing in RootComponent
    

	//CREATE Target2 Component
    
	//CALL SetCollisionProfileName() on Target2 passing in "NoCollision"
    
	//CALL SetCollisionEnabled() on Target2 passing in ECollisionEnabled::NoCollision
    
	//CALL SetupAttachment() on Target2 passing in RootComponent
    

	//CREATE the BoxCollision Component
    
	//CALL SetCollisionProfileName() on BoxCollision passing in "BlockAll"
    
	//SET RootComponent to BoxCollision
    

	//CREATE the PlatformSprite Component
    
	//CALL SetCollisionProfileName() on PlatformSprite passing in "NoCollision"
    
	//CALL SetCollisionEnabled() on PlatformSprite passing in ECollisionEnabled::NoCollision
    
	//CALL SetupAttachment() on PlatformSprite passing in RootComponent
    

	//SET InterpSpeed to 600.0f
    
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//SET Target1Location to the return value of Target1->GetComponentLocation()
    
	//SET Target2Location to the return value of Target2->GetComponentLocation()
    

	//IF StartingTarget IS ETarget::First
    
    {
    	//SET CurrentGoToLocation to Target1Location
    
    }
	//ELSE
    
    {
    	//SET CurrentGoToLocation to Target2Location
    
    }
	//ENDIF
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//DECLARE a variable called Delta of type FVector const and assign it to BoxCollision->GetComponentLocation() - CurrentGoToLocation
    
	//DECLARE a variable called DistanceToPoint and assign it to the return value of Delta.Size()
    

	//IF DistanceToPoint LESS THAN 100
    
    {
    	//IF CurrentGoToLocation NOT EQUAL to Target1Location
    
        {
        	//SET CurrentGoToLocation to Target1Location
    
        }
    	//ELSE
    
        {
        	//SET CurrentGoToLocation to Target2Location
    
        }

    }
	//ENDIF

	//DECLARE a variable called targetLocation of type FVector and assign it to the return value of FMath::VInterpConstantTo(BoxCollision->GetComponentLocation(), CurrentGoToLocation, DeltaTime, InterpSpeed)
    
	//CALL SetWorldLocation() on BoxCollision passing in targetLocation
    

}

