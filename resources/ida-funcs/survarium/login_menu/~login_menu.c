void __thiscall survarium::login_menu::~login_menu(survarium::login_menu *this)
{
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::login_menu_vtbl *)&survarium::login_menu::`vftable'{for `survarium::base_game_scene'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::login_menu::`vftable'{for `vostok::input::handler'};
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_cursor_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_login_menu_ui);
  survarium::base_game_scene::~base_game_scene(this);
}
