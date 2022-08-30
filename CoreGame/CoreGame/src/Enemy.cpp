//
// Created by Jacopo Gasparetto on 30/08/22.
//

#include "Enemy.h"

void Enemy::_init() {
    godot::Godot::print("Enemy init");
}

void Enemy::_ready() {
    _input = godot::Input::get_singleton();
}

void Enemy::_process(const double p_delta) {
    godot::Vector2 velocity{ 0, 0 };
    velocity.x = _input->get_action_strength("move_right") - _input->get_action_strength("move_left");
    velocity.y = _input->get_action_strength("move_down") - _input->get_action_strength("move_up");
    velocity = velocity.normalized() * speed;
    godot::Vector2 position = get_position();
    position += velocity * (real_t) p_delta;
    set_position(position);
}

void Enemy::_register_methods() {
    godot::register_method("_init", &Enemy::_init);
    godot::register_method("_ready", &Enemy::_ready);
    godot::register_method("_process", &Enemy::_process);
}