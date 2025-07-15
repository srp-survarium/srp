void __cdecl survarium::load_transform(const vostok::configs::binary_config_value *t, vostok::math::float4x4 *dest)
{
  const vostok::math::float3 *pointer; // esi
  const vostok::math::float3 *v3; // ebx
  vostok::math::float4x4 *rotation; // ebx
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 *v6; // eax
  const vostok::math::float3 **v7; // [esp+Ch] [ebp-144h]
  vostok::math::float4x4 v8; // [esp+10h] [ebp-140h] BYREF
  vostok::math::float4x4 v9; // [esp+50h] [ebp-100h] BYREF
  _BYTE v10[64]; // [esp+90h] [ebp-C0h] BYREF
  vostok::math::float4x4 v11; // [esp+D0h] [ebp-80h] BYREF
  vostok::math::float4x4 v12; // [esp+110h] [ebp-40h] BYREF

  pointer = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "scale")->data.pointer;
  v3 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "rotation")->data.pointer;
  v7 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](t, "position");
  rotation = vostok::math::create_rotation(v3, (int)"position", (int)v10);
  v5 = vostok::math::create_scale(pointer, &v11);
  vostok::math::mul4x3(rotation, v5, &v9);
  v6 = vostok::math::create_translation(*v7, &v12);
  vostok::math::mul4x3(v6, &v9, &v8);
  qmemcpy(dest, &v8, sizeof(vostok::math::float4x4));
}
