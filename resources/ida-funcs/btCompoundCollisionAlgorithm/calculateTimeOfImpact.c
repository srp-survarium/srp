double __userpurge btCompoundCollisionAlgorithm::calculateTimeOfImpact@<st0>(
        btCompoundCollisionAlgorithm *this@<ecx>,
        const float *a2@<edi>,
        btVector3 *body0,
        btVector3 *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool m_isSwapped; // al
  btVector3 *v7; // ebx
  int m_size; // ecx
  int v9; // eax
  int v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  int v15; // ecx
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm2_4
  float v26; // xmm2_4
  int v27; // esi
  int v28; // edi
  int v29; // ecx
  const float *v31; // [esp+0h] [ebp-130h]
  int v32; // [esp+10h] [ebp-120h]
  float v33; // [esp+10h] [ebp-120h]
  int v34; // [esp+14h] [ebp-11Ch]
  float v35; // [esp+18h] [ebp-118h]
  float v36; // [esp+1Ch] [ebp-114h]
  float v37; // [esp+20h] [ebp-110h]
  btVector3 *v38; // [esp+24h] [ebp-10Ch]
  float v39; // [esp+28h] [ebp-108h]
  float v40; // [esp+30h] [ebp-100h] BYREF
  float v41; // [esp+34h] [ebp-FCh]
  float v42; // [esp+38h] [ebp-F8h]
  int v43; // [esp+3Ch] [ebp-F4h]
  float v44; // [esp+40h] [ebp-F0h]
  float v45; // [esp+44h] [ebp-ECh]
  float v46; // [esp+48h] [ebp-E8h]
  int v47; // [esp+4Ch] [ebp-E4h]
  float v48; // [esp+50h] [ebp-E0h]
  float v49; // [esp+54h] [ebp-DCh]
  float v50; // [esp+58h] [ebp-D8h]
  int v51; // [esp+5Ch] [ebp-D4h]
  float v52; // [esp+60h] [ebp-D0h]
  float v53; // [esp+64h] [ebp-CCh]
  float v54; // [esp+68h] [ebp-C8h]
  int v55; // [esp+6Ch] [ebp-C4h]
  float v56; // [esp+70h] [ebp-C0h] BYREF
  float v57; // [esp+74h] [ebp-BCh] BYREF
  float v58; // [esp+78h] [ebp-B8h] BYREF
  btVector3 *v59; // [esp+7Ch] [ebp-B4h]
  btMatrix3x3 v60; // [esp+80h] [ebp-B0h] BYREF
  float v61; // [esp+B0h] [ebp-80h]
  float v62; // [esp+B4h] [ebp-7Ch]
  float v63; // [esp+B8h] [ebp-78h]
  int v64; // [esp+BCh] [ebp-74h]
  _DWORD v65[12]; // [esp+C0h] [ebp-70h] BYREF
  _DWORD v66[16]; // [esp+F0h] [ebp-40h] BYREF

  m_isSwapped = this->m_isSwapped;
  v7 = body1;
  if ( !m_isSwapped )
    v7 = body0;
  v31 = a2;
  v60.m_el[1].mVec128.m128_i32[0] = (int)this;
  v38 = body0;
  if ( !m_isSwapped )
    v38 = body1;
  m_size = this->m_childCollisionAlgorithms.m_size;
  v32 = 0;
  v60.m_el[0].mVec128.m128_i32[1] = v7[12].mVec128.m128_i32[3];
  v35 = s_bm_current_air_resistance;
  v60.m_el[1].mVec128.m128_i32[2] = m_size;
  if ( m_size > 0 )
  {
    v34 = 0;
    v60.m_el[2].mVec128.m128_i32[2] = (int)&v7[2];
    v60.m_el[2].mVec128.m128_i32[0] = (int)&v7[3];
    v59 = v7 + 4;
    v64 = 0;
    do
    {
      v40 = v7[1].mVec128.m128_f32[0];
      v41 = v7[1].mVec128.m128_f32[1];
      v42 = v7[1].mVec128.m128_f32[2];
      v43 = v7[1].mVec128.m128_i32[3];
      v44 = *(float *)v60.m_el[2].mVec128.m128_i32[2];
      v45 = *(float *)(v60.m_el[2].mVec128.m128_i32[2] + 4);
      v46 = *(float *)(v60.m_el[2].mVec128.m128_i32[2] + 8);
      v47 = *(_DWORD *)(v60.m_el[2].mVec128.m128_i32[2] + 12);
      v9 = *(_DWORD *)(v60.m_el[0].mVec128.m128_i32[1] + 24);
      v48 = *(float *)v60.m_el[2].mVec128.m128_i32[0];
      v49 = *(float *)(v60.m_el[2].mVec128.m128_i32[0] + 4);
      v50 = *(float *)(v60.m_el[2].mVec128.m128_i32[0] + 8);
      v51 = *(_DWORD *)(v60.m_el[2].mVec128.m128_i32[0] + 12);
      v52 = v59->mVec128.m128_f32[0];
      v53 = v59->mVec128.m128_f32[1];
      v54 = v59->mVec128.m128_f32[2];
      v55 = v59->mVec128.m128_i32[3];
      v10 = v34 + v9;
      v11 = *(float *)(v10 + 52);
      v12 = *(float *)(v10 + 48);
      v13 = *(float *)(v10 + 56);
      v14 = *(float *)(v10 + 20);
      v15 = *(_DWORD *)(v10 + 64);
      v61 = (float)((float)((float)(v12 * v40) + (float)(v11 * v41)) + (float)(v13 * v42)) + v52;
      v16 = (float)((float)((float)(v12 * v44) + (float)(v11 * v45)) + (float)(v13 * v46)) + v53;
      v17 = *(float *)(v10 + 24);
      v63 = (float)((float)((float)(v12 * v48) + (float)(v11 * v49)) + (float)(v13 * v50)) + v54;
      v18 = *(float *)(v10 + 8);
      v62 = v16;
      v19 = *(float *)(v10 + 40);
      v20 = *(float *)(v10 + 36);
      v60.m_el[1].mVec128.m128_f32[3] = (float)((float)(v18 * v48) + (float)(v17 * v49)) + (float)(v19 * v50);
      v21 = *(float *)(v10 + 4);
      v39 = v14;
      v60.m_el[0].mVec128.m128_i32[2] = v15;
      v37 = v20;
      v22 = (float)(v21 * v48) + (float)(v14 * v49);
      v23 = *(float *)(v10 + 16);
      v24 = v22 + (float)(v20 * v50);
      v25 = *(float *)(v10 + 32);
      v56 = v24;
      v36 = v25;
      v26 = *(float *)v10;
      v60.m_el[2].mVec128.m128_f32[1] = (float)((float)(*(float *)v10 * v48) + (float)(v23 * v49)) + (float)(v36 * v50);
      v60.m_el[0].mVec128.m128_f32[3] = (float)((float)(v18 * v44) + (float)(v17 * v45)) + (float)(v19 * v46);
      v57 = (float)((float)(v18 * v40) + (float)(v17 * v41)) + (float)(v19 * v42);
      v60.m_el[2].mVec128.m128_f32[3] = (float)((float)(v21 * v44) + (float)(v39 * v45)) + (float)(v37 * v46);
      v60.m_el[1].mVec128.m128_f32[1] = (float)((float)(v26 * v44) + (float)(v23 * v45)) + (float)(v36 * v46);
      v58 = (float)((float)(v21 * v40) + (float)(v39 * v41)) + (float)(v37 * v42);
      v60.m_el[0].mVec128.m128_f32[0] = (float)((float)(v26 * v40) + (float)(v23 * v41)) + (float)(v36 * v42);
      btMatrix3x3::setValue(
        &v60,
        (int)v65,
        &v58,
        &v57,
        &v60.m_el[1].mVec128.m128_f32[1],
        &v60.m_el[2].mVec128.m128_f32[3],
        &v60.m_el[0].mVec128.m128_f32[3],
        &v60.m_el[2].mVec128.m128_f32[1],
        &v56,
        &v60.m_el[1].mVec128.m128_f32[3],
        v31);
      v66[0] = v65[0];
      v66[1] = v65[1];
      v66[2] = v65[2];
      v66[3] = v65[3];
      v66[4] = v65[4];
      v66[5] = v65[5];
      v66[6] = v65[6];
      v66[7] = v65[7];
      v66[8] = v65[8];
      v66[9] = v65[9];
      v66[10] = v65[10];
      v66[11] = v65[11];
      *(float *)&v66[12] = v61;
      *(float *)&v66[13] = v62;
      *(float *)&v66[14] = v63;
      v66[15] = v64;
      btCollisionObject::setWorldTransform((btCollisionObject *)v66, v7);
      v27 = v7[12].mVec128.m128_i32[3];
      v28 = v32;
      v7[12].mVec128.m128_i32[3] = v60.m_el[0].mVec128.m128_i32[2];
      v29 = *(_DWORD *)(*(_DWORD *)(v60.m_el[1].mVec128.m128_i32[0] + 20) + 4 * v32);
      v33 = ((double (__thiscall *)(int, btVector3 *, btVector3 *, const btDispatcherInfo *, btManifoldResult *))*(_DWORD *)(*(_DWORD *)v29 + 8))(
              v29,
              v7,
              v38,
              dispatchInfo,
              resultOut);
      if ( v35 > (double)v33 )
        v35 = v33;
      v7[12].mVec128.m128_i32[3] = v27;
      btCollisionObject::setWorldTransform((btCollisionObject *)&v40, v7);
      v34 += 80;
      v32 = v28 + 1;
    }
    while ( v28 + 1 < v60.m_el[1].mVec128.m128_i32[2] );
  }
  return v35;
}
