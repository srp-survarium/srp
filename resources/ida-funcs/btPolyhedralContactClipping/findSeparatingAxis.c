char __cdecl btPolyhedralContactClipping::findSeparatingAxis(
        btConvexPolyhedron *hullA,
        btConvexPolyhedron *hullB,
        const btTransform *transA,
        const btTransform *transB,
        btVector3 *sep)
{
  btConvexPolyhedron *v5; // ecx
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  const btTransform *v9; // eax
  btConvexPolyhedron *v10; // edx
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  int m_size; // esi
  float v24; // xmm5_4
  float *v25; // esi
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm4_4
  unsigned int v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  unsigned int v35; // xmm2_4
  float v36; // xmm3_4
  btVector3 *v37; // ecx
  float v38; // xmm0_4
  float *v39; // esi
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm2_4
  float v44; // xmm6_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm6_4
  btVector3 *v49; // ecx
  float v50; // xmm0_4
  bool v51; // cc
  btVector3 *v52; // esi
  float v53; // xmm2_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  float v56; // xmm6_4
  float v57; // xmm1_4
  btVector3 *v58; // esi
  float v59; // xmm4_4
  float v60; // xmm3_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  float v66; // xmm5_4
  float v67; // xmm1_4
  float v68; // xmm3_4
  btVector3 *v69; // ecx
  float v70; // xmm0_4
  float v71; // xmm4_4
  float v72; // xmm5_4
  int v73; // xmm6_4
  float v75; // [esp+18h] [ebp-6Ch]
  int v76; // [esp+1Ch] [ebp-68h]
  int v77; // [esp+1Ch] [ebp-68h]
  int v78; // [esp+1Ch] [ebp-68h]
  int v79; // [esp+20h] [ebp-64h]
  int v80; // [esp+20h] [ebp-64h]
  int v81; // [esp+20h] [ebp-64h]
  int v82; // [esp+24h] [ebp-60h]
  float v83; // [esp+28h] [ebp-5Ch]
  int v84; // [esp+28h] [ebp-5Ch]
  int v85; // [esp+28h] [ebp-5Ch]
  int v86; // [esp+28h] [ebp-5Ch]
  float v87; // [esp+2Ch] [ebp-58h] BYREF
  float v88; // [esp+30h] [ebp-54h] BYREF
  btVector3 v89; // [esp+34h] [ebp-50h] BYREF
  float v90; // [esp+44h] [ebp-40h]
  float v91; // [esp+48h] [ebp-3Ch]
  float v92; // [esp+4Ch] [ebp-38h]
  int v93; // [esp+50h] [ebp-34h]
  btVector3 v94; // [esp+54h] [ebp-30h] BYREF
  btVector3 v95; // [esp+64h] [ebp-20h] BYREF
  float v96; // [esp+74h] [ebp-10h]
  unsigned __int64 v97; // [esp+78h] [ebp-Ch]
  int v98; // [esp+80h] [ebp-4h]

  v5 = hullA;
  v6 = hullA->m_localCenter.mVec128.m128_f32[2];
  v7 = hullA->m_localCenter.mVec128.m128_f32[1];
  v8 = hullA->m_localCenter.mVec128.m128_f32[0];
  v9 = transB;
  v10 = hullB;
  v11 = hullB->m_localCenter.mVec128.m128_f32[1];
  v12 = hullB->m_localCenter.mVec128.m128_f32[2];
  v13 = (float)((float)(v7 * transA->m_basis.m_el[0].mVec128.m128_f32[1])
              + (float)(v6 * transA->m_basis.m_el[0].mVec128.m128_f32[2]))
      + (float)(v8 * transA->m_basis.m_el[0].mVec128.m128_f32[0]);
  v14 = transA->m_basis.m_el[1].mVec128.m128_f32[0] * v8;
  v15 = v8 * transA->m_basis.m_el[2].mVec128.m128_f32[0];
  v16 = v13 + transA->m_origin.mVec128.m128_f32[0];
  v17 = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v7)
              + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * v6))
      + v14;
  v18 = transA->m_basis.m_el[2].mVec128.m128_f32[1] * v7;
  v19 = transA->m_basis.m_el[2].mVec128.m128_f32[2] * v6;
  v20 = v17 + transA->m_origin.mVec128.m128_f32[1];
  ++gActualSATPairTests;
  v21 = (float)((float)(v18 + v19) + v15) + transA->m_origin.mVec128.m128_f32[2];
  v83 = hullB->m_localCenter.mVec128.m128_f32[0];
  v22 = (float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v11)
                      + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v12))
              + (float)(v83 * transB->m_basis.m_el[1].mVec128.m128_f32[0]))
      + transB->m_origin.mVec128.m128_f32[1];
  m_size = hullA->m_faces.m_size;
  v24 = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v11)
                      + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v12))
              + (float)(v83 * transB->m_basis.m_el[2].mVec128.m128_f32[0]))
      + transB->m_origin.mVec128.m128_f32[2];
  v89.mVec128.m128_f32[0] = v16
                          - (float)((float)((float)((float)(v83 * transB->m_basis.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v11 * transB->m_basis.m_el[0].mVec128.m128_f32[1]))
                                          + (float)(v12 * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
                                  + transB->m_origin.mVec128.m128_f32[0]);
  v89.mVec128.m128_f32[1] = v20 - v22;
  v89.mVec128.m128_f32[2] = v21 - v24;
  v89.mVec128.m128_i32[3] = 0;
  v75 = FLOAT_3_4028235e38;
  v84 = m_size;
  v79 = 0;
  if ( m_size > 0 )
  {
    v94.mVec128.m128_i32[3] = 0;
    v76 = 0;
    do
    {
      v25 = (float *)&v5->m_faces.m_data[v76];
      v26 = v25[5];
      v27 = v25[7];
      v28 = v25[6];
      *(float *)&v29 = (float)((float)(transA->m_basis.m_el[0].mVec128.m128_f32[0] * v26)
                             + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[2] * v27))
                     + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[1] * v28);
      v30 = transA->m_basis.m_el[1].mVec128.m128_f32[2] * v27;
      v31 = v27 * transA->m_basis.m_el[2].mVec128.m128_f32[2];
      v32 = (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * v26) + v30;
      v33 = transA->m_basis.m_el[1].mVec128.m128_f32[1] * v28;
      v34 = v28 * transA->m_basis.m_el[2].mVec128.m128_f32[1];
      *(float *)&v35 = v32 + v33;
      v36 = transA->m_basis.m_el[2].mVec128.m128_f32[0];
      v94.mVec128.m128_u64[0] = __PAIR64__(v35, v29);
      v94.mVec128.m128_f32[2] = (float)((float)(v36 * v26) + v31) + v34;
      if ( (float)((float)((float)(*(float *)&v29 * v89.mVec128.m128_f32[0])
                         + (float)(v94.mVec128.m128_f32[2] * v89.mVec128.m128_f32[2]))
                 + (float)(*(float *)&v35 * v89.mVec128.m128_f32[1])) >= 0.0 )
      {
        ++gExpectedNbTests;
        if ( TestInternalObjects(v9, &v89, &v94, v5, transA, v10, v75) )
        {
          ++gActualNbTests;
          if ( !TestSepAxis(hullA, hullB, transA, transB, &v87) )
            return 0;
          v38 = v87;
          if ( v75 > v87 )
          {
            *sep = (btVector3)v37->mVec128;
            v75 = v38;
          }
        }
        v9 = transB;
        v5 = hullA;
        v10 = hullB;
      }
      ++v79;
      ++v76;
    }
    while ( v79 < v84 );
  }
  v85 = v10->m_faces.m_size;
  v77 = 0;
  if ( v85 > 0 )
  {
    v94.mVec128.m128_i32[3] = 0;
    v80 = 0;
    do
    {
      v39 = (float *)&v10->m_faces.m_data[v80];
      v40 = v39[6];
      v41 = v39[7];
      v42 = v39[5];
      v43 = v9->m_basis.m_el[1].mVec128.m128_f32[2] * v41;
      v44 = v9->m_basis.m_el[1].mVec128.m128_f32[1] * v40;
      v45 = (float)(v41 * v9->m_basis.m_el[2].mVec128.m128_f32[2])
          + (float)(v40 * v9->m_basis.m_el[2].mVec128.m128_f32[1]);
      v46 = v9->m_basis.m_el[2].mVec128.m128_f32[0];
      v47 = v43 + v44;
      v48 = v9->m_basis.m_el[1].mVec128.m128_f32[0];
      v94.mVec128.m128_f32[0] = (float)((float)(v39[7] * v9->m_basis.m_el[0].mVec128.m128_f32[2])
                                      + (float)(v39[6] * v9->m_basis.m_el[0].mVec128.m128_f32[1]))
                              + (float)(v9->m_basis.m_el[0].mVec128.m128_f32[0] * v42);
      v94.mVec128.m128_f32[2] = v45 + (float)(v46 * v42);
      v94.mVec128.m128_f32[1] = v47 + (float)(v48 * v42);
      if ( (float)((float)((float)(v94.mVec128.m128_f32[0] * v89.mVec128.m128_f32[0])
                         + (float)(v94.mVec128.m128_f32[2] * v89.mVec128.m128_f32[2]))
                 + (float)(v94.mVec128.m128_f32[1] * v89.mVec128.m128_f32[1])) >= 0.0 )
      {
        ++gExpectedNbTests;
        if ( TestInternalObjects(v9, &v89, &v94, v5, transA, v10, v75) )
        {
          ++gActualNbTests;
          if ( !TestSepAxis(hullA, hullB, transA, transB, &v87) )
            return 0;
          v50 = v87;
          if ( v75 > v87 )
          {
            *sep = (btVector3)v49->mVec128;
            v75 = v50;
          }
        }
        v9 = transB;
        v5 = hullA;
        v10 = hullB;
      }
      ++v77;
      ++v80;
    }
    while ( v77 < v85 );
  }
  v51 = v5->m_uniqueEdges.m_size <= 0;
  v87 = 0.0;
  v86 = 0;
  if ( !v51 )
  {
    v82 = 0;
    do
    {
      v52 = &v5->m_uniqueEdges.m_data[v82];
      v53 = transA->m_basis.m_el[0].mVec128.m128_f32[0];
      v54 = transA->m_basis.m_el[0].mVec128.m128_f32[1];
      v55 = transA->m_basis.m_el[0].mVec128.m128_f32[2];
      v96 = v52->mVec128.m128_f32[0];
      v52 = (btVector3 *)((char *)v52 + 4);
      LODWORD(v97) = v52->mVec128.m128_i32[0];
      v52 = (btVector3 *)((char *)v52 + 4);
      HIDWORD(v97) = v52->mVec128.m128_i32[0];
      v98 = v52->mVec128.m128_i32[1];
      v94.mVec128.m128_f32[0] = (float)((float)(v53 * v96) + (float)(v54 * *(float *)&v97))
                              + (float)(v55 * *((float *)&v97 + 1));
      v56 = (float)((float)(*(float *)&v97 * transA->m_basis.m_el[1].mVec128.m128_f32[1])
                  + (float)(*((float *)&v97 + 1) * transA->m_basis.m_el[1].mVec128.m128_f32[2]))
          + (float)(v96 * transA->m_basis.m_el[1].mVec128.m128_f32[0]);
      v51 = v10->m_uniqueEdges.m_size <= 0;
      v57 = (float)((float)(*(float *)&v97 * transA->m_basis.m_el[2].mVec128.m128_f32[1])
                  + (float)(*((float *)&v97 + 1) * transA->m_basis.m_el[2].mVec128.m128_f32[2]))
          + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * v96);
      v94.mVec128.m128_f32[1] = v56;
      v94.mVec128.m128_f32[2] = v57;
      v78 = 0;
      if ( !v51 )
      {
        v95.mVec128.m128_i32[3] = 0;
        v81 = 0;
        do
        {
          v58 = &v10->m_uniqueEdges.m_data[v81];
          v59 = v9->m_basis.m_el[2].mVec128.m128_f32[1];
          v90 = v58->mVec128.m128_f32[0];
          v58 = (btVector3 *)((char *)v58 + 4);
          v91 = v58->mVec128.m128_f32[0];
          v58 = (btVector3 *)((char *)v58 + 4);
          v92 = v58->mVec128.m128_f32[0];
          v93 = v58->mVec128.m128_i32[1];
          v60 = (float)((float)(v91 * v9->m_basis.m_el[0].mVec128.m128_f32[1])
                      + (float)(v92 * v9->m_basis.m_el[0].mVec128.m128_f32[2]))
              + (float)(v90 * v9->m_basis.m_el[0].mVec128.m128_f32[0]);
          v61 = (float)(v91 * v9->m_basis.m_el[1].mVec128.m128_f32[1])
              + (float)(v92 * v9->m_basis.m_el[1].mVec128.m128_f32[2]);
          v62 = v90 * v9->m_basis.m_el[1].mVec128.m128_f32[0];
          ++LODWORD(v87);
          v63 = v61 + v62;
          v64 = (float)((float)(v9->m_basis.m_el[2].mVec128.m128_f32[0] * v90) + (float)(v59 * v91))
              + (float)(v9->m_basis.m_el[2].mVec128.m128_f32[2] * v92);
          v65 = (float)(v94.mVec128.m128_f32[2] * v60) - (float)(v64 * v94.mVec128.m128_f32[0]);
          v66 = (float)(v64 * v56) - (float)(v63 * v94.mVec128.m128_f32[2]);
          v67 = (float)(v63 * v94.mVec128.m128_f32[0]) - (float)(v56 * v60);
          if ( COERCE_FLOAT(LODWORD(v66) & _mask__AbsFloat_) > 0.000001
            || COERCE_FLOAT(LODWORD(v65) & _mask__AbsFloat_) > 0.000001
            || COERCE_FLOAT(LODWORD(v67) & _mask__AbsFloat_) > 0.000001 )
          {
            v68 = s_bm_current_air_resistance
                / fsqrt((float)((float)(v66 * v66) + (float)(v67 * v67)) + (float)(v65 * v65));
            v95.mVec128.m128_f32[0] = v68 * v66;
            v95.mVec128.m128_f32[2] = v67 * v68;
            v95.mVec128.m128_f32[1] = v65 * v68;
            if ( (float)((float)((float)((float)(v68 * v66) * v89.mVec128.m128_f32[0])
                               + (float)((float)(v67 * v68) * v89.mVec128.m128_f32[2]))
                       + (float)((float)(v65 * v68) * v89.mVec128.m128_f32[1])) >= 0.0 )
            {
              ++gExpectedNbTests;
              if ( TestInternalObjects(v9, &v89, &v95, v5, transA, v10, v75) )
              {
                ++gActualNbTests;
                if ( !TestSepAxis(hullA, hullB, transA, transB, &v88) )
                  return 0;
                v70 = v88;
                if ( v75 > v88 )
                {
                  *sep = (btVector3)v69->mVec128;
                  v75 = v70;
                }
              }
              v9 = transB;
              v5 = hullA;
              v10 = hullB;
              v56 = v94.mVec128.m128_f32[1];
            }
          }
          ++v78;
          ++v81;
        }
        while ( v78 < v10->m_uniqueEdges.m_size );
      }
      ++v86;
      ++v82;
    }
    while ( v86 < v5->m_uniqueEdges.m_size );
  }
  v71 = sep->mVec128.m128_f32[2];
  v72 = sep->mVec128.m128_f32[1];
  v73 = sep->mVec128.m128_i32[0];
  if ( (float)((float)((float)((float)(v9->m_origin.mVec128.m128_f32[1] - transA->m_origin.mVec128.m128_f32[1]) * v72)
                     + (float)((float)(v9->m_origin.mVec128.m128_f32[2] - transA->m_origin.mVec128.m128_f32[2]) * v71))
             + (float)((float)(v9->m_origin.mVec128.m128_f32[0] - transA->m_origin.mVec128.m128_f32[0])
                     * sep->mVec128.m128_f32[0])) > 0.0 )
  {
    v98 = 0;
    LODWORD(v96) = v73 ^ _mask__NegFloat_;
    LODWORD(v97) = LODWORD(v72) ^ _mask__NegFloat_;
    HIDWORD(v97) = LODWORD(v71) ^ _mask__NegFloat_;
    sep->mVec128.m128_i32[0] = v73 ^ _mask__NegFloat_;
    *(unsigned __int64 *)((char *)sep->mVec128.m128_u64 + 4) = v97;
    sep->mVec128.m128_i32[3] = v98;
  }
  return 1;
}
