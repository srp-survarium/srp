char __fastcall vostok::math::try_invert4x4(
        const vostok::math::float4x4 *matrix_to_invert,
        vostok::math::float4x4 *out_result)
{
  float y; // xmm4_4
  float v3; // xmm5_4
  float z; // xmm7_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float x; // xmm4_4
  float v9; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // [esp+0h] [ebp-14h]
  float v18; // [esp+8h] [ebp-Ch]
  float v19; // [esp+Ch] [ebp-8h]
  float v20; // [esp+10h] [ebp-4h]

  out_result->i.x = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.y * matrix_to_invert->k.z)
                                                          * matrix_to_invert->c.w)
                                                  - (float)((float)(matrix_to_invert->k.w * matrix_to_invert->c.z)
                                                          * matrix_to_invert->j.y))
                                          - (float)((float)(matrix_to_invert->j.z * matrix_to_invert->k.y)
                                                  * matrix_to_invert->c.w))
                                  + (float)((float)(matrix_to_invert->c.y * matrix_to_invert->j.z)
                                          * matrix_to_invert->k.w))
                          + (float)((float)(matrix_to_invert->j.w * matrix_to_invert->k.y) * matrix_to_invert->c.z))
                  - (float)((float)(matrix_to_invert->c.y * matrix_to_invert->j.w) * matrix_to_invert->k.z);
  out_result->j.x = (float)((float)((float)((float)((float)((float)(matrix_to_invert->k.x * matrix_to_invert->j.z)
                                                          - (float)(matrix_to_invert->j.x * matrix_to_invert->k.z))
                                                  * matrix_to_invert->c.w)
                                          + (float)((float)(matrix_to_invert->j.x * matrix_to_invert->k.w)
                                                  * matrix_to_invert->c.z))
                                  - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->j.w)
                                          * matrix_to_invert->c.z))
                          - (float)((float)(matrix_to_invert->c.x * matrix_to_invert->j.z) * matrix_to_invert->k.w))
                  + (float)((float)(matrix_to_invert->c.x * matrix_to_invert->j.w) * matrix_to_invert->k.z);
  out_result->k.x = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.x * matrix_to_invert->k.y)
                                                          * matrix_to_invert->c.w)
                                                  - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->c.y)
                                                          * matrix_to_invert->k.w))
                                          - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->j.y)
                                                  * matrix_to_invert->c.w))
                                  + (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.y)
                                          * matrix_to_invert->j.w))
                          + (float)((float)(matrix_to_invert->c.x * matrix_to_invert->k.w) * matrix_to_invert->j.y))
                  - (float)((float)(matrix_to_invert->c.x * matrix_to_invert->j.w) * matrix_to_invert->k.y);
  y = matrix_to_invert->j.y;
  v3 = matrix_to_invert->k.y;
  z = matrix_to_invert->k.z;
  v5 = matrix_to_invert->j.z;
  v6 = (float)((float)((float)((float)(matrix_to_invert->k.x * y) - (float)(matrix_to_invert->j.x * v3))
                     * matrix_to_invert->c.z)
             + (float)((float)(matrix_to_invert->j.x * matrix_to_invert->c.y) * z))
     - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.y) * v5);
  v7 = matrix_to_invert->c.x * y;
  x = out_result->i.x;
  v9 = (float)(v6 - (float)(v7 * z)) + (float)((float)(matrix_to_invert->c.x * v5) * v3);
  out_result->c.x = v9;
  v17 = (float)((float)((float)(x * matrix_to_invert->i.x) + (float)(matrix_to_invert->i.y * out_result->j.x))
              + (float)(v9 * matrix_to_invert->i.w))
      + (float)(matrix_to_invert->i.z * out_result->k.x);
  if ( v17 == 0.0 )
    return 0;
  out_result->i.y = (float)((float)((float)((float)((float)((float)(matrix_to_invert->i.z * matrix_to_invert->k.y)
                                                          - (float)(matrix_to_invert->i.y * matrix_to_invert->k.z))
                                                  * matrix_to_invert->c.w)
                                          + (float)((float)(matrix_to_invert->k.w * matrix_to_invert->c.z)
                                                  * matrix_to_invert->i.y))
                                  - (float)((float)(matrix_to_invert->i.w * matrix_to_invert->c.z)
                                          * matrix_to_invert->k.y))
                          - (float)((float)(matrix_to_invert->c.y * matrix_to_invert->k.w) * matrix_to_invert->i.z))
                  + (float)((float)(matrix_to_invert->c.y * matrix_to_invert->i.w) * matrix_to_invert->k.z);
  out_result->j.y = (float)((float)((float)((float)((float)((float)(matrix_to_invert->c.w * matrix_to_invert->k.z)
                                                          * matrix_to_invert->i.x)
                                                  - (float)((float)(matrix_to_invert->k.w * matrix_to_invert->c.z)
                                                          * matrix_to_invert->i.x))
                                          - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.w)
                                                  * matrix_to_invert->i.z))
                                  + (float)((float)(matrix_to_invert->k.x * matrix_to_invert->i.w)
                                          * matrix_to_invert->c.z))
                          + (float)((float)(matrix_to_invert->c.x * matrix_to_invert->k.w) * matrix_to_invert->i.z))
                  - (float)((float)(matrix_to_invert->c.x * matrix_to_invert->i.w) * matrix_to_invert->k.z);
  out_result->k.y = (float)((float)((float)((float)((float)((float)(matrix_to_invert->k.x * matrix_to_invert->i.y)
                                                          - (float)(matrix_to_invert->k.y * matrix_to_invert->i.x))
                                                  * matrix_to_invert->c.w)
                                          + (float)((float)(matrix_to_invert->c.y * matrix_to_invert->k.w)
                                                  * matrix_to_invert->i.x))
                                  - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.y)
                                          * matrix_to_invert->i.w))
                          - (float)((float)(matrix_to_invert->c.x * matrix_to_invert->k.w) * matrix_to_invert->i.y))
                  + (float)((float)(matrix_to_invert->c.x * matrix_to_invert->i.w) * matrix_to_invert->k.y);
  out_result->c.y = (float)((float)((float)((float)((float)((float)(matrix_to_invert->c.z * matrix_to_invert->k.y)
                                                          * matrix_to_invert->i.x)
                                                  - (float)((float)(matrix_to_invert->c.y * matrix_to_invert->k.z)
                                                          * matrix_to_invert->i.x))
                                          - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.z)
                                                  * matrix_to_invert->i.y))
                                  + (float)((float)(matrix_to_invert->k.x * matrix_to_invert->c.y)
                                          * matrix_to_invert->i.z))
                          + (float)((float)(matrix_to_invert->c.x * matrix_to_invert->i.y) * matrix_to_invert->k.z))
                  - (float)((float)(matrix_to_invert->c.x * matrix_to_invert->i.z) * matrix_to_invert->k.y);
  out_result->i.z = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.z * matrix_to_invert->c.w)
                                                          * matrix_to_invert->i.y)
                                                  - (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.z)
                                                          * matrix_to_invert->i.y))
                                          - (float)((float)(matrix_to_invert->j.y * matrix_to_invert->c.w)
                                                  * matrix_to_invert->i.z))
                                  + (float)((float)(matrix_to_invert->j.y * matrix_to_invert->i.w)
                                          * matrix_to_invert->c.z))
                          + (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.y) * matrix_to_invert->i.z))
                  - (float)((float)(matrix_to_invert->j.z * matrix_to_invert->c.y) * matrix_to_invert->i.w);
  out_result->j.z = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.x * matrix_to_invert->i.z)
                                                          - (float)(matrix_to_invert->j.z * matrix_to_invert->i.x))
                                                  * matrix_to_invert->c.w)
                                          + (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.z)
                                                  * matrix_to_invert->i.x))
                                  - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->i.w)
                                          * matrix_to_invert->c.z))
                          - (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.x) * matrix_to_invert->i.z))
                  + (float)((float)(matrix_to_invert->j.z * matrix_to_invert->c.x) * matrix_to_invert->i.w);
  out_result->k.z = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.y * matrix_to_invert->c.w)
                                                          * matrix_to_invert->i.x)
                                                  - (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.y)
                                                          * matrix_to_invert->i.x))
                                          - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->c.w)
                                                  * matrix_to_invert->i.y))
                                  + (float)((float)(matrix_to_invert->j.x * matrix_to_invert->c.y)
                                          * matrix_to_invert->i.w))
                          + (float)((float)(matrix_to_invert->j.w * matrix_to_invert->c.x) * matrix_to_invert->i.y))
                  - (float)((float)(matrix_to_invert->j.y * matrix_to_invert->c.x) * matrix_to_invert->i.w);
  out_result->c.z = (float)((float)((float)((float)((float)((float)(matrix_to_invert->j.x * matrix_to_invert->i.y)
                                                          - (float)(matrix_to_invert->j.y * matrix_to_invert->i.x))
                                                  * matrix_to_invert->c.z)
                                          + (float)((float)(matrix_to_invert->j.z * matrix_to_invert->c.y)
                                                  * matrix_to_invert->i.x))
                                  - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->c.y)
                                          * matrix_to_invert->i.z))
                          - (float)((float)(matrix_to_invert->j.z * matrix_to_invert->c.x) * matrix_to_invert->i.y))
                  + (float)((float)(matrix_to_invert->j.y * matrix_to_invert->c.x) * matrix_to_invert->i.z);
  out_result->i.w = (float)((float)((float)((float)((float)((float)(matrix_to_invert->i.z * matrix_to_invert->j.y)
                                                          - (float)(matrix_to_invert->j.z * matrix_to_invert->i.y))
                                                  * matrix_to_invert->k.w)
                                          + (float)((float)(matrix_to_invert->i.y * matrix_to_invert->j.w)
                                                  * matrix_to_invert->k.z))
                                  - (float)((float)(matrix_to_invert->k.z * matrix_to_invert->i.w)
                                          * matrix_to_invert->j.y))
                          - (float)((float)(matrix_to_invert->j.w * matrix_to_invert->k.y) * matrix_to_invert->i.z))
                  + (float)((float)(matrix_to_invert->j.z * matrix_to_invert->k.y) * matrix_to_invert->i.w);
  out_result->j.w = (float)((float)((float)((float)((float)((float)(matrix_to_invert->i.x * matrix_to_invert->k.w)
                                                          * matrix_to_invert->j.z)
                                                  - (float)((float)(matrix_to_invert->i.x * matrix_to_invert->j.w)
                                                          * matrix_to_invert->k.z))
                                          - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->k.w)
                                                  * matrix_to_invert->i.z))
                                  + (float)((float)(matrix_to_invert->j.x * matrix_to_invert->i.w)
                                          * matrix_to_invert->k.z))
                          + (float)((float)(matrix_to_invert->k.x * matrix_to_invert->j.w) * matrix_to_invert->i.z))
                  - (float)((float)(matrix_to_invert->k.x * matrix_to_invert->j.z) * matrix_to_invert->i.w);
  out_result->k.w = (float)((float)((float)((float)((float)((float)(matrix_to_invert->i.y * matrix_to_invert->j.x)
                                                          - (float)(matrix_to_invert->i.x * matrix_to_invert->j.y))
                                                  * matrix_to_invert->k.w)
                                          + (float)((float)(matrix_to_invert->i.x * matrix_to_invert->j.w)
                                                  * matrix_to_invert->k.y))
                                  - (float)((float)(matrix_to_invert->j.x * matrix_to_invert->k.y)
                                          * matrix_to_invert->i.w))
                          - (float)((float)(matrix_to_invert->i.y * matrix_to_invert->k.x) * matrix_to_invert->j.w))
                  + (float)((float)(matrix_to_invert->k.x * matrix_to_invert->i.w) * matrix_to_invert->j.y);
  v11 = matrix_to_invert->j.y;
  v12 = matrix_to_invert->i.y;
  v19 = matrix_to_invert->k.y;
  v20 = matrix_to_invert->j.z;
  v13 = matrix_to_invert->j.x;
  v18 = matrix_to_invert->i.z;
  v14 = matrix_to_invert->k.x;
  v15 = (float)((float)((float)(matrix_to_invert->i.x * matrix_to_invert->k.z) * v11)
              - (float)((float)(matrix_to_invert->i.x * v20) * v19))
      - (float)((float)(v12 * v13) * matrix_to_invert->k.z);
  v16 = s_bm_current_air_resistance / v17;
  out_result->i.y = out_result->i.y * (float)(s_bm_current_air_resistance / v17);
  out_result->i.z = out_result->i.z * v16;
  out_result->i.w = out_result->i.w * v16;
  out_result->c.w = (float)((float)(v15 + (float)((float)(v12 * v14) * v20)) + (float)((float)(v13 * v19) * v18))
                  - (float)((float)(v14 * v18) * v11);
  out_result->i.x = x * v16;
  out_result->j.x = out_result->j.x * v16;
  out_result->j.y = out_result->j.y * v16;
  out_result->j.z = out_result->j.z * v16;
  out_result->j.w = out_result->j.w * v16;
  out_result->k.x = v16 * out_result->k.x;
  out_result->k.y = out_result->k.y * v16;
  out_result->k.z = out_result->k.z * v16;
  out_result->k.w = out_result->k.w * v16;
  out_result->c.x = out_result->c.x * v16;
  out_result->c.y = out_result->c.y * v16;
  out_result->c.z = out_result->c.z * v16;
  out_result->c.w = out_result->c.w * v16;
  return 1;
}
