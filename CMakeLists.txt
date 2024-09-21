cmake_minimum_required(VERSION 3.10)
project(ReserFISI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar el ejecutable
add_executable(ReserFISI 
src/main.cpp 
src/db.cpp 
src/routes/students_routes.cpp 
src/routes/index_routes.cpp
src/routes/controllers/students_controller.cpp
)

# Encontrar y configurar jsoncpp
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

# Incluir jsoncpp en tu proyecto
target_include_directories(ReserFISI PRIVATE ${JSONCPP_INCLUDE_DIRS})

# Enlazar jsoncpp a tu proyecto
target_link_libraries(ReserFISI PRIVATE ${JSONCPP_LIBRARIES})

# Encontrar y configurar libpq
pkg_check_modules(LIBPQ libpq)

# Agregar directorios de inclusión para libpq
target_include_directories(ReserFISI PRIVATE ${LIBPQ_INCLUDE_DIRS})

# Enlazar libpq a tu proyecto
target_link_libraries(ReserFISI PRIVATE ${LIBPQ_LIBRARIES})

# Incluir directorio de headers de Crow
target_include_directories(ReserFISI PRIVATE include)

# Copiar archivos de configuración
configure_file(${CMAKE_SOURCE_DIR}/db/data.json ${CMAKE_BINARY_DIR}/db/data.json COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/hola.json ${CMAKE_BINARY_DIR}/hola.json COPYONLY)
