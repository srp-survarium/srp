void __usercall survarium::load_transform(vostok::configs::binary_config_value *t@<eax>, vostok::math::float4x4 *dest)
{
  float *pointer; // esi
  const vostok::math::float3 *v4; // ebx
  const vostok::math::float3 **v5; // edi
  const vostok::math::float4x4 *v6; // eax
  const vostok::math::float4x4 *v7; // eax
  vostok::math::float4x4 dst; // [esp+10h] [ebp-100h] BYREF
  vostok::math::float4x4 left; // [esp+50h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+90h] [ebp-80h] BYREF
  vostok::math::float4x4 v11; // [esp+D0h] [ebp-40h] BYREF

  pointer = (float *)vostok::configs::binary_config_value::operator[](t, "scale")->data.pointer;
  v4 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "rotation")->data.pointer;
  v5 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](t, "position");
  memset((int)&dst, 0, sizeof(dst));
  dst.i.x = *pointer;
  dst.j.y = pointer[1];
  dst.k.z = pointer[2];
  LODWORD(dst.c.w) = clear_value;
  v6 = vostok::math::create_rotation(&result, v4);
  vostok::math::mul4x3(&left, &dst, v6);
  v7 = vostok::math::create_translation(&v11, *v5);
  vostok::math::mul4x3(&dst, &left, v7);
  qmemcpy((void *)dest, &dst, sizeof(vostok::math::float4x4));
}
