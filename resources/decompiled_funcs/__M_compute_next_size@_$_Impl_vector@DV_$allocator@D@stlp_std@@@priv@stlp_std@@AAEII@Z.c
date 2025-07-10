unsigned int __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  const unsigned int *v2; // eax
  unsigned int v5; // [esp+4h] [ebp-30h]
  int v6; // [esp+8h] [ebp-2Ch]
  unsigned int v8; // [esp+10h] [ebp-24h]
  unsigned int v9; // [esp+18h] [ebp-1Ch]
  unsigned int v10; // [esp+24h] [ebp-10h]
  unsigned int __size; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+30h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  v10 = stlp_std::allocator<char>::max_size(&this->_M_end_of_storage);
  if ( v10 == -1 )
    v6 = -1;
  else
    v6 = v10;
  if ( __n > v6 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v2 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v2 + __size;
  v9 = stlp_std::allocator<char>::max_size(&this->_M_end_of_storage);
  if ( v9 == -1 )
    v5 = -1;
  else
    v5 = v9;
  if ( __len > v5 || __len < __size )
  {
    v8 = stlp_std::allocator<char>::max_size(&this->_M_end_of_storage);
    if ( v8 == -1 )
      return -1;
    else
      return v8;
  }
  return __len;
}
