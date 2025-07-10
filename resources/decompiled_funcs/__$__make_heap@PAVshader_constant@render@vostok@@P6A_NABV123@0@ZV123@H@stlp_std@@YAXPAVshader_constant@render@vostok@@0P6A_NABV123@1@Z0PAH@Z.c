void __usercall stlp_std::__make_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),vostok::render::shader_constant,int>(
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *__first,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v3; // ebx
  int v4; // edi
  vostok::render::shader_constant_source *i; // esi
  vostok::render::shader_constant v6; // [esp-1Ch] [ebp-2Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  for ( i = &__first[v4].m_source; ; i -= 3 )
  {
    v6.m_slot = (vostok::render::shader_constant_slot)i[-1];
    v6.m_source.m_pointer = i->m_pointer;
    v6.m_source.m_size = i->m_size;
    v6.m_host = (const vostok::render::shader_constant_host *)i[1].m_pointer;
    stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      v4,
      v3,
      v6,
      __comp);
    if ( !v4 )
      break;
    --v4;
  }
}
