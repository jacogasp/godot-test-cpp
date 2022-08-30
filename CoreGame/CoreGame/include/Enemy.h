//
// Created by Jacopo Gasparetto on 30/08/22.
//

#ifndef COREGAME_ENEMY_H
#define COREGAME_ENEMY_H

#include <Area2D.hpp>
#include <Sprite.hpp>
#include <Godot.hpp>
#include <Input.hpp>


class Enemy: public godot::Area2D {
    GODOT_CLASS(Enemy, godot::Area2D)

    godot::Input * _input;
    float speed = 200;

public:
    static void _register_methods();

    void _init();

    void _ready();

    void _process(const double p_delta);
};

#endif //COREGAME_ENEMY_H
