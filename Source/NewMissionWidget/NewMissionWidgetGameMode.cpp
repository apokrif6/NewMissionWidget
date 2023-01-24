// Copyright Epic Games, Inc. All Rights Reserved.

#include "NewMissionWidgetGameMode.h"
#include "NewMissionWidgetCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANewMissionWidgetGameMode::ANewMissionWidgetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
