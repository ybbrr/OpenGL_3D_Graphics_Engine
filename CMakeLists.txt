cmake_minimum_required(VERSION 3.25)

project(OpenGL_3D_Graphics_Engine)

set(CMAKE_CXX_STANDARD 17)

if (EDITOR_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE})
	set(CMAKE_INSTALL_PREFIX ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP /O2 /GA /MD")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /O2 /GA /MD /arch:AVX2")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP /Od /GA /MDd")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /Od /MDd /arch:AVX2")
endif ()

set(WORKSPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(THIRD_PARTY_FOLDER ${WORKSPACE_DIR}/__third_parties__)

# Project Includes
include_directories(${WORKSPACE_DIR}/include)
include_directories(${WORKSPACE_DIR}/include/model)
include_directories(${WORKSPACE_DIR}/include/render)
include_directories(${WORKSPACE_DIR}/include/util)
include_directories(${WORKSPACE_DIR}/include/window)
include_directories(${WORKSPACE_DIR}/include/worlds)

# Third Party Includes
include_directories(${THIRD_PARTY_FOLDER}/glad/include)
include_directories(${THIRD_PARTY_FOLDER}/glfw/include)
include_directories(${THIRD_PARTY_FOLDER}/glm/include)
include_directories(${THIRD_PARTY_FOLDER}/stb_image/include)
include_directories(${THIRD_PARTY_FOLDER}/tinyobjloader/include)

# GLAD
set(GLAD_SOURCE_FILE ${THIRD_PARTY_FOLDER}/glad/source/glad.c)

# GLFW
link_directories(${THIRD_PARTY_FOLDER}/glfw/lib/${CMAKE_BUILD_TYPE})
set(GLFW_TARGET glfw3.lib)

# GLM
add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
link_directories(${THIRD_PARTY_FOLDER}/glm/lib/${CMAKE_BUILD_TYPE})
set(GLM_TARGET glm.lib)

# TINYOBJLOADER
add_compile_definitions(TINYOBJLOADER_IMPLEMENTATION)

# STB_IMAGE
add_compile_definitions(STB_IMAGE_IMPLEMENTATION)

add_executable(
	${PROJECT_NAME}

	${WORKSPACE_DIR}/source/main.cpp
	${GLAD_SOURCE_FILE}
	${WORKSPACE_DIR}/source/model/mesh.cpp
	${WORKSPACE_DIR}/source/model/model_3d.cpp
	${WORKSPACE_DIR}/source/model/shader.cpp
	${WORKSPACE_DIR}/source/render/camera.cpp
	${WORKSPACE_DIR}/source/render/keyboard.cpp
	${WORKSPACE_DIR}/source/render/renderer.cpp
	${WORKSPACE_DIR}/source/render/mouse.cpp
	${WORKSPACE_DIR}/source/window/window.cpp
	${WORKSPACE_DIR}/source/window/window_callbacks.cpp
	${WORKSPACE_DIR}/source/worlds/default_world.cpp
	${WORKSPACE_DIR}/source/worlds/world.cpp)

target_link_libraries(
	${PROJECT_NAME}

	PRIVATE

	${GLFW_TARGET}
	${GLM_TARGET})

set(OUTPUT_DIR ${CMAKE_INSTALL_PREFIX})
set(DIR_TO_COPY ${CMAKE_SOURCE_DIR}/__resources__)

install(TARGETS ${PROJECT_NAME}
		DESTINATION ${CMAKE_INSTALL_PREFIX})

# Add a custom command to copy the directory
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${DIR_TO_COPY} ${OUTPUT_DIR}
    COMMENT "Copying directory ${DIR_TO_COPY} to ${OUTPUT_DIR}")

# end of file
