const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<char const [1]>(
        vostok::fs_new::path_string_impl *this,
        vostok::fixed_string<16> *s)
{
  vostok::fixed_string<16>::operator=(s, &this->m_string);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}
