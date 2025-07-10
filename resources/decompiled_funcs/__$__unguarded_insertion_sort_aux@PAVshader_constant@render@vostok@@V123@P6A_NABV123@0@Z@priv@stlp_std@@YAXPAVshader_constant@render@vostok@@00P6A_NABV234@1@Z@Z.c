void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__last@<edi>)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant v3; // [esp-18h] [ebp-1Ch]
  bool (__cdecl *v4)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-4h]

  for ( i = __first; i != __last; ++i )
  {
    v3.m_slot.m_value = i->m_slot.m_value;
    v3.m_source.m_pointer = i->m_source.m_pointer;
    v3.m_source.m_size = i->m_source.m_size;
    v3.m_host = i->m_host;
    stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      i,
      v3,
      v4);
  }
}
