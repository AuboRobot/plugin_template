cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0097 NEW) # ``ExternalProject_Add()`` with ``GIT_SUBMODULES ""`` initializes no submodules.

project(
    json_rpc_test
    DESCRIPTION "Put a short description of your plugin here"
    LANGUAGES C CXX
    VERSION 1.0.0
)

set(CMAKE_DEBUG_POSTFIX "")

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    #set(PLUGIN_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/extensions)
    set(PLUGIN_OUTPUT_PATH $ENV{HOME}/arcs_ws/extensions)

    # NOTE: 下载AuboCaps接口，用户可以选择自己的版本
    include(FetchContent)
    if(NOT AuboCaps_POPULATED)
        FetchContent_Declare(
            AuboCaps
            URL "http://highouse.synology.me:8001/public/AuboCaps-0.2.3-Linux64.zip"
            DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/_deps"
        )
        FetchContent_Populate(AuboCaps)
    endif()

    find_package(AuboCaps REQUIRED PATHS ${aubocaps_SOURCE_DIR}/lib/cmake/AuboCaps)

    CPMAddPackage(json-rpc-cxx1
      NAME json-rpc-cxx1
      VERSION 0.3.0
      GIT_REPOSITORY https://gitee.com/aubo-robotics/json-rpc-cxx.git
      EXCLUDE_FROM_ALL YES
      OPTIONS
        "COMPILE_EXAMPLES OFF"
        "COMPILE_TESTS OFF"
    )
    CPMAddPackage(json1
      NAME json1
      VERSION 3.9.1
      GIT_REPOSITORY https://gitee.com/aubo-robotics/json-v3.9.1.git
      EXCLUDE_FROM_ALL YES
      OPTIONS
        "JSON_BuildTests OFF"
        "JSON_Install OFF"
    )
endif()

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

usFunctionGetResourceSource(TARGET json_rpc_test OUT _srcs)
usFunctionGenerateBundleInit(TARGET json_rpc_test OUT _srcs)

set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(BUILD_RPATH_USE_ORIGIN TRUE)

# 将新加入的文件添加到 cmake 进行项目管理
# 在 src 文件夹下新建 installation 和 program 两个文件夹
# 分别用来存储 inatallation 节点和 program 节点的相关文件 

set(program_src) 
set(install_src)
file(GLOB_RECURSE install_src "src/installation/*")
file(GLOB_RECURSE program_src "src/program/*")

add_subdirectory(src/user_service)
add_library(json_rpc_test SHARED ${_srcs}  ${program_src} ${install_src} src/activator.cpp)
target_link_libraries(json_rpc_test PRIVATE
    AuboCaps::aubo_caps_interface Qt5::Widgets
    )
target_include_directories(json_rpc_test
    PRIVATE
    "$<TARGET_PROPERTY:CppMicroServices,INTERFACE_INCLUDE_DIRECTORIES>"
)
set_property(TARGET json_rpc_test APPEND PROPERTY COMPILE_DEFINITIONS US_BUNDLE_NAME=json_rpc_test)
set_target_properties(json_rpc_test PROPERTIES
    LABELS aubo_caps
    OUTPUT_NAME json_rpc_test
    PREFIX ""
    DEBUG_POSTFIX ""
    INSTALL_RPATH "$\{ORIGIN\}/"
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_PATH}/json_rpc_test
)

usFunctionAddResources(
    TARGET json_rpc_test
    BUNDLE_NAME json_rpc_test
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/resources
    FILES "manifest.json")
usFunctionEmbedResources(TARGET json_rpc_test)

install(TARGETS json_rpc_test DESTINATION .)
install(FILES package.json DESTINATION .)
installBundleDepends(TARGET $<TARGET_FILE:json_rpc_test> DESTINATION .)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPACK_PACKAGE_VERSION_MAJOR "${json_rpc_test_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${json_rpc_test_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${json_rpc_test_VERSION_REVISION}")
    set(CPACK_GENERATOR "ZIP")
    set(CPACK_PACKAGE_NAME "json_rpc_test")
    set(CPACK_PACKAGE_CONTACT "your@aubo-robotics.com")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "your@aubo-robotics.com")
    set(CPACK_PACKAGE_FILE_NAME json_rpc_test-${json_rpc_test_VERSION})
    include(CPack)
endif()
