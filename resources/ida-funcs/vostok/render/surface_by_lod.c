vostok::render::grass_render_surface *__usercall vostok::render::surface_by_lod@<eax>(
        const unsigned int lod_index@<eax>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> mod)
{
  float m_time_fade_in; // esi
  int v3; // eax

  m_time_fade_in = 0.0;
  if ( lod_index )
  {
    v3 = lod_index - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        m_time_fade_in = mod.m_object->m_lods[1].m_time_fade_in;
    }
    else
    {
      m_time_fade_in = mod.m_object->m_lods[1].m_distance;
    }
  }
  else
  {
    m_time_fade_in = *(float *)&mod.m_object->m_lods[1].m_emitter_instance_list.m_last;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&mod);
  return (vostok::render::grass_render_surface *)LODWORD(m_time_fade_in);
}
