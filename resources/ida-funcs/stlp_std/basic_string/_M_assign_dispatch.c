stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_assign_dispatch<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        char *__f,
        char *__l,
        const stlp_std::__false_type *__formal)
{
  char *v4; // eax
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


stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_assign_dispatch<wchar_t const *>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        wchar_t *__f,
        wchar_t *__l,
        const stlp_std::__false_type *__formal)
{
  wchar_t *v4; // eax
  const wchar_t *v6; // ecx
  wchar_t *M_data; // edi
  unsigned __int8 *M_finish; // esi

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
    if ( M_data != (wchar_t *)M_finish )
    {
      memmove((unsigned __int8 *)M_data, M_finish, 2u);
      this->_M_finish -= (M_finish - (unsigned __int8 *)M_data) >> 1;
    }
    return this;
  }
  else
  {
    stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_appendT<wchar_t const *>(
      this,
      v4,
      v6,
      (const stlp_std::forward_iterator_tag *)&__f);
    return this;
  }
}
