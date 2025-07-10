unsigned int __thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned int __n)
{
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 0x1FFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( __len > 0x1FFFFFFF || __len < __size )
    return 0x1FFFFFFF;
  return __len;
}
