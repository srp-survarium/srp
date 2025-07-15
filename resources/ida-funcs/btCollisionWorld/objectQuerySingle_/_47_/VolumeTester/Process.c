void __userpurge btCollisionWorld::objectQuerySingle_::_47_::VolumeTester::Process(
        btCollisionWorld::objectQuerySingle::__l47::VolumeTester *this@<ecx>,
        const float *a2@<edi>,
        _DWORD *i,
        unsigned int a4)
{
  unsigned int v4; // ecx
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm3_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm5_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm0_4
  int v46; // eax
  int v47; // edx
  float v48; // xmm0_4
  int *v49; // eax
  int v50; // esi
  int v51; // eax
  unsigned __int64 v52; // [esp-4h] [ebp-D8h]
  float v53; // [esp+18h] [ebp-BCh] BYREF
  float v54; // [esp+1Ch] [ebp-B8h] BYREF
  float v55; // [esp+20h] [ebp-B4h] BYREF
  btMatrix3x3 v56; // [esp+24h] [ebp-B0h] BYREF
  float v57; // [esp+54h] [ebp-80h]
  float v58; // [esp+58h] [ebp-7Ch]
  float v59; // [esp+5Ch] [ebp-78h]
  int v60; // [esp+60h] [ebp-74h]
  _DWORD v61[12]; // [esp+64h] [ebp-70h] BYREF
  _DWORD v62[16]; // [esp+94h] [ebp-40h] BYREF

  v4 = *(_DWORD *)(i[1] + 24) + 80 * a4;
  v5 = *(float *)(v4 + 52);
  v6 = *(float *)(v4 + 48);
  v7 = *(float *)(v4 + 56);
  v56.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(v4 + 64);
  v8 = *(float **)(*i + 20);
  v9 = v8[1];
  v10 = *v8;
  v11 = v8[2];
  v12 = v8[5];
  v57 = (float)((float)((float)(*v8 * v6) + (float)(v9 * v5)) + (float)(v11 * v7)) + v8[12];
  v13 = (float)(v8[6] * v7) + (float)(v12 * v5);
  v14 = v8[4] * v6;
  v15 = v6 * v8[8];
  v16 = (float)(v13 + v14) + v8[13];
  v17 = v8[10];
  v58 = v16;
  v18 = v8[10] * v7;
  v19 = v8[9] * v5;
  v20 = *(float *)(v4 + 8) * v8[8];
  v21 = v18 + v19;
  v22 = *(float *)(v4 + 24);
  v59 = (float)(v21 + v15) + v8[14];
  v23 = v8[9] * v22;
  v60 = 0;
  v24 = *(float *)(v4 + 40);
  v25 = v23 + (float)(v17 * v24);
  v26 = v8[9];
  v27 = v25 + v20;
  v28 = *(float *)(v4 + 36);
  v56.m_el[1].mVec128.m128_f32[1] = v27;
  v29 = (float)(v26 * *(float *)(v4 + 20)) + (float)(v8[10] * v28);
  v30 = *(float *)(v4 + 16);
  v31 = *(float *)(v4 + 32);
  v55 = v29 + (float)(*(float *)(v4 + 4) * v8[8]);
  v32 = (float)((float)(v8[9] * v30) + (float)(v8[10] * v31)) + (float)(*(float *)v4 * v8[8]);
  v33 = *(float *)(v4 + 20);
  v56.m_el[0].mVec128.m128_f32[1] = (float)((float)(v8[5] * v22) + (float)(v8[6] * v24))
                                  + (float)(*(float *)(v4 + 8) * v8[4]);
  v34 = v8[5] * v33;
  v35 = *(float *)(v4 + 36);
  v56.m_el[1].mVec128.m128_f32[2] = v32;
  v36 = v8[6] * v35;
  v37 = *(float *)(v4 + 16);
  v38 = (float)(v34 + v36) + (float)(v8[4] * *(float *)(v4 + 4));
  v39 = v8[6];
  v56.m_el[1].mVec128.m128_f32[0] = v38;
  v40 = v8[5] * v37;
  v41 = *(float *)v4;
  v56.m_el[0].mVec128.m128_f32[3] = (float)(v40 + (float)(v39 * *(float *)(v4 + 32))) + (float)(v8[4] * *(float *)v4);
  v42 = (float)((float)(v10 * *(float *)(v4 + 8)) + (float)(v9 * v22)) + (float)(v11 * v24);
  v43 = (float)(v10 * *(float *)(v4 + 4)) + (float)(v9 * *(float *)(v4 + 20));
  v44 = v11 * *(float *)(v4 + 36);
  v45 = (float)((float)(v9 * *(float *)(v4 + 16)) + (float)(v11 * *(float *)(v4 + 32))) + (float)(v10 * v41);
  v53 = v42;
  v54 = v43 + v44;
  v56.m_el[0].mVec128.m128_f32[0] = v45;
  btMatrix3x3::setValue(
    &v56,
    (int)v61,
    &v54,
    &v53,
    &v56.m_el[0].mVec128.m128_f32[3],
    v56.m_el[1].mVec128.m128_f32,
    &v56.m_el[0].mVec128.m128_f32[1],
    &v56.m_el[1].mVec128.m128_f32[2],
    &v55,
    &v56.m_el[1].mVec128.m128_f32[1],
    a2);
  v62[0] = v61[0];
  v62[1] = v61[1];
  v62[2] = v61[2];
  v62[3] = v61[3];
  v62[4] = v61[4];
  v62[5] = v61[5];
  v62[6] = v61[6];
  v62[7] = v61[7];
  v62[8] = v61[8];
  v62[9] = v61[9];
  v62[10] = v61[10];
  v62[11] = v61[11];
  v46 = *i;
  v47 = v56.m_el[0].mVec128.m128_i32[2];
  v48 = s_bm_current_air_resistance;
  *(float *)&v62[12] = v57;
  *(float *)&v62[13] = v58;
  *(float *)&v62[14] = v59;
  v62[15] = v60;
  v49 = (int *)(*(_DWORD *)(v46 + 12) + 204);
  v50 = *v49;
  *v49 = v56.m_el[0].mVec128.m128_i32[2];
  v51 = *i;
  v56.m_el[2].mVec128.m128_u64[1] = __PAIR64__(a4, *(_DWORD *)(*i + 24));
  v56.m_el[2].mVec128.m128_u64[0] = LODWORD(v48) | 0xFFFF000100000000uLL;
  v56.m_el[1].mVec128.m128_i32[3] = (int)&`btCollisionWorld::objectQuerySingle'::`46'::LocalInfoAdder::`vftable';
  v56.m_el[2].mVec128.m128_i32[0] = *(_DWORD *)(v56.m_el[2].mVec128.m128_i32[2] + 4);
  *((float *)&v52 + 1) = *(float *)(v51 + 28);
  LODWORD(v52) = &v56.m_el[1].mVec128.m128_i32[3];
  btCollisionWorld::objectQuerySingle(*(_QWORD *)v51, *(_QWORD *)(v51 + 8), __PAIR64__(v62, v47), v52);
  *(_DWORD *)(*(_DWORD *)(*i + 12) + 204) = v50;
}
