void __thiscall survarium::login_menu::clear_resources(survarium::login_menu *this)
{
  vostok::particle::particle_system_instance_impl *v2; // ecx

  survarium::base_game_scene::hide_movie(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_login_menu_ui,
    (vostok::particle::particle_system_instance_impl *)this,
    this);
  survarium::base_game_scene::hide_movie(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_cursor_ui,
    v2,
    this);
}
