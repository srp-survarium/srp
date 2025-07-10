unsigned int __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int __n)
{
  const unsigned int *v2; // eax
  unsigned int __size; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+30h] [ebp-4h]

  __size = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size((stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)this);
  if ( __n > 0x3FFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v2 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v2 + __size;
  if ( __len > 0x3FFFFFFF || __len < __size )
    return 0x3FFFFFFF;
  return __len;
}
