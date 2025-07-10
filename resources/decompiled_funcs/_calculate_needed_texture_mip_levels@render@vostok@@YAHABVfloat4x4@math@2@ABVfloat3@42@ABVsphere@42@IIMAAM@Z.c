unsigned int __usercall vostok::render::calculate_needed_texture_mip_levels@<eax>(
        const vostok::math::float3 *viewer_position@<eax>,
        const vostok::math::sphere *object_sphere@<esi>,
        const vostok::math::float4x4 *projection_matrix,
        unsigned int screen_size_x,
        float screen_size_y,
        float *factor)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  unsigned int v8; // eax
  long double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  unsigned int v13; // eax
  bool v14; // cf
  long double v16; // [esp+4h] [ebp-10h]
  long double v17; // [esp+4h] [ebp-10h]
  float w; // [esp+8h] [ebp-Ch]
  float screen_space_size_x; // [esp+Ch] [ebp-8h]
  float screen_space_size_y; // [esp+10h] [ebp-4h]

  v6 = viewer_position->z - object_sphere->vector.z;
  v7 = viewer_position->y - object_sphere->vector.y;
  w = object_sphere->vector.w;
  screen_space_size_x = sqrtf(
                          (float)((float)(v6 * v6) + (float)(v7 * v7))
                        + (float)((float)(viewer_position->x - object_sphere->vector.x)
                                * (float)(viewer_position->x - object_sphere->vector.x)))
                      + w * 0.25;
  *factor = screen_space_size_x;
  v8 = 11;
  if ( screen_space_size_x > w )
  {
    *((float *)&v16 + 1) = object_sphere->vector.w;
    v9 = *((float *)&v16 + 1)
       / sqrtf((float)(screen_space_size_x * screen_space_size_x) - (float)(*((float *)&v16 + 1) * *((float *)&v16 + 1)));
    v10 = FLOAT_0_000099999997;
    if ( screen_size_y > 0.000099999997 )
      v10 = screen_size_y;
    v11 = (double)(unsigned int)projection_matrix * v9 * 2.0;
    screen_space_size_y = v9 * (double)screen_size_x * 2.0;
    if ( v11 <= screen_space_size_y )
      v11 = v9 * (double)screen_size_x * 2.0;
    v12 = (float)(v11 / (float)(*((float *)&v16 + 1) * 2.0)) * v10;
    if ( v12 >= 4096.0 )
      v12 = 4096.0;
    __libm_sse2_log(v16);
    __libm_sse2_log(v17);
    v13 = vostok::math::ceil(v12 / (float)2.0);
    v14 = v13 == -1;
    v8 = v13 + 1;
    if ( v14 || v8 == 1 )
      return 1 - quality_index;
    if ( v8 > 0xB )
      v8 = 11;
  }
  return v8 - quality_index;
}
