stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *__userpurge stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator=@<eax>(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *a2@<esi>,
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *__x)
{
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v3; // ebx
  unsigned __int8 *M_start; // ecx
  unsigned __int8 *v5; // edx
  unsigned int v6; // edi
  unsigned __int8 *v7; // ebx
  void **v8; // eax
  unsigned int v9; // eax
  unsigned __int8 *v11; // [esp+8h] [ebp-8h]
  unsigned __int8 *M_finish; // [esp+Ch] [ebp-4h]

  v3 = __x;
  if ( __x != a2 )
  {
    M_start = (unsigned __int8 *)__x->_M_start;
    v5 = (unsigned __int8 *)a2->_M_start;
    M_finish = (unsigned __int8 *)__x->_M_finish;
    v6 = (M_finish - (unsigned __int8 *)__x->_M_start) >> 2;
    v11 = (unsigned __int8 *)__x->_M_start;
    if ( v6 <= a2->_M_end_of_storage._M_data - a2->_M_start )
    {
      v9 = ((char *)a2->_M_finish - (char *)v5) >> 2;
      if ( v9 < v6 )
      {
        stlp_std::priv::__copy_trivial(M_start, &M_start[4 * v9], v5);
        stlp_std::priv::__ucopy_trivial(
          (unsigned __int8 *)&v3->_M_start[a2->_M_finish - a2->_M_start],
          (unsigned __int8 *)v3->_M_finish,
          (unsigned __int8 *)a2->_M_finish);
      }
      else
      {
        stlp_std::priv::__copy_trivial(M_start, M_finish, v5);
      }
    }
    else
    {
      __x = (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)((M_finish
                                                                                       - (unsigned __int8 *)__x->_M_start) >> 2);
      v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *>>::allocate(
                                v6,
                                (unsigned int *)&__x,
                                &a2->_M_end_of_storage);
      stlp_std::priv::__ucopy_trivial(v11, M_finish, v7);
      a2->_M_end_of_storage.m_allocator->call_free(
        a2->_M_end_of_storage.m_allocator,
        a2->_M_start,
        "vostok::detail::std_allocator<void *>::deallocate",
        "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
        102u);
      v8 = (void **)&v7[4 * (_DWORD)__x];
      a2->_M_start = (void **)v7;
      a2->_M_end_of_storage._M_data = v8;
    }
    a2->_M_finish = &a2->_M_start[v6];
  }
  return a2;
}
