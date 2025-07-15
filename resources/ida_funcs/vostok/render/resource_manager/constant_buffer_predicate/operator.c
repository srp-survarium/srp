bool __usercall vostok::render::resource_manager::constant_buffer_predicate::operator()@<al>(
        const vostok::render::shader_constant_buffer *const left@<ecx>,
        const vostok::render::shader_constant_buffer *const right@<eax>,
        vostok::render::resource_manager::constant_buffer_predicate *this)
{
  _D3D_CBUFFER_TYPE m_type; // edx
  _D3D_CBUFFER_TYPE v4; // esi
  bool result; // al
  unsigned int m_buffer_size; // edx
  unsigned int v7; // esi
  vostok::render::enum_shader_type m_dest; // edx
  vostok::render::enum_shader_type v9; // esi

  m_type = left->m_type;
  v4 = right->m_type;
  result = 1;
  if ( m_type >= v4 )
  {
    if ( m_type > v4 )
      return 0;
    m_buffer_size = left->m_buffer_size;
    v7 = right->m_buffer_size;
    if ( m_buffer_size >= v7 )
    {
      if ( m_buffer_size > v7 )
        return 0;
      m_dest = left->m_dest;
      v9 = right->m_dest;
      if ( m_dest >= v9 && (m_dest > v9 || !vostok::operator<(&left->m_name, &right->m_name)) )
        return 0;
    }
  }
  return result;
}
