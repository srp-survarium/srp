gjkepa2_impl::EPA::eStatus::_ __thiscall gjkepa2_impl::EPA::Evaluate(
        gjkepa2_impl::EPA *this,
        gjkepa2_impl::EPA *gjk,
        gjkepa2_impl::GJK *guess,
        const btVector3 *guessa)
{
  gjkepa2_impl::GJK::sSV **c; // esi
  int root; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  float *v9; // eax
  float *v10; // ecx
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float *v14; // ecx
  float v15; // xmm6_4
  float v16; // xmm1_4
  gjkepa2_impl::GJK::sSV *v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  gjkepa2_impl::GJK::sSV *v21; // xmm0_4
  gjkepa2_impl::EPA::sFace *v22; // eax
  gjkepa2_impl::GJK::sSV *v23; // edx
  gjkepa2_impl::GJK::sSV *v24; // edi
  gjkepa2_impl::EPA::sFace *v25; // eax
  gjkepa2_impl::GJK::sSV *v26; // edi
  gjkepa2_impl::EPA::sFace *v27; // eax
  gjkepa2_impl::GJK::sSV *v28; // ecx
  gjkepa2_impl::GJK::sSV *v29; // edi
  gjkepa2_impl::EPA::sFace *v30; // eax
  gjkepa2_impl::EPA *v31; // ecx
  bool v32; // zf
  gjkepa2_impl::EPA::sFace *v33; // eax
  int v34; // edx
  unsigned __int64 v35; // kr00_8
  int v36; // ecx
  unsigned int m_nextsv; // ecx
  int v38; // edi
  gjkepa2_impl::GJK::sSV *v39; // eax
  int v40; // esi
  gjkepa2_impl::EPA::sFace *ff; // eax
  gjkepa2_impl::EPA::sFace *cf; // ecx
  int v43; // eax
  int v44; // eax
  gjkepa2_impl::EPA *v45; // ecx
  int v46; // eax
  float v47; // xmm0_4
  gjkepa2_impl::GJK::sSV *v48; // eax
  gjkepa2_impl::GJK::sSV *v49; // edi
  gjkepa2_impl::GJK::sSV *v50; // esi
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  unsigned __int64 v54; // xmm2_8
  unsigned int v55; // xmm1_4
  unsigned int v56; // xmm4_4
  float v57; // xmm5_4
  float v58; // xmm3_4
  float v59; // xmm0_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm1_4
  float *v63; // eax
  float v64; // xmm6_4
  float v65; // xmm0_4
  float v66; // xmm3_4
  float v67; // xmm1_4
  float v68; // xmm1_4
  float v69; // xmm0_4
  float v70; // xmm6_4
  float v71; // xmm5_4
  float v72; // xmm3_4
  float v73; // xmm1_4
  gjkepa2_impl::EPA::eStatus::_ result; // eax
  float v75; // xmm0_4
  float v76; // xmm1_4
  long double v77; // st7
  const vostok::math::float4x4 *v78; // xmm1_4
  gjkepa2_impl::GJK::sSV *v79; // [esp+3B2h] [ebp-8Ch]
  gjkepa2_impl::GJK::sSV *v80; // [esp+3B6h] [ebp-88h]
  char v81; // [esp+3CDh] [ebp-71h]
  unsigned int v82; // [esp+3CEh] [ebp-70h]
  float *v83; // [esp+3D2h] [ebp-6Ch]
  gjkepa2_impl::EPA::sFace **v84; // [esp+3D2h] [ebp-6Ch]
  float v85; // [esp+3D2h] [ebp-6Ch]
  gjkepa2_impl::GJK::sSV *v86; // [esp+3D6h] [ebp-68h]
  float v87; // [esp+3D6h] [ebp-68h]
  int v88; // [esp+3DAh] [ebp-64h]
  float v89; // [esp+3DAh] [ebp-64h]
  float v90; // [esp+3DAh] [ebp-64h]
  gjkepa2_impl::EPA::sHorizon v91; // [esp+3DEh] [ebp-60h] BYREF
  unsigned __int64 v92; // [esp+3EEh] [ebp-50h]
  unsigned __int64 v93; // [esp+3F6h] [ebp-48h]
  _QWORD v94[8]; // [esp+3FEh] [ebp-40h] BYREF

  c = guess->m_simplex->c;
  if ( (unsigned int)c[8] <= 1 || !gjkepa2_impl::GJK::EncloseOrigin(guess) )
    goto LABEL_41;
  for ( ; gjk->m_hull.root; gjk->m_stock.root = (gjkepa2_impl::EPA::sFace *)root )
  {
    root = (int)gjk->m_hull.root;
    v6 = *(_DWORD *)(root + 52);
    if ( v6 )
      *(_DWORD *)(v6 + 48) = *(_DWORD *)(root + 48);
    v7 = *(_DWORD *)(root + 48);
    if ( v7 )
      *(_DWORD *)(v7 + 52) = *(_DWORD *)(root + 52);
    if ( (gjkepa2_impl::EPA::sFace *)root == gjk->m_hull.root )
      gjk->m_hull.root = *(gjkepa2_impl::EPA::sFace **)(root + 52);
    --gjk->m_hull.count;
    *(_DWORD *)(root + 48) = 0;
    *(_DWORD *)(root + 52) = gjk->m_stock.root;
    v8 = (int)gjk->m_stock.root;
    if ( v8 )
      *(_DWORD *)(v8 + 48) = root;
    ++gjk->m_stock.count;
  }
  gjk->m_status = Valid;
  gjk->m_nextsv = 0;
  v9 = (float *)c[3];
  v10 = (float *)c[2];
  v11 = v10[5] - v9[5];
  v12 = v10[4] - v9[4];
  v13 = v10[6] - v9[6];
  v14 = (float *)c[1];
  v15 = v14[4] - v9[4];
  *((float *)&v92 + 1) = v14[5] - v9[5];
  v16 = v14[6];
  v17 = *c;
  v18 = (*c)->w.mVec128.m128_f32[2] - v9[6];
  v19 = v16 - v9[6];
  *(float *)&v91.cf = (*c)->w.mVec128.m128_f32[0] - v9[4];
  v20 = v17->w.mVec128.m128_f32[1] - v9[5];
  *(float *)&v92 = v15;
  if ( (float)((float)((float)((float)((float)((float)((float)(v18 * v11) * v15) + (float)((float)(v20 * v19) * v12))
                                     - (float)((float)(v19 * v11) * *(float *)&v91.cf))
                             - (float)((float)(v20 * v13) * v15))
                     + (float)((float)(v13 * *((float *)&v92 + 1)) * *(float *)&v91.cf))
             - (float)((float)(v18 * *((float *)&v92 + 1)) * v12)) < 0.0 )
  {
    *c = c[1];
    v21 = c[4];
    c[4] = c[5];
    c[1] = v17;
    c[5] = v21;
  }
  v22 = gjkepa2_impl::EPA::newface(gjk, *c, c[1], c[2], 1);
  v23 = c[3];
  v24 = c[1];
  LODWORD(v92) = v22;
  v25 = gjkepa2_impl::EPA::newface(gjk, v24, *c, v23, 1);
  v26 = c[2];
  v80 = c[3];
  v79 = c[1];
  HIDWORD(v92) = v25;
  v27 = gjkepa2_impl::EPA::newface(gjk, v26, v79, v80, 1);
  v28 = c[2];
  v29 = *c;
  LODWORD(v93) = v27;
  v30 = gjkepa2_impl::EPA::newface(gjk, v29, v28, c[3], 1);
  v32 = gjk->m_hull.count == 4;
  HIDWORD(v93) = v30;
  if ( v32 )
  {
    v33 = gjkepa2_impl::EPA::findbest(v31);
    v34 = HIDWORD(v92);
    qmemcpy(v94, v33, sizeof(v94));
    v35 = v93;
    v82 = 0;
    v88 = 0;
    v36 = v92;
    *(_BYTE *)(v92 + 56) = 0;
    *(_DWORD *)(v36 + 36) = v34;
    *(_BYTE *)(v34 + 56) = 0;
    *(_DWORD *)(v34 + 36) = v36;
    *(_BYTE *)(v36 + 57) = 0;
    *(_DWORD *)(v36 + 40) = v35;
    *(_BYTE *)(v35 + 56) = 1;
    *(_DWORD *)(v35 + 36) = v36;
    *(_BYTE *)(v36 + 58) = 0;
    *(_DWORD *)(v36 + 44) = HIDWORD(v35);
    *(_BYTE *)(HIDWORD(v35) + 56) = 2;
    *(_DWORD *)(HIDWORD(v35) + 36) = v36;
    *(_BYTE *)(v34 + 57) = 2;
    *(_DWORD *)(v34 + 40) = HIDWORD(v35);
    *(_BYTE *)(HIDWORD(v35) + 58) = 1;
    *(_DWORD *)(HIDWORD(v35) + 44) = v34;
    *(_BYTE *)(v34 + 58) = 1;
    *(_DWORD *)(v34 + 44) = v35;
    *(_BYTE *)(v35 + 57) = 2;
    *(_DWORD *)(v35 + 40) = v34;
    *(_BYTE *)(v35 + 58) = 1;
    *(_DWORD *)(v35 + 44) = HIDWORD(v35);
    *(_BYTE *)(HIDWORD(v35) + 57) = 2;
    *(_DWORD *)(HIDWORD(v35) + 40) = v35;
    v83 = (float *)v33;
    gjk->m_status = Valid;
    while ( 1 )
    {
      m_nextsv = gjk->m_nextsv;
      if ( m_nextsv >= 0x40 )
        break;
      memset(&v91, 0, sizeof(v91));
      gjk->m_nextsv = m_nextsv + 1;
      v33->pass = ++v82;
      v86 = &gjk->m_sv_store[m_nextsv];
      v81 = 1;
      gjkepa2_impl::GJK::getsupport(&v33->n, v86, guess);
      v38 = (int)v83;
      v39 = v86;
      if ( (float)((float)((float)((float)(v86->w.mVec128.m128_f32[2] * v83[2])
                                 + (float)(v86->w.mVec128.m128_f32[1] * v83[1]))
                         + (float)(v86->w.mVec128.m128_f32[0] * *v83))
                 - v83[4]) <= 0.000099999997 )
      {
        gjk->m_status = Failed|Inside|0x4;
        goto LABEL_40;
      }
      v40 = 0;
      v84 = (gjkepa2_impl::EPA::sFace **)(v83 + 9);
      while ( 1 )
      {
        if ( !v81 )
          goto LABEL_37;
        v81 &= gjkepa2_impl::EPA::expand(gjk, v82, v39, *v84++, *(unsigned __int8 *)(v40 + v38 + 56), &v91);
        if ( (unsigned int)++v40 >= 3 )
          break;
        v39 = v86;
      }
      if ( !v81 || v91.nf < 3 )
      {
LABEL_37:
        gjk->m_status = 4;
        goto LABEL_40;
      }
      ff = v91.ff;
      cf = v91.cf;
      v91.cf->e[1] = 2;
      cf->f[1] = ff;
      ff->e[2] = 1;
      ff->f[2] = cf;
      v43 = *(_DWORD *)(v38 + 52);
      if ( v43 )
        *(_DWORD *)(v43 + 48) = *(_DWORD *)(v38 + 48);
      v44 = *(_DWORD *)(v38 + 48);
      if ( v44 )
        *(_DWORD *)(v44 + 52) = *(_DWORD *)(v38 + 52);
      if ( (gjkepa2_impl::EPA::sFace *)v38 == gjk->m_hull.root )
        gjk->m_hull.root = *(gjkepa2_impl::EPA::sFace **)(v38 + 52);
      --gjk->m_hull.count;
      *(_DWORD *)(v38 + 48) = 0;
      v45 = (gjkepa2_impl::EPA *)gjk->m_stock.root;
      *(_DWORD *)(v38 + 52) = v45;
      v46 = (int)gjk->m_stock.root;
      if ( v46 )
        *(_DWORD *)(v46 + 48) = v38;
      ++gjk->m_stock.count;
      gjk->m_stock.root = (gjkepa2_impl::EPA::sFace *)v38;
      v33 = gjkepa2_impl::EPA::findbest(v45);
      v83 = (float *)v33;
      if ( v33->p >= *((float *)&v94[2] + 1) )
        qmemcpy(v94, v33, sizeof(v94));
      if ( (unsigned int)++v88 >= 0xFF )
        goto LABEL_40;
    }
    gjk->m_status = 6;
LABEL_40:
    v47 = *(float *)&v94[2];
    v48 = (gjkepa2_impl::GJK::sSV *)v94[4];
    v49 = (gjkepa2_impl::GJK::sSV *)HIDWORD(v94[3]);
    v50 = (gjkepa2_impl::GJK::sSV *)v94[3];
    v51 = *(float *)v94;
    v52 = *((float *)v94 + 1);
    v53 = *(float *)&v94[1];
    gjk->m_normal.mVec128.m128_u64[0] = v94[0];
    v54 = v94[1];
    *(float *)&v55 = v51 * v47;
    gjk->m_depth = v47;
    gjk->m_normal.mVec128.m128_u64[1] = v54;
    *(float *)&v56 = v52 * v47;
    v57 = v53 * v47;
    gjk->m_result.c[2] = v48;
    gjk->m_result.rank = 3;
    gjk->m_result.c[0] = v50;
    gjk->m_result.c[1] = v49;
    v58 = v49->w.mVec128.m128_f32[1];
    v59 = v48->w.mVec128.m128_f32[1] - *(float *)&v56;
    *(float *)&v54 = v48->w.mVec128.m128_f32[2] - v57;
    v60 = v49->w.mVec128.m128_f32[0] - *(float *)&v55;
    v61 = v48->w.mVec128.m128_f32[0] - *(float *)&v55;
    v92 = __PAIR64__(v56, v55);
    v62 = v49->w.mVec128.m128_f32[2] - v57;
    *(float *)&v93 = v57;
    v85 = sqrtf(
            (float)((float)((float)((float)(v59 * v60) - (float)((float)(v58 - *(float *)&v56) * v61))
                          * (float)((float)(v59 * v60) - (float)((float)(v58 - *(float *)&v56) * v61)))
                  + (float)((float)((float)(v62 * v61) - (float)(*(float *)&v54 * v60))
                          * (float)((float)(v62 * v61) - (float)(*(float *)&v54 * v60))))
          + (float)((float)((float)((float)(v58 - *(float *)&v56) * *(float *)&v54) - (float)(v62 * v59))
                  * (float)((float)((float)(v58 - *(float *)&v56) * *(float *)&v54) - (float)(v62 * v59))));
    v63 = (float *)v94[4];
    gjk->m_result.p[0] = v85;
    v64 = v63[4] - *(float *)&v92;
    v65 = v50->w.mVec128.m128_f32[1] - *((float *)&v92 + 1);
    *(float *)&v54 = v50->w.mVec128.m128_f32[2] - *(float *)&v93;
    v66 = v63[5] - *((float *)&v92 + 1);
    v67 = v63[6] - *(float *)&v93;
    v87 = sqrtf(
            (float)((float)((float)((float)(v65 * v64)
                                  - (float)(v66 * (float)(v50->w.mVec128.m128_f32[0] - *(float *)&v92)))
                          * (float)((float)(v65 * v64)
                                  - (float)(v66 * (float)(v50->w.mVec128.m128_f32[0] - *(float *)&v92))))
                  + (float)((float)((float)(v67 * (float)(v50->w.mVec128.m128_f32[0] - *(float *)&v92))
                                  - (float)(*(float *)&v54 * v64))
                          * (float)((float)(v67 * (float)(v50->w.mVec128.m128_f32[0] - *(float *)&v92))
                                  - (float)(*(float *)&v54 * v64))))
          + (float)((float)((float)(v66 * *(float *)&v54) - (float)(v67 * v65))
                  * (float)((float)(v66 * *(float *)&v54) - (float)(v67 * v65))));
    v68 = *(float *)&v92;
    gjk->m_result.p[1] = v87;
    v69 = v49->w.mVec128.m128_f32[1] - *((float *)&v92 + 1);
    *(float *)&v54 = v49->w.mVec128.m128_f32[2] - *(float *)&v93;
    v70 = v50->w.mVec128.m128_f32[0] - v68;
    v71 = v49->w.mVec128.m128_f32[0] - v68;
    v72 = v50->w.mVec128.m128_f32[1] - *((float *)&v92 + 1);
    v73 = v50->w.mVec128.m128_f32[2] - *(float *)&v93;
    v89 = sqrtf(
            (float)((float)((float)((float)(v69 * v70) - (float)(v72 * v71))
                          * (float)((float)(v69 * v70) - (float)(v72 * v71)))
                  + (float)((float)((float)(v73 * v71) - (float)(*(float *)&v54 * v70))
                          * (float)((float)(v73 * v71) - (float)(*(float *)&v54 * v70))))
          + (float)((float)((float)(v72 * *(float *)&v54) - (float)(v73 * v69))
                  * (float)((float)(v72 * *(float *)&v54) - (float)(v73 * v69))));
    result = gjk->m_status;
    v75 = *(float *)&clear_value / (float)((float)(v89 + v87) + v85);
    gjk->m_result.p[0] = v75 * v85;
    gjk->m_result.p[1] = v75 * v87;
    gjk->m_result.p[2] = v75 * v89;
  }
  else
  {
LABEL_41:
    gjk->m_status = 8;
    *(float *)&v92 = -guessa->mVec128.m128_f32[0];
    *((float *)&v92 + 1) = -guessa->mVec128.m128_f32[1];
    v76 = -guessa->mVec128.m128_f32[2];
    HIDWORD(v93) = 0;
    gjk->m_normal.mVec128.m128_u64[0] = v92;
    *(float *)&v93 = v76;
    gjk->m_normal.mVec128.m128_u64[1] = v93;
    v77 = sqrtf(
            (float)((float)(gjk->m_normal.mVec128.m128_f32[0] * gjk->m_normal.mVec128.m128_f32[0])
                  + (float)(gjk->m_normal.mVec128.m128_f32[1] * gjk->m_normal.mVec128.m128_f32[1]))
          + (float)(gjk->m_normal.mVec128.m128_f32[2] * gjk->m_normal.mVec128.m128_f32[2]));
    v90 = v77;
    v78 = clear_value;
    if ( v77 <= 0.0 )
    {
      v92 = (unsigned int)clear_value;
      LODWORD(v93) = 0;
    }
    else
    {
      *(float *)&v92 = gjk->m_normal.mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v90);
      *((float *)&v92 + 1) = gjk->m_normal.mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v90);
      *(float *)&v93 = gjk->m_normal.mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v90);
    }
    gjk->m_normal.mVec128.m128_u64[0] = v92;
    HIDWORD(v93) = 0;
    gjk->m_normal.mVec128.m128_u64[1] = v93;
    gjk->m_depth = 0.0;
    gjk->m_result.rank = 1;
    gjk->m_result.c[0] = *c;
    LODWORD(gjk->m_result.p[0]) = v78;
    return 8;
  }
  return result;
}
