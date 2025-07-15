void __thiscall survarium::object_particle_visual::remove(survarium::object_particle_visual *this)
{
  survarium::scheduler *v2; // ecx

  vostok::render::scene_renderer::remove_particle_system_instance(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_system_instance_ptr);
  if ( this->m_track )
    survarium::scheduler::unregister(v2, (int)&this->m_game_scene->m_scheduler, &this->m_scheduler_identifier);
}
