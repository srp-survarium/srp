stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_assign_dispatch<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        const char *__f,
        const char *__l,
        const stlp_std::__false_type *__formal)
{
  const char *v4; // eax
  const char *v6; // ecx
  char *M_data; // esi
  unsigned __int8 *M_finish; // ebx

  v4 = __f;
  v6 = __l;
  M_data = this->_M_start_of_storage._M_data;
  if ( __f == __l )
    goto LABEL_6;
  while ( M_data != this->_M_finish )
  {
    *M_data++ = *v4++;
    if ( v4 == v6 )
      goto LABEL_6;
  }
  if ( v4 == v6 )
  {
LABEL_6:
    M_finish = (unsigned __int8 *)this->_M_finish;
    if ( M_data != (char *)M_finish )
    {
      memmove((unsigned __int8 *)M_data, M_finish, 1u);
      this->_M_finish += M_data - (char *)M_finish;
    }
    return this;
  }
  else
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
      this,
      v4,
      v6,
      (const stlp_std::forward_iterator_tag *)&__f);
    return this;
  }
}
