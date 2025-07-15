void **__thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_erase(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        const stlp_std::__false_type *__formal)
{
  unsigned __int8 *M_finish; // eax

  M_finish = (unsigned __int8 *)this->_M_finish;
  if ( __pos + 1 != (void **)M_finish )
    stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos + 4, M_finish, (unsigned __int8 *)__pos);
  --this->_M_finish;
  return __pos;
}
