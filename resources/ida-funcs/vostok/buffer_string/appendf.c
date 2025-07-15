vostok::buffer_string *__usercall vostok::buffer_string::appendf@<eax>(
        vostok::buffer_string *a1@<esi>,
        vostok::buffer_string *this,
        const char *format,
        ...)
{
  vostok::buffer_string::appendf_va_list(a1, (const char *)this, (char *)&format);
  return a1;
}
