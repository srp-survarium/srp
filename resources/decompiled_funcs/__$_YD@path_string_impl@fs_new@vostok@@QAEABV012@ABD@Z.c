vostok::fs_new::native_path_string *__usercall vostok::fs_new::path_string_impl::operator+=<char>@<eax>(
        vostok::fs_new::native_path_string *this@<eax>,
        char *s@<edx>)
{
  *this->m_string.m_end++ = *s;
  *this->m_string.m_end = 0;
  return this;
}
