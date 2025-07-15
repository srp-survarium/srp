vostok::math::quaternion *__usercall vostok::math::conjugate@<eax>(
        const vostok::math::quaternion *value@<ecx>,
        vostok::math::quaternion *result@<eax>)
{
  float v2; // ecx
  __int64 v3; // [esp+4h] [ebp-20h]
  vostok::math::quaternion v4; // [esp+10h] [ebp-14h]

  v4 = *value;
  *(float *)&v3 = -v4.x;
  HIDWORD(v3) = LODWORD(v4.y) ^ 0x80000000;
  v2 = -v4.z;
  *(_QWORD *)&result->x = v3;
  v4.z = v2;
  *(_QWORD *)&result->vector.elements[2] = *(_QWORD *)&v4.vector.elements[2];
  return result;
}
