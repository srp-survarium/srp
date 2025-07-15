void __usercall stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *this@<ecx>,
        int a2@<eax>)
{
  void *v2; // ecx
  unsigned int v3; // eax

  v2 = *(void **)a2;
  if ( *(_DWORD *)a2 )
  {
    v3 = *(_DWORD *)(a2 + 8) - (_DWORD)v2;
    if ( v3 <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(v2, v3);
    else
      operator delete(v2);
  }
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
