const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::assignf_with_conversion@<eax>(
        vostok::fs_new::path_string_impl *a1@<ecx>,
        _DWORD *a2@<esi>,
        vostok::fs_new::path_string_impl *this,
        const char *const format,
        ...)
{
  _BYTE *v4; // eax

  v4 = (_BYTE *)*a2;
  a2[1] = *a2;
  *v4 = 0;
  vostok::fs_new::path_string_impl::appendf_va_list_with_conversion(a1, (int)a2, (char *)this, (char *)&format);
  return (const vostok::fs_new::path_string_impl *)a2;
}
