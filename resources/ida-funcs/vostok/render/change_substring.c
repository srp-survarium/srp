void __usercall vostok::render::change_substring(
        vostok::fs_new::virtual_path_string *src_and_dest@<edi>,
        vostok::buffer_string *a2@<ecx>,
        char *what)
{
  unsigned int v3; // ebx
  char *m_begin; // ecx
  char *v5; // eax
  char *v6; // edx
  char *i; // esi
  char v8; // al
  char *m_end; // ecx
  char *j; // eax
  unsigned int v11; // [esp+0h] [ebp-A8h]
  vostok::buffer_string v12; // [esp+8h] [ebp-A0h] BYREF
  _BYTE v13[260]; // [esp+14h] [ebp-94h] BYREF
  char v14; // [esp+118h] [ebp+70h] BYREF
  unsigned int v15; // [esp+124h] [ebp+7Ch]

  v12.m_begin = v13;
  v12.m_end = v13;
  v12.m_max_end = &v14;
  v13[0] = 0;
  v14 = 47;
  v3 = vostok::buffer_string::find(a2, (unsigned __int8 **)src_and_dest, what, v11);
  if ( v3 != -1 )
  {
    v15 = strlen(what);
    m_begin = v12.m_begin;
    v5 = src_and_dest->m_string.m_begin;
    v6 = &src_and_dest->m_string.m_begin[v3];
    v12.m_end = v12.m_begin;
    *v12.m_begin = 0;
    for ( i = v5; i != v6; ++v12.m_end )
    {
      v8 = *i;
      m_begin = v12.m_end;
      ++i;
      *v12.m_end = v8;
    }
    *v12.m_end = 0;
    vostok::buffer_string::append((vostok::buffer_string *)m_begin, (int)&v12, (char *)uri);
    m_end = src_and_dest->m_string.m_end;
    for ( j = &src_and_dest->m_string.m_begin[v15 + v3]; j != m_end; ++j )
      *v12.m_end++ = *j;
    *v12.m_end = 0;
    if ( src_and_dest != (vostok::fs_new::virtual_path_string *)&v12 )
      vostok::buffer_string::operator=(&v12, &src_and_dest->m_string);
  }
}
