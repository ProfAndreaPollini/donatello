workspace "Donatello"
	architecture "x86_64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg-architecture}"

project "Donatello"
	location "Donatello"
	kind "Staticlib"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

	targetdir ("bin/%{prj.name}")
	objdir ("obj/%{prj.name}")

	pchheader "dntpch.h"
	pchsource "Donatello/src/dntpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	links 
	{
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines{}

	filter "configurations:Debug"
		defines "DONATELLO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DONATELLO_RELEASE"
		runtime "Release"
		optimize "on"


project "DonatelloTests"
	location "DonatelloTests"
	kind "ConsoleApp"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"


	

	targetdir ("bin/%{prj.name}")
	objdir ("obj/%{prj.name}")

	nuget("Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static:1.8.1.3")

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"%{prj.name}",
		"Donatello/src",
		"packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static.1.8.1.3/build/native/include"
	}
	libdirs
	{
		"bin/Donatello",
		"packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static.1.8.1.3/lib/native/v140/windesktop/msvcstl/static/rt-static/x64/Debug"
	}

	links
	{
		"gtestd",
		"gtest_maind",
		"Donatello"
	}

	filter "system:windows"
		systemversion "latest"
		defines{}

	filter "configurations:Debug"
		defines "DONATELLO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DONATELLO_RELEASE"
		runtime "Release"
		optimize "on"