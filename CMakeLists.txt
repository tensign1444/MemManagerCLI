cmake_minimum_required(VERSION 3.24)
project(MemManCLI C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES_DATA_STRUCT MemoryManager/DataStructures/Src/LinkedList/LinkedList.c MemoryManager/DataStructures/Util/Utility.c MemoryManager/DataStructures/Src/Queue/Queue.c MemoryManager/DataStructures/Src/Stack/Stack.c MemoryManager/DataStructures/Test/TestRun.c MemoryManager/DataStructures/Test/LinkedListTest.c MemoryManager/DataStructures/Test/StackTest.c MemoryManager/DataStructures/Test/StackTest.c MemoryManager/DataStructures/Include/LinkedList.h MemoryManager/DataStructures/Include/Queue.h MemoryManager/DataStructures/Include/Stack.h MemoryManager/DataStructures/Include/TestRun.h MemoryManager/DataStructures/Include/Utility.h)
set(SOURCE_FILES_MEM_MAN MemoryManager/Src/MemoryManager.c MemoryManager/Include/MemoryManager.h)

add_library(DataStructures ${SOURCE_FILES_DATA_STRUCT})
add_library(MemoryManager ${SOURCE_FILES_MEM_MAN})

add_executable(MemManCLI main.c)

target_link_libraries(MemoryManager PRIVATE DataStructures)
target_link_libraries(MemManCLI PRIVATE MemoryManager)