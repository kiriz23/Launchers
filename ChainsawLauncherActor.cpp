// Copyright A.T. Chamillard. All Rights Reserved.


#include "ChainsawLauncherActor.h"

/**
 * Sets default values
*/
AChainsawLauncherActor::AChainsawLauncherActor() :
	ALauncherActor{}
{
	SetCooldownSeconds(2.0f);
}