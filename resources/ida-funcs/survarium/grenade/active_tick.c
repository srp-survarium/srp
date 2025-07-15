void __thiscall survarium::grenade::active_tick(
        survarium::grenade *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::grenade_set *v4; // ecx
  survarium::grenade_set_core *m_owner; // eax

  survarium::grenade_core::active_tick(this, time_delta_ms, current_time_ms);
  m_owner = this->m_owner;
  if ( this->m_physics_world )
  {
    survarium::grenade_set::preview(v4, (int)m_owner, 0);
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      &this->m_render_transform,
      &this->m_render_transform);
  }
  else
  {
    survarium::grenade_set::preview(v4, (int)m_owner, 1);
  }
}
