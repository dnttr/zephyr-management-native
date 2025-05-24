find_package(Java REQUIRED)
find_package(JNI REQUIRED)

function(prepare_dependencies)
    set(JNI_HEADER "jni.h")
    set(JNI_MD_HEADER "jni_md.h")

    if (NOT JAVA_FOUND OR NOT JNI_FOUND)
        message(FATAL_ERROR "Java or JNI not found.")
    endif ()

    find_path(JNI_H_PATH ${JNI_HEADER} PATHS ${JNI_INCLUDE_DIRS} REQUIRED)
    find_path(JNI_H_MD_PATH ${JNI_MD_HEADER} PATHS ${JNI_INCLUDE_DIRS} REQUIRED)

    if (NOT JNI_H_PATH OR NOT JNI_H_MD_PATH)
        message(FATAL_ERROR "JNI header not found.")
    endif ()

    message(STATUS "Found JNI.")

    set(JNI_INCLUDE_OS_SPECIFIC "${JNI_H_PATH}/${OS}")

    if (NOT JNI_INCLUDE_OS_SPECIFIC)
        message(FATAL_ERROR "JNI OS specific header not found.")
    endif ()

    target_include_directories(${PROJECT_NAME} PUBLIC ${JNI_INCLUDE_DIRS} ${JNI_INCLUDE_OS_SPECIFIC} )

    target_link_libraries(${PROJECT_NAME} PUBLIC ${JNI_LIBRARIES})
endfunction()