void __userpurge stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<ecx>,
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *a2@<esi>,
        unsigned int __n)
{
  const void **M_start; // ecx
  int v4; // ebx
  const void **v5; // edi
  const void **v6; // ecx

  M_start = a2->_M_start;
  if ( a2->_M_end_of_storage._M_data - a2->_M_start < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v4 = a2->_M_finish - M_start;
    if ( M_start )
    {
      v5 = stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_allocate_and_copy<void const * *>(
             a2,
             &__n,
             M_start,
             a2->_M_finish);
      a2->_M_end_of_storage.m_allocator->call_free(a2->_M_end_of_storage.m_allocator, a2->_M_start);
    }
    else
    {
      v5 = stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate(
             __n,
             &__n,
             &a2->_M_end_of_storage);
    }
    v6 = &v5[__n];
    a2->_M_start = v5;
    a2->_M_finish = &v5[v4];
    a2->_M_end_of_storage._M_data = v6;
  }
}
