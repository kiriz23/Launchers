// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

/**
 * A projectile
*/
UCLASS()
class LAUNCHERS_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
private:
	FVector ImpulseForce{ 0.0f };
	const float ScreenRight{ 256 };
	float HalfCollisionWidth;

public:
	/**
	 * Sets default values for this actor's properties
	*/
	AProjectileActor();

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
	 * Sets the impulse force
	 * @param Force
	*/
	void SetImpulseForce(FVector Force);
};
