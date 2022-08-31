//
// Created by Jacopo Gasparetto on 30/08/22.
//
#include "Player.h"

void Player::_ready() {
  _animated_sprite = get_node<godot::AnimatedSprite>("AnimatedSprite");
  _collision_shape = get_node<godot::CollisionShape2D>("CollisionShape2D");
  _input = godot::Input::get_singleton();
  _screen_size = get_viewport_rect().size;
  hide();
  godot::Godot::print("Player ready and hidden");
}

void Player::start(const godot::Vector2 position) {
  show();
  set_position(position);
  _collision_shape->set_disabled(false);
}

void Player::_on_Player_body_entered(godot::Node2D *body) {
  hide();
  emit_signal("hit");
  _collision_shape->set_deferred("disable", true);
}

void Player::_register_methods() {
  godot::register_property((char *)"speed", &Player::speed, (real_t)200.0f);
  godot::register_signal<Player>("hit", godot::Dictionary());
  godot::register_method("_ready", &Player::_ready);
  godot::register_method("start", &Player::start);
  godot::register_method("_process", &Player::_process);
  godot::register_method("_onPlayer_body_entered", &Player::_on_Player_body_entered);
  godot::register_method("_on_VisibilityNotifier2D_screen_exited", &Player::_on_VisibilityNotifier2D_screen_exited);
}

void Player::_process(const double p_delta) {
  godot::Vector2 velocity{0, 0};
  velocity.x = _input->get_action_strength("move_right") - _input->get_action_strength("move_left");
  velocity.y = _input->get_action_strength("move_down") - _input->get_action_strength("move_up");
  if (velocity.length() > 0) {
    velocity = velocity.normalized() * speed;
    _animated_sprite->play();
  } else {
    _animated_sprite->stop();
  }

  godot::Vector2 position = get_position();
  position += velocity * (real_t)p_delta;
  position.x = godot::Math::clamp(position.x, (real_t)0.0, _screen_size.x);
  position.y = godot::Math::clamp(position.y, (real_t)0.0, _screen_size.y);
  set_position(position);
}

void Player::_on_VisibilityNotifier2D_screen_exited() { queue_free(); }