// Copyright A.T. Chamillard. All Rights Reserved.
#pragma once
#include "PirateLauncherActor.h"
#include "ZombieLauncherActor.h"
#include "ChainsawLauncherActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LauncherActor.h"
#include "LauncherSpawner.generated.h"
UCLASS()
class LAUNCHERS_API ALauncherSpawner : public AActor
{GENERATED_BODY()
	
private:
	const float SpawnDelaySeconds{ 5 };
	/**
	 * Starts the spawn timer
	*/
	void StartSpawnTimer();

public:	
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "Launcher"),
		Category = LauncherBlueprints)
		TSubclassOf<ALauncherActor> UChainsawLauncher;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "Launcher"),
		Category = LauncherBlueprints)
		TSubclassOf<ALauncherActor> UPirateLauncher;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "Launcher"),
		Category = LauncherBlueprints)
		TSubclassOf<ALauncherActor> UZombieLauncher;
	
	/**
	 * Spawns a ball
	*/
	UFUNCTION()
		void SpawnLauncher();
	
	// Sets default values for this actor's properties
	ALauncherSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
