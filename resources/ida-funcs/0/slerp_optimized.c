vostok::math::quaternion *__usercall slerp_optimized@<eax>(
        const vostok::math::quaternion *q0@<ecx>,
        const vostok::math::quaternion *q1@<eax>,
        _QWORD *a3@<esi>,
        float t)
{
  float y; // xmm2_4
  float z; // xmm6_4
  float v6; // xmm3_4
  float w; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float i_sinom; // [esp+4h] [ebp-40h]
  float i_sinoma; // [esp+4h] [ebp-40h]
  float sign; // [esp+8h] [ebp-3Ch]
  float t_omega; // [esp+Ch] [ebp-38h]
  float t_omegaa; // [esp+Ch] [ebp-38h]
  float Scale0; // [esp+10h] [ebp-34h]
  __int64 v20; // [esp+28h] [ebp-1Ch]
  float x; // [esp+30h] [ebp-14h]
  __int64 v22; // [esp+34h] [ebp-10h]
  __int64 v23; // [esp+3Ch] [ebp-8h]

  y = q0->y;
  z = q1->z;
  v6 = q0->z;
  w = q1->w;
  v8 = q0->w;
  v20 = *(_QWORD *)&q1->x;
  v9 = (float)((float)((float)(q1->x * q0->x) + (float)(q1->y * y)) + (float)(z * v6)) + (float)(w * v8);
  x = q0->x;
  i_sinom = v9;
  if ( v9 >= 0.0 )
  {
    sign = *(float *)&clear_value;
  }
  else
  {
    v9 = -v9;
    i_sinom = v9;
    sign = -1.0;
  }
  if ( v9 >= 0.99998999 )
  {
    v11 = t;
    v10 = *(float *)&clear_value - t;
  }
  else
  {
    t_omega = acosf(i_sinom);
    i_sinoma = 1.0 / sinf(t_omega);
    Scale0 = sinf(t_omega - (float)(t_omega * t)) * i_sinoma;
    v10 = Scale0;
    t_omegaa = sinf(t_omega * t) * i_sinoma;
    v11 = t_omegaa;
  }
  v12 = v11 * sign;
  *(float *)&v22 = (float)(x * v10) + (float)(*(float *)&v20 * v12);
  *((float *)&v22 + 1) = (float)(y * v10) + (float)(*((float *)&v20 + 1) * v12);
  *a3 = v22;
  *(float *)&v23 = (float)(v6 * v10) + (float)(z * v12);
  *((float *)&v23 + 1) = (float)(v8 * v10) + (float)(w * v12);
  a3[1] = v23;
  return (vostok::math::quaternion *)a3;
}
