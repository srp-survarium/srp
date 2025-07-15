unsigned int __usercall vostok::render::get_num_mips_for_pool_texture@<eax>(
        unsigned int width@<eax>,
        unsigned int height)
{
  float v2; // xmm0_4
  float v4; // [esp+Ch] [ebp+8h]

  v4 = __FYL2X__((double)(height + (width < height ? width - height : 0)), 0.6931471805599453094)
     / __FYL2X__(2.0, 0.6931471805599453094)
     - s_bm_current_air_resistance;
  if ( v4 <= 5.0 )
    v2 = FLOAT_5_0;
  else
    v2 = v4;
  return vostok::math::floor(v2);
}
