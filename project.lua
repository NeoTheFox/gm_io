solution "io"
	flags {
			"NoPCH",
			"Symbols",
			"EnableSSE",
			"StaticRuntime",
			"NoEditAndContinue"
	}
    includedirs {
                  "include/",
                  "source/LuaOO/include/"
    }

	language "c++"
	location("build/"..os.get().."/")
	targetdir("build/"..os.get().."/bin/")

        if os.get() == "linux" then
            buildoptions {"-fPIC"}
            linkoptions  {"-fPIC"}
        end

        configurations {"Server", "Client"}
        configuration "Server"
            defines {"NDEBUG", "SERVER"}
            flags   {"Optimize", "FloatFast"}

            if os.get() == "windows" then
                defines {"WIN32"}
                targetname "gmsv_io_win32"
            elseif os.get() == "linux" then
                defines {"LINUX"}
                targetname "gmsv_io_linux"
            end
            targetname "gmsv_io_win32"
        configuration "Client"
            defines {"NDEBUG", "CLIENT"}
            flags   {"Optimize", "FloatFast"}

            if os.get() == "windows" then
                defines {"WIN32"}
                targetname "gmcl_io_win32"
            elseif os.get() == "linux" then
                defines {"LINUX"}
                targetname "gmcl_io_linux"
            end

        project "LuaOO"
            defines {"GMMODULE"}
            files   {
                      "source/LuaOO/source/**.*",
                      "source/LuaOO/include/**.*"
            }
            kind "StaticLib"
            targetname "LuaOO"
        project "io"
    		links   {"LuaOO"}
            defines {"GMMODULE"}
            files   {
            	      "source/io/**.*"
            }
            kind "SharedLib"

