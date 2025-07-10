unsigned __int8 *__userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_allocate_and_copy<unsigned short const *>@<eax>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        const unsigned __int16 **__n@<eax>,
        unsigned __int16 *__first,
        int __last)
{
  unsigned __int8 *v4; // ebx
  const unsigned __int16 *v5; // esi
  int *p_last; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi

  v4 = (unsigned __int8 *)__first;
  v5 = (const unsigned __int16 *)__last;
  __first = (unsigned __int16 *)*__n;
  __last = 1;
  p_last = &__last;
  if ( __first )
    p_last = (int *)&__first;
  v7 = (unsigned __int8 *)this->_M_end_of_storage.m_allocator->call_realloc(
                            this->_M_end_of_storage.m_allocator,
                            0,
                            2 * *p_last);
  v8 = v7;
  if ( v5 != (const unsigned __int16 *)v4 )
    memcpy(v7, v4, (char *)v5 - (char *)v4);
  return v8;
}
