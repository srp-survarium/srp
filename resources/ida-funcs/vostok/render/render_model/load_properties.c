void __thiscall vostok::render::render_model::load_properties(
        vostok::render::render_model *this,
        const vostok::configs::binary_config_value *properties)
{
  vostok::configs::binary_config_value *v3; // eax
  float **v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  float **v6; // eax
  vostok::configs::binary_config_value *v7; // ecx
  unsigned __int16 v8; // ax
  vostok::memory::doug_lea_allocator *v9; // esi
  char *v10; // eax
  unsigned __int16 v11; // ax
  vostok::configs::binary_config_value *v12; // esi
  const vostok::math::float3 *v13; // esi
  vostok::math::float4x4 *v14; // edi
  vostok::math::float4x4 *rotation; // eax
  const char *v16; // [esp+0h] [ebp-E8h]
  const char *v17; // [esp+4h] [ebp-E4h]
  unsigned int v18; // [esp+8h] [ebp-E0h]
  int v19; // [esp+10h] [ebp-D8h]
  char *pointer; // [esp+14h] [ebp-D4h]
  const vostok::math::float3 *v21; // [esp+14h] [ebp-D4h]
  vostok::render::model_locator_item *v22; // [esp+18h] [ebp-D0h]
  float v23; // [esp+20h] [ebp-C8h]
  float v24; // [esp+20h] [ebp-C8h]
  float v25; // [esp+24h] [ebp-C4h]
  float v26; // [esp+24h] [ebp-C4h]
  vostok::math::float4x4 v27; // [esp+28h] [ebp-C0h] BYREF
  vostok::math::float4x4 v28; // [esp+68h] [ebp-80h] BYREF
  _BYTE v29[64]; // [esp+A8h] [ebp-40h] BYREF

  v3 = vostok::configs::binary_config_value::operator[](properties, "bounding_box");
  v4 = (float **)vostok::configs::binary_config_value::operator[](v3, "max");
  v23 = (*v4)[1];
  v25 = (*v4)[2];
  this->m_aabbox.max.x = **v4;
  this->m_aabbox.max.y = v23;
  this->m_aabbox.max.z = v25;
  v5 = vostok::configs::binary_config_value::operator[](properties, "bounding_box");
  v6 = (float **)vostok::configs::binary_config_value::operator[](v5, "min");
  v24 = (*v6)[1];
  v26 = (*v6)[2];
  this->m_aabbox.min.x = **v6;
  this->m_aabbox.min.y = v24;
  this->m_aabbox.min.z = v26;
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)properties, (unsigned int)"locators") )
    v8 = 24 * vostok::configs::binary_config_value::operator[](properties, "locators")->count / 24;
  else
    v8 = 0;
  this->m_locators_count = v8;
  if ( v8 )
  {
    v9 = vostok::render::g_allocator;
    v10 = type_info::raw_name(&vostok::render::model_locator_item `RTTI Type Descriptor');
    v19 = 0;
    this->m_locators = (vostok::render::model_locator_item *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                               (vostok::memory::doug_lea_allocator *)(100 * this->m_locators_count),
                                                               (int)v9,
                                                               100 * this->m_locators_count,
                                                               v10,
                                                               v16,
                                                               v17,
                                                               v18);
    v11 = 0;
    while ( v11 < this->m_locators_count )
    {
      v12 = (vostok::configs::binary_config_value *)((char *)vostok::configs::binary_config_value::operator[](
                                                               properties,
                                                               "locators")->data.pointer
                                                   + 24 * (unsigned __int16)v19);
      v22 = &this->m_locators[(unsigned __int16)v19];
      pointer = (char *)vostok::configs::binary_config_value::operator[](v12, "name")->data.pointer;
      v22->m_bone = (unsigned __int16)vostok::configs::binary_config_value::operator[](v12, "bone_idx")->data.pointer;
      vostok::strings::copy<32>((char (*)[32])v22, pointer);
      v21 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](v12, "position")->data.pointer;
      v13 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](v12, "rotation")->data.pointer;
      v14 = vostok::math::create_translation(v21, &v28);
      rotation = vostok::math::create_rotation(v13, (int)v14, (int)v29);
      vostok::math::mul4x3(v14, rotation, &v27);
      v11 = ++v19;
      qmemcpy(&v22->m_offset, &v27, sizeof(v22->m_offset));
    }
  }
}
