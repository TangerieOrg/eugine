file(GLOB SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/**/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) 

find_package(raylib 3.0 CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} raylib Scrap)