void __thiscall vostok::render::decal_instance::set_properties(
        vostok::render::decal_instance *this,
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *in_properties,
        const vostok::render::decal_properties *in_propertiesa)
{
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_material; // esi
  float v4; // ecx
  vostok::resources::unmanaged_resource *m_object; // edi
  vostok::render::decal_instance *v6; // ecx
  vostok::render::decal_instance *v7; // ecx
  vostok::render::decal_instance *z_low; // ecx
  const vostok::math::float4x4 *v9; // esi
  vostok::collision::box_geometry_instance *v10; // eax
  float v11; // eax
  float v12; // edi
  int v13; // eax
  vostok::collision::object *v14; // ecx
  float *v15; // esi
  const vostok::math::float4x4 *v16; // ecx
  __int64 v17; // xmm0_8
  const vostok::math::float4x4 *v18; // [esp+0h] [ebp-BCh]
  vostok::math::float3 sc; // [esp+10h] [ebp-ACh] BYREF
  vostok::resources::unmanaged_resource *resource[2]; // [esp+1Ch] [ebp-A0h]
  __int128 v21; // [esp+28h] [ebp-94h]
  vostok::math::float4x4 new_transform; // [esp+38h] [ebp-84h] BYREF
  vostok::math::float4x4 m; // [esp+78h] [ebp-44h] BYREF

  p_material = &in_propertiesa->material;
  if ( !in_propertiesa->material.m_object
    || (v4 = *(float *)&in_properties[17].m_object,
        resource[0] = (vostok::resources::unmanaged_resource *)LODWORD(v4),
        v4 == 0.0) )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      in_properties + 17,
      &in_propertiesa->material);
    if ( in_properties[17].m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::decal_instance::set_materail_effects(v7, in_properties, p_material);
    }
  }
  else
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v4) + 208), 1u);
    m_object = 0;
    if ( p_material->m_object )
    {
      m_object = p_material->m_object;
      _InterlockedExchangeAdd(&p_material->m_object->m_reference_count, 1u);
    }
    if ( vostok::fs_new::path_string_impl::operator!=(
           (vostok::fs_new::path_string_impl *)(LODWORD(v4) + 1176),
           (vostok::fs_new::path_string_impl *)&m_object[4].m_last_fail_of_increasing_quality) )
    {
      vostok::render::decal_instance::set_materail_effects(v6, in_properties, p_material);
    }
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    if ( !_InterlockedExchangeAdd(&resource[0]->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &resource[0]->vostok::resources::unmanaged_intrusive_base,
        resource[0]);
  }
  qmemcpy(&in_properties[1], in_propertiesa, 0x40u);
  *(_QWORD *)&in_properties[18].m_object = *(_QWORD *)&in_propertiesa->width_height_far_distance.x;
  z_low = (vostok::render::decal_instance *)LODWORD(in_propertiesa->width_height_far_distance.z);
  in_properties[20].m_object = (vostok::resources::unmanaged_resource *)z_low;
  in_properties[21].m_object = (vostok::resources::unmanaged_resource *)LODWORD(in_propertiesa->alpha_angle);
  in_properties[22].m_object = (vostok::resources::unmanaged_resource *)LODWORD(in_propertiesa->clip_angle);
  LOBYTE(in_properties[24].m_object) = in_propertiesa->projection_on_terrain_geometry;
  BYTE1(in_properties[24].m_object) = in_propertiesa->projection_on_static_geometry;
  LOBYTE(z_low) = in_propertiesa->projection_on_speedtree_geometry;
  BYTE2(in_properties[24].m_object) = (_BYTE)z_low;
  HIBYTE(in_properties[24].m_object) = in_propertiesa->projection_on_skeleton_geometry;
  LOBYTE(in_properties[25].m_object) = in_propertiesa->projection_on_particle_geometry;
  in_properties[23].m_object = (vostok::resources::unmanaged_resource *)LODWORD(in_propertiesa->draw_priority);
  vostok::render::decal_instance::remove_collision(z_low, (int)in_properties);
  qmemcpy((void *)&m, &in_properties[1], sizeof(m));
  LODWORD(sc.x) = clear_value;
  LODWORD(sc.y) = clear_value;
  LODWORD(sc.z) = clear_value;
  vostok::math::float4x4::set_scale(&m, &sc);
  sc = in_propertiesa->width_height_far_distance;
  v9 = vostok::math::float4x4::identity(&m);
  v10 = (vostok::collision::box_geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
                                                      vostok::render::g_allocator.m_object,
                                                      136);
  if ( v10 )
  {
    vostok::collision::box_geometry_instance::box_geometry_instance(v10, v9);
    v12 = v11;
  }
  else
  {
    v12 = 0.0;
  }
  *(float *)&in_properties[34].m_object = v12;
  v13 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
          vostok::render::g_allocator.m_object,
          52);
  v15 = (float *)v13;
  if ( v13 )
  {
    vostok::collision::object::object(v14, v13);
    *(_DWORD *)v15 = &vostok::collision::collision_object::`vftable';
    v15[12] = v12;
    *((_DWORD *)v15 + 9) = in_properties;
    *((_DWORD *)v15 + 10) = 1;
  }
  else
  {
    v15 = 0;
  }
  in_properties[35].m_object = (vostok::resources::unmanaged_resource *)v15;
  qmemcpy((void *)&new_transform, &in_properties[1], sizeof(new_transform));
  vostok::math::float4x4::set_scale(&new_transform, &sc);
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, vostok::resources::unmanaged_resource *, vostok::math::float4x4 *))in_properties[33].m_object->~vostok::resources::resource_base)(
    in_properties[33].m_object,
    in_properties[35].m_object,
    &new_transform);
  LODWORD(sc.z) = clear_value;
  v16 = clear_value;
  LODWORD(sc.x) = clear_value;
  LODWORD(sc.y) = clear_value;
  LODWORD(v21) = -1082130432;
  *(_QWORD *)((char *)&v21 + 4) = *(_QWORD *)&sc.x;
  v17 = v21;
  *(_QWORD *)&in_properties[26].m_object = 0xBF800000BF800000uLL;
  HIDWORD(v21) = v16;
  *(_QWORD *)&in_properties[28].m_object = v17;
  *(_QWORD *)&in_properties[30].m_object = *((_QWORD *)&v21 + 1);
  vostok::math::aabb::modify((vostok::math::aabb *)&new_transform, v18);
}
