//
// Created by Damian Netter on 24/05/2025.
//

#pragma once

#include <jni.h>

class bindings
{
public:
    static jint ffi_zm_open_session(JNIEnv *env, jlongArray);
    static jint ffi_zm_close_session(JNIEnv *env, jlong);

    static jint ffi_ze_encrypt_symmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray, jbyteArray);
    static jint ffi_ze_decrypt_symmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray, jbyteArray);

    static jint ffi_ze_encrypt_asymmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray);
    static jint ffi_ze_decrypt_asymmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray);

    static jint ffi_ze_nonce(JNIEnv *env, jlong, jint);
};
