void __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_swap(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this,
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *__s)
{
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *v4; // eax
  char *M_end_of_storage; // edx
  char *v6; // eax
  char *M_finish; // ecx
  char *M_data; // ecx
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax

  if ( (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)this->_M_start_of_storage._M_data == this )
  {
    while ( (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)__s->_M_start_of_storage._M_data != __s )
    {
      v4 = this;
      this = __s;
      __s = v4;
      if ( (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)this->_M_start_of_storage._M_data != this )
        goto LABEL_4;
    }
    stlp_std::swap<stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_Buffers>(
      &this->_M_buffers,
      &__s->_M_buffers);
    M_data = this->_M_start_of_storage._M_data;
    v9 = (char *)(this->_M_finish - M_data);
    this->_M_finish = &M_data[__s->_M_finish - __s->_M_start_of_storage._M_data];
    __s->_M_finish = &v9[(_DWORD)__s];
    this->_M_start_of_storage._M_data = (char *)this;
    __s->_M_start_of_storage._M_data = (char *)__s;
  }
  else
  {
LABEL_4:
    if ( (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)__s->_M_start_of_storage._M_data == __s )
    {
      M_end_of_storage = this->_M_buffers._M_end_of_storage;
      v6 = this->_M_start_of_storage._M_data;
      M_finish = this->_M_finish;
      this->_M_buffers._M_end_of_storage = __s->_M_buffers._M_end_of_storage;
      *(_DWORD *)&this->_M_buffers._M_static_buf[4] = *(_DWORD *)&__s->_M_buffers._M_static_buf[4];
      *(_DWORD *)&this->_M_buffers._M_static_buf[8] = *(_DWORD *)&__s->_M_buffers._M_static_buf[8];
      *(_DWORD *)&this->_M_buffers._M_static_buf[12] = *(_DWORD *)&__s->_M_buffers._M_static_buf[12];
      __s->_M_start_of_storage._M_data = v6;
      this->_M_start_of_storage._M_data = (char *)this;
      this->_M_finish = (char *)this + __s->_M_finish - (char *)__s;
      __s->_M_buffers._M_end_of_storage = M_end_of_storage;
      __s->_M_start_of_storage._M_data = v6;
      __s->_M_finish = M_finish;
    }
    else
    {
      v10 = this->_M_buffers._M_end_of_storage;
      this->_M_buffers._M_end_of_storage = __s->_M_buffers._M_end_of_storage;
      __s->_M_buffers._M_end_of_storage = v10;
      v11 = this->_M_start_of_storage._M_data;
      this->_M_start_of_storage._M_data = __s->_M_start_of_storage._M_data;
      __s->_M_start_of_storage._M_data = v11;
      v12 = this->_M_finish;
      this->_M_finish = __s->_M_finish;
      __s->_M_finish = v12;
    }
  }
}
