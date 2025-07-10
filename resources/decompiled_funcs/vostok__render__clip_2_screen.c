vostok::math::float2 *__fastcall vostok::render::clip_2_screen(
        const vostok::math::float4x4 *wvpMatrix,
        const vostok::math::float3 *world_pixel,
        vostok::math::float2 *screen_width,
        unsigned int screen_height,
        unsigned int screen_heighta)
{
  float z; // xmm6_4
  float y; // xmm5_4
  vostok::math::float2 *result; // eax
  float v8; // xmm4_4
  float v9; // [esp+14h] [ebp-Ch]

  z = world_pixel->z;
  y = world_pixel->y;
  result = screen_width;
  v8 = (float)((float)((float)(wvpMatrix->k.w * z) + (float)(wvpMatrix->i.w * world_pixel->x))
             + (float)(wvpMatrix->j.w * y))
     + wvpMatrix->c.w;
  if ( fabs(v8) < 0.0000099999997 )
    v8 = epsilon_3_11;
  v9 = (float)((float)((float)((float)((float)((float)(wvpMatrix->k.y * z) + (float)(wvpMatrix->i.y * world_pixel->x))
                                     + (float)(wvpMatrix->j.y * y))
                             + wvpMatrix->c.y)
                     * (float)(*(float *)&clear_value / v8))
             * -0.5)
     + 0.5;
  screen_width->x = (double)screen_height
                  * (float)((float)((float)((float)((float)((float)((float)(wvpMatrix->k.x * z)
                                                                  + (float)(wvpMatrix->j.x * y))
                                                          + (float)(wvpMatrix->i.x * world_pixel->x))
                                                  + wvpMatrix->c.x)
                                          * (float)(*(float *)&clear_value / v8))
                                  * 0.5)
                          + 0.5);
  screen_width->y = (double)screen_heighta * v9;
  return result;
}
