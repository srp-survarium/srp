void vostok::debug::detail::string_helper::appendf(vostok::debug::detail::string_helper *this, const char *format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, format);
  vostok::debug::detail::string_helper::appendf_va_list(this, format, va);
}
