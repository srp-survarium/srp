void __thiscall survarium::game_world::add_decal(
        survarium::game_world *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *decal,
        const vostok::render::decal_properties *id,
        float size,
        float depth,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal,
        bool is_front_face)
{
  char v9; // bl
  float z; // xmm5_4
  float v11; // xmm6_4
  float y; // xmm7_4
  float v13; // xmm4_4
  float x; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  vostok::resources::unmanaged_resource *v18; // esi
  vostok::resources::unmanaged_resource *m_object; // eax
  int v20; // eax
  vostok::render::scene_renderer *v21; // ecx
  vostok::resources::unmanaged_resource *v22; // eax
  vostok::resources::unmanaged_intrusive_base *v23; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+14h] [ebp-D0h] BYREF
  vostok::math::float3 v25; // [esp+18h] [ebp-CCh] BYREF
  vostok::resources::unmanaged_resource *resource; // [esp+24h] [ebp-C0h] BYREF
  float v27; // [esp+28h] [ebp-BCh]
  vostok::math::float3 scale; // [esp+2Ch] [ebp-B8h] BYREF
  survarium::game_world *v29; // [esp+38h] [ebp-ACh]
  vostok::render::decal_properties properties; // [esp+3Ch] [ebp-A8h] BYREF
  vostok::math::float4x4 transform; // [esp+A4h] [ebp-40h] BYREF

  v9 = 0;
  v29 = this;
  v27 = 0.0;
  vostok::render::decal_properties::decal_properties((vostok::render::decal_properties *)this, &properties);
  z = normal->z;
  v11 = direction->z;
  y = normal->y;
  v13 = direction->y;
  x = direction->x;
  v15 = (float)(z * v13) - (float)(y * v11);
  resource = (vostok::resources::unmanaged_resource *)LODWORD(normal->x);
  v25.z = (float)(x * y) - (float)(*(float *)&resource * v13);
  v25.y = (float)(*(float *)&resource * v11) - (float)(x * z);
  *(float *)&v24.m_object = 1.0 / sqrtf((float)((float)(v25.z * v25.z) + (float)(v15 * v15)) + (float)(v25.y * v25.y));
  v25.x = *(float *)&v24.m_object * v15;
  v25.y = *(float *)&v24.m_object * v25.y;
  v25.z = v25.z * *(float *)&v24.m_object;
  scale.x = -*(float *)&resource;
  v24.m_object = (vostok::configs::binary_config *)LODWORD(normal->elements[1]);
  LODWORD(scale.y) = (unsigned int)v24.m_object ^ 0x80000000;
  v27 = normal->z;
  scale.z = -v27;
  vostok::math::create_rotation(&scale, &v25, &transform);
  v16 = position->x + (float)((float)(*(float *)&resource * depth) * 0.5);
  v25.y = position->y + (float)((float)(*(float *)&v24.m_object * depth) * 0.5);
  v25.z = position->z + (float)((float)(v27 * depth) * 0.5);
  v25.x = v16;
  *(_QWORD *)&transform.lines[3].x = *(_QWORD *)&v25.x;
  transform.c.z = v25.z;
  if ( is_front_face )
  {
    v18 = resource;
  }
  else
  {
    v18 = 0;
    v9 = 1;
    *(float *)&resource = 0.0;
    decal = (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&resource;
  }
  *(float *)&v24.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v24,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)decal);
  m_object = properties.material.m_object;
  properties.material.m_object = v24.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  if ( (v9 & 1) != 0 && v18 && !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v18->vostok::resources::unmanaged_intrusive_base, v18);
  qmemcpy(&properties, &transform, 0x40u);
  LODWORD(scale.x) = clear_value;
  LODWORD(scale.y) = clear_value;
  LODWORD(scale.z) = clear_value;
  vostok::math::float4x4::set_scale(&properties.transform, &scale);
  v25.z = (float)(depth * 2.0) * 0.5;
  properties.width_height_far_distance.z = v25.z;
  v20 = *(_DWORD *)(v29[-1].m_input_mode + 148);
  v25.x = size * 0.5;
  v25.y = size * 0.5;
  v21 = *(vostok::render::scene_renderer **)(v20 + 16);
  *(_QWORD *)&properties.width_height_far_distance.x = *(_QWORD *)&v25.x;
  properties.projection_on_static_geometry = 1;
  properties.projection_on_skeleton_geometry = 1;
  properties.projection_on_terrain_geometry = 1;
  properties.projection_on_speedtree_geometry = 1;
  properties.projection_on_particle_geometry = 1;
  properties.alpha_angle = -1.0;
  properties.clip_angle = -1.0;
  vostok::render::scene_renderer::update_decal(
    v21,
    v21,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&v29[-1].m_enemies_for_team_1._M_impl._M_finish,
    id,
    &properties);
  v22 = properties.material.m_object;
  if ( properties.material.m_object )
  {
    v23 = &properties.material.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&properties.material.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v23, v22);
  }
}
