cmake_minimum_required(VERSION 3.15)
project(TranslateUProject)

set(CMAKE_CXX_STANDARD 17)

# Flags condicionales seg n el compilador
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(TranslateUProject
    src/main.cpp

    src/dictionaryAVLTree/DictionaryAVLTree.cpp
    src/dictionaryAVLTree/DictionaryAVLTree.h

    src/dictionaryMenu/DictionaryMenu.cpp
    src/dictionaryMenu/DictionaryMenu.h

    src/translateManager/TranslateManager.cpp
    src/translateManager/TranslateManager.h

    src/utils/TranslationFileHandler/TranslationFileHandler.cpp
    src/utils/TranslationFileHandler/TranslationFileHandler.h

    src/utils/audioPlayer/AUDIOPlayer.cpp
    src/utils/audioPlayer/AUDIOPlayer.h
)
add_custom_command(TARGET TranslateUProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:TranslateUProject>/data
)



# Definiciones de plataforma para usar en #ifdef
if(WIN32)
    target_compile_definitions(TranslateUProject PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(TranslateUProject PRIVATE PLATFORM_MACOS)
endif()
