float __userpurge survarium::bullet::compute_max_error@<xmm0>(
        survarium::bullet *this@<eax>,
        survarium::bullet *a2@<ecx>,
        float a3@<xmm0>,
        float low,
        float high)
{
  survarium::bullet *v6; // ecx
  survarium::bullet *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  vostok::math::float3 v12; // [esp+Ch] [ebp-24h] BYREF
  vostok::math::float3 v13; // [esp+18h] [ebp-18h] BYREF
  vostok::math::float3 v14; // [esp+24h] [ebp-Ch] BYREF
  float v15; // [esp+38h] [ebp+8h]

  survarium::bullet::compute_trajectory_position(this, a2, &v14, a3, low);
  survarium::bullet::compute_trajectory_position(this, v6, &v12, a3, high);
  survarium::bullet::compute_trajectory_position(this, v7, &v13, (float)(low + high) * 0.5, (float)(low + high) * 0.5);
  v15 = fsqrt(
          (float)((float)((float)(v13.z - v14.z) * (float)(v13.z - v14.z))
                + (float)((float)(v13.y - v14.y) * (float)(v13.y - v14.y)))
        + (float)((float)(v13.x - v14.x) * (float)(v13.x - v14.x)));
  v13.y = (float)(v13.y - v14.y) * (float)(s_bm_current_air_resistance / v15);
  v8 = s_bm_current_air_resistance
     / fsqrt(
         (float)((float)((float)(v12.z - v14.z) * (float)(v12.z - v14.z))
               + (float)((float)(v12.y - v14.y) * (float)(v12.y - v14.y)))
       + (float)((float)(v12.x - v14.x) * (float)(v12.x - v14.x)));
  v9 = (float)((float)((float)((float)(v12.z - v14.z) * v8)
                     * (float)((float)(v13.z - v14.z) * (float)(s_bm_current_air_resistance / v15)))
             + (float)((float)((float)(v12.y - v14.y) * v8) * v13.y))
     + (float)((float)(v8 * (float)(v12.x - v14.x))
             * (float)((float)(s_bm_current_air_resistance / v15) * (float)(v13.x - v14.x)));
  if ( s_bm_current_air_resistance <= v9 )
    v9 = s_bm_current_air_resistance;
  v10 = FLOAT_N1_0;
  if ( v9 >= -1.0 )
    v10 = v9;
  return fsqrt(s_bm_current_air_resistance - (float)(v10 * v10)) * v15;
}
