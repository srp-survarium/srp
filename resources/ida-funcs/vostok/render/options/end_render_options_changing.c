int __thiscall vostok::render::options::end_render_options_changing(
        vostok::render::options *this,
        vostok::buffer_vector<vostok::fs_new::virtual_path_string> *out_changed_defines,
        int save_settings,
        char a4)
{
  vostok::fs_new::virtual_path_string *m_begin; // esi
  vostok::fixed_string<260> *v6; // ecx
  vostok::buffer_vector<vostok::fs_new::virtual_path_string> *v7; // ecx
  char *m_max_end; // [esp-4h] [ebp-130h]
  vostok::fs_new::virtual_path_string v10; // [esp+Ch] [ebp-120h] BYREF
  vostok::fs_new::virtual_path_string *v11; // [esp+120h] [ebp-Ch] BYREF
  int v12; // [esp+124h] [ebp-8h]
  vostok::fs_new::virtual_path_string *m_end; // [esp+134h] [ebp+8h]

  survarium::parse_resolution(s_r_resolution_value.m_begin, (int *)&v11);
  m_begin = out_changed_defines->m_begin;
  out_changed_defines[21].m_begin = v11;
  out_changed_defines[21].m_end = (vostok::fs_new::virtual_path_string *)v12;
  v12 = 1;
  m_end = m_begin;
  if ( m_begin )
  {
    while ( 1 )
    {
      if ( (*((unsigned __int8 (__thiscall **)(vostok::fs_new::virtual_path_string *))m_begin->m_string.m_begin + 1))(m_begin) )
      {
        m_max_end = m_begin->m_string.m_max_end;
        v12 |= *(_DWORD *)m_begin->m_string.m_buffer;
        vostok::fixed_string<260>::fixed_string<260>(v6, &v10.m_string, m_max_end);
        v10.m_separator = 47;
        vostok::buffer_vector<vostok::fs_new::virtual_path_string>::push_back(v7, save_settings, &v10);
        m_begin = m_end;
      }
      m_end = (vostok::fs_new::virtual_path_string *)m_begin->m_string.m_end;
      if ( !m_end )
        break;
      m_begin = (vostok::fs_new::virtual_path_string *)m_begin->m_string.m_end;
    }
  }
  qmemcpy(&out_changed_defines[25].m_max_end, &out_changed_defines[1], 0x128u);
  if ( a4 )
    vostok::console_commands::save(command_type_user_specific, 0);
  return v12;
}
