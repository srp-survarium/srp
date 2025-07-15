vostok::math::float2 *__usercall vostok::render::clip_2_screen@<eax>(
        const vostok::math::float3 *world_pixel@<ecx>,
        const vostok::math::float4x4 *wvpMatrix@<eax>,
        vostok::math::float2 *screen_width,
        unsigned int screen_height,
        unsigned int a5)
{
  vostok::math::float2 *v5; // ebx
  float z; // xmm3_4
  float y; // xmm2_4
  double v8; // st7
  vostok::math::float2 *result; // eax
  float v10; // [esp+24h] [ebp-14h]
  float v11; // [esp+28h] [ebp-10h]
  float v12[2]; // [esp+30h] [ebp-8h] BYREF

  v5 = screen_width;
  z = world_pixel->z;
  y = world_pixel->y;
  v10 = (float)((float)((float)(wvpMatrix->k.x * z) + (float)(wvpMatrix->j.x * y))
              + (float)(wvpMatrix->i.x * world_pixel->x))
      + wvpMatrix->c.x;
  v11 = (float)((float)((float)(wvpMatrix->k.y * z) + (float)(wvpMatrix->i.y * world_pixel->x))
              + (float)(wvpMatrix->j.y * y))
      + wvpMatrix->c.y;
  v12[0] = (float)((float)((float)(wvpMatrix->k.w * z) + (float)(wvpMatrix->i.w * world_pixel->x))
                 + (float)(wvpMatrix->j.w * y))
         + wvpMatrix->c.w;
  screen_width = 0;
  if ( vostok::math::is_similar<float>(v12, (const float *)&screen_width, 0.0000099999997) )
    v12[0] = epsilon_3_4;
  v8 = (double)a5 * (float)((float)((float)(v11 * (float)(s_bm_current_air_resistance / v12[0])) * -0.5) + 0.5);
  result = v5;
  v5->x = (double)screen_height
        * (float)((float)((float)(v10 * (float)(s_bm_current_air_resistance / v12[0])) * 0.5) + 0.5);
  v5->y = v8;
  return result;
}
