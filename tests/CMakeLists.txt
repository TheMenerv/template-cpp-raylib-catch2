FetchContent_Declare(
        Catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG         v3.8.0
)

FetchContent_MakeAvailable(Catch2)

# Surveiller un répertoire comme dépendance explicite
set_source_files_properties(
        ../src PROPERTIES GENERATED TRUE
)

# Collecter les fichiers (de manière classique ou récursive)
file(GLOB_RECURSE SOURCES ../src/*.cpp ../src/*.h)

# Supprimer un fichier spécifique
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp")

# Définir une commande qui regénère CMake quand quelque chose a changé
add_custom_target(
        RegenerateOnSourceChange ALL
        COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR} -B ${CMAKE_BINARY_DIR}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Regénération automatique de la configuration"
)

# Ajouter à l'exécutable
add_executable(Tests
        ${SOURCES}
        test.cpp
)

add_dependencies(Tests RegenerateOnSourceChange)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(Tests)