void __thiscall vostok::render::render_particle_emitter_instance::change_material(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *material)
{
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::render::material_effects_instance *v3; // eax
  vostok::render::material_effects_instance *v4; // edx
  vostok::render::material_effects_instance *v5; // eax

  m_object = 0;
  if ( material->m_object )
  {
    m_object = material->m_object;
    _InterlockedExchangeAdd(&material->m_object->m_reference_count, 1u);
  }
  v3 = 0;
  if ( m_object )
  {
    v3 = (vostok::render::material_effects_instance *)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = v3;
  v5 = this->m_material_effects_ptr.m_object;
  this->m_material_effects_ptr.m_object = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
