# sanity note: if running cmake inside an IDE it will not find any environment variable changes [win10] 
# until relaunching the IDE (at least for VSCode)
cmake_minimum_required(VERSION 3.13)

# set the project name
project(MetaBlade VERSION 0.1)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX d)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")  # enable parallel builds
	set(PATH)
endif()

# ===BOOST===
# Any issues then use https://cmake.org/cmake/help/latest/module/FindBoost.html

if(WIN32)
# Set these to derive your filename 
# ex - "libboost_serialization-mgw8-mt-d-x64-1_74.a"
	set(Boost_COMPILER "-mgw8") # cmake will grab "mgw" but not "mgw8" so specify your own if it's different
	set(Boost_USE_MULTITHREADED      ON)
	set(Boost_USE_DEBUG_LIBS         ON)
	set(Boost_USE_STATIC_LIBS ON)
	set(Boost_ARCHITECTURE "-x64")
endif()
# set(Boost_DEBUG 1) # Uncomment for more info if cmake can't get your boost
message("Boost_INCLUDE_DIR = ${Boost_INCLUDE_DIR}")
set(BOOST_LIBS serialization system) # ALL REQUIRED BOOST LIBS GO HERE
find_package(Boost 1.73.0 REQUIRED COMPONENTS ${BOOST_LIBS})

# ===BOOST_END===

# ===CURSES===
if(WIN32)
	set(CURSES_WIN_DEPS gdi32 comdlg32 Winmm)
	message("curses.h Directory: " ${CURSES_INCLUDE_DIR})
	find_path(CURSES_INCLUDE_DIR curses.h HINTS $ENV{CURSES_INCLUDE_PATH} REQUIRED)
	# set(CURSES_LIBRARY "$ENV{CURSES_LIBRARY}")
	message("Curses Library Path: " ${CURSES_LIBRARY})
	find_library(CURSES_LIBRARY pdcurses REQUIRED HINTS $ENV{CURSES_LIBRARY})
else()
	message("Curses_INCLUDE_DIR = ${CURSES_INCLUDE_DIR}")
	message("CURSES_LIBRARY = ${CURSES_LIBRARY}")
	find_package(Curses REQUIRED)
endif()
# ===CURSES_END===

# target include/link localizes the includes and libs to the target as opposed to the entire subdirs
# https://stackoverflow.com/questions/31969547/what-is-the-difference-between-include-directories-and-target-include-directorie

set(CMAKE_CXX_FLAGS "-g -Wall -Wuninitialized")
# add the executable
set(SOURCES main.cpp Map.cpp Tile.cpp Creature.cpp Serialize.h)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
								PUBLIC ${PROJECT_BINARY_DIR}
								${Boost_INCLUDE_DIR}
								${CURSES_INCLUDE_DIR}
							)
target_link_libraries(${PROJECT_NAME} 
						PUBLIC
						${Boost_LIBRARIES} 
						${CURSES_LIBRARY}
						${CURSES_WIN_DEPS})
