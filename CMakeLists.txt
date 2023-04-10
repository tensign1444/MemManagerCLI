cmake_minimum_required(VERSION 3.24)
project(MemManCLI C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES_DATA_STRUCT MemoryManager/DataStructures/Src/LinkedList/LinkedList.c MemoryManager/DataStructures/Util/Utility.c MemoryManager/DataStructures/Include/LinkedList.h MemoryManager/DataStructures/Include/Utility.h)
set(SOURCE_FILES_MEM_MAN MemoryManager/Src/MemoryManager.c MemoryManager/Include/MemoryManager.h)

add_library(DataStructures ${SOURCE_FILES_DATA_STRUCT})
add_library(MemoryManager ${SOURCE_FILES_MEM_MAN})

add_executable(MemManCLI main.c)
add_executable(MemoryManagerTest /MemoryManager/Test/MemoryManagerTest.c)

target_link_libraries(MemoryManager PRIVATE DataStructures)
target_link_libraries(MemManCLI PRIVATE MemoryManager)
target_link_libraries(MemoryManagerTest PRIVATE MemoryManager)