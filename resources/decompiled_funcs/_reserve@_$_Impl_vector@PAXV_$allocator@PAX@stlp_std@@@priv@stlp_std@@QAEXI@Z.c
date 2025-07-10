void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int __n)
{
  void **M_start; // eax
  stlp_std::allocator<void *> *p_M_end_of_storage; // ebp
  void **M_finish; // ecx
  int v6; // ebx
  void **v7; // edi
  void **v8; // eax

  M_start = this->_M_start;
  p_M_end_of_storage = &this->_M_end_of_storage;
  if ( this->_M_end_of_storage._M_data - this->_M_start < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    M_finish = this->_M_finish;
    v6 = M_finish - M_start;
    if ( M_start )
    {
      v7 = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
             this,
             &__n,
             (stlp_std::locale::facet **)M_start,
             (stlp_std::locale::facet **)M_finish);
      stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(this);
    }
    else
    {
      v7 = stlp_std::allocator<void *>::_M_allocate(p_M_end_of_storage, __n, &__n);
    }
    v8 = &v7[__n];
    this->_M_start = v7;
    this->_M_finish = &v7[v6];
    *(_DWORD *)&p_M_end_of_storage->stlp_std::__stlport_class<stlp_std::allocator<void *> > = v8;
  }
}
