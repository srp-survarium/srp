void __cdecl stlp_std::priv::__linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant __val)
{
  vostok::render::shader_constant *v2; // ecx
  vostok::render::shader_constant *v3; // esi
  int i; // ebx

  if ( __val.m_host->m_name.m_pointer.m_object >= __first->m_host->m_name.m_pointer.m_object )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v2,
      __val);
  }
  else
  {
    v3 = v2 + 1;
    for ( i = v2 - __first; i > 0; --i )
    {
      --v3;
      vostok::render::shader_constant::operator=(v3 - 1, v3);
    }
    vostok::render::shader_constant::operator=(&__val, __first);
  }
}
