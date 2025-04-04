workspace "brainfuckjit"
    configurations { "debug", "release" }

project "interpreter"
    kind "ConsoleApp"
    language "C++"
    warnings "Everything"

    files {
        "src/**.cpp",
        "include/**.hpp",
    }

    includedirs { "include" }

    filter "configurations:Debug"
      defines { "BFJIT_DEBUG" }
      symbols "On"

    filter "configurations:Release"
      defines { "BFJIT_RELEASE" }
      optimize "On"
