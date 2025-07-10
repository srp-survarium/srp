unsigned __int8 *__thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        unsigned int __n)
{
  unsigned __int8 *v4; // [esp+4h] [ebp-40h]
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned __int8 *v6; // [esp+Ch] [ebp-38h]
  unsigned int v7; // [esp+18h] [ebp-2Ch]
  unsigned int v8; // [esp+24h] [ebp-20h]
  unsigned int v9; // [esp+34h] [ebp-10h]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( vostok::memory::s_CRT_arena == (unsigned __int8 *)-20377625 )
    v9 = 1;
  else
    v9 = (unsigned int)&vostok::memory::s_CRT_arena[20377625];
  if ( v9 >= (unsigned int)&vostok::memory::s_CRT_arena[20377625] )
    v6 = &vostok::memory::s_CRT_arena[20377625];
  else
    v6 = (unsigned __int8 *)v9;
  if ( __n > (unsigned int)&v6[-__size] )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( vostok::memory::s_CRT_arena == (unsigned __int8 *)-20377625 )
    v8 = 1;
  else
    v8 = (unsigned int)&vostok::memory::s_CRT_arena[20377625];
  if ( v8 >= (unsigned int)&vostok::memory::s_CRT_arena[20377625] )
    v4 = &vostok::memory::s_CRT_arena[20377625];
  else
    v4 = (unsigned __int8 *)v8;
  if ( __len > (unsigned int)v4 || __len < __size )
  {
    if ( vostok::memory::s_CRT_arena == (unsigned __int8 *)-20377625 )
      v7 = 1;
    else
      v7 = (unsigned int)&vostok::memory::s_CRT_arena[20377625];
    if ( v7 >= (unsigned int)&vostok::memory::s_CRT_arena[20377625] )
      return &vostok::memory::s_CRT_arena[20377625];
    else
      return (unsigned __int8 *)v7;
  }
  return (unsigned __int8 *)__len;
}
