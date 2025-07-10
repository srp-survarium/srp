void __thiscall survarium::object_volume_fog::insert(survarium::object_volume_fog *this)
{
  __int64 v2; // xmm0_8
  float z; // ecx
  vostok::math::float2 *v4; // eax
  float x; // ecx
  float y; // edx
  survarium::base_game_scene *m_game_scene; // eax
  unsigned int m_volume_fog_id; // edx
  survarium::game *m_game; // edx
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // ecx
  vostok::render::game::renderer *m_renderer; // eax
  vostok::render::scene_renderer *m_scene; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v13; // [esp-Ch] [ebp-A4h]
  const vostok::render::volume_fog_parameters *v14; // [esp-8h] [ebp-A0h]
  vostok::math::float2_pod result_in_case_of_zero; // [esp+10h] [ebp-88h] BYREF
  vostok::render::volume_fog_parameters v; // [esp+18h] [ebp-80h] BYREF
  vostok::math::float2 v17; // [esp+90h] [ebp-8h] BYREF

  vostok::render::volume_fog_parameters::volume_fog_parameters((vostok::render::volume_fog_parameters *)this, &v);
  v2 = *(_QWORD *)&this->m_color.x;
  qmemcpy(&v, &this->m_transform, 0x40u);
  z = this->m_color.z;
  *(_QWORD *)&v.fog_color.x = v2;
  v.density = this->m_density;
  v.speed = this->m_speed;
  v.fog_color.z = z;
  result_in_case_of_zero = 0;
  v4 = vostok::math::normalize_safe(&this->m_direction, &v17, (vostok::math::float2 *)&result_in_case_of_zero);
  x = v4->x;
  y = v4->y;
  *(float *)&v2 = this->m_noise_scale;
  m_game_scene = this->m_game_scene;
  v.direction = (vostok::math::float2)__PAIR64__(LODWORD(y), LODWORD(x));
  LODWORD(v.noise_scale) = v2;
  m_volume_fog_id = this->m_volume_fog_id;
  v.wave_length = this->m_wave_length;
  v14 = (const vostok::render::volume_fog_parameters *)m_volume_fog_id;
  m_game = m_game_scene->m_game;
  v.near_density = this->m_near_density;
  p_m_render_scene = &m_game_scene->m_render_scene;
  m_renderer = m_game->m_renderer;
  v.transparency_multiplier = this->m_transparency_multiplier;
  v13 = p_m_render_scene;
  m_scene = m_renderer->m_scene;
  v.density_offset = this->m_density_offset;
  v.height_falloff_offset = this->m_height_falloff_offset;
  vostok::render::scene_renderer::update_volume_fog(m_scene, m_scene, v13, v14, &v);
}
