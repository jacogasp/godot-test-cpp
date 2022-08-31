//
// Created by Jacopo Gasparetto on 30/08/22.
//

#include <Mob.h>

void Mob::_ready() {
  auto random = godot::RandomNumberGenerator::_new();
  random->randomize();
  _animatedSprite = get_node<godot::AnimatedSprite>("AnimatedSprite");
  _animatedSprite->set_playing(true);
  auto mob_types = _animatedSprite->get_sprite_frames()->get_animation_names();
  _animatedSprite->set_animation(mob_types[random->randi() % mob_types.size()]);
}

void Mob::_register_methods() { godot::register_method("_ready", &Mob::_ready); }
