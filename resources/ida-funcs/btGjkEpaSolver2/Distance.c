char __usercall btGjkEpaSolver2::Distance@<al>(
        const btConvexShape *shape0@<ecx>,
        const btTransform *wtrs0@<edi>,
        const btConvexShape *shape1@<eax>,
        const btTransform *wtrs1,
        const btVector3 *guess,
        btGjkEpaSolver2::sResults *results)
{
  btGjkEpaSolver2::sResults *v6; // ebx
  unsigned int v7; // esi
  gjkepa2_impl::MinkowskiDiff *v8; // edx
  gjkepa2_impl::GJK::eStatus::_ v9; // eax
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  btVector3 *(__thiscall *Ls)(btConvexShape *, btVector3 *, const btVector3 *); // ebx
  __int64 *v17; // eax
  __int64 v18; // xmm0_8
  gjkepa2_impl::GJK::sSV *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  int v22; // eax
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm7_4
  int v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm7_4
  int v29; // xmm6_4
  float v30; // xmm7_4
  unsigned int v31; // xmm4_4
  unsigned int v32; // xmm1_4
  __int64 v33; // xmm6_8
  unsigned int v34; // xmm5_4
  __int64 v35; // xmm0_8
  long double v36; // st7
  const vostok::math::float4x4 *v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  gjkepa2_impl::GJK::sSV *_X; // [esp+B70h] [ebp-2B4h]
  __m128i v42; // [esp+B84h] [ebp-2A0h] BYREF
  float v43; // [esp+BA0h] [ebp-284h]
  float v44; // [esp+BA4h] [ebp-280h]
  float v45; // [esp+BA8h] [ebp-27Ch]
  float v46; // [esp+BACh] [ebp-278h]
  float v47[2]; // [esp+BB4h] [ebp-270h] BYREF
  __int64 v48; // [esp+BBCh] [ebp-268h]
  __int64 v49; // [esp+BC4h] [ebp-260h]
  __int64 v50; // [esp+BCCh] [ebp-258h]
  float v51; // [esp+BD4h] [ebp-250h]
  float v52; // [esp+BD8h] [ebp-24Ch]
  int v53; // [esp+BDCh] [ebp-248h]
  int v54; // [esp+BE0h] [ebp-244h]
  gjkepa2_impl::MinkowskiDiff v55; // [esp+BE4h] [ebp-240h] BYREF
  btVector3 v56; // [esp+C74h] [ebp-1B0h] BYREF
  btVector3 v57; // [esp+C84h] [ebp-1A0h] BYREF
  gjkepa2_impl::GJK v58; // [esp+C94h] [ebp-190h] BYREF

  v6 = results;
  v7 = 0;
  gjkepa2_impl::Initialize(wtrs1, &v55, shape0, wtrs0, shape1, results, 0);
  memset(&v42, 0, sizeof(v42));
  v58.m_ray = (btVector3)_mm_load_si128(&v42);
  v58.m_nfree = 0;
  v58.m_status = Failed;
  v58.m_current = 0;
  v58.m_distance = 0.0;
  v9 = gjkepa2_impl::GJK::Evaluate(guess, (const gjkepa2_impl::MinkowskiDiff *)wtrs0, &v58, v8);
  if ( v9 )
  {
    results->status = (v9 != Inside) + 1;
    return 0;
  }
  else
  {
    m_simplex = v58.m_simplex;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    v44 = 0.0;
    v45 = 0.0;
    v46 = 0.0;
    memset(&v42, 0, 12);
    if ( v58.m_simplex->rank )
    {
      Ls = v55.Ls;
      do
      {
        _X = m_simplex->c[v7];
        v43 = m_simplex->p[v7];
        v17 = (__int64 *)Ls((btConvexShape *)v55.m_shapes[0], &v56, &_X->d);
        v49 = *v17;
        v18 = v17[1];
        v19 = v58.m_simplex->c[v7];
        v50 = v18;
        v45 = (float)(*((float *)&v49 + 1) * v43) + v45;
        v20 = -v19->d.mVec128.m128_f32[1];
        v46 = (float)(*(float *)&v18 * v43) + v46;
        v21 = -v19->d.mVec128.m128_f32[0];
        v44 = (float)(*(float *)&v49 * v43) + v44;
        *(float *)&v18 = -v19->d.mVec128.m128_f32[2];
        v47[0] = (float)((float)(v55.m_toshape1.m_el[0].mVec128.m128_f32[0] * v21)
                       + (float)(v55.m_toshape1.m_el[0].mVec128.m128_f32[1] * v20))
               + (float)(v55.m_toshape1.m_el[0].mVec128.m128_f32[2] * *(float *)&v18);
        v47[1] = (float)((float)(v55.m_toshape1.m_el[1].mVec128.m128_f32[0] * v21)
                       + (float)(v55.m_toshape1.m_el[1].mVec128.m128_f32[1] * v20))
               + (float)(v55.m_toshape1.m_el[1].mVec128.m128_f32[2] * *(float *)&v18);
        v51 = v21;
        v52 = v20;
        v53 = v18;
        v54 = 0;
        v48 = COERCE_UNSIGNED_INT(
                (float)((float)(v55.m_toshape1.m_el[2].mVec128.m128_f32[0] * v21)
                      + (float)(v55.m_toshape1.m_el[2].mVec128.m128_f32[1] * v20))
              + (float)(v55.m_toshape1.m_el[2].mVec128.m128_f32[2] * *(float *)&v18));
        v22 = (int)Ls((btConvexShape *)v55.m_shapes[1], &v57, (const btVector3 *)v47);
        v23 = *(float *)(v22 + 8);
        v24 = *(float *)(v22 + 4);
        LODWORD(v18) = *(_DWORD *)v22;
        m_simplex = v58.m_simplex;
        ++v7;
        v13 = (float)((float)((float)((float)((float)(v24 * v55.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[1])
                                            + (float)(v23 * v55.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[2]))
                                    + (float)(*(float *)&v18 * v55.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[0]))
                            + v55.m_toshape0.m_origin.mVec128.m128_f32[0])
                    * v43)
            + *(float *)v42.m128i_i32;
        v14 = (float)((float)((float)((float)((float)(*(float *)&v18 * v55.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[0])
                                            + (float)(v24 * v55.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[1]))
                                    + (float)(v23 * v55.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[2]))
                            + v55.m_toshape0.m_origin.mVec128.m128_f32[1])
                    * v43)
            + *(float *)&v42.m128i_i32[1];
        v15 = (float)((float)((float)((float)((float)(*(float *)&v18 * v55.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[0])
                                            + (float)(v24 * v55.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[1]))
                                    + (float)(v23 * v55.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[2]))
                            + v55.m_toshape0.m_origin.mVec128.m128_f32[2])
                    * v43)
            + *(float *)&v42.m128i_i32[2];
        v42.m128i_i64[0] = __PAIR64__(LODWORD(v14), LODWORD(v13));
        *(float *)&v42.m128i_i32[2] = v15;
      }
      while ( v7 < v58.m_simplex->rank );
      v12 = v45;
      v11 = v44;
      v6 = results;
    }
    v25 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    *(float *)v42.m128i_i32 = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v46)
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v12))
                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v11))
                            + wtrs0->m_origin.mVec128.m128_f32[0];
    *(float *)&v26 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v46) + (float)(v25 * v12))
                           + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v11))
                   + wtrs0->m_origin.mVec128.m128_f32[1];
    v27 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
    v42.m128i_i32[1] = v26;
    *(float *)&v42.m128i_i32[2] = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v46)
                                                + (float)(v27 * v12))
                                        + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v11))
                                + wtrs0->m_origin.mVec128.m128_f32[2];
    v6->witnesses[0].mVec128.m128_u64[0] = v42.m128i_i64[0];
    v42.m128i_i32[3] = 0;
    v6->witnesses[0].mVec128.m128_u64[1] = v42.m128i_u64[1];
    v28 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    *(float *)v42.m128i_i32 = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v13)
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v15))
                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v14))
                            + wtrs0->m_origin.mVec128.m128_f32[0];
    *(float *)&v29 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v15) + (float)(v28 * v14))
                           + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v13))
                   + wtrs0->m_origin.mVec128.m128_f32[1];
    v30 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
    v42.m128i_i32[1] = v29;
    *(float *)&v42.m128i_i32[2] = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v15)
                                                + (float)(v30 * v14))
                                        + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v13))
                                + wtrs0->m_origin.mVec128.m128_f32[2];
    *(float *)&v31 = v11 - v13;
    v42.m128i_i32[3] = 0;
    *(float *)&v32 = v46 - v15;
    v6->witnesses[1].mVec128.m128_u64[0] = v42.m128i_i64[0];
    v33 = v42.m128i_i64[1];
    *(float *)&v34 = v12 - v14;
    v42.m128i_i64[0] = __PAIR64__(v34, v31);
    v42.m128i_i64[1] = v32;
    v6->normal.mVec128.m128_u64[0] = __PAIR64__(v34, v31);
    v35 = v42.m128i_i64[1];
    v6->witnesses[1].mVec128.m128_u64[1] = v33;
    v6->normal.mVec128.m128_u64[1] = v35;
    v36 = sqrtf(
            (float)((float)(v6->normal.mVec128.m128_f32[0] * v6->normal.mVec128.m128_f32[0])
                  + (float)(v6->normal.mVec128.m128_f32[1] * v6->normal.mVec128.m128_f32[1]))
          + (float)(v6->normal.mVec128.m128_f32[2] * v6->normal.mVec128.m128_f32[2]));
    v43 = v36;
    v37 = clear_value;
    v6->distance = v36;
    if ( v36 <= 0.000099999997 )
      v38 = *(float *)&v37;
    else
      v38 = v43;
    v39 = *(float *)&v37 / v38;
    v6->normal.mVec128.m128_f32[0] = v6->normal.mVec128.m128_f32[0] * v39;
    v6->normal.mVec128.m128_f32[1] = v6->normal.mVec128.m128_f32[1] * v39;
    v6->normal.mVec128.m128_f32[2] = v6->normal.mVec128.m128_f32[2] * v39;
    return 1;
  }
}
