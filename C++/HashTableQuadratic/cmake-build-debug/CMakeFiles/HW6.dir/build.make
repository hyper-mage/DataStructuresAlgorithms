# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\HW6.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\HW6.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\HW6.dir\flags.make

CMakeFiles\HW6.dir\main.cpp.obj: CMakeFiles\HW6.dir\flags.make
CMakeFiles\HW6.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW6.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HW6.dir\main.cpp.obj /FdCMakeFiles\HW6.dir\ /FS -c "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\main.cpp"
<<

CMakeFiles\HW6.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW6.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\Hostx86\x86\cl.exe > CMakeFiles\HW6.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\main.cpp"
<<

CMakeFiles\HW6.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW6.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HW6.dir\main.cpp.s /c "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\main.cpp"
<<

# Object files for target HW6
HW6_OBJECTS = \
"CMakeFiles\HW6.dir\main.cpp.obj"

# External object files for target HW6
HW6_EXTERNAL_OBJECTS =

HW6.exe: CMakeFiles\HW6.dir\main.cpp.obj
HW6.exe: CMakeFiles\HW6.dir\build.make
HW6.exe: CMakeFiles\HW6.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW6.exe"
	"C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HW6.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\HW6.dir\objects1.rsp @<<
 /out:HW6.exe /implib:HW6.lib /pdb:"C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug\HW6.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\HW6.dir\build: HW6.exe

.PHONY : CMakeFiles\HW6.dir\build

CMakeFiles\HW6.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW6.dir\cmake_clean.cmake
.PHONY : CMakeFiles\HW6.dir\clean

CMakeFiles\HW6.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6" "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6" "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug" "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug" "C:\Users\56kbps\Desktop\Spring2019stuff\CS 5343\HW\HW6\cmake-build-debug\CMakeFiles\HW6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\HW6.dir\depend

