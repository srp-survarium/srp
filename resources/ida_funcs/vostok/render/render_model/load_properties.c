void __thiscall vostok::render::render_model::load_properties(
        vostok::render::render_model *this,
        vostok::configs::binary_config_value *properties)
{
  vostok::configs::binary_config_value *v2; // esi
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  __int64 v6; // xmm0_8
  float v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax
  unsigned __int16 v12; // ax
  vostok::configs::binary_config_value *v13; // esi
  vostok::render::model_locator_item *v14; // edi
  const vostok::math::float3 *pointer; // esi
  const vostok::math::float4x4 *v16; // eax
  const char *name; // [esp+10h] [ebp-C8h]
  const char *namea; // [esp+10h] [ebp-C8h]
  const vostok::math::float4x4 *nameb; // [esp+10h] [ebp-C8h]
  int i; // [esp+14h] [ebp-C4h]
  vostok::math::float4x4 v21; // [esp+18h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+58h] [ebp-80h] BYREF
  vostok::math::float4x4 v23; // [esp+98h] [ebp-40h] BYREF

  v2 = properties;
  v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 properties,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v5 = vostok::configs::binary_config_value::operator[](v4, (const char *)&stru_962594.m_v_shaders._M_t._M_node_count);
  v6 = *(_QWORD *)v5->data.pointer;
  v7 = *((float *)v5->data.pointer + 2);
  *(_QWORD *)&this->m_aabbox.max.x = v6;
  this->m_aabbox.max.z = v7;
  v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 properties,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v9 = vostok::configs::binary_config_value::operator[](v8, (const char *)&stru_962594.m_v_shaders._M_t._M_key_compare);
  v10 = *(_QWORD *)v9->data.pointer;
  v11 = *((float *)v9->data.pointer + 2);
  *(_QWORD *)&this->m_aabbox.min.x = v10;
  this->m_aabbox.min.z = v11;
  if ( vostok::configs::binary_config_value::value_exists(
         properties,
         (const char *)&stru_962594.m_g_shaders._M_t._M_header._M_data._M_color) )
  {
    v12 = (__int16)(24
                  * vostok::configs::binary_config_value::operator[](
                      properties,
                      (const char *)&stru_962594.m_g_shaders._M_t._M_header._M_data._M_color)->count)
        / 24;
  }
  else
  {
    v12 = 0;
  }
  this->m_locators_count = v12;
  if ( v12 )
  {
    this->m_locators = (vostok::render::model_locator_item *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                               100 * v12);
    i = 0;
    if ( this->m_locators_count )
    {
      while ( 1 )
      {
        v13 = (vostok::configs::binary_config_value *)((char *)vostok::configs::binary_config_value::operator[](
                                                                 v2,
                                                                 (const char *)&stru_962594.m_g_shaders._M_t._M_header._M_data._M_color)->data.pointer
                                                     + 24 * (unsigned __int16)i);
        v14 = &this->m_locators[(unsigned __int16)i];
        name = (const char *)vostok::configs::binary_config_value::operator[](v13, "name")->data.pointer;
        v14->m_bone = (unsigned __int16)vostok::configs::binary_config_value::operator[](
                                          v13,
                                          (const char *)&stru_962594.m_g_shaders._M_t._M_header._M_data._M_right)->data.pointer;
        vostok::strings::copy<32>((char (*)[32])v14, name);
        namea = (const char *)vostok::configs::binary_config_value::operator[](v13, "position")->data.pointer;
        pointer = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](v13, "rotation")->data.pointer;
        nameb = vostok::math::create_translation(&result, (const vostok::math::float3 *)namea);
        v16 = vostok::math::create_rotation(&v23, pointer);
        vostok::math::mul4x3(&v21, v16, nameb);
        qmemcpy((void *)&v14->m_offset, &v21, sizeof(v14->m_offset));
        if ( (unsigned __int16)++i >= this->m_locators_count )
          break;
        v2 = properties;
      }
    }
  }
}
