void __usercall vostok::journaling::generate_journal_file_name(
        vostok::fs_new::native_path_string *const out_result@<edi>,
        const char *const name)
{
  const char *v2; // eax
  vostok::fs_new::native_path_string *v3; // eax
  vostok::fs_new::path_string_impl *v4; // ecx
  vostok::buffer_string *v5; // ecx
  vostok::fs_new::path_string_impl *v6; // ecx
  char *v7; // eax
  vostok::fixed_string<260> *v8; // ecx
  vostok::buffer_string *v9; // [esp-4h] [ebp-120h]
  vostok::fs_new::native_path_string result; // [esp+0h] [ebp-11Ch] BYREF
  char *v11; // [esp+114h] [ebp-8h] BYREF

  v2 = s_engine_0->get_user_data_directory(s_engine_0);
  v3 = vostok::fs_new::native_path_string::convert(&result, v2);
  vostok::fixed_string<260>::operator=(&v3->m_string, &out_result->m_string);
  if ( name )
  {
    vostok::fs_new::path_string_impl::append_path<char const *>(v4, (int)out_result, (char **)&name);
  }
  else
  {
    v11 = vostok::core::application_name();
    vostok::fs_new::path_string_impl::append_path<char const *>(v6, (int)out_result, &v11);
    v7 = vostok::core::user_name();
    vostok::fixed_string<260>::fixed_string<260>(v8, &result.m_string, v7);
    result.m_separator = 92;
    if ( result.m_string.m_end != result.m_string.m_begin )
    {
      vostok::buffer_string::appendf(out_result, v5, (vostok::buffer_string *)"_%s", result.m_string.m_begin);
      v5 = v9;
    }
  }
  vostok::buffer_string::appendf(out_result, v5, (vostok::buffer_string *)".%s", "journal");
}
