// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Lemon : ModuleRules
{
	public Lemon(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

        PublicDefinitions.Add("LEMON_NO_UNUSED_LOCAL_TYPEDEF_WARNINGS = 0");
        //PublicDefinitions.Add("GCC");

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "lemon.lib"));
	}
}
