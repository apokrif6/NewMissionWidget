// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NewMissionWidget : ModuleRules
{
	public NewMissionWidget(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "SlateCore", "InputCore", "HeadMountedDisplay" });
	}
}
