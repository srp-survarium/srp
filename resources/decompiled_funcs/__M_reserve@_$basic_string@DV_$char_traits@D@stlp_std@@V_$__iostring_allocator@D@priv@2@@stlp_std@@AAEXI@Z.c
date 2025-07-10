void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *p_M_start_of_storage; // ebp
  char *M_static_buf; // edi
  char *v5; // ebx
  char *M_data; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  if ( __n <= 0x101 )
    M_static_buf = this->_M_start_of_storage._M_static_buf;
  else
    M_static_buf = (char *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, __n, 0);
  v5 = stlp_std::priv::__ucopy<char *,char *,int>(this->_M_start_of_storage._M_data, this->_M_finish, M_static_buf);
  *v5 = 0;
  M_data = this->_M_start_of_storage._M_data;
  if ( M_data != (char *)this && M_data && M_data != (char *)p_M_start_of_storage )
  {
    if ( (unsigned int)(this->_M_buffers._M_end_of_storage - M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        this->_M_buffers._M_end_of_storage - M_data);
    else
      operator delete(this->_M_start_of_storage._M_data);
  }
  this->_M_start_of_storage._M_data = M_static_buf;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = &M_static_buf[__n];
}
