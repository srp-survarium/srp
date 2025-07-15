void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int __n)
{
  void **M_start; // eax
  stlp_std::allocator<void *> *p_M_end_of_storage; // ebp
  void **M_finish; // ecx
  int v6; // ebx
  _STLP_atomic_freelist::item *v7; // edi
  _STLP_atomic_freelist::item *v8; // eax

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
      v7 = (_STLP_atomic_freelist::item *)stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
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
    this->_M_start = (void **)&v7->_M_next;
    this->_M_finish = (void **)&v7[v6]._M_next;
    *(_DWORD *)&p_M_end_of_storage->stlp_std::__stlport_class<stlp_std::allocator<void *> > = v8;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *a2@<esi>,
        unsigned int __n)
{
  unsigned __int8 *m_allocator; // ebx
  int v4; // edi
  vostok::memory::base_allocator *v5; // ebx
  void **v6; // eax
  unsigned __int8 *v7; // [esp+Ch] [ebp-8h]
  unsigned __int8 *M_data; // [esp+10h] [ebp-4h]

  m_allocator = (unsigned __int8 *)a2->m_allocator;
  if ( ((char *)a2[1]._M_data - (char *)a2->m_allocator) >> 2 < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    M_data = (unsigned __int8 *)a2->_M_data;
    v4 = (M_data - m_allocator) >> 2;
    if ( m_allocator )
    {
      v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *>>::allocate(
                                __n,
                                &__n,
                                a2 + 1);
      stlp_std::priv::__ucopy_trivial(m_allocator, M_data, v7);
      v5 = (vostok::memory::base_allocator *)v7;
      a2[1].m_allocator->call_free(
        a2[1].m_allocator,
        a2->m_allocator,
        "vostok::detail::std_allocator<void *>::deallocate",
        "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
        102u);
    }
    else
    {
      v5 = (vostok::memory::base_allocator *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *>>::allocate(
                                               __n,
                                               &__n,
                                               a2 + 1);
    }
    a2->_M_data = (void **)(&v5->__vftable + v4);
    v6 = (void **)(&v5->__vftable + __n);
    a2->m_allocator = v5;
    a2[1]._M_data = v6;
  }
}
