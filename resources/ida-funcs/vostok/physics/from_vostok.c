btQuaternion *__cdecl vostok::physics::from_vostok(btQuaternion *a1)
{
  vostok::math::quaternion *from; // ecx
  float v3; // [esp+4Ch] [ebp-20h] BYREF
  vostok::math::float3 axis; // [esp+50h] [ebp-1Ch] BYREF
  btVector3 v5; // [esp+5Ch] [ebp-10h] BYREF

  vostok::math::quaternion::get_axis_and_angle(from, &axis, &v3);
  v5.mVec128.m128_u64[0] = *(_QWORD *)&axis.x;
  v5.mVec128.m128_f32[2] = -axis.z;
  v5.mVec128.m128_i32[3] = 0;
  btQuaternion::setRotation(a1, &v5, &v3);
  return a1;
}


vostok::math::quaternion *__usercall vostok::physics::from_vostok@<eax>(
        const vostok::math::float4x4 *m@<esi>,
        vostok::math::quaternion *a2@<edi>)
{
  vostok::math::quaternion from; // [esp+30h] [ebp-20h] BYREF
  btQuaternion v4; // [esp+40h] [ebp-10h] BYREF

  vostok::math::quaternion::quaternion(&from, m);
  vostok::physics::from_vostok(&v4);
  *(_QWORD *)&from.x = *(_QWORD *)&m->lines[3].x;
  from.z = -m->c.z;
  from.w = 0.0;
  btMatrix3x3::setRotation((btMatrix3x3 *)&v4, (int)a2);
  a2[3] = from;
  return a2;
}
