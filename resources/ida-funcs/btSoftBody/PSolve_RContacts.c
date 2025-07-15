void __cdecl btSoftBody::PSolve_RContacts(btSoftBody *psb, float kst)
{
  btCollisionShape *m_collisionShape; // ecx
  float (__thiscall *getMargin)(btCollisionShape *); // edx
  int v4; // edi
  btSoftBody::RContact *m_data; // eax
  btCollisionObject *m_colObj; // ecx
  const btVector3 *v7; // eax
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  btRigidBody *v16; // edx
  float *v17; // ecx
  float v18; // xmm4_4
  __int64 v19; // xmm0_8
  float *v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float *v26; // esi
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm7_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  unsigned int v41; // xmm0_4
  unsigned int v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // [esp+F0h] [ebp-60h] BYREF
  int m_size; // [esp+F4h] [ebp-5Ch]
  float sdt; // [esp+F8h] [ebp-58h]
  float v53; // [esp+FCh] [ebp-54h] BYREF
  float v54; // [esp+100h] [ebp-50h]
  float v55; // [esp+104h] [ebp-4Ch]
  float v56; // [esp+108h] [ebp-48h]
  float v57[4]; // [esp+110h] [ebp-40h] BYREF
  _DWORD v58[4]; // [esp+120h] [ebp-30h] BYREF
  __int64 v59; // [esp+130h] [ebp-20h]
  __int64 v60; // [esp+138h] [ebp-18h]
  btVector3 v61; // [esp+140h] [ebp-10h] BYREF

  m_collisionShape = psb->m_collisionShape;
  getMargin = m_collisionShape->getMargin;
  sdt = psb->m_sst.sdt;
  v50 = getMargin(m_collisionShape);
  if ( psb->m_rcontacts.m_size > 0 )
  {
    v4 = 0;
    m_size = psb->m_rcontacts.m_size;
    do
    {
      m_data = psb->m_rcontacts.m_data;
      m_colObj = m_data[v4].m_cti.m_colObj;
      v7 = (const btVector3 *)&m_data[v4];
      if ( (m_colObj->m_internalType & 2) != 0 )
      {
        v8 = m_colObj[1].m_worldTransform.m_origin.mVec128.m128_f32[2];
        v9 = m_colObj[1].m_worldTransform.m_origin.mVec128.m128_f32[1];
        v10 = v7[7].mVec128.m128_f32[0] * v8;
        v11 = (float)(v7[7].mVec128.m128_f32[2] * v9) - (float)(v7[7].mVec128.m128_f32[1] * v8);
        v12 = m_colObj[1].m_worldTransform.m_origin.mVec128.m128_f32[0];
        v13 = m_colObj[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] + v11;
        v14 = m_colObj[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
            + (float)(v10 - (float)(v12 * v7[7].mVec128.m128_f32[2]));
        v15 = (float)(m_colObj[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                    + (float)((float)(v12 * v7[7].mVec128.m128_f32[1]) - (float)(v7[7].mVec128.m128_f32[0] * v9)))
            * sdt;
        v16 = (btRigidBody *)m_colObj;
        v57[0] = v13 * sdt;
        v57[1] = v14 * sdt;
        v57[2] = v15;
        v57[3] = 0.0;
        v17 = v57;
      }
      else
      {
        v16 = 0;
        memset(v58, 0, sizeof(v58));
        v17 = (float *)v58;
      }
      v18 = v7[1].mVec128.m128_f32[1];
      v59 = *(_QWORD *)v17;
      v19 = *((_QWORD *)v17 + 1);
      v20 = (float *)v7[3].mVec128.m128_i32[0];
      v21 = v20[6] - v20[10];
      v22 = (float)(v20[5] - v20[9]) - *((float *)&v59 + 1);
      v23 = (float)(v20[4] - v20[8]) - *(float *)&v59;
      v60 = v19;
      v24 = v21 - *(float *)&v19;
      v25 = (float)((float)(v7[1].mVec128.m128_f32[2] * v24) + (float)(v18 * v22))
          + (float)(v7[1].mVec128.m128_f32[0] * v23);
      if ( v25 <= 0.00000011920929 )
      {
        v53 = (float)((float)((float)(v20[6] * v7[1].mVec128.m128_f32[2]) + (float)(v20[5] * v7[1].mVec128.m128_f32[1]))
                    + (float)(v7[1].mVec128.m128_f32[0] * v20[4]))
            + v7[2].mVec128.m128_f32[0];
        v26 = &v53;
        if ( v50 <= v53 )
          v26 = &v50;
        v27 = v7[1].mVec128.m128_f32[0] * v25;
        v28 = v7[1].mVec128.m128_f32[2] * v25;
        v29 = v7[1].mVec128.m128_f32[1] * v25;
        v30 = v7[8].mVec128.m128_f32[2] * *v26;
        v31 = v23 - v27;
        v32 = v22 - v29;
        v33 = v24 - v28;
        v54 = v7[1].mVec128.m128_f32[0] * v30;
        v55 = v7[1].mVec128.m128_f32[1] * v30;
        v34 = v7[1].mVec128.m128_f32[2] * v30;
        v35 = v7[8].mVec128.m128_f32[1];
        v56 = v34;
        v36 = (float)(v23 - (float)(v35 * v31)) + v54;
        v37 = (float)((float)(v24 - (float)(v35 * v33)) + v34) * kst;
        v38 = v35 * v32;
        v39 = v36 * kst;
        v40 = (float)((float)(v22 - v38) + v55) * kst;
        *(float *)&v41 = (float)((float)(v7[4].mVec128.m128_f32[2] * v37) + (float)(v7[4].mVec128.m128_f32[1] * v40))
                       + (float)(v7[4].mVec128.m128_f32[0] * (float)(v36 * kst));
        *(float *)&v42 = (float)((float)(v7[5].mVec128.m128_f32[2] * v37) + (float)(v7[5].mVec128.m128_f32[1] * v40))
                       + (float)(v7[5].mVec128.m128_f32[0] * (float)(v36 * kst));
        v43 = (float)((float)(v7[6].mVec128.m128_f32[2] * v37) + (float)(v7[6].mVec128.m128_f32[1] * v40))
            + (float)(v7[6].mVec128.m128_f32[0] * v39);
        v61.mVec128.m128_i32[3] = 0;
        v44 = v7[8].mVec128.m128_f32[0];
        v45 = v44 * *(float *)&v41;
        v61.mVec128.m128_u64[0] = __PAIR64__(v42, v41);
        v46 = v44 * *(float *)&v42;
        v20[4] = v20[4] - v45;
        v47 = v20[5];
        v61.mVec128.m128_f32[2] = v43;
        v48 = v47 - v46;
        v49 = v20[6] - (float)(v44 * v43);
        v20[5] = v48;
        v20[6] = v49;
        if ( v16 )
          btRigidBody::applyImpulse(v16, &v61, v7 + 7);
      }
      ++v4;
      --m_size;
    }
    while ( m_size );
  }
}
