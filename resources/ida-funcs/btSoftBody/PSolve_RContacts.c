void __cdecl btSoftBody::PSolve_RContacts(btSoftBody *psb, float kst)
{
  btSoftBody *v2; // esi
  const btVector3 *v3; // ebx
  btRigidBody *v4; // eax
  btVector3 *VelocityInLocalPoint; // eax
  float *v6; // esi
  float *v7; // eax
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float *v13; // esi
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float *v18; // ecx
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  unsigned int v29; // xmm0_4
  unsigned int v30; // xmm1_4
  unsigned int v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  btRigidBody *v35; // edx
  float sdt; // [esp+14h] [ebp-98h]
  int v37; // [esp+18h] [ebp-94h]
  float v38; // [esp+1Ch] [ebp-90h] BYREF
  int m_size; // [esp+20h] [ebp-8Ch]
  float v40; // [esp+24h] [ebp-88h] BYREF
  btRigidBody *v41; // [esp+28h] [ebp-84h]
  float v42[4]; // [esp+2Ch] [ebp-80h] BYREF
  _DWORD v43[4]; // [esp+3Ch] [ebp-70h] BYREF
  btVector3 v44; // [esp+4Ch] [ebp-60h] BYREF
  float v45; // [esp+60h] [ebp-4Ch]
  float v46; // [esp+64h] [ebp-48h]
  float v47; // [esp+6Ch] [ebp-40h]
  float v48; // [esp+70h] [ebp-3Ch]
  float v49; // [esp+74h] [ebp-38h]
  int v50; // [esp+78h] [ebp-34h]
  float v51; // [esp+7Ch] [ebp-30h]
  float v52; // [esp+8Ch] [ebp-20h]
  btVector3 v53; // [esp+9Ch] [ebp-10h] BYREF

  v2 = psb;
  sdt = psb->m_sst.sdt;
  v38 = psb->m_collisionShape->getMargin(psb->m_collisionShape);
  if ( psb->m_rcontacts.m_size > 0 )
  {
    v37 = 0;
    m_size = psb->m_rcontacts.m_size;
    while ( 1 )
    {
      v3 = (const btVector3 *)&v2->m_rcontacts.m_data[v37];
      v4 = (*(_BYTE *)(v3->mVec128.m128_i32[0] + 244) & 2) != 0 ? (btRigidBody *)v3->mVec128.m128_i32[0] : 0;
      v41 = v4;
      if ( v4 )
      {
        VelocityInLocalPoint = btRigidBody::getVelocityInLocalPoint(v3 + 7, &v53, v4);
        v42[0] = VelocityInLocalPoint->mVec128.m128_f32[0] * sdt;
        v42[1] = VelocityInLocalPoint->mVec128.m128_f32[1] * sdt;
        v42[2] = VelocityInLocalPoint->mVec128.m128_f32[2] * sdt;
        v42[3] = 0.0;
        v6 = v42;
      }
      else
      {
        memset(v43, 0, sizeof(v43));
        v6 = (float *)v43;
      }
      v7 = (float *)v3[3].mVec128.m128_i32[0];
      v8 = v7[5] - v7[9];
      v9 = v7[6] - v7[10];
      v10 = v3[1].mVec128.m128_f32[2];
      v11 = v3[1].mVec128.m128_f32[1];
      v12 = v7[4] - v7[8];
      v47 = *v6;
      v13 = v6 + 1;
      v48 = *v13++;
      v49 = *v13;
      v50 = *((_DWORD *)v13 + 1);
      v14 = v8 - v48;
      v15 = v9 - v49;
      v16 = v12 - v47;
      v17 = (float)((float)(v10 * v15) + (float)(v11 * v14)) + (float)(v3[1].mVec128.m128_f32[0] * v16);
      if ( v17 <= 0.00000011920929 )
      {
        v40 = (float)((float)((float)(v7[6] * v3[1].mVec128.m128_f32[2]) + (float)(v7[5] * v3[1].mVec128.m128_f32[1]))
                    + (float)(v3[1].mVec128.m128_f32[0] * v7[4]))
            + v3[2].mVec128.m128_f32[0];
        v18 = &v40;
        if ( v38 <= v40 )
          v18 = &v38;
        v19 = v3[1].mVec128.m128_f32[2] * v17;
        v20 = v16 - (float)(v3[1].mVec128.m128_f32[0] * v17);
        v45 = v14 - (float)(v3[1].mVec128.m128_f32[1] * v17);
        v21 = v15 - v19;
        v22 = v3[1].mVec128.m128_f32[2];
        v46 = v21;
        v23 = v3[8].mVec128.m128_f32[2] * *v18;
        v52 = v23 * v3[1].mVec128.m128_f32[0];
        v24 = v3[8].mVec128.m128_f32[1] * v20;
        v25 = v3[8].mVec128.m128_f32[1];
        v26 = (float)((float)(v15 - (float)(v25 * v46)) + (float)(v22 * v23)) * kst;
        v27 = (float)((float)(v14 - (float)(v25 * v45)) + (float)(v3[1].mVec128.m128_f32[1] * v23)) * kst;
        v28 = (float)((float)(v16 - v24) + v52) * kst;
        *(float *)&v29 = (float)((float)(v3[4].mVec128.m128_f32[2] * v26) + (float)(v3[4].mVec128.m128_f32[1] * v27))
                       + (float)(v3[4].mVec128.m128_f32[0] * v28);
        *(float *)&v30 = (float)((float)(v3[5].mVec128.m128_f32[2] * v26) + (float)(v3[5].mVec128.m128_f32[1] * v27))
                       + (float)(v28 * v3[5].mVec128.m128_f32[0]);
        *(float *)&v31 = (float)((float)(v3[6].mVec128.m128_f32[2] * v26) + (float)(v3[6].mVec128.m128_f32[1] * v27))
                       + (float)(v28 * v3[6].mVec128.m128_f32[0]);
        v32 = v3[8].mVec128.m128_f32[0];
        v44.mVec128.m128_u64[0] = __PAIR64__(v30, v29);
        v7[4] = v7[4] - (float)(v32 * *(float *)&v29);
        v33 = v7[5] - (float)(v32 * *(float *)&v30);
        v34 = v7[6];
        v51 = v24;
        v44.mVec128.m128_u64[1] = v31;
        v7[5] = v33;
        v35 = v41;
        v7[6] = v34 - (float)(v32 * *(float *)&v31);
        if ( v35 )
          btRigidBody::applyImpulse(v35, &v44, v3 + 7);
      }
      ++v37;
      if ( !--m_size )
        break;
      v2 = psb;
    }
  }
}
