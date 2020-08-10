cmake_minimum_required(VERSION 3.17.0)

project(GLIB VERSION 0.1.0)



find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(Playground
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

target_link_libraries(Playground PUBLIC GLEW::glew glfw glm)
target_compile_features(Playground PUBLIC cxx_std_20)