// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include <Components/SphereComponent.h>
#include "PaperSpriteComponent.h"

#include "Helpers/LockAxisfor2D.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    //CREATE the SphereCollision Component
    
	//CALL SetCollisionEnabled() on SphereCollision passing in ECollisionEnabled::QueryAndPhysics
    
	//CALL SetCollisionProfileName() on SphereCollision passing in "OverlapAll"
    
	//CALL SetGenerateOverlapEvents() on SphereCollision passing in  true
    
	//CALL SetSimulatePhysics() on SphereCollision passing in false
    
	//SET the RootComponent to SphereCollision
    

	//CREATE the Sprite Component
    
	//CALL SetCollisionEnabled() on Sprite passing in ECollisionEnabled::NoCollision
    
	//CALL SetCollisionProfileName() on Sprite passing in "NoCollision"
    
	//CALL SetupAttachment() on Sprite passing in RootComponent
    

	//CALL Add() on Tags passing in "Pickup"
    
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

