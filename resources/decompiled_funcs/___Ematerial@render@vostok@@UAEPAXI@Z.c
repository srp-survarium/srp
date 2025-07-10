vostok::render::material *__thiscall vostok::render::material::`vector deleting destructor'(
        vostok::render::material *this,
        char a2)
{
  vostok::configs::binary_config *m_object; // eax

  m_object = this->m_config.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_config.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_config.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
