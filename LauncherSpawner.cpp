// Copyright A.T. Chamillard. All Rights Reserved.
#include "Kismet/GameplayStatics.h"
#include "LauncherActor.h"
#include "LauncherSpawner.h"

// Sets default values
ALauncherSpawner::ALauncherSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ALauncherSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	StartSpawnTimer();
}

// Called every frame
void ALauncherSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ALauncherSpawner::SpawnLauncher()
{
	// try to find Actor with tag
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(
		GetWorld(), "Launcher", TaggedActors);

	// destroy first Actor in TArray
	if (TaggedActors.Num() > 0)
	{
		TaggedActors[0]->Destroy();
	}

	// randomly pick which launcher to spawn
	TSubclassOf<ALauncherActor> SpawnLauncher;
	/*int LauncherNumber = FMath::RandRange(0, 2);
	if (LauncherNumber == 0)
	{*/
		SpawnLauncher = UChainsawLauncher;
	/*}
	else if (LauncherNumber == 1)
	{
		SpawnLauncher = UPirateLauncher;
	}
	else
	{
		SpawnLauncher = UZombieLauncher;
	}*/

	// spawn the launcher
	GetWorld()->SpawnActor<ALauncherActor>(
		SpawnLauncher, FVector::ZeroVector,
		FRotator::ZeroRotator);

	// start the timer again
	StartSpawnTimer();
}


/**
 * Starts the spawn timer
*/
void ALauncherSpawner::StartSpawnTimer()
{
	// start the timer
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ALauncherSpawner::SpawnLauncher,
		SpawnDelaySeconds);
}

