void __thiscall survarium::game_world::show_ui(survarium::game_world *this, bool b_show)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_game_hud_ui; // eax
  vostok::particle::particle_system_instance_impl *v4; // ecx

  if ( this->m_is_ui_shown != b_show )
  {
    p_m_game_hud_ui = &this->game_ui.m_game_hud_ui;
    if ( b_show )
    {
      survarium::base_game_scene::show_movie(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_game_hud_ui,
        this);
      survarium::base_game_scene::show_movie(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->game_ui.m_player_icons_ui,
        this);
    }
    else
    {
      survarium::base_game_scene::hide_movie(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_game_hud_ui,
        (vostok::particle::particle_system_instance_impl *)this,
        this);
      survarium::base_game_scene::hide_movie(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->game_ui.m_player_icons_ui,
        v4,
        this);
    }
    this->m_is_ui_shown = b_show;
  }
}
