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

    set(LIBSODIUM "${PROJECT_SOURCE_DIR}/external/libsodium.dylib")
    if (NOT EXISTS "${LIBSODIUM}")
        message(FATAL_ERROR "libsodium not found at ${LIBSODIUM}. Please ensure it is built and available.")
    endif ()

    set(LIBZE "${PROJECT_SOURCE_DIR}/external/libze.dylib")
    if (NOT EXISTS "${LIBZE}")
        message(FATAL_ERROR "libze not found at ${LIBZE}. Please ensure it is built and available.")
    endif ()

    set(LIBZNB "${PROJECT_SOURCE_DIR}/external/libznb.dylib")
    if (NOT EXISTS "${LIBZNB}")
        message(FATAL_ERROR "libznb not found at ${LIBZNB}. Please ensure it is built and available.")
    endif ()

    set(LIB_LINK
        ${LIBSODIUM}
        ${LIBZE}
        ${LIBZNB}
    )

    set(LIB_INCLUDE "${PROJECT_SOURCE_DIR}/external/include")

    target_include_directories(${PROJECT_NAME} PUBLIC ${JNI_INCLUDE_DIRS} ${JNI_INCLUDE_OS_SPECIFIC} ${LIB_INCLUDE})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${JNI_LIBRARIES} ${LIB_LINK})
endfunction()