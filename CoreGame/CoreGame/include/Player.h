//
// Created by Jacopo Gasparetto on 30/08/22.
//

#ifndef COREGAME_PLAYER_H
#define COREGAME_PLAYER_H

#include <AnimatedSprite.hpp>
#include <Area2D.hpp>
#include <CollisionShape2D.hpp>
#include <Godot.hpp>
#include <Input.hpp>
#include <iostream>

class Player : public godot::Area2D {
GODOT_CLASS(Player, godot::Area2D)

    godot::AnimatedSprite *_animated_sprite;
    godot::CollisionShape2D *_collision_shape;
    godot::Input *_input;
    godot::Vector2 _screen_size;

public:
    real_t speed = 400;

    static void _register_methods();

    void _init() {};

    void _ready();

    void _process(const double p_delta);

//    void start(godot::Vector2 p_position);
//
//    void _on_Player_body_entered(godot::Node *_body);
};

#endif //COREGAME_PLAYER_H
