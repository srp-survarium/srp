void __thiscall stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_M_deallocate_block(
        stlp_std::priv::__basic_iostring<char> *this)
{
  char *M_data; // eax
  char *v2; // edx

  M_data = this->_M_start_of_storage._M_data;
  if ( M_data != (char *)this )
  {
    if ( M_data )
    {
      v2 = (char *)(this->_M_buffers._M_end_of_storage - M_data);
      if ( M_data != (char *)&this->_M_start_of_storage )
      {
        if ( (unsigned int)v2 <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate((_STLP_atomic_freelist::item *)M_data, (unsigned int)v2);
        else
          operator delete(M_data);
      }
    }
  }
}
