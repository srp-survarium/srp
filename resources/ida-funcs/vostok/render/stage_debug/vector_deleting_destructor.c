vostok::render::stage_debug *__thiscall vostok::render::stage_debug::`vector deleting destructor'(
        vostok::render::stage_debug *this,
        char a2)
{
  vostok::render::res_effect *m_object; // eax

  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage_debug::`vftable';
  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, (int)&this->m_sphere_geometry);
  m_object = this->m_debug_environment_probe_preview_effect.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_debug_environment_probe_preview_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_debug_environment_probe_preview_effect.m_object);
  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
