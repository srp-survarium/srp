vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::appendf_va_list_with_conversion@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<eax>,
        char *format,
        char *argptr)
{
  char *v6; // [esp+0h] [ebp-8h]

  vostok::buffer_string::appendf_va_list(&this->m_string, (_DWORD *)a2, format, argptr);
  vostok::fs_new::path_string_impl::convert(
    *(vostok::fs_new::path_string_impl **)a2,
    a2,
    *(vostok::fs_new::path_string_impl **)(a2 + 4),
    v6);
  return (vostok::fs_new::path_string_impl *)a2;
}
