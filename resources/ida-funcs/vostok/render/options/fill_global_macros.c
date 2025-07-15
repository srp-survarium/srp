void __userpurge vostok::render::options::fill_global_macros(
        vostok::render::options *this@<ecx>,
        int *a2@<eax>,
        vostok::fixed_vector<vostok::render::shader_macro,128> *out_defines)
{
  int i; // edi
  vostok::render::shader_macro *m_end; // esi
  vostok::render::shader_macro d; // [esp+10h] [ebp-220h] BYREF
  _UNKNOWN *retaddr; // [esp+230h] [ebp+0h] BYREF

  for ( i = *a2; i; i = *(_DWORD *)(i + 4) )
  {
    d.name.m_string.m_begin = d.name.m_string.m_buffer;
    d.name.m_string.m_end = d.name.m_string.m_buffer;
    d.name.m_string.m_max_end = &d.name.m_separator;
    d.definition.m_begin = d.definition.m_buffer;
    d.definition.m_end = d.definition.m_buffer;
    d.definition.m_max_end = (char *)&retaddr;
    d.name.m_string.m_buffer[0] = 0;
    d.name.m_separator = 47;
    d.definition.m_buffer[0] = 0;
    if ( (**(unsigned __int8 (__thiscall ***)(int, vostok::render::shader_macro *))i)(i, &d) )
    {
      m_end = out_defines->m_end;
      if ( m_end )
        vostok::render::shader_macro::shader_macro(m_end, &d);
      ++out_defines->m_end;
    }
  }
}
