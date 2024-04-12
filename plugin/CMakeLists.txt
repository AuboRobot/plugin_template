cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0097 NEW) # ``ExternalProject_Add()`` with ``GIT_SUBMODULES ""`` initializes no submodules.

project(
    %{ProjectName}
    DESCRIPTION "%{Description}"
    LANGUAGES C CXX
    VERSION 1.0.0
)

set(CMAKE_DEBUG_POSTFIX "")

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(PLUGIN_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/extensions)

    # NOTE: 下载AuboCaps接口，用户可以选择自己的版本
    include(FetchContent)
    if(NOT AuboCaps_POPULATED)
        FetchContent_Declare(
            AuboCaps
            URL "https://download.aubo-robotics.cn/sdk/AuboCaps-0.5.2-Linux_x86_64.zip"
            DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/_deps"
        )
        FetchContent_Populate(AuboCaps)
    endif()

    find_package(AuboCaps REQUIRED PATHS ${aubocaps_SOURCE_DIR}/lib/cmake/AuboCaps)
elseif(NOT PLUGIN_OUTPUT_PATH)
    set(PLUGIN_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/extensions)
endif()

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

usFunctionGetResourceSource(TARGET %{ProjectName} OUT _srcs)
usFunctionGenerateBundleInit(TARGET %{ProjectName} OUT _srcs)

set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(BUILD_RPATH_USE_ORIGIN TRUE)

# 将新加入的文件添加到 cmake 进行项目管理
# 在 src 文件夹下新建 installation 和 program 两个文件夹
# 分别用来存储 inatallation 节点和 program 节点的相关文件 

set(program_src) 
set(install_src)
# file(GLOB_RECURSE install_src "src/installation/*")
# file(GLOB_RECURSE program_src "src/program/*")

add_library(%{ProjectName} SHARED ${_srcs}  ${program_src} ${install_src} src/activator.cpp)
target_link_libraries(%{ProjectName} PRIVATE
    AuboCaps::aubo_caps_interface Qt5::Widgets
    )
target_include_directories(%{ProjectName}
    PRIVATE
    "$<TARGET_PROPERTY:CppMicroServices,INTERFACE_INCLUDE_DIRECTORIES>"
)
set_property(TARGET %{ProjectName} APPEND PROPERTY COMPILE_DEFINITIONS US_BUNDLE_NAME=%{ProjectName})
set_target_properties(%{ProjectName} PROPERTIES
    LABELS aubo_caps
    OUTPUT_NAME %{ProjectName}
    PREFIX ""
    DEBUG_POSTFIX ""
    INSTALL_RPATH "$\\{ORIGIN\\}/"
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_PATH}/%{ProjectName}
)

usFunctionAddResources(
    TARGET %{ProjectName}
    BUNDLE_NAME %{ProjectName}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/resources
    FILES "manifest.json")
usFunctionEmbedResources(TARGET %{ProjectName})

install(TARGETS %{ProjectName} DESTINATION .)
install(FILES package.json DESTINATION .)
installBundleDepends(TARGET $<TARGET_FILE:%{ProjectName}> DESTINATION .)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPACK_PACKAGE_VERSION_MAJOR "${%{ProjectName}_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${%{ProjectName}_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${%{ProjectName}_VERSION_REVISION}")
    set(CPACK_GENERATOR "ZIP")
    set(CPACK_PACKAGE_NAME "%{ProjectName}")
    set(CPACK_PACKAGE_CONTACT "%{Email}")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "%{Email}")
    set(CPACK_PACKAGE_FILE_NAME %{ProjectName}-${%{ProjectName}_VERSION})
    include(CPack)
endif()
