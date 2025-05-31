//
// Created by Damian Netter on 24/05/2025.
//

#include "bindings.hpp"

jint bindings::ffi_zm_open_session(JNIEnv *env, jlongArray)
{
    return 0;
}

jint bindings::ffi_zm_close_session(JNIEnv *env, jlong)
{
    return 0;
}

jint bindings::ffi_ze_encrypt_symmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray, jbyteArray)
{
    return 0;
}

jint bindings::ffi_ze_decrypt_symmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray, jbyteArray)
{
    return 0;
}

jint bindings::ffi_ze_encrypt_asymmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray)
{
    return 0;
}

jint bindings::ffi_ze_decrypt_asymmetric(JNIEnv *env, jlong, jbyteArray, jbyteArray)
{
    return 0;
}

jint bindings::ffi_ze_nonce(JNIEnv *env, jlong, jint)
{
    return 0;
}
