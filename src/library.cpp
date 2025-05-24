//
// Created by Damian Netter on 23/05/2025.
//

#include <iostream>
#include <jni.h>

int JNI_onload(JavaVM *vm, void *reserved) {
    //dlopen czy cos?
    std::cout << "XD" << std::endl;
    return JNI_VERSION_21;
}
