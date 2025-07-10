vostok::render::update_skeleton_command *__thiscall vostok::render::update_skeleton_command::`vector deleting destructor'(
        vostok::render::update_skeleton_command *this,
        char a2)
{
  vostok::render::render_model_instance *m_object; // eax

  m_object = this->m_model_instance.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_model_instance.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_model_instance.m_object);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
