void __userpurge vostok::render::shader_constant_binding::shader_constant_binding(
        vostok::render::shader_constant_binding *this@<edi>,
        vostok::math::float3 *source@<eax>,
        vostok::shared_string *a3@<ecx>,
        char *name)
{
  this->m_source.m_pointer = source;
  this->m_source.m_size = 12;
  vostok::shared_string::shared_string(a3, &this->m_name.m_pointer, name);
  this->m_type = rc_float;
  this->m_class_id = rc_1x3;
}


void __userpurge vostok::render::shader_constant_binding::shader_constant_binding(
        vostok::render::shader_constant_binding *this@<edi>,
        vostok::math::float4 *source@<eax>,
        vostok::shared_string *a3@<ecx>,
        char *name)
{
  this->m_source.m_pointer = source;
  this->m_source.m_size = 16;
  vostok::shared_string::shared_string(a3, &this->m_name.m_pointer, name);
  this->m_type = rc_float;
  this->m_class_id = rc_1x4;
}


void __userpurge vostok::render::shader_constant_binding::shader_constant_binding(
        vostok::render::shader_constant_binding *this@<edi>,
        vostok::math::float4x4 *source@<eax>,
        vostok::shared_string *a3@<ecx>,
        char *name)
{
  this->m_source.m_pointer = source;
  this->m_source.m_size = 64;
  vostok::shared_string::shared_string(a3, &this->m_name.m_pointer, name);
  this->m_type = rc_float;
  this->m_class_id = rc_4x4;
}
