void __thiscall survarium::object_volume_fog::load(
        survarium::object_volume_fog *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  survarium::object_volume_fog *v4; // esi
  vostok::configs::binary_config_value *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  vostok::math::float3 *p_m_color; // edi
  survarium::object_volume_fog_vtbl **pointer; // esi
  vostok::configs::binary_config_value *v9; // ecx
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  vostok::configs::binary_config_value *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  vostok::configs::binary_config_value *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // ecx
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  vostok::configs::binary_config_value *v21; // ecx
  const void *v22; // eax
  vostok::configs::binary_config_value *v23; // ecx
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  vostok::configs::binary_config_value *v26; // ecx
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4
  vostok::configs::binary_config_value *v29; // ecx
  const vostok::configs::binary_config_value *v30; // eax
  float v31; // xmm0_4
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v32; // ecx
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  vostok::configs::binary_config_value *v35; // [esp-4h] [ebp-14h]

  v4 = this;
  survarium::load_transform(t, &this->m_transform);
  if ( vostok::configs::binary_config_value::value_exists(v35, (int)t, (unsigned int)"color") )
  {
    v6 = vostok::configs::binary_config_value::operator[](t, "color");
    p_m_color = &v4->m_color;
    pointer = (survarium::object_volume_fog_vtbl **)v6->data.pointer;
    p_m_color->x = *(float *)v6->data.pointer;
    ++pointer;
    p_m_color = (vostok::math::float3 *)((char *)p_m_color + 4);
    LODWORD(p_m_color->x) = *pointer;
    LODWORD(p_m_color->y) = pointer[1];
    v4 = this;
  }
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)t, (unsigned int)"density") )
  {
    v10 = vostok::configs::binary_config_value::operator[](t, "density");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    v4->m_density = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)t, (unsigned int)"speed") )
  {
    v13 = vostok::configs::binary_config_value::operator[](t, "speed");
    if ( v13->type == 2 )
      v14 = *(float *)&v13->data.pointer;
    else
      v14 = (float)(int)v13->data.pointer;
    v4->m_speed = v14;
  }
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)t, (unsigned int)"noise_scale") )
  {
    v16 = vostok::configs::binary_config_value::operator[](t, "noise_scale");
    if ( v16->type == 2 )
      v17 = *(float *)&v16->data.pointer;
    else
      v17 = (float)(int)v16->data.pointer;
    v4->m_noise_scale = v17;
  }
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)t, (unsigned int)"wave_length") )
  {
    v19 = vostok::configs::binary_config_value::operator[](t, "wave_length");
    if ( v19->type == 2 )
      v20 = *(float *)&v19->data.pointer;
    else
      v20 = (float)(int)v19->data.pointer;
    v4->m_wave_length = v20;
  }
  if ( vostok::configs::binary_config_value::value_exists(v18, (int)t, (unsigned int)"direction") )
  {
    v22 = vostok::configs::binary_config_value::operator[](t, "direction")->data.pointer;
    v21 = *(vostok::configs::binary_config_value **)v22;
    v4->m_direction.x = *(float *)v22;
    v4->m_direction.y = *((float *)v22 + 1);
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)t, (unsigned int)"near_density") )
  {
    v24 = vostok::configs::binary_config_value::operator[](t, "near_density");
    if ( v24->type == 2 )
      v25 = *(float *)&v24->data.pointer;
    else
      v25 = (float)(int)v24->data.pointer;
    v4->m_near_density = v25;
  }
  if ( vostok::configs::binary_config_value::value_exists(v23, (int)t, (unsigned int)"transparency_multiplier") )
  {
    v27 = vostok::configs::binary_config_value::operator[](t, "transparency_multiplier");
    if ( v27->type == 2 )
      v28 = *(float *)&v27->data.pointer;
    else
      v28 = (float)(int)v27->data.pointer;
    v4->m_transparency_multiplier = v28;
  }
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)t, (unsigned int)"density_offset") )
  {
    v30 = vostok::configs::binary_config_value::operator[](t, "density_offset");
    if ( v30->type == 2 )
      v31 = *(float *)&v30->data.pointer;
    else
      v31 = (float)(int)v30->data.pointer;
    v4->m_density_offset = v31;
  }
  if ( vostok::configs::binary_config_value::value_exists(v29, (int)t, (unsigned int)"height_falloff_offset") )
  {
    v33 = vostok::configs::binary_config_value::operator[](t, "height_falloff_offset");
    if ( v33->type == 2 )
      v34 = *(float *)&v33->data.pointer;
    else
      v34 = (float)(int)v33->data.pointer;
    v4->m_height_falloff_offset = v34;
  }
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v32,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)v4);
}
