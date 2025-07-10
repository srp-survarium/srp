void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        unsigned int __n,
        float *__x,
        const stlp_std::__false_type *__formal)
{
  float *v7; // [esp+14h] [ebp-50h]
  int i; // [esp+18h] [ebp-4Ch]
  float *v9; // [esp+38h] [ebp-2Ch]
  int j; // [esp+3Ch] [ebp-28h]
  float *M_finish; // [esp+4Ch] [ebp-18h]
  stlp_std::__false_type v12; // [esp+57h] [ebp-Dh] BYREF
  float __x_copy; // [esp+58h] [ebp-Ch] BYREF
  float *__old_finish; // [esp+5Ch] [ebp-8h]
  unsigned int __elems_after; // [esp+60h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v12 = 0;
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v12);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<float *,unsigned int,float>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      if ( __old_finish != __pos )
        memcpy((unsigned __int8 *)this->_M_finish, (unsigned __int8 *)__pos, (char *)__old_finish - (char *)__pos);
      this->_M_finish += __elems_after;
      v7 = __pos;
      for ( i = __old_finish - __pos; i > 0; --i )
        *v7++ = *__x;
    }
    else
    {
      M_finish = this->_M_finish;
      if ( M_finish != &M_finish[-__n] )
        memcpy((unsigned __int8 *)this->_M_finish, (unsigned __int8 *)&M_finish[-__n], 4 * __n);
      this->_M_finish += __n;
      if ( (char *)&__old_finish[-__n] - (char *)__pos > 0 )
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&__old_finish[-__n] - (char *)__pos);
      v9 = __pos;
      for ( j = (int)(4 * __n) >> 2; j > 0; --j )
        *v9++ = *__x;
    }
  }
}
