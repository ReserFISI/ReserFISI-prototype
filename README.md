# ReserFISI-prototype (Backend)

Proyecto realizado por el grupo 2 de BD

## Requerimientos

Para que se pueda buildear correctamente el proyecto

### Externo

- Compilador de c++
- Cmake
- PostgreSQL

### Librerías

- [Jsoncpp](https://github.com/open-source-parsers/jsoncpp)
- [Libpq](https://www.postgresql.org/download/) 
- [Crow](https://crowcpp.org/master/)
- [Dotenvcpp](https://github.com/laserpants/dotenv-cpp)
- [Libcurl](https://curl.se/download.html)

> Todas las librerías deben estar instaladas a nivel de sistema

## Buildeo


Creas un directorio para el buildeo

~~~
    mkdir build
~~~

Haces Cmake

~~~
    cmake ..
~~~

Y haces make

~~~
    make
~~~

Ejecutas el resultante
~~~
    ./ReserFISI
~~~