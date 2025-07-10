void __thiscall stlp_std::priv::_Time_Info_Base::~_Time_Info_Base(stlp_std::priv::_Time_Info_Base *this)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v3; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v4; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v5; // ecx
  stlp_std::priv::_Time_Info_Base *v6; // eax
  char *v7; // ecx
  char *v8; // eax

  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_long_date_time_format._M_start_of_storage._M_data;
  if ( M_data != &this->_M_long_date_time_format && M_data )
  {
    if ( (unsigned int)(this->_M_long_date_time_format._M_buffers._M_end_of_storage - (char *)M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        this->_M_long_date_time_format._M_buffers._M_end_of_storage - (char *)M_data);
    else
      operator delete(M_data);
  }
  v3 = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_long_date_format._M_start_of_storage._M_data;
  if ( v3 != &this->_M_long_date_format && v3 )
  {
    if ( (unsigned int)(this->_M_long_date_format._M_buffers._M_end_of_storage - (char *)v3) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v3,
        this->_M_long_date_format._M_buffers._M_end_of_storage - (char *)v3);
    else
      operator delete(v3);
  }
  v4 = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_date_time_format._M_start_of_storage._M_data;
  if ( v4 != &this->_M_date_time_format && v4 )
  {
    if ( (unsigned int)(this->_M_date_time_format._M_buffers._M_end_of_storage - (char *)v4) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v4,
        this->_M_date_time_format._M_buffers._M_end_of_storage - (char *)v4);
    else
      operator delete(v4);
  }
  v5 = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_date_format._M_start_of_storage._M_data;
  if ( v5 != &this->_M_date_format && v5 )
  {
    if ( (unsigned int)(this->_M_date_format._M_buffers._M_end_of_storage - (char *)v5) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v5,
        this->_M_date_format._M_buffers._M_end_of_storage - (char *)v5);
    else
      operator delete(v5);
  }
  v6 = (stlp_std::priv::_Time_Info_Base *)this->_M_time_format._M_start_of_storage._M_data;
  if ( v6 != this && v6 )
  {
    v7 = this->_M_time_format._M_start_of_storage._M_data;
    v8 = (char *)(this->_M_time_format._M_buffers._M_end_of_storage - (char *)v6);
    if ( (unsigned int)v8 <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate((_STLP_atomic_freelist::item *)v7, (unsigned int)v8);
    else
      operator delete(v7);
  }
}
