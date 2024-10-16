cmake_minimum_required(VERSION 3.10)
project(ReserFISI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ejecutables
add_executable(ReserFISI 
    main.cpp 
    
    db/db_setup.cpp
    email_service/email.cpp

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
find_package(PkgConfig REQUIRED)

pkg_check_modules(JSONCPP jsoncpp)
pkg_check_modules(LIBPQ libpq)

#find_packages
find_package(laserpants_dotenv REQUIRED) #dotenv
find_package(CURL REQUIRED) #libcurl

#Directorios
include_directories(${CURL_INCLUDE_DIRS})
include_directories(${LIBPQ_INCLUDE_DIRS})

#Enlaces
target_link_libraries(ReserFISI PRIVATE ${LIBPQ_LIBRARIES} laserpants::dotenv ${JSONCPP_LIBRARIES} ${CURL_LIBRARIES})
target_include_directories(ReserFISI PRIVATE include ${JSONCPP_INCLUDE_DIRS})

