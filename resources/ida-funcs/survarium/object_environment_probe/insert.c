void __thiscall survarium::object_environment_probe::insert(survarium::object_environment_probe *this)
{
  float m_outer_radius; // xmm0_4
  vostok::fixed_string<260> *p_m_texture_name; // ecx
  bool m_enabled; // al
  float m_diffuse_multiplier; // xmm0_4
  unsigned int m_cubemap_resolution_index; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  float m_probe_side_width; // xmm0_4
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_scene; // eax
  int v12; // [esp-4h] [ebp-284h]
  volatile int *v13; // [esp+0h] [ebp-280h]
  vostok::math::float3 scale; // [esp+Ch] [ebp-274h] BYREF
  vostok::render::environment_probe_properties v15; // [esp+18h] [ebp-268h] BYREF
  vostok::math::float4x4 v16; // [esp+240h] [ebp-40h] BYREF

  v15.cooked_render_texture_specular.m_object = 0;
  v15.cooked_render_texture_diffuse.m_object = 0;
  m_outer_radius = this->m_outer_radius;
  v15.texture_name.m_begin = v15.texture_name.m_buffer;
  v15.texture_name.m_end = v15.texture_name.m_buffer;
  v15.texture_name.m_max_end = (char *)&v15.transform;
  v15.texture_name.m_buffer[0] = 0;
  qmemcpy(&v15.transform, &this->m_transform, sizeof(v15.transform));
  *(_QWORD *)&v15.location.x = *(_QWORD *)&this->m_transform.lines[3].x;
  v15.location.z = this->m_transform.c.z;
  p_m_texture_name = &this->m_texture_name;
  v15.outer_radius = m_outer_radius;
  v15.inner_radius = m_outer_radius - this->m_probe_side_width;
  if ( &v15.texture_name != &this->m_texture_name )
    vostok::buffer_string::operator=(p_m_texture_name, &v15.texture_name);
  m_enabled = this->m_enabled;
  m_diffuse_multiplier = this->m_diffuse_multiplier;
  v15.preview_mip = 0;
  v15.enabled = m_enabled;
  m_cubemap_resolution_index = this->m_cubemap_resolution_index;
  v15.diffuse_multiplier = m_diffuse_multiplier;
  v15.specular_multiplier = this->m_specular_multiplier;
  v15.texture_invalidated = 1;
  if ( !m_cubemap_resolution_index )
  {
    v12 = 32;
    goto LABEL_12;
  }
  v7 = m_cubemap_resolution_index - 1;
  if ( !v7 )
  {
    v12 = 64;
LABEL_12:
    v9 = v12;
    goto LABEL_13;
  }
  v8 = v7 - 1;
  if ( v8 )
  {
    if ( v8 == 1 )
      v9 = 256;
    else
      v9 = 512;
  }
  else
  {
    v9 = 128;
  }
LABEL_13:
  v15.cubemap_resolution = v9;
  v15.geometry = this->m_geometry;
  qmemcpy(&v15.transform, &this->m_transform, sizeof(v15.transform));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_cooked_render_texture_specular,
    &v15.cooked_render_texture_specular);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_cooked_render_texture_diffuse,
    &v15.cooked_render_texture_diffuse);
  v15.smart_attenuation = this->m_smart_attenuation;
  qmemcpy(v15.face_average_colors, this->m_face_average_colors, sizeof(v15.face_average_colors));
  vostok::math::float4x4::get_scale(&this->m_transform, &scale);
  m_probe_side_width = this->m_probe_side_width;
  scale.y = scale.y - m_probe_side_width;
  qmemcpy(&v16, &this->m_transform, sizeof(v16));
  scale.x = scale.x - m_probe_side_width;
  scale.z = scale.z - m_probe_side_width;
  vostok::math::float4x4::set_scale(&v16, &scale);
  m_game_scene = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_scene;
  qmemcpy(&v15.inner_box_transform, &v16, sizeof(v15.inner_box_transform));
  vostok::render::scene_renderer::update_environment_probe(
    m_game_scene + 1,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_scene[40].m_object->m_fat_it.m_type),
    this->m_probe_id,
    &v15,
    v13);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15.cooked_render_texture_diffuse);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
}
