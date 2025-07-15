void __thiscall survarium::object_sky_ambient_occlusion::load(
        survarium::object_sky_ambient_occlusion *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const char *pointer; // edx
  char *m_begin; // eax
  vostok::fixed_string<260> *p_m_texture_name; // ecx

  survarium::load_transform(t, &this->m_transform);
  this->m_generated = 0;
  this->m_width = (int)vostok::configs::binary_config_value::operator[](t, "width")->data.pointer;
  this->m_height = (int)vostok::configs::binary_config_value::operator[](t, "height")->data.pointer;
  this->m_depth = (int)vostok::configs::binary_config_value::operator[](t, "depth")->data.pointer;
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  this->m_resolution_x = (int)vostok::configs::binary_config_value::operator[](t, "resolution_x")->data.pointer;
  this->m_resolution_y = (int)vostok::configs::binary_config_value::operator[](t, "resolution_y")->data.pointer;
  pointer = (const char *)vostok::configs::binary_config_value::operator[](t, "texture")->data.pointer;
  m_begin = this->m_texture_name.m_begin;
  p_m_texture_name = &this->m_texture_name;
  if ( m_begin != pointer )
  {
    this->m_texture_name.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(p_m_texture_name, pointer);
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)p_m_texture_name,
    cb,
    (const char *)this);
}
