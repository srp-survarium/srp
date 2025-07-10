const vostok::fs_new::virtual_path_string *__thiscall vostok::fs_new::path_string_impl::append<char const *>(
        vostok::fs_new::virtual_path_string *this,
        char **s)
{
  vostok::buffer_string::append(&this->m_string, *s);
  return this;
}
