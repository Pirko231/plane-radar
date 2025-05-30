cmake_minimum_required(VERSION 3.27)
project(CMakeSFMLProject LANGUAGES CXX)

# Ustawienie katalogu dla plików wykonywalnych
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Określenie wersji builda (Debug domyślnie)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 🟢 Ustawienie ścieżek do SFML (zmień na swoją lokalizację SFML)

set(SFML_ROOT "/opt/sfml-3")
set(CMAKE_PREFIX_PATH "/opt/sfml-3")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

add_compile_definitions(IMGUI)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/lib/imgui)
include_directories(${CMAKE_SOURCE_DIR}/lib/imgui/backends)
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/src/game/interfaces)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/game/gameObjects)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/game/gameObjects/obj)

find_package(OpenGL REQUIRED)

set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/lib/imgui")
add_library(imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui-SFML.cpp  # albo sfml, glfw, itd.
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)


find_package(SFML 3.0.0 COMPONENTS System Window Graphics Audio Network REQUIRED)


set(SFML_LIBS SFML::Graphics SFML::Window SFML::System SFML::Audio SFML::Network)


set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")

file(COPY "${RESOURCES_DIR}" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Tworzenie pliku wykonywalnego
add_executable(main 
    src/main.cpp 
    src/program.cpp

    src/game/map.cpp
    src/game/airportManager.cpp
    src/game/flightControl.cpp

    src/game/gameObjects/obj/plane.cpp
    src/game/gameObjects/obj/helicopter.cpp
    src/game/gameObjects/obj/airport.cpp
)

if(NOT MSVC)
	target_compile_options(main PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(main PRIVATE -Wno-unused-parameter)
endif()

# Ustawienie wersji standardu C++
target_compile_features(main PRIVATE cxx_std_20)

# Linkowanie SFML
target_link_libraries(main PRIVATE ${SFML_LIBS} imgui OpenGL::GL)
