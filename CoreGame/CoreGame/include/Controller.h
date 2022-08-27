#ifndef GDNATIVEEXPLORATION_CONTROLLER_H
#define GDNATIVEEXPLORATION_CONTROLLER_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>

namespace godot {
    class Controller : public KinematicBody2D {
    private:

        // We need to register some information to Godot
        GODOT_CLASS(Controller, KinematicBody2D)
    public:
        static void _register_methods();
        void _init();
        void _process();
        
        Controller() = default;
        ~Controller() = default;
        

        // Member fields
        int speed = 200;
        Vector2 motion;
        

        // Member functions
        void UpdateMotionFromInput();
    };
}

#endif //GDNATIVEEXPLORATION_CONTROLLER_H