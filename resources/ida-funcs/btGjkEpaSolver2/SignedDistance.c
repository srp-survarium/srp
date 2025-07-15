float __usercall btGjkEpaSolver2::SignedDistance@<xmm0>(
        const btVector3 *position,
        btConvexShape *margin,
        const btTransform *shape0,
        btGjkEpaSolver2::sResults *wtrs0)
{
  btSphereShape *v4; // ecx
  btGjkEpaSolver2::sResults *v5; // esi
  gjkepa2_impl::GJK *v6; // ecx
  gjkepa2_impl::GJK *v7; // ecx
  gjkepa2_impl::GJK::eStatus::_ v8; // eax
  gjkepa2_impl::MinkowskiDiff *v9; // ecx
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  gjkepa2_impl::GJK::sSV *v14; // esi
  int v15; // xmm3_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float result; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  unsigned int v33; // [esp+1Ch] [ebp-2F8h]
  float MarginNonVirtual; // [esp+1Ch] [ebp-2F8h]
  float v35; // [esp+1Ch] [ebp-2F8h]
  float v36; // [esp+20h] [ebp-2F4h]
  btVector3 v37; // [esp+24h] [ebp-2F0h] BYREF
  btQuaternion v38; // [esp+34h] [ebp-2E0h] BYREF
  float v39; // [esp+44h] [ebp-2D0h]
  float v40; // [esp+48h] [ebp-2CCh]
  float v41; // [esp+4Ch] [ebp-2C8h]
  btVector3 v42; // [esp+54h] [ebp-2C0h] BYREF
  float v43[4]; // [esp+64h] [ebp-2B0h] BYREF
  btConvexShape v44[4]; // [esp+74h] [ebp-2A0h] BYREF
  btTransform v45; // [esp+B4h] [ebp-260h] BYREF
  gjkepa2_impl::MinkowskiDiff v46; // [esp+F4h] [ebp-220h] BYREF
  gjkepa2_impl::GJK v47; // [esp+184h] [ebp-190h] BYREF

  btSphereShape::btSphereShape(v4, 0.0);
  memset(&v38, 0, 12);
  v38.m_floats[3] = s_bm_current_air_resistance;
  btMatrix3x3::setRotation(&v38, &v45.m_basis);
  v45.m_origin = (btVector3)position->mVec128;
  v5 = wtrs0;
  gjkepa2_impl::Initialize(wtrs0, 0, margin, shape0, v44, &v45, &v46, 0);
  gjkepa2_impl::GJK::GJK(v6, &v47);
  v38.m_floats[0] = s_bm_current_air_resistance;
  v38.m_floats[1] = s_bm_current_air_resistance;
  v38.m_floats[2] = s_bm_current_air_resistance;
  v38.m_floats[3] = 0.0;
  v8 = gjkepa2_impl::GJK::Evaluate(v7, &v47, &v46, (int *)&v38);
  if ( v8 )
  {
    if ( v8 == Inside && btGjkEpaSolver2::Penetration(margin, shape0, v44, &v45, wtrs0, 1) )
    {
      v29 = wtrs0->witnesses[0].mVec128.m128_f32[0] - wtrs0->witnesses[1].mVec128.m128_f32[0];
      v30 = wtrs0->witnesses[0].mVec128.m128_f32[2] - wtrs0->witnesses[1].mVec128.m128_f32[2];
      v31 = wtrs0->witnesses[0].mVec128.m128_f32[1] - wtrs0->witnesses[1].mVec128.m128_f32[1];
      v32 = fsqrt((float)((float)(v29 * v29) + (float)(v30 * v30)) + (float)(v31 * v31));
      if ( v32 >= 0.00000011920929 )
      {
        v37.mVec128.m128_i32[3] = 0;
        v37.mVec128.m128_f32[1] = v31 * (float)(s_bm_current_air_resistance / v32);
        v37.mVec128.m128_f32[2] = v30 * (float)(s_bm_current_air_resistance / v32);
        wtrs0->normal.mVec128.m128_f32[0] = v29 * (float)(s_bm_current_air_resistance / v32);
        *(unsigned __int64 *)((char *)wtrs0->normal.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v37.mVec128.m128_u64
                                                                                                + 4);
        wtrs0->normal.mVec128.m128_i32[3] = v37.mVec128.m128_i32[3];
      }
      LODWORD(result) = LODWORD(v32) ^ _mask__NegFloat_;
    }
    else
    {
      return FLOAT_3_4028235e38;
    }
  }
  else
  {
    m_simplex = v47.m_simplex;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v39 = 0.0;
    v40 = 0.0;
    v41 = 0.0;
    memset(&v38, 0, 12);
    v33 = 0;
    if ( v47.m_simplex->rank )
    {
      do
      {
        v36 = m_simplex->p[v33];
        gjkepa2_impl::MinkowskiDiff::Support0(v9, (int)&v46, &v42, &m_simplex->c[v33]->d);
        v14 = v47.m_simplex->c[v33];
        v15 = v14->d.mVec128.m128_i32[0];
        v39 = (float)(v42.mVec128.m128_f32[0] * v36) + v39;
        v16 = v14->d.mVec128.m128_i32[2];
        v40 = (float)(v42.mVec128.m128_f32[1] * v36) + v40;
        v17 = v14->d.mVec128.m128_i32[1];
        v41 = (float)(v42.mVec128.m128_f32[2] * v36) + v41;
        v37.mVec128.m128_u64[1] = (unsigned int)v16 ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
        v37.mVec128.m128_i32[0] = v15 ^ _mask__NegFloat_;
        v37.mVec128.m128_i32[1] = v17 ^ _mask__NegFloat_;
        gjkepa2_impl::MinkowskiDiff::Support1(&v46, &v37, (int)v43);
        ++v33;
        m_simplex = v47.m_simplex;
        v9 = (gjkepa2_impl::MinkowskiDiff *)v33;
        v12 = (float)(v43[1] * v36) + v38.m_floats[1];
        v13 = (float)(v43[2] * v36) + v38.m_floats[2];
        v11 = (float)(v43[0] * v36) + v38.m_floats[0];
        v38.m_floats[0] = v11;
        v38.m_floats[1] = v12;
        v38.m_floats[2] = v13;
      }
      while ( v33 < v47.m_simplex->rank );
      v5 = wtrs0;
    }
    v18 = shape0->m_basis.m_el[1].mVec128.m128_f32[1] * v40;
    v37.mVec128.m128_f32[0] = (float)((float)((float)(v41 * shape0->m_basis.m_el[0].mVec128.m128_f32[2])
                                            + (float)(v40 * shape0->m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(shape0->m_basis.m_el[0].mVec128.m128_f32[0] * v39))
                            + shape0->m_origin.mVec128.m128_f32[0];
    v19 = (float)((float)((float)(shape0->m_basis.m_el[1].mVec128.m128_f32[2] * v41) + v18)
                + (float)(shape0->m_basis.m_el[1].mVec128.m128_f32[0] * v39))
        + shape0->m_origin.mVec128.m128_f32[1];
    v20 = shape0->m_basis.m_el[2].mVec128.m128_f32[1] * v40;
    v37.mVec128.m128_f32[1] = v19;
    v37.mVec128.m128_f32[2] = (float)((float)((float)(shape0->m_basis.m_el[2].mVec128.m128_f32[2] * v41) + v20)
                                    + (float)(shape0->m_basis.m_el[2].mVec128.m128_f32[0] * v39))
                            + shape0->m_origin.mVec128.m128_f32[2];
    v37.mVec128.m128_i32[3] = 0;
    v5->witnesses[0] = (btVector3)v37.mVec128;
    v21 = shape0->m_basis.m_el[1].mVec128.m128_f32[1];
    v37.mVec128.m128_f32[0] = (float)((float)((float)(v13 * shape0->m_basis.m_el[0].mVec128.m128_f32[2])
                                            + (float)(v12 * shape0->m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(shape0->m_basis.m_el[0].mVec128.m128_f32[0] * v11))
                            + shape0->m_origin.mVec128.m128_f32[0];
    v22 = (float)(shape0->m_basis.m_el[1].mVec128.m128_f32[2] * v13) + (float)(v21 * v12);
    v23 = v11 * shape0->m_basis.m_el[1].mVec128.m128_f32[0];
    v24 = v11 * shape0->m_basis.m_el[2].mVec128.m128_f32[0];
    v37.mVec128.m128_f32[1] = (float)(v22 + v23) + shape0->m_origin.mVec128.m128_f32[1];
    v37.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                (float)((float)((float)(shape0->m_basis.m_el[2].mVec128.m128_f32[2] * v13)
                                              + (float)(shape0->m_basis.m_el[2].mVec128.m128_f32[1] * v12))
                                      + v24)
                              + shape0->m_origin.mVec128.m128_f32[2]);
    wtrs0->witnesses[1] = (btVector3)v37.mVec128;
    v38.m_floats[0] = wtrs0->witnesses[1].mVec128.m128_f32[0] - v5->witnesses[0].mVec128.m128_f32[0];
    v38.m_floats[1] = wtrs0->witnesses[1].mVec128.m128_f32[1] - v5->witnesses[0].mVec128.m128_f32[1];
    v38.m_floats[2] = wtrs0->witnesses[1].mVec128.m128_f32[2] - v5->witnesses[0].mVec128.m128_f32[2];
    MarginNonVirtual = btConvexShape::getMarginNonVirtual(margin);
    v35 = btConvexShape::getMarginNonVirtual(v44) + MarginNonVirtual;
    v25 = fsqrt(
            (float)((float)(v38.m_floats[2] * v38.m_floats[2]) + (float)(v38.m_floats[1] * v38.m_floats[1]))
          + (float)(v38.m_floats[0] * v38.m_floats[0]));
    v37.mVec128.m128_f32[0] = v38.m_floats[0] * (float)(s_bm_current_air_resistance / v25);
    v37.mVec128.m128_i32[3] = 0;
    v37.mVec128.m128_f32[1] = v38.m_floats[1] * (float)(s_bm_current_air_resistance / v25);
    v37.mVec128.m128_f32[2] = v38.m_floats[2] * (float)(s_bm_current_air_resistance / v25);
    wtrs0->normal = (btVector3)v37.mVec128;
    v26 = (float)(wtrs0->normal.mVec128.m128_f32[1] * v35) + v5->witnesses[0].mVec128.m128_f32[1];
    v27 = (float)(wtrs0->normal.mVec128.m128_f32[2] * v35) + v5->witnesses[0].mVec128.m128_f32[2];
    v5->witnesses[0].mVec128.m128_f32[0] = v5->witnesses[0].mVec128.m128_f32[0]
                                         + (float)(v35 * wtrs0->normal.mVec128.m128_f32[0]);
    v5->witnesses[0].mVec128.m128_f32[1] = v26;
    v5->witnesses[0].mVec128.m128_f32[2] = v27;
    return v25 - v35;
  }
  return result;
}


char __cdecl btGjkEpaSolver2::SignedDistance(
        const btConvexShape *shape0,
        const btTransform *wtrs0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        btVector3 *guess,
        btGjkEpaSolver2::sResults *results)
{
  if ( btGjkEpaSolver2::Distance(shape0, wtrs0, shape1, wtrs1, guess, results) )
    return 1;
  else
    return btGjkEpaSolver2::Penetration(shape0, wtrs0, shape1, wtrs1, results, 0);
}
