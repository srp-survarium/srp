int __cdecl vostok::render::compare(
        const vostok::render::res_shader_technique *left,
        const vostok::render::res_shader_technique *right)
{
  const vostok::render::res_shader_technique *v2; // ebx
  vostok::render::res_shader_technique::sflags m_flags; // edx
  const vostok::render::res_shader_technique *v4; // ebp
  vostok::render::res_shader_technique::sflags v5; // ecx
  int result; // eax
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edx
  const vostok::render::res_shader_technique *v16; // ecx
  unsigned int v17; // edi
  const vostok::render::res_shader_technique **p_right; // eax
  const vostok::render::res_pass **p_m_object; // esi
  int v20; // ebx

  v2 = right;
  m_flags = right->m_flags;
  v4 = left;
  v5 = left->m_flags;
  if ( (*(_BYTE *)&m_flags & 3u) > (*(_BYTE *)&v5 & 3u) )
    return -1;
  result = (*(_BYTE *)&m_flags & 3u) < (*(_BYTE *)&v5 & 3u);
  if ( (*(_BYTE *)&m_flags & 3u) >= (*(_BYTE *)&v5 & 3u) )
  {
    v7 = (*(unsigned int *)&v5 >> 2) & 1;
    v8 = (*(unsigned int *)&m_flags >> 2) & 1;
    if ( v8 > v7 )
      return -1;
    result = v8 < v7;
    if ( result )
      return result;
    v9 = (*(unsigned int *)&v5 >> 3) & 1;
    v10 = (*(unsigned int *)&m_flags >> 3) & 1;
    if ( v10 > v9 )
      return -1;
    result = v10 < v9;
    if ( result )
      return result;
    v11 = (*(unsigned int *)&v5 >> 5) & 1;
    v12 = (*(unsigned int *)&m_flags >> 5) & 1;
    if ( v12 > v11 )
      return -1;
    result = v12 < v11;
    if ( result )
      return result;
    v13 = (*(unsigned int *)&v5 >> 4) & 1;
    v14 = (*(unsigned int *)&m_flags >> 4) & 1;
    if ( v14 > v13 )
      return -1;
    result = v14 < v13;
    if ( v14 < v13 )
      return result;
    if ( left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start < (unsigned int)(right->m_passes._M_impl._M_finish
                                                                                           - right->m_passes._M_impl._M_start) )
      return -1;
    v15 = right->m_passes._M_impl._M_finish - right->m_passes._M_impl._M_start;
    result = v15 < left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start;
    if ( v15 >= left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start )
    {
      v16 = (const vostok::render::res_shader_technique *)(left->m_passes._M_impl._M_finish
                                                         - left->m_passes._M_impl._M_start);
      v17 = 0;
      right = (const vostok::render::res_shader_technique *)(right->m_passes._M_impl._M_finish
                                                           - right->m_passes._M_impl._M_start);
      left = v16;
      p_right = &right;
      if ( right >= v16 )
        p_right = &left;
      right = *p_right;
      if ( right )
      {
        p_m_object = (const vostok::render::res_pass **)&v4->m_passes._M_impl._M_start->m_object;
        v20 = (char *)v2->m_passes._M_impl._M_start - (char *)p_m_object;
        while ( 1 )
        {
          result = vostok::render::compare(*(const vostok::render::res_pass **)((char *)p_m_object + v20), *p_m_object);
          if ( result )
            break;
          ++v17;
          ++p_m_object;
          if ( v17 >= (unsigned int)right )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
