#pragma once
#define CHUNK_SIZE 16 // Fixed Chunk Size since we will be using "Cubic Chunks" method.

#include "../object.hpp"

namespace Sandbox {

    class Chunk : public Object {
        public:
            Chunk() {}

    };
}