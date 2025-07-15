double __userpurge btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact@<st0>(
        btConvexConcaveCollisionAlgorithm *this@<ecx>,
        const float *a2@<edi>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  float *v6; // ebx
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  unsigned int v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  int v47; // eax
  float v48; // xmm3_4
  float v49; // xmm6_4
  float v50; // xmm5_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm7_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  int v56; // xmm0_4
  int v57; // ecx
  float v58; // xmm0_4
  double result; // st7
  const float *v60; // [esp-4h] [ebp-210h]
  float v61; // [esp+10h] [ebp-1FCh] BYREF
  btMatrix3x3 v62; // [esp+14h] [ebp-1F8h] BYREF
  float v63; // [esp+44h] [ebp-1C8h] BYREF
  float v64; // [esp+48h] [ebp-1C4h] BYREF
  btTransform v65; // [esp+4Ch] [ebp-1C0h] BYREF
  float v66; // [esp+98h] [ebp-174h] BYREF
  unsigned __int64 v67; // [esp+9Ch] [ebp-170h] BYREF
  unsigned __int64 v68; // [esp+A4h] [ebp-168h]
  unsigned __int64 v69; // [esp+ACh] [ebp-160h]
  unsigned __int64 v70; // [esp+B4h] [ebp-158h]
  unsigned __int64 v71; // [esp+BCh] [ebp-150h] BYREF
  unsigned __int64 v72; // [esp+C4h] [ebp-148h]
  btVector3 v73; // [esp+CCh] [ebp-140h]
  btVector3 v74; // [esp+DCh] [ebp-130h]
  btTransform v75; // [esp+ECh] [ebp-120h] BYREF
  _BYTE v76[212]; // [esp+12Ch] [ebp-E0h] BYREF
  float v77; // [esp+200h] [ebp-Ch]

  LOBYTE(this) = this->m_isSwapped;
  v6 = (float *)body1;
  if ( !(_BYTE)this )
    v6 = (float *)body0;
  v62.m_el[0].mVec128.m128_i32[1] = (int)body0;
  if ( !(_BYTE)this )
    v62.m_el[0].mVec128.m128_i32[1] = (int)body1;
  v7 = v6[32] - v6[16];
  v8 = v6[34] - v6[18];
  v9 = v6[33] - v6[17];
  if ( (float)(v6[65] * v6[65]) > (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) )
    return 1.0;
  btTransform::inverse((btTransform *)this, v62.m_el[0].mVec128.m128_i32[1] + 16, &v65);
  v10 = v6[17];
  v11 = v6[16];
  v12 = v6[18];
  v13 = v6[5];
  *(float *)&v69 = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v11)
                                 + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v10))
                         + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v12))
                 + v65.m_origin.mVec128.m128_f32[0];
  *((float *)&v69 + 1) = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v11)
                                       + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v10))
                               + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v12))
                       + v65.m_origin.mVec128.m128_f32[1];
  v14 = v65.m_basis.m_el[2].mVec128.m128_f32[0] * v11;
  v15 = v65.m_basis.m_el[2].mVec128.m128_f32[1] * v10;
  v16 = v65.m_basis.m_el[2].mVec128.m128_f32[2] * v12;
  v17 = v6[10];
  *(float *)&v18 = (float)((float)(v14 + v15) + v16) + v65.m_origin.mVec128.m128_f32[2];
  v19 = v6[6];
  v70 = v18;
  v20 = v6[14];
  v21 = v6[9];
  v62.m_el[2].mVec128.m128_f32[2] = (float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v19)
                                          + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v17))
                                  + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v20);
  v22 = v6[13];
  v23 = (float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v13)
              + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v21))
      + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v22);
  v24 = v6[8];
  v62.m_el[2].mVec128.m128_f32[0] = v23;
  v62.m_el[2].mVec128.m128_f32[3] = (float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v6[4])
                                          + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v24))
                                  + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v6[12]);
  v62.m_el[2].mVec128.m128_f32[1] = (float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v19)
                                          + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v17))
                                  + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v20);
  v25 = v6[4];
  v64 = (float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v6[5])
              + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v21))
      + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v22);
  v26 = v65.m_basis.m_el[1].mVec128.m128_f32[0] * v25;
  v27 = v6[12];
  v66 = (float)(v26 + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v6[8]))
      + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v27);
  v28 = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v19)
              + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v17))
      + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v20);
  v29 = v6[4];
  v61 = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v6[5])
              + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v21))
      + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v22);
  v30 = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v29)
              + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v6[8]))
      + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v27);
  v63 = v28;
  v62.m_el[0].mVec128.m128_f32[0] = v30;
  btMatrix3x3::setValue(
    &v62,
    (int)&v71,
    &v61,
    &v63,
    &v66,
    &v64,
    &v62.m_el[2].mVec128.m128_f32[1],
    &v62.m_el[2].mVec128.m128_f32[3],
    v62.m_el[2].mVec128.m128_f32,
    &v62.m_el[2].mVec128.m128_f32[2],
    a2);
  v75.m_basis.m_el[0].mVec128.m128_u64[0] = v71;
  v75.m_basis.m_el[0].mVec128.m128_u64[1] = v72;
  v75.m_basis.m_el[1] = (btVector3)v73.mVec128;
  v31 = v6[33];
  v32 = v6[34];
  v62.m_el[0].mVec128.m128_f32[0] = v6[32];
  v62.m_el[0].mVec128.m128_f32[2] = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0]
                                                          * v62.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v31))
                                          + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v32))
                                  + v65.m_origin.mVec128.m128_f32[0];
  v61 = v32;
  v75.m_basis.m_el[2] = (btVector3)v74.mVec128;
  v62.m_el[0].mVec128.m128_f32[3] = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0]
                                                          * v62.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v31))
                                          + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v32))
                                  + v65.m_origin.mVec128.m128_f32[1];
  v33 = v6[22];
  v62.m_el[1].mVec128.m128_f32[0] = (float)((float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0]
                                                          * v62.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v31))
                                          + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v32))
                                  + v65.m_origin.mVec128.m128_f32[2];
  v62.m_el[1].mVec128.m128_i32[1] = 0;
  v34 = v65.m_basis.m_el[2].mVec128.m128_f32[2] * v6[30];
  v75.m_origin.mVec128.m128_u64[0] = v69;
  v35 = v6[25];
  v36 = (float)(v34 + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v33))
      + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v6[26]);
  v37 = v6[21];
  v62.m_el[0].mVec128.m128_f32[0] = v36;
  v75.m_origin.mVec128.m128_u64[1] = v70;
  v38 = (float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v37)
              + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v35))
      + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v6[29]);
  v39 = v6[28];
  v40 = v65.m_basis.m_el[2].mVec128.m128_f32[0] * v6[20];
  v61 = v38;
  v63 = (float)(v40 + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v6[24]))
      + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v39);
  v41 = v6[21];
  v66 = (float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v6[30])
              + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v6[22]))
      + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v6[26]);
  v42 = v65.m_basis.m_el[1].mVec128.m128_f32[0] * v41;
  v43 = v6[29];
  v64 = (float)(v42 + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v6[25]))
      + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v43);
  v44 = v6[28];
  v62.m_el[2].mVec128.m128_f32[1] = (float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v6[20])
                                          + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v6[24]))
                                  + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v44);
  v45 = v6[21];
  v62.m_el[2].mVec128.m128_f32[3] = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v6[30])
                                          + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v6[22]))
                                  + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v6[26]);
  v46 = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v6[20])
              + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v6[24]))
      + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v44);
  v62.m_el[2].mVec128.m128_f32[0] = (float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v45)
                                          + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v6[25]))
                                  + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v43);
  v62.m_el[2].mVec128.m128_f32[2] = v46;
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v62.m_el[2].m_floats[2],
    (int)&v71,
    v62.m_el[2].mVec128.m128_f32,
    &v62.m_el[2].mVec128.m128_f32[3],
    &v62.m_el[2].mVec128.m128_f32[1],
    &v64,
    &v66,
    &v63,
    &v61,
    (const float *)&v62,
    v60);
  v65.m_basis.m_el[0].mVec128.m128_u64[0] = v71;
  v65.m_basis.m_el[0].mVec128.m128_u64[1] = v72;
  v65.m_basis.m_el[1] = (btVector3)v73.mVec128;
  v47 = *(_DWORD *)(*(_DWORD *)(v62.m_el[0].mVec128.m128_i32[1] + 204) + 4);
  v65.m_basis.m_el[2] = (btVector3)v74.mVec128;
  v65.m_origin = *(btVector3 *)((char *)v62.m_el + 8);
  if ( (unsigned int)(v47 - 21) > 8 )
    return 1.0;
  v48 = v62.m_el[0].mVec128.m128_f32[2];
  v67 = v69;
  v68 = v70;
  if ( *(float *)&v69 <= v62.m_el[0].mVec128.m128_f32[2] )
    v49 = *(float *)&v67;
  else
    v49 = v62.m_el[0].mVec128.m128_f32[2];
  v50 = *((float *)&v67 + 1);
  v51 = v62.m_el[0].mVec128.m128_f32[3];
  if ( *((float *)&v67 + 1) > v62.m_el[0].mVec128.m128_f32[3] )
    v50 = v62.m_el[0].mVec128.m128_f32[3];
  v52 = *(float *)&v68;
  v53 = v62.m_el[1].mVec128.m128_f32[0];
  if ( *(float *)&v68 > v62.m_el[1].mVec128.m128_f32[0] )
    v52 = v62.m_el[1].mVec128.m128_f32[0];
  if ( *((float *)&v68 + 1) > 0.0 )
    HIDWORD(v68) = 0;
  v62.m_el[0].mVec128.m128_u64[1] = v69;
  v62.m_el[1].mVec128.m128_u64[0] = v70;
  if ( v48 <= *(float *)&v69 )
    v48 = v62.m_el[0].mVec128.m128_f32[2];
  v54 = v62.m_el[0].mVec128.m128_f32[3];
  if ( v51 > v62.m_el[0].mVec128.m128_f32[3] )
    v54 = v51;
  v55 = v62.m_el[1].mVec128.m128_f32[0];
  if ( v53 > v62.m_el[1].mVec128.m128_f32[0] )
    v55 = v53;
  if ( v62.m_el[1].mVec128.m128_f32[1] < 0.0 )
    v62.m_el[1].mVec128.m128_i32[1] = 0;
  v56 = *((int *)v6 + 64);
  *(float *)&v67 = v49 - *(float *)&v56;
  *((float *)&v67 + 1) = v50 - *(float *)&v56;
  *(float *)&v68 = v52 - *(float *)&v56;
  v62.m_el[0].mVec128.m128_f32[2] = v48 + *(float *)&v56;
  v62.m_el[0].mVec128.m128_f32[3] = v54 + *(float *)&v56;
  v62.m_el[1].mVec128.m128_f32[0] = v55 + *(float *)&v56;
  btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::LocalTriangleSphereCastCallback(
    (int)v76,
    &v65,
    v56,
    &v75);
  v57 = *(_DWORD *)(v62.m_el[0].mVec128.m128_i32[1] + 204);
  v58 = v6[63];
  v77 = v58;
  if ( v57 )
  {
    (*(void (__thiscall **)(int, _BYTE *, unsigned __int64 *, float *))(*(_DWORD *)v57 + 56))(
      v57,
      v76,
      &v67,
      &v62.m_el[0].mVec128.m128_f32[2]);
    v58 = v77;
  }
  if ( v6[63] <= v58 )
    return 1.0;
  result = v77;
  v6[63] = v58;
  return result;
}
