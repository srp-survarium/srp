void **__thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int *__n,
        stlp_std::locale::facet **__first,
        stlp_std::locale::facet **__last)
{
  unsigned __int8 *v4; // esi

  v4 = (unsigned __int8 *)stlp_std::allocator<void *>::_M_allocate(&this->_M_end_of_storage, *__n, __n);
  if ( __last != __first )
    memcpy(v4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
  return (void **)v4;
}
