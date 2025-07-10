void __fastcall gjkepa2_impl::Initialize(
        const btTransform *wtrs1,
        gjkepa2_impl::MinkowskiDiff *shape,
        const btConvexShape *shape0,
        const btTransform *wtrs0,
        const btConvexShape *shape1,
        btGjkEpaSolver2::sResults *results,
        bool withmargins)
{
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  unsigned int v12; // xmm3_4
  unsigned int v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  unsigned int v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // [esp+0h] [ebp-6Ch]
  float v37; // [esp+0h] [ebp-6Ch]
  float v38; // [esp+0h] [ebp-6Ch]
  float v39; // [esp+4h] [ebp-68h]
  float v40; // [esp+8h] [ebp-64h]
  unsigned int v41; // [esp+Ch] [ebp-60h]
  float v42; // [esp+Ch] [ebp-60h]
  float v43; // [esp+10h] [ebp-5Ch]
  unsigned __int64 v44; // [esp+14h] [ebp-58h]
  unsigned int v45; // [esp+1Ch] [ebp-50h]
  unsigned __int64 v46; // [esp+20h] [ebp-4Ch]
  unsigned int v47; // [esp+28h] [ebp-44h]
  btVector3 v48; // [esp+2Ch] [ebp-40h]
  unsigned __int64 v49; // [esp+3Ch] [ebp-30h]
  btVector3 v50; // [esp+4Ch] [ebp-20h]

  results->status = Separated;
  results->witnesses[1].mVec128.m128_u64[0] = 0;
  results->witnesses[0].mVec128.m128_u64[0] = 0;
  results->witnesses[1].mVec128.m128_u64[1] = 0;
  results->witnesses[0].mVec128.m128_u64[1] = 0;
  v8 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[2];
  v9 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[2];
  v10 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v11 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[2];
  *(float *)&v12 = (float)((float)(v9 * v10) + (float)(v8 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v11 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v13 = (float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v9)
                         + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[1] * v8))
                 + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v11);
  v14 = (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v9)
      + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v8);
  v15 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v11;
  v39 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[1];
  v16 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[1];
  *(float *)&v17 = v14 + v15;
  v18 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[1];
  *((float *)&v44 + 1) = (float)((float)(v16 * v10) + (float)(v39 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[2]))
                       + (float)(v18 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  v19 = (float)(v16 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
      + (float)(v39 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]);
  shape->m_shapes[0] = shape0;
  v36 = v19;
  v20 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
  shape->m_shapes[1] = shape1;
  *(float *)&v44 = v36 + (float)(v18 * v20);
  v21 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[0];
  v37 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[0];
  *(float *)&v41 = (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0]
                                 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(v37 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v21 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  *((float *)&v49 + 1) = (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0]
                                       * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
                               + (float)(v37 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v21 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]);
  v50.mVec128.m128_f32[0] = (float)((float)(v16 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0])
                                  + (float)(v39 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0]))
                          + (float)(v18 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0]);
  *(unsigned __int64 *)((char *)v50.mVec128.m128_u64 + 4) = v44;
  *(float *)&v49 = (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0]
                                 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v37 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0]))
                 + (float)(v21 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0]);
  shape->m_toshape1.m_el[0].mVec128.m128_u64[0] = v49;
  shape->m_toshape1.m_el[0].mVec128.m128_u64[1] = v41;
  v50.mVec128.m128_i32[3] = 0;
  shape->m_toshape1.m_el[1] = (btVector3)v50.mVec128;
  shape->m_toshape1.m_el[2].mVec128.m128_u64[0] = __PAIR64__(v13, v17);
  shape->m_toshape1.m_el[2].mVec128.m128_u64[1] = v12;
  v22 = wtrs1->m_origin.mVec128.m128_f32[1] - wtrs0->m_origin.mVec128.m128_f32[1];
  v23 = wtrs1->m_origin.mVec128.m128_f32[2] - wtrs0->m_origin.mVec128.m128_f32[2];
  v24 = wtrs1->m_origin.mVec128.m128_f32[0] - wtrs0->m_origin.mVec128.m128_f32[0];
  v25 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[2];
  v48.mVec128.m128_f32[0] = (float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v22)
                                  + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v23))
                          + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v24);
  v26 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2];
  v48.mVec128.m128_f32[1] = (float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[1] * v22)
                                  + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v23))
                          + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v24);
  v27 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[2];
  v28 = (float)(v25 * v22) + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v23);
  v29 = v26 * v24;
  v30 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[2];
  v48.mVec128.m128_f32[2] = v28 + v29;
  v31 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[2];
  *(float *)&v47 = (float)((float)(v30 * v26) + (float)(v31 * v25))
                 + (float)(v27 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  v38 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[1];
  v32 = wtrs1->m_basis.m_el[0].mVec128.m128_f32[1];
  v43 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[1];
  *((float *)&v46 + 1) = (float)((float)(v32 * v26) + (float)(v43 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[2]))
                       + (float)(v38 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  v42 = wtrs1->m_basis.m_el[2].mVec128.m128_f32[0];
  v40 = wtrs1->m_basis.m_el[1].mVec128.m128_f32[0];
  v48.mVec128.m128_i32[3] = 0;
  *(float *)&v46 = (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0] * v26) + (float)(v40 * v25))
                 + (float)(v42 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v45 = (float)((float)(v30 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v31 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(v27 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]);
  v33 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[0];
  v34 = (float)(v30 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v31 * v33);
  v35 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[0];
  v50.mVec128.m128_u64[0] = __PAIR64__(
                              (float)((float)(v32 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
                                    + (float)(v43 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]))
                            + (float)(v38 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]),
                              (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0]
                                            * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1])
                                    + (float)(v40 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[1]))
                            + (float)(v42 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[1]));
  *(float *)&v49 = (float)((float)(wtrs1->m_basis.m_el[0].mVec128.m128_f32[0]
                                 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v40 * v33))
                 + (float)(v42 * v35);
  *((float *)&v49 + 1) = (float)((float)(v32 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v43 * v33))
                       + (float)(v38 * v35);
  shape->m_toshape0.m_basis.m_el[0].mVec128.m128_u64[0] = v49;
  shape->m_toshape0.m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v34 + (float)(v27 * v35));
  shape->m_toshape0.m_basis.m_el[1].mVec128.m128_u64[0] = v50.mVec128.m128_u64[0];
  shape->m_toshape0.m_basis.m_el[1].mVec128.m128_u64[1] = v45;
  shape->m_toshape0.m_basis.m_el[2].mVec128.m128_u64[0] = v46;
  shape->m_toshape0.m_basis.m_el[2].mVec128.m128_u64[1] = v47;
  shape->m_toshape0.m_origin = (btVector3)v48.mVec128;
  if ( withmargins )
    shape->Ls = btConvexShape::localGetSupportVertexNonVirtual;
  else
    shape->Ls = btConvexShape::localGetSupportVertexWithoutMarginNonVirtual;
}
