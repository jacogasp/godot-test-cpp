//
// Created by Jacopo Gasparetto on 31/08/22.
//

#ifndef COREGAME_MAIN_H
#define COREGAME_MAIN_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <PathFollow2D.hpp>
#include <RandomNumberGenerator.hpp>
#include <Timer.hpp>
#include <SceneTree.hpp>

#include "HUD.h"
#include "Player.h"

class Main : public godot::Node {
  GODOT_CLASS(Main, godot::Node)

  int score{0};
  Player *_player;
  HUD *_hud;
  godot::Node2D *_start_position;
  godot::Timer *_mob_timer;
  godot::Timer *_start_timer;
  godot::Timer *_score_timer;
  godot::PathFollow2D *_mob_spawn_location;
  godot::Ref<godot::RandomNumberGenerator> _random;

public:
  godot::Ref<godot::PackedScene> mob_scene;

  void _init() { godot::Godot::print("Main init"); }
  void _ready();
  void game_over();
  void new_game();
  void _on_MobTimer_timeout();
  void _on_StartTimer_timeout();
  void _on_ScoreTimer_timeout();
  static void _register_methods();
};

#endif // COREGAME_MAIN_H
