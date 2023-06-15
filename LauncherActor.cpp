// Copyright A.T. Chamillard. All Rights Reserved.


#include "LauncherActor.h"

/**
 * Sets default values
*/
ALauncherActor::ALauncherActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void ALauncherActor::BeginPlay()
{
	Super::BeginPlay();
	
	// save bounds for actor
	FVector Origin;
	FVector BoxExtent;
	GetActorBounds(true, Origin, BoxExtent);
	HalfCollisionWidth = BoxExtent.Y;

	StartCooldownTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ALauncherActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * @brief Sets cooldown seconds
 * @param Seconds cooldown seconds
*/
void ALauncherActor::SetCooldownSeconds(float Seconds)
{
	if (Seconds > 0)
	{
		CooldownSeconds = Seconds;
	}
}

/**
 * Spawns a projectile
*/
void ALauncherActor::SpawnProjectile()
{
	// spawn projectile
	FVector SpawnLocation{ GetActorLocation() };
	SpawnLocation.Y += HalfCollisionWidth + ProjectileSpawnOffset;
	GetWorld()->SpawnActor<AProjectileActor>(
		UProjectile, SpawnLocation,
		FRotator::ZeroRotator);

	StartCooldownTimer();
}

/**
 * Starts the cooldown timer
*/
void ALauncherActor::StartCooldownTimer()
{
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ALauncherActor::SpawnProjectile,
		CooldownSeconds);
}
