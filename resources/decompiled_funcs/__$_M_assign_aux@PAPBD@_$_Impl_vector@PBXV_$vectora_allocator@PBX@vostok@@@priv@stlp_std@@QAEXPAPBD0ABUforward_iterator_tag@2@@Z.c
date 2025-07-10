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
