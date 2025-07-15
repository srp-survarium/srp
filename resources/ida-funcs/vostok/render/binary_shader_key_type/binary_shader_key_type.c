void __usercall vostok::render::binary_shader_key_type::binary_shader_key_type(
        vostok::render::binary_shader_key_type *this@<esi>,
        const vostok::render::binary_shader_key_type *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  char *m_end; // ecx
  int v4; // ebx

  this->configuration.configuration[0] = __that->configuration.configuration[0];
  this->configuration.configuration[1] = __that->configuration.configuration[1];
  m_begin = (unsigned __int8 *)__that->shader_name.m_string.m_begin;
  m_end = __that->shader_name.m_string.m_end;
  this->shader_name.m_string.m_max_end = &this->shader_name.m_separator;
  v4 = m_end - (char *)m_begin;
  this->shader_name.m_string.m_begin = this->shader_name.m_string.m_buffer;
  this->shader_name.m_string.m_end = this->shader_name.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->shader_name.m_string.m_buffer, m_begin, m_end - (char *)m_begin);
  this->shader_name.m_string.m_end += v4;
  *this->shader_name.m_string.m_end = 0;
  this->shader_name.m_separator = 47;
  this->type = __that->type;
}
