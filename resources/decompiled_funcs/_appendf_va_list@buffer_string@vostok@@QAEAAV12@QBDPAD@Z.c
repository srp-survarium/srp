vostok::buffer_string *__thiscall vostok::buffer_string::appendf_va_list(
        vostok::buffer_string *this,
        const char *format,
        char *argptr)
{
  char *v4; // ecx
  char *i; // eax
  char temp_buffer[4088]; // [esp+4h] [ebp-FF8h] BYREF

  v4 = &temp_buffer[vsnprintf_s(temp_buffer, 0xFF8u, 0xFF8u, format, argptr)];
  for ( i = temp_buffer; i != v4; ++i )
    *this->m_end++ = *i;
  *this->m_end = 0;
  return this;
}
