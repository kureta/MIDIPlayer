cmake_minimum_required(VERSION 3.27)
project(MIDIPlayer)

set(CMAKE_CXX_STANDARD 20)

# ================= Dependencies =================
include(FetchContent)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

set(LIBREMIDI_VERSION v4.2.4)
find_package(libremidi QUIET) # QUIET or REQUIRED
if (NOT libremidi_FOUND) # If there's none, fetch and build libremidi
    FetchContent_Declare(
            libremidi
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/jcelerier/libremidi/archive/refs/tags/${LIBREMIDI_VERSION}.tar.gz
    )
    FetchContent_GetProperties(libremidi)
    if (NOT libremidi_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(libremidi)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${libremidi_SOURCE_DIR} ${libremidi_BINARY_DIR})
    endif ()
endif ()

# ================= Other stuff =================
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
add_executable(MIDIPlayer src/main.cpp src/utils.h src/RayApp.cpp src/RayApp.h src/Midi.cpp src/Midi.h)
target_link_libraries(${PROJECT_NAME} raylib libremidi)
