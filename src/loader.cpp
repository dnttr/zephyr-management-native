//
// Created by Damian Netter on 23/05/2025.
//

#include "loader.hpp"

#include <iostream>
#include <map>

#include "bindings.hpp"
#include "ZNBKit/vm_management.hpp"

int main(const int argc, char *argv[])
{
    std::vector<std::string> args[argc - 1];
    for (int i = 1; i < argc; ++i)
    {
        args->push_back(std::string(argv[i]));
    }

    if (args->size() != 1)
    {
        std::cerr << "Invalid arguments." << std::endl;
        return 1;
    }

    const auto argument = args->at(0);
    const size_t position = argument.find_last_of('=');

    if (position == std::string::npos)
    {
        std::cerr << "Invalid VM path format. Expected format: vm_path=<vm_classpath>" << std::endl;
        return 1;
    }

    const auto vm_path = argument.substr(position + 1, argument.length());

    if (!std::filesystem::exists(vm_path))
    {
        std::cerr << "VM path does not exist: " << vm_path << std::endl;
        return 1;
    }

    const auto vm_object = znb_kit::vm_management::create_and_wrap_vm(vm_path);
    const auto vm = vm_object.get();

    if (!vm)
    {
        std::cerr << "Failed to create VM object." << std::endl;
        return 1;
    }

    auto jni_env = vm->get_env();
    auto jvmti_env = vm->get_jvmti()->get().get_owner();

    znb_kit::jvmti_object jvmti(jni_env, jvmti_env);

    const std::unordered_multimap<std::string, znb_kit::reference> jvm_methods_map = {
        {"ffi_zm_open_session", znb_kit::reference(&bindings::ffi_zm_open_session, {"long[]"})},
        {"ffi_zm_close_session", znb_kit::reference(&bindings::ffi_zm_close_session, {"long"})},
        {
            "ffi_ze_encrypt_symmetric",
            znb_kit::reference(&bindings::ffi_ze_encrypt_symmetric, {"long", "byte[]", "byte[]", "byte[]"})
        },
        {
            "ffi_ze_decrypt_symmetric",
            znb_kit::reference(&bindings::ffi_ze_decrypt_symmetric, {"long", "byte[]", "byte[]", "byte[]"})
        },
        {
            "ffi_ze_encrypt_asymmetric",
            znb_kit::reference(&bindings::ffi_ze_encrypt_asymmetric, {"long", "byte[]", "byte[]"})
        },
        {
            "ffi_ze_decrypt_asymmetric",
            znb_kit::reference(&bindings::ffi_ze_decrypt_asymmetric, {"long", "byte[]", "byte[]"})
        },
        {"ffi_ze_nonce", znb_kit::reference(&bindings::ffi_ze_nonce, {"long", "int"})}
    };

    const znb_kit::klass_signature klass_signature(
        jni_env, "org/dnttr/zephyr/management/Bindings");

    jvmti.try_mapping_methods(klass_signature.get_owner(), jvm_methods_map);

    return 0;
}