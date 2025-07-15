float __usercall btGjkEpaSolver2::SignedDistance@<xmm0>(
        const btVector3 *position@<ecx>,
        const btTransform *wtrs0@<eax>,
        const btConvexShape *margin,
        btGjkEpaSolver2::sResults *shape0)
{
  gjkepa2_impl::MinkowskiDiff *v6; // edx
  gjkepa2_impl::GJK::eStatus::_ v7; // eax
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  unsigned int v9; // edi
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  btVector3 *v15; // eax
  unsigned __int64 v16; // xmm0_8
  gjkepa2_impl::GJK::sSV *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  btVector3 *v20; // eax
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  unsigned int v30; // xmm6_4
  float v31; // xmm5_4
  unsigned int v32; // xmm4_4
  int m_shapeType; // eax
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  int v41; // xmm2_4
  float v42; // xmm3_4
  unsigned int v44; // xmm1_4
  unsigned int v45; // xmm0_4
  long double v46; // st7
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // [esp+2180h] [ebp-324h]
  float v50; // [esp+2180h] [ebp-324h]
  float v51; // [esp+2180h] [ebp-324h]
  btMatrix3x3 v52; // [esp+2184h] [ebp-320h] BYREF
  btConvexShape v53; // [esp+21B4h] [ebp-2F0h] BYREF
  const vostok::math::float4x4 *v54; // [esp+21C4h] [ebp-2E0h]
  const vostok::math::float4x4 *v55; // [esp+21C8h] [ebp-2DCh]
  const vostok::math::float4x4 *v56; // [esp+21CCh] [ebp-2D8h]
  int v57; // [esp+21D0h] [ebp-2D4h]
  float v58; // [esp+21D4h] [ebp-2D0h]
  float v59; // [esp+21E4h] [ebp-2C0h]
  unsigned __int64 v60; // [esp+21F4h] [ebp-2B0h]
  unsigned __int64 v61; // [esp+21FCh] [ebp-2A8h]
  btVector3 v62; // [esp+2204h] [ebp-2A0h] BYREF
  float v63; // [esp+2214h] [ebp-290h]
  float v64; // [esp+2218h] [ebp-28Ch]
  int v65; // [esp+221Ch] [ebp-288h]
  int v66; // [esp+2220h] [ebp-284h]
  gjkepa2_impl::MinkowskiDiff v67; // [esp+2224h] [ebp-280h] BYREF
  btTransform v68; // [esp+22B4h] [ebp-1F0h] BYREF
  btVector3 result; // [esp+22F4h] [ebp-1B0h] BYREF
  btVector3 v70; // [esp+2304h] [ebp-1A0h] BYREF
  gjkepa2_impl::GJK v71; // [esp+2314h] [ebp-190h] BYREF

  v53.m_userPointer = 0;
  v54 = clear_value;
  v55 = clear_value;
  v56 = clear_value;
  v57 = 0;
  v53.__vftable = (btConvexShape_vtbl *)&btSphereShape::`vftable';
  v53.m_shapeType = 8;
  v58 = 0.0;
  v59 = 0.0;
  memset(&v52, 0, 12);
  v52.m_el[0].mVec128.m128_i32[3] = (int)clear_value;
  btMatrix3x3::setRotation(&v52, (int)&v68);
  v68.m_origin = (btVector3)position->mVec128;
  gjkepa2_impl::Initialize(&v68, &v67, margin, wtrs0, &v53, shape0, 0);
  v52.m_el[0].mVec128.m128_u64[0] = 0;
  v52.m_el[0].mVec128.m128_i32[3] = 0;
  v71.m_ray = (btVector3)_mm_load_si128((const __m128i *)&v52);
  v71.m_nfree = 0;
  v71.m_current = 0;
  v71.m_status = Failed;
  v71.m_distance = 0.0;
  v52.m_el[0].mVec128.m128_i32[0] = (int)clear_value;
  v52.m_el[0].mVec128.m128_i32[1] = (int)clear_value;
  v52.m_el[0].mVec128.m128_u64[1] = (unsigned int)clear_value;
  v7 = gjkepa2_impl::GJK::Evaluate(v52.m_el, (const gjkepa2_impl::MinkowskiDiff *)margin, &v71, v6);
  if ( v7 )
  {
    if ( v7 == Inside
      && btGjkEpaSolver2::Penetration(
           margin,
           wtrs0,
           &v53,
           &v68,
           (const gjkepa2_impl::MinkowskiDiff *)&v71.m_ray,
           shape0,
           1) )
    {
      *(float *)&v44 = shape0->witnesses[0].mVec128.m128_f32[1] - shape0->witnesses[1].mVec128.m128_f32[1];
      *(float *)&v45 = shape0->witnesses[0].mVec128.m128_f32[0] - shape0->witnesses[1].mVec128.m128_f32[0];
      v52.m_el[0].mVec128.m128_f32[2] = shape0->witnesses[0].mVec128.m128_f32[2]
                                      - shape0->witnesses[1].mVec128.m128_f32[2];
      v52.m_el[0].mVec128.m128_u64[0] = __PAIR64__(v44, v45);
      v46 = sqrtf(
              (float)((float)(v52.m_el[0].mVec128.m128_f32[2] * v52.m_el[0].mVec128.m128_f32[2])
                    + (float)(*(float *)&v44 * *(float *)&v44))
            + (float)(*(float *)&v45 * *(float *)&v45));
      v52.m_el[2].mVec128.m128_f32[3] = v46;
      v47 = v52.m_el[2].mVec128.m128_f32[3];
      if ( v46 >= 0.00000011920929 )
      {
        v52.m_el[1].mVec128.m128_f32[0] = v52.m_el[0].mVec128.m128_f32[0]
                                        * (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3]);
        v52.m_el[1].mVec128.m128_f32[1] = v52.m_el[0].mVec128.m128_f32[1]
                                        * (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3]);
        v48 = v52.m_el[0].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3]);
        v52.m_el[1].mVec128.m128_i32[3] = 0;
        shape0->normal.mVec128.m128_u64[0] = v52.m_el[1].mVec128.m128_u64[0];
        v52.m_el[1].mVec128.m128_f32[2] = v48;
        shape0->normal.mVec128.m128_u64[1] = v52.m_el[1].mVec128.m128_u64[1];
      }
      return -v47;
    }
    else
    {
      return 3.4028235e38;
    }
  }
  else
  {
    m_simplex = v71.m_simplex;
    v9 = 0;
    v10 = 0.0;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v14 = 0.0;
    memset(&v52.m_el[1], 0, 12);
    memset(&v52, 0, 12);
    if ( v71.m_simplex->rank )
    {
      do
      {
        v49 = m_simplex->p[v9];
        v15 = v67.Ls(v67.m_shapes[0], &result, m_simplex->c[v9]);
        v60 = v15->mVec128.m128_u64[0];
        v16 = v15->mVec128.m128_u64[1];
        v17 = v71.m_simplex->c[v9];
        v61 = v16;
        v52.m_el[1].mVec128.m128_f32[2] = (float)(*(float *)&v16 * v49) + v52.m_el[1].mVec128.m128_f32[2];
        v18 = -v17->d.mVec128.m128_f32[0];
        v52.m_el[1].mVec128.m128_f32[0] = (float)(*(float *)&v60 * v49) + v52.m_el[1].mVec128.m128_f32[0];
        *(float *)&v16 = -v17->d.mVec128.m128_f32[2];
        v52.m_el[1].mVec128.m128_f32[1] = (float)(*((float *)&v60 + 1) * v49) + v52.m_el[1].mVec128.m128_f32[1];
        v19 = -v17->d.mVec128.m128_f32[1];
        v62.mVec128.m128_f32[0] = (float)((float)(v67.m_toshape1.m_el[0].mVec128.m128_f32[2] * *(float *)&v16)
                                        + (float)(v67.m_toshape1.m_el[0].mVec128.m128_f32[0] * v18))
                                + (float)(v67.m_toshape1.m_el[0].mVec128.m128_f32[1] * v19);
        v62.mVec128.m128_f32[1] = (float)((float)(v67.m_toshape1.m_el[1].mVec128.m128_f32[2] * *(float *)&v16)
                                        + (float)(v67.m_toshape1.m_el[1].mVec128.m128_f32[0] * v18))
                                + (float)(v67.m_toshape1.m_el[1].mVec128.m128_f32[1] * v19);
        v63 = v18;
        v64 = v19;
        v65 = v16;
        v66 = 0;
        v62.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                    (float)((float)(v67.m_toshape1.m_el[2].mVec128.m128_f32[0] * v18)
                                          + (float)(v67.m_toshape1.m_el[2].mVec128.m128_f32[1] * v19))
                                  + (float)(v67.m_toshape1.m_el[2].mVec128.m128_f32[2] * *(float *)&v16));
        v20 = v67.Ls(v67.m_shapes[1], &v70, &v62);
        v21 = v20->mVec128.m128_f32[1];
        v22 = v20->mVec128.m128_f32[0];
        v23 = v20->mVec128.m128_f32[2];
        *(float *)&v16 = (float)(v67.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[0] * v20->mVec128.m128_f32[0])
                       + (float)(v67.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[1] * v21);
        m_simplex = v71.m_simplex;
        ++v9;
        v12 = (float)((float)((float)(*(float *)&v16 + (float)(v67.m_toshape0.m_basis.m_el[0].mVec128.m128_f32[2] * v23))
                            + v67.m_toshape0.m_origin.mVec128.m128_f32[0])
                    * v49)
            + v52.m_el[0].mVec128.m128_f32[0];
        v13 = (float)((float)((float)((float)((float)(v67.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[0] * v22)
                                            + (float)(v67.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[1] * v21))
                                    + (float)(v67.m_toshape0.m_basis.m_el[1].mVec128.m128_f32[2] * v23))
                            + v67.m_toshape0.m_origin.mVec128.m128_f32[1])
                    * v49)
            + v52.m_el[0].mVec128.m128_f32[1];
        v14 = (float)((float)((float)((float)((float)(v67.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[0] * v22)
                                            + (float)(v67.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[1] * v21))
                                    + (float)(v67.m_toshape0.m_basis.m_el[2].mVec128.m128_f32[2] * v23))
                            + v67.m_toshape0.m_origin.mVec128.m128_f32[2])
                    * v49)
            + v52.m_el[0].mVec128.m128_f32[2];
        v52.m_el[0].mVec128.m128_f32[0] = v12;
        v52.m_el[0].mVec128.m128_f32[1] = v13;
        v52.m_el[0].mVec128.m128_f32[2] = v14;
      }
      while ( v9 < v71.m_simplex->rank );
      v11 = v52.m_el[1].mVec128.m128_f32[1];
      v10 = v52.m_el[1].mVec128.m128_f32[0];
    }
    v24 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    v52.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2]
                                                            * v52.m_el[1].mVec128.m128_f32[2])
                                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v11))
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v10))
                                    + wtrs0->m_origin.mVec128.m128_f32[0];
    v25 = (float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v52.m_el[1].mVec128.m128_f32[2]) + (float)(v24 * v11);
    v26 = v10;
    v27 = v10 * wtrs0->m_basis.m_el[2].mVec128.m128_f32[0];
    v28 = (float)(v25 + (float)(v26 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0])) + wtrs0->m_origin.mVec128.m128_f32[1];
    v29 = wtrs0->m_basis.m_el[2].mVec128.m128_f32[1];
    v52.m_el[0].mVec128.m128_f32[1] = v28;
    *(float *)&v30 = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v52.m_el[1].mVec128.m128_f32[2])
                                   + (float)(v29 * v11))
                           + v27)
                   + wtrs0->m_origin.mVec128.m128_f32[2];
    shape0->witnesses[0].mVec128.m128_u64[0] = v52.m_el[0].mVec128.m128_u64[0];
    v52.m_el[0].mVec128.m128_u64[1] = v30;
    shape0->witnesses[0].mVec128.m128_u64[1] = v30;
    v31 = wtrs0->m_basis.m_el[1].mVec128.m128_f32[1];
    v52.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[2] * v14)
                                                    + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[1] * v13))
                                            + (float)(wtrs0->m_basis.m_el[0].mVec128.m128_f32[0] * v12))
                                    + wtrs0->m_origin.mVec128.m128_f32[0];
    v52.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(wtrs0->m_basis.m_el[1].mVec128.m128_f32[2] * v14)
                                                    + (float)(v31 * v13))
                                            + (float)(v12 * wtrs0->m_basis.m_el[1].mVec128.m128_f32[0]))
                                    + wtrs0->m_origin.mVec128.m128_f32[1];
    *(float *)&v32 = (float)((float)((float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[2] * v14)
                                   + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[1] * v13))
                           + (float)(wtrs0->m_basis.m_el[2].mVec128.m128_f32[0] * v12))
                   + wtrs0->m_origin.mVec128.m128_f32[2];
    shape0->witnesses[1].mVec128.m128_u64[0] = v52.m_el[0].mVec128.m128_u64[0];
    v52.m_el[0].mVec128.m128_u64[1] = v32;
    shape0->witnesses[1].mVec128.m128_u64[1] = v32;
    m_shapeType = margin->m_shapeType;
    v34 = shape0->witnesses[1].mVec128.m128_f32[0] - shape0->witnesses[0].mVec128.m128_f32[0];
    v35 = shape0->witnesses[1].mVec128.m128_f32[1] - shape0->witnesses[0].mVec128.m128_f32[1];
    v36 = shape0->witnesses[1].mVec128.m128_f32[2] - shape0->witnesses[0].mVec128.m128_f32[2];
    v52.m_el[1].mVec128.m128_f32[0] = v34;
    *(unsigned __int64 *)((char *)v52.m_el[1].mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v36), LODWORD(v35));
    switch ( m_shapeType )
    {
      case 0:
      case 1:
      case 4:
      case 5:
      case 10:
      case 13:
        v37 = *(float *)&margin[3].__vftable;
        v50 = v37;
        break;
      case 8:
        v37 = *(float *)&margin[2].__vftable * *(float *)&margin[1].__vftable;
        v50 = v37;
        break;
      default:
        v50 = margin->getMargin((struct btConvexShape *)margin);
        v37 = v50;
        v36 = v52.m_el[1].mVec128.m128_f32[2];
        v35 = v52.m_el[1].mVec128.m128_f32[1];
        v34 = v52.m_el[1].mVec128.m128_f32[0];
        break;
    }
    switch ( v53.m_shapeType )
    {
      case 0:
      case 1:
      case 4:
      case 5:
      case 0xA:
      case 0xD:
        v38 = v59;
        break;
      case 8:
        v38 = *(float *)&v54 * v58;
        break;
      default:
        v52.m_el[2].mVec128.m128_f32[3] = v53.getMargin(&v53);
        v38 = v52.m_el[2].mVec128.m128_f32[3];
        v37 = v50;
        v36 = v52.m_el[1].mVec128.m128_f32[2];
        v35 = v52.m_el[1].mVec128.m128_f32[1];
        v34 = v52.m_el[1].mVec128.m128_f32[0];
        break;
    }
    v51 = v38 + v37;
    v52.m_el[2].mVec128.m128_f32[3] = sqrtf((float)((float)(v36 * v36) + (float)(v35 * v35)) + (float)(v34 * v34));
    v39 = v52.m_el[2].mVec128.m128_f32[3];
    v52.m_el[0].mVec128.m128_f32[0] = (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3])
                                    * v52.m_el[1].mVec128.m128_f32[0];
    v52.m_el[0].mVec128.m128_f32[1] = v52.m_el[1].mVec128.m128_f32[1]
                                    * (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3]);
    v40 = v52.m_el[1].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v52.m_el[2].mVec128.m128_f32[3]);
    v52.m_el[0].mVec128.m128_i32[3] = 0;
    shape0->normal.mVec128.m128_u64[0] = v52.m_el[0].mVec128.m128_u64[0];
    v52.m_el[0].mVec128.m128_f32[2] = v40;
    shape0->normal.mVec128.m128_u64[1] = v52.m_el[0].mVec128.m128_u64[1];
    *(float *)&v41 = (float)(shape0->normal.mVec128.m128_f32[1] * (float)(v38 + v37))
                   + shape0->witnesses[0].mVec128.m128_f32[1];
    v42 = (float)(shape0->normal.mVec128.m128_f32[2] * (float)(v38 + v37)) + shape0->witnesses[0].mVec128.m128_f32[2];
    shape0->witnesses[0].mVec128.m128_f32[0] = (float)(shape0->normal.mVec128.m128_f32[0] * v51)
                                             + shape0->witnesses[0].mVec128.m128_f32[0];
    shape0->witnesses[0].mVec128.m128_f32[1] = *(float *)&v41;
    shape0->witnesses[0].mVec128.m128_f32[2] = v42;
    return v39 - v51;
  }
}


char __usercall btGjkEpaSolver2::SignedDistance@<al>(
        const btTransform *wtrs0@<ecx>,
        const gjkepa2_impl::MinkowskiDiff *guess@<eax>,
        const btConvexShape *shape0,
        const btConvexShape *shape1,
        const btTransform *wtrs1,
        btGjkEpaSolver2::sResults *results)
{
  if ( btGjkEpaSolver2::Distance(shape0, wtrs0, shape1, wtrs1, (const btVector3 *)guess, results) )
    return 1;
  else
    return btGjkEpaSolver2::Penetration(shape0, wtrs0, shape1, wtrs1, guess, results, 0);
}
