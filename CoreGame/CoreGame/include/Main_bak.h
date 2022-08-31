//
// Created by Jacopo Gasparetto on 30/08/22.
//

#ifndef COREGAME_MAIN_BAK_H
#define COREGAME_MAIN_BAK_H
//
//#include "HUD.h"
//#include "Player.h"
//#include <AudioStream.hpp>
#include <Godot.hpp>
#include <Node.hpp>
//#include <PathFollow2D.hpp>
//#include <RandomNumberGenerator.hpp>
//#include <PackedScene.hpp>
//#include <Timer.hpp>
//#include <SceneTree.hpp>

class Main_bak : public godot::Node {
  GODOT_CLASS(Main_bak, godot::Node)

//  int score;
//  Player *_player;
//  HUD *_hud;
//  godot::Node2D *_start_position;
//  godot::Timer *_mob_timer;
//  godot::Timer *_start_timer;
//  godot::Timer *_score_timer;
//  godot::PathFollow2D *_mob_spawn_location;
//  godot::Ref<godot::RandomNumberGenerator> _random;

public:
//  Main_bak() {
//    godot::Godot::print("built");
//  }
//  godot::Ref<godot::PackedScene> mob_scene;

  void __init(){};
  void _ready();
//  void game_over();
//  void new_game();
//  void _on_MobTimer_timeout();
//  void _on_StartTimer_timeout();
//  void _on_ScoreTimer_timeout();

  static void _register_methods();
};

#endif // COREGAME_MAIN_BAK_H
