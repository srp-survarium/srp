void __thiscall vostok::fs_new::path_string_impl::convert(
        vostok::fs_new::path_string_impl *this,
        char *begin,
        char *end)
{
  char other_separator; // [esp+Fh] [ebp-1h]

  other_separator = this->m_separator != 47 ? 47 : 92;
  while ( begin != end )
  {
    if ( *begin == other_separator )
      *begin = this->m_separator;
    ++begin;
  }
}
