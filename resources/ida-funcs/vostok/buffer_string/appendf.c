vostok::buffer_string *__usercall vostok::buffer_string::appendf@<eax>(
        _DWORD *a1@<eax>,
        vostok::buffer_string *a2@<ecx>,
        vostok::buffer_string *this,
        const char *format,
        ...)
{
  vostok::buffer_string::appendf_va_list(a2, a1, (char *)this, (char *)&format);
  return (vostok::buffer_string *)a1;
}
