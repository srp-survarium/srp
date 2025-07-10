void __usercall btGImpactQuantizedBvh::find_collision(
        const btTransform *trans1@<eax>,
        btGImpactQuantizedBvh *boxset0,
        const btTransform *trans0,
        btGImpactQuantizedBvh *boxset1,
        btPairSet *collision_pairs)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  int v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  unsigned int v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  btVector3 v20; // xmm0
  __m128i si128; // xmm0
  __m128i v22; // xmm0
  btMatrix3x3 *p_m_AR; // ebx
  btMatrix3x3 *v24; // esi
  int v25; // edi
  long double v26; // st7
  float v27; // [esp+80h] [ebp-E0h]
  int v28; // [esp+80h] [ebp-E0h]
  float v29; // [esp+84h] [ebp-DCh]
  float v30; // [esp+88h] [ebp-D8h]
  float v31; // [esp+8Ch] [ebp-D4h]
  btTransform v32; // [esp+90h] [ebp-D0h] BYREF
  float v33; // [esp+D0h] [ebp-90h]
  float v34; // [esp+D4h] [ebp-8Ch]
  float v35; // [esp+D8h] [ebp-88h]
  float v36; // [esp+DCh] [ebp-84h]
  __m128i v37; // [esp+E0h] [ebp-80h] BYREF
  BT_BOX_BOX_TRANSFORM_CACHE trans_cache_1to0; // [esp+F0h] [ebp-70h] BYREF

  if ( boxset0->m_box_tree.m_num_nodes && boxset1->m_box_tree.m_num_nodes )
  {
    btTransform::inverse(trans0, &v32);
    v6 = trans1->m_origin.mVec128.m128_f32[0];
    v7 = trans1->m_origin.mVec128.m128_f32[2];
    v8 = trans1->m_origin.mVec128.m128_f32[1] * v32.m_basis.m_el[1].mVec128.m128_f32[1];
    v9 = trans1->m_origin.mVec128.m128_f32[1] * v32.m_basis.m_el[2].mVec128.m128_f32[1];
    *(float *)v37.m128i_i32 = (float)((float)((float)(v6 * v32.m_basis.m_el[0].mVec128.m128_f32[0])
                                            + (float)(trans1->m_origin.mVec128.m128_f32[1]
                                                    * v32.m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(v7 * v32.m_basis.m_el[0].mVec128.m128_f32[2]))
                            + v32.m_origin.mVec128.m128_f32[0];
    *(float *)&v37.m128i_i32[2] = (float)((float)((float)(v6 * v32.m_basis.m_el[2].mVec128.m128_f32[0]) + v9)
                                        + (float)(v7 * v32.m_basis.m_el[2].mVec128.m128_f32[2]))
                                + v32.m_origin.mVec128.m128_f32[2];
    *(float *)&v10 = (float)((float)((float)(v6 * v32.m_basis.m_el[1].mVec128.m128_f32[0]) + v8)
                           + (float)(v7 * v32.m_basis.m_el[1].mVec128.m128_f32[2]))
                   + v32.m_origin.mVec128.m128_f32[1];
    v11 = trans1->m_basis.m_el[1].mVec128.m128_f32[2];
    v37.m128i_i32[3] = 0;
    v12 = trans1->m_basis.m_el[0].mVec128.m128_f32[2];
    v37.m128i_i32[1] = v10;
    v13 = trans1->m_basis.m_el[2].mVec128.m128_f32[2];
    *(float *)&v14 = (float)((float)(v12 * v32.m_basis.m_el[2].mVec128.m128_f32[0])
                           + (float)(v11 * v32.m_basis.m_el[2].mVec128.m128_f32[1]))
                   + (float)(v13 * v32.m_basis.m_el[2].mVec128.m128_f32[2]);
    v29 = trans1->m_basis.m_el[2].mVec128.m128_f32[1];
    v30 = trans1->m_basis.m_el[1].mVec128.m128_f32[1];
    v15 = trans1->m_basis.m_el[0].mVec128.m128_f32[1];
    v34 = (float)((float)(v15 * v32.m_basis.m_el[2].mVec128.m128_f32[0])
                + (float)(v30 * v32.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v29 * v32.m_basis.m_el[2].mVec128.m128_f32[2]);
    v27 = trans1->m_basis.m_el[2].mVec128.m128_f32[0];
    v31 = trans1->m_basis.m_el[1].mVec128.m128_f32[0];
    v16 = trans1->m_basis.m_el[0].mVec128.m128_f32[0];
    v36 = (float)((float)(trans1->m_basis.m_el[0].mVec128.m128_f32[0] * v32.m_basis.m_el[2].mVec128.m128_f32[0])
                + (float)(v31 * v32.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v27 * v32.m_basis.m_el[2].mVec128.m128_f32[2]);
    v35 = (float)((float)(v12 * v32.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v11 * v32.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v13 * v32.m_basis.m_el[1].mVec128.m128_f32[2]);
    v33 = (float)((float)(v15 * v32.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v30 * v32.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v29 * v32.m_basis.m_el[1].mVec128.m128_f32[2]);
    v17 = v32.m_basis.m_el[0].mVec128.m128_f32[1];
    v18 = (float)(v12 * v32.m_basis.m_el[0].mVec128.m128_f32[0])
        + (float)(v11 * v32.m_basis.m_el[0].mVec128.m128_f32[1]);
    v19 = v32.m_basis.m_el[0].mVec128.m128_f32[2];
    v32.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(v15 * v32.m_basis.m_el[0].mVec128.m128_f32[0])
                                                    + (float)(v30 * v32.m_basis.m_el[0].mVec128.m128_f32[1]))
                                            + (float)(v29 * v32.m_basis.m_el[0].mVec128.m128_f32[2]);
    v32.m_basis.m_el[1].mVec128.m128_f32[0] = (float)((float)(v16 * v32.m_basis.m_el[1].mVec128.m128_f32[0])
                                                    + (float)(v31 * v32.m_basis.m_el[1].mVec128.m128_f32[1]))
                                            + (float)(v27 * v32.m_basis.m_el[1].mVec128.m128_f32[2]);
    v32.m_basis.m_el[0].mVec128.m128_f32[2] = v18 + (float)(v13 * v32.m_basis.m_el[0].mVec128.m128_f32[2]);
    v32.m_basis.m_el[1].mVec128.m128_f32[1] = v33;
    v32.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
    v20.mVec128 = (__m128)_mm_load_si128(&v37);
    v32.m_basis.m_el[1].mVec128.m128_u64[1] = LODWORD(v35);
    trans_cache_1to0.m_T1to0 = (btVector3)v20.mVec128;
    v32.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v16 * v32.m_basis.m_el[0].mVec128.m128_f32[0])
                                                    + (float)(v31 * v17))
                                            + (float)(v27 * v19);
    si128 = _mm_load_si128((const __m128i *)&v32);
    v32.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v34), LODWORD(v36));
    trans_cache_1to0.m_R1to0.m_el[0] = (btVector3)si128;
    v22 = _mm_load_si128((const __m128i *)&v32.m_basis.m_el[1]);
    v32.m_basis.m_el[2].mVec128.m128_u64[1] = v14;
    trans_cache_1to0.m_R1to0.m_el[1] = (btVector3)v22;
    trans_cache_1to0.m_R1to0.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v32.m_basis.m_el[2]);
    p_m_AR = &trans_cache_1to0.m_AR;
    v28 = 3;
    do
    {
      v24 = p_m_AR;
      v25 = 3;
      do
      {
        v26 = fabsf(v24[-1].m_el[0].mVec128.m128_f32[0]);
        v24 = (btMatrix3x3 *)((char *)v24 + 4);
        --v25;
        v24[-1].m_el[2].mVec128.m128_f32[3] = v26 + 0.000001;
      }
      while ( v25 );
      p_m_AR = (btMatrix3x3 *)((char *)p_m_AR + 16);
      --v28;
    }
    while ( v28 );
    find_quantized_collision_pairs_recursive(boxset0, boxset1, collision_pairs, &trans_cache_1to0, 0, 0, 1);
  }
}
