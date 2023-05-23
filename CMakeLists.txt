cmake_minimum_required(VERSION 3.21)
project(EmployeeSystemFrontend)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/icons/appIcon.rc")

add_executable(EmployeeSystemFrontend
        WIN32
         mainwindow.h
         mainwindow.cpp
         pttab.h
         pttab.cpp
         descriptionfield.h
         descriptionfield.cpp
         database_files/database.h
         database_files/database.cpp
         database_files/employee.h
         database_files/employee.cpp
         database_files/task.h
         database_files/task.cpp
         database_files/rank.h
         database_files/rank.cpp
         writepanel.h
         messagewindow.h
         messagewindow.cpp
         writepanel.cpp
         lockscreen.h
         lockscreen.cpp
         leftpanel.h
         leftpanel.cpp
         rightpanel.h
         rightpanel.cpp
         addemployeemenu.h
         addemployeemenu.cpp
         addtaskmenu.h
         addtaskmenu.cpp
         addvacationmenu.h
         addvacationmenu.cpp
         searchbyname.h
         searchbyname.cpp
         database_files/document.h
         database_files/document.cpp
         database_files/payment.h
         database_files/payment.cpp
         database_files/department.h
         database_files/department.cpp
         database_files/vacation.h
         database_files/vacation.cpp
         database_files/employee_role.h
         database_files/employee_role.cpp
         database_files/role.h
         database_files/role.cpp
         database_files/roleauthority.h
         database_files/roleauthority.cpp
         database_files/authority.h
         database_files/authority.cpp
         database_files/event.h
         database_files/event.cpp
  	 main.cpp
         pictures.qrc
     ${APP_ICON_RESOURCE_WINDOWS}
 )

target_link_libraries(EmployeeSystemFrontend
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
