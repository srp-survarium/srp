int __usercall vostok::render::compare@<eax>(
        const vostok::render::shader_constant *right@<eax>,
        const vostok::render::shader_constant *left)
{
  int result; // eax
  void *m_pointer; // eax
  void *v5; // ecx
  unsigned int m_size; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int m_value_high; // ebx
  unsigned int v11; // edi

  result = vostok::render::compare(left->m_host, right->m_host);
  if ( !result )
  {
    m_pointer = left->m_source.m_pointer;
    v5 = right->m_source.m_pointer;
    if ( m_pointer < v5 )
      return -1;
    if ( m_pointer > v5 )
      return 1;
    m_size = left->m_source.m_size;
    v7 = right->m_source.m_size;
    if ( m_size < v7 )
      return -1;
    if ( m_size > v7 )
      return 1;
    v8 = *(_DWORD *)&left->m_slot.m_class_id;
    v9 = *(_DWORD *)&right->m_slot.m_class_id;
    m_value_high = HIDWORD(left->m_slot.m_value);
    v11 = HIDWORD(right->m_slot.m_value);
    if ( m_value_high > v11 )
      return 1;
    if ( m_value_high < v11 || v8 < v9 )
      return -1;
    return __PAIR64__(m_value_high, v8) > __PAIR64__(v11, v9);
  }
  return result;
}
