survarium::usable_object *__usercall survarium::base_player::detect_usable_object@<eax>(
        survarium::base_player *this@<ecx>,
        const vostok::math::float4x4 *head_transform@<eax>)
{
  vostok::physics::world *m_physics_world; // ecx
  int v4; // ecx
  unsigned int v5; // ebx
  char *v6; // esi
  __int16 v7; // ax
  int v8; // esi
  int v9; // eax
  vostok::memory::base_allocator_vtbl *v10; // esi
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v11; // ecx
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > v13; // [esp+1Ch] [ebp-3Ch] BYREF
  vostok::memory::pthreads3_allocator *v14; // [esp+24h] [ebp-34h]
  int v15; // [esp+28h] [ebp-30h]
  int v16; // [esp+2Ch] [ebp-2Ch] BYREF
  int v17; // [esp+30h] [ebp-28h]
  vostok::memory::pthreads3_allocator *v18; // [esp+34h] [ebp-24h]
  int v19; // [esp+38h] [ebp-20h]
  unsigned int v20; // [esp+3Ch] [ebp-1Ch]
  survarium::usable_object_user_data *p_m_usable_object_user_data; // [esp+40h] [ebp-18h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v22; // [esp+44h] [ebp-14h] BYREF
  int v23; // [esp+54h] [ebp-4h]

  v16 = 0;
  v17 = 0;
  v19 = 0;
  m_physics_world = this->m_physics_world;
  v18 = &vostok::memory::g_mt_allocator;
  ((void (__thiscall *)(vostok::physics::world *, vostok::math::float4_pod *, vostok::math::float4_pod *, _DWORD, int *, int, int))m_physics_world->ray_query)(
    m_physics_world,
    &head_transform->c,
    &head_transform->k,
    LODWORD(survarium::s_usable_objects_detection_distance),
    &v16,
    276,
    138);
  v4 = 40;
  v5 = 0;
  v22._M_end_of_storage._M_data = 0;
  v23 = 0;
  p_m_usable_object_user_data = &this->m_usable_object_user_data;
  v22._M_finish = 0;
  v20 = (v17 - v16) / 40;
  if ( v20 )
  {
    v22._M_end_of_storage.m_allocator = 0;
    do
    {
      v6 = (char *)v22._M_end_of_storage.m_allocator + v16;
      v7 = (***(int (__thiscall ****)(_DWORD))((char *)&v22._M_end_of_storage.m_allocator->__vftable + v16))(*(vostok::memory::base_allocator_vtbl **)((char *)&v22._M_end_of_storage.m_allocator->__vftable + v16));
      LOWORD(v23) = v7 | v23;
      if ( (v23 & 0x80u) == 0 )
      {
        if ( (v23 & 0xA) == 0xA )
          break;
      }
      else
      {
        v8 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)v6 + 12) + 4))(*(_DWORD *)(*(_DWORD *)v6 + 12));
        v9 = *(_DWORD *)(v8 + 12) - *(_DWORD *)(v8 + 8);
        v13.m_allocator = 0;
        v13._M_data = 0;
        v14 = &vostok::memory::g_mt_allocator;
        v15 = 0;
        if ( v9 >> 2 )
        {
          do
          {
            v22._M_start = (void **) __thiscall survarium::collision_geometry_subscriber::`vcall'{4,{flat}}(*(void **)(*(_DWORD *)(v8 + 8) + 4 * v5));
            if ( v22._M_start )
              stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(&v22, &v13);
            ++v5;
          }
          while ( v5 < (*(_DWORD *)(v8 + 12) - *(_DWORD *)(v8 + 8)) >> 2 );
        }
        v10 = v13.m_allocator->__vftable;
        if ( (*((unsigned __int8 (__thiscall **)(vostok::memory::base_allocator_vtbl *, survarium::usable_object_user_data *))v13.m_allocator->~vostok::memory::base_allocator
              + 5))(
               v13.m_allocator->__vftable,
               p_m_usable_object_user_data) )
        {
          v22._M_end_of_storage._M_data = (void **)&v10->~vostok::memory::base_allocator;
          stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
            v11,
            (int)&v13);
          break;
        }
        v23 &= 0xFF7Fu;
        if ( !v22._M_end_of_storage._M_data )
          v22._M_end_of_storage._M_data = (void **)&v10->~vostok::memory::base_allocator;
        stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
          v11,
          (int)&v13);
        v5 = 0;
      }
      ++v22._M_finish;
      v22._M_end_of_storage.m_allocator += 2;
    }
    while ( v22._M_finish < (void **)v20 );
  }
  vostok::vectora<vostok::physics::closest_ray_result>::~vectora<vostok::physics::closest_ray_result>(
    (vostok::vectora<vostok::physics::closest_ray_result> *)v4,
    (int)&v16);
  return (survarium::usable_object *)v22._M_end_of_storage._M_data;
}
