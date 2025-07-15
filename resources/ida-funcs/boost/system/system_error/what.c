char *__thiscall boost::system::system_error::what(boost::system::system_error *this)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  char *__s; // [esp+24h] [ebp-3Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v6; // [esp+48h] [ebp-18h] BYREF

  if ( this->m_what._M_start_of_storage._M_data == this->m_what._M_finish )
  {
    __s = (char *)stlp_std::__Named_exception::what(this);
    v1 = stlp_std::char_traits<char>::length(__s);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
      &this->m_what,
      __s,
      &__s[v1]);
    if ( this->m_what._M_start_of_storage._M_data != this->m_what._M_finish )
    {
      v2 = stlp_std::char_traits<char>::length(": ");
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
        &this->m_what,
        ": ",
        (char *)&_first[v2]);
    }
    this->m_error_code.m_cat->message(this->m_error_code.m_cat, &v6, this->m_error_code.m_val);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
      &this->m_what,
      v6._M_start_of_storage._M_data,
      v6._M_finish);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v6);
  }
  return this->m_what._M_start_of_storage._M_data;
}
