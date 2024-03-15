#pragma once

namespace Sandbox {
    /**
     * Boilerplate Object Class
     * 
     * Contains Update & Render Functions
    */
    class Object {
        public: 
            virtual void Init() {};
            virtual void Update(float dt) {};
            virtual void Render() {};
    };
}