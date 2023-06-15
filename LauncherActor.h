// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "ProjectileActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LauncherActor.generated.h"

/**
 * A launcher
*/
UCLASS()
class LAUNCHERS_API ALauncherActor : public AActor
{
	GENERATED_BODY()
	
private:
	float CooldownSeconds{ 0 };
	float HalfCollisionWidth;
	float ProjectileSpawnOffset{ 15 };

	/**
	 * Starts the cooldown timer
	*/
	void StartCooldownTimer();

public:
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "Projectile"),
		Category = ProjectileBlueprints)
		TSubclassOf<AProjectileActor> UProjectile;

	/**
	 * Spawns a projectile
	*/
	UFUNCTION()
		void SpawnProjectile();

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ALauncherActor();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

protected:
	/**
	 * @brief Sets cooldown seconds
	 * @param Seconds cooldown seconds
	*/
	void SetCooldownSeconds(float Seconds);
};
