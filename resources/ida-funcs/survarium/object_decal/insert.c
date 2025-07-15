void __thiscall survarium::object_decal::insert(survarium::object_decal *this)
{
  float m_clip_angle; // xmm1_4
  float m_draw_priority; // xmm0_4
  bool m_projection_on_terrain_geometry; // al
  bool m_projection_on_static_geometry; // [esp+4h] [ebp-8Ch]
  bool m_projection_on_skeleton_geometry; // [esp+8h] [ebp-88h]
  bool v7; // [esp+Ch] [ebp-84h]
  bool m_projection_on_particle_geometry; // [esp+10h] [ebp-80h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> other; // [esp+14h] [ebp-7Ch] BYREF
  vostok::math::float3 scale; // [esp+18h] [ebp-78h] BYREF
  float v11; // [esp+24h] [ebp-6Ch]
  float v12; // [esp+28h] [ebp-68h]
  float v13; // [esp+2Ch] [ebp-64h]
  vostok::render::decal_properties v14; // [esp+30h] [ebp-60h] BYREF

  m_clip_angle = this->m_clip_angle;
  *(_QWORD *)&scale.x = *(_QWORD *)&this->m_decal_width;
  scale.z = this->m_decal_far_distance;
  v12 = m_clip_angle * 0.011111111;
  v13 = this->m_alpha_angle * 0.011111111;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &other,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_material);
  m_draw_priority = this->m_draw_priority;
  m_projection_on_particle_geometry = this->m_projection_on_particle_geometry;
  m_projection_on_skeleton_geometry = this->m_projection_on_skeleton_geometry;
  m_projection_on_static_geometry = this->m_projection_on_static_geometry;
  m_projection_on_terrain_geometry = this->m_projection_on_terrain_geometry;
  qmemcpy(&v14, &this->m_transform, 0x40u);
  v11 = m_draw_priority;
  v7 = m_projection_on_terrain_geometry;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v14.material,
    &other);
  v14.width_height_far_distance = scale;
  v14.projection_on_terrain_geometry = v7;
  v14.projection_on_static_geometry = m_projection_on_static_geometry;
  v14.alpha_angle = v13;
  v14.projection_on_skeleton_geometry = m_projection_on_skeleton_geometry;
  v14.clip_angle = v12;
  v14.projection_on_particle_geometry = m_projection_on_particle_geometry;
  v14.draw_priority = v11;
  scale.x = s_bm_current_air_resistance;
  scale.y = s_bm_current_air_resistance;
  scale.z = s_bm_current_air_resistance;
  vostok::math::float4x4::set_scale(&v14.transform, &scale);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other);
  vostok::render::scene_renderer::update_decal(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (const vostok::render::decal_properties *)this->m_decal_id,
    &v14);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14.material);
}
