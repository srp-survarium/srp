void __usercall stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__middle,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant v6; // [esp-1Ch] [ebp-2Ch]
  int *v7; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),vostok::render::shader_constant,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
  for ( i = __middle; i < __last; ++i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::shader_constant *, vostok::render::shader_constant *))__formal)(
           i,
           __first) )
    {
      v6.m_slot.m_value = i->m_slot.m_value;
      v6.m_source.m_pointer = i->m_source.m_pointer;
      v6.m_source.m_size = i->m_source.m_size;
      v6.m_host = i->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        __first,
        __middle,
        i,
        v6,
        (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal,
        v7);
    }
  }
  stlp_std::sort_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    __middle,
    (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
}
