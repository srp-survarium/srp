void __thiscall survarium::object_decal::insert(survarium::object_decal *this)
{
  BOOL m_projection_on_particle_geometry; // eax
  double m_draw_priority; // st7
  BOOL m_projection_on_speedtree_geometry; // edx
  float m_decal_width; // xmm0_4
  float m_decal_height; // xmm1_4
  float m_decal_far_distance; // xmm2_4
  BOOL m_projection_on_skeleton_geometry; // ecx
  double m_clip_angle; // st7
  BOOL m_projection_on_static_geometry; // eax
  BOOL m_projection_on_terrain_geometry; // ecx
  double v12; // st7
  vostok::render::decal_properties *v13; // eax
  _BYTE v14[68]; // [esp-54h] [ebp-F0h] BYREF
  vostok::math::float3 v15; // [esp-10h] [ebp-ACh] BYREF
  float v16; // [esp-4h] [ebp-A0h]
  float in_clip_angle; // [esp+0h] [ebp-9Ch]
  bool in_projection_on_terrain_geometry[4]; // [esp+4h] [ebp-98h]
  BOOL v19; // [esp+8h] [ebp-94h]
  BOOL v20; // [esp+Ch] [ebp-90h]
  BOOL v21; // [esp+10h] [ebp-8Ch]
  BOOL v22; // [esp+14h] [ebp-88h]
  float v23; // [esp+18h] [ebp-84h]
  float v24; // [esp+1Ch] [ebp-80h]
  unsigned __int64 v25; // [esp+2Ch] [ebp-70h]
  float v26; // [esp+34h] [ebp-68h]
  vostok::render::decal_properties in_transform; // [esp+38h] [ebp-64h] BYREF

  m_projection_on_particle_geometry = this->m_projection_on_particle_geometry;
  m_draw_priority = this->m_draw_priority;
  m_projection_on_speedtree_geometry = this->m_projection_on_speedtree_geometry;
  m_decal_width = this->m_decal_width;
  m_decal_height = this->m_decal_height;
  m_decal_far_distance = this->m_decal_far_distance;
  v24 = *(float *)&this;
  m_projection_on_skeleton_geometry = this->m_projection_on_skeleton_geometry;
  v24 = m_draw_priority;
  m_clip_angle = this->m_clip_angle;
  LODWORD(v23) = m_projection_on_particle_geometry;
  m_projection_on_static_geometry = this->m_projection_on_static_geometry;
  v22 = m_projection_on_skeleton_geometry;
  m_projection_on_terrain_geometry = this->m_projection_on_terrain_geometry;
  v21 = m_projection_on_speedtree_geometry;
  v20 = m_projection_on_static_geometry;
  v19 = m_projection_on_terrain_geometry;
  v25 = __PAIR64__(LODWORD(m_decal_height), LODWORD(m_decal_width));
  *(float *)in_projection_on_terrain_geometry = m_clip_angle * 0.011111111;
  v12 = 0.011111111 * this->m_alpha_angle;
  v26 = m_decal_far_distance;
  in_clip_angle = v12;
  *(_QWORD *)&v15.elements[1] = __PAIR64__(LODWORD(m_decal_height), LODWORD(m_decal_width));
  v16 = m_decal_far_distance;
  v15.x = 0.0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_material);
  qmemcpy(&v14[4], &this->m_transform, 0x40u);
  *(_DWORD *)v14 = &in_transform;
  vostok::render::decal_properties::decal_properties(
    &in_transform,
    *(vostok::math::float4x4 *)v14,
    *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v14[64],
    v15,
    v16,
    in_clip_angle,
    *(float *)in_projection_on_terrain_geometry,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24);
  vostok::render::scene_renderer::update_decal(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    (const vostok::render::decal_properties *)this->m_decal_id,
    v13);
  if ( in_transform.material.m_object )
  {
    if ( !_InterlockedExchangeAdd(&in_transform.material.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &in_transform.material.m_object->vostok::resources::unmanaged_intrusive_base,
        in_transform.material.m_object);
  }
}
