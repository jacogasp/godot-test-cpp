//
// Created by Jacopo Gasparetto on 31/08/22.
//

#ifndef COREGAME_HUD_H
#define COREGAME_HUD_H

#include <Button.hpp>
#include <CanvasLayer.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Timer.hpp>
#include <iostream>
#include <sstream>
#include <string>

class HUD : public godot::CanvasLayer {
  GODOT_CLASS(HUD, godot::CanvasLayer)

  godot::Label *_scoreLabel;
  godot::Label *_messageLabel;
  godot::Button *_startButton;
  godot::Timer *_start_message_timer;
  godot::Timer *_get_ready_message_timer;
  godot::Timer *_start_button_timer;

public:
  void _init() {}
  void _ready();
  void setup_timers();
  void show_get_ready();
  void show_gameover();
  void update_score(int score);
  void _on_StartButton_pressed();
  void _on_StartButtonTimer_timeout();
  void _on_StartMessageTimer_timeout();
  void _on_GetReadyMessageTimer_timeout();
  static void _register_methods();
};

#endif // COREGAME_HUD_H
