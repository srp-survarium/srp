void __usercall stlp_std::__push_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        int __holeIndex@<eax>,
        vostok::render::shader_constant *__first,
        int __topIndex,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v5; // edi
  int v6; // esi
  vostok::render::shader_constant *v7; // ebx
  vostok::render::shader_constant *v8; // eax
  bool v9; // cc
  vostok::render::shader_constant *v10; // eax
  int m_value_high; // edx
  void *m_pointer; // ecx
  unsigned int m_size; // edx
  const vostok::render::shader_constant_host *m_host; // ecx

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      v8 = &__first[v5];
      if ( v8 )
      {
        *(_DWORD *)&v8->m_slot.m_class_id = *(_DWORD *)&v7->m_slot.m_class_id;
        HIDWORD(v8->m_slot.m_value) = HIDWORD(v7->m_slot.m_value);
        v8->m_source.m_pointer = v7->m_source.m_pointer;
        v8->m_source.m_size = v7->m_source.m_size;
        v8->m_host = v7->m_host;
      }
      v5 = v6;
      v9 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v9 );
  }
  v10 = &__first[v5];
  if ( v10 )
  {
    m_value_high = HIDWORD(__val.m_slot.m_value);
    *(_DWORD *)&v10->m_slot.m_class_id = *(_DWORD *)&__val.m_slot.m_class_id;
    m_pointer = __val.m_source.m_pointer;
    HIDWORD(v10->m_slot.m_value) = m_value_high;
    m_size = __val.m_source.m_size;
    v10->m_source.m_pointer = m_pointer;
    m_host = __val.m_host;
    v10->m_source.m_size = m_size;
    v10->m_host = m_host;
  }
}
