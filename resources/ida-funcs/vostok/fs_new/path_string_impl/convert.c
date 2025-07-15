void __userpurge vostok::fs_new::path_string_impl::convert(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<esi>,
        vostok::fs_new::path_string_impl *begin,
        char *end)
{
  char v4; // al

  v4 = *(_BYTE *)(a2 + 272) != 47 ? 47 : 92;
  while ( this != begin )
  {
    if ( LOBYTE(this->m_string.m_begin) == v4 )
      LOBYTE(this->m_string.m_begin) = *(_BYTE *)(a2 + 272);
    this = (vostok::fs_new::path_string_impl *)((char *)this + 1);
  }
}
