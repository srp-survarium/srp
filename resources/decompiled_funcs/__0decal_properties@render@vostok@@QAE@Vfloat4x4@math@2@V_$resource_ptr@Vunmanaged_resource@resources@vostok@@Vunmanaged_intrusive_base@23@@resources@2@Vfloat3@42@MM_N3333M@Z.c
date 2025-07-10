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
