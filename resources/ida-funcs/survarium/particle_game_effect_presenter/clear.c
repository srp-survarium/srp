void __thiscall survarium::particle_game_effect_presenter::clear(survarium::particle_game_effect_presenter *this)
{
  int v2; // edi
  int v3; // ebx

  if ( this->m_old_effects.m_end - this->m_old_effects.m_begin )
  {
    v2 = 0;
    v3 = this->m_old_effects.m_end - this->m_old_effects.m_begin;
    do
    {
      vostok::render::scene_renderer::remove_particle_system_instance(
        (vostok::render::scene_renderer *)&this->m_scene->m_render_scene,
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_scene->m_game->m_renderer),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene->m_render_scene,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_old_effects.m_begin[v2++].particle_system);
      --v3;
    }
    while ( v3 );
  }
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(
    this->m_old_effects.m_begin,
    &this->m_old_effects.m_end);
  this->m_old_effects.m_end = this->m_old_effects.m_begin;
}
