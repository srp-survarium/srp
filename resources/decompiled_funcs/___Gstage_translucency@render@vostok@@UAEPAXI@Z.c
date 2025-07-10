vostok::render::stage_resolve_lighting *__thiscall vostok::render::stage_translucency::`scalar deleting destructor'(
        vostok::render::stage_resolve_lighting *this,
        char a2)
{
  vostok::render::res_effect *m_object; // eax

  m_object = this->m_resolve_lighting_effect.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_resolve_lighting_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_resolve_lighting_effect.m_object);
  this->__vftable = (vostok::render::stage_resolve_lighting_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
