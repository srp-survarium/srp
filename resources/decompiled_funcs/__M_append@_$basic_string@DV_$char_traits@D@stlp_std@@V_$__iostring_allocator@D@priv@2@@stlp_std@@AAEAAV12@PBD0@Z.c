stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_append(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        const char *__first,
        const char *__last)
{
  char *M_finish; // ecx
  unsigned int v5; // edi
  char *v6; // eax
  unsigned int size; // eax
  unsigned int v8; // ebp
  char *M_static_buf; // edi
  char *v10; // eax
  char *v11; // ebx

  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  v5 = __last - __first;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v6 = (char *)((char *)this - M_finish + 16);
  else
    v6 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
  if ( v5 < (unsigned int)v6 )
  {
    stlp_std::priv::__ucopy<char *,char *,int>(__first + 1, __last, M_finish + 1);
    this->_M_finish[v5] = 0;
    *this->_M_finish = *__first;
    this->_M_finish += v5;
    return this;
  }
  else
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             __last - __first);
    v8 = size;
    if ( size <= 0x101 )
      M_static_buf = this->_M_start_of_storage._M_static_buf;
    else
      M_static_buf = (char *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, size, 0);
    v10 = stlp_std::priv::__ucopy<char *,char *,int>(this->_M_start_of_storage._M_data, this->_M_finish, M_static_buf);
    v11 = stlp_std::priv::__ucopy<char *,char *,int>(__first, __last, v10);
    *v11 = 0;
    stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_M_deallocate_block((stlp_std::priv::__basic_iostring<char> *)this);
    this->_M_start_of_storage._M_data = M_static_buf;
    this->_M_buffers._M_end_of_storage = &M_static_buf[v8];
    this->_M_finish = v11;
    return this;
  }
}
