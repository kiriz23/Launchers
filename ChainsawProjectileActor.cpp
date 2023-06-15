// Copyright A.T. Chamillard. All Rights Reserved.


#include "ChainsawProjectileActor.h"

/**
 * Sets default values
*/
AChainsawProjectileActor::AChainsawProjectileActor() :
	AProjectileActor{}
{
	SetImpulseForce(FVector{ 0.0f, 50.0f, 0.0f });
}