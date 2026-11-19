add_executable(game src/main.cpp)

target_link_libraries(game PRIVATE
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
)

if (MSVC)
    target_compile_options(game PRIVATE /W4 /permissive- /utf-8)
endif()

add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:game>/assets
)