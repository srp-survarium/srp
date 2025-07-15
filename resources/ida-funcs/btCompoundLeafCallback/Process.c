void __thiscall btCompoundLeafCallback::Process(btCompoundLeafCallback *this, btCollisionShape *leaf, int a3)
{
  btCollisionShape *v3; // esi
  btCompoundLeafCallback *v4; // ecx
  btCollisionShape_vtbl *v5; // eax
  float (__thiscall **p_getContactBreakingThreshold)(btCollisionShape *, float); // eax
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  btCollisionShape_vtbl *v23; // eax
  const float *v24; // [esp+0h] [ebp-100h]
  float v25; // [esp+10h] [ebp-F0h] BYREF
  float v26; // [esp+14h] [ebp-ECh]
  float v27; // [esp+18h] [ebp-E8h]
  int v28; // [esp+1Ch] [ebp-E4h]
  float v29; // [esp+28h] [ebp-D8h] BYREF
  float v30; // [esp+2Ch] [ebp-D4h] BYREF
  float v31; // [esp+30h] [ebp-D0h]
  float v32; // [esp+34h] [ebp-CCh]
  float v33; // [esp+38h] [ebp-C8h]
  btMatrix3x3 v34; // [esp+4Ch] [ebp-B4h] BYREF
  float (__thiscall *v35)(btCollisionShape *, float); // [esp+7Ch] [ebp-84h]
  float v36; // [esp+80h] [ebp-80h]
  float v37; // [esp+84h] [ebp-7Ch]
  float v38; // [esp+88h] [ebp-78h]
  float (__thiscall *v39)(btCollisionShape *, float); // [esp+8Ch] [ebp-74h]
  float v40; // [esp+90h] [ebp-70h]
  float v41; // [esp+94h] [ebp-6Ch]
  float v42; // [esp+98h] [ebp-68h]
  float (__thiscall *v43)(btCollisionShape *, float); // [esp+9Ch] [ebp-64h]
  float v44; // [esp+A0h] [ebp-60h]
  float v45; // [esp+A4h] [ebp-5Ch]
  float v46; // [esp+A8h] [ebp-58h]
  float (__thiscall *v47)(btCollisionShape *, float); // [esp+ACh] [ebp-54h]
  float v48[12]; // [esp+B0h] [ebp-50h] BYREF
  float v49[4]; // [esp+E0h] [ebp-20h] BYREF
  float v50[4]; // [esp+F0h] [ebp-10h] BYREF

  v34.m_el[1].mVec128.m128_i32[2] = *(_DWORD *)(a3 + 36);
  v3 = leaf;
  v4 = (btCompoundLeafCallback *)*((_DWORD *)leaf->__vftable[3].setMargin + 6);
  v34.m_el[0].mVec128.m128_i32[1] = (int)(&v4[2].m_dispatcher)[20 * v34.m_el[1].mVec128.m128_i32[2]];
  v5 = leaf[1].__vftable;
  if ( v5->setLocalScaling
    && ((*(int (__thiscall **)(void (__thiscall *)(btCollisionShape *, const btVector3 *)))(*(_DWORD *)v5->setLocalScaling
                                                                                          + 48))(v5->setLocalScaling)
      & 2) != 0 )
  {
    p_getContactBreakingThreshold = &leaf->getContactBreakingThreshold;
    *(unsigned __int64 *)((char *)v34.m_el[2].mVec128.m128_u64 + 4) = *(_QWORD *)p_getContactBreakingThreshold;
    v34.m_el[2].mVec128.m128_i32[3] = (int)p_getContactBreakingThreshold[2];
    v35 = p_getContactBreakingThreshold[3];
    v36 = *((float *)p_getContactBreakingThreshold + 4);
    v37 = *((float *)p_getContactBreakingThreshold + 5);
    v38 = *((float *)p_getContactBreakingThreshold + 6);
    v39 = p_getContactBreakingThreshold[7];
    v7 = *(float *)(a3 + 16);
    v8 = *(float *)(a3 + 20);
    v9 = *(float *)(a3 + 24);
    v10 = *(float *)a3;
    v11 = *(float *)(a3 + 4);
    v12 = *(float *)(a3 + 8);
    v40 = *((float *)p_getContactBreakingThreshold + 8);
    v41 = *((float *)p_getContactBreakingThreshold + 9);
    v42 = *((float *)p_getContactBreakingThreshold + 10);
    v43 = p_getContactBreakingThreshold[11];
    v44 = *((float *)p_getContactBreakingThreshold + 12);
    v45 = *((float *)p_getContactBreakingThreshold + 13);
    v46 = *((float *)p_getContactBreakingThreshold + 14);
    v47 = p_getContactBreakingThreshold[15];
    v30 = v8;
    v29 = v9;
    v25 = (float)(v7 - v10) * 0.5;
    v13 = (float)(v8 - v11) * 0.5;
    v14 = (float)(v9 - v12) * 0.5;
    v15 = (float)(v11 + v30) * 0.5;
    v16 = (float)(v12 + v29) * 0.5;
    LODWORD(v29) = LODWORD(v42) & _mask__AbsFloat_;
    LODWORD(v30) = LODWORD(v41) & _mask__AbsFloat_;
    v34.m_el[1].mVec128.m128_i32[1] = LODWORD(v40) & _mask__AbsFloat_;
    v34.m_el[0].mVec128.m128_i32[2] = LODWORD(v38) & _mask__AbsFloat_;
    v34.m_el[1].mVec128.m128_i32[0] = LODWORD(v37) & _mask__AbsFloat_;
    v34.m_el[1].mVec128.m128_i32[3] = LODWORD(v36) & _mask__AbsFloat_;
    v34.m_el[0].mVec128.m128_i32[3] = v34.m_el[2].mVec128.m128_i32[3] & _mask__AbsFloat_;
    v34.m_el[2].mVec128.m128_i32[0] = v34.m_el[2].mVec128.m128_i32[2] & _mask__AbsFloat_;
    v26 = v13;
    v27 = v14;
    v31 = (float)(v10 + v7) * 0.5;
    v32 = v15;
    v33 = v16;
    v34.m_el[0].mVec128.m128_i32[0] = v34.m_el[2].mVec128.m128_i32[1] & _mask__AbsFloat_;
    btMatrix3x3::setValue(
      &v34,
      (int)v48,
      v34.m_el[2].mVec128.m128_f32,
      &v34.m_el[0].mVec128.m128_f32[3],
      &v34.m_el[1].mVec128.m128_f32[3],
      v34.m_el[1].mVec128.m128_f32,
      &v34.m_el[0].mVec128.m128_f32[2],
      &v34.m_el[1].mVec128.m128_f32[1],
      &v30,
      &v29,
      v24);
    v17 = (float)((float)((float)(v34.m_el[2].mVec128.m128_f32[3] * v33) + (float)(v34.m_el[2].mVec128.m128_f32[2] * v32))
                + (float)(v34.m_el[2].mVec128.m128_f32[1] * v31))
        + v44;
    v18 = (float)((float)((float)(v38 * v33) + (float)(v37 * v32)) + (float)(v36 * v31)) + v45;
    v19 = (float)((float)((float)(v42 * v33) + (float)(v41 * v32)) + (float)(v40 * v31)) + v46;
    v20 = (float)((float)(v48[2] * v14) + (float)(v48[1] * v13)) + (float)(v48[0] * v25);
    v21 = (float)((float)(v48[6] * v14) + (float)(v48[5] * v13)) + (float)(v48[4] * v25);
    v22 = (float)((float)(v48[10] * v14) + (float)(v48[9] * v26)) + (float)(v48[8] * v25);
    v25 = v17 - v20;
    v26 = v18 - v21;
    v27 = v19 - v22;
    v28 = 0;
    v50[0] = v17 - v20;
    v50[1] = v18 - v21;
    v50[2] = v19 - v22;
    v50[3] = 0.0;
    v23 = leaf[1].__vftable;
    v49[0] = v20 + v17;
    v49[1] = v21 + v18;
    v49[2] = v22 + v19;
    v49[3] = 0.0;
    v25 = s_bm_current_air_resistance;
    v26 = 0.0;
    v27 = 0.0;
    v28 = 0;
    (*(void (__thiscall **)(void (__thiscall *)(btCollisionShape *, const btVector3 *), float *, float *, float *))(*(_DWORD *)v23->setLocalScaling + 52))(
      v23->setLocalScaling,
      v50,
      v49,
      &v25);
    v3 = leaf;
  }
  btCompoundLeafCallback::ProcessChildShape(v4, v3, v34.m_el[0].mVec128.m128_i32[1], v34.m_el[1].mVec128.m128_i32[2]);
}
