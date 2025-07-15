vostok::fs_new::path_string_impl *vostok::fs_new::path_string_impl::assignf(
        vostok::fs_new::path_string_impl *this,
        const char *format,
        ...)
{
  va_list va; // [esp+1Ch] [ebp+10h] BYREF

  va_start(va, format);
  vostok::fs_new::path_string_impl::clear(&this->m_string);
  vostok::buffer_string::appendf_va_list(&this->m_string, format, va);
  return this;
}
