//
// Created by Jacopo Gasparetto on 30/08/22.
//

#ifndef COREGAME_MOB_H
#define COREGAME_MOB_H

#include <AnimatedSprite.hpp>
#include <CollisionShape2D.hpp>
#include <Godot.hpp>
#include <RandomNumberGenerator.hpp>
#include <RigidBody2D.hpp>
#include <SpriteFrames.hpp>

class Mob : public godot::RigidBody2D {
  GODOT_CLASS(Mob, godot::RigidBody2D);
  godot::AnimatedSprite *_animatedSprite;

public:
  void _init(){};
  void _ready();
  void _on_VisibilityNotifier2D_screen_exited();

  static void _register_methods();
};

#endif // COREGAME_MOB_H
