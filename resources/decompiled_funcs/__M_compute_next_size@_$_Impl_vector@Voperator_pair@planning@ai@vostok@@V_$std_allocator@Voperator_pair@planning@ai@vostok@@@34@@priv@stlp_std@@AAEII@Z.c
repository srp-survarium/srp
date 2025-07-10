unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  int v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  unsigned int v9; // [esp+4h] [ebp-3Ch]
  int v10; // [esp+8h] [ebp-38h]
  unsigned int v12; // [esp+14h] [ebp-2Ch]
  unsigned int v13; // [esp+20h] [ebp-20h]
  unsigned int v14; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    v14 = 0x1FFFFFFF;
  else
    v14 = 1;
  if ( v14 >= 0x1FFFFFFF )
    v10 = 0x1FFFFFFF;
  else
    v10 = v14;
  if ( __n > v10 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)__len);
  if ( *v5 )
    v13 = 0x1FFFFFFF;
  else
    v13 = 1;
  if ( v13 >= 0x1FFFFFFF )
  {
    v4 = 0x1FFFFFFF;
    v9 = 0x1FFFFFFF;
  }
  else
  {
    v9 = v13;
  }
  if ( __len > v9 || __len < __size )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v4);
    if ( *v6 )
      v12 = 0x1FFFFFFF;
    else
      v12 = 1;
    if ( v12 >= 0x1FFFFFFF )
      return 0x1FFFFFFF;
    else
      return v12;
  }
  return __len;
}
