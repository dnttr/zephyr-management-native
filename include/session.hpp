//
// Created by Damian Netter on 25/05/2025.
//

#pragma once

#include "ZEKit/guarded_ptr.hpp"

/*
 * Class has to be deleted manually after use. (I think?)
 */

class session
{
    ze_kit::guarded_ptr shared_key;

    ze_kit::guarded_ptr public_key;
    ze_kit::guarded_ptr private_key;
};
