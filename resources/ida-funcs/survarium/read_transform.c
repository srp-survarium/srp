void __cdecl survarium::read_transform(const vostok::configs::binary_config_value *cfg, vostok::math::float4x4 *result)
{
  const vostok::math::float3 *pointer; // esi
  const vostok::math::float3 *v3; // ebx
  vostok::math::float4x4 *rotation; // ebx
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 v7; // [esp+Ch] [ebp-144h] BYREF
  vostok::math::float4x4 v8; // [esp+4Ch] [ebp-104h] BYREF
  _BYTE v9[64]; // [esp+8Ch] [ebp-C4h] BYREF
  vostok::math::float4x4 v10; // [esp+CCh] [ebp-84h] BYREF
  vostok::math::float4x4 v11; // [esp+10Ch] [ebp-44h] BYREF
  const vostok::math::float3 **v12; // [esp+14Ch] [ebp-4h]

  pointer = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](cfg, "scale")->data.pointer;
  v3 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](cfg, "rotation")->data.pointer;
  v12 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](cfg, "position");
  rotation = vostok::math::create_rotation(v3, (int)"position", (int)v9);
  v5 = vostok::math::create_scale(pointer, &v8);
  vostok::math::mul4x3(rotation, v5, &v10);
  v6 = vostok::math::create_translation(*v12, &v7);
  vostok::math::mul4x3(v6, &v10, &v11);
  qmemcpy(result, &v11, sizeof(vostok::math::float4x4));
}
