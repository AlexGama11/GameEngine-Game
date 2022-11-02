workspace "Engine"
	location "./solution/"
	startproject "Engine"

	targetdir "./Build/bin/%{cfg.buildcfg}/%{cfg.platform}/"
	objdir "./Build/obj/%{cfg.buildcfg}/%{cfg.platform}/"
	buildlog "./Build/obj/%{cfg.platform}/%{cfg.buildcfg}/%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "unicode"
	warnings "extra"

	flags {
		"shadowedvariables",
		"multiprocessorcompile",
		"undefinedidentifiers",
	}

	platforms {
		"Win-x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	--x86
	filter "platforms:Win-x86"
		architecture "x86"
	--end

	filter "Release"
		defines "NDEBUG"
		optimize "full"
		runtime "release"
		symbols "off"

	filter "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project "Game Engine"
		targetname "Game Engine"
		language "c++"
		cppdialect "c++20"
		warnings "off"

		kind "consoleapp"

		filter "platforms:Win-x86"
			syslibdirs {
				"./devlib/lib/",
			}
		filter {}

		links {
			"SDL2",
			"SDL2main",
			"SDL2_image",
			"SDL2_mixer",
			"SDL2_TTF",
		}

		includedirs {
			"./src/Header Files/",
			"./src/Header Files/Engine Code/",
			"./src/Header Files/Game Code/",
			"./devlib/include/",
		}

		files {
			"./**.txt",
		    "./**.md",
		    "./**.lua",
			"./src/Header Files/**.h",
			"./src/Header Files/Engine Code/**.h",
			"./src/Header Files/Game Code/**.h",
			"./src/Source Files/**.cpp",
			"./src/Header Files/Engine Code/**.cpp",
			"./src/Header Files/Game Code/**.cpp",
		}

		removefiles {
			"./gamefiles/**" ,
			"./Build/**"
		}
		
		vpaths {
			["Important/*"] = {"**.txt", "**.md", "**.lua"},
		} 

		--Post-Build
		postbuildcommands{ 
			{"{COPY} ../dlls/**.dll ../Build//bin//%{cfg.buildcfg}//%{cfg.platform}//"}
		}