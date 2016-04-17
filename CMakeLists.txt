cmake_minimum_required (VERSION 3.5)
project (GeneticProgram)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SRC ${GeneticProgram_SOURCE_DIR}/src)
set(FN_SRC ${SRC}/functions)
set(SM_SRC ${SRC}/sample)

set(GP_CPP
  ${SRC}/gp.cpp
  ${SRC}/types.cpp
  ${SRC}/generate.cpp
  ${SRC}/select.cpp
  ${SRC}/cross.cpp
  ${SRC}/mutate.cpp
  ${SRC}/program.cpp
  ${SRC}/program_run.cpp
  ${SRC}/program_node.cpp
  ${SRC}/fitness.cpp
  ${SRC}/function.cpp
  ${SRC}/random.cpp
)

set(FN_CPP
  ${FN_SRC}/add.cpp
  ${FN_SRC}/sub.cpp
  ${FN_SRC}/div.cpp
  ${FN_SRC}/mul.cpp
  ${FN_SRC}/mod.cpp
  ${FN_SRC}/param.cpp
  ${FN_SRC}/value.cpp
  ${FN_SRC}/and.cpp
  ${FN_SRC}/or.cpp
  ${FN_SRC}/not.cpp  
)

set(SM_CPP
  ${SM_SRC}/regression.cpp
  ${SM_SRC}/classification.cpp
)

add_executable(GeneticProgram src/main.cpp ${GP_CPP} ${FN_CPP} ${SM_CPP})
