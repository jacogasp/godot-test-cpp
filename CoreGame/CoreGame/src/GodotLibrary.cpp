#include "Controller.h"
#include "HUD.h"
#include "Main.h"
#include "Mob.h"
#include "Player.h"
#include <Godot.hpp>

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) { Godot::gdnative_init(o); }

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
  Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
  Godot::nativescript_init(handle);
  register_class<Controller>();
  register_class<Player>();
  register_class<Mob>();
  register_class<Main>();
  register_class<HUD>();
}