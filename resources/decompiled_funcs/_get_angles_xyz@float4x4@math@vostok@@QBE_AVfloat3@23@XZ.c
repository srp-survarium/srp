vostok::math::float3 *__usercall vostok::math::float4x4::get_angles_xyz@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        float *a2@<edi>,
        float *a3@<esi>)
{
  long double v3; // st6
  long double v4; // st7
  float v5; // xmm0_4
  float v7; // xmm0_4
  long double v8; // st7
  float _Y; // [esp+4h] [ebp-1Ch]
  float _X; // [esp+8h] [ebp-18h]
  float iz_wo_scale; // [esp+Ch] [ebp-14h]
  float v12; // [esp+10h] [ebp-10h]
  float v13; // [esp+14h] [ebp-Ch]
  float v14; // [esp+18h] [ebp-8h]
  float v15; // [esp+1Ch] [ebp-4h]

  v15 = *a3;
  v3 = 1.0 / sqrtf((float)((float)(v15 * v15) + (float)(a3[1] * a3[1])) + (float)(a3[2] * a3[2])) * a3[2];
  iz_wo_scale = v3;
  if ( v3 >= 1.0 )
  {
    v8 = atan2f(a3[4], a3[5]);
    v7 = pi_d2_8;
  }
  else
  {
    if ( iz_wo_scale > -1.0 )
    {
      v14 = a3[6];
      v13 = a3[5];
      v12 = a3[4];
      _X = 1.0 / sqrtf((float)((float)(a3[8] * a3[8]) + (float)(a3[9] * a3[9])) + (float)(a3[10] * a3[10])) * a3[10];
      _Y = -(1.0 / sqrtf((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14)) * a3[6]);
      *a2 = atan2f(_Y, _X);
      v4 = asinf(iz_wo_scale);
      v5 = a3[1];
      a2[1] = v4;
      a2[2] = atan2f(-v5, v15);
      return (vostok::math::float3 *)a2;
    }
    v7 = -1.5707964;
    v8 = -atan2f(a3[4], a3[5]);
  }
  a2[1] = v7;
  *a2 = v8;
  a2[2] = 0.0;
  return (vostok::math::float3 *)a2;
}
