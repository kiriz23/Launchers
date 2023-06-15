// Copyright A.T. Chamillard. All Rights Reserved.


#include "ProjectileActor.h"

/**
 * Sets default values
*/
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	 
}

/**
 * Called when the game starts or when spawned
*/
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
	// save bounds for actor
	FVector Origin;
	FVector BoxExtent;
	GetActorBounds(true, Origin, BoxExtent);
	HalfCollisionWidth = BoxExtent.Y;

	// get the static mesh components for the ball
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	GetComponents(StaticMeshComponents);

	// make sure we found the static mesh
	if (StaticMeshComponents.Num() > 0)
	{
		// the mesh we want is at location 0 because there's only 1 mesh
		UStaticMeshComponent* StaticMesh = StaticMeshComponents[0];

		// add impulse force to mesh
		StaticMesh->AddImpulse(ImpulseForce);
	}
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// destroy projectile if it leaves the screen
	if (GetActorLocation().Y + HalfCollisionWidth >
		ScreenRight)
	{
		Destroy();
	}
}

/**
 * Sets the impulse force
 * @param Force
*/
void AProjectileActor::SetImpulseForce(FVector Force)
{
	ImpulseForce = Force;
}