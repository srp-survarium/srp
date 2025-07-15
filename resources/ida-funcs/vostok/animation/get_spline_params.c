void __fastcall vostok::animation::get_spline_params<vostok::animation::bi_spline_channel_animation_baked,float,1>(
        const vostok::animation::bi_spline_channel_animation_baked *cv,
        unsigned int index,
        float *point_factors)
{
  unsigned int m_knots_count; // eax
  unsigned int v4; // ebp
  unsigned int v5; // esi
  float v6; // xmm4_4
  unsigned int v7; // esi
  float v8; // xmm4_4
  unsigned int v9; // esi
  float v10; // xmm2_4
  unsigned int v11; // esi
  float v12; // xmm2_4
  unsigned int v13; // esi
  unsigned int v14; // edi
  float v15; // xmm0_4
  unsigned int v16; // edi
  float v17; // xmm0_4
  unsigned int v18; // ebx
  float v19; // xmm1_4
  unsigned int v20; // esi
  float v21; // xmm7_4
  unsigned int v22; // esi
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm5_4
  unsigned int v28; // esi
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  unsigned int v34; // esi
  float v35; // xmm3_4
  unsigned int v36; // esi
  float v37; // xmm2_4
  float p_j1; // [esp+18h] [ebp-48h]
  float k22; // [esp+1Ch] [ebp-44h]
  float v40; // [esp+20h] [ebp-40h]
  float v41; // [esp+30h] [ebp-30h]
  float v42; // [esp+34h] [ebp-2Ch]
  float v43; // [esp+40h] [ebp-20h]
  float v44; // [esp+44h] [ebp-1Ch]
  float v45; // [esp+48h] [ebp-18h]
  float dT; // [esp+4Ch] [ebp-14h]
  float dT_4; // [esp+50h] [ebp-10h]
  float dT_8; // [esp+54h] [ebp-Ch]
  float dT_12; // [esp+58h] [ebp-8h]

  m_knots_count = cv->m_knots_count;
  v4 = index - 1;
  v5 = index - 1;
  if ( index - 1 >= cv->m_knots_count )
    v5 = m_knots_count - 1;
  v6 = *(float *)&cv[2 * v5 + 1].m_knots_count;
  v7 = index - 2;
  if ( index - 2 >= m_knots_count )
    v7 = m_knots_count - 1;
  v8 = v6 - *(float *)&cv[2 * v7 + 1].m_knots_count;
  dT = v8;
  v9 = index;
  if ( index >= m_knots_count )
    v9 = m_knots_count - 1;
  v10 = *(float *)&cv[2 * v9 + 1].m_knots_count;
  v11 = index - 1;
  if ( v4 >= m_knots_count )
    v11 = m_knots_count - 1;
  v12 = v10 - *(float *)&cv[2 * v11 + 1].m_knots_count;
  v13 = index + 1;
  v14 = index + 1;
  if ( index + 1 >= m_knots_count )
    v14 = m_knots_count - 1;
  v15 = *(float *)&cv[2 * v14 + 1].m_knots_count;
  v16 = index;
  if ( index >= m_knots_count )
    v16 = m_knots_count - 1;
  v17 = v15 - *(float *)&cv[2 * v16 + 1].m_knots_count;
  v18 = index + 2;
  if ( index + 2 >= m_knots_count )
    v18 = m_knots_count - 1;
  if ( v13 >= m_knots_count )
    v13 = m_knots_count - 1;
  v19 = *(float *)&cv[2 * v18 + 1].m_knots_count - *(float *)&cv[2 * v13 + 1].m_knots_count;
  v20 = index + 3;
  dT_12 = v19;
  if ( index + 3 >= m_knots_count )
    v20 = m_knots_count - 1;
  v21 = *(float *)&cv[2 * v20 + 1].m_knots_count;
  v22 = index + 2;
  if ( index + 2 >= m_knots_count )
    v22 = m_knots_count - 1;
  v40 = (float)((float)(v21 - *(float *)&cv[2 * v22 + 1].m_knots_count) + v19) + v17;
  v23 = *(float *)&clear_value / (float)((float)((float)((float)(v17 + v12) + v8) * (float)(v17 + v12)) * v17);
  v24 = v19 + v17;
  v25 = *(float *)&clear_value / (float)((float)((float)(v24 + v12) * (float)(v17 + v12)) * v17);
  v26 = *(float *)&clear_value / (float)((float)((float)(v24 + v12) * v24) * v17);
  k22 = *(float *)&clear_value / (float)((float)(v40 * v24) * v17);
  v41 = (float)((float)-v25 - v26) - k22;
  v42 = (float)(v26 + v25) + v23;
  v43 = (float)((float)((float)(v17 - (float)(v12 * 2.0)) * v25) + (float)((float)(v24 - v12) * v26))
      + (float)(v40 * k22);
  v44 = (float)((float)((float)(v12 - (float)((float)(v17 * 2.0) + dT_12)) * v25)
              + (float)((float)((float)(v12 + dT) - (float)(v17 * 2.0)) * v23))
      + (float)((float)(v24 * -2.0) * v26);
  v45 = (float)(v23 * v17) * 3.0;
  dT_4 = (float)((float)((float)((float)(v17 * v12) * 2.0) - (float)(v12 * v12)) * v25)
       + (float)((float)(v24 * v12) * v26);
  dT_8 = (float)((float)((float)((float)(v17 * v17) - (float)((float)((float)(v12 + dT) * v17) * 2.0)) * v23)
               + (float)((float)((float)((float)(v17 - v12) * v24) - (float)(v17 * v12)) * v25))
       + (float)((float)(v24 * v24) * v26);
  v27 = (float)(v17 * v17) * v23;
  v28 = index - 3;
  v29 = v27 * -3.0;
  v30 = (float)((float)(v12 * v12) * v17) * v25;
  v31 = (float)((float)((float)(v24 * v17) * v12) * v25)
      + (float)((float)((float)(v12 + dT) * (float)(v17 * v17)) * v23);
  v32 = v27 * v17;
  if ( index - 3 >= m_knots_count )
    v28 = m_knots_count - 1;
  v33 = *(float *)&cv[2 * v28 + 2].m_knots_count;
  v34 = index - 2;
  if ( index - 2 >= m_knots_count )
    v34 = m_knots_count - 1;
  v35 = *(float *)&cv[2 * v34 + 2].m_knots_count;
  v36 = index - 1;
  if ( v4 >= m_knots_count )
    v36 = m_knots_count - 1;
  p_j1 = *(float *)&cv[2 * v36 + 2].m_knots_count;
  if ( index >= m_knots_count )
    index = m_knots_count - 1;
  v37 = *(float *)&cv[2 * index + 2].m_knots_count * 0.0;
  point_factors[3] = (float)((float)((float)(v42 * v35) + (float)(v41 * *(float *)&cv[2 * v36 + 2].m_knots_count))
                           + (float)((float)-v23 * v33))
                   + (float)(*(float *)&cv[2 * index + 2].m_knots_count * k22);
  point_factors[2] = (float)((float)((float)(v43 * p_j1) + (float)(v44 * v35)) + (float)(v45 * v33)) + v37;
  point_factors[1] = (float)((float)((float)(dT_4 * p_j1) + (float)(dT_8 * v35)) + (float)(v29 * v33)) + v37;
  *point_factors = (float)((float)((float)(v30 * p_j1) + (float)(v31 * v35)) + (float)(v32 * v33)) + v37;
}
