#include "Controller.h"

void godot::Controller::_init()
{
    motion = Vector2(0, 0);
    godot::Godot::print("Init controller");
}

void godot::Controller::_register_methods()
{
    register_method((char*)"_process", &Controller::_process);
    register_method((char*)"UpdateMotionFromInput", &Controller::UpdateMotionFromInput);
    register_property((char*)"speed", &Controller::speed, 200);
}

void godot::Controller::_process()
{
    UpdateMotionFromInput();
    move_and_slide(motion);
}

void godot::Controller::UpdateMotionFromInput()
{
    motion = Vector2(0, 0);
    Input* input = Input::get_singleton();
    
    if(input->is_action_pressed("ui_up")) {
        motion.y -= speed;
    }
    
    if(input->is_action_pressed("ui_down")) {
        motion.y += speed;
    }
    
    if(input->is_action_pressed("ui_left")) {
        motion.x -= speed;
    }
    
    if(input->is_action_pressed("ui_right")) {
        motion.x += speed;
    }
}