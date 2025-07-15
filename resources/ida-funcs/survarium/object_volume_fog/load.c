void __thiscall survarium::object_volume_fog::load(
        survarium::object_volume_fog *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  float *pointer; // eax
  const vostok::configs::binary_config_value *v6; // eax
  float v7; // xmm0_4
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  boost::function1<void,char const *> *v21; // ecx
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4

  survarium::load_transform(t, &this->m_transform);
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)&stru_9555EC) )
  {
    pointer = (float *)vostok::configs::binary_config_value::operator[](t, (char *)&stru_9555EC)->data.pointer;
    *(_QWORD *)&this->m_color.x = *(_QWORD *)pointer;
    this->m_color.z = pointer[2];
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "density") )
  {
    v6 = vostok::configs::binary_config_value::operator[](t, "density");
    if ( v6->type == 2 )
      v7 = *(float *)&v6->data.pointer;
    else
      v7 = (float)(int)v6->data.pointer;
    this->m_density = v7;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "speed") )
  {
    v8 = vostok::configs::binary_config_value::operator[](t, "speed");
    if ( v8->type == 2 )
      v9 = *(float *)&v8->data.pointer;
    else
      v9 = (float)(int)v8->data.pointer;
    this->m_speed = v9;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "noise_scale") )
  {
    v10 = vostok::configs::binary_config_value::operator[](t, "noise_scale");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->m_noise_scale = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "wave_length") )
  {
    v12 = vostok::configs::binary_config_value::operator[](t, "wave_length");
    if ( v12->type == 2 )
      v13 = *(float *)&v12->data.pointer;
    else
      v13 = (float)(int)v12->data.pointer;
    this->m_wave_length = v13;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)&stru_96A440.m_inverted_view.lines[2].elements[2]) )
  {
    v14 = (float *)vostok::configs::binary_config_value::operator[](
                     t,
                     (char *)&stru_96A440.m_inverted_view.lines[2].elements[2])->data.pointer;
    this->m_direction.x = *v14;
    this->m_direction.y = v14[1];
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "near_density") )
  {
    v15 = vostok::configs::binary_config_value::operator[](t, "near_density");
    if ( v15->type == 2 )
      v16 = *(float *)&v15->data.pointer;
    else
      v16 = (float)(int)v15->data.pointer;
    this->m_near_density = v16;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "transparency_multiplier") )
  {
    v17 = vostok::configs::binary_config_value::operator[](t, "transparency_multiplier");
    if ( v17->type == 2 )
      v18 = *(float *)&v17->data.pointer;
    else
      v18 = (float)(int)v17->data.pointer;
    this->m_transparency_multiplier = v18;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "density_offset") )
  {
    v19 = vostok::configs::binary_config_value::operator[](t, "density_offset");
    if ( v19->type == 2 )
      v20 = *(float *)&v19->data.pointer;
    else
      v20 = (float)(int)v19->data.pointer;
    this->m_density_offset = v20;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "height_falloff_offset") )
  {
    v22 = vostok::configs::binary_config_value::operator[](t, "height_falloff_offset");
    if ( v22->type == 2 )
      v23 = *(float *)&v22->data.pointer;
    else
      v23 = (float)(int)v22->data.pointer;
    this->m_height_falloff_offset = v23;
  }
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(v21, cb, (const char *)this);
}
