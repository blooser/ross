find_package(Qt5 COMPONENTS Core Widgets Quick)
find_package(Qt5QuickCompiler)

set(QRC_FILES
    qml/qml.qrc)

add_definitions(-DPROJECT_NAME="Ross"
                -DPROJECT_DESC="Advanced Files Watching"
                -DVERSION="0.1"
                -DORGANIZATION_NAME="blooser"
                -DORGANIZATION_DOMAIN="https://github.com/blooser"
                )

add_executable(ross main.cpp ${QRC_FILES})

target_link_libraries(ross
                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Quick)


