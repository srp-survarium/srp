void __usercall vostok::core::generate_log_file_name(vostok::fs_new::native_path_string *const out_result@<edi>)
{
  const char *v1; // eax
  vostok::fs_new::native_path_string *v2; // eax
  vostok::fs_new::path_string_impl *v3; // ecx
  char *v4; // eax
  vostok::fixed_string<260> *v5; // ecx
  vostok::buffer_string *v6; // ecx
  vostok::buffer_string *v7; // [esp+0h] [ebp-234h]
  vostok::fs_new::native_path_string result; // [esp+4h] [ebp-230h] BYREF
  vostok::buffer_string v9; // [esp+118h] [ebp-11Ch] BYREF
  char v10; // [esp+228h] [ebp-Ch]
  char *v11; // [esp+22Ch] [ebp-8h] BYREF

  v1 = s_engine_0->get_user_data_directory(s_engine_0);
  v2 = vostok::fs_new::native_path_string::convert(&result, v1);
  vostok::fixed_string<260>::operator=(&v2->m_string, &out_result->m_string);
  v11 = vostok::core::application_name();
  vostok::fs_new::path_string_impl::append_path<char const *>(v3, (int)out_result, &v11);
  v4 = vostok::core::user_name();
  vostok::fixed_string<260>::fixed_string<260>(v5, &v9, v4);
  v10 = 92;
  if ( v9.m_end != v9.m_begin )
  {
    vostok::buffer_string::appendf(out_result, v6, (vostok::buffer_string *)"_%s", v9.m_begin);
    v6 = v7;
  }
  vostok::buffer_string::appendf(out_result, v6, (vostok::buffer_string *)".%s", "log");
}
