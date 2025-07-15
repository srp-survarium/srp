void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::clear(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this)
{
  if ( this->_M_start_of_storage._M_data != this->_M_finish )
  {
    *(_BYTE *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this) = 0;
    this->_M_finish = (char *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
  }
}
