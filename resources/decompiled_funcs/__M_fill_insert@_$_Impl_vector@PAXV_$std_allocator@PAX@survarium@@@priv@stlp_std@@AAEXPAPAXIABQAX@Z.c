void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        void **__pos,
        const stlp_std::__true_type *__n,
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *__x)
{
  bool v4; // [esp+0h] [ebp-Ch]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
    {
      stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
        __x,
        (unsigned __int8 **)this,
        __pos,
        (void *const *)&__x->_M_start,
        __n,
        0,
        v4);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        (void *const *)&__x->_M_start,
        &__formal);
    }
  }
}
