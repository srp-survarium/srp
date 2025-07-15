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


void __userpurge stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_assign_aux<char const * *>(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<esi>,
        const char **__first@<eax>,
        unsigned int __last,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *M_start; // edx
  unsigned int v5; // ebp
  int v6; // ebx
  unsigned int v7; // edi
  const void **v8; // ebx
  const void **v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned int v13; // ecx
  unsigned __int8 *M_finish; // eax
  int v15; // eax
  const void **v16; // [esp-4h] [ebp-10h]

  M_start = (unsigned __int8 *)this->_M_start;
  v5 = __last;
  v6 = __last - (_DWORD)__first;
  v7 = (int)(__last - (_DWORD)__first) >> 2;
  if ( v7 <= this->_M_end_of_storage._M_data - this->_M_start )
  {
    v10 = ((char *)this->_M_finish - (char *)M_start) >> 2;
    if ( v10 < v7 )
    {
      v12 = (unsigned __int8 *)&__first[v10];
      v13 = 4 * v10;
      if ( v13 )
        memmove(M_start, (unsigned __int8 *)__first, v13);
      M_finish = (unsigned __int8 *)this->_M_finish;
      if ( (unsigned __int8 *)v5 != v12 )
      {
        memcpy(M_finish, v12, v5 - (_DWORD)v12);
        M_finish = (unsigned __int8 *)(v5 - (_DWORD)v12 + v15);
      }
      this->_M_finish = (const void **)M_finish;
    }
    else if ( v6 )
    {
      memmove(M_start, (unsigned __int8 *)__first, __last - (_DWORD)__first);
      this->_M_finish = (const void **)(v6 + v11);
    }
    else
    {
      this->_M_finish = (const void **)M_start;
    }
  }
  else
  {
    v16 = (const void **)__last;
    __last = (int)(__last - (_DWORD)__first) >> 2;
    v8 = stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_allocate_and_copy<void const * *>(
           this,
           &__last,
           (const void **)__first,
           v16);
    this->_M_end_of_storage.m_allocator->call_free(this->_M_end_of_storage.m_allocator, this->_M_start);
    v9 = &v8[__last];
    this->_M_start = v8;
    this->_M_end_of_storage._M_data = v9;
    this->_M_finish = &v8[v7];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_assign_aux<unsigned short const *>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<esi>,
        char *__first@<eax>,
        unsigned int __last,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *M_start; // edx
  unsigned int v5; // ebp
  int v6; // ebx
  unsigned int v7; // edi
  unsigned __int16 *v8; // ebx
  unsigned __int16 *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned int v13; // ecx
  unsigned __int8 *M_finish; // eax
  int v15; // eax
  const unsigned __int16 *v16; // [esp-4h] [ebp-10h]

  M_start = (unsigned __int8 *)this->_M_start;
  v5 = __last;
  v6 = __last - (_DWORD)__first;
  v7 = (int)(__last - (_DWORD)__first) >> 1;
  if ( v7 <= this->_M_end_of_storage._M_data - this->_M_start )
  {
    v10 = ((char *)this->_M_finish - (char *)M_start) >> 1;
    if ( v10 < v7 )
    {
      v12 = (unsigned __int8 *)&__first[2 * v10];
      v13 = 2 * v10;
      if ( v13 )
        memmove(M_start, (unsigned __int8 *)__first, v13);
      M_finish = (unsigned __int8 *)this->_M_finish;
      if ( (unsigned __int8 *)v5 != v12 )
      {
        memcpy(M_finish, v12, v5 - (_DWORD)v12);
        M_finish = (unsigned __int8 *)(v5 - (_DWORD)v12 + v15);
      }
      this->_M_finish = (unsigned __int16 *)M_finish;
    }
    else if ( v6 )
    {
      memmove(M_start, (unsigned __int8 *)__first, __last - (_DWORD)__first);
      this->_M_finish = (unsigned __int16 *)(v6 + v11);
    }
    else
    {
      this->_M_finish = (unsigned __int16 *)M_start;
    }
  }
  else
  {
    v16 = (const unsigned __int16 *)__last;
    __last = (int)(__last - (_DWORD)__first) >> 1;
    v8 = stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_allocate_and_copy<unsigned short const *>(
           this,
           &__last,
           (const unsigned __int16 *)__first,
           v16);
    this->_M_end_of_storage.m_allocator->call_free(this->_M_end_of_storage.m_allocator, this->_M_start);
    v9 = &v8[__last];
    this->_M_start = v8;
    this->_M_end_of_storage._M_data = v9;
    this->_M_finish = &v8[v7];
  }
}
