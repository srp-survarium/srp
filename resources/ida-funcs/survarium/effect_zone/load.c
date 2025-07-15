void __thiscall survarium::effect_zone::load(
        survarium::effect_zone *this,
        const vostok::configs::binary_config_value *cfg_val)
{
  vostok::math::float4x4 *v3; // eax
  vostok::math::float4x4 *v4; // eax
  const vostok::math::float3 *v5; // [esp+Ch] [ebp-14Ch]
  vostok::math::float4x4 *rotation; // [esp+Ch] [ebp-14Ch]
  const vostok::math::float3 *pointer; // [esp+10h] [ebp-148h]
  const vostok::math::float3 **v8; // [esp+14h] [ebp-144h]
  vostok::math::float4x4 v9; // [esp+18h] [ebp-140h] BYREF
  vostok::math::float4x4 v10; // [esp+58h] [ebp-100h] BYREF
  _BYTE v11[64]; // [esp+98h] [ebp-C0h] BYREF
  vostok::math::float4x4 v12; // [esp+D8h] [ebp-80h] BYREF
  vostok::math::float4x4 v13; // [esp+118h] [ebp-40h] BYREF

  survarium::effect_zone_core::load((survarium::effect_zone_core *)this, cfg_val);
  pointer = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](cfg_val, "scale")->data.pointer;
  v5 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](cfg_val, "rotation")->data.pointer;
  v8 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](cfg_val, "position");
  rotation = vostok::math::create_rotation(v5, (int)"position", (int)v11);
  v3 = vostok::math::create_scale(pointer, &v12);
  vostok::math::mul4x3(rotation, v3, &v9);
  v4 = vostok::math::create_translation(*v8, &v13);
  vostok::math::mul4x3(v4, &v9, &v10);
  qmemcpy(&this->m_memory_usage_self.size, &v10, 0x40u);
}
