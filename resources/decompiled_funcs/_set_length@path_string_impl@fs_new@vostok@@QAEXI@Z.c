void __fastcall vostok::fs_new::path_string_impl::set_length(vostok::fs_new::path_string_impl *this, unsigned int size)
{
  char *v2; // eax

  v2 = &this->m_string.m_begin[size];
  this->m_string.m_end = v2;
  *v2 = 0;
}
