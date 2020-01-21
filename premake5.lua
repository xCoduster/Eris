workspace "Eris"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Eris/vendor/GLFW/include"
IncludeDir["glad"] = "Eris/vendor/glad/include"
IncludeDir["ImGui"] = "Eris/vendor/imgui"

group "Dependencies"
	include "Eris/vendor/GLFW"
	include "Eris/vendor/glad"
	include "Eris/vendor/imgui"

group ""

project "Eris"
	location "Eris"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "er/erpch.h"
	pchsource "Eris/src/er/erpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ER_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ER_RELEASE"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Eris/src",
		"Eris/vendor",
		"Eris/vendor/spdlog/include"
	}

	links
	{
		"Eris"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "ER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ER_RELEASE"
		runtime "Release"
		optimize "on"