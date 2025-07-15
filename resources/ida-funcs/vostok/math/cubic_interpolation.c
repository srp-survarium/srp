float *__usercall vostok::math::cubic_interpolation<vostok::math::float3_pod,float>@<eax>(
        float *result@<eax>,
        float a2@<xmm7>,
        vostok::math::float3_pod P0,
        vostok::math::float3_pod M0,
        vostok::math::float3_pod P1,
        vostok::math::float3_pod M1)
{
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // [esp+Ch] [ebp-Ch]
  float v18; // [esp+10h] [ebp-8h]

  v6 = (float)(a2 * a2) * 3.0;
  v7 = (float)((float)(a2 * a2) * a2) - (float)(a2 * a2);
  v8 = (float)((float)(a2 * a2) * a2) * 2.0;
  v9 = (float)((float)((float)(a2 * a2) * a2) - (float)((float)(a2 * a2) * 2.0)) + a2;
  v10 = v6 - v8;
  v17 = P1.y * (float)(v6 - v8);
  v18 = P1.z * (float)(v6 - v8);
  v11 = v8 - v6;
  v12 = (float)((float)(P0.y * (float)(v11 + s_bm_current_air_resistance)) + (float)(M0.y * v9)) + v17;
  v13 = M1.x * v7;
  v14 = M1.y * v7;
  v15 = M1.z * v7;
  v16 = (float)((float)(P0.z * (float)(v11 + s_bm_current_air_resistance)) + (float)(M0.z * v9)) + v18;
  *result = (float)((float)((float)(P0.x * (float)(v11 + s_bm_current_air_resistance)) + (float)(M0.x * v9))
                  + (float)(P1.x * v10))
          + v13;
  result[1] = v12 + v14;
  result[2] = v16 + v15;
  return result;
}


float *__usercall vostok::math::cubic_interpolation<vostok::math::float4_pod,float>@<eax>(
        float *result@<eax>,
        float a2@<xmm7>,
        vostok::math::float4_pod P0,
        vostok::math::float4_pod M0,
        vostok::math::float4_pod P1,
        vostok::math::float4_pod M1)
{
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm0_4

  v6 = (float)((float)(a2 * a2) * a2) - (float)(a2 * a2);
  v7 = (float)(a2 * a2) * 3.0;
  v8 = (float)((float)((float)(a2 * a2) * a2) - (float)((float)(a2 * a2) * 2.0)) + a2;
  v9 = (float)((float)(a2 * a2) * a2) * 2.0;
  v10 = v7 - v9;
  v11 = (float)(v9 - v7) + s_bm_current_air_resistance;
  *result = (float)((float)((float)(P0.x * v11) + (float)(M0.x * v8)) + (float)(P1.x * v10)) + (float)(M1.x * v6);
  result[1] = (float)((float)((float)(P0.y * v11) + (float)(M0.y * v8)) + (float)(P1.y * v10)) + (float)(M1.y * v6);
  result[2] = (float)((float)((float)(P0.z * v11) + (float)(M0.z * v8)) + (float)(P1.z * v10)) + (float)(M1.z * v6);
  result[3] = (float)((float)((float)(P0.w * v11) + (float)(M0.w * v8)) + (float)(P1.w * v10)) + (float)(M1.w * v6);
  return result;
}
