void __thiscall vostok::render::ambient_light::set_properties(
        vostok::render::ambient_light *this,
        vostok::collision::geometry_instance *in_properties,
        int a3)
{
  vostok::collision::geometry_instance_vtbl *v3; // xmm0_4
  vostok::math::float4x4 *v4; // ecx
  vostok::memory::base_allocator *v5; // eax
  vostok::collision::geometry_instance *v6; // eax
  vostok::math::float4x4 *v7; // esi
  float v8; // xmm0_4
  vostok::math::float4x4 *v9; // eax
  vostok::collision::geometry_instance_vtbl *v10; // eax
  vostok::collision::object *v11; // eax
  void (__thiscall ***v12)(_DWORD, vostok::collision::object *, vostok::math::float4x4 *); // ecx
  vostok::math::aabb scale; // [esp+8h] [ebp-98h] BYREF
  vostok::math::float4x4 v14; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v15; // [esp+60h] [ebp-40h] BYREF

  v3 = in_properties[20].__vftable;
  qmemcpy(&in_properties->m_delete_by_collision_object, (const void *)a3, 0x70u);
  *(float *)&in_properties[12].__vftable = *(float *)&v3 + *(float *)&in_properties[12].__vftable;
  vostok::render::ambient_light::remove_collision(0, (int)in_properties);
  if ( *(_DWORD *)&in_properties[13].m_delete_by_collision_object )
  {
    v9 = vostok::math::float4x4::identity(v4, &v15);
    v10 = (vostok::collision::geometry_instance_vtbl *)vostok::collision::new_box_geometry_instance(
                                                         vostok::render::g_allocator,
                                                         v9);
    in_properties[18].__vftable = v10;
    v11 = vostok::collision::new_collision_object(vostok::render::g_allocator, (unsigned int)v10, in_properties);
    qmemcpy(&v14, &in_properties->m_delete_by_collision_object, sizeof(v14));
    v12 = *(void (__thiscall ****)(_DWORD, vostok::collision::object *, vostok::math::float4x4 *))&in_properties[17].m_delete_by_collision_object;
    *(_DWORD *)&in_properties[18].m_delete_by_collision_object = v11;
    (**v12)(v12, v11, &v14);
  }
  else
  {
    scale.min.x = s_bm_current_air_resistance;
    scale.min.y = s_bm_current_air_resistance;
    scale.min.z = s_bm_current_air_resistance;
    v5 = (vostok::memory::base_allocator *)vostok::math::create_scale(&scale.min, &v15);
    v6 = vostok::collision::new_sphere_geometry_instance(v5);
    in_properties[18].__vftable = (vostok::collision::geometry_instance_vtbl *)v6;
    *(_DWORD *)&in_properties[18].m_delete_by_collision_object = vostok::collision::new_collision_object(
                                                                   vostok::render::g_allocator,
                                                                   (unsigned int)v6,
                                                                   in_properties);
    v7 = vostok::math::create_translation((const vostok::math::float3 *)(a3 + 64), &v15);
    v8 = *(float *)(a3 + 92);
    qmemcpy(&v14, v7, sizeof(v14));
    scale.min.x = v8;
    scale.min.y = v8;
    scale.min.z = v8;
    vostok::math::float4x4::set_scale(&v14, &scale.min);
    (***(void (__thiscall ****)(_DWORD, _DWORD, vostok::math::float4x4 *))&in_properties[17].m_delete_by_collision_object)(
      *(_DWORD *)&in_properties[17].m_delete_by_collision_object,
      *(_DWORD *)&in_properties[18].m_delete_by_collision_object,
      &v14);
  }
  qmemcpy(&in_properties[14].m_delete_by_collision_object, vostok::math::create_identity_aabb(&scale), 0x18u);
  vostok::math::aabb::modify(
    (vostok::math::aabb *)&v14,
    (vostok::math::aabb *)&in_properties[14].m_delete_by_collision_object);
}
