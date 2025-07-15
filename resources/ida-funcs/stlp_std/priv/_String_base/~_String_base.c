// attributes: thunk
void __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::~_String_base<char,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this)
{
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(this);
}


void __thiscall stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::~_String_base<wchar_t,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this)
{
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *M_data; // eax
  wchar_t *v2; // edx

  M_data = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data;
  if ( M_data != this && M_data )
  {
    v2 = this->_M_start_of_storage._M_data;
    if ( (unsigned int)(2 * (((char *)this->_M_buffers._M_end_of_storage - (char *)M_data) >> 1)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v2,
        2 * (this->_M_buffers._M_end_of_storage - v2));
    else
      operator delete(v2);
  }
}
