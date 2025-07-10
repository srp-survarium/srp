void __thiscall survarium::object_sky_ambient_occlusion::insert(survarium::object_sky_ambient_occlusion *this)
{
  float m_width; // xmm0_4
  bool m_enabled; // cl
  float m_height; // xmm0_4
  float z; // eax
  float m_depth; // xmm0_4
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::scene_renderer *m_scene; // [esp-10h] [ebp-140h]
  vostok::render::sky_ambient_occlusion_properties properties; // [esp+4h] [ebp-12Ch] BYREF

  *(_QWORD *)&properties.location.x = *(_QWORD *)&this->m_transform.lines[3].x;
  m_width = (float)this->m_width;
  properties.texture_name.m_end = properties.texture_name.m_buffer;
  m_enabled = this->m_enabled;
  properties.width = m_width;
  m_height = (float)this->m_height;
  properties.texture_name.m_max_end = (char *)&properties.location;
  properties.texture_name.m_begin = properties.texture_name.m_buffer;
  z = this->m_transform.c.z;
  properties.height = m_height;
  m_depth = (float)this->m_depth;
  properties.enabled = m_enabled;
  properties.texture_name.m_buffer[0] = 0;
  properties.location.z = z;
  properties.depth = m_depth;
  properties.texture_invalidated = 1;
  vostok::fixed_string<260>::operator=(&properties.texture_name, &this->m_texture_name);
  m_game_scene = this->m_game_scene;
  m_scene = m_game_scene->m_game->m_renderer->m_scene;
  vostok::render::scene_renderer::update_sky_ambient_occlusion(
    m_scene,
    m_scene,
    &m_game_scene->m_render_scene,
    (const vostok::render::sky_ambient_occlusion_properties *)this->m_sky_ao_volume_id,
    &properties);
}
