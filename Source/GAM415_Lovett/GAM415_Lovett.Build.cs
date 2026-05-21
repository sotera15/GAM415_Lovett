// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAM415_Lovett : ModuleRules
{
	public GAM415_Lovett(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
