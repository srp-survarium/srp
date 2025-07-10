void __thiscall vostok::render::render_surface::set_default_material(vostok::render::render_surface *this)
{
  vostok::render::material_effects_instance *m_object; // eax

  m_object = this->m_materail_effects_instance.m_object;
  this->m_materail_effects_instance.m_object = 0;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
