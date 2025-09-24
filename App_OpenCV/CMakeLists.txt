cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# paths
set(opencv_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/App_OpenCV/Assets/opencv/include)
set(opencv_LIB_DIR ${CMAKE_SOURCE_DIR}/App_OpenCV/Assets/opencv/lib)

include_directories(${opencv_INCLUDE_DIR})
link_directories(${opencv_LIB_DIR})


# Sources
set(SRC_DIR ${CMAKE_SOURCE_DIR}/App_OpenCV)
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

add_executable(Windows_OpenCV_App ${SOURCES})


# Link
target_link_libraries(Windows_OpenCV_App PRIVATE
    opencv_world4120
	opencv_world4120d
)


# DLL's
if(WIN32)
    add_custom_command(TARGET Windows_OpenCV_App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SRC_DIR}/opencv_world4120.dll
			${SRC_DIR}/opencv_world4120d.dll
            $<TARGET_FILE_DIR:Windows_OpenCV_App>
    )
endif()


# Copy assets
add_custom_command(TARGET Windows_OpenCV_App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SRC_DIR}/Assets/Input_Pictures
        $<TARGET_FILE_DIR:Windows_OpenCV_App>/Assets/Input_Pictures
)

