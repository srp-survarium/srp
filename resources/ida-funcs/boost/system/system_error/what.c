char *__thiscall boost::system::system_error::what(boost::system::system_error *this)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_m_what; // esi
  char *v3; // eax
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v5; // [esp+8h] [ebp-18h] BYREF

  p_m_what = &this->m_what;
  if ( this->m_what._M_start_of_storage._M_data == this->m_what._M_finish )
  {
    v3 = stlp_std::__Named_exception::what(this);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::operator=(p_m_what, v3);
    if ( p_m_what->_M_start_of_storage._M_data != p_m_what->_M_finish )
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::append(p_m_what, ": ");
    this->m_error_code.m_cat->message(
      this->m_error_code.m_cat,
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v5,
      this->m_error_code.m_val);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
      p_m_what,
      v5._M_start_of_storage._M_data,
      v5._M_finish);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v5);
  }
  return this->m_what._M_start_of_storage._M_data;
}
