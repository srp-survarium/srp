void __thiscall stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *this)
{
  if ( this->_M_impl._M_start )
    stlp_std::__node_alloc::deallocate(
      (_STLP_atomic_freelist::item *)this->_M_impl._M_start,
      this->_M_impl._M_end_of_storage._M_data - this->_M_impl._M_start);
}


void __thiscall stlp_std::vector<stlp_std::locale::facet *,stlp_std::allocator<stlp_std::locale::facet *>>::~vector<stlp_std::locale::facet *,stlp_std::allocator<stlp_std::locale::facet *>>(
        stlp_std::vector<stlp_std::locale::facet *,stlp_std::allocator<stlp_std::locale::facet *> > *this)
{
  _STLP_atomic_freelist::item *M_start; // edx

  M_start = (_STLP_atomic_freelist::item *)this->_M_impl._M_start;
  if ( this->_M_impl._M_start )
  {
    if ( (unsigned int)(4 * (((char *)this->_M_impl._M_end_of_storage._M_data - (char *)M_start) >> 2)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        M_start,
        4 * (((char *)this->_M_impl._M_end_of_storage._M_data - (char *)M_start) >> 2));
    else
      operator delete(this->_M_impl._M_start);
  }
}
