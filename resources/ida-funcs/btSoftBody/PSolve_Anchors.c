void __cdecl btSoftBody::PSolve_Anchors(btSoftBody *psb, float kst)
{
  int m_size; // eax
  const btVector3 *v3; // edi
  int v4; // eax
  float v5; // xmm3_4
  float v6; // xmm2_4
  float *v7; // esi
  float v8; // xmm4_4
  btVector3 *VelocityInLocalPoint; // eax
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  btRigidBody *v26; // edx
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float sdt; // [esp+4h] [ebp-64h]
  float v36; // [esp+8h] [ebp-60h]
  int v37; // [esp+Ch] [ebp-5Ch]
  int v38; // [esp+10h] [ebp-58h]
  float v39; // [esp+18h] [ebp-50h]
  float v40; // [esp+1Ch] [ebp-4Ch]
  float v41; // [esp+20h] [ebp-48h]
  btVector3 v42; // [esp+28h] [ebp-40h] BYREF
  float v43; // [esp+3Ch] [ebp-2Ch]
  float v44; // [esp+40h] [ebp-28h]
  float v45; // [esp+48h] [ebp-20h]
  float v46; // [esp+4Ch] [ebp-1Ch]
  btVector3 v47; // [esp+58h] [ebp-10h] BYREF

  m_size = psb->m_anchors.m_size;
  v36 = psb->m_cfg.kAHR * kst;
  sdt = psb->m_sst.sdt;
  if ( m_size > 0 )
  {
    v37 = 0;
    v42.mVec128.m128_i32[3] = 0;
    v38 = m_size;
    do
    {
      v3 = (const btVector3 *)&psb->m_anchors.m_data[v37];
      v4 = v3[2].mVec128.m128_i32[0];
      v5 = v3[1].mVec128.m128_f32[1];
      v6 = v3[1].mVec128.m128_f32[2];
      v7 = (float *)v3->mVec128.m128_i32[0];
      v39 = (float)((float)((float)(*(float *)(v4 + 20) * v5) + (float)(*(float *)(v4 + 24) * v6))
                  + (float)(v3[1].mVec128.m128_f32[0] * *(float *)(v4 + 16)))
          + *(float *)(v4 + 64);
      v8 = v3[1].mVec128.m128_f32[0];
      v40 = (float)((float)((float)(*(float *)(v4 + 36) * v5) + (float)(*(float *)(v4 + 40) * v6))
                  + (float)(v8 * *(float *)(v4 + 32)))
          + *(float *)(v4 + 68);
      v41 = (float)((float)((float)(*(float *)(v4 + 52) * v5) + (float)(*(float *)(v4 + 56) * v6))
                  + (float)(v8 * *(float *)(v4 + 48)))
          + *(float *)(v4 + 72);
      VelocityInLocalPoint = btRigidBody::getVelocityInLocalPoint(v3 + 6, &v47, (btRigidBody *)v4);
      v10 = v40 - v7[5];
      v11 = sdt * VelocityInLocalPoint->mVec128.m128_f32[0];
      v12 = VelocityInLocalPoint->mVec128.m128_f32[2] * sdt;
      v13 = v7[6] - v7[10];
      v14 = VelocityInLocalPoint->mVec128.m128_f32[1] * sdt;
      v15 = v7[4] - v7[8];
      v16 = v7[5] - v7[9];
      v45 = (float)(v39 - v7[4]) * v36;
      v43 = v10;
      v17 = v10 * v36;
      v18 = v41 - v7[6];
      v46 = v17;
      v19 = (float)(v14 - v16) + v17;
      v20 = (float)(v12 - v13) + (float)(v18 * v36);
      v21 = (float)(v11 - v15) + v45;
      v22 = v3[3].mVec128.m128_f32[2] * v20;
      v23 = v3[3].mVec128.m128_f32[1] * v19;
      v44 = v18;
      v24 = (float)(v22 + v23) + (float)(v3[3].mVec128.m128_f32[0] * v21);
      v25 = (float)((float)(v3[4].mVec128.m128_f32[2] * v20) + (float)(v3[4].mVec128.m128_f32[1] * v19))
          + (float)(v3[4].mVec128.m128_f32[0] * v21);
      v26 = (btRigidBody *)v3[2].mVec128.m128_i32[0];
      v27 = (float)((float)(v3[5].mVec128.m128_f32[2] * v20) + (float)(v3[5].mVec128.m128_f32[1] * v19))
          + (float)(v3[5].mVec128.m128_f32[0] * v21);
      v28 = v3[2].mVec128.m128_f32[1] * v24;
      v29 = v3[2].mVec128.m128_f32[1];
      v30 = v29 * v27;
      v31 = v29 * v25;
      v32 = v3[7].mVec128.m128_f32[0];
      v33 = v7[4] + (float)(v32 * v28);
      v7[5] = v7[5] + (float)(v32 * v31);
      v34 = v7[6] + (float)(v32 * v30);
      v7[4] = v33;
      v7[6] = v34;
      v42.mVec128.m128_i32[0] = LODWORD(v28) ^ _mask__NegFloat_;
      v42.mVec128.m128_i32[1] = LODWORD(v31) ^ _mask__NegFloat_;
      v42.mVec128.m128_i32[2] = LODWORD(v30) ^ _mask__NegFloat_;
      btRigidBody::applyImpulse(v26, &v42, v3 + 6);
      ++v37;
      --v38;
    }
    while ( v38 );
  }
}
