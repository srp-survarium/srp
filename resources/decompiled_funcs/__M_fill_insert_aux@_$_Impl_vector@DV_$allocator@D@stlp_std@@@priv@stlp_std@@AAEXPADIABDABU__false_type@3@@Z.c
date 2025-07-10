void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        unsigned int __n,
        const char *__x,
        const stlp_std::__false_type *__formal)
{
  int i; // [esp+18h] [ebp-34h]
  char *M_finish; // [esp+1Ch] [ebp-30h]
  char *v9; // [esp+24h] [ebp-28h]
  stlp_std::__false_type v10; // [esp+42h] [ebp-Ah] BYREF
  char __x_copy; // [esp+43h] [ebp-9h] BYREF
  char *__old_finish; // [esp+44h] [ebp-8h]
  unsigned int __elems_after; // [esp+48h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v10 = 0;
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(this, __pos, __n, &__x_copy, &v10);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      v9 = &this->_M_finish[__n - __elems_after];
      M_finish = this->_M_finish;
      for ( i = __n - __elems_after; i > 0; --i )
      {
        survarium::generate_shaders_world::is_loading();
        survarium::generate_shaders_world::is_loading();
        *M_finish++ = *__x;
      }
      this->_M_finish = v9;
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)__pos,
        (unsigned __int8 *)__old_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __elems_after;
      memset((unsigned __int8 *)__pos, *__x, __old_finish - __pos);
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &__old_finish[-__n], __old_finish);
      memset((unsigned __int8 *)__pos, *__x, __n);
    }
  }
}
