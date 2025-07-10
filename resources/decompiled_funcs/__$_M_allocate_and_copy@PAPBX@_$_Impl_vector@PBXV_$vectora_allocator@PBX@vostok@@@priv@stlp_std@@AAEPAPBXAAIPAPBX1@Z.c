const void **__userpurge stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_allocate_and_copy<void const * *>@<eax>(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<ecx>,
        const void ***__n@<eax>,
        const void **__first,
        int __last)
{
  unsigned __int8 *v4; // ebx
  const void **v5; // esi
  int *p_last; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi

  v4 = (unsigned __int8 *)__first;
  v5 = (const void **)__last;
  __first = *__n;
  __last = 1;
  p_last = &__last;
  if ( __first )
    p_last = (int *)&__first;
  v7 = (unsigned __int8 *)this->_M_end_of_storage.m_allocator->call_realloc(
                            this->_M_end_of_storage.m_allocator,
                            0,
                            4 * *p_last);
  v8 = v7;
  if ( v5 != (const void **)v4 )
    memcpy(v7, v4, (char *)v5 - (char *)v4);
  return (const void **)v8;
}
