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
IncludeDir["glad"] = "Eris/vendor/glad/include"
IncludeDir["GLFW"] = "Eris/vendor/GLFW/include"
IncludeDir["glm"] = "Eris/vendor/glm"
IncludeDir["ImGui"] = "Eris/vendor/imgui"
IncludeDir["stb_image"] = "Eris/vendor/stb_image"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.stb_image}"
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
		"Eris/vendor/spdlog/include",
		"%{IncludeDir.glm}"
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