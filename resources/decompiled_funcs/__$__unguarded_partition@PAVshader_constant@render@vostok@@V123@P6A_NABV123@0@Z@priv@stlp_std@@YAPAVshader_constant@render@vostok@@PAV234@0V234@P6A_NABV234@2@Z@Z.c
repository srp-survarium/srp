vostok::render::shader_constant *__usercall stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>@<eax>(
        vostok::render::shader_constant *__first@<ecx>,
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant __pivot)
{
  unsigned __int8 (__cdecl *v3)(vostok::render::shader_constant *, char *); // ebx
  vostok::render::shader_constant *v5; // esi
  char i; // al
  unsigned int m_size; // ebx
  void *m_pointer; // edx
  int v9; // eax
  int m_value_high; // ecx
  const vostok::render::shader_constant_host *m_host; // [esp+20h] [ebp-8h]

  v3 = *(unsigned __int8 (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id;
  v5 = __first;
  for ( i = (*(int (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id)(
              __first,
              (char *)&__pivot.m_slot.m_value + 4);
        ;
        i = (*(int (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id)(
              v5,
              (char *)&__pivot.m_slot.m_value + 4) )
  {
    if ( i )
    {
      do
        ++v5;
      while ( v3(v5, (char *)&__pivot.m_slot.m_value + 4) );
    }
    for ( --__last; v3((vostok::render::shader_constant *)((char *)&__pivot.m_slot.m_value + 4), (char *)__last); --__last )
      ;
    if ( v5 >= __last )
      break;
    m_size = v5->m_source.m_size;
    m_pointer = v5->m_source.m_pointer;
    v9 = *(_DWORD *)&v5->m_slot.m_class_id;
    m_value_high = HIDWORD(v5->m_slot.m_value);
    m_host = v5->m_host;
    *(_DWORD *)&v5->m_slot.m_class_id = *(_DWORD *)&__last->m_slot.m_class_id;
    HIDWORD(v5->m_slot.m_value) = HIDWORD(__last->m_slot.m_value);
    v5->m_source.m_pointer = __last->m_source.m_pointer;
    v5->m_source.m_size = __last->m_source.m_size;
    v5->m_host = __last->m_host;
    HIDWORD(__last->m_slot.m_value) = m_value_high;
    *(_DWORD *)&__last->m_slot.m_class_id = v9;
    __last->m_source.m_size = m_size;
    v3 = *(unsigned __int8 (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id;
    __last->m_source.m_pointer = m_pointer;
    __last->m_host = m_host;
    ++v5;
  }
  return v5;
}
