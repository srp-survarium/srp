void __thiscall survarium::object_environment_probe::load(
        survarium::object_environment_probe *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  const char *v11; // edx
  char *m_begin; // eax
  boost::function1<void,char const *> *v13; // ecx

  survarium::load_transform(t, &this->m_transform);
  this->m_cubemap_resolution = (unsigned int)vostok::configs::binary_config_value::operator[](t, "cubemap_resolution")->data.pointer;
  v5 = vostok::configs::binary_config_value::operator[](t, "radius");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  this->m_radius = pointer;
  v7 = vostok::configs::binary_config_value::operator[](t, "diffuse_multiplier");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  this->m_diffuse_multiplier = v8;
  v9 = vostok::configs::binary_config_value::operator[](t, "specular_multiplier");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  this->m_specular_multiplier = v10;
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  v11 = (const char *)vostok::configs::binary_config_value::operator[](t, "texture")->data.pointer;
  m_begin = this->m_texture_name.m_begin;
  if ( m_begin != v11 )
  {
    this->m_texture_name.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_texture_name, v11);
  }
  this->m_clip_by_normal = vostok::configs::binary_config_value::operator[](t, "clip_by_normal")->data.pointer != 0;
  this->m_with_shadows = vostok::configs::binary_config_value::operator[](t, "with_shadows")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "geometry") )
    this->m_geometry = (unsigned int)vostok::configs::binary_config_value::operator[](t, "geometry")->data.pointer;
  else
    this->m_geometry = 0;
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(v13, cb, (const char *)this);
}
