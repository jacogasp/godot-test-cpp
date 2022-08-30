//
// Created by Jacopo Gasparetto on 30/08/22.
//
#include "Player.h"

void Player::_ready() {
    _animated_sprite = get_node<godot::AnimatedSprite>("AnimatedSprite");
    _collision_shape = get_node<godot::CollisionShape2D>("CollisionShape2D");
    _input = godot::Input::get_singleton();
    _screen_size = get_viewport_rect().size;
    godot::Godot::print("Player ready");
}

void Player::_register_methods() {
    godot::register_method((char *) "_ready", &Player::_ready);
    godot::register_method((char *) "_process", &Player::_process);
    godot::register_property((char *)"speed", &Player::speed, (real_t)200.0f);
}

void Player::_process(const double p_delta) {
    godot::Vector2 velocity{ 0, 0 };
    velocity.x = _input->get_action_strength("move_right") - _input->get_action_strength("move_left");
    velocity.y = _input->get_action_strength("move_down") - _input->get_action_strength("move_up");
    if (velocity.length() > 0) {
        velocity = velocity.normalized() * speed;
        _animated_sprite->play();
    } else {
        _animated_sprite->stop();
    }

    godot::Vector2 position = get_position();
    position += velocity * (real_t) p_delta;
    position.x = godot::Math::clamp(position.x, (real_t) 0.0, _screen_size.x);
    position.y = godot::Math::clamp(position.y, (real_t) 0.0, _screen_size.y);
    set_position(position);
}