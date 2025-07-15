void __usercall vostok::collision::random_point_inside_axis_aligned_rectangle(
        vostok::math::random32 *randomizer@<edx>,
        const vostok::math::float2 *center@<esi>,
        const vostok::math::float2 *half_size@<ecx>,
        const float *x_part,
        float *result_x,
        float *result_y)
{
  double v6; // st7
  unsigned int v7; // eax
  float v8; // xmm1_4
  float result_4; // [esp+4h] [ebp-4h]

  v6 = half_size->y + half_size->y;
  v7 = 134775813 * randomizer->m_seed + 1;
  randomizer->m_seed = v7;
  v8 = center->y - half_size->y;
  result_4 = v6 * ((double)((unsigned __int64)v7 >> 12) * 0.00000095367432);
  *result_x = (float)(center->x - half_size->x) + (float)((float)(*x_part * half_size->x) * 2.0);
  *result_y = v8 + result_4;
}
