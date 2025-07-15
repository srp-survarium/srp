void __usercall vostok::render::fix_texture_name(
        vostok::fs_new::virtual_path_string *str@<eax>,
        vostok::buffer_string *a2@<ecx>)
{
  vostok::buffer_string *v3; // ecx
  char *m_begin; // ecx
  char *v5; // eax
  int v6; // eax
  char *v7; // eax

  vostok::render::change_substring(str, a2, "resources.sources/textures/");
  vostok::render::change_substring(str, v3, "resources/textures/");
  m_begin = str->m_string.m_begin;
  v5 = str->m_string.m_end - 1;
  if ( v5 >= str->m_string.m_begin )
  {
    while ( 1 )
    {
      if ( *v5 == 46 )
      {
        v6 = v5 - m_begin;
        goto LABEL_8;
      }
      if ( v5 == m_begin )
        break;
      --v5;
    }
    v6 = -1;
LABEL_8:
    if ( v6 != -1 )
    {
      v7 = &m_begin[v6];
      str->m_string.m_end = v7;
      *v7 = 0;
    }
  }
}
