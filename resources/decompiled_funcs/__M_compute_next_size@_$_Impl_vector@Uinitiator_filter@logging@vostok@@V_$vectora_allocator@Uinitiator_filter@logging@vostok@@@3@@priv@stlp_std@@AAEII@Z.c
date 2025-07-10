unsigned __int8 *__thiscall stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned __int8 *v10; // [esp+4h] [ebp-3Ch]
  unsigned __int8 *v11; // [esp+8h] [ebp-38h]
  unsigned int v13; // [esp+14h] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-20h]
  unsigned int v15; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x3C);
  if ( *v2 )
    v15 = (unsigned int)&vostok::memory::s_CRT_arena[60379772];
  else
    v15 = 1;
  if ( v15 >= (unsigned int)&vostok::memory::s_CRT_arena[60379772] )
    v11 = &vostok::memory::s_CRT_arena[60379772];
  else
    v11 = (unsigned __int8 *)v15;
  if ( __n > (unsigned int)&v11[-__size] )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v6 )
    v14 = (unsigned int)&vostok::memory::s_CRT_arena[60379772];
  else
    v14 = 1;
  if ( v14 >= (unsigned int)&vostok::memory::s_CRT_arena[60379772] )
  {
    v10 = &vostok::memory::s_CRT_arena[60379772];
  }
  else
  {
    v5 = (survarium::game_camera *)v14;
    v10 = (unsigned __int8 *)v14;
  }
  if ( __len > (unsigned int)v10 || (v5 = (survarium::game_camera *)__len, __len < __size) )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      v13 = (unsigned int)&vostok::memory::s_CRT_arena[60379772];
    else
      v13 = 1;
    if ( v13 >= (unsigned int)&vostok::memory::s_CRT_arena[60379772] )
      return &vostok::memory::s_CRT_arena[60379772];
    else
      return (unsigned __int8 *)v13;
  }
  return (unsigned __int8 *)__len;
}
