void __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *p_M_start_of_storage; // edi
  char *v4; // eax
  unsigned int v5; // edx

  if ( !__n )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( __n > 0x10 )
  {
    p_M_start_of_storage = &this->_M_start_of_storage;
    v4 = stlp_std::allocator<char>::_M_allocate(&this->_M_start_of_storage, __n, &__n);
    v5 = __n;
    p_M_start_of_storage->_M_data = v4;
    this->_M_finish = v4;
    this->_M_buffers._M_end_of_storage = &v4[v5];
  }
}
