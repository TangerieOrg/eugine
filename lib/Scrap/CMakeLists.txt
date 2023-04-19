file(GLOB SOURCE_FILES src/*.cpp)
add_library(Scrap ${SOURCE_FILES})
target_include_directories(Scrap PUBLIC include)