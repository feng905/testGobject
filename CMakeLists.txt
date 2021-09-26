cmake_minimum_required(VERSION 2.8)
project(testGobject)
include(FindPkgConfig)

#pkg_check_modules(GLIB2 REQUIRED glib-2.0)
pkg_check_modules(GOBJECT2 REQUIRED gobject-2.0)

aux_source_directory(src SRC_LIST)

include_directories(
    .
    ${SRC_LIST}
    ${GLIB2_INCLUDE_DIRS}
    ${GOBJECT2_INCLUDE_DIRS}
    )

set(COMMON_LIBS
        ${GOBJECT2_LIBRARIES}
    )

add_executable(${PROJECT_NAME} "main.c" ${SRC_LIST})



target_link_libraries(${PROJECT_NAME} ${COMMON_LIBS})
