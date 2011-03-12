-- sudoku, premake4.lua

if _ACTION == "clean" then
	os.rmdir("bin")
	os.rmdir("build")
end

solution "sudoku"
	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }
	
	buildflags = { "fatal-warnings" }
   
	includedirs { "inc" }
 
	-- A project defines one build target
	project "sudoku"
		kind "ConsoleApp"
		language "C++"
		files { "**.h", "**.cpp" }
 
		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
 
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
