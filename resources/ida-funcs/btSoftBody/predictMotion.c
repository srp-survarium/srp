void __thiscall btSoftBody::predictMotion(btSoftBody *this, _DWORD *dt, float a3)
{
  btDbvt *v3; // ecx
  btSoftBody *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  int v7; // ecx
  btSoftBody *v8; // ecx
  double v9; // st7
  float *v10; // eax
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // edx
  float *v16; // eax
  btSoftBody *v17; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  btSoftBody *v36; // ecx
  btSoftBody *v37; // ecx
  int v38; // eax
  const void *v39; // eax
  double v40; // st7
  float v41; // xmm0_4
  const btSoftBody::Face *v42; // ecx
  float *v43; // eax
  float *v44; // edx
  float v45; // xmm1_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  btDbvtAabbMm *v48; // eax
  float v49; // xmm0_4
  int v50; // ecx
  int v51; // eax
  int v52; // edx
  float *v53; // eax
  float v54; // xmm4_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm5_4
  float v59; // xmm4_4
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm3_4
  float v63; // xmm5_4
  float v64; // xmm3_4
  float v65; // xmm4_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm0_4
  int v69; // esi
  int v70; // esi
  btSoftBody::RContact *v71; // eax
  int v72; // esi
  int v73; // eax
  btDbvtAabbMm *v74; // edi
  btDbvt *v75; // ecx
  btDbvt *v76; // ecx
  btDbvt *v77; // [esp-4h] [ebp-128h]
  btDbvt *m_leaf; // [esp-4h] [ebp-128h]
  float v79; // [esp+0h] [ebp-124h]
  float v80; // [esp+0h] [ebp-124h]
  int v81; // [esp+0h] [ebp-124h]
  int v82; // [esp+0h] [ebp-124h]
  int v83; // [esp+18h] [ebp-10Ch]
  int v84; // [esp+18h] [ebp-10Ch]
  int v85; // [esp+18h] [ebp-10Ch]
  int v86; // [esp+18h] [ebp-10Ch]
  int v87; // [esp+1Ch] [ebp-108h]
  int v88; // [esp+1Ch] [ebp-108h]
  int v89; // [esp+1Ch] [ebp-108h]
  int v90; // [esp+20h] [ebp-104h]
  const btSoftBody::Face *v91; // [esp+20h] [ebp-104h]
  btVector3 v92; // [esp+24h] [ebp-100h] BYREF
  btDbvtAabbMm v93[2]; // [esp+34h] [ebp-F0h] BYREF
  btDbvtAabbMm v94; // [esp+74h] [ebp-B0h] BYREF
  btSoftBody::RContact __that; // [esp+94h] [ebp-90h] BYREF

  if ( *((_BYTE *)dt + 944) )
  {
    *((_BYTE *)dt + 944) = 0;
    btSoftBody::updateConstants(this, dt);
    btDbvt::clear(v3, (btDbvt *)(dt + 247));
    if ( (dt[99] & 0x10) != 0 )
      btSoftBody::initializeFaceTree(v4, (int)dt);
  }
  v5 = *((float *)dt + 94) * a3;
  v6 = s_bm_current_air_resistance;
  v7 = dt[51];
  *((float *)dt + 115) = v5;
  *((float *)dt + 116) = v6 / v5;
  *((float *)dt + 117) = v5 * 3.0;
  v9 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v7 + 40))(v7);
  *((float *)dt + 118) = v9;
  v10 = (float *)(dt[173] + 48);
  *((float *)dt + 119) = v9 * 0.25;
  v11 = *((float *)dt + 115);
  v12 = v11 * *v10;
  v13 = v10[1] * v11;
  v14 = v10[2] * v11;
  if ( (int)dt[180] > 0 )
  {
    v8 = 0;
    v15 = dt[180];
    do
    {
      v16 = (float *)((char *)v8 + dt[182]);
      if ( v16[24] > 0.0 )
      {
        v16[12] = v16[12] + v12;
        v16[13] = v16[13] + v13;
        v16[14] = v16[14] + v14;
      }
      v8 = (btSoftBody *)((char *)v8 + 112);
      --v15;
    }
    while ( v15 );
  }
  btSoftBody::applyForces(v8, (int)dt);
  v18 = dt[180];
  if ( v18 > 0 )
  {
    memset(&v92, 0, sizeof(v92));
    v19 = 0;
    v83 = v18;
    do
    {
      v20 = v19 + dt[182];
      v17 = (btSoftBody *)(v20 + 16);
      *(_DWORD *)(v20 + 32) = *(_DWORD *)(v20 + 16);
      *(_DWORD *)(v20 + 36) = *(_DWORD *)(v20 + 20);
      *(_DWORD *)(v20 + 40) = *(_DWORD *)(v20 + 24);
      *(_DWORD *)(v20 + 44) = *(_DWORD *)(v20 + 28);
      v21 = *(float *)(v20 + 96);
      v22 = *(float *)(v20 + 68) * v21;
      v23 = *(float *)(v20 + 72) * v21;
      v24 = *((float *)dt + 115);
      v25 = v24 * (float)(*(float *)(v20 + 96) * *(float *)(v20 + 64));
      v26 = v24 * v22;
      v27 = *(float *)(v20 + 48);
      v28 = v26 + *(float *)(v20 + 52);
      *(float *)(v20 + 52) = v28;
      v29 = (float)(v24 * v23) + *(float *)(v20 + 56);
      *(float *)(v20 + 56) = v29;
      *(float *)(v20 + 48) = v27 + v25;
      v30 = *((float *)dt + 115);
      v31 = v30 * *(float *)(v20 + 48);
      v32 = (float)(v28 * v30) + *(float *)(v20 + 20);
      v33 = v29 * v30;
      v34 = *(float *)(v20 + 16);
      v35 = v33 + *(float *)(v20 + 24);
      *(float *)(v20 + 20) = v32;
      *(float *)(v20 + 24) = v35;
      *(float *)(v20 + 16) = v34 + v31;
      *(btVector3 *)(v20 + 64) = (btVector3)v92.mVec128;
      v19 += 112;
      --v83;
    }
    while ( v83 );
  }
  btSoftBody::updateClusters(v17, (int)dt);
  btSoftBody::updateBounds(v36, (int)dt);
  v38 = dt[180];
  if ( v38 > 0 )
  {
    v87 = 0;
    v92.mVec128.m128_i32[3] = 0;
    v84 = v38;
    do
    {
      v90 = v87 + dt[182];
      v39 = (const void *)btDbvtAabbMm::FromCR((int)v93, (float *)(v90 + 16), *((float *)dt + 118));
      v40 = *((float *)dt + 119);
      v41 = *((float *)dt + 117);
      qmemcpy(&v94, v39, sizeof(v94));
      v92.mVec128.m128_f32[0] = v41 * *(float *)(v90 + 48);
      v79 = v40;
      v77 = *(btDbvt **)(v90 + 104);
      v92.mVec128.m128_f32[1] = *(float *)(v90 + 52) * v41;
      v92.mVec128.m128_f32[2] = *(float *)(v90 + 56) * v41;
      btDbvt::update(&v94, &v92, (btDbvt *)(dt + 237), v77, v79);
      v87 += 112;
      --v84;
    }
    while ( v84 );
  }
  if ( dt[247] )
  {
    v85 = 0;
    if ( (int)dt[190] > 0 )
    {
      v92.mVec128.m128_i32[3] = 0;
      v88 = 0;
      do
      {
        v42 = (const btSoftBody::Face *)(v88 + dt[192]);
        v43 = (float *)v42->m_n[1];
        v44 = (float *)v42->m_n[0];
        v45 = (float)(v42->m_n[2]->m_v.mVec128.m128_f32[1] + (float)(v43[13] + v44[13])) * 0.33333334;
        v91 = v42;
        v46 = (float)(v42->m_n[2]->m_v.mVec128.m128_f32[0] + (float)(v43[12] + v44[12])) * 0.33333334;
        v47 = (float)(v42->m_n[2]->m_v.mVec128.m128_f32[2] + (float)(v43[14] + v44[14])) * 0.33333334;
        v48 = VolumeOf(v42, v93, *((float *)dt + 118));
        v49 = *((float *)dt + 117);
        v80 = *((float *)dt + 119);
        m_leaf = (btDbvt *)v91->m_leaf;
        qmemcpy(&v94, v48, sizeof(v94));
        v92.mVec128.m128_f32[0] = v46 * v49;
        v92.mVec128.m128_f32[1] = v45 * v49;
        v92.mVec128.m128_f32[2] = v47 * v49;
        btDbvt::update(&v94, &v92, (btDbvt *)(dt + 247), m_leaf, v80);
        ++v85;
        v88 += 64;
      }
      while ( v85 < dt[190] );
    }
  }
  btSoftBody::updatePose(v37, (int)dt);
  if ( *((_BYTE *)dt + 481) )
  {
    if ( *((float *)dt + 82) > 0.0 )
    {
      v93[0] = *(btDbvtAabbMm *)((_BYTE *)dt + 17);
      v51 = dt[180];
      v93[1].mi.mVec128.m128_u64[0] = *((_QWORD *)dt + 72);
      v93[1].mi.mVec128.m128_u64[1] = *((_QWORD *)dt + 73);
      if ( v51 > 0 )
      {
        v52 = 0;
        v86 = 0;
        v89 = v51;
        do
        {
          v50 = v86 + dt[182];
          if ( *(float *)(v50 + 96) > 0.0 )
          {
            v53 = (float *)(v52 + dt[125]);
            v54 = v53[1];
            v55 = v53[2];
            v56 = (float)((float)(v93[0].mi.mVec128.m128_f32[0] * *v53) + (float)(v93[0].mi.mVec128.m128_f32[1] * v54))
                + (float)(v93[0].mi.mVec128.m128_f32[2] * v55);
            v57 = (float)((float)(v93[0].mx.mVec128.m128_f32[0] * *v53) + (float)(v93[0].mx.mVec128.m128_f32[1] * v54))
                + (float)(v93[0].mx.mVec128.m128_f32[2] * v55);
            v58 = v93[1].mi.mVec128.m128_f32[1] * v54;
            v59 = v93[1].mi.mVec128.m128_f32[2] * v55;
            v60 = *((float *)dt + 133) + v57;
            v61 = *(float *)(v50 + 24);
            v62 = (float)(v93[1].mi.mVec128.m128_f32[0] * *v53) + v58;
            v63 = *(float *)(v50 + 20);
            v64 = v62 + v59;
            v65 = *(float *)(v50 + 16);
            v66 = *((float *)dt + 134) + v64;
            v67 = *((float *)dt + 82);
            v68 = (float)(v56 + *((float *)dt + 132)) - v65;
            v92.mVec128.m128_i32[3] = 0;
            v92.mVec128.m128_f32[0] = (float)(v68 * v67) + v65;
            v92.mVec128.m128_f32[1] = (float)((float)(v60 - v63) * v67) + v63;
            v92.mVec128.m128_f32[2] = (float)((float)(v66 - v61) * v67) + v61;
            *(btVector3 *)(v50 + 16) = (btVector3)v92.mVec128;
          }
          v86 += 112;
          v52 += 16;
          --v89;
        }
        while ( v89 );
      }
    }
  }
  v69 = dt[205];
  if ( v69 <= 0 )
  {
    if ( v69 < 0 && (int)dt[206] < 0 )
    {
      if ( dt[207] )
      {
        if ( *((_BYTE *)dt + 832) )
        {
          btAlignedFreeInternal((void *)dt[207]);
          v50 = v81;
        }
        dt[207] = 0;
      }
      *((_BYTE *)dt + 832) = 1;
      dt[207] = 0;
      dt[206] = 0;
    }
    if ( v69 < 0 )
    {
      v70 = 144 * v69;
      do
      {
        v71 = (btSoftBody::RContact *)(v70 + dt[207]);
        if ( v71 )
          btSoftBody::RContact::RContact(v71, &__that);
        v70 += 144;
      }
      while ( v70 < 0 );
    }
  }
  dt[205] = 0;
  v72 = dt[210];
  if ( v72 <= 0 )
  {
    if ( v72 < 0 && (int)dt[211] < 0 )
    {
      if ( dt[212] )
      {
        if ( *((_BYTE *)dt + 852) )
        {
          btAlignedFreeInternal((void *)dt[212]);
          v50 = v82;
        }
        dt[212] = 0;
      }
      *((_BYTE *)dt + 852) = 1;
      dt[212] = 0;
      dt[211] = 0;
    }
    if ( v72 < 0 )
    {
      v73 = v72 << 6;
      do
      {
        v74 = (btDbvtAabbMm *)(v73 + dt[212]);
        if ( v74 )
        {
          qmemcpy(v74, v93, 0x40u);
          v50 = 0;
        }
        v73 += 64;
      }
      while ( v73 < 0 );
    }
  }
  dt[210] = 0;
  btDbvt::optimizeIncremental((btDbvt *)v50, (btDbvt *)(dt + 237), 1);
  btDbvt::optimizeIncremental(v75, (btDbvt *)(dt + 247), 1);
  btDbvt::optimizeIncremental(v76, (btDbvt *)(dt + 257), 1);
}
