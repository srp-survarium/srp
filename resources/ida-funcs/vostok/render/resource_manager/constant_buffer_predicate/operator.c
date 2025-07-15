bool __usercall vostok::render::resource_manager::constant_buffer_predicate::operator()@<al>(
        const vostok::render::shader_constant_buffer *const left@<edx>,
        const vostok::render::shader_constant_buffer *const right@<eax>)
{
  _D3D_CBUFFER_TYPE m_type; // ecx
  _D3D_CBUFFER_TYPE v3; // esi
  bool result; // al
  unsigned int m_buffer_size; // ecx
  unsigned int v6; // esi
  vostok::render::enum_shader_type m_dest; // ecx
  vostok::render::enum_shader_type v8; // esi

  m_type = left->m_type;
  v3 = right->m_type;
  result = 1;
  if ( m_type >= v3 )
  {
    if ( m_type > v3 )
      return 0;
    m_buffer_size = left->m_buffer_size;
    v6 = right->m_buffer_size;
    if ( m_buffer_size >= v6 )
    {
      if ( m_buffer_size > v6 )
        return 0;
      m_dest = left->m_dest;
      v8 = right->m_dest;
      if ( m_dest >= v8
        && (m_dest > v8 || vostok::detail::strcmp_s(left->m_name.m_begin, right->m_name.m_begin) != (const char *)-1) )
      {
        return 0;
      }
    }
  }
  return result;
}
