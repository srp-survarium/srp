char __usercall btGjkEpaSolver2::Penetration@<al>(
        const btConvexShape *shape0@<edx>,
        const btTransform *wtrs0@<esi>,
        const btConvexShape *shape1@<ecx>,
        const btTransform *wtrs1,
        const gjkepa2_impl::MinkowskiDiff *guess,
        btGjkEpaSolver2::sResults *results,
        bool usemargins)
{
  float v7; // xmm2_4
  float v8; // xmm2_4
  unsigned int v9; // xmm2_4
  gjkepa2_impl::MinkowskiDiff *v10; // edx
  __int32 v11; // eax
  gjkepa2_impl::EPA *v12; // ecx
  unsigned int v14; // edi
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  btVector3 *v18; // eax
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm4_4
  float m_depth; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm1_4
  unsigned int v32; // xmm4_4
  unsigned int v33; // xmm6_4
  btVector3 guessa; // [esp+10h] [ebp-2AC0h] BYREF
  unsigned __int64 v35; // [esp+20h] [ebp-2AB0h]
  unsigned __int64 v36; // [esp+28h] [ebp-2AA8h]
  btVector3 result; // [esp+30h] [ebp-2AA0h] BYREF
  gjkepa2_impl::MinkowskiDiff shape; // [esp+40h] [ebp-2A90h] BYREF
  gjkepa2_impl::GJK v39; // [esp+D0h] [ebp-2A00h] BYREF
  gjkepa2_impl::EPA gjk; // [esp+260h] [ebp-2870h] BYREF

  gjkepa2_impl::Initialize(wtrs1, &shape, shape0, wtrs0, shape1, results, usemargins);
  v7 = *(float *)guess->m_shapes;
  memset(&guessa, 0, sizeof(guessa));
  v39.m_ray = (btVector3)_mm_load_si128((const __m128i *)&guessa);
  guessa.mVec128.m128_f32[0] = -v7;
  v8 = *(float *)&guess->m_shapes[1];
  v39.m_nfree = 0;
  v39.m_current = 0;
  guessa.mVec128.m128_f32[1] = -v8;
  *(float *)&v9 = -*(float *)&guess->m_shapes[2];
  v39.m_status = Failed;
  v39.m_distance = 0.0;
  guessa.mVec128.m128_u64[1] = v9;
  v11 = gjkepa2_impl::GJK::Evaluate(&guessa, guess, &v39, v10) - 1;
  if ( v11 )
  {
    if ( v11 == 1 )
    {
      results->status = GJK_Failed;
      return 0;
    }
    return 0;
  }
  memset(&gjk.m_hull, 0, 16);
  gjkepa2_impl::EPA::Initialize(v12, (int)&gjk);
  guessa.mVec128.m128_f32[0] = -*(float *)guess->m_shapes;
  guessa.mVec128.m128_f32[1] = -*(float *)&guess->m_shapes[1];
  guessa.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-*(float *)&guess->m_shapes[2]);
  if ( gjkepa2_impl::EPA::Evaluate(&gjk, &gjk, &v39, &guessa) == 9 )
  {
    results->status = EPA_Failed;
    return 0;
  }
  v14 = 0;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  memset(&guessa, 0, 12);
  if ( gjk.m_result.rank )
  {
    do
    {
      v18 = shape.Ls(shape.m_shapes[0], &result, gjk.m_result.c[v14]);
      v19 = gjk.m_result.p[v14];
      v35 = v18->mVec128.m128_u64[0];
      v36 = v18->mVec128.m128_u64[1];
      v15 = (float)(v19 * *(float *)&v35) + guessa.mVec128.m128_f32[0];
      v16 = (float)(v19 * *((float *)&v35 + 1)) + guessa.mVec128.m128_f32[1];
      v17 = (float)(v19 * *(float *)&v36) + guessa.mVec128.m128_f32[2];
      ++v14;
      guessa.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v16), LODWORD(v15));
      guessa.mVec128.m128_f32[2] = v17;
    }
    while ( v14 < gjk.m_result.rank );
  }
  results->status = Penetrating;
  v20 = gjk.m_normal.mVec128.m128_f32[1];
  v21 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1] * v16;
  guessa.mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v15)
                                             + (float)(v17 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[2]))
                                     + (float)(v16 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1]))
                             + wtrs0->m_origin.mVec128.m128_f32[0];
  v22 = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v17) + v21)
              + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v15))
      + wtrs0->m_origin.mVec128.m128_f32[1];
  v23 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v16;
  guessa.mVec128.m128_f32[1] = v22;
  v24 = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v17) + v23)
              + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v15))
      + wtrs0->m_origin.mVec128.m128_f32[2];
  guessa.mVec128.m128_i32[3] = 0;
  results->witnesses[0].mVec128.m128_u64[0] = guessa.mVec128.m128_u64[0];
  guessa.mVec128.m128_f32[2] = v24;
  v25 = gjk.m_normal.mVec128.m128_f32[0];
  results->witnesses[0].mVec128.m128_u64[1] = guessa.mVec128.m128_u64[1];
  m_depth = gjk.m_depth;
  *((float *)&v35 + 1) = v20 * gjk.m_depth;
  v27 = v16 - (float)(v20 * gjk.m_depth);
  v28 = v17 - (float)(gjk.m_normal.mVec128.m128_f32[2] * gjk.m_depth);
  v29 = v15 - (float)(v25 * gjk.m_depth);
  v30 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
  guessa.mVec128.m128_f32[0] = (float)((float)((float)(v28 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[2])
                                             + (float)(v27 * wtrs0->m_basis.m_el[0].mVec128.m128_f32[1]))
                                     + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v29))
                             + wtrs0->m_origin.mVec128.m128_f32[0];
  guessa.mVec128.m128_f32[1] = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v28)
                                             + (float)(v30 * v27))
                                     + (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[0] * v29))
                             + wtrs0->m_origin.mVec128.m128_f32[1];
  guessa.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v28)
                                               + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v27))
                                       + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v29))
                               + wtrs0->m_origin.mVec128.m128_f32[2]);
  v31 = gjk.m_normal.mVec128.m128_f32[2];
  results->witnesses[1] = (btVector3)guessa.mVec128;
  *(float *)&v32 = -v25;
  *(float *)&v33 = -v20;
  guessa.mVec128.m128_f32[2] = -v31;
  guessa.mVec128.m128_u64[0] = __PAIR64__(v33, v32);
  results->normal.mVec128.m128_u64[0] = __PAIR64__(v33, v32);
  guessa.mVec128.m128_i32[3] = 0;
  results->normal.mVec128.m128_u64[1] = guessa.mVec128.m128_u32[2];
  results->distance = -m_depth;
  return 1;
}
