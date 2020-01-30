#=======================================================================================================================
# Define xlsx2csv target
#=======================================================================================================================

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(xlsx2csv)

add_executable(xlsx2csv xlsx2csv.cpp)
add_subdirectory(csv_engine)
add_subdirectory(OpenXLSX)
target_link_libraries(xlsx2csv PUBLIC OpenXLSX csv_engine)
target_include_directories(xlsx2csv PUBLIC ${OPENXLSX_INSTALLDIR}/include)

