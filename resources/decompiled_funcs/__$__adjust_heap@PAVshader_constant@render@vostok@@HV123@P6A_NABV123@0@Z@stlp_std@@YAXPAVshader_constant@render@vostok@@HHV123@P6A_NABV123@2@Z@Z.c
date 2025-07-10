void __usercall stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        int __holeIndex@<eax>,
        vostok::render::shader_constant *__first,
        int __len,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::render::shader_constant *v10; // eax
  vostok::render::shader_constant *v11; // ecx
  vostok::render::shader_constant *v12; // ecx
  vostok::render::shader_constant *v13; // eax

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; i = v7 == __len )
  {
    if ( __comp(&__first[v7], &__first[v7 - 1]) )
      --v7;
    v10 = &__first[v6];
    v11 = &__first[v7];
    if ( v10 )
    {
      *(_DWORD *)&v10->m_slot.m_class_id = *(_DWORD *)&v11->m_slot.m_class_id;
      HIDWORD(v10->m_slot.m_value) = HIDWORD(v11->m_slot.m_value);
      v10->m_source.m_pointer = v11->m_source.m_pointer;
      v10->m_source.m_size = v11->m_source.m_size;
      v10->m_host = v11->m_host;
    }
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    v12 = &__first[v7 - 1];
    v13 = &__first[v6];
    if ( v13 )
    {
      *(_DWORD *)&v13->m_slot.m_class_id = *(_DWORD *)&v12->m_slot.m_class_id;
      HIDWORD(v13->m_slot.m_value) = HIDWORD(v12->m_slot.m_value);
      v13->m_source.m_pointer = v12->m_source.m_pointer;
      v13->m_source.m_size = v12->m_source.m_size;
      v13->m_host = v12->m_host;
    }
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}
