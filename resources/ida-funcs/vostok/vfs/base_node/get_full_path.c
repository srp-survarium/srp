void __usercall vostok::vfs::base_node<1>::get_full_path(
        vostok::vfs::base_node<1> *this@<ecx>,
        vostok::fs_new::virtual_path_string *out_string@<eax>)
{
  char *m_begin; // eax
  vostok::vfs::base_node<1> *p_base; // edi
  _DWORD *v5; // ebx
  void *v6; // esp
  vostok::vfs::base_folder_node<1> *pointer; // edi
  _DWORD *i; // edi
  _DWORD v9[5]; // [esp-8h] [ebp-14h] BYREF

  m_begin = out_string->m_string.m_begin;
  out_string->m_string.m_end = m_begin;
  p_base = this;
  *m_begin = 0;
  v5 = 0;
  while ( p_base && p_base->m_name[0] )
  {
    v6 = alloca(8);
    v9[1] = v5;
    v9[0] = p_base;
    pointer = p_base->m_parent.pointer;
    v5 = v9;
    if ( pointer )
      p_base = &pointer->base;
    else
      p_base = 0;
  }
  for ( i = v5; i; i = (_DWORD *)i[1] )
  {
    vostok::buffer_string::append((vostok::buffer_string *)this, (int)out_string, (char *)(*i + 51));
    if ( i[1] )
    {
      *out_string->m_string.m_end++ = 47;
      *out_string->m_string.m_end = 0;
    }
  }
}
