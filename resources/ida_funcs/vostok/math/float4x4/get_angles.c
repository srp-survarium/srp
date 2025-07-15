vostok::math::float3 *__usercall vostok::math::float4x4::get_angles@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        int a2@<edi>,
        float *a3@<esi>)
{
  long double v3; // st6
  long double v4; // st7
  float v5; // xmm0_4
  float _Y; // [esp+4h] [ebp-14h]
  float _Ya; // [esp+4h] [ebp-14h]
  float _Yb; // [esp+4h] [ebp-14h]
  float _X; // [esp+8h] [ebp-10h]
  float _Xa; // [esp+8h] [ebp-10h]
  float _Xb; // [esp+8h] [ebp-10h]
  float _Xc; // [esp+8h] [ebp-10h]
  float ky_wo_scale; // [esp+Ch] [ebp-Ch]
  float ky_wo_scalea; // [esp+Ch] [ebp-Ch]
  float v16; // [esp+10h] [ebp-8h]
  float v17; // [esp+14h] [ebp-4h]

  v3 = 1.0 / sqrtf((float)((float)(a3[8] * a3[8]) + (float)(a3[9] * a3[9])) + (float)(a3[10] * a3[10])) * a3[9];
  if ( v3 >= 1.0 )
  {
    _Xc = *a3;
    *(float *)a2 = pi_d2_8;
    _Yb = a3[2];
    *(_DWORD *)(a2 + 4) = 0;
    *(float *)(a2 + 8) = atan2f(_Yb, _Xc);
    return (vostok::math::float3 *)a2;
  }
  else
  {
    ky_wo_scale = v3;
    if ( ky_wo_scale <= -1.0 )
    {
      _Xb = *a3;
      *(_DWORD *)a2 = -1077342245;
      _Ya = a3[2];
      *(_DWORD *)(a2 + 4) = 0;
      *(float *)(a2 + 8) = -atan2f(_Ya, _Xb);
    }
    else
    {
      _X = v3;
      v4 = asinf(_X);
      v5 = a3[8];
      *(float *)a2 = v4;
      *(float *)(a2 + 4) = atan2f(-v5, a3[10]);
      v17 = a3[2];
      v16 = *a3;
      ky_wo_scalea = a3[1];
      _Xa = 1.0 / sqrtf((float)((float)(a3[4] * a3[4]) + (float)(a3[5] * a3[5])) + (float)(a3[6] * a3[6])) * a3[5];
      _Y = -(1.0 / sqrtf((float)((float)(ky_wo_scalea * ky_wo_scalea) + (float)(v16 * v16)) + (float)(v17 * v17)) * a3[1]);
      *(float *)(a2 + 8) = atan2f(_Y, _Xa);
    }
    return (vostok::math::float3 *)a2;
  }
}
