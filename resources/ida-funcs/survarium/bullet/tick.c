void __userpurge survarium::bullet::tick(
        unsigned int current_time_in_ms@<eax>,
        survarium::bullet *a2@<ecx>,
        vostok::math::float3 this)
{
  int x_low; // ebx
  float x; // xmm3_4
  float permissible_time; // xmm0_4
  unsigned int v7; // xmm2_4
  unsigned int v8; // xmm1_4
  survarium::bullet_manager *v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  int v13; // eax
  float v14; // xmm3_4
  __int128 v15; // [esp-10h] [ebp-54h] BYREF
  vostok::math::float3 *low_time; // [esp+0h] [ebp-44h]
  float *high_time; // [esp+4h] [ebp-40h]
  float v18[3]; // [esp+18h] [ebp-2Ch] BYREF
  vostok::math::float3 v19; // [esp+24h] [ebp-20h] BYREF
  float v20; // [esp+30h] [ebp-14h]
  float v21; // [esp+34h] [ebp-10h]
  float v22; // [esp+38h] [ebp-Ch]
  float next_time; // [esp+3Ch] [ebp-8h] BYREF
  float v24; // [esp+40h] [ebp-4h] BYREF

  x_low = LODWORD(this.x);
  x = *(float *)(LODWORD(this.x) + 100);
  *(_DWORD *)(LODWORD(this.x) + 96) = current_time_in_ms;
  LODWORD(this.x) = current_time_in_ms - *(_DWORD *)(x_low + 92);
  next_time = x;
  LODWORD(v22) = *(_DWORD *)(x_low + 60) + 20;
  v24 = (double)LODWORD(this.x) * 0.001;
  while ( 1 )
  {
    if ( s_bm_current_air_resistance > (float)((float)((float)(*(float *)(x_low + 16) * *(float *)(x_low + 16))
                                                     + (float)(*(float *)(x_low + 20) * *(float *)(x_low + 20)))
                                             + (float)(*(float *)(x_low + 24) * *(float *)(x_low + 24)))
      || *(_DWORD *)(x_low + 132) >= 0x1Eu )
    {
      goto LABEL_11;
    }
    if ( x == v24 )
      return;
    permissible_time = survarium::bullet::pick_next_permissible_time(
                         (survarium::bullet *)x_low,
                         a2,
                         s_bm_current_air_resistance,
                         next_time,
                         v24);
    this.x = permissible_time;
    if ( next_time == permissible_time
      || (high_time = &v24,
          low_time = &this,
          HIDWORD(v15) = &next_time,
          *(_QWORD *)&v15 = *(_QWORD *)(x_low + 4),
          DWORD2(v15) = *(_DWORD *)(x_low + 12),
          survarium::bullet::check_collision(a2, permissible_time, (survarium::bullet *)x_low, v15, &this.x, &v24) == 1)
      || this.x != 0.0
      && !survarium::bullet::update_bullet_position(
            a2,
            x_low,
            (int)&v15 + 12,
            x_low + 16,
            0.0,
            (survarium::bullet *)x_low,
            (const vostok::math::float3 *)LODWORD(this.x),
            v22) )
    {
LABEL_11:
      survarium::bullet::finish_flying(a2, (_DWORD *)x_low);
      return;
    }
    x = this.x;
    v21 = this.x - v24;
    v20 = fabs(this.x - v24);
    if ( v20 < 0.0000099999997 )
      break;
    next_time = this.x;
  }
  *(float *)&v7 = *(float *)(x_low + 8) - *(float *)(x_low + 32);
  *(float *)&v8 = *(float *)(x_low + 4) - *(float *)(x_low + 28);
  v19.z = *(float *)(x_low + 12) - *(float *)(x_low + 36);
  *(_QWORD *)&v19.x = __PAIR64__(v7, v8);
  v18[0] = 0.0;
  v18[1] = 0.0;
  v22 = fsqrt(
          (float)((float)(v19.z * v19.z) + (float)(*(float *)&v7 * *(float *)&v7))
        + (float)(*(float *)&v8 * *(float *)&v8));
  v18[2] = s_bm_current_air_resistance;
  vostok::math::float3_pod::normalize_safe((vostok::math::float3_pod *)a2, &v19, v18);
  v10 = *(float *)(x_low + 100);
  v11 = fsqrt(
          (float)((float)(*(float *)(x_low + 24) * *(float *)(x_low + 24))
                + (float)(*(float *)(x_low + 16) * *(float *)(x_low + 16)))
        + (float)(*(float *)(x_low + 20) * *(float *)(x_low + 20)));
  if ( g_bullet_tracer_exposition <= v10 )
    v12 = g_bullet_tracer_exposition;
  else
    v12 = *(float *)(x_low + 100);
  v13 = *(_DWORD *)(x_low + 132);
  v14 = v12 * v11;
  this.x = v14;
  if ( v13 )
  {
    if ( v14 > v22 )
    {
      v14 = v22;
      this.x = v22;
    }
  }
  else if ( g_bullet_tracer_exposition > v10 )
  {
    v14 = v14 - 3.0;
    this.x = v14;
  }
  if ( v14 > 0.0 )
    survarium::bullet_manager::update_tracer(
      v9,
      *(survarium::bullet **)(x_low + 60),
      (const vostok::math::float3 *)x_low,
      (const vostok::math::float3 *)(x_low + 4),
      &v19.x,
      SLODWORD(this.x));
}
