void __usercall btGImpactQuantizedBvh::find_collision(
        const btTransform *trans1@<eax>,
        btTransform *a2@<ecx>,
        btGImpactQuantizedBvh *boxset0,
        const btTransform *trans0,
        btGImpactQuantizedBvh *boxset1,
        btPairSet *collision_pairs)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  int v20; // xmm2_4
  float v21; // xmm2_4
  btMatrix3x3 *p_m_AR; // eax
  int v23; // esi
  float *v24; // ecx
  int v25; // edx
  const float *v26; // [esp+0h] [ebp-100h]
  float v27; // [esp+10h] [ebp-F0h] BYREF
  float v28; // [esp+14h] [ebp-ECh] BYREF
  float v29; // [esp+18h] [ebp-E8h]
  float v30; // [esp+1Ch] [ebp-E4h]
  btTransform v31; // [esp+20h] [ebp-E0h] BYREF
  float v32; // [esp+64h] [ebp-9Ch] BYREF
  float v33; // [esp+68h] [ebp-98h] BYREF
  float v34; // [esp+6Ch] [ebp-94h] BYREF
  float v35; // [esp+70h] [ebp-90h] BYREF
  float v36; // [esp+74h] [ebp-8Ch] BYREF
  float v37; // [esp+78h] [ebp-88h] BYREF
  float v38; // [esp+7Ch] [ebp-84h] BYREF
  unsigned __int64 v39; // [esp+80h] [ebp-80h]
  unsigned __int64 v40; // [esp+88h] [ebp-78h]
  BT_BOX_BOX_TRANSFORM_CACHE trans_cache_1to0; // [esp+90h] [ebp-70h] BYREF

  if ( boxset0->m_box_tree.m_num_nodes && boxset1->m_box_tree.m_num_nodes )
  {
    btTransform::inverse(a2, (int)trans0, &v31);
    v7 = trans1->m_origin.mVec128.m128_f32[2];
    v8 = trans1->m_origin.mVec128.m128_f32[0];
    v9 = trans1->m_basis.m_el[1].mVec128.m128_f32[1];
    v10 = trans1->m_origin.mVec128.m128_f32[1];
    *(float *)&v39 = (float)((float)((float)(v7 * v31.m_basis.m_el[0].mVec128.m128_f32[2])
                                   + (float)(v8 * v31.m_basis.m_el[0].mVec128.m128_f32[0]))
                           + (float)(v10 * v31.m_basis.m_el[0].mVec128.m128_f32[1]))
                   + v31.m_origin.mVec128.m128_f32[0];
    *(float *)&v40 = (float)((float)((float)(v8 * v31.m_basis.m_el[2].mVec128.m128_f32[0])
                                   + (float)(v10 * v31.m_basis.m_el[2].mVec128.m128_f32[1]))
                           + (float)(v7 * v31.m_basis.m_el[2].mVec128.m128_f32[2]))
                   + v31.m_origin.mVec128.m128_f32[2];
    v11 = (float)((float)(v8 * v31.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v10 * v31.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v7 * v31.m_basis.m_el[1].mVec128.m128_f32[2]);
    v12 = trans1->m_basis.m_el[1].mVec128.m128_f32[2];
    HIDWORD(v40) = 0;
    v13 = trans1->m_basis.m_el[0].mVec128.m128_f32[2];
    v30 = v9;
    *((float *)&v39 + 1) = v11 + v31.m_origin.mVec128.m128_f32[1];
    v14 = trans1->m_basis.m_el[2].mVec128.m128_f32[2];
    v15 = trans1->m_basis.m_el[2].mVec128.m128_f32[1];
    v38 = (float)((float)(v13 * v31.m_basis.m_el[2].mVec128.m128_f32[0])
                + (float)(v12 * v31.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v14 * v31.m_basis.m_el[2].mVec128.m128_f32[2]);
    v16 = trans1->m_basis.m_el[0].mVec128.m128_f32[1];
    v27 = v15;
    v17 = (float)(v16 * v31.m_basis.m_el[2].mVec128.m128_f32[0]) + (float)(v9 * v31.m_basis.m_el[2].mVec128.m128_f32[1]);
    v18 = trans1->m_basis.m_el[1].mVec128.m128_f32[0];
    v19 = v17 + (float)(v15 * v31.m_basis.m_el[2].mVec128.m128_f32[2]);
    v20 = trans1->m_basis.m_el[2].mVec128.m128_i32[0];
    v37 = v19;
    v28 = v18;
    v29 = *(float *)&v20;
    v21 = trans1->m_basis.m_el[0].mVec128.m128_f32[0];
    v32 = (float)((float)(trans1->m_basis.m_el[0].mVec128.m128_f32[0] * v31.m_basis.m_el[2].mVec128.m128_f32[0])
                + (float)(v18 * v31.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v29 * v31.m_basis.m_el[2].mVec128.m128_f32[2]);
    v35 = (float)((float)(v13 * v31.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v12 * v31.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v14 * v31.m_basis.m_el[1].mVec128.m128_f32[2]);
    v34 = (float)((float)(v13 * v31.m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v12 * v31.m_basis.m_el[0].mVec128.m128_f32[1]))
        + (float)(v14 * v31.m_basis.m_el[0].mVec128.m128_f32[2]);
    v36 = (float)((float)(v16 * v31.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v30 * v31.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v27 * v31.m_basis.m_el[1].mVec128.m128_f32[2]);
    v33 = (float)((float)(v21 * v31.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v18 * v31.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v29 * v31.m_basis.m_el[1].mVec128.m128_f32[2]);
    v27 = (float)((float)(v16 * v31.m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v30 * v31.m_basis.m_el[0].mVec128.m128_f32[1]))
        + (float)(v27 * v31.m_basis.m_el[0].mVec128.m128_f32[2]);
    v28 = (float)((float)(v21 * v31.m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v18 * v31.m_basis.m_el[0].mVec128.m128_f32[1]))
        + (float)(v29 * v31.m_basis.m_el[0].mVec128.m128_f32[2]);
    btMatrix3x3::setValue((btMatrix3x3 *)&v28, (int)&v31, &v27, &v34, &v33, &v36, &v35, &v32, &v37, &v38, v26);
    trans_cache_1to0.m_T1to0.mVec128.m128_u64[0] = v39;
    trans_cache_1to0.m_T1to0.mVec128.m128_u64[1] = v40;
    trans_cache_1to0.m_R1to0 = v31.m_basis;
    p_m_AR = &trans_cache_1to0.m_AR;
    v23 = 3;
    do
    {
      v24 = (float *)p_m_AR;
      v25 = 3;
      do
      {
        *v24 = COERCE_FLOAT(*(_DWORD *)(v24 - 12) & _mask__AbsFloat_) + 0.000001;
        ++v24;
        --v25;
      }
      while ( v25 );
      p_m_AR = (btMatrix3x3 *)((char *)p_m_AR + 16);
      --v23;
    }
    while ( v23 );
    find_quantized_collision_pairs_recursive(boxset0, boxset1, collision_pairs, &trans_cache_1to0, 0, 0, 1);
  }
}
