void __cdecl vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *out_result,
        char *path)
{
  const char *v2; // eax
  const char *last_slash_pos; // [esp+10h] [ebp-4h]

  strrchr((unsigned __int8 *)path, 0x2Fu);
  last_slash_pos = v2;
  if ( v2 )
  {
    vostok::fs_new::path_string_impl::clear(&out_result->m_string);
    vostok::buffer_string::append(&out_result->m_string, path, last_slash_pos);
    vostok::fs_new::path_string_impl::verify_self(out_result);
  }
  else
  {
    vostok::fs_new::path_string_impl::clear(&out_result->m_string);
  }
}
