void __userpurge vostok::render::shader_constant_binding::shader_constant_binding(
        vostok::render::shader_constant_binding *this@<eax>,
        vostok::math::float4 *source@<ecx>,
        const vostok::shared_string *name)
{
  vostok::strings::shared::profile *m_object; // ecx

  this->m_source.m_pointer = source;
  this->m_source.m_size = 16;
  this->m_name.m_pointer.m_object = 0;
  m_object = name->m_pointer.m_object;
  if ( name->m_pointer.m_object )
  {
    this->m_name.m_pointer.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  this->m_type = rc_float;
  this->m_class_id = rc_1x4;
}
