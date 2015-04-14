add_executable(myexec main.cpp rule.cpp)
add_library(game_library rule.cpp)
target_link_libraries(myexec game_library)
