void __usercall vostok::fs_new::get_path_without_last_item<vostok::fs_new::native_path_string>(
        vostok::fs_new::native_path_string *out_result@<esi>,
        char *path)
{
  const char *v2; // eax
  char *m_begin; // eax
  vostok::fs_new::path_string_impl *v4; // [esp-4h] [ebp-8h]
  const char *v5; // [esp+0h] [ebp-4h] BYREF

  strrchr(path, 0x5Cu);
  v5 = v2;
  if ( v2 )
  {
    vostok::fs_new::path_string_impl::assign<char const *>(v4, &out_result->m_string, &path, &v5);
  }
  else
  {
    m_begin = out_result->m_string.m_begin;
    out_result->m_string.m_end = out_result->m_string.m_begin;
    *m_begin = 0;
  }
}


void __usercall vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *out_result@<esi>,
        char *path)
{
  const char *v2; // eax
  char *m_begin; // eax
  vostok::fs_new::path_string_impl *v4; // [esp-4h] [ebp-8h]
  const char *v5; // [esp+0h] [ebp-4h] BYREF

  strrchr(path, 0x2Fu);
  v5 = v2;
  if ( v2 )
  {
    vostok::fs_new::path_string_impl::assign<char const *>(v4, &out_result->m_string, &path, &v5);
  }
  else
  {
    m_begin = out_result->m_string.m_begin;
    out_result->m_string.m_end = out_result->m_string.m_begin;
    *m_begin = 0;
  }
}
