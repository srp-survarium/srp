void __thiscall survarium::object_environment_probe::insert(survarium::object_environment_probe *this)
{
  __int64 v2; // xmm0_8
  vostok::math::float4x4 *p_m_transform; // ebx
  float z; // eax
  unsigned int m_cubemap_resolution; // eax
  bool m_clip_by_normal; // cl
  bool m_with_shadows; // dl
  unsigned int m_geometry; // eax
  const vostok::render::environment_probe_properties *m_probe_id; // edx
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::scene_renderer *m_scene; // [esp-10h] [ebp-198h]
  vostok::render::environment_probe_properties properties; // [esp+10h] [ebp-178h] BYREF

  v2 = *(_QWORD *)&this->m_transform.lines[3].x;
  properties.texture_name.m_end = properties.texture_name.m_buffer;
  p_m_transform = &this->m_transform;
  properties.texture_name.m_begin = properties.texture_name.m_buffer;
  z = this->m_transform.c.z;
  properties.texture_name.m_max_end = (char *)&properties.transform;
  properties.texture_name.m_buffer[0] = 0;
  qmemcpy((void *)&properties.transform, &this->m_transform, sizeof(properties.transform));
  *(_QWORD *)&properties.location.x = v2;
  *(float *)&v2 = this->m_radius;
  properties.location.z = z;
  LODWORD(properties.radius) = v2;
  vostok::fixed_string<260>::operator=(&properties.texture_name, &this->m_texture_name);
  m_cubemap_resolution = this->m_cubemap_resolution;
  m_clip_by_normal = this->m_clip_by_normal;
  *(float *)&v2 = this->m_diffuse_multiplier;
  properties.enabled = this->m_enabled;
  m_with_shadows = this->m_with_shadows;
  properties.cubemap_resolution = m_cubemap_resolution;
  m_geometry = this->m_geometry;
  properties.clip_by_normal = m_clip_by_normal;
  LODWORD(properties.diffuse_multiplier) = v2;
  *(float *)&v2 = this->m_specular_multiplier;
  properties.with_shadows = m_with_shadows;
  m_probe_id = (const vostok::render::environment_probe_properties *)this->m_probe_id;
  properties.geometry = m_geometry;
  m_game_scene = this->m_game_scene;
  LODWORD(properties.specular_multiplier) = v2;
  properties.texture_invalidated = 1;
  properties.preview_mip = 0;
  qmemcpy((void *)&properties.transform, p_m_transform, sizeof(properties.transform));
  m_scene = m_game_scene->m_game->m_renderer->m_scene;
  vostok::render::scene_renderer::update_environment_probe(
    m_scene,
    m_scene,
    &m_game_scene->m_render_scene,
    m_probe_id,
    &properties);
}
