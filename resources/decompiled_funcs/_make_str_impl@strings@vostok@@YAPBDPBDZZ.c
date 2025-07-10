vostok::debug::detail::string_helper *vostok::strings::make_str_impl(char *format, ...)
{
  vostok::debug::detail::string_helper v2; // [esp+0h] [ebp-1000h] BYREF
  va_list argptr; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(argptr, format);
  v2.m_buffer[0] = 0;
  vostok::debug::detail::string_helper::appendf_va_list(&v2, format, argptr);
  return &v2;
}
