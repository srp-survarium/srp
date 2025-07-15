void __usercall vostok::animation::get_spline_params<vostok::animation::bi_spline_channel_animation_baked,float,1>(
        const vostok::animation::bi_spline_channel_animation_baked *cv@<eax>,
        unsigned int index@<edx>,
        float *point_factors)
{
  unsigned int m_knots_count; // ecx
  unsigned int v4; // esi
  float v5; // xmm0_4
  unsigned int v6; // esi
  unsigned int v7; // esi
  float v8; // xmm0_4
  unsigned int v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // esi
  float v12; // xmm2_4
  unsigned int v13; // esi
  float v14; // xmm2_4
  unsigned int v15; // esi
  float v16; // xmm0_4
  unsigned int v17; // edi
  unsigned int v18; // esi
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  unsigned int v26; // esi
  float v27; // xmm5_4
  float v28; // xmm0_4
  unsigned int v29; // xmm1_4
  unsigned int v30; // esi
  float v31; // xmm1_4
  unsigned int v32; // esi
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // [esp+Ch] [ebp-60h]
  float v38; // [esp+10h] [ebp-5Ch]
  float v39; // [esp+18h] [ebp-54h]
  float v40; // [esp+1Ch] [ebp-50h]
  float v41; // [esp+24h] [ebp-48h]
  float v42; // [esp+2Ch] [ebp-40h]
  float v43; // [esp+38h] [ebp-34h]
  float v44; // [esp+3Ch] [ebp-30h]
  float v45; // [esp+44h] [ebp-28h]
  float v46; // [esp+48h] [ebp-24h]
  float v47; // [esp+4Ch] [ebp-20h]
  float v48; // [esp+50h] [ebp-1Ch]
  float v49; // [esp+50h] [ebp-1Ch]
  float v50; // [esp+58h] [ebp-14h]
  float v51; // [esp+5Ch] [ebp-10h]
  float v52; // [esp+60h] [ebp-Ch]
  float v53; // [esp+68h] [ebp-4h]

  m_knots_count = cv->m_knots_count;
  v4 = index - 1;
  if ( index - 1 >= cv->m_knots_count )
    v4 = m_knots_count - 1;
  v5 = *(float *)&cv[2 * v4 + 1].m_knots_count;
  v6 = index - 2;
  if ( index - 2 >= m_knots_count )
    v6 = m_knots_count - 1;
  v37 = v5 - *(float *)&cv[2 * v6 + 1].m_knots_count;
  v7 = index;
  if ( index >= m_knots_count )
    v7 = m_knots_count - 1;
  v8 = *(float *)&cv[2 * v7 + 1].m_knots_count;
  v9 = index - 1;
  if ( index - 1 >= m_knots_count )
    v9 = m_knots_count - 1;
  v10 = index + 1;
  v38 = v8 - *(float *)&cv[2 * v9 + 1].m_knots_count;
  v11 = index + 1;
  if ( index + 1 >= m_knots_count )
    v11 = m_knots_count - 1;
  v12 = *(float *)&cv[2 * v11 + 1].m_knots_count;
  v13 = index;
  if ( index >= m_knots_count )
    v13 = m_knots_count - 1;
  v14 = v12 - *(float *)&cv[2 * v13 + 1].m_knots_count;
  v15 = index + 2;
  if ( index + 2 >= m_knots_count )
    v15 = m_knots_count - 1;
  if ( v10 >= m_knots_count )
    v10 = m_knots_count - 1;
  v16 = *(float *)&cv[2 * v15 + 1].m_knots_count - *(float *)&cv[2 * v10 + 1].m_knots_count;
  v17 = index + 3;
  v39 = v16;
  if ( index + 3 >= m_knots_count )
    v17 = m_knots_count - 1;
  v18 = index + 2;
  if ( index + 2 >= m_knots_count )
    v18 = m_knots_count - 1;
  v19 = s_bm_current_air_resistance / (float)((float)((float)((float)(v14 + v38) + v37) * (float)(v14 + v38)) * v14);
  v20 = v16 + v14;
  v21 = s_bm_current_air_resistance / (float)((float)((float)(v20 + v38) * (float)(v14 + v38)) * v14);
  v48 = (float)((float)(*(float *)&cv[2 * v17 + 1].m_knots_count - *(float *)&cv[2 * v18 + 1].m_knots_count) + v39)
      + v14;
  v50 = s_bm_current_air_resistance / (float)((float)(v48 * v20) * v14);
  v22 = s_bm_current_air_resistance / (float)((float)((float)(v20 + v38) * v20) * v14);
  v45 = (float)(COERCE_FLOAT(LODWORD(v21) ^ _mask__NegFloat_) - v22) - v50;
  v46 = (float)(v22 + v21) + v19;
  v53 = v19;
  LODWORD(v47) = LODWORD(v19) ^ _mask__NegFloat_;
  v23 = (float)((float)((float)(v14 - (float)(v38 * 2.0)) * v21) + (float)((float)(v20 - v38) * v22))
      + (float)(v48 * v50);
  v43 = (float)((float)((float)(v38 - (float)((float)(v14 * 2.0) + v39)) * v21)
              + (float)((float)((float)(v38 + v37) - (float)(v14 * 2.0)) * v19))
      + (float)((float)(v20 * -2.0) * v22);
  v44 = (float)(v19 * v14) * 3.0;
  v41 = (float)((float)((float)((float)(v14 * v38) * 2.0) - (float)(v38 * v38)) * v21)
      + (float)((float)(v20 * v38) * v22);
  v24 = (float)((float)((float)((float)(v14 * v14) - (float)((float)((float)(v38 + v37) * v14) * 2.0)) * v19)
              + (float)((float)((float)((float)(v14 - v38) * v20) - (float)(v14 * v38)) * v21))
      + (float)((float)(v20 * v20) * v22);
  v25 = (float)(v14 * v14) * v53;
  v26 = index - 3;
  v27 = (float)((float)(v38 * v38) * v14) * v21;
  v42 = v25 * -3.0;
  v28 = (float)((float)((float)(v20 * v14) * v38) * v21)
      + (float)((float)((float)(v38 + v37) * (float)(v14 * v14)) * v53);
  v40 = v25 * v14;
  if ( index - 3 >= m_knots_count )
    v26 = m_knots_count - 1;
  v29 = cv[2 * v26 + 2].m_knots_count;
  v30 = index - 2;
  v49 = *(float *)&v29;
  if ( index - 2 >= m_knots_count )
    v30 = m_knots_count - 1;
  v31 = *(float *)&cv[2 * v30 + 2].m_knots_count;
  v32 = index - 1;
  v52 = v31;
  if ( index - 1 >= m_knots_count )
    v32 = m_knots_count - 1;
  v51 = *(float *)&cv[2 * v32 + 2].m_knots_count;
  if ( index >= m_knots_count )
    index = m_knots_count - 1;
  v33 = *(float *)&cv[2 * index + 2].m_knots_count;
  v34 = (float)((float)(v46 * v31) + (float)(v45 * *(float *)&cv[2 * v32 + 2].m_knots_count)) + (float)(v47 * v49);
  v35 = v33 * v50;
  v36 = v33 * 0.0;
  point_factors[3] = v34 + v35;
  point_factors[2] = (float)((float)((float)(v23 * v51) + (float)(v43 * v52)) + (float)(v44 * v49)) + v36;
  point_factors[1] = (float)((float)((float)(v41 * v51) + (float)(v24 * v52)) + (float)(v42 * v49)) + v36;
  *point_factors = (float)((float)((float)(v27 * v51) + (float)(v28 * v52)) + (float)(v40 * v49)) + v36;
}
