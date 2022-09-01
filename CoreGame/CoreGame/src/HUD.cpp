//
// Created by Jacopo Gasparetto on 31/08/22.
//

#include "HUD.h"

void HUD::_ready() {
  _scoreLabel = get_node<godot::Label>("ScoreLabel");
  _messageLabel = get_node<godot::Label>("MessageLabel");
  _startButton = get_node<godot::Button>("StartButton");
  _startButton->connect("pressed", this, "_on_StartButton_pressed");
  _start_message_timer = get_node<godot::Timer>("StartMessageTimer");
  _get_ready_message_timer = get_node<godot::Timer>("GetReadyMessageTimer");
  _start_button_timer = get_node<godot::Timer>("StartButtonTimer");
  setup_timers();
}

void HUD::setup_timers() {
  _start_message_timer->connect("timeout", this, "_on_StartMessageTimer_timeout");
  _get_ready_message_timer->connect("timeout", this, "_on_GetReadyMessageTimer_timeout");
  _start_button_timer->connect("timeout", this, "_on_StartButtonTimer_timeout");
}

void HUD::show_get_ready() {
  _messageLabel->set_text("Get Ready!");
  _messageLabel->show();
  _get_ready_message_timer->start();
}

void HUD::show_get_gameover() {
  _messageLabel->set_text("Gameover");
  _messageLabel->show();
  _start_message_timer->start();
}

void HUD::update_score(const int score) {
  godot::String s {"the score is "};
  godot::Godot::print(s + godot::Variant(score));
  _scoreLabel->set_text(godot::Variant(score));
  _scoreLabel->show();
}

void HUD::_on_StartButton_pressed() {
  godot::Godot::print("Start!");
  _start_button_timer->stop();
  _startButton->hide();
  show_get_ready();
  emit_signal("start_game");
}

void HUD::_on_StartMessageTimer_timeout() {
  _messageLabel->set_text("Dooooooooodge the\nCreeps");
  _messageLabel->show();
  _start_button_timer->start();
  godot::Godot::print("Start message Timeout");
}

void HUD::_on_GetReadyMessageTimer_timeout() {
  _messageLabel->hide();
  godot::Godot::print("Get ready Timeout");
}

void HUD::_on_StartButtonTimer_timeout() { godot::Godot::print("Start button Timeout"); }

void HUD::_register_methods() {
  godot::register_method("_ready", &HUD::_ready);
  godot::register_method("_on_StartMessageTimer_timeout", &HUD::_on_StartMessageTimer_timeout);
  godot::register_method("_on_GetReadyMessageTimer_timeout", &HUD::_on_GetReadyMessageTimer_timeout);
  godot::register_method("_on_StartButtonTimer_timeout", &HUD::_on_StartButtonTimer_timeout);
  godot::register_method("_on_StartButton_pressed", &HUD::_on_StartButton_pressed);
  godot::register_signal<HUD>("start_game", godot::Dictionary());
}