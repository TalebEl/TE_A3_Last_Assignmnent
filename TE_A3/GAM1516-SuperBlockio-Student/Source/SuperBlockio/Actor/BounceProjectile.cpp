// Fill out your copyright notice in the Description page of Project Settings.


#include "BounceProjectile.h"

#include "PaperSpriteComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Game/SuperBlockioGameStateBase.h"

#include "Pawns/PlayerCharacter.h"

#include "Helpers/LockAxisfor2D.h"

// Sets default values
ABounceProjectile::ABounceProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    /** USphereComponent  */
	//CREATE the SphereComponent
    SphereComponent = CreateDefaultSubobject<USphereComponent>(("SphereComponent"));
	//CALL ULockAxisfor2D::LockPhysicsTo2DAxis() passing in SphereComponent
    ULockAxisfor2D::LockPhysicsTo2DAxis(SphereComponent);
	//CALL SphereComponent->OnComponentBeginOverlap.AddDynamic() passing in this, &ABounceProjectile::OnOverlapBegin
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABounceProjectile::OnOverlapBegin);
	//SET the SphereComponent as the RootComponent 
    RootComponent = SphereComponent;

    /** UPaperSpriteComponent  */
	//CREATE the BallSprite Component
    BallSprite = CreateDefaultSubobject<UPaperSpriteComponent>(("BallSprite"));
	//CALL SetCollisionProfileName() on BallSprite passing in "NoCollision"
    BallSprite->SetCollisionProfileName(("NoCollision")); //collision NO COLLSION??
	//CALL SetCollisionEnabled() on BallSprite passing in ECollisionEnabled::NoCollision
    BallSprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//CALL SetupAttachment() on BallSprite passing in RootComponent
    BallSprite->SetupAttachment(RootComponent);






    /** ProjectileMovementComponent  */
	//CREATE the ProjectileMovementComponent
    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(("ProjectileMovementComponent"));
	//SET the ProjectileMovementComponent->UpdatedComponent to SphereComponent
    ProjectileMovementComponent->UpdatedComponent = SphereComponent;
    ProjectileMovementComponent->bRotationFollowsVelocity = false;
    ProjectileMovementComponent->bShouldBounce = true;
    ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
    ProjectileMovementComponent->Bounciness = 1.0;



    //CALL Add() on Tags passing in "Ball"
    Tags.Add("Ball");

	//SET InitialLifeSpan to 5
    InitialLifeSpan = 5.0f;

	//CALL ProjectileMovementComponent->OnProjectileBounce.AddDynamic() passing in this, &ABounceProjectile::OnProjectileBounce
    ProjectileMovementComponent->OnProjectileBounce.AddDynamic(this, &ABounceProjectile::OnProjectileBounce);
}

// Called when the game starts or when spawned
void ABounceProjectile::BeginPlay()
{
	Super::BeginPlay();
	//SET ProjectileMovementComponent->InitialSpeed to Speed
    ProjectileMovementComponent->InitialSpeed = Speed;
    
	//CALL ProjectileMovementComponent->MaxSpeed to Speed
    ProjectileMovementComponent->MaxSpeed = Speed;
}

// Called every frame
void ABounceProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABounceProjectile::ShootThatProjectile(const FVector& Direction)
{
	//SET LaunchDir to Direction
    LaunchDir = Direction;

	//SET ProjectileMovementComponent->Velocity to LaunchDir * Speed
    ProjectileMovementComponent->Velocity = LaunchDir* Speed;
}

void ABounceProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    /*If it hits against Enemy/Player, else if it hits against world stuff*/
	//IF OtherActor NOT EQUAL to this->GetOwner()
    if(OtherActor != this->GetOwner())
    {
    	//IF OtherActor->ActorHasTag("Enemy")
        if (OtherActor->ActorHasTag("Enemy"))
        {
            //CALL Destroy() on OtherActor
            OtherActor->Destroy();
            //CAll Destroy() on this
            this->Destroy();

            //DECLARE a variable called gamestate of type ASuperBlockioGameStateBase and assign it to the return of GetWorld()->GetGameState<ASuperBlockioGameStateBase>()
            ASuperBlockioGameStateBase* gamestate = GetWorld()->GetGameState<ASuperBlockioGameStateBase>(); // might be wrong
            //IF gamestate NOT nullptr
            if (gamestate != nullptr)
            {
                //CALL IncreaseScore() on gamestate passing in 500
                gamestate->IncreaseScore(500.0f);
            }
            //ENDIF
        }
        //ELSE IF OtherActor->ActorHasTag("Player")
        else if (OtherActor->ActorHasTag("Player"))
        {
        	//DECLARE a variable called player of type APlayerCharacter* and assign it to the return value of Cast<APlayerCharacter>(OtherActor)
            APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor);
        	//CALL HasDied() on player
            player->HasDied();
            //CALL Destroy() on this
            this->Destroy();
        }
    	// ELSE IF OtherActor->ActorHasTag("Coin")
        else if(OtherActor->ActorHasTag("Coin"))
        {
        	//IF this->GetOwner()->ActorHasTag("Player")
            if(this->GetOwner()->ActorHasTag("Player"))
            {
            	//DECLARE a variable called gamestate of type ASuperBlockioGameStateBase* and assign it to the return value of GetWorld()->GetGameState<ASuperBlockioGameStateBase>()
                ASuperBlockioGameStateBase* gamestate = GetWorld()->GetGameState<ASuperBlockioGameStateBase>();

            	//IF  gamestate NOT nullptr
                if(gamestate != nullptr)
                {
                	//CALL IncreaseCoins() on gamestate passing in 1
                    gamestate->IncreaseCoins(1.0f);
                	//CALL IncreaseScore() on gamestate passing in 100
                    gamestate->IncreaseScore(100.0f);
                }//ENDIF

            	//CALL Destroy() on OtherActor
                OtherActor->Destroy();
            }
        	//ENDIF
        }//ENDIF
    }
	//ENDIF
}

void ABounceProjectile::OnProjectileBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FString("OnBounce"));

	//DECLARE a variable called ImpactNormal of type FVector and SET it to ImpactResult.ImpactNormal
    FVector ImpactNormal = ImpactResult.ImpactNormal;
	//DECLARE a variable called Velocity of type FVector and SET it to ProjectileMovementComponent->Velocity
    FVector Velocity = ProjectileMovementComponent->Velocity;

	//DECLARE a variable called Length of type float and SET it to the return value of Velocity.Size()
    float Lenght = Velocity.Size();

	//IF Length GREATER THAN OR EQUAL to 1
    if(Lenght >= 1.0f)
    {
    	//DIVIDE Velocity.X by Length i.e Velocity.X /= Length;
        Velocity.X /= Lenght;
    	//DIVIDE Velocity.Y by Length
        Velocity.Y /= Lenght;
    	//DIVIDE Velocity.Z by Length
        Velocity.Z /= Lenght;
    }

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FString("Velocity: X -") + FString::SanitizeFloat(Velocity.X) + " Y - " + FString::SanitizeFloat(Velocity.Y) + " Z - " + FString::SanitizeFloat(Velocity.Z));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FString("Velocity: X -") + FString::SanitizeFloat(Velocity.X) + " Y - " + FString::SanitizeFloat(Velocity.Y) + " Z - " + FString::SanitizeFloat(Velocity.Z));
	//CALL Velocity.MirrorByVector() passing in ImpactNormal
    Velocity.MirrorByVector(ImpactNormal);
	//SET ProjectileMovementComponent->Velocity to Velocity * Speed
    ProjectileMovementComponent->Velocity = Velocity * Speed;
}

