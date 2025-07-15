void __usercall gjkepa2_impl::Initialize(
        btGjkEpaSolver2::sResults *results@<eax>,
        const float *a2@<edi>,
        const btConvexShape *shape0,
        const btTransform *wtrs0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        gjkepa2_impl::MinkowskiDiff *shape,
        bool withmargins)
{
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm7_4
  unsigned int v37; // xmm4_4
  unsigned int v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  float v44; // xmm3_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm5_4
  float v48; // xmm3_4
  float v49; // xmm0_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm6_4
  float v54; // xmm5_4
  float v55; // xmm2_4
  float v56; // xmm6_4
  float v57; // xmm5_4
  float v58; // xmm6_4
  float v59; // xmm5_4
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm6_4
  float v63; // xmm5_4
  float v64; // xmm6_4
  float v65; // xmm0_4
  float v66; // xmm3_4
  const float *v67; // [esp-Ch] [ebp-80h]
  float v68; // [esp+8h] [ebp-6Ch] BYREF
  float v69; // [esp+Ch] [ebp-68h] BYREF
  float v70; // [esp+10h] [ebp-64h] BYREF
  btMatrix3x3 v71; // [esp+14h] [ebp-60h] BYREF
  btMatrix3x3 v72; // [esp+44h] [ebp-30h] BYREF

  results->status = Separated;
  memset(&v71.m_el[2], 0, sizeof(v71.m_el[2]));
  results->witnesses[1].mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)results->witnesses[1].mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v71.m_el[2].mVec128.m128_u64
                                                                                                  + 4);
  results->witnesses[1].mVec128.m128_i32[3] = v71.m_el[2].mVec128.m128_i32[3];
  results->witnesses[0] = v71.m_el[2];
  v9 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v10 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[2];
  v11 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[2];
  shape->m_shapes[0] = shape0;
  shape->m_shapes[1] = shape1;
  v12 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[2];
  v13 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[2];
  v14 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[2];
  v15 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
  v71.m_el[0].mVec128.m128_f32[0] = (float)((float)(v13 * v9) + (float)(v12 * v10)) + (float)(v14 * v11);
  v16 = (float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v13) + (float)(v15 * v12))
      + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v14);
  v17 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * wtrs1->m_basis.m_el[0].mVec128.m128_f32[2];
  v18 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[2];
  v70 = v16;
  v19 = v17 + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v18);
  v20 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[1];
  v21 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v14;
  v22 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[1];
  v23 = v19 + v21;
  v24 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[1];
  v69 = v23;
  v25 = (float)((float)(v22 * v9) + (float)(v20 * v10)) + (float)(v24 * v11);
  v26 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[1];
  v68 = v25;
  v27 = (float)(v22 * v26) + (float)(v20 * v15);
  v28 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
  v29 = v27 + (float)(v24 * v28);
  v30 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v31 = (float)(v22 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0])
      + (float)(v20 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0]);
  v32 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[0];
  v33 = v31 + (float)(v24 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0]);
  v34 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[0];
  v71.m_el[0].mVec128.m128_f32[2] = v33;
  v35 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[0];
  v71.m_el[0].mVec128.m128_f32[1] = v29;
  v36 = (float)((float)(v35 * v30) + (float)(v32 * v10)) + (float)(v34 * v11);
  *(float *)&v37 = (float)((float)(v35 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v32 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(v34 * v28);
  *(float *)&v38 = (float)((float)(v35 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v32 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0]))
                 + (float)(v34 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0]);
  v71.m_el[0].mVec128.m128_f32[3] = v36;
  v71.m_el[1].mVec128.m128_u64[0] = __PAIR64__(v38, v37);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v71.m_el[1].m_floats[1],
    (int)&v72,
    v71.m_el[1].mVec128.m128_f32,
    &v71.m_el[0].mVec128.m128_f32[3],
    &v71.m_el[0].mVec128.m128_f32[2],
    &v71.m_el[0].mVec128.m128_f32[1],
    &v68,
    &v69,
    &v70,
    (const float *)&v71,
    a2);
  shape->m_toshape1 = v72;
  v39 = wtrs1->m_origin.mVec128.m128_f32[1] - wtrs0->m_origin.mVec128.m128_f32[1];
  v40 = wtrs1->m_origin.mVec128.m128_f32[2] - wtrs0->m_origin.mVec128.m128_f32[2];
  v41 = wtrs1->m_origin.mVec128.m128_f32[0] - wtrs0->m_origin.mVec128.m128_f32[0];
  v42 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[2];
  v43 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v44 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1] * v39;
  v45 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[1];
  v71.m_el[2].mVec128.m128_f32[0] = (float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v40)
                                          + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v39))
                                  + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v41);
  v46 = (float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v40) + v44) + (float)(v45 * v41);
  v47 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[2];
  v71.m_el[2].mVec128.m128_f32[2] = (float)((float)(v42 * v40) + (float)(v47 * v39)) + (float)(v43 * v41);
  v48 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[2];
  v71.m_el[2].mVec128.m128_i32[3] = 0;
  v49 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[2];
  v71.m_el[2].mVec128.m128_f32[1] = v46;
  v50 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[2];
  v71.m_el[1].mVec128.m128_f32[1] = (float)((float)(v49 * v43) + (float)(v48 * v42)) + (float)(v50 * v47);
  v68 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[1];
  v69 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[1];
  v51 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[1];
  v52 = (float)(v51 * v43) + (float)(v68 * v42);
  v53 = v69 * v47;
  v54 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v71.m_el[1].mVec128.m128_f32[0] = v52 + v53;
  v70 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[0];
  v71.m_el[0].mVec128.m128_i32[0] = wtrs1->m_basis.m_el[1].mVec128.m128_i32[0];
  v55 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[0];
  v56 = (float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0] * v54) + (float)(v70 * v42);
  v57 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[1];
  v71.m_el[0].mVec128.m128_f32[3] = v56
                                  + (float)(v71.m_el[0].mVec128.m128_f32[0] * wtrs0->m_basis.m_el[1].mVec128.m128_f32[2]);
  v58 = v49 * v57;
  v59 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[1];
  v71.m_el[0].mVec128.m128_f32[2] = (float)(v58 + (float)(v48 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]))
                                  + (float)(v50 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]);
  v60 = v51 * v59;
  v61 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[1];
  v71.m_el[0].mVec128.m128_f32[1] = (float)(v60 + (float)(v68 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]))
                                  + (float)(v69 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]);
  v62 = v55 * v61;
  v63 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[0];
  v71.m_el[1].mVec128.m128_f32[2] = (float)(v62 + (float)(v70 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]))
                                  + (float)(v71.m_el[0].mVec128.m128_f32[0] * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]);
  v64 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[0];
  v65 = (float)(v49 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v48 * v63);
  v66 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[0];
  v71.m_el[1].mVec128.m128_f32[3] = v65 + (float)(v50 * v66);
  v69 = (float)((float)(v51 * v64) + (float)(v68 * v63)) + (float)(v69 * v66);
  v71.m_el[0].mVec128.m128_f32[0] = (float)((float)(v55 * v64) + (float)(v70 * v63))
                                  + (float)(v71.m_el[0].mVec128.m128_f32[0] * v66);
  btMatrix3x3::setValue(
    &v71,
    (int)&v72,
    &v69,
    &v71.m_el[1].mVec128.m128_f32[3],
    &v71.m_el[1].mVec128.m128_f32[2],
    &v71.m_el[0].mVec128.m128_f32[1],
    &v71.m_el[0].mVec128.m128_f32[2],
    &v71.m_el[0].mVec128.m128_f32[3],
    v71.m_el[1].mVec128.m128_f32,
    &v71.m_el[1].mVec128.m128_f32[1],
    v67);
  shape->m_toshape0.m_basis = v72;
  shape->m_toshape0.m_origin = v71.m_el[2];
  if ( withmargins )
    shape->Ls = btConvexShape::localGetSupportVertexNonVirtual;
  else
    shape->Ls = btConvexShape::localGetSupportVertexWithoutMarginNonVirtual;
}
