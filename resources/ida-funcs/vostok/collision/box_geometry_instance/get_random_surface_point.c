vostok::math::float3 *__thiscall vostok::collision::box_geometry_instance::get_random_surface_point(
        vostok::collision::box_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  vostok::buffer_vector<float> *v3; // ecx
  vostok::buffer_vector<float> *v4; // ecx
  vostok::buffer_vector<float> *v5; // ecx
  vostok::buffer_vector<float> *v6; // ecx
  vostok::buffer_vector<float> *v7; // ecx
  float *v8; // eax
  float v9; // xmm0_4
  int v10; // ecx
  float v11; // xmm1_4
  float *v12; // eax
  double v13; // st7
  int v14; // xmm2_4
  double v15; // st7
  int v16; // edx
  float v17; // xmm1_4
  double v18; // st7
  int v19; // edx
  float value; // [esp+14h] [ebp-D0h] BYREF
  stlp_std::less<float> __comp[4]; // [esp+18h] [ebp-CCh]
  float v23; // [esp+1Ch] [ebp-C8h]
  float v24; // [esp+20h] [ebp-C4h]
  int v25; // [esp+24h] [ebp-C0h]
  float v26; // [esp+28h] [ebp-BCh]
  float v27; // [esp+2Ch] [ebp-B8h]
  float *__first; // [esp+30h] [ebp-B4h] BYREF
  float *__last; // [esp+34h] [ebp-B0h]
  _DWORD *v30; // [esp+38h] [ebp-ACh]
  _BYTE v31[24]; // [esp+3Ch] [ebp-A8h] BYREF
  _DWORD v32[36]; // [esp+54h] [ebp-90h] BYREF

  __first = (float *)v31;
  __last = (float *)v31;
  v30 = v32;
  value = FLOAT_4_0;
  vostok::buffer_vector<float>::push_back((vostok::buffer_vector<float> *)this, (int)&__first, &value);
  value = *__first + 4.0;
  vostok::buffer_vector<float>::push_back(v3, (int)&__first, &value);
  value = __first[1] + 4.0;
  vostok::buffer_vector<float>::push_back(v4, (int)&__first, &value);
  value = __first[2] + 4.0;
  vostok::buffer_vector<float>::push_back(v5, (int)&__first, &value);
  value = __first[3] + 4.0;
  vostok::buffer_vector<float>::push_back(v6, (int)&__first, &value);
  value = __first[4] + 4.0;
  vostok::buffer_vector<float>::push_back(v7, (int)&__first, &value);
  value = vostok::math::random32::random_f(randomizer, 24.0);
  v8 = stlp_std::lower_bound<float *,float,stlp_std::less<float>>(__first, __last, &value);
  *(float *)v32 = FLOAT_N1_0;
  *(float *)&v32[1] = s_bm_current_air_resistance;
  *(float *)&v32[2] = FLOAT_N1_0;
  *(float *)&v32[3] = s_bm_current_air_resistance;
  *(float *)&v32[4] = FLOAT_N1_0;
  *(float *)&v32[5] = FLOAT_N1_0;
  *(float *)&v32[6] = FLOAT_N1_0;
  *(float *)&v32[7] = s_bm_current_air_resistance;
  *(float *)&v32[8] = s_bm_current_air_resistance;
  *(float *)&v32[9] = s_bm_current_air_resistance;
  *(float *)&v32[10] = FLOAT_N1_0;
  *(float *)&v32[11] = s_bm_current_air_resistance;
  *(float *)&v32[12] = FLOAT_N1_0;
  *(float *)&v32[13] = s_bm_current_air_resistance;
  *(float *)&v32[14] = s_bm_current_air_resistance;
  *(float *)&v32[15] = FLOAT_N1_0;
  *(float *)&v32[16] = FLOAT_N1_0;
  *(float *)&v32[17] = FLOAT_N1_0;
  *(float *)&v32[18] = s_bm_current_air_resistance;
  *(float *)&v32[19] = s_bm_current_air_resistance;
  *(float *)&v32[20] = s_bm_current_air_resistance;
  *(float *)&v32[21] = s_bm_current_air_resistance;
  *(float *)&v32[22] = FLOAT_N1_0;
  *(float *)&v32[23] = FLOAT_N1_0;
  *(float *)&v32[24] = FLOAT_N1_0;
  *(float *)&v32[25] = s_bm_current_air_resistance;
  *(float *)&v32[26] = s_bm_current_air_resistance;
  *(float *)&v32[27] = s_bm_current_air_resistance;
  *(float *)&v32[28] = s_bm_current_air_resistance;
  *(float *)&v32[29] = FLOAT_N1_0;
  v25 = LODWORD(FLOAT_N1_0);
  v26 = FLOAT_N1_0;
  v27 = s_bm_current_air_resistance;
  *(float *)&v32[30] = FLOAT_N1_0;
  *(float *)&v32[31] = FLOAT_N1_0;
  *(float *)&v32[32] = s_bm_current_air_resistance;
  *(float *)&__comp[0].gap0 = s_bm_current_air_resistance;
  v23 = FLOAT_N1_0;
  v24 = FLOAT_N1_0;
  *(float *)&v32[33] = s_bm_current_air_resistance;
  *(float *)&v32[34] = FLOAT_N1_0;
  *(float *)&v32[35] = FLOAT_N1_0;
  if ( v8 == __first )
    v9 = 0.0;
  else
    v9 = *(v8 - 1);
  v10 = v8 - __first;
  v11 = (float)(value - v9) / (float)(*v8 - v9);
  v12 = (float *)&v32[6 * v10];
  if ( v10 >= 0 )
  {
    if ( v10 <= 1 )
    {
      v18 = v12[2];
      *(float *)&__comp[0].gap0 = v12[1];
      result->z = v18;
      v19 = *(_DWORD *)&__comp[0].gap0;
      *(float *)&__comp[0].gap0 = *v12;
      v25 = *(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF;
      *(float *)&__comp[0].gap0 = (float)(COERCE_FLOAT(*(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF) * v11) * 2.0;
      LODWORD(value) = v19 & 0x7FFFFFFF;
      v23 = vostok::math::random32::random_f(randomizer, COERCE_FLOAT(v19 & 0x7FFFFFFF) * 2.0);
      v14 = _mask__NegFloat_;
      result->y = COERCE_FLOAT(LODWORD(value) ^ _mask__NegFloat_) + v23;
      goto LABEL_11;
    }
    if ( v10 <= 3 )
    {
      v15 = *v12;
      *(float *)&__comp[0].gap0 = v12[1];
      result->x = v15;
      v16 = *(_DWORD *)&__comp[0].gap0;
      *(float *)&__comp[0].gap0 = v12[2];
      v25 = *(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF;
      *(float *)&__comp[0].gap0 = (float)(COERCE_FLOAT(*(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF) * v11) * 2.0;
      LODWORD(value) = v16 & 0x7FFFFFFF;
      v23 = vostok::math::random32::random_f(randomizer, COERCE_FLOAT(v16 & 0x7FFFFFFF) * 2.0);
      v17 = COERCE_FLOAT(LODWORD(value) ^ _mask__NegFloat_) + v23;
      result->z = COERCE_FLOAT(v25 ^ _mask__NegFloat_) + *(float *)&__comp[0].gap0;
      result->y = v17;
    }
    else if ( v10 <= 5 )
    {
      v13 = v12[1];
      value = v12[2];
      result->y = v13;
      *(float *)&__comp[0].gap0 = *v12;
      v25 = *(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF;
      *(float *)&__comp[0].gap0 = (float)(COERCE_FLOAT(*(_DWORD *)&__comp[0].gap0 & 0x7FFFFFFF) * v11) * 2.0;
      LODWORD(value) &= ~0x80000000;
      v23 = vostok::math::random32::random_f(randomizer, value * 2.0);
      v14 = _mask__NegFloat_;
      result->z = COERCE_FLOAT(LODWORD(value) ^ _mask__NegFloat_) + v23;
LABEL_11:
      result->x = COERCE_FLOAT(v25 ^ v14) + *(float *)&__comp[0].gap0;
    }
  }
  return result;
}
