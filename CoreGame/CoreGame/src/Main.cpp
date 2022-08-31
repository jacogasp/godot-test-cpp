//
// Created by Jacopo Gasparetto on 31/08/22.
//

#include "Main.h"

void Main::_ready() {
  _hud = get_node<HUD>("HUD");
  _player = get_node<Player>("Player");
  _start_position = get_node<godot::Node2D>("StartPosition");
  _mob_spawn_location = get_node<godot::PathFollow2D>("MobPath/MobSpawnLocation");
  _mob_timer = get_node<godot::Timer>("MobTimer");
  _start_timer = get_node<godot::Timer>("StartTimer");
  _score_timer = get_node<godot::Timer>("ScoreTimer");
  _random = static_cast<godot::Ref<godot::RandomNumberGenerator>>(godot::RandomNumberGenerator::_new());
  _random->randomize();
  godot::Godot::print("Main scene ready");
}

void Main::new_game() {
  godot::Godot::print("New game!");
  score = 0;
  _player->start(_start_position->get_position());
  _start_timer->start();
}

void Main::game_over() {
  _score_timer->stop();
  _mob_timer->stop();
}


void Main::_on_MobTimer_timeout() {
  auto *mob = mob_scene->instance();
  _mob_spawn_location->set_offset(static_cast<real_t>(_random->randi()));
  auto direction = _mob_spawn_location->get_rotation() + (real_t)Math_PI / 2;
  mob->set("position", _mob_spawn_location->get_position());
  direction += _random->randf_range((real_t)-Math_PI / 4, (real_t)Math_PI / 4);
  mob->set("rotation", direction);
  godot::Vector2 velocity{_random->randf_range(150.0, 250.0), 0.0};
  mob->set("linear_velocity", velocity);
  add_child(mob);
}

void Main::_on_ScoreTimer_timeout() { score += 1; }

void Main::_on_StartTimer_timeout() {
  _mob_timer->start();
  _score_timer->start();
}

void Main::_register_methods() { 
  godot::register_method("_ready", &Main::_ready); 
    godot::register_method("new_game", &Main::new_game);
    godot::register_method("game_over", &Main::game_over);
    godot::register_method("_on_MobTimer_timeout", &Main::_on_MobTimer_timeout);
    godot::register_method("_on_StartTimer_timeout", &Main::_on_StartTimer_timeout);
    godot::register_method("_on_ScoreTimer_timeout", &Main::_on_ScoreTimer_timeout);
    godot::register_property("mob_scene", &Main::mob_scene, static_cast<godot::Ref<godot::PackedScene>>(nullptr));
}