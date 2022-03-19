find_package(Qt5 COMPONENTS Core Widgets Quick)
find_package(Qt5QuickCompiler)

set(QRC_FILES
    qml/qml.qrc)

set(MODEL_FILES
    model/pathmodel.h
    model/pathmodel.cpp
    model/eventmodel.h
    model/eventmodel.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/model)

add_definitions(-DPROJECT_NAME="Ross"
                -DPROJECT_DESC="Advanced Files Watching"
                -DVERSION="0.1"
                -DORGANIZATION_NAME="blooser"
                -DORGANIZATION_DOMAIN="https://github.com/blooser"
                )

add_executable(ross main.cpp paths.h paths.cpp ${MODEL_FILES} ${QRC_FILES})

target_link_libraries(ross
                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Quick)


