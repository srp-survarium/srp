void __thiscall survarium::damage_zone::stop_particles(
        survarium::damage_zone *this,
        const survarium::damage_zone *particles,
        const survarium::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > *particlesa)
{
  unsigned int v3; // esi
  unsigned int i; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_game_world; // eax
  vostok::render::scene_renderer *v6; // [esp-Ch] [ebp-1Ch]

  v3 = particlesa->_M_impl._M_finish - particlesa->_M_impl._M_start;
  for ( i = 0; i < v3; ++i )
  {
    m_game_world = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)particles->m_game_world;
    v6 = *(vostok::render::scene_renderer **)(m_game_world[42].m_object->grm_satisfaction_tree_hook.color_ + 16);
    vostok::render::scene_renderer::remove_particle_system_instance(
      v6,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v6,
      m_game_world + 1);
  }
}
