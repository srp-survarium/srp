vostok::buffer_string *__usercall vostok::fs_new::path_string_impl::assignf@<eax>(
        _DWORD *a1@<eax>,
        vostok::buffer_string *a2@<ecx>,
        vostok::buffer_string *this,
        const char *format,
        ...)
{
  _BYTE *v5; // eax

  v5 = (_BYTE *)*a1;
  a1[1] = v5;
  *v5 = 0;
  vostok::buffer_string::appendf_va_list(a2, a1, (char *)this, (char *)&format);
  return (vostok::buffer_string *)a1;
}
