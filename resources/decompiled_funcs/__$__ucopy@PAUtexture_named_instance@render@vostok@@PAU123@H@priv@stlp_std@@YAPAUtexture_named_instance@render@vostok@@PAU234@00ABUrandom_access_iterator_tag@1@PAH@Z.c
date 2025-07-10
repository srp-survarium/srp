vostok::render::texture_named_instance *__usercall stlp_std::priv::__ucopy<vostok::render::texture_named_instance *,vostok::render::texture_named_instance *,int>@<eax>(
        vostok::render::texture_named_instance *__last@<eax>,
        vostok::render::texture_named_instance *__result@<ecx>,
        vostok::render::texture_named_instance *__first)
{
  vostok::render::texture_named_instance *v3; // edi
  int v4; // ebx
  unsigned __int8 *m_buffer; // esi
  unsigned int v6; // ebp
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-18h]
  vostok::render::texture_named_instance *__cur; // [esp+10h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->path.m_buffer;
    do
    {
      if ( __result )
      {
        __result->texture = v3->texture;
        v6 = v3->path.m_end - v3->path.m_begin;
        m_begin = (unsigned __int8 *)v3->path.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v6);
        __result = __cur;
        *((_DWORD *)m_buffer - 2) += v6;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      ++__result;
      --v4;
      ++v3;
      m_buffer += 276;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}
