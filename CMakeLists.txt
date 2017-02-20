cmake_minimum_required (VERSION 3.6)
SET(CMAKE_BUILD_TYPE Debug)
project (KnR_c_prax)

set (CMAKE_C_STANDARD 11)

set(SRC_DIR ${PROJECT_SOURCE_DIR})                                      #корневая директория
set(CHAPTER_3_DIR ${PROJECT_SOURCE_DIR}/ch_3_flow_control)              #chapter 3
set(CHAPTER_4_DIR ${PROJECT_SOURCE_DIR}/ch_4_functions)                 #chapter 4
set(CHAPTER_5_DIR ${PROJECT_SOURCE_DIR}/ch_5_pointers_and_arrays)       #chapter 5

#исходные файлы
file(GLOB src_files ${SRC_DIR}/*.c)

#заголовочные файлы из соответствующих папок
file(GLOB include_files ${SRC_DIR}/*.h ${CHAPTER_3_DIR}/*.h  ${CHAPTER_4_DIR}/*.h  ${CHAPTER_5_DIR}/*.h )
file(GLOB include_cfiles ${CHAPTER_3_DIR}/*.c  ${CHAPTER_4_DIR}/*.c  ${CHAPTER_5_DIR}/*.c )

#соберем все вместе
set(src_files ${src_files} ${common_files} ${include_files} ${include_cfiles} )

# Build the binary
add_executable(KnR_c_prax  ${src_files})
