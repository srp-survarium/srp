void __usercall vostok::render::shader_macro::shader_macro(
        vostok::render::shader_macro *this@<esi>,
        const vostok::render::shader_macro *__that@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  char *m_end; // ecx
  unsigned __int8 *v7; // edi
  int v8; // ebx

  m_begin = (unsigned __int8 *)__that->name.m_string.m_begin;
  v4 = __that->name.m_string.m_end - __that->name.m_string.m_begin;
  this->name.m_string.m_max_end = &this->name.m_separator;
  v5 = v4;
  this->name.m_string.m_begin = this->name.m_string.m_buffer;
  this->name.m_string.m_end = this->name.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->name.m_string.m_buffer, m_begin, v4);
  this->name.m_string.m_end += v5;
  *this->name.m_string.m_end = 0;
  this->name.m_separator = 47;
  m_end = __that->definition.m_end;
  v7 = (unsigned __int8 *)__that->definition.m_begin;
  v8 = m_end - (char *)v7;
  this->definition.m_begin = this->definition.m_buffer;
  this->definition.m_end = this->definition.m_buffer;
  this->definition.m_max_end = (char *)&this[1];
  memcpy((unsigned __int8 *)this->definition.m_buffer, v7, m_end - (char *)v7);
  this->definition.m_end += v8;
  *this->definition.m_end = 0;
}
