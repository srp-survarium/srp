void __userpurge survarium::breath_vibration_calculator::tick(
        survarium::breath_vibration_calculator *this@<ecx>,
        int a2@<eax>,
        const float dispersion,
        const unsigned int time_delta_in_ms)
{
  float *v6; // edi
  float *v7; // ebx
  __m128 v8; // xmm0
  __m128i v9; // xmm0
  float v10; // xmm2_4
  __m128 v11; // xmm0
  __m128i v12; // xmm0
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  long double v17; // [esp+8h] [ebp-24h]
  float v18; // [esp+14h] [ebp-18h]
  float v19; // [esp+20h] [ebp-Ch]
  float v20; // [esp+24h] [ebp-8h]
  float v21; // [esp+28h] [ebp-4h]
  float v22; // [esp+38h] [ebp+Ch]
  float v23; // [esp+38h] [ebp+Ch]

  v6 = (float *)(*(_DWORD *)(a2 + 60) + 588);
  v7 = (float *)(*(_DWORD *)(a2 + 56) + 860);
  vostok::ai::fsm::tick(&this->m_logic, a2);
  v22 = (double)time_delta_in_ms * 0.001;
  (*(void (__stdcall **)(_DWORD, float))(**(_DWORD **)(a2 + 16) + 28))(LODWORD(dispersion), COERCE_FLOAT(LODWORD(v22)));
  if ( *(float *)(a2 + 80) <= 0.0 )
    survarium::player_stamina::spend(
      (survarium::player_stamina *)((char *)&loc_1106F + *(_DWORD *)(a2 + 60) + 1),
      *(float *)((char *)&locret_110FB + *(_DWORD *)(a2 + 60) + 1));
  v8 = (__m128)*(unsigned int *)(a2 + 88);
  v8.m128_f32[0] = v8.m128_f32[0] * 1.5707964;
  v9 = (__m128i)_mm_cvtps_pd(v8);
  __libm_sse2_sin(v9);
  *(float *)v9.m128i_i32 = *(double *)v9.m128i_i64;
  v21 = *(float *)v9.m128i_i32;
  v10 = s_bm_current_air_resistance - *(float *)v9.m128i_i32;
  v20 = *(float *)(a2 + 84);
  *(float *)v9.m128i_i32 = (float)((float)((float)(v20
                                                 / (float)(v7[2]
                                                         / (float)(s_bm_current_air_resistance
                                                                 - (float)(v6[7] * dispersion))))
                                         * (float)(s_bm_current_air_resistance - *(float *)v9.m128i_i32))
                                 * v22)
                         + *(float *)(a2 + 64);
  *(_DWORD *)(a2 + 64) = v9.m128i_i32[0];
  v23 = *(float *)v9.m128i_i32 * 6.2831855;
  v19 = v10;
  __libm_sse2_cos(v17);
  v18 = (float)(*(float *)v9.m128i_i32 * 6.2831855) * *v7;
  v11 = (__m128)COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * 6.2831855);
  v11.m128_f32[0] = v23 * 2.0;
  v12 = (__m128i)_mm_cvtps_pd(v11);
  __libm_sse2_sin(v12);
  v13 = *(double *)v12.m128i_i64;
  v14 = v13 * v7[1];
  v15 = (float)((float)((float)((float)(v6[6] * dispersion) + s_bm_current_air_resistance) - *(float *)(a2 + 76)) * v20)
      + *(float *)(a2 + 76);
  *(float *)(a2 + 76) = v15;
  v16 = (float)(v6[3] * v21) + (float)((float)(v15 * v14) * v19);
  *(float *)(a2 + 68) = (float)(v21 * 0.0) + (float)((float)(v15 * v18) * v19);
  *(float *)(a2 + 72) = v16;
}
