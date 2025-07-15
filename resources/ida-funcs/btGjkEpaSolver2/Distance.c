char __cdecl btGjkEpaSolver2::Distance(
        const btConvexShape *shape0,
        const btTransform *wtrs0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        btVector3 *guess,
        btGjkEpaSolver2::sResults *results)
{
  btGjkEpaSolver2::sResults *v6; // esi
  gjkepa2_impl::GJK *v7; // ecx
  gjkepa2_impl::GJK *v8; // ecx
  gjkepa2_impl::GJK::eStatus::_ v9; // eax
  gjkepa2_impl::MinkowskiDiff *v10; // ecx
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  unsigned int v15; // esi
  gjkepa2_impl::GJK::sSV *v16; // esi
  int v17; // xmm3_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v37; // [esp+Ch] [ebp-284h]
  btVector3 v38; // [esp+10h] [ebp-280h] BYREF
  unsigned int v39; // [esp+2Ch] [ebp-264h]
  float v40; // [esp+30h] [ebp-260h]
  float v41; // [esp+34h] [ebp-25Ch]
  float v42; // [esp+38h] [ebp-258h]
  float v43; // [esp+40h] [ebp-250h]
  float v44; // [esp+44h] [ebp-24Ch]
  float v45; // [esp+48h] [ebp-248h]
  btVector3 v46; // [esp+50h] [ebp-240h] BYREF
  float v47[4]; // [esp+60h] [ebp-230h] BYREF
  gjkepa2_impl::MinkowskiDiff v48; // [esp+70h] [ebp-220h] BYREF
  gjkepa2_impl::GJK v49; // [esp+100h] [ebp-190h] BYREF

  v6 = results;
  gjkepa2_impl::Initialize(results, 0, shape0, wtrs0, shape1, wtrs1, &v48, 0);
  gjkepa2_impl::GJK::GJK(v7, &v49);
  v9 = gjkepa2_impl::GJK::Evaluate(v8, &v49, &v48, (int *)guess);
  if ( v9 )
  {
    results->status = (v9 != Inside) + 1;
    return 0;
  }
  else
  {
    m_simplex = v49.m_simplex;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v43 = 0.0;
    v44 = 0.0;
    v45 = 0.0;
    v40 = 0.0;
    v41 = 0.0;
    v42 = 0.0;
    v39 = 0;
    if ( v49.m_simplex->rank )
    {
      do
      {
        v15 = v39;
        v37 = m_simplex->p[v39];
        gjkepa2_impl::MinkowskiDiff::Support0(v10, (int)&v48, &v46, &m_simplex->c[v39]->d);
        v16 = v49.m_simplex->c[v15];
        v17 = v16->d.mVec128.m128_i32[0];
        v43 = (float)(v46.mVec128.m128_f32[0] * v37) + v43;
        v18 = v16->d.mVec128.m128_i32[2];
        v44 = (float)(v46.mVec128.m128_f32[1] * v37) + v44;
        v19 = v16->d.mVec128.m128_i32[1];
        v45 = (float)(v46.mVec128.m128_f32[2] * v37) + v45;
        v38.mVec128.m128_u64[1] = (unsigned int)v18 ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
        v38.mVec128.m128_i32[0] = v17 ^ _mask__NegFloat_;
        v38.mVec128.m128_i32[1] = v19 ^ _mask__NegFloat_;
        gjkepa2_impl::MinkowskiDiff::Support1(&v48, &v38, (int)v47);
        ++v39;
        m_simplex = v49.m_simplex;
        v10 = (gjkepa2_impl::MinkowskiDiff *)v39;
        v40 = (float)(v47[0] * v37) + v40;
        v41 = (float)(v47[1] * v37) + v41;
        v42 = (float)(v47[2] * v37) + v42;
      }
      while ( v39 < v49.m_simplex->rank );
      v14 = v45;
      v13 = v44;
      v12 = v43;
      v6 = results;
    }
    v20 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    v38.mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v13)
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v12))
                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v14))
                            + wtrs0->m_origin.mVec128.m128_f32[0];
    v21 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v14) + (float)(v20 * v13))
                + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v12))
        + wtrs0->m_origin.mVec128.m128_f32[1];
    v22 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
    v38.mVec128.m128_f32[1] = v21;
    v23 = (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v14) + (float)(v22 * v13);
    v24 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[0];
    v38.mVec128.m128_i32[3] = 0;
    v38.mVec128.m128_f32[2] = (float)(v23 + (float)(v24 * v12)) + wtrs0->m_origin.mVec128.m128_f32[2];
    v25 = v40;
    v6->witnesses[0] = (btVector3)v38.mVec128;
    v26 = v41;
    v27 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    v38.mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v25)
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v42))
                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v41))
                            + wtrs0->m_origin.mVec128.m128_f32[0];
    v28 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v42) + (float)(v27 * v41))
                + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v25))
        + wtrs0->m_origin.mVec128.m128_f32[1];
    v29 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
    v38.mVec128.m128_f32[1] = v28;
    v30 = (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v42) + (float)(v29 * v41);
    v31 = v25 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0];
    v38.mVec128.m128_i32[3] = 0;
    v38.mVec128.m128_f32[2] = (float)(v30 + v31) + wtrs0->m_origin.mVec128.m128_f32[2];
    results->witnesses[1] = (btVector3)v38.mVec128;
    v38.mVec128.m128_f32[0] = v12 - v25;
    v38.mVec128.m128_f32[1] = v13 - v26;
    v38.mVec128.m128_i32[3] = 0;
    v38.mVec128.m128_f32[2] = v14 - v42;
    results->normal.mVec128.m128_f32[0] = v12 - v25;
    *(unsigned __int64 *)((char *)results->normal.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v38.mVec128.m128_u64
                                                                                              + 4);
    results->normal.mVec128.m128_i32[3] = v38.mVec128.m128_i32[3];
    v32 = fsqrt(
            (float)((float)(results->normal.mVec128.m128_f32[2] * results->normal.mVec128.m128_f32[2])
                  + (float)(results->normal.mVec128.m128_f32[1] * results->normal.mVec128.m128_f32[1]))
          + (float)(results->normal.mVec128.m128_f32[0] * results->normal.mVec128.m128_f32[0]));
    v33 = s_bm_current_air_resistance;
    results->distance = v32;
    if ( v32 <= 0.000099999997 )
      v32 = v33;
    v34 = v33 / v32;
    results->normal.mVec128.m128_f32[0] = results->normal.mVec128.m128_f32[0] * v34;
    v35 = v34 * results->normal.mVec128.m128_f32[2];
    results->normal.mVec128.m128_f32[1] = v34 * results->normal.mVec128.m128_f32[1];
    results->normal.mVec128.m128_f32[2] = v35;
    return 1;
  }
}
