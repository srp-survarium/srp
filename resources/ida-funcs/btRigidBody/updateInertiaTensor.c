void __usercall btRigidBody::updateInertiaTensor(btRigidBody *this@<ecx>, int a2@<eax>)
{
  int v2; // edi
  float *v3; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  int v11; // eax
  const float *v12; // [esp+0h] [ebp-90h]
  const float *v13; // [esp+0h] [ebp-90h]
  float v14; // [esp+Ch] [ebp-84h] BYREF
  btMatrix3x3 v15; // [esp+10h] [ebp-80h] BYREF
  float v16; // [esp+40h] [ebp-50h]
  float v17; // [esp+44h] [ebp-4Ch]
  float v18; // [esp+48h] [ebp-48h]
  float v19; // [esp+50h] [ebp-40h]
  float v20; // [esp+54h] [ebp-3Ch]
  float v21; // [esp+58h] [ebp-38h]
  float v22; // [esp+60h] [ebp-30h] BYREF
  float v23; // [esp+64h] [ebp-2Ch]
  float v24; // [esp+68h] [ebp-28h]
  int v25; // [esp+6Ch] [ebp-24h]
  float v26; // [esp+70h] [ebp-20h]
  float v27; // [esp+74h] [ebp-1Ch]
  float v28; // [esp+78h] [ebp-18h]
  int v29; // [esp+7Ch] [ebp-14h]
  float v30; // [esp+80h] [ebp-10h]
  float v31; // [esp+84h] [ebp-Ch]
  float v32; // [esp+88h] [ebp-8h]
  int v33; // [esp+8Ch] [ebp-4h]

  v2 = a2;
  v3 = (float *)(a2 + 16);
  btMatrix3x3::btMatrix3x3(
    (btMatrix3x3 *)(a2 + 16),
    (btMatrix3x3 *)&v15.m_el[2],
    (float *)(a2 + 32),
    (float *)(a2 + 48),
    (float *)(a2 + 20),
    (float *)(a2 + 36),
    (float *)(a2 + 52),
    (float *)(a2 + 24),
    (float *)(a2 + 40),
    (const float *)(a2 + 56));
  v4 = *(float *)(v2 + 424);
  v5 = v3[9];
  v6 = v3[8];
  v15.m_el[0].mVec128.m128_f32[0] = v3[10] * v4;
  v7 = *(float *)(v2 + 420);
  v15.m_el[1].mVec128.m128_f32[3] = v5 * v7;
  v8 = *(float *)(v2 + 416);
  v15.m_el[0].mVec128.m128_f32[2] = v6 * v8;
  v15.m_el[1].mVec128.m128_f32[2] = v3[6] * v4;
  v15.m_el[1].mVec128.m128_f32[0] = v3[5] * v7;
  v14 = v3[4] * v8;
  v9 = v3[2] * v4;
  v15.m_el[0].mVec128.m128_f32[3] = v3[1] * v7;
  v10 = *v3 * v8;
  v15.m_el[0].mVec128.m128_f32[1] = v9;
  v15.m_el[1].mVec128.m128_f32[1] = v10;
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v15.m_el[1].m_floats[1],
    (int)&v22,
    &v15.m_el[0].mVec128.m128_f32[3],
    &v15.m_el[0].mVec128.m128_f32[1],
    &v14,
    v15.m_el[1].mVec128.m128_f32,
    &v15.m_el[1].mVec128.m128_f32[2],
    &v15.m_el[0].mVec128.m128_f32[2],
    &v15.m_el[1].mVec128.m128_f32[3],
    (const float *)&v15,
    v12);
  v15.m_el[1].mVec128.m128_f32[1] = (float)((float)(v32 * v21) + (float)(v31 * v18))
                                  + (float)(v30 * v15.m_el[2].mVec128.m128_f32[2]);
  v15.m_el[0].mVec128.m128_f32[3] = (float)((float)(v31 * v17) + (float)(v32 * v20))
                                  + (float)(v30 * v15.m_el[2].mVec128.m128_f32[1]);
  v15.m_el[0].mVec128.m128_f32[1] = (float)((float)(v31 * v16) + (float)(v32 * v19))
                                  + (float)(v30 * v15.m_el[2].mVec128.m128_f32[0]);
  v14 = (float)((float)(v28 * v21) + (float)(v27 * v18)) + (float)(v26 * v15.m_el[2].mVec128.m128_f32[2]);
  v15.m_el[1].mVec128.m128_f32[0] = (float)((float)(v27 * v17) + (float)(v28 * v20))
                                  + (float)(v26 * v15.m_el[2].mVec128.m128_f32[1]);
  v15.m_el[1].mVec128.m128_f32[2] = (float)((float)(v27 * v16) + (float)(v28 * v19))
                                  + (float)(v26 * v15.m_el[2].mVec128.m128_f32[0]);
  v15.m_el[0].mVec128.m128_f32[2] = (float)((float)(v24 * v21) + (float)(v23 * v18))
                                  + (float)(v22 * v15.m_el[2].mVec128.m128_f32[2]);
  v15.m_el[1].mVec128.m128_f32[3] = (float)((float)(v23 * v17) + (float)(v24 * v20))
                                  + (float)(v22 * v15.m_el[2].mVec128.m128_f32[1]);
  v15.m_el[0].mVec128.m128_f32[0] = (float)((float)(v23 * v16) + (float)(v24 * v19))
                                  + (float)(v22 * v15.m_el[2].mVec128.m128_f32[0]);
  btMatrix3x3::setValue(
    &v15,
    (int)&v22,
    &v15.m_el[1].mVec128.m128_f32[3],
    &v15.m_el[0].mVec128.m128_f32[2],
    &v15.m_el[1].mVec128.m128_f32[2],
    v15.m_el[1].mVec128.m128_f32,
    &v14,
    &v15.m_el[0].mVec128.m128_f32[1],
    &v15.m_el[0].mVec128.m128_f32[3],
    &v15.m_el[1].mVec128.m128_f32[1],
    v13);
  v11 = v2 + 272;
  *(float *)(v2 + 272) = v22;
  v2 += 276;
  *(float *)v2 = v23;
  v2 += 4;
  *(float *)v2 = v24;
  *(_DWORD *)(v2 + 4) = v25;
  *(float *)(v11 + 16) = v26;
  *(float *)(v11 + 20) = v27;
  *(float *)(v11 + 24) = v28;
  *(_DWORD *)(v11 + 28) = v29;
  *(float *)(v11 + 32) = v30;
  *(float *)(v11 + 36) = v31;
  *(float *)(v11 + 40) = v32;
  *(_DWORD *)(v11 + 44) = v33;
}
