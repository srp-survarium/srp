vostok::fs_new::path_string_impl *vostok::fs_new::path_string_impl::appendf(
        vostok::fs_new::path_string_impl *this,
        const char *format,
        ...)
{
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, format);
  vostok::buffer_string::appendf_va_list(&this->m_string, format, va);
  return this;
}
