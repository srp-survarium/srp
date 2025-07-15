void __thiscall survarium::object_sky_ambient_occlusion::insert(survarium::object_sky_ambient_occlusion *this)
{
  float m_width; // xmm0_4
  bool m_enabled; // al
  float m_height; // xmm0_4
  vostok::fixed_string<260> *p_m_texture_name; // ecx
  vostok::render::base_scene v6; // [esp+8h] [ebp-B4h] BYREF
  float z; // [esp+120h] [ebp+64h]
  float v8; // [esp+124h] [ebp+68h]
  float v9; // [esp+128h] [ebp+6Ch]
  float m_depth; // [esp+12Ch] [ebp+70h]
  bool v11; // [esp+130h] [ebp+74h]
  char v12; // [esp+131h] [ebp+75h]

  m_width = (float)this->m_width;
  v6.__vftable = (vostok::render::base_scene_vtbl *)(&v6.vostok::resources::resource_flags + 1);
  v6.type = (unsigned int)(&v6.vostok::resources::resource_flags + 1);
  v6.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = (volatile int)&v6.next_scene;
  m_enabled = this->m_enabled;
  *((_BYTE *)&v6.vostok::resources::resource_flags + 12) = 0;
  *(_QWORD *)&v6.next_scene.m_object = *(_QWORD *)&this->m_transform.lines[3].x;
  z = this->m_transform.c.z;
  v8 = m_width;
  m_height = (float)this->m_height;
  v11 = m_enabled;
  p_m_texture_name = &this->m_texture_name;
  v9 = m_height;
  m_depth = (float)this->m_depth;
  v12 = 1;
  if ( &v6 != (vostok::render::base_scene *)p_m_texture_name )
    vostok::buffer_string::operator=(p_m_texture_name, (vostok::buffer_string *)&v6);
  vostok::render::scene_renderer::update_sky_ambient_occlusion(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (const vostok::render::sky_ambient_occlusion_properties *)this->m_sky_ao_volume_id,
    &v6);
}
