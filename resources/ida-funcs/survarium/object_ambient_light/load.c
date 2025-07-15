void __thiscall survarium::object_ambient_light::load(
        survarium::object_ambient_light *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  bool v13; // al
  vostok::configs::binary_config_value *v14; // ecx
  const void *v15; // eax
  vostok::configs::binary_config_value *v16; // ecx
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v19; // ecx

  survarium::load_transform(t, &this->m_transform);
  v5 = vostok::configs::binary_config_value::operator[](t, "radius");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  this->m_radius = pointer;
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  this->m_color = (unsigned int)vostok::configs::binary_config_value::operator[](t, "color")->data.pointer;
  v7 = vostok::configs::binary_config_value::operator[](t, "intensity");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  this->m_intensity = v8;
  v9 = vostok::configs::binary_config_value::operator[](t, "attenuation_power");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  this->m_attenuation_power = v10;
  this->m_dot_normal = vostok::configs::binary_config_value::operator[](t, "dot_normal")->data.pointer != 0;
  v13 = vostok::configs::binary_config_value::value_exists(v11, (int)t, (unsigned int)"affect_specular")
     && vostok::configs::binary_config_value::operator[](t, "affect_specular")->data.pointer != 0;
  this->m_affect_specular = v13;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)t, (unsigned int)"geometry") )
    v15 = vostok::configs::binary_config_value::operator[](t, "geometry")->data.pointer;
  else
    v15 = 0;
  this->m_geometry = (int)v15;
  if ( vostok::configs::binary_config_value::value_exists(v14, (int)t, (unsigned int)"side_width") )
  {
    v17 = vostok::configs::binary_config_value::operator[](t, "side_width");
    if ( v17->type == 2 )
      v18 = *(float *)&v17->data.pointer;
    else
      v18 = (float)(int)v17->data.pointer;
  }
  else
  {
    v18 = FLOAT_0_1;
  }
  this->m_side_width = v18;
  if ( vostok::configs::binary_config_value::value_exists(v16, (int)t, (unsigned int)"smart_attenuation") )
    this->m_smart_attenuation = vostok::configs::binary_config_value::operator[](t, "smart_attenuation")->data.pointer != 0;
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v19,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
