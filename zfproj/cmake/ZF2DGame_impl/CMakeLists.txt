cmake_minimum_required(VERSION 3.16)
project(ZF2DGame_impl)
set(ZF_ROOT_PATH "${PROJECT_SOURCE_DIR}/../../../../../../ZFFramework")
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

include("${PROJECT_SOURCE_DIR}/zfprojConfig.cmake" OPTIONAL)

file(GLOB_RECURSE ZF_SRC_FILES RELATIVE "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc/*.c"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc/*.cpp"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.c"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.cpp"
    )
if(COMMAND zfprojConfigBefore_ZF2DGame_impl)
    zfprojConfigBefore_ZF2DGame_impl(ZF2DGame_impl ZF_SRC_FILES)
endif()
add_library(ZF2DGame_impl SHARED ${ZF_SRC_FILES})
zfprojStripFILE(ZF2DGame_impl)
set_target_properties(ZF2DGame_impl PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(ZF2DGame_impl PUBLIC ZFLIB_ZF2DGame_impl=ZF_ENV_EXPORT)
if(COMMAND zfprojConfigAfter_ZF2DGame_impl)
    zfprojConfigAfter_ZF2DGame_impl(ZF2DGame_impl)
endif()

target_include_directories(ZF2DGame_impl PRIVATE "${PROJECT_SOURCE_DIR}/../../../zfsrc")

function(ZFAddLib ZF_LIB_NAME_)
    target_include_directories(ZF2DGame_impl PRIVATE "${ZF_ROOT_PATH}/_release/cmake/all/include")

    target_link_directories(ZF2DGame_impl PUBLIC "${ZF_ROOT_PATH}/_release/cmake/module/${ZF_LIB_NAME_}/lib")
    target_link_libraries(ZF2DGame_impl PRIVATE ${ZF_LIB_NAME_})
endfunction()

ZFAddLib(ZFCore)
ZFAddLib(ZFUtility)
ZFAddLib(ZFAlgorithm)
ZFAddLib(ZFUIKit)
ZFAddLib(ZFUIWidget)
ZFAddLib(ZF_impl)
ZFAddLib(ZF2DGame)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfsrc/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZF2DGame_impl/include"
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
install(
    TARGETS ZF2DGame_impl
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZF2DGame_impl/lib"
    )
if(WIN32)
    execute_process(COMMAND "${ZF_ROOT_PATH}\\tools\\util\\copy_res.bat" "${PROJECT_SOURCE_DIR}\\..\\..\\..\\zfres\\" "${ZF_ROOT_PATH}\\_release\\cmake\\module\\ZF2DGame_impl\\zfres")
else()
    execute_process(COMMAND sh "${ZF_ROOT_PATH}/tools/util/copy_res.sh" "${PROJECT_SOURCE_DIR}/../../../zfres/" "${ZF_ROOT_PATH}/_release/cmake/module/ZF2DGame_impl/zfres")
endif()

install(
    DIRECTORY "${ZF_ROOT_PATH}/_release/cmake/module/ZF2DGame_impl/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/all"
    )

