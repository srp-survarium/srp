vostok::math::float4x4 *__thiscall vostok::math::float4x4::identity(vostok::math::float4x4 *this)
{
  const vostok::math::float4x4 *v1; // xmm1_4
  vostok::math::float4x4 *result; // eax
  __int64 v3; // xmm2_8
  __int64 v4; // xmm0_8
  vostok::math::float4_pod v5; // [esp+0h] [ebp-10h]

  v1 = clear_value;
  result = this;
  *(_QWORD *)&v5.elements[2] = 0;
  *(_QWORD *)&this->i.x = (unsigned int)clear_value;
  v5.x = 0.0;
  *(_QWORD *)&this->lines[0].elements[2] = *(_QWORD *)&v5.elements[2];
  LODWORD(v5.y) = v1;
  *(_QWORD *)&v5.elements[2] = 0;
  this->j = v5;
  *(_QWORD *)&v5.elements[2] = (unsigned int)v1;
  *(_QWORD *)&this->lines[2].x = 0;
  v3 = *(_QWORD *)&v5.elements[2];
  v5.z = 0.0;
  *(_QWORD *)&this->lines[3].x = 0;
  LODWORD(v5.w) = v1;
  v4 = *(_QWORD *)&v5.elements[2];
  *(_QWORD *)&this->lines[2].elements[2] = v3;
  *(_QWORD *)&this->lines[3].elements[2] = v4;
  return result;
}
