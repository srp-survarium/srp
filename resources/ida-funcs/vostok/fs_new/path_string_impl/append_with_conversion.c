const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::append_with_conversion<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        char **s@<eax>)
{
  char *m_end; // edi
  char *v5; // [esp+0h] [ebp-8h]

  m_end = this->m_string.m_end;
  vostok::buffer_string::append(&this->m_string, (int)this, *s);
  vostok::fs_new::path_string_impl::convert(
    (vostok::fs_new::path_string_impl *)m_end,
    (int)this,
    (vostok::fs_new::path_string_impl *)this->m_string.m_end,
    v5);
  return this;
}


const vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::append_with_conversion<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        const char *end@<eax>,
        char *begin)
{
  char *m_end; // edi
  char *v6; // [esp+0h] [ebp-8h]

  m_end = this->m_string.m_end;
  vostok::buffer_string::append(&this->m_string, end, begin);
  vostok::fs_new::path_string_impl::convert(
    (vostok::fs_new::path_string_impl *)m_end,
    (int)this,
    (vostok::fs_new::path_string_impl *)this->m_string.m_end,
    v6);
  return this;
}
