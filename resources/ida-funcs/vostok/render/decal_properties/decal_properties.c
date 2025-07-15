void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::render::decal_properties *__that,
        const vostok::render::decal_properties *__thata)
{
  qmemcpy(__that, __thata, 0x40u);
  __that->material.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that->material,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__thata->material);
  __that->width_height_far_distance = __thata->width_height_far_distance;
  __that->alpha_angle = __thata->alpha_angle;
  __that->clip_angle = __thata->clip_angle;
  __that->draw_priority = __thata->draw_priority;
  __that->projection_on_terrain_geometry = __thata->projection_on_terrain_geometry;
  __that->projection_on_static_geometry = __thata->projection_on_static_geometry;
  __that->projection_on_speedtree_geometry = __thata->projection_on_speedtree_geometry;
  __that->projection_on_skeleton_geometry = __thata->projection_on_skeleton_geometry;
  __that->projection_on_particle_geometry = __thata->projection_on_particle_geometry;
}


void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::math::float4x4 in_transform,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> in_material,
        vostok::math::float3 in_width_height_far_distance,
        float in_alpha_angle,
        float in_clip_angle,
        float in_projection_on_terrain_geometry,
        bool in_projection_on_static_geometry,
        bool in_projection_on_speedtree_geometry,
        bool in_projection_on_skeleton_geometry,
        bool in_projection_on_particle_geometry,
        float in_draw_priority,
        float in_draw_prioritya)
{
  float v13; // ecx
  bool v14; // dl
  bool v15; // al
  float v16; // xmm0_4
  bool v17; // dl
  char v18; // al
  const vostok::math::float4x4 *v19; // xmm0_4
  float x; // eax
  vostok::math::float3 scale; // [esp+Ch] [ebp-Ch] BYREF

  qmemcpy((void *)LODWORD(in_transform.i.x), &in_transform.lines[0].elements[1], 0x40u);
  *(_DWORD *)(LODWORD(in_transform.i.x) + 64) = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(in_transform.i.x) + 64),
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_width_height_far_distance);
  v13 = in_alpha_angle;
  v14 = in_projection_on_static_geometry;
  v15 = in_projection_on_speedtree_geometry;
  *(_QWORD *)(LODWORD(in_transform.i.x) + 68) = *(_QWORD *)&in_width_height_far_distance.elements[1];
  *(float *)(LODWORD(in_transform.i.x) + 80) = in_clip_angle;
  *(float *)(LODWORD(in_transform.i.x) + 84) = in_projection_on_terrain_geometry;
  v16 = in_draw_prioritya;
  *(float *)(LODWORD(in_transform.i.x) + 76) = v13;
  LOBYTE(v13) = in_projection_on_skeleton_geometry;
  *(_BYTE *)(LODWORD(in_transform.i.x) + 92) = v14;
  v17 = in_projection_on_particle_geometry;
  *(_BYTE *)(LODWORD(in_transform.i.x) + 93) = v15;
  v18 = LOBYTE(in_draw_priority);
  *(float *)(LODWORD(in_transform.i.x) + 88) = v16;
  v19 = clear_value;
  *(_BYTE *)(LODWORD(in_transform.i.x) + 94) = LOBYTE(v13);
  *(_BYTE *)(LODWORD(in_transform.i.x) + 95) = v17;
  *(_BYTE *)(LODWORD(in_transform.i.x) + 96) = v18;
  LODWORD(scale.x) = v19;
  LODWORD(scale.y) = v19;
  LODWORD(scale.z) = v19;
  vostok::math::float4x4::set_scale((vostok::math::float4x4 *)LODWORD(in_transform.i.x), &scale);
  x = in_width_height_far_distance.x;
  *(float *)(LODWORD(in_transform.i.x) + 68) = *(float *)(LODWORD(in_transform.i.x) + 68) * 0.5;
  *(float *)(LODWORD(in_transform.i.x) + 72) = *(float *)(LODWORD(in_transform.i.x) + 72) * 0.5;
  *(float *)(LODWORD(in_transform.i.x) + 76) = *(float *)(LODWORD(in_transform.i.x) + 76) * 0.5;
  if ( x != 0.0 && !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(x) + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(LODWORD(in_width_height_far_distance.x) + 208),
      (vostok::resources::unmanaged_resource *)LODWORD(in_width_height_far_distance.x));
}


void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::render::decal_properties *thisa)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  __int64 v3; // [esp+Ch] [ebp-4Ch]
  vostok::math::float4x4 v4; // [esp+18h] [ebp-40h] BYREF

  thisa->material.m_object = 0;
  qmemcpy(thisa, vostok::math::float4x4::identity(&v4), 0x40u);
  m_object = thisa->material.m_object;
  thisa->material.m_object = 0;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  *(float *)&v3 = FLOAT_0_5;
  *((float *)&v3 + 1) = FLOAT_0_5;
  *(_QWORD *)&thisa->width_height_far_distance.x = v3;
  thisa->width_height_far_distance.z = FLOAT_0_5;
  thisa->projection_on_terrain_geometry = 1;
  thisa->projection_on_static_geometry = 1;
  thisa->projection_on_speedtree_geometry = 1;
  thisa->projection_on_skeleton_geometry = 1;
  thisa->projection_on_particle_geometry = 1;
  thisa->alpha_angle = -1.0;
  thisa->clip_angle = -1.0;
}
