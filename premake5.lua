workspace "brainfuckjit"
    configurations { "debug", "release" }

project "interpreter"
    kind "ConsoleApp"
    language "C++"
    warnings "Extra"

    files {
        "src/**.cpp",
        "include/**.hpp",
    }
    removefiles { "src/tests.cpp" }

    includedirs { "include" }

    filter "configurations:Debug"
        defines { "BFJIT_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "BFJIT_RELEASE" }
        optimize "On"

project "tests"
    kind "ConsoleApp"
    language "C++"
    warnings "Extra"

    files {
        "src/**.cpp",
        "include/**.hpp",
    }
    removefiles { "src/main.cpp" }

    includedirs { "include" }

    filter "configurations:Debug"
        defines { "BFJIT_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "BFJIT_RELEASE" }
        optimize "On"
