vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::make_lowercase(
        vostok::fs_new::path_string_impl *this)
{
  vostok::buffer_string::make_lowercase(&this->m_string);
  return this;
}
