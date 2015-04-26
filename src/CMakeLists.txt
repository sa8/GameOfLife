find_package(Boost COMPONENTS system filesystem REQUIRED)
add_executable(game main.cpp rule.cpp)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
add_library(game_library rule.cpp)
target_link_libraries(game game_library)
target_link_libraries(game ${Boost_LIBRARIES})

