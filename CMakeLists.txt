cmake_minimum_required(VERSION 3.10)
project(ReserFISI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ejecutables
add_executable(ReserFISI 
    main.cpp 

    #db/db_setup.cpp

    src/db.cpp 
    src/db_operations.cpp
    src/db_utilities.cpp
    src/routes/students_routes.cpp
    src/routes/request_routes.cpp 
    src/routes/index_routes.cpp
    src/routes/controllers/students_controller.cpp
    src/routes/controllers/request_controller.cpp
    src/routes/controllers/index_controller.cpp
)

#jsoncpp
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

#dotenv 
find_package(laserpants_dotenv REQUIRED)

# Encontrar y configurar libpq
pkg_check_modules(LIBPQ libpq)
include_directories(${LIBPQ_INCLUDE_DIRS})

# Enlaces
target_link_libraries(ReserFISI PRIVATE ${LIBPQ_LIBRARIES} laserpants::dotenv ${JSONCPP_LIBRARIES})

# Crow
target_include_directories(ReserFISI PRIVATE include)
target_include_directories(ReserFISI PRIVATE ${JSONCPP_INCLUDE_DIRS})

# Para los jsons (Se borrará si es que no se necesita xd)
#configure_file(${CMAKE_SOURCE_DIR}/db/data.json ${CMAKE_BINARY_DIR}/db/data.json COPYONLY)
#configure_file(${CMAKE_SOURCE_DIR}/hola.json ${CMAKE_BINARY_DIR}/hola.json COPYONLY)
