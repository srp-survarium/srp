vostok::math::quaternion *__usercall vostok::math::create_quaternion_from_direction_vector@<eax>(
        const vostok::math::float3 *direction@<edi>,
        vostok::math::quaternion *a2)
{
  vostok::math::float4x4 *rotation_x; // ebp
  vostok::math::float4x4 *rotation_y; // eax
  float _X; // [esp+4h] [ebp-D4h]
  float _Xa; // [esp+4h] [ebp-D4h]
  float _Y; // [esp+14h] [ebp-C4h]
  vostok::math::float4x4 result; // [esp+18h] [ebp-C0h] BYREF
  _QWORD v9[8]; // [esp+58h] [ebp-80h] BYREF
  _QWORD v10[8]; // [esp+98h] [ebp-40h] BYREF

  _Y = direction->z;
  _X = atan2f(direction->y, _Y);
  rotation_x = vostok::math::create_rotation_x(v9, (vostok::math::float4x4 *)LODWORD(_X));
  _Xa = atan2f(_Y, direction->x);
  rotation_y = vostok::math::create_rotation_y(v10, (vostok::math::float4x4 *)LODWORD(_Xa));
  vostok::math::mul4x3(&result, rotation_y, rotation_x);
  vostok::math::quaternion::quaternion(a2, &result);
  return a2;
}
