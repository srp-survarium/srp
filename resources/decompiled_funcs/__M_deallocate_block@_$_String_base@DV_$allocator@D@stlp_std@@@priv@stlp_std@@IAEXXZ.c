void __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // eax
  char *v2; // edx
  char *v3; // eax

  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_start_of_storage._M_data;
  if ( M_data != this )
  {
    if ( M_data )
    {
      v2 = this->_M_start_of_storage._M_data;
      v3 = (char *)(this->_M_buffers._M_end_of_storage - (char *)M_data);
      if ( v2 )
      {
        if ( (unsigned int)v3 <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(v2, (unsigned int)v3);
        else
          operator delete(v2);
      }
    }
  }
}
