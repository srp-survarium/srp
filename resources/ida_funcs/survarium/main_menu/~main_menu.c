void __thiscall survarium::main_menu::~main_menu(survarium::main_menu *this)
{
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::main_menu_vtbl *)&survarium::main_menu::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::main_menu::`vftable'{for `survarium::engine'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::main_menu::`vftable';
  survarium::base_game_scene::~base_game_scene(this);
}
