vostok::math::float4x4 *__thiscall vostok::particle::particle_domain_complex::get_transform(
        vostok::particle::particle_domain_complex *this,
        vostok::math::float4x4 *result)
{
  float z; // xmm0_4
  double y; // st7
  const vostok::math::quaternion *v4; // eax
  vostok::math::float4x4 *v5; // ebx
  vostok::math::float4x4 *v6; // eax
  vostok::math::quaternion v8; // [esp-18h] [ebp-C8h] BYREF
  vostok::math::float4x4 v9; // [esp+4h] [ebp-ACh] BYREF
  vostok::math::float4x4 v10; // [esp+44h] [ebp-6Ch] BYREF
  float v11[4]; // [esp+84h] [ebp-2Ch] BYREF
  vostok::math::float3 v12; // [esp+94h] [ebp-1Ch] BYREF
  vostok::math::float3_pod m_translate; // [esp+A0h] [ebp-10h] BYREF

  m_translate = this->m_translate;
  *(_QWORD *)&v12.x = *(_QWORD *)&this->m_scale.x;
  z = this->m_scale.z;
  v8.x = this->m_rotate.x;
  y = this->m_rotate.y;
  v12.z = z;
  v8.y = y;
  v8.z = this->m_rotate.z;
  vostok::math::quaternion::quaternion(&v8, v11, *(vostok::math::float3 *)&v8.x);
  v5 = vostok::math::create_matrix(v4, (const vostok::math::float3 *)&m_translate, &v10);
  v6 = vostok::math::create_scale(&v12, &v9);
  vostok::math::mul4x3(v5, v6, result);
  return result;
}
