vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::assign<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        vostok::buffer_string *a2@<eax>,
        char **begin,
        const char **end)
{
  char *m_begin; // eax

  m_begin = a2->m_begin;
  a2->m_end = m_begin;
  *m_begin = 0;
  vostok::buffer_string::append(a2, *end, *begin);
  return (vostok::fs_new::path_string_impl *)a2;
}
