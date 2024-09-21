cmake_minimum_required(VERSION 3.10)
project(ReserFISI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ReserFISI index.cpp db.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

# Incluir jsoncpp en tu proyecto
target_include_directories(ReserFISI PRIVATE ${JSONCPP_INCLUDE_DIRS})

# Enlazar jsoncpp a tu proyecto
target_link_libraries(ReserFISI PRIVATE ${JSONCPP_LIBRARIES})

# Incluir y enlazar libpq
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQ libpq)

# Agregar directorios de inclusión para libpq
target_include_directories(ReserFISI PRIVATE ${LIBPQ_INCLUDE_DIRS})

# Enlazar libpq a tu proyecto
target_link_libraries(ReserFISI PRIVATE ${LIBPQ_LIBRARIES})

#crow
target_include_directories(ReserFISI PRIVATE include)

configure_file(${CMAKE_SOURCE_DIR}/data.json ${CMAKE_BINARY_DIR}/data.json COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/hola.json ${CMAKE_BINARY_DIR}/hola.json COPYONLY)
