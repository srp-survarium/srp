vostok::math::float4x4 *__thiscall vostok::particle::particle_domain_complex::get_transform(
        vostok::particle::particle_domain_complex *this,
        vostok::math::float4x4 *result)
{
  vostok::math::quaternion *v2; // ecx
  const vostok::math::quaternion *v3; // eax
  vostok::math::float4x4 *v4; // eax
  vostok::math::float3 v6; // [esp-Ch] [ebp-140h] BYREF
  const vostok::math::float4x4 *right; // [esp+8h] [ebp-12Ch]
  vostok::math::float3 *position; // [esp+Ch] [ebp-128h]
  const vostok::particle::particle_domain_complex *thisa; // [esp+10h] [ebp-124h]
  _BYTE v10[64]; // [esp+88h] [ebp-ACh] BYREF
  vostok::math::float3 scale; // [esp+C8h] [ebp-6Ch] BYREF
  char v12; // [esp+D4h] [ebp-60h] BYREF
  float v13[4]; // [esp+118h] [ebp-1Ch] BYREF
  vostok::math::float3 v14; // [esp+128h] [ebp-Ch] BYREF

  thisa = this;
  vostok::math::float3::float3((vostok::math::float3 *)&this->m_translate, &v14);
  vostok::math::float3::float3((vostok::math::float3 *)&thisa->m_scale, &scale);
  position = &v14;
  vostok::math::float3::float3((vostok::math::float3 *)&thisa->m_rotate, &v6);
  vostok::math::quaternion::quaternion(v2, v13, v6);
  LODWORD(v6.z) = &v12;
  right = vostok::math::create_matrix(v3, position);
  LODWORD(v6.z) = right;
  v4 = vostok::math::create_scale(&scale, (int)v10);
  vostok::math::operator*(result, v4, (const vostok::math::float4x4 *)LODWORD(v6.z));
  return result;
}
