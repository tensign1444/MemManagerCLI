cmake_minimum_required(VERSION 3.10)
project(MemManCLI LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCE_FILES_DATA_STRUCT
        MemoryManager/DataStructures/Src/LinkedList/LinkedList.c
        MemoryManager/DataStructures/Util/Utility.c
        )
set(HEADER_FILES_DATA_STRUCT
        MemoryManager/DataStructures/Include/LinkedList.h
        MemoryManager/DataStructures/Include/Utility.h
        )
set(SOURCE_FILES_MEM_MAN
        MemoryManager/Src/MemoryManager.c
        )
set(HEADER_FILES_MEM_MAN
        MemoryManager/Include/MemoryManager.h
        )

add_library(DataStructures ${SOURCE_FILES_DATA_STRUCT} ${HEADER_FILES_DATA_STRUCT})
add_library(MemoryManager ${SOURCE_FILES_MEM_MAN} ${HEADER_FILES_MEM_MAN})

# Set include directories for the libraries
target_include_directories(DataStructures PUBLIC MemoryManager/DataStructures/Include)
target_include_directories(MemoryManager PUBLIC MemoryManager/Include)

add_executable(MemManCLI main.c)
add_executable(MemoryManagerTest MemoryManager/Test/MemoryManagerTest.c)

target_link_libraries(MemoryManager PRIVATE DataStructures)
target_link_libraries(MemManCLI PRIVATE MemoryManager)
target_link_libraries(MemoryManagerTest PRIVATE MemoryManager)
