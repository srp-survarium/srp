void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::resize(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        unsigned int __new_size,
        const float *__x)
{
  stlp_std::__false_type __formal; // [esp+2Bh] [ebp-9h] BYREF
  float *M_start; // [esp+2Ch] [ebp-8h]
  vostok::sound::search::vertex_id_type *__last; // [esp+30h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = (vostok::sound::search::vertex_id_type *)this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != (float *)__last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_erase(
        (stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this,
        (vostok::sound::search::vertex_id_type *)&M_start[__new_size],
        __last,
        &__formal);
    }
  }
}
