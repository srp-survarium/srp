vostok::render::cloud_key_parameters *__userpurge vostok::render::environment_temp::get_interp_key@<eax>(
        vostok::render::environment_temp *this@<ecx>,
        int a2@<eax>,
        vostok::render::cloud_key_parameters *result,
        float time)
{
  double v6; // st7
  unsigned int v7; // ebp
  const vostok::math::float4x4 *v8; // xmm0_4
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // ebp
  float v12; // xmm3_4
  float v13; // xmm2_4
  float *v14; // edx
  float *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float value; // [esp+4h] [ebp-5Ch]
  _DWORD v30[17]; // [esp+1Ch] [ebp-44h] BYREF
  float alpha; // [esp+64h] [ebp+4h]
  float alphaa; // [esp+64h] [ebp+4h]

  v6 = 0.0 / *(float *)(a2 + 4);
  v7 = *(_DWORD *)(a2 + 8);
  result->cloud_base = 3200.0;
  result->layer_height = 7.0;
  v8 = clear_value;
  result->linear_time = 0.0;
  LODWORD(result->direct_light) = v8;
  LODWORD(result->indirect_light) = v8;
  LODWORD(result->ambient) = v8;
  LODWORD(result->extinction) = v8;
  LODWORD(result->detail_noise_wave_lenght) = v8;
  LODWORD(result->detail_noise_amplitude) = v8;
  LODWORD(result->wind_speed) = v8;
  result->cloud_generate_cloudiness = FLOAT_0_5;
  LODWORD(result->cloud_generate_octaves) = v8;
  result->diffusivity = 0.0;
  LODWORD(result->persistence) = v8;
  result->source_key_index = 0;
  result->target_key_index = 1;
  alpha = v6;
  value = v6;
  v9 = vostok::math::floor(value);
  v10 = v9 % v7;
  v11 = v9 % v7 + 1 < v7 ? v9 % v7 + 1 : 0;
  alphaa = powf(
             COERCE_FLOAT(LODWORD(alpha) & 0x7FFFFFFF) - (float)(((int)alpha >> 31) ^ (((int)alpha >> 31) + (int)alpha)),
             2.0);
  v12 = *(float *)(*(_DWORD *)a2 + 68 * v11 + 28);
  v13 = *(float *)(*(_DWORD *)a2 + 68 * v10 + 28);
  v14 = (float *)(*(_DWORD *)a2 + 68 * v11);
  v15 = (float *)(*(_DWORD *)a2 + 68 * v10);
  qmemcpy(v30, v15, sizeof(v30));
  v16 = (float)(v13 * (float)(*(float *)&clear_value - alphaa)) + (float)(v12 * alphaa);
  v17 = v14[8];
  *(float *)&v30[7] = v16;
  v18 = (float)(v15[8] * (float)(*(float *)&clear_value - alphaa)) + (float)(v17 * alphaa);
  v19 = v14[9];
  *(float *)&v30[8] = v18;
  v20 = (float)(v15[9] * (float)(*(float *)&clear_value - alphaa)) + (float)(v19 * alphaa);
  v21 = v14[10];
  *(float *)&v30[9] = v20;
  v22 = (float)(v15[10] * (float)(*(float *)&clear_value - alphaa)) + (float)(v21 * alphaa);
  v23 = v14[11];
  *(float *)&v30[10] = v22;
  v24 = (float)(v15[11] * (float)(*(float *)&clear_value - alphaa)) + (float)(v23 * alphaa);
  v25 = v14[2];
  *(float *)&v30[11] = v24;
  v26 = (float)(v15[2] * (float)(*(float *)&clear_value - alphaa)) + (float)(v25 * alphaa);
  v27 = v14[3];
  *(float *)&v30[2] = v26;
  *(float *)&v30[3] = (float)(v15[3] * (float)(*(float *)&clear_value - alphaa)) + (float)(v27 * alphaa);
  *(float *)&v30[4] = (float)(v15[4] * (float)(*(float *)&clear_value - alphaa)) + (float)(v14[4] * alphaa);
  qmemcpy(result, v30, sizeof(vostok::render::cloud_key_parameters));
  result->interp_alpha = alphaa;
  result->target_key_index = v11;
  result->source_key_index = v10;
  return result;
}
