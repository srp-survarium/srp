vostok::render::material_effects_entry *__usercall stlp_std::priv::__ucopy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>@<eax>(
        vostok::render::material_effects_entry *__last@<eax>,
        vostok::render::material_effects_entry *__result@<ecx>,
        vostok::render::material_effects_entry *__first)
{
  vostok::render::material_effects_entry *v3; // edi
  int v4; // eax
  unsigned __int8 *m_buffer; // esi
  unsigned int v6; // ebp
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-1Ch]
  int __n; // [esp+Ch] [ebp-4h]
  vostok::render::material_effects_entry *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  __n = v4;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_material_name.m_string.m_buffer;
    do
    {
      if ( __result )
      {
        __result->m_material_effects_instance_ptr = v3->m_material_effects_instance_ptr;
        v6 = v3->m_material_name.m_string.m_end - v3->m_material_name.m_string.m_begin;
        m_begin = (unsigned __int8 *)v3->m_material_name.m_string.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v6);
        __result = __cur;
        *((_DWORD *)m_buffer - 2) += v6;
        **((_BYTE **)m_buffer - 2) = 0;
        v4 = __n;
        m_buffer[260] = 47;
      }
      --v4;
      ++__result;
      ++v3;
      m_buffer += 280;
      __cur = __result;
      __n = v4;
    }
    while ( v4 > 0 );
  }
  return __result;
}
