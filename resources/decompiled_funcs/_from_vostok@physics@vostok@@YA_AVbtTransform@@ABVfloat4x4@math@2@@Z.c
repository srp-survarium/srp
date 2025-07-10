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
