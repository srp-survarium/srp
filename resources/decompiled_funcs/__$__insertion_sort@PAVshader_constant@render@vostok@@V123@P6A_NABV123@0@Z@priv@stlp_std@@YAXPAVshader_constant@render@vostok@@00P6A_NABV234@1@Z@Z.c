void __usercall stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__last)
{
  vostok::render::shader_constant *i; // edi
  vostok::render::shader_constant v4; // [esp-18h] [ebp-24h]
  bool (__cdecl *v5)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    v4.m_slot.m_value = i->m_slot.m_value;
    v4.m_source.m_pointer = i->m_source.m_pointer;
    v4.m_source.m_size = i->m_source.m_size;
    v4.m_host = i->m_host;
    stlp_std::priv::__linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      i,
      v4,
      v5);
  }
}
