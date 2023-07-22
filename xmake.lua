add_rules("mode.debug", "mode.release", "mode.asan", "mode.check", "mode.tsan", "mode.lsan" ,"mode.ubsan","mode.valgrind")
add_rules("plugin.vsxmake.autoupdate")
add_rules("plugin.compile_commands.autoupdate")

set_languages("c17", "c++20")

set_exceptions("no-cxx")

set_warnings("allextra", "error")


target("Console-Game-Engine")
    set_kind("binary")
    add_files("Src/*.cpp")


