vostok::math::float3 *__cdecl vostok::physics::get_box_random_surface_point(
        float result,
        vostok::math::random32 *random)
{
  vostok::buffer_vector<float> *v2; // ecx
  float *v3; // ebx
  vostok::buffer_vector<float> *v4; // ecx
  vostok::buffer_vector<float> *v5; // ecx
  vostok::buffer_vector<float> *v6; // ecx
  vostok::buffer_vector<float> *v7; // ecx
  vostok::buffer_vector<float> *v8; // ecx
  float *v9; // eax
  float v10; // xmm0_4
  int v11; // ecx
  float v12; // xmm1_4
  float *v13; // eax
  double v14; // st7
  int v15; // xmm2_4
  double v16; // st7
  float v17; // xmm1_4
  double v18; // st7
  _DWORD v20[3]; // [esp+14h] [ebp-D0h] BYREF
  unsigned __int64 v21; // [esp+20h] [ebp-C4h]
  float v22; // [esp+28h] [ebp-BCh]
  float v23; // [esp+2Ch] [ebp-B8h]
  float v24; // [esp+30h] [ebp-B4h]
  float v25; // [esp+34h] [ebp-B0h]
  float v26; // [esp+38h] [ebp-ACh]
  float v27; // [esp+3Ch] [ebp-A8h]
  float v28; // [esp+40h] [ebp-A4h]
  float v29; // [esp+44h] [ebp-A0h]
  float v30; // [esp+48h] [ebp-9Ch]
  float v31; // [esp+4Ch] [ebp-98h]
  float v32; // [esp+50h] [ebp-94h]
  float v33; // [esp+54h] [ebp-90h]
  float v34; // [esp+58h] [ebp-8Ch]
  float v35; // [esp+5Ch] [ebp-88h]
  float v36; // [esp+60h] [ebp-84h]
  float v37; // [esp+64h] [ebp-80h]
  float v38; // [esp+68h] [ebp-7Ch]
  float v39; // [esp+6Ch] [ebp-78h]
  float v40; // [esp+70h] [ebp-74h]
  float v41; // [esp+74h] [ebp-70h]
  float v42; // [esp+78h] [ebp-6Ch]
  float v43; // [esp+7Ch] [ebp-68h]
  float v44; // [esp+80h] [ebp-64h]
  float v45; // [esp+84h] [ebp-60h]
  float v46; // [esp+88h] [ebp-5Ch]
  float v47; // [esp+8Ch] [ebp-58h]
  float v48; // [esp+90h] [ebp-54h]
  float v49; // [esp+94h] [ebp-50h]
  float v50; // [esp+98h] [ebp-4Ch]
  float v51; // [esp+9Ch] [ebp-48h]
  float v52; // [esp+A0h] [ebp-44h]
  float *v53; // [esp+A8h] [ebp-3Ch] BYREF
  float *v54; // [esp+ACh] [ebp-38h]
  float *v55; // [esp+B0h] [ebp-34h]
  _BYTE v56[24]; // [esp+B4h] [ebp-30h] BYREF
  float v57; // [esp+CCh] [ebp-18h] BYREF
  int v58; // [esp+D0h] [ebp-14h]
  float v59; // [esp+D4h] [ebp-10h]
  float v60; // [esp+D8h] [ebp-Ch]
  float v61; // [esp+DCh] [ebp-8h]
  float v62; // [esp+E0h] [ebp-4h]

  v3 = (float *)LODWORD(result);
  v53 = (float *)v56;
  v54 = (float *)v56;
  v55 = &v57;
  result = FLOAT_4_0;
  vostok::buffer_vector<float>::push_back(v2, (int)&v53, &result);
  result = *v53 + 4.0;
  vostok::buffer_vector<float>::push_back(v4, (int)&v53, &result);
  result = v53[1] + 4.0;
  vostok::buffer_vector<float>::push_back(v5, (int)&v53, &result);
  result = v53[2] + 4.0;
  vostok::buffer_vector<float>::push_back(v6, (int)&v53, &result);
  result = v53[3] + 4.0;
  vostok::buffer_vector<float>::push_back(v7, (int)&v53, &result);
  result = v53[4] + 4.0;
  vostok::buffer_vector<float>::push_back(v8, (int)&v53, &result);
  result = vostok::math::random32::random_f(random, 24.0);
  v9 = stlp_std::lower_bound<float *,float,stlp_std::less<float>>(v53, v54, &result);
  *(float *)v20 = FLOAT_N1_0;
  *(float *)&v20[1] = s_bm_current_air_resistance;
  *(float *)&v20[2] = FLOAT_N1_0;
  v21 = __PAIR64__(LODWORD(FLOAT_N1_0), LODWORD(s_bm_current_air_resistance));
  v22 = FLOAT_N1_0;
  v23 = FLOAT_N1_0;
  v24 = s_bm_current_air_resistance;
  v25 = s_bm_current_air_resistance;
  v26 = s_bm_current_air_resistance;
  v27 = FLOAT_N1_0;
  v28 = s_bm_current_air_resistance;
  v29 = FLOAT_N1_0;
  v30 = s_bm_current_air_resistance;
  v31 = s_bm_current_air_resistance;
  v32 = FLOAT_N1_0;
  v33 = FLOAT_N1_0;
  v34 = FLOAT_N1_0;
  v35 = s_bm_current_air_resistance;
  v36 = s_bm_current_air_resistance;
  v37 = s_bm_current_air_resistance;
  v38 = s_bm_current_air_resistance;
  v39 = FLOAT_N1_0;
  v40 = FLOAT_N1_0;
  v41 = FLOAT_N1_0;
  v42 = s_bm_current_air_resistance;
  v43 = s_bm_current_air_resistance;
  v44 = s_bm_current_air_resistance;
  v45 = s_bm_current_air_resistance;
  v46 = FLOAT_N1_0;
  v57 = FLOAT_N1_0;
  v58 = LODWORD(FLOAT_N1_0);
  v59 = s_bm_current_air_resistance;
  v47 = FLOAT_N1_0;
  v48 = FLOAT_N1_0;
  v49 = s_bm_current_air_resistance;
  v60 = s_bm_current_air_resistance;
  v61 = FLOAT_N1_0;
  v62 = FLOAT_N1_0;
  v50 = s_bm_current_air_resistance;
  v51 = FLOAT_N1_0;
  v52 = FLOAT_N1_0;
  if ( v9 == v53 )
    v10 = 0.0;
  else
    v10 = *(v9 - 1);
  v11 = v9 - v53;
  v12 = (float)(result - v10) / (float)(*v9 - v10);
  v13 = (float *)&v20[6 * v11];
  if ( v11 >= 0 )
  {
    if ( v11 <= 1 )
    {
      v18 = v13[2];
      result = v13[1];
      v3[2] = v18;
      v62 = *v13;
      v58 = LODWORD(v62) & 0x7FFFFFFF;
      v61 = (float)(COERCE_FLOAT(LODWORD(v62) & 0x7FFFFFFF) * v12) * 2.0;
      LODWORD(result) &= ~0x80000000;
      v62 = vostok::math::random32::random_f(random, result * 2.0);
      v15 = _mask__NegFloat_;
      v3[1] = COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_) + v62;
      goto LABEL_11;
    }
    if ( v11 <= 3 )
    {
      v16 = *v13;
      result = v13[1];
      *v3 = v16;
      v62 = v13[2];
      v58 = LODWORD(v62) & 0x7FFFFFFF;
      v61 = (float)(COERCE_FLOAT(LODWORD(v62) & 0x7FFFFFFF) * v12) * 2.0;
      LODWORD(result) &= ~0x80000000;
      v62 = vostok::math::random32::random_f(random, result * 2.0);
      v17 = COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_) + v62;
      v3[2] = COERCE_FLOAT(v58 ^ _mask__NegFloat_) + v61;
      v3[1] = v17;
    }
    else if ( v11 <= 5 )
    {
      v14 = v13[1];
      result = v13[2];
      v3[1] = v14;
      v62 = *v13;
      v58 = LODWORD(v62) & 0x7FFFFFFF;
      v61 = (float)(COERCE_FLOAT(LODWORD(v62) & 0x7FFFFFFF) * v12) * 2.0;
      LODWORD(result) &= ~0x80000000;
      v62 = vostok::math::random32::random_f(random, result * 2.0);
      v15 = _mask__NegFloat_;
      v3[2] = COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_) + v62;
LABEL_11:
      *v3 = COERCE_FLOAT(v58 ^ v15) + v61;
    }
  }
  return (vostok::math::float3 *)v3;
}
