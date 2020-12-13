# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("RegApp")

if(MSVC)
add_compile_definitions(
	_CRT_SECURE_NO_WARNINGS
	_WIN32_WINNT=_WIN32_WINNT_WINXP
)
else(MSVC)
endif(MSVC)

# Include sub-projects.
add_subdirectory ("RegApp")
