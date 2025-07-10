int __thiscall vostok::render::decal_instance::draw(
        vostok::render::decal_instance *this,
        vostok::render::decal_instance *context,
        vostok::render::renderer_context *opaque_geometry_mask_effect,
        vostok::resources::unmanaged_resource *stage_type,
        vostok::render::enum_render_stage_type stage_typea)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  char *z_low; // ecx
  float v10; // xmm3_4
  float v11; // xmm0_4
  vostok::math::float4x4 *v12; // ecx
  const vostok::math::float4x4 *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  vostok::render::decal_instance *v15; // ecx
  vostok::math::float3 *v17; // [esp+0h] [ebp-13Ch]
  vostok::math::float3 position; // [esp+14h] [ebp-128h] BYREF
  vostok::math::float3 angles; // [esp+20h] [ebp-11Ch] BYREF
  vostok::math::float3 scale; // [esp+2Ch] [ebp-110h]
  vostok::math::float4x4 geom_world_matrix; // [esp+38h] [ebp-104h] BYREF
  vostok::math::float4x4 left; // [esp+78h] [ebp-C4h] BYREF
  vostok::math::float4x4 result; // [esp+B8h] [ebp-84h] BYREF
  vostok::math::float4x4 v24; // [esp+F8h] [ebp-44h] BYREF

  m_object = context->m_properties.material.m_object;
  v6 = 0;
  if ( m_object )
  {
    this = (vostok::render::decal_instance *)&m_object->vostok::resources::unmanaged_intrusive_base;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    v7 = (int)&m_object[1];
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)this,
        m_object);
    v8 = v7;
    v6 = 0;
  }
  else
  {
    v8 = dword_4BB07F4;
  }
  if ( *(_BYTE *)(v8 + stage_typea + 724)
    && *(&vostok::render::decal_instance::get_effects(this, (int)context)[3].type + stage_typea)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && context->m_properties.material.m_object )
  {
    z_low = (char *)LODWORD(context->m_properties.width_height_far_distance.z);
    *(_QWORD *)&scale.x = *(_QWORD *)&context->m_properties.width_height_far_distance.x;
    *(_QWORD *)&angles.x = 0;
    LODWORD(scale.z) = z_low;
    LODWORD(angles.z) = clear_value;
    vostok::math::normalize_safe(
      (const vostok::math::float3_pod *)&context->m_properties.transform.lines[2],
      &position,
      &angles);
    v10 = context->m_properties.transform.c.x + (float)(scale.z * position.x);
    position.y = context->m_properties.transform.c.y + (float)(scale.z * position.y);
    v11 = context->m_properties.transform.c.z + (float)(scale.z * position.z);
    position.x = v10;
    position.z = v11;
    vostok::math::float4x4::get_angles_xyz(v12, v17);
    memset((int)&geom_world_matrix, 0, sizeof(geom_world_matrix));
    geom_world_matrix.j.y = scale.y;
    geom_world_matrix.i.x = scale.x;
    geom_world_matrix.k.z = scale.z;
    LODWORD(geom_world_matrix.c.w) = clear_value;
    v13 = vostok::math::create_rotation(&result, &angles);
    vostok::math::mul4x3(&left, &geom_world_matrix, v13);
    v14 = vostok::math::create_translation(&v24, &position);
    vostok::math::mul4x3(&geom_world_matrix, &left, v14);
    vostok::render::renderer_context::set_w(opaque_geometry_mask_effect, &geom_world_matrix);
    vostok::render::decal_instance::render(
      v15,
      *(float *)&context,
      *(float *)&stage_typea,
      context,
      opaque_geometry_mask_effect,
      stage_typea);
    v6 = 1;
  }
  if ( stage_type && !_InterlockedExchangeAdd(&stage_type->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &stage_type->vostok::resources::unmanaged_intrusive_base,
      stage_type);
  return v6;
}
