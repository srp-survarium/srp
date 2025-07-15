void __thiscall vostok::render::environment_probe::set_properties(
        vostok::render::environment_probe *this,
        vostok::collision::geometry_instance *in_properties,
        int a3)
{
  float v3; // xmm0_4
  vostok::render::resource_manager *v4; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::query_result_for_cook *v6; // eax
  vostok::render::res_texture *texture; // esi
  const unsigned int *(__thiscall *v8)(vostok::collision::geometry_instance *); // xmm0_4
  int v9; // ecx
  const char *v10; // edi
  char *v11; // esi
  bool v12; // cf
  bool v13; // zf
  vostok::render::res_texture *v14; // eax
  vostok::render::resource_manager *v15; // esi
  float v16; // xmm0_4
  vostok::math::float4x4 *v17; // ecx
  vostok::memory::base_allocator *v18; // eax
  vostok::collision::geometry_instance *v19; // eax
  vostok::math::float4x4 *v20; // esi
  float v21; // xmm0_4
  vostok::math::float4x4 *v22; // eax
  vostok::collision::geometry_instance *v23; // eax
  vostok::collision::object *v24; // eax
  vostok::collision::geometry_instance_vtbl *v25; // ecx
  const char *v26; // [esp-4h] [ebp-1C4h]
  int v27; // [esp-4h] [ebp-1C4h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+Ch] [ebp-1B4h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+10h] [ebp-1B0h] BYREF
  char *texture_name; // [esp+14h] [ebp-1ACh]
  vostok::math::aabb scale; // [esp+18h] [ebp-1A8h] BYREF
  vostok::math::float4x4 v32; // [esp+30h] [ebp-190h] BYREF
  vostok::math::float4x4 v33; // [esp+70h] [ebp-150h] BYREF
  char *name[3]; // [esp+B0h] [ebp-110h] BYREF
  _BYTE v35[260]; // [esp+BCh] [ebp-104h] BYREF
  char vars0; // [esp+1C0h] [ebp+0h] BYREF

  vostok::render::environment_probe_properties::operator=(
    (vostok::render::environment_probe_properties *)this,
    (const vostok::render::environment_probe_properties *)&in_properties->m_delete_by_collision_object,
    a3);
  v3 = *(float *)&in_properties[76].m_delete_by_collision_object;
  *(float *)&in_properties[65].m_delete_by_collision_object = v3
                                                            + *(float *)&in_properties[65].m_delete_by_collision_object;
  *(float *)&in_properties[65].__vftable = v3 + *(float *)&in_properties[65].__vftable;
  *(_DWORD *)&in_properties[72].m_delete_by_collision_object = (unsigned __int64)(__FYL2X__(
                                                                                    (double)*(unsigned int *)(a3 + 536),
                                                                                    0.6931471805599453094)
                                                                                / __FYL2X__(2.0, 0.6931471805599453094))
                                                             + 1;
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&in_properties[1],
    &v28);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&in_properties->m_delete_by_collision_object,
    &v29);
  m_object = v28.m_object;
  if ( v28.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v29.m_object )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v29.m_object->m_lods,
      (vostok::render::res_texture *)&in_properties[75]);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object->m_lods,
      (vostok::render::res_texture *)&in_properties[74].m_delete_by_collision_object);
  }
  else if ( *(_BYTE *)(a3 + 540) )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)&in_properties[75]);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)&in_properties[74].m_delete_by_collision_object);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)&in_properties[75].m_delete_by_collision_object);
    v6 = *(vostok::resources::query_result_for_cook **)&in_properties[1].m_delete_by_collision_object;
    if ( v6 )
    {
      v4 = *(vostok::render::resource_manager **)&in_properties[1].m_delete_by_collision_object;
      if ( v6 != (vostok::resources::query_result_for_cook *)in_properties[2].__vftable )
      {
        texture = vostok::render::resource_manager::create_texture(
                    v4,
                    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v6,
                    0,
                    0,
                    0,
                    0,
                    1,
                    0xFFFFFFFF,
                    1,
                    0,
                    0);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          texture,
          (vostok::render::res_texture *)&in_properties[75]);
        v4 = (vostok::render::resource_manager *)in_properties[75].__vftable;
        if ( v4 )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v8 = (const unsigned int *(__thiscall *)(vostok::collision::geometry_instance *))LODWORD(s_bm_current_air_resistance);
            v4->available_memory = 0;
            in_properties[75].indices = v8;
            v26 = *(const char **)&in_properties[1].m_delete_by_collision_object;
            name[0] = v35;
            name[1] = v35;
            name[2] = &vars0;
            v35[0] = 0;
            vostok::fs_new::path_string_impl::assignf(
              name,
              (vostok::buffer_string *)v4,
              (vostok::buffer_string *)"%s_diffuse",
              v26);
            v9 = v27;
            texture_name = name[0];
            if ( !name[0] )
              goto LABEL_17;
            v10 = "null";
            v11 = name[0];
            v9 = 5;
            v14 = 0;
            v12 = 0;
            v13 = 1;
            do
            {
              if ( !v9 )
                break;
              v12 = (unsigned __int8)*v11 < (unsigned int)*v10;
              v13 = *v11++ == *v10++;
              --v9;
            }
            while ( v13 );
            if ( !v13 )
              v14 = (vostok::render::res_texture *)(-v12 - (v12 - 1));
            if ( v14 )
            {
LABEL_17:
              v15 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
              v14 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                     (vostok::render::resource_manager *)v9,
                                                     (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                     name[0]);
              if ( !v14 )
                v14 = vostok::render::resource_manager::load_texture(v15, texture_name, 0, 0, 0, 0, 1, 0xFFFFFFFF, 1, 0);
            }
            vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
              v14,
              (vostok::render::res_texture *)&in_properties[74].m_delete_by_collision_object);
            v16 = s_bm_current_air_resistance;
            *(_BYTE *)(*(_DWORD *)&in_properties[74].m_delete_by_collision_object + 60) = 0;
            v4 = *(vostok::render::resource_manager **)&in_properties[74].m_delete_by_collision_object;
            v4->available_memory = 0;
            *(float *)(*(_DWORD *)&in_properties[74].m_delete_by_collision_object + 24) = v16;
          }
        }
      }
    }
  }
  vostok::render::environment_probe::remove_collision((vostok::render::environment_probe *)v4, (int)in_properties);
  if ( *(_DWORD *)&in_properties[68].m_delete_by_collision_object )
  {
    v22 = vostok::math::float4x4::identity(v17, &v33);
    v23 = vostok::collision::new_box_geometry_instance(vostok::render::g_allocator, v22);
    *(_DWORD *)&in_properties[73].m_delete_by_collision_object = v23;
    v24 = vostok::collision::new_collision_object(vostok::render::g_allocator, (unsigned int)v23, in_properties);
    qmemcpy(&v32, &in_properties[35].m_delete_by_collision_object, sizeof(v32));
    v25 = in_properties[73].__vftable;
    in_properties[74].__vftable = (vostok::collision::geometry_instance_vtbl *)v24;
    (*(void (__thiscall **)(vostok::collision::geometry_instance_vtbl *, vostok::collision::object *, vostok::math::float4x4 *))v25->destroy)(
      v25,
      v24,
      &v32);
  }
  else
  {
    scale.min.x = s_bm_current_air_resistance;
    scale.min.y = s_bm_current_air_resistance;
    scale.min.z = s_bm_current_air_resistance;
    v18 = (vostok::memory::base_allocator *)vostok::math::create_scale(&scale.min, &v33);
    v19 = vostok::collision::new_sphere_geometry_instance(v18);
    *(_DWORD *)&in_properties[73].m_delete_by_collision_object = v19;
    in_properties[74].__vftable = (vostok::collision::geometry_instance_vtbl *)vostok::collision::new_collision_object(
                                                                                 vostok::render::g_allocator,
                                                                                 (unsigned int)v19,
                                                                                 in_properties);
    v20 = vostok::math::create_translation((const vostok::math::float3 *)(a3 + 504), &v33);
    v21 = *(float *)(a3 + 516);
    qmemcpy(&v32, v20, sizeof(v32));
    scale.min.x = v21;
    scale.min.y = v21;
    scale.min.z = v21;
    vostok::math::float4x4::set_scale(&v32, &scale.min);
    (*(void (__thiscall **)(vostok::collision::geometry_instance_vtbl *, vostok::collision::geometry_instance_vtbl *, vostok::math::float4x4 *))in_properties[73].destroy)(
      in_properties[73].__vftable,
      in_properties[74].__vftable,
      &v32);
  }
  qmemcpy(&in_properties[69], vostok::math::create_identity_aabb(&scale), 0x18u);
  vostok::math::aabb::modify((vostok::math::aabb *)&v32, (vostok::math::aabb *)&in_properties[69]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
}
