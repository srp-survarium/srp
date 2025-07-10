void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n,
        char __c,
        const stlp_std::allocator<char> *__a)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *p_M_start_of_storage; // edi
  char *v8; // eax
  unsigned int v9; // edx
  char *M_data; // eax
  char *v11; // edi

  v5 = __n;
  v6 = __n + 1;
  p_M_start_of_storage = &this->_M_start_of_storage;
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  __n = v6;
  if ( !v6 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( v6 > 0x10 )
  {
    v8 = stlp_std::allocator<char>::_M_allocate(&this->_M_start_of_storage, v6, &__n);
    v9 = __n;
    p_M_start_of_storage->_M_data = v8;
    this->_M_finish = v8;
    this->_M_buffers._M_end_of_storage = &v8[v9];
  }
  M_data = p_M_start_of_storage->_M_data;
  v11 = &p_M_start_of_storage->_M_data[v5];
  stlp_std::priv::__ufill<char *,char,int>(M_data, &M_data[v5], &__c);
  this->_M_finish = v11;
  *v11 = 0;
}
