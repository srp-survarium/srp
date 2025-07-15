void __userpurge btCollisionWorld::rayTestSingle_::_43_::RayTester::Process(
        btCollisionWorld::rayTestSingle::__l43::RayTester *this@<ecx>,
        const float *a2@<edi>,
        btCollisionShape ***i,
        int a4)
{
  int v4; // ecx
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  float v22; // xmm5_4
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
  float v42; // xmm6_4
  float v43; // xmm4_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  btCollisionShape **v46; // eax
  float *v47; // esi
  unsigned int v48; // edi
  btCollisionWorld::RayResultCallback *v49; // ecx
  const btTransform *v50; // [esp-20h] [ebp-F8h]
  const btTransform *v51; // [esp-1Ch] [ebp-F4h]
  btCollisionObject *v52; // [esp-18h] [ebp-F0h]
  float v53; // [esp+10h] [ebp-C8h] BYREF
  btCollisionShape *v54; // [esp+14h] [ebp-C4h]
  float v55; // [esp+18h] [ebp-C0h] BYREF
  float v56; // [esp+1Ch] [ebp-BCh] BYREF
  float v57; // [esp+20h] [ebp-B8h] BYREF
  float v58; // [esp+24h] [ebp-B4h] BYREF
  float v59; // [esp+28h] [ebp-B0h] BYREF
  float v60; // [esp+2Ch] [ebp-ACh] BYREF
  float v61; // [esp+30h] [ebp-A8h] BYREF
  float v62; // [esp+34h] [ebp-A4h] BYREF
  btVector3 v63; // [esp+38h] [ebp-A0h]
  btCollisionWorld::RayResultCallback v64; // [esp+48h] [ebp-90h] BYREF
  float *v65; // [esp+60h] [ebp-78h]
  unsigned int v66; // [esp+64h] [ebp-74h]
  _QWORD v67[2]; // [esp+68h] [ebp-70h] BYREF
  btVector3 v68; // [esp+78h] [ebp-60h]
  btVector3 v69; // [esp+88h] [ebp-50h]
  btTransform v70; // [esp+98h] [ebp-40h] BYREF

  v4 = (int)i[1][6] + 80 * a4;
  v5 = *(float *)(v4 + 52);
  v6 = *(float *)(v4 + 48);
  v7 = *(float *)(v4 + 56);
  v54 = *(btCollisionShape **)(v4 + 64);
  v8 = (float *)i[2];
  v9 = v8[1];
  v10 = *v8;
  v11 = v8[2];
  v12 = v8[6];
  v63.mVec128.m128_f32[0] = (float)((float)((float)(*v8 * v6) + (float)(v9 * v5)) + (float)(v11 * v7)) + v8[12];
  v13 = (float)(v8[5] * v5) + (float)(v12 * v7);
  v14 = v8[4] * v6;
  v15 = v6 * v8[8];
  v16 = (float)(v13 + v14) + v8[13];
  v17 = v8[10];
  v63.mVec128.m128_f32[1] = v16;
  v18 = v8[9] * v5;
  v19 = v8[10] * v7;
  v20 = *(float *)(v4 + 24);
  v21 = v18 + v19;
  v22 = *(float *)(v4 + 8) * v8[8];
  v63.mVec128.m128_f32[2] = (float)(v21 + v15) + v8[14];
  v23 = v8[9] * v20;
  v63.mVec128.m128_i32[3] = 0;
  v24 = *(float *)(v4 + 40);
  v25 = v23 + (float)(v17 * v24);
  v26 = v8[9];
  v27 = v25 + v22;
  v28 = *(float *)(v4 + 36);
  v62 = v27;
  v29 = (float)(v26 * *(float *)(v4 + 20)) + (float)(v8[10] * v28);
  v30 = *(float *)(v4 + 16);
  v31 = *(float *)(v4 + 32);
  v58 = v29 + (float)(*(float *)(v4 + 4) * v8[8]);
  v32 = (float)((float)(v8[9] * v30) + (float)(v8[10] * v31)) + (float)(*(float *)v4 * v8[8]);
  v33 = *(float *)(v4 + 20);
  v60 = (float)((float)(v8[5] * v20) + (float)(v8[6] * v24)) + (float)(*(float *)(v4 + 8) * v8[4]);
  v34 = v8[5] * v33;
  v35 = *(float *)(v4 + 36);
  v57 = v32;
  v36 = v8[6] * v35;
  v37 = *(float *)(v4 + 16);
  v38 = (float)(v34 + v36) + (float)(v8[4] * *(float *)(v4 + 4));
  v39 = v8[6];
  v59 = v38;
  v40 = v8[5] * v37;
  v41 = *(float *)v4;
  v55 = (float)(v40 + (float)(v39 * *(float *)(v4 + 32))) + (float)(v8[4] * *(float *)v4);
  v42 = (float)((float)(v9 * v20) + (float)(v11 * v24)) + (float)(v10 * *(float *)(v4 + 8));
  v43 = v10 * *(float *)(v4 + 4);
  v44 = *(float *)(v4 + 20);
  v61 = v42;
  v45 = (float)((float)(v10 * v41) + (float)(v9 * *(float *)(v4 + 16))) + (float)(v11 * *(float *)(v4 + 32));
  v56 = (float)(v43 + (float)(v9 * v44)) + (float)(v11 * *(float *)(v4 + 36));
  v53 = v45;
  btMatrix3x3::setValue((btMatrix3x3 *)&v53, (int)v67, &v56, &v61, &v55, &v59, &v60, &v57, &v58, &v62, a2);
  v70.m_basis.m_el[0].mVec128.m128_u64[0] = v67[0];
  v70.m_basis.m_el[0].mVec128.m128_u64[1] = v67[1];
  v70.m_basis.m_el[1] = (btVector3)v68.mVec128;
  v46 = *i;
  v70.m_basis.m_el[2] = (btVector3)v69.mVec128;
  v70.m_origin = (btVector3)v63.mVec128;
  v46 += 51;
  v53 = *(float *)v46;
  *v46 = v54;
  v47 = (float *)i[5];
  v48 = (*(int (__thiscall **)(float *, int))(*(_DWORD *)v47 + 12))(v47, a4);
  btCollisionWorld::RayResultCallback::RayResultCallback(v49, (int)&v64);
  v64.__vftable = (btCollisionWorld::RayResultCallback_vtbl *)&`btCollisionWorld::rayTestSingle'::`42'::LocalInfoAdder2::`vftable';
  v52 = (btCollisionObject *)*i;
  v65 = v47;
  v51 = (const btTransform *)i[4];
  v66 = v48;
  v50 = (const btTransform *)i[3];
  v64.m_shape_id = v48;
  v64.m_closestHitFraction = v47[1];
  btCollisionWorld::rayTestSingle(v50, v51, v52, (btVoronoiSimplexSolver *)v54, &v70, &v64);
  *((float *)*i + 51) = v53;
}
