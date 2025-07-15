void __thiscall survarium::weapon::set_target(survarium::weapon *this, survarium::weapon_targets new_target)
{
  survarium::weapon_targets m_target; // esi
  vostok::render::light_props *m_weapon_fire_light_id; // edx

  m_target = this->m_target;
  survarium::weapon_core::set_target(this, new_target);
  if ( this->m_target == weapon_target_fire )
  {
    if ( m_target != weapon_target_fire )
    {
      m_weapon_fire_light_id = (vostok::render::light_props *)this->m_weapon_fire_light_id;
      qmemcpy(&this->m_weapon_fire_light_props, &this->m_barrel_transform, 0x40u);
      vostok::render::scene_renderer::add_light(
        (vostok::render::scene_renderer *)this->m_game_scene->m_game,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
        (unsigned int)&this->m_game_scene->m_render_scene,
        m_weapon_fire_light_id);
      this->m_firing_light_added = 1;
    }
  }
  else if ( m_target == weapon_target_fire && this->m_firing_light_added )
  {
    vostok::render::scene_renderer::remove_light(
      (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
      (unsigned int)&this->m_game_scene->m_render_scene);
    this->m_firing_light_added = 0;
  }
}
