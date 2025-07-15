vostok::math::float4x4 *__usercall vostok::animation::mix_transformations@<eax>(
        const vostok::math::float4x4 *a1@<eax>,
        const vostok::math::float4x4 *a2@<esi>,
        float a3@<xmm0>,
        vostok::math::float4x4 *this,
        struct vostok::math::float4x4 *retstr)
{
  unsigned int v5; // xmm1_4
  unsigned int v6; // xmm2_4
  vostok::math::quaternion result; // [esp+8h] [ebp-3Ch] BYREF
  vostok::math::quaternion q0; // [esp+18h] [ebp-2Ch] BYREF
  vostok::math::quaternion q1; // [esp+28h] [ebp-1Ch] BYREF
  vostok::math::float3 v11; // [esp+38h] [ebp-Ch] BYREF

  *(float *)&v5 = (float)(a1->c.y * (float)(s_bm_current_air_resistance - a3)) + (float)(a2->c.y * a3);
  *(float *)&v6 = (float)(a1->c.z * (float)(s_bm_current_air_resistance - a3)) + (float)(a2->c.z * a3);
  v11.x = (float)(a1->c.x * (float)(s_bm_current_air_resistance - a3)) + (float)(a3 * a2->c.x);
  *(_QWORD *)&v11.elements[1] = __PAIR64__(v6, v5);
  vostok::math::quaternion::quaternion(&q0, a1);
  if ( !vostok::math::quaternion::is_unit(&q0) )
    vostok::math::float4_pod::normalize((vostok::math::float4_pod *)&q0);
  vostok::math::quaternion::quaternion(&q1, a2);
  if ( !vostok::math::quaternion::is_unit(&q1) )
    vostok::math::float4_pod::normalize((vostok::math::float4_pod *)&q1);
  vostok::math::slerp(&result, &q0, &q1, *(float *)&retstr);
  vostok::math::create_matrix(&result, &v11, this);
  return this;
}
