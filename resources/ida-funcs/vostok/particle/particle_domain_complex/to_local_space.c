vostok::math::float3 *__usercall vostok::particle::particle_domain_complex::to_local_space@<eax>(
        vostok::particle::particle_domain_complex *this@<ecx>,
        const vostok::math::float3 *point@<edi>,
        float *a3@<esi>)
{
  const vostok::math::float4x4 *transform; // eax
  float y; // xmm2_4
  float x; // xmm0_4
  float z; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  vostok::math::float4x4 result; // [esp+0h] [ebp-80h] BYREF
  vostok::math::float4x4 v11; // [esp+40h] [ebp-40h] BYREF

  transform = vostok::particle::particle_domain_complex::get_transform(this, &result);
  vostok::math::float4x4::try_invert(transform, &v11);
  y = point->y;
  x = point->x;
  z = point->z;
  *a3 = (float)((float)((float)(point->x * v11.i.x) + (float)(y * v11.j.x)) + (float)(z * v11.k.x)) + v11.c.x;
  v7 = (float)(x * v11.i.y) + (float)(y * v11.j.y);
  v8 = (float)((float)((float)(x * v11.i.z) + (float)(y * v11.j.z)) + (float)(z * v11.k.z)) + v11.c.z;
  a3[1] = (float)(v7 + (float)(z * v11.k.y)) + v11.c.y;
  a3[2] = v8;
  return (vostok::math::float3 *)a3;
}
