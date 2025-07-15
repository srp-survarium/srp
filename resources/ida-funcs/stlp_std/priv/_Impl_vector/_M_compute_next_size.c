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


unsigned int __usercall stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = a2[1] - *a2;
  __na = 1;
  __size = v2;
  if ( v2 == -1 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result < v2 )
    return -1;
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) >> 1;
  __size = v3;
  if ( __n > 0x7FFFFFFF - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x7FFFFFFF || result < v3 )
    return 0x7FFFFFFF;
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        unsigned int __n)
{
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 0x3FFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( __len > 0x3FFFFFFF || __len < __size )
    return 0x3FFFFFFF;
  return __len;
}


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


unsigned int __userpurge stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 52;
  __size = v3;
  if ( __n > 82595524 - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x4EC4EC4 || result < v3 )
    return 82595524;
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 36;
  __size = v3;
  if ( __n > 119304647 - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x71C71C7 || result < v3 )
    return 119304647;
  return result;
}


unsigned __int8 *__userpurge stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 56;
  __size = v3;
  if ( __n > (unsigned int)&vostok::memory::s_CRT_arena[-v3 + 65492828] )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = (unsigned __int8 *)(v3 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[65492828] || (unsigned int)result < v3 )
    return &vostok::memory::s_CRT_arena[65492828];
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 40;
  __na = 1;
  __size = v2;
  if ( v2 == 107374182 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x6666666 || result < v2 )
    return 107374182;
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 12;
  __na = 1;
  __size = v2;
  if ( v2 == 357913941 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x15555555 || result < v2 )
    return 357913941;
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 36;
  __na = 1;
  __size = v2;
  if ( v2 == 119304647 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x71C71C7 || result < v2 )
    return 119304647;
  return result;
}


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


unsigned __int8 *__userpurge stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 60;
  __size = v3;
  if ( __n > (unsigned int)&vostok::memory::s_CRT_arena[-v3 + 60379772] )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = (unsigned __int8 *)(v3 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[60379772] || (unsigned int)result < v3 )
    return &vostok::memory::s_CRT_arena[60379772];
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) >> 1;
  __na = 1;
  __size = v2;
  if ( v2 == 0x7FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x7FFFFFFF || result < v2 )
    return 0x7FFFFFFF;
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::culling::portal_sector_system::quad,vostok::render::std_allocator<vostok::render::culling::portal_sector_system::quad>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::culling::portal_sector_system::quad,vostok::render::std_allocator<vostok::render::culling::portal_sector_system::quad> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 48;
  __na = 1;
  __size = v2;
  if ( v2 == 89478485 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x5555555 || result < v2 )
    return 89478485;
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v10; // [esp+4h] [ebp-3Ch]
  int v11; // [esp+8h] [ebp-38h]
  unsigned int v13; // [esp+14h] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-20h]
  unsigned int v15; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0xC);
  if ( *v2 )
    v15 = 357913941;
  else
    v15 = 1;
  if ( v15 >= 0x15555555 )
    v11 = 357913941;
  else
    v11 = v15;
  if ( __n > v11 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v6 )
    v14 = 357913941;
  else
    v14 = 1;
  if ( v14 >= 0x15555555 )
  {
    v10 = 357913941;
  }
  else
  {
    v5 = (survarium::game_camera *)v14;
    v10 = v14;
  }
  if ( __len > v10 || (v5 = (survarium::game_camera *)__len, __len < __size) )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      v13 = 357913941;
    else
      v13 = 1;
    if ( v13 >= 0x15555555 )
      return 357913941;
    else
      return v13;
  }
  return __len;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 56;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[65492828] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[65492828] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[65492828];
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 24;
  __na = 1;
  __size = v2;
  if ( v2 == 178956970 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0xAAAAAAA || result < v2 )
    return 178956970;
  return result;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<vostok::render::requested_streamable_texture,vostok::render::std_allocator<vostok::render::requested_streamable_texture>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::requested_streamable_texture,vostok::render::std_allocator<vostok::render::requested_streamable_texture> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 280;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[4136152] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[4136152] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[4136152];
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 848;
  __na = 1;
  __size = v2;
  if ( (_UNKNOWN *)((char *)&loc_4D4871 + 2) == (_UNKNOWN *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > (unsigned int)&loc_4D4871 + 2 || result < v2 )
    return (unsigned int)&loc_4D4871 + 2;
  return result;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) >> 5;
  __na = 1;
  __size = v2;
  if ( v2 == 0x7FFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x7FFFFFF || result < v2 )
    return 0x7FFFFFF;
  return result;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<vostok::render::streamable_texture_info,vostok::render::std_allocator<vostok::render::streamable_texture_info>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::streamable_texture_info,vostok::render::std_allocator<vostok::render::streamable_texture_info> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 288;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[3710064] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[3710064] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[3710064];
  return result;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 276;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[4358459] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[4358459] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[4358459];
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) >> 3;
  __size = v3;
  if ( __n > 0x1FFFFFFF - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x1FFFFFFF || result < v3 )
    return 0x1FFFFFFF;
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this,
        unsigned int __n)
{
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 214748364 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( __len > 0xCCCCCCC || __len < __size )
    return 214748364;
  return __len;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 28;
  __size = v3;
  if ( __n > 153391689 - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x9249249 || result < v3 )
    return 153391689;
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) >> 4;
  __size = v3;
  if ( __n > 0xFFFFFFF - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0xFFFFFFF || result < v3 )
    return 0xFFFFFFF;
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *this,
        unsigned int __n)
{
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 357913941 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error(this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( __len > 0x15555555 || __len < __size )
    return 357913941;
  return __len;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<vostok::render::volume_fog_parameters,vostok::render::std_allocator<vostok::render::volume_fog_parameters>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::volume_fog_parameters,vostok::render::std_allocator<vostok::render::volume_fog_parameters> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 116;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[25822564] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[25822564] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[25822564];
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > *this,
        unsigned int __n)
{
  unsigned int *p_n; // [esp+8h] [ebp-3Ch]
  unsigned int __size; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+40h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 0xFFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  if ( __n >= __size )
    p_n = &__n;
  else
    p_n = &__size;
  __len = *p_n + __size;
  if ( __len > 0xFFFFFFF || __len < __size )
    return 0xFFFFFFF;
  return __len;
}


unsigned __int8 *__userpurge stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) >> 6;
  __size = v3;
  if ( __n > (unsigned int)&vostok::memory::s_CRT_arena[-v3 + 55905847] )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = (unsigned __int8 *)(v3 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[55905847] || (unsigned int)result < v3 )
    return &vostok::memory::s_CRT_arena[55905847];
  return result;
}


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


unsigned int __usercall stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 20;
  __na = 1;
  __size = v2;
  if ( v2 == 214748364 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0xCCCCCCC || result < v2 )
    return 214748364;
  return result;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v10; // [esp+4h] [ebp-3Ch]
  int v11; // [esp+8h] [ebp-38h]
  unsigned int v13; // [esp+14h] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-20h]
  unsigned int v15; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x34);
  if ( *v2 )
    v15 = 82595524;
  else
    v15 = 1;
  if ( v15 >= 0x4EC4EC4 )
    v11 = 82595524;
  else
    v11 = v15;
  if ( __n > v11 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v6 )
    v14 = 82595524;
  else
    v14 = 1;
  if ( v14 >= 0x4EC4EC4 )
  {
    v10 = 82595524;
  }
  else
  {
    v5 = (survarium::game_camera *)v14;
    v10 = v14;
  }
  if ( __len > v10 || (v5 = (survarium::game_camera *)__len, __len < __size) )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      v13 = 82595524;
    else
      v13 = 1;
    if ( v13 >= 0x4EC4EC4 )
      return 82595524;
    else
      return v13;
  }
  return __len;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v10; // [esp+4h] [ebp-3Ch]
  int v11; // [esp+8h] [ebp-38h]
  unsigned int v13; // [esp+14h] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-20h]
  unsigned int v15; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x1C);
  if ( *v2 )
    v15 = 153391689;
  else
    v15 = 1;
  if ( v15 >= 0x9249249 )
    v11 = 153391689;
  else
    v11 = v15;
  if ( __n > v11 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v6 )
    v14 = 153391689;
  else
    v14 = 1;
  if ( v14 >= 0x9249249 )
  {
    v10 = 153391689;
  }
  else
  {
    v5 = (survarium::game_camera *)v14;
    v10 = v14;
  }
  if ( __len > v10 || (v5 = (survarium::game_camera *)__len, __len < __size) )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      v13 = 153391689;
    else
      v13 = 1;
    if ( v13 >= 0x9249249 )
      return 153391689;
    else
      return v13;
  }
  return __len;
}


unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 272;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[4587304] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[4587304] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[4587304];
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 44;
  __size = v3;
  if ( __n > 97612893 - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x5D1745D || result < v3 )
    return 97612893;
  return result;
}


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


unsigned int __thiscall stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *this,
        unsigned int __n)
{
  const unsigned int *v2; // eax
  unsigned int __size; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int __len; // [esp+30h] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  if ( __n > 0x1FFFFFFF - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v2 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v2 + __size;
  if ( __len > 0x1FFFFFFF || __len < __size )
    return 0x1FFFFFFF;
  return __len;
}


unsigned int __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        unsigned int __n)
{
  _DWORD *v2; // eax
  const unsigned int *v3; // eax
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v10; // [esp+4h] [ebp-3Ch]
  int v11; // [esp+8h] [ebp-38h]
  unsigned int v13; // [esp+14h] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-20h]
  unsigned int v15; // [esp+30h] [ebp-10h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x30);
  if ( *v2 )
    v15 = 89478485;
  else
    v15 = 1;
  if ( v15 >= 0x5555555 )
    v11 = 89478485;
  else
    v11 = v15;
  if ( __n > v11 - __size )
    stlp_std::priv::_Vector_base<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_throw_length_error((stlp_std::priv::_Vector_base<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this);
  v3 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = *v3 + __size;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v6 )
    v14 = 89478485;
  else
    v14 = 1;
  if ( v14 >= 0x5555555 )
  {
    v10 = 89478485;
  }
  else
  {
    v5 = (survarium::game_camera *)v14;
    v10 = v14;
  }
  if ( __len > v10 || (v5 = (survarium::game_camera *)__len, __len < __size) )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      v13 = 89478485;
    else
      v13 = 1;
    if ( v13 >= 0x5555555 )
      return 89478485;
    else
      return v13;
  }
  return __len;
}


unsigned int __usercall stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) >> 2;
  __na = 1;
  __size = v2;
  if ( v2 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x3FFFFFFF || result < v2 )
    return 0x3FFFFFFF;
  return result;
}


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
