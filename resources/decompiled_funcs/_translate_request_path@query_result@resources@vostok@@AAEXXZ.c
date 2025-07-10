void __usercall vostok::resources::query_result::translate_request_path(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  const char *v4; // ecx
  const char *v5; // eax
  char *v6; // eax
  unsigned int v7; // [esp+0h] [ebp-120h]
  char *m_begin; // [esp+4h] [ebp-11Ch]
  vostok::fs_new::virtual_path_string new_path; // [esp+Ch] [ebp-114h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook )
  {
    new_path.m_string.m_begin = new_path.m_string.m_buffer;
    new_path.m_string.m_max_end = &new_path.m_separator;
    v4 = *(const char **)(a2 + 252);
    new_path.m_string.m_end = new_path.m_string.m_buffer;
    new_path.m_string.m_buffer[0] = 0;
    new_path.m_separator = 47;
    if ( !v4 )
      v4 = *(const char **)(a2 + 248);
    cook->translate_request_path(cook, v4, &new_path);
    v5 = *(const char **)(a2 + 252);
    if ( !v5 )
      v5 = *(const char **)(a2 + 248);
    if ( vostok::fs_new::path_string_impl::operator!=(&new_path, v5) )
    {
      v6 = (char *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 324) + 16))(
                     *(_DWORD *)(a2 + 324),
                     new_path.m_string.m_end - new_path.m_string.m_begin + 1);
      m_begin = new_path.m_string.m_begin;
      v7 = new_path.m_string.m_end - new_path.m_string.m_begin + 1;
      *(_DWORD *)(a2 + 248) = v6;
      strcpy_s(v6, v7, m_begin);
      vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x400u);
    }
  }
}
