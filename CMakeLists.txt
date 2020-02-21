cmake_minimum_required(VERSION 3.1.0)

project(QtExample)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(QT_BIN_PATH /home/art/Qt5.14.0/5.14.0/gcc_64/bin/)
set(CMAKE_PREFIX_PATH /home/art/Qt5.14.0/5.14.0/gcc_64/)

FILE(GLOB SOURCES ./*.[ch]pp)
MESSAGE("SOURCES = ${SOURCES}")
find_package(Qt5 COMPONENTS Core Quick Qml Widgets REQUIRED)

qt5_add_resources(RESOURCES res/res.qrc)
MESSAGE("RESOURCES = ${RESOURCES}")

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
