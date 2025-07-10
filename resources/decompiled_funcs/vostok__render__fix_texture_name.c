void __usercall vostok::render::fix_texture_name(vostok::fs_new::virtual_path_string *str@<esi>)
{
  char *m_begin; // ecx
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  vostok::fs_new::virtual_path_string *v5; // [esp+0h] [ebp-4h]

  vostok::render::change_substring("resources.sources/textures/", v5);
  vostok::render::change_substring("resources/textures/", str);
  m_begin = str->m_string.m_begin;
  v2 = str->m_string.m_end - 1;
  if ( v2 >= str->m_string.m_begin )
  {
    if ( *v2 == 46 )
    {
LABEL_5:
      v3 = v2 - m_begin;
      if ( v3 != -1 )
      {
        v4 = &m_begin[v3];
        str->m_string.m_end = v4;
        *v4 = 0;
      }
    }
    else
    {
      while ( v2 != m_begin )
      {
        if ( *--v2 == 46 )
          goto LABEL_5;
      }
    }
  }
}
