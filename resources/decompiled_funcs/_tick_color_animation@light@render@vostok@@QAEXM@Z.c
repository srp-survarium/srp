void __thiscall vostok::render::light::tick_color_animation(
        vostok::render::light *this,
        const float time_delta,
        float time_deltaa)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  bool v5; // cc
  double v6; // st7
  vostok::math::float4 *v7; // eax
  vostok::math::float4 *result; // [esp+0h] [ebp-38h]
  int v9; // [esp+14h] [ebp-24h]
  vostok::math::enum_evaluate_time_type v10; // [esp+18h] [ebp-20h]
  vostok::math::float4 v11; // [esp+24h] [ebp-14h] BYREF

  if ( *(_BYTE *)(LODWORD(time_delta) + 264) )
  {
    v3 = epsilon_3_11;
    if ( *(float *)(LODWORD(time_delta) + 268) > 0.001 )
      v3 = *(float *)(LODWORD(time_delta) + 268);
    v4 = (float)(time_deltaa / v3) + *(float *)(LODWORD(time_delta) + 336);
    v5 = v4 <= *(float *)&clear_value;
    *(float *)(LODWORD(time_delta) + 336) = v4;
    if ( !v5 )
    {
      this = (vostok::render::light *)(((int)v4 >> 31) ^ (((int)v4 >> 31) + (int)v4));
      *(float *)(LODWORD(time_delta) + 336) = COERCE_FLOAT(LODWORD(v4) & 0x7FFFFFFF) - (float)(int)this;
    }
    v6 = *(float *)(LODWORD(time_delta) + 336);
    memset(&v11, 0, sizeof(v11));
    *(float *)&result = v6;
    v7 = vostok::math::curve_line_color::evaluate(
           (vostok::math::curve_line_color *)this,
           LODWORD(time_delta) + 272,
           &v11,
           result,
           0,
           0,
           v9,
           v10);
    *(_QWORD *)(LODWORD(time_delta) + 132) = *(_QWORD *)&v7->x;
    *(float *)(LODWORD(time_delta) + 140) = v7->z;
  }
}
