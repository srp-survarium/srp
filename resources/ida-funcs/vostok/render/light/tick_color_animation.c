void __fastcall vostok::render::light::tick_color_animation(vostok::render::light *this, float time_delta, float a4)
{
  float v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cc
  double v8; // st7
  vostok::math::float4 *v9; // eax
  unsigned int v10; // [esp+0h] [ebp-34h]
  double v11; // [esp+10h] [ebp-24h]
  vostok::render::light *v12; // [esp+10h] [ebp-24h]
  vostok::math::float4 v13; // [esp+24h] [ebp-10h] BYREF

  v4 = time_delta;
  if ( *(_BYTE *)(LODWORD(time_delta) + 748) )
  {
    v5 = *(float *)(LODWORD(time_delta) + 752);
    if ( v5 <= 0.001 )
      v5 = epsilon_3_4;
    v6 = (float)(a4 / v5) + *(float *)(LODWORD(time_delta) + 824);
    v7 = v6 <= s_bm_current_air_resistance;
    *(float *)(LODWORD(time_delta) + 824) = v6;
    if ( !v7 )
    {
      LODWORD(v11) = &time_delta;
      time_delta = v6;
      *(float *)(LODWORD(v4) + 824) = modf(v6, v11);
      this = v12;
    }
    v8 = *(float *)(LODWORD(v4) + 824);
    memset(&v13, 0, sizeof(v13));
    *(float *)&v10 = v8;
    v9 = vostok::math::curve_line_color::evaluate(
           (vostok::math::curve_line_color *)this,
           (vostok::math::float4 *)(LODWORD(v4) + 760),
           &v13,
           (vostok::math::float4)v10,
           0);
    *(float *)(LODWORD(v4) + 516) = v9->x;
    *(float *)(LODWORD(v4) + 520) = v9->y;
    *(float *)(LODWORD(v4) + 524) = v9->z;
  }
}
