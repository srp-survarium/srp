vostok::particle::world *__usercall vostok::render::scene_renderer::particle_world@<eax>(
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene@<eax>,
        vostok::render::scene_renderer *this)
{
  vostok::render::base_scene *m_object; // ecx
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::resources::resource_base *m_prev_in_memory_type; // esi

  m_object = scene->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  m_prev_in_memory_type = v3[3].m_prev_in_memory_type;
  if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  return (vostok::particle::world *)m_prev_in_memory_type;
}
