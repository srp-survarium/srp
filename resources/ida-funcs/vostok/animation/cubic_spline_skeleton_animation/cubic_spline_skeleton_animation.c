void __thiscall vostok::animation::cubic_spline_skeleton_animation::cubic_spline_skeleton_animation(
        vostok::animation::cubic_spline_skeleton_animation *this,
        vostok::animation::bone_names *animation,
        int a3)
{
  signed int m_internal_memory_position; // ecx
  _DWORD *v4; // eax
  vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *v5; // esi
  int v6; // edi
  int v7; // ecx
  vostok::animation::animation_event_channels *v8; // ecx
  unsigned int v9; // eax
  signed int v10; // [esp-4h] [ebp-2Ch]
  void *v11; // [esp+0h] [ebp-28h]
  unsigned int *memory; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  const vostok::animation::bi_spline_bone_animation_baked *v14; // [esp+14h] [ebp-14h]
  unsigned int *v15; // [esp+18h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> names; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h]
  const vostok::animation::bi_spline_channel_animation_baked *v18; // [esp+24h] [ebp-4h]

  animation->m_internal_memory_position = -1;
  animation->m_bone_count = -1;
  animation[1].m_internal_memory_position = -1;
  animation[1].m_bone_count = -1;
  animation[3].m_internal_memory_position = *(unsigned __int8 *)(a3 + 275);
  animation[2].m_internal_memory_position = *(unsigned __int16 *)(a3 + 272);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&names,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a3 + 264));
  vostok::animation::bone_names::create_internals_in_place(&names, animation, &animation[3].m_bone_count);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&names);
  m_internal_memory_position = animation[2].m_internal_memory_position;
  names.m_object = 0;
  memory = &animation[9 * m_internal_memory_position + 3 + 9 * m_internal_memory_position].m_bone_count;
  animation[2].m_bone_count = 72 * m_internal_memory_position + 28;
  if ( m_internal_memory_position )
  {
    v13 = 0;
    v14 = (const vostok::animation::bi_spline_bone_animation_baked *)(a3 + 276);
    do
    {
      v4 = (unsigned int *)((char *)&animation[v13].m_internal_memory_position + animation[2].m_bone_count);
      if ( v4 )
      {
        for ( m_internal_memory_position = 8; m_internal_memory_position >= 0; --m_internal_memory_position )
        {
          *v4 = -1;
          v4[1] = -1;
          v4 += 2;
        }
      }
      v5 = (vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)((char *)&animation[v13]
                                                                                                  + animation[2].m_bone_count);
      v15 = memory;
      v6 = (char *)v14 - (char *)v5;
      v17 = 9;
      do
      {
        v18 = *(const vostok::animation::bi_spline_channel_animation_baked **)((char *)&v5->m_time_channel.m_knots_count
                                                                             + v6);
        vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1>>::create_in_place_internals(
          v15,
          m_internal_memory_position,
          v5,
          v18);
        v15 += 5 * vostok::animation::poly_knots_count(v7, v18);
        ++v5;
        --v17;
      }
      while ( v17 );
      memory = (unsigned int *)((char *)memory + vostok::animation::bone_animation::count_internal_memory_size(v14));
      ++names.m_object;
      v13 += 9;
      ++v14;
      m_internal_memory_position = v10;
    }
    while ( (unsigned int)names.m_object < animation[2].m_internal_memory_position );
  }
  v8 = (vostok::animation::animation_event_channels *)(72 * *(unsigned __int16 *)(a3 + 272) + a3 + 276);
  if ( 72 * *(unsigned __int16 *)(a3 + 272) + a3 != -276 )
  {
    v9 = *(unsigned __int8 *)(a3 + 274);
    animation[1].m_internal_memory_position = v9;
    if ( v9 )
      vostok::animation::animation_event_channels::create_in_place_internals(
        v8,
        &animation[1].m_internal_memory_position,
        (const vostok::animation::bi_spline_event_channel_baked *)v8,
        (unsigned int)memory,
        v11);
  }
}
