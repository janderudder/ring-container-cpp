-- premake5.lua
workspace "C++17-Project-Workspace"
   configurations { "simple", "debug", "release" }

project "ring-container"

   kind        "ConsoleApp"
   objdir      "%{cfg.buildcfg}/obj"
   language    "C++"
   cppdialect  "C++17"
   location    "../"
   targetdir   "../bin/"
   targetname  "ring-container"

   files {
      "../src/**.cpp"
   }
   includedirs    { "../include" }
   links          { }

   enablewarnings { "all", "extra", "shadow", "unused" }

   filter "configurations:simple"
      defines  { "DEBUG" }
      symbols  "Off"
      disablewarnings { "unused" }

   filter "configurations:debug"
      defines  { "DEBUG" }
      symbols  "On"
      optimize "Debug"

   filter "configurations:release"
      symbols  "Off"
      defines  { "NDEBUG" }
      optimize "On"
