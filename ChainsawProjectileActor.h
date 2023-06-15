// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileActor.h"
#include "ChainsawProjectileActor.generated.h"

/**
 * A chainsaw projectile
 */
UCLASS()
class LAUNCHERS_API AChainsawProjectileActor : public AProjectileActor
{
	GENERATED_BODY()
	
public:
	/**
	 * Sets default values for this actor's properties
	*/
	AChainsawProjectileActor();
};
