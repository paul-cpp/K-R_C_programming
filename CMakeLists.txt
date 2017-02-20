cmake_minimum_required (VERSION 3.6)
SET(CMAKE_BUILD_TYPE Debug)
project (KnR_c_prax)

#set(GREETER_ROOT "..")
set (CMAKE_C_STANDARD 11)

# We want the built binaries to go in the bin folder
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(SRC_DIR ${PROJECT_SOURCE_DIR})                                      #корневая директория
set(CHAPTER_3_DIR ${PROJECT_SOURCE_DIR}/ch_3_flow_control)              #chapter 3
set(CHAPTER_4_DIR ${PROJECT_SOURCE_DIR}/ch_4_functions)                 #chapter 4
set(CHAPTER_5_DIR ${PROJECT_SOURCE_DIR}/ch_5_pointers_and_arrays)       #chapter 5

#исходные файлы
file(GLOB src_files ${SRC_DIR}/*.c)

#заголовочные файлы из соответствующих папок
file(GLOB include_files ${SRC_DIR}/*.h ${CHAPTER_3_DIR}/*.h  ${CHAPTER_4_DIR}/*.h  ${CHAPTER_5_DIR}/*.h )

# Gather the source files in greeter (some platform specfic)
#file(GLOB greeter_files_main ${SRC_DIR}/greeter/*.c)
#if( WIN32 )
#    file(GLOB_RECURSE greeter_files_win32 ${SRC_DIR}/greeter/win32/*.c)
#elseif( UNIX )
#    file(GLOB_RECURSE greeter_files_unix ${SRC_DIR}/greeter/unix/*.c)
#endif()

#set(greeter_files ${greeter_files_main} ${greeter_files_win32} ${greeter_files_unix})


#соберем все вместе
set(src_files ${src_files} ${common_files} ${include_files})   #${greeter_files}

# Build the binary
add_executable(KnR_c_prax  ${src_files})
