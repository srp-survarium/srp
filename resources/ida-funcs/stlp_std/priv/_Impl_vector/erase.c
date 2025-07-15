void **__userpurge stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase@<eax>(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<esi>,
        void **__first@<edi>,
        void **__last)
{
  if ( __first != __last )
    this->_M_finish = (void **)stlp_std::priv::__copy_trivial(
                                 (unsigned __int8 *)__last,
                                 (unsigned __int8 *)this->_M_finish,
                                 (unsigned __int8 *)__first);
  return __first;
}


void **__usercall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase@<eax>(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<esi>,
        void **__pos@<edi>)
{
  unsigned __int8 *M_finish; // eax

  M_finish = (unsigned __int8 *)this->_M_finish;
  if ( __pos + 1 != (void **)M_finish )
    stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos + 4, M_finish, (unsigned __int8 *)__pos);
  --this->_M_finish;
  return __pos;
}
