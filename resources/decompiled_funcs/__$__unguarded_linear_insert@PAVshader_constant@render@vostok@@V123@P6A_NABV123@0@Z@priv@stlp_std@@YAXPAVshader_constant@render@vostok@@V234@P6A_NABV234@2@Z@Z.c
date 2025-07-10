void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant __val)
{
  vostok::render::shader_constant *__last; // ecx
  vostok::render::shader_constant *v2; // eax
  const vostok::render::shader_constant_host *m_host; // esi

  v2 = __last - 1;
  if ( __val.m_host->m_name.m_pointer.m_object < __last[-1].m_host->m_name.m_pointer.m_object )
  {
    do
    {
      if ( __last )
        *__last = *v2;
      m_host = v2[-1].m_host;
      __last = v2--;
    }
    while ( __val.m_host->m_name.m_pointer.m_object < m_host->m_name.m_pointer.m_object );
  }
  if ( __last )
    *__last = __val;
}
