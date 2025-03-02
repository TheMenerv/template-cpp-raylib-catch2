FetchContent_Declare(
        raylib
        GIT_REPOSITORY  https://github.com/raysan5/raylib.git
        GIT_TAG         5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(My_Project main.cpp)

target_link_libraries(My_Project PRIVATE raylib)

# Copier les assets dans le répertoire de compilation
file(
        COPY ${CMAKE_SOURCE_DIR}/src/assets
        DESTINATION ${CMAKE_BINARY_DIR}/src
)