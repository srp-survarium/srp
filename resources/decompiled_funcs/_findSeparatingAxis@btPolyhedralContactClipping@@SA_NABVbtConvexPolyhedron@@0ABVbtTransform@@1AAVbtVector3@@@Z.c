char __usercall btPolyhedralContactClipping::findSeparatingAxis@<al>(
        btConvexPolyhedron *hullA@<eax>,
        btConvexPolyhedron *hullB,
        const btTransform *transA,
        const btTransform *transB,
        btVector3 *sep)
{
  btConvexPolyhedron *v5; // ecx
  float v6; // xmm6_4
  float v7; // xmm7_4
  const btTransform *v8; // esi
  float v9; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  int m_size; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  int v21; // eax
  btFace *m_data; // edx
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  unsigned int v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  unsigned int v32; // xmm1_4
  float v33; // xmm2_4
  const btVector3 *v34; // edx
  float v35; // xmm0_4
  bool v36; // cc
  int v37; // eax
  btFace *v38; // edx
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm5_4
  const btVector3 *v47; // edx
  float v48; // xmm0_4
  float v49; // xmm5_4
  btVector3 *v50; // eoff
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm6_4
  float v54; // xmm0_4
  __m128 *p_mVec128; // eax
  float v56; // xmm7_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm0_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  float v62; // xmm0_4
  const btVector3 *v63; // edx
  float v64; // xmm0_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  unsigned int v67; // xmm5_4
  unsigned int v68; // xmm4_4
  float v70; // [esp+4D0h] [ebp-7Ch]
  int v71; // [esp+4D4h] [ebp-78h]
  int v72; // [esp+4D4h] [ebp-78h]
  int v73; // [esp+4D4h] [ebp-78h]
  float v74; // [esp+4D8h] [ebp-74h]
  int v75; // [esp+4D8h] [ebp-74h]
  int v76; // [esp+4D8h] [ebp-74h]
  int v77; // [esp+4D8h] [ebp-74h]
  float min; // [esp+4DCh] [ebp-70h] BYREF
  float max; // [esp+4E0h] [ebp-6Ch] BYREF
  float v80; // [esp+4E4h] [ebp-68h] BYREF
  float v81; // [esp+4E8h] [ebp-64h] BYREF
  int v82; // [esp+4ECh] [ebp-60h] BYREF
  float v83; // [esp+4F0h] [ebp-5Ch] BYREF
  float v84; // [esp+4F4h] [ebp-58h] BYREF
  float v85; // [esp+4F8h] [ebp-54h] BYREF
  btVector3 delta_c; // [esp+4FCh] [ebp-50h] BYREF
  btVector3 dir; // [esp+50Ch] [ebp-40h] BYREF
  btVector3 axis; // [esp+51Ch] [ebp-30h] BYREF
  unsigned __int64 v89; // [esp+52Ch] [ebp-20h]
  unsigned __int64 v90; // [esp+534h] [ebp-18h]
  unsigned __int64 v91; // [esp+53Ch] [ebp-10h]
  unsigned __int64 v92; // [esp+544h] [ebp-8h]

  v5 = hullB;
  v6 = hullB->m_localCenter.mVec128.m128_f32[2];
  v7 = hullB->m_localCenter.mVec128.m128_f32[1];
  v8 = transA;
  v9 = transA->m_basis.m_el[1].mVec128.m128_f32[2];
  v11 = hullA->m_localCenter.mVec128.m128_f32[1];
  v12 = hullA->m_localCenter.mVec128.m128_f32[0];
  v13 = hullA->m_localCenter.mVec128.m128_f32[2];
  v14 = transA->m_basis.m_el[1].mVec128.m128_f32[1];
  v15 = (float)((float)((float)(v12 * transA->m_basis.m_el[0].mVec128.m128_f32[0])
                      + (float)(v11 * transA->m_basis.m_el[0].mVec128.m128_f32[1]))
              + (float)(v13 * transA->m_basis.m_el[0].mVec128.m128_f32[2]))
      + transA->m_origin.mVec128.m128_f32[0];
  ++gActualSATPairTests;
  m_size = hullA->m_faces.m_size;
  v17 = (float)((float)((float)(v14 * v11) + (float)(v9 * v13))
              + (float)(v12 * transA->m_basis.m_el[1].mVec128.m128_f32[0]))
      + transA->m_origin.mVec128.m128_f32[1];
  v18 = (float)((float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v11)
                      + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v13))
              + (float)(v12 * transA->m_basis.m_el[2].mVec128.m128_f32[0]))
      + transA->m_origin.mVec128.m128_f32[2];
  v74 = hullB->m_localCenter.mVec128.m128_f32[0];
  v19 = (float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v7)
                      + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v6))
              + (float)(v74 * transB->m_basis.m_el[1].mVec128.m128_f32[0]))
      + transB->m_origin.mVec128.m128_f32[1];
  v20 = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v7)
                      + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v6))
              + (float)(v74 * transB->m_basis.m_el[2].mVec128.m128_f32[0]))
      + transB->m_origin.mVec128.m128_f32[2];
  delta_c.mVec128.m128_f32[0] = v15
                              - (float)((float)((float)((float)(v7 * transB->m_basis.m_el[0].mVec128.m128_f32[1])
                                                      + (float)(v6 * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
                                              + (float)(v74 * transB->m_basis.m_el[0].mVec128.m128_f32[0]))
                                      + transB->m_origin.mVec128.m128_f32[0]);
  delta_c.mVec128.m128_f32[1] = v17 - v19;
  delta_c.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v18 - v20);
  v70 = 3.4028235e38;
  v82 = m_size;
  v75 = 0;
  if ( m_size > 0 )
  {
    v21 = 0;
    axis.mVec128.m128_i32[3] = 0;
    v71 = 0;
    do
    {
      m_data = hullA->m_faces.m_data;
      v23 = *(float *)((char *)&m_data->m_plane[1] + v21);
      v24 = *(float *)((char *)&m_data->m_plane[2] + v21);
      v25 = *(float *)((char *)m_data->m_plane + v21);
      *(float *)&v26 = (float)((float)(v24 * v8->m_basis.m_el[0].mVec128.m128_f32[2])
                             + (float)(v23 * v8->m_basis.m_el[0].mVec128.m128_f32[1]))
                     + (float)(v8->m_basis.m_el[0].mVec128.m128_f32[0] * v25);
      v27 = v8->m_basis.m_el[1].mVec128.m128_f32[2] * v24;
      v28 = v24 * v8->m_basis.m_el[2].mVec128.m128_f32[2];
      v29 = (float)(v8->m_basis.m_el[1].mVec128.m128_f32[0] * v25) + v27;
      v30 = v8->m_basis.m_el[1].mVec128.m128_f32[1] * v23;
      v31 = v23 * v8->m_basis.m_el[2].mVec128.m128_f32[1];
      *(float *)&v32 = v29 + v30;
      v33 = v8->m_basis.m_el[2].mVec128.m128_f32[0];
      axis.mVec128.m128_u64[0] = __PAIR64__(v32, v26);
      axis.mVec128.m128_f32[2] = (float)((float)(v33 * v25) + v28) + v31;
      if ( (float)((float)((float)(*(float *)&v26 * delta_c.mVec128.m128_f32[0])
                         + (float)(axis.mVec128.m128_f32[2] * delta_c.mVec128.m128_f32[2]))
                 + (float)(*(float *)&v32 * delta_c.mVec128.m128_f32[1])) >= 0.0 )
      {
        ++gExpectedNbTests;
        if ( TestInternalObjects(transB, &delta_c, &axis, hullA, v8, v5, v70) )
        {
          ++gActualNbTests;
          btConvexPolyhedron::project(hullA, transA, v34, &min, &max);
          btConvexPolyhedron::project(hullB, transB, &axis, &v80, &v81);
          if ( v80 > max || min > v81 )
            return 0;
          v35 = v81 - min;
          if ( (float)(v81 - min) > (float)(max - v80) )
            v35 = max - v80;
          if ( v70 > v35 )
          {
            v70 = v35;
            *sep = (btVector3)axis.mVec128;
          }
        }
        v8 = transA;
      }
      v21 = v71 + 36;
      v36 = ++v75 < v82;
      v5 = hullB;
      v71 += 36;
    }
    while ( v36 );
  }
  min = *(float *)&v5->m_faces.m_size;
  v76 = 0;
  if ( SLODWORD(min) > 0 )
  {
    v37 = 0;
    axis.mVec128.m128_i32[3] = 0;
    v72 = 0;
    do
    {
      v38 = v5->m_faces.m_data;
      v39 = *(float *)((char *)&v38->m_plane[2] + v37);
      v40 = *(float *)((char *)v38->m_plane + v37);
      v41 = *(float *)((char *)&v38->m_plane[1] + v37);
      v42 = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v40)
                  + (float)(v39 * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
          + (float)(v41 * transB->m_basis.m_el[0].mVec128.m128_f32[1]);
      v43 = (float)(v39 * transB->m_basis.m_el[2].mVec128.m128_f32[2])
          + (float)(v41 * transB->m_basis.m_el[2].mVec128.m128_f32[1]);
      v44 = transB->m_basis.m_el[2].mVec128.m128_f32[0];
      v45 = (float)(*(float *)((char *)&v38->m_plane[2] + v37) * transB->m_basis.m_el[1].mVec128.m128_f32[2])
          + (float)(*(float *)((char *)&v38->m_plane[1] + v37) * transB->m_basis.m_el[1].mVec128.m128_f32[1]);
      v46 = transB->m_basis.m_el[1].mVec128.m128_f32[0];
      axis.mVec128.m128_f32[0] = v42;
      axis.mVec128.m128_f32[2] = v43 + (float)(v44 * v40);
      axis.mVec128.m128_f32[1] = v45 + (float)(v46 * v40);
      if ( (float)((float)((float)(v42 * delta_c.mVec128.m128_f32[0])
                         + (float)(axis.mVec128.m128_f32[2] * delta_c.mVec128.m128_f32[2]))
                 + (float)(axis.mVec128.m128_f32[1] * delta_c.mVec128.m128_f32[1])) >= 0.0 )
      {
        ++gExpectedNbTests;
        if ( TestInternalObjects(transB, &delta_c, &axis, hullA, v8, v5, v70) )
        {
          ++gActualNbTests;
          btConvexPolyhedron::project(hullA, transA, v47, &v80, &v81);
          btConvexPolyhedron::project(hullB, transB, &axis, (float *)&v82, &max);
          if ( *(float *)&v82 > v81 || v80 > max )
            return 0;
          v48 = max - v80;
          if ( (float)(max - v80) > (float)(v81 - *(float *)&v82) )
            v48 = v81 - *(float *)&v82;
          if ( v70 > v48 )
          {
            v70 = v48;
            *sep = (btVector3)axis.mVec128;
          }
        }
        v8 = transA;
      }
      v37 = v72 + 36;
      v36 = ++v76 < SLODWORD(min);
      v5 = hullB;
      v72 += 36;
    }
    while ( v36 );
  }
  v36 = hullA->m_uniqueEdges.m_size <= 0;
  min = 0.0;
  v80 = 0.0;
  if ( !v36 )
  {
    v77 = 0;
    do
    {
      v49 = v8->m_basis.m_el[0].mVec128.m128_f32[0];
      v50 = &hullA->m_uniqueEdges.m_data[v77];
      v51 = v8->m_basis.m_el[1].mVec128.m128_f32[0];
      v89 = v50->mVec128.m128_u64[0];
      v90 = v50->mVec128.m128_u64[1];
      v52 = (float)((float)(v49 * *(float *)&v89)
                  + (float)(*((float *)&v89 + 1) * v8->m_basis.m_el[0].mVec128.m128_f32[1]))
          + (float)(*(float *)&v90 * v8->m_basis.m_el[0].mVec128.m128_f32[2]);
      v53 = (float)((float)(v51 * *(float *)&v89)
                  + (float)(v8->m_basis.m_el[1].mVec128.m128_f32[1] * *((float *)&v89 + 1)))
          + (float)(v8->m_basis.m_el[1].mVec128.m128_f32[2] * *(float *)&v90);
      v36 = v5->m_uniqueEdges.m_size <= 0;
      v54 = (float)((float)(v8->m_basis.m_el[2].mVec128.m128_f32[1] * *((float *)&v89 + 1))
                  + (float)(v8->m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v90))
          + (float)(v8->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v89);
      axis.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v53), LODWORD(v52));
      axis.mVec128.m128_f32[2] = v54;
      max = 0.0;
      if ( !v36 )
      {
        dir.mVec128.m128_i32[3] = 0;
        v73 = 0;
        do
        {
          p_mVec128 = &v5->m_uniqueEdges.m_data[v73].mVec128;
          v56 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
          v91 = p_mVec128->m128_u64[0];
          v92 = p_mVec128->m128_u64[1];
          ++LODWORD(min);
          v57 = (float)((float)(*(float *)&v91 * transB->m_basis.m_el[0].mVec128.m128_f32[0])
                      + (float)(*((float *)&v91 + 1) * transB->m_basis.m_el[0].mVec128.m128_f32[1]))
              + (float)(*(float *)&v92 * transB->m_basis.m_el[0].mVec128.m128_f32[2]);
          v58 = (float)((float)(*((float *)&v91 + 1) * transB->m_basis.m_el[2].mVec128.m128_f32[1])
                      + (float)(*(float *)&v92 * transB->m_basis.m_el[2].mVec128.m128_f32[2]))
              + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v91);
          v59 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * *((float *)&v91 + 1))
                      + (float)(v56 * *(float *)&v92))
              + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)&v91);
          v60 = (float)(axis.mVec128.m128_f32[2] * v57) - (float)(v58 * v52);
          v61 = (float)(v58 * v53) - (float)(v59 * axis.mVec128.m128_f32[2]);
          v62 = (float)(v59 * v52) - (float)(v53 * v57);
          dir.mVec128.m128_f32[0] = v61;
          dir.mVec128.m128_f32[1] = v60;
          dir.mVec128.m128_f32[2] = v62;
          if ( COERCE_FLOAT(LODWORD(v61) & _mask__AbsFloat_) > 0.000001
            || COERCE_FLOAT(LODWORD(v60) & _mask__AbsFloat_) > 0.000001
            || COERCE_FLOAT(LODWORD(v62) & _mask__AbsFloat_) > 0.000001 )
          {
            *(float *)&v82 = 1.0 / sqrtf((float)((float)(v61 * v61) + (float)(v62 * v62)) + (float)(v60 * v60));
            dir.mVec128.m128_f32[0] = *(float *)&v82 * dir.mVec128.m128_f32[0];
            dir.mVec128.m128_f32[1] = dir.mVec128.m128_f32[1] * *(float *)&v82;
            dir.mVec128.m128_f32[2] = dir.mVec128.m128_f32[2] * *(float *)&v82;
            if ( (float)((float)((float)(dir.mVec128.m128_f32[0] * delta_c.mVec128.m128_f32[0])
                               + (float)(dir.mVec128.m128_f32[2] * delta_c.mVec128.m128_f32[2]))
                       + (float)(dir.mVec128.m128_f32[1] * delta_c.mVec128.m128_f32[1])) >= 0.0 )
            {
              ++gExpectedNbTests;
              if ( TestInternalObjects(transB, &delta_c, &dir, hullA, v8, hullB, v70) )
              {
                ++gActualNbTests;
                btConvexPolyhedron::project(hullA, transA, v63, &v84, &v83);
                btConvexPolyhedron::project(hullB, transB, &dir, &v81, &v85);
                if ( v81 > v83 || v84 > v85 )
                  return 0;
                v64 = v85 - v84;
                if ( (float)(v85 - v84) > (float)(v83 - v81) )
                  v64 = v83 - v81;
                if ( v70 > v64 )
                {
                  v70 = v64;
                  *sep = (btVector3)dir.mVec128;
                }
              }
              v8 = transA;
            }
            v53 = axis.mVec128.m128_f32[1];
            v52 = axis.mVec128.m128_f32[0];
          }
          v5 = hullB;
          ++v73;
          v36 = ++LODWORD(max) < hullB->m_uniqueEdges.m_size;
        }
        while ( v36 );
      }
      ++v77;
      v36 = ++LODWORD(v80) < hullA->m_uniqueEdges.m_size;
    }
    while ( v36 );
  }
  v65 = sep->mVec128.m128_f32[2];
  v66 = sep->mVec128.m128_f32[1];
  if ( (float)((float)((float)((float)(transB->m_origin.mVec128.m128_f32[1] - v8->m_origin.mVec128.m128_f32[1]) * v66)
                     + (float)((float)(transB->m_origin.mVec128.m128_f32[2] - v8->m_origin.mVec128.m128_f32[2]) * v65))
             + (float)((float)(transB->m_origin.mVec128.m128_f32[0] - v8->m_origin.mVec128.m128_f32[0])
                     * sep->mVec128.m128_f32[0])) > 0.0 )
  {
    *(float *)&v67 = -sep->mVec128.m128_f32[0];
    *(float *)&v68 = -v66;
    axis.mVec128.m128_u64[0] = __PAIR64__(v68, v67);
    sep->mVec128.m128_u64[0] = __PAIR64__(v68, v67);
    axis.mVec128.m128_f32[2] = -v65;
    axis.mVec128.m128_i32[3] = 0;
    sep->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-v65);
  }
  return 1;
}
