vostok::render::effect_compiler::texture_query_desc *__usercall stlp_std::priv::__ucopy<vostok::render::effect_compiler::texture_query_desc *,vostok::render::effect_compiler::texture_query_desc *,int>@<eax>(
        vostok::render::effect_compiler::texture_query_desc *__last@<eax>,
        vostok::render::effect_compiler::texture_query_desc *__result@<ecx>,
        vostok::render::effect_compiler::texture_query_desc *__first)
{
  vostok::render::effect_compiler::texture_query_desc *v3; // edi
  int v4; // ebx
  vostok::render::effect_compiler::texture_query_desc *v5; // ebp
  char *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v9; // [esp-4h] [ebp-18h]
  unsigned int v10; // [esp+10h] [ebp-4h]
  vostok::render::effect_compiler::texture_query_desc *__cur; // [esp+18h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = __result->m_query_physicaly_path.m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_query_physicaly_path.m_begin;
        v9 = v3->m_query_physicaly_path.m_end - v3->m_query_physicaly_path.m_begin;
        v5->m_query_physicaly_path.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        v10 = v9;
        memcpy((unsigned __int8 *)m_buffer, m_begin, v9);
        *((_DWORD *)m_buffer - 2) += v10;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 65) = v3->m_mip_level_cut;
        v5 = __cur;
        *((_DWORD *)m_buffer + 66) = v3->m_num_last_mips_used;
      }
      ++v5;
      --v4;
      ++v3;
      m_buffer += 280;
      __cur = v5;
    }
    while ( v4 > 0 );
  }
  return v5;
}
