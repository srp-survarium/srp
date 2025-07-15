void __thiscall vostok::render::decal_instance::set_properties(
        vostok::render::decal_instance *this,
        vostok::render::decal_properties *in_properties,
        char *a3)
{
  vostok::render::decal_properties *v3; // ebx
  char *v4; // esi
  float x; // edi
  int v6; // esi
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // edi
  char *v8; // eax
  vostok::render::decal_instance *v9; // ecx
  vostok::math::float4x4 *v10; // ecx
  vostok::math::float4x4 *v11; // eax
  vostok::collision::geometry_instance *v12; // eax
  vostok::math::aabb *p_e01; // ebx
  vostok::math::float4x4 v14; // [esp+10h] [ebp-A0h] BYREF
  vostok::math::float4x4 v15; // [esp+50h] [ebp-60h] BYREF
  vostok::math::aabb v16; // [esp+94h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+ACh] [ebp-4h] BYREF

  v3 = in_properties;
  v4 = a3 + 64;
  if ( !*((_DWORD *)a3 + 16) || (x = in_properties->width_height_far_distance.x, x == 0.0) )
  {
    v7 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 64);
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)a3
    + 16,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&in_properties->width_height_far_distance);
    if ( LODWORD(v3->width_height_far_distance.x)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::decal_instance::set_materail_effects((vostok::render::decal_instance *)v3, v7);
    }
  }
  else
  {
    v17.m_object = 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
    v17.m_object = (vostok::particle::particle_system_instance_impl *)LODWORD(x);
    _InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(x) + 208), 1u);
    v6 = *(_DWORD *)v4;
    in_properties = 0;
    if ( v6 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_properties);
      in_properties = (vostok::render::decal_properties *)v6;
      _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 1u);
    }
    if ( vostok::detail::strcmp_s(
           *(const char **)(LODWORD(x) + 264),
           (const char *)LODWORD(in_properties[2].width_height_far_distance.y)) )
    {
      vostok::render::decal_instance::set_materail_effects(
        (vostok::render::decal_instance *)v3,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)a3
      + 16);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_properties);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
  }
  v8 = a3;
  qmemcpy(&v3->transform.e01, a3, 0x40u);
  v3->width_height_far_distance.y = *((float *)v8 + 17);
  v3->width_height_far_distance.z = *((float *)v8 + 18);
  v3->alpha_angle = *((float *)v8 + 19);
  v3->clip_angle = *((float *)v8 + 20);
  v3->draw_priority = *((float *)v8 + 21);
  LOBYTE(v3[1].transform.i.x) = v8[92];
  BYTE1(v3[1].transform.i.x) = v8[93];
  BYTE2(v3[1].transform.right.elements[0]) = v8[94];
  v9 = (vostok::render::decal_instance *)(unsigned __int8)v8[95];
  HIBYTE(v3[1].transform.elements[0][0]) = (_BYTE)v9;
  *(float *)&v3->projection_on_terrain_geometry = *((float *)v8 + 22);
  vostok::render::decal_instance::remove_collision(v9, (int)v3);
  qmemcpy(&v14, &v3->transform.e01, sizeof(v14));
  v16.max.x = s_bm_current_air_resistance;
  v16.max.y = s_bm_current_air_resistance;
  v16.max.z = s_bm_current_air_resistance;
  vostok::math::float4x4::set_scale(&v14, &v16.max);
  v16.max = *(vostok::math::float3 *)(a3 + 68);
  v11 = vostok::math::float4x4::identity(v10, &v14);
  v12 = vostok::collision::new_box_geometry_instance(vostok::render::g_allocator, v11);
  LODWORD(v3[1].transform.k.y) = v12;
  LODWORD(v3[1].transform.k.z) = vostok::collision::new_collision_object(
                                   vostok::render::g_allocator,
                                   (unsigned int)v12,
                                   (vostok::collision::geometry_instance *)v3);
  qmemcpy(&v15, &v3->transform.e01, sizeof(v15));
  vostok::math::float4x4::set_scale(&v15, &v16.max);
  (**(void (__thiscall ***)(_DWORD, _DWORD, vostok::math::float4x4 *))LODWORD(v3[1].transform.k.x))(
    LODWORD(v3[1].transform.k.x),
    LODWORD(v3[1].transform.k.z),
    &v15);
  p_e01 = (vostok::math::aabb *)&v3[1].transform.e01;
  qmemcpy(p_e01, vostok::math::create_identity_aabb(&v16), sizeof(vostok::math::aabb));
  vostok::math::aabb::modify((vostok::math::aabb *)&v15, p_e01);
}
