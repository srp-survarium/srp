void __thiscall stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_M_swap(
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *this,
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *__s)
{
  stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *v4; // eax
  wchar_t *v5; // eax
  wchar_t *M_finish; // edx
  wchar_t *M_data; // ecx
  int v8; // eax
  wchar_t *M_end_of_storage; // eax
  wchar_t *v10; // eax
  wchar_t *v11; // eax
  wchar_t *__tmp_end_data; // [esp+Ch] [ebp+4h]

  if ( (stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data == this )
  {
    while ( (stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *)__s->_M_start_of_storage._M_data != __s )
    {
      v4 = this;
      this = __s;
      __s = v4;
      if ( (stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data != this )
        goto LABEL_4;
    }
    stlp_std::swap<stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_Buffers>(
      &this->_M_buffers,
      &__s->_M_buffers);
    M_data = this->_M_start_of_storage._M_data;
    v8 = this->_M_finish - M_data;
    this->_M_finish = &M_data[__s->_M_finish - __s->_M_start_of_storage._M_data];
    __s->_M_finish = (wchar_t *)((char *)__s + 2 * v8);
    this->_M_start_of_storage._M_data = (wchar_t *)this;
    __s->_M_start_of_storage._M_data = (wchar_t *)__s;
  }
  else
  {
LABEL_4:
    if ( (stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *)__s->_M_start_of_storage._M_data == __s )
    {
      v5 = this->_M_start_of_storage._M_data;
      M_finish = this->_M_finish;
      __tmp_end_data = this->_M_buffers._M_end_of_storage;
      qmemcpy(this, __s, 0x20u);
      __s->_M_start_of_storage._M_data = v5;
      this->_M_start_of_storage._M_data = (wchar_t *)this;
      this->_M_finish = (wchar_t *)((char *)this + 2 * (((char *)__s->_M_finish - (char *)__s) >> 1));
      __s->_M_buffers._M_end_of_storage = __tmp_end_data;
      __s->_M_start_of_storage._M_data = v5;
      __s->_M_finish = M_finish;
    }
    else
    {
      M_end_of_storage = this->_M_buffers._M_end_of_storage;
      this->_M_buffers._M_end_of_storage = __s->_M_buffers._M_end_of_storage;
      __s->_M_buffers._M_end_of_storage = M_end_of_storage;
      v10 = this->_M_start_of_storage._M_data;
      this->_M_start_of_storage._M_data = __s->_M_start_of_storage._M_data;
      __s->_M_start_of_storage._M_data = v10;
      v11 = this->_M_finish;
      this->_M_finish = __s->_M_finish;
      __s->_M_finish = v11;
    }
  }
}
