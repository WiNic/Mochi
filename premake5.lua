workspace "Mochi"
    startproject "SandBox"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mochi"
    location "Mochi"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {   

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {

        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MOCHI_PLATFORM_WINDOWS",
            "MOCHI_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }
    
    filter "configurations:Debug"
        defines "MOCHI_DEBUG"
        symbols "On"
        
    filter "configurations:Release" 
        defines "MOCHI_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MOCHI_DIST"
        optimize "On"


project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Mochi/vendor/spdlog/include",
        "Mochi/src"
    }

    links
    {
        "Mochi"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MOCHI_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MOCHI_DEBUG"
        symbols "On"
        
    filter "configurations:Release" 
        defines "MOCHI_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MOCHI_DIST"
        optimize "On"