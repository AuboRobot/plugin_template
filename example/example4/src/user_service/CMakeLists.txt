set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(rpc_test_srcs)
set(rpc_test_hdrs)
set(rpc_test_hpps)
file(GLOB_RECURSE rpc_test_srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE rpc_test_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE rpc_test_hpps "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

find_package(Thread)

# user_service 服务端
add_executable(user_service
   httplib.h
   # user_service_test.h
   start_user_service_demo.cpp
   user_service_rpc_service.cpp
   user_service_rpc_service.h
   user_service.h
   user_service.cpp
   # user_service_test_demon.cpp
   test.h
   cpphttplibconnector.hpp
    )

install(TARGETS user_service DESTINATION .)
target_include_directories(user_service PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}  )
target_link_libraries(user_service PUBLIC json-rpc-cxx nlohmann_json)
target_link_libraries(user_service PRIVATE ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(user_service PROPERTIES
  OUTPUT_NAME user_service
  #RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/extensions
  RUNTIME_OUTPUT_DIRECTORY $ENV{HOME}/arcs_ws/extensions/json_rpc_test
  PREFIX ""
  DEBUG_POSTFIX ""
  INSTALL_RPATH "$\{ORIGIN\}/lib"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

