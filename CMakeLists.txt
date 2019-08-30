cmake_minimum_required(VERSION 3.8)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 0)
endif()

project(Editor VERSION 0.0.${VERSION_BUILD})

add_executable(Editor main.cpp
	painter_interface.h
	functional_interface.h
	figure.h
	figure_interface.h
)

set_property(TARGET Editor PROPERTY CXX_STANDARD 17)

set_target_properties(Editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(Editor
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(Editor PRIVATE
        /W4
    )
else ()
    target_compile_options(Editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS Editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT askimarhond@gmail.com)

include(CPack)
