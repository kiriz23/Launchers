// Copyright A.T. Chamillard. All Rights Reserved.


#include "PirateProjectileActor.h"

/**
 * Sets default values
*/
APirateProjectileActor::APirateProjectileActor() :
	AProjectileActor{}
{
	SetImpulseForce(FVector{ 0.0f, 100.0f, 0.0f });
}