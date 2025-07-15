void __thiscall survarium::object_ambient_light::insert(survarium::object_ambient_light *this)
{
  bool m_enabled; // al
  float m_radius; // xmm0_4
  double x; // xmm0_8
  double y; // xmm0_8
  double z; // xmm0_8
  float m_intensity; // xmm1_4
  float m_attenuation_power; // xmm0_4
  int m_geometry; // eax
  float m_side_width; // xmm0_4
  survarium::base_game_scene *m_game_scene; // eax
  long double v12; // [esp+0h] [ebp-90h]
  long double v13; // [esp+0h] [ebp-90h]
  long double v14; // [esp+0h] [ebp-90h]
  long double v15; // [esp+8h] [ebp-88h] BYREF
  __int64 v16; // [esp+10h] [ebp-80h]
  int v17; // [esp+18h] [ebp-78h]
  float a; // [esp+1Ch] [ebp-74h] BYREF
  vostok::render::ambient_light_properties v19; // [esp+20h] [ebp-70h] BYREF

  m_enabled = this->m_enabled;
  m_radius = this->m_radius;
  *(_QWORD *)&v19.location.x = *(_QWORD *)&this->m_transform.lines[3].x;
  v19.location.z = this->m_transform.c.z;
  v19.enabled = m_enabled;
  HIDWORD(v15) = this->m_color;
  v19.radius = m_radius;
  vostok::math::color::get_RGBA(
    (vostok::math::color *)this,
    (unsigned __int8 *)&v15 + 4,
    &v19.color.x,
    &v19.color.y,
    &v19.color.z,
    &a);
  x = v19.color.x;
  __libm_sse2_pow(v12, v15);
  *(float *)&x = x;
  LODWORD(v16) = LODWORD(x);
  y = v19.color.y;
  __libm_sse2_pow(v13, v15);
  *(float *)&y = y;
  HIDWORD(v16) = LODWORD(y);
  z = v19.color.z;
  __libm_sse2_pow(v14, v15);
  m_intensity = this->m_intensity;
  *(float *)&z = z;
  v17 = LODWORD(z);
  *(_QWORD *)&v19.color.x = v16;
  v19.color.z = *(float *)&z;
  if ( m_intensity >= 0.0 )
    v19.intensity = m_intensity;
  else
    v19.intensity = 0.0;
  m_attenuation_power = this->m_attenuation_power;
  v19.dot_normal = this->m_dot_normal;
  v19.smart_attenuation = this->m_smart_attenuation;
  v19.affect_specular = this->m_affect_specular;
  m_geometry = this->m_geometry;
  v19.attenuation_power = m_attenuation_power;
  m_side_width = this->m_side_width;
  v19.geometry = m_geometry;
  m_game_scene = this->m_game_scene;
  v19.side_width = m_side_width;
  qmemcpy(&v19, &this->m_transform, 0x40u);
  vostok::render::scene_renderer::update_ambient_light(
    (vostok::render::scene_renderer *)&m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_game_scene->m_render_scene,
    (const vostok::render::ambient_light_properties *)this->m_ambient_light_id,
    &v19);
}
