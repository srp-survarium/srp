char __cdecl btGjkEpaSolver2::Penetration(
        const btConvexShape *shape0,
        const btTransform *wtrs0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        btGjkEpaSolver2::sResults *results,
        bool usemargins)
{
  _DWORD *v6; // ecx
  _DWORD *v7; // esi
  gjkepa2_impl::GJK *v8; // ecx
  gjkepa2_impl::GJK *v9; // ecx
  __int32 v10; // eax
  gjkepa2_impl::EPA *v11; // ecx
  gjkepa2_impl::EPA *v12; // ecx
  gjkepa2_impl::MinkowskiDiff *v13; // ecx
  unsigned int v14; // esi
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  unsigned int v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm7_4
  unsigned int v33; // xmm4_4
  float v34; // xmm3_4
  btVector3 v36; // [esp+10h] [ebp-2AB0h] BYREF
  btVector3 v37; // [esp+20h] [ebp-2AA0h] BYREF
  gjkepa2_impl::MinkowskiDiff v38; // [esp+30h] [ebp-2A90h] BYREF
  gjkepa2_impl::GJK v39; // [esp+C0h] [ebp-2A00h] BYREF
  gjkepa2_impl::GJK::sSV v40; // [esp+250h] [ebp-2870h] BYREF
  unsigned int v41; // [esp+274h] [ebp-284Ch]
  float v42; // [esp+280h] [ebp-2840h]
  float v43; // [esp+284h] [ebp-283Ch]
  float v44; // [esp+288h] [ebp-2838h]
  float v45; // [esp+290h] [ebp-2830h]

  v7 = v6;
  gjkepa2_impl::Initialize(results, (const float *)results, shape0, wtrs0, shape1, wtrs1, &v38, usemargins);
  gjkepa2_impl::GJK::GJK(v8, &v39);
  v36.mVec128.m128_i32[0] = *v7 ^ _mask__NegFloat_;
  v36.mVec128.m128_i32[1] = v7[1] ^ _mask__NegFloat_;
  v36.mVec128.m128_u64[1] = (unsigned int)v7[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  v10 = gjkepa2_impl::GJK::Evaluate(v9, &v39, &v38, (int *)&v36) - 1;
  if ( v10 )
  {
    if ( v10 == 1 )
      results->status = GJK_Failed;
    return 0;
  }
  gjkepa2_impl::EPA::EPA(v11, (int)&v40);
  v36.mVec128.m128_i32[0] = *v7 ^ _mask__NegFloat_;
  v36.mVec128.m128_i32[1] = v7[1] ^ _mask__NegFloat_;
  v36.mVec128.m128_u64[1] = (unsigned int)v7[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  if ( gjkepa2_impl::EPA::Evaluate(v12, &v40, &v39, &v36) == 9 )
  {
    results->status = EPA_Failed;
    return 0;
  }
  v14 = 0;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v36.mVec128.m128_u64[0] = 0;
  for ( v36.mVec128.m128_i32[2] = 0; v14 < v41; v36.mVec128.m128_f32[2] = v19 )
  {
    gjkepa2_impl::MinkowskiDiff::Support0(v13, (int)&v38, &v37, (const btVector3 *)v40.d.mVec128.m128_i32[v14 + 1]);
    v15 = (float)(v40.w.mVec128.m128_f32[v14 + 1] * v37.mVec128.m128_f32[0]) + v36.mVec128.m128_f32[0];
    v18 = v40.w.mVec128.m128_f32[v14 + 1];
    v19 = (float)(v18 * v37.mVec128.m128_f32[2]) + v36.mVec128.m128_f32[2];
    v16 = (float)(v18 * v37.mVec128.m128_f32[1]) + v36.mVec128.m128_f32[1];
    ++v14;
    v17 = v19;
    v36.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v16), LODWORD(v15));
  }
  results->status = Penetrating;
  v20 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
  v36.mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v15)
                                          + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v17))
                                  + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v16))
                          + wtrs0->m_origin.mVec128.m128_f32[0];
  v21 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v17) + (float)(v20 * v16))
              + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v15))
      + wtrs0->m_origin.mVec128.m128_f32[1];
  v22 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
  v36.mVec128.m128_f32[1] = v21;
  *(float *)&v23 = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v17) + (float)(v22 * v16))
                         + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v15))
                 + wtrs0->m_origin.mVec128.m128_f32[2];
  v24 = v42;
  v36.mVec128.m128_u64[1] = v23;
  v25 = v45;
  results->witnesses[0] = (btVector3)v36.mVec128;
  v36.mVec128.m128_f32[0] = v24 * v25;
  v26 = v43;
  v27 = v15 - (float)(v24 * v25);
  v36.mVec128.m128_f32[1] = v43 * v25;
  v28 = v16 - (float)(v43 * v25);
  v29 = v17 - (float)(v44 * v25);
  v36.mVec128.m128_f32[2] = v44 * v25;
  v30 = wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v29;
  v37.mVec128.m128_f32[2] = v29;
  v31 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v29;
  v36.mVec128.m128_f32[0] = (float)((float)(v30 + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v28))
                                  + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v27))
                          + wtrs0->m_origin.mVec128.m128_f32[0];
  v32 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
  v36.mVec128.m128_f32[1] = (float)((float)(v31 + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[1] * v28))
                                  + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v27))
                          + wtrs0->m_origin.mVec128.m128_f32[1];
  *(float *)&v33 = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v37.mVec128.m128_f32[2])
                                 + (float)(v32 * v28))
                         + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v27))
                 + wtrs0->m_origin.mVec128.m128_f32[2];
  v34 = v44;
  v36.mVec128.m128_u64[1] = v33;
  results->witnesses[1] = (btVector3)v36.mVec128;
  v36.mVec128.m128_i32[0] = LODWORD(v24) ^ _mask__NegFloat_;
  v36.mVec128.m128_i32[1] = LODWORD(v26) ^ _mask__NegFloat_;
  v36.mVec128.m128_u64[1] = LODWORD(v34) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  results->normal.mVec128.m128_i32[0] = LODWORD(v24) ^ _mask__NegFloat_;
  *(unsigned __int64 *)((char *)results->normal.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v36.mVec128.m128_u64
                                                                                            + 4);
  LODWORD(results->distance) = LODWORD(v25) ^ _mask__NegFloat_;
  results->normal.mVec128.m128_i32[3] = v36.mVec128.m128_i32[3];
  return 1;
}
