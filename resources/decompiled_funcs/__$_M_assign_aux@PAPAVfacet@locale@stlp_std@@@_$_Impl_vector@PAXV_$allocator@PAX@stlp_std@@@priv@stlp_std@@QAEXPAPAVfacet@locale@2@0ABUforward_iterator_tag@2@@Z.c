void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_assign_aux<stlp_std::locale::facet * *>(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        stlp_std::locale::facet **__first,
        unsigned int __last,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned int v4; // ebp
  unsigned __int8 *M_start; // edx
  int v7; // ebx
  unsigned int v8; // edi
  void **v9; // eax
  _STLP_atomic_freelist::item *v10; // ecx
  void **v11; // ebx
  void **v12; // edx
  void **v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edi
  unsigned int v17; // ecx
  unsigned __int8 *M_finish; // eax
  int v19; // eax
  stlp_std::locale::facet **v20; // [esp-4h] [ebp-14h]

  v4 = __last;
  M_start = (unsigned __int8 *)this->_M_start;
  v7 = __last - (_DWORD)__first;
  v8 = (int)(__last - (_DWORD)__first) >> 2;
  if ( v8 <= this->_M_end_of_storage._M_data - this->_M_start )
  {
    v14 = ((char *)this->_M_finish - (char *)M_start) >> 2;
    if ( v14 < v8 )
    {
      v16 = (unsigned __int8 *)&__first[v14];
      v17 = 4 * v14;
      if ( v17 )
        memmove(M_start, (unsigned __int8 *)__first, v17);
      M_finish = (unsigned __int8 *)this->_M_finish;
      if ( (unsigned __int8 *)v4 != v16 )
      {
        memcpy(M_finish, v16, v4 - (_DWORD)v16);
        M_finish = (unsigned __int8 *)(v4 - (_DWORD)v16 + v19);
      }
      this->_M_finish = (void **)M_finish;
    }
    else if ( v7 )
    {
      memmove(M_start, (unsigned __int8 *)__first, __last - (_DWORD)__first);
      this->_M_finish = (void **)(v7 + v15);
    }
    else
    {
      this->_M_finish = (void **)M_start;
    }
  }
  else
  {
    v20 = (stlp_std::locale::facet **)__last;
    __last = (int)(__last - (_DWORD)__first) >> 2;
    v9 = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
           this,
           &__last,
           __first,
           v20);
    v10 = (_STLP_atomic_freelist::item *)this->_M_start;
    v11 = v9;
    if ( this->_M_start )
    {
      if ( (unsigned int)(4 * (((char *)this->_M_end_of_storage._M_data - (char *)v10) >> 2)) > 0x80 )
      {
        operator delete(v10);
        v12 = &v11[__last];
        this->_M_start = v11;
        this->_M_end_of_storage._M_data = v12;
        this->_M_finish = &v11[v8];
        return;
      }
      stlp_std::__node_alloc::_M_deallocate(v10, 4 * (((char *)this->_M_end_of_storage._M_data - (char *)v10) >> 2));
    }
    v13 = &v11[__last];
    this->_M_start = v11;
    this->_M_end_of_storage._M_data = v13;
    this->_M_finish = &v11[v8];
  }
}
