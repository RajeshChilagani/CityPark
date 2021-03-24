// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CrownCitySimulation : ModuleRules
{
	public CrownCitySimulation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
