void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        void **__pos,
        unsigned int __n,
        void *const *__x,
        const stlp_std::__false_type *__formal)
{
  void **v7; // [esp+8h] [ebp-50h]
  int i; // [esp+Ch] [ebp-4Ch]
  void **v9; // [esp+2Ch] [ebp-2Ch]
  int j; // [esp+30h] [ebp-28h]
  stlp_std::__false_type v11; // [esp+4Bh] [ebp-Dh] BYREF
  void *__x_copy; // [esp+4Ch] [ebp-Ch] BYREF
  void **__old_finish; // [esp+50h] [ebp-8h]
  unsigned int __elems_after; // [esp+54h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v11 = 0;
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v11);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)__pos,
        (unsigned __int8 *)__old_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __elems_after;
      v7 = __pos;
      for ( i = __old_finish - __pos; i > 0; --i )
        *v7++ = *__x;
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &__old_finish[-__n], (char *)__old_finish);
      v9 = __pos;
      for ( j = (int)(4 * __n) >> 2; j > 0; --j )
        *v9++ = *__x;
    }
  }
}
