void __userpurge btSoftBodyTriangleCallback::setTimeStepAndCounters(
        btSoftBodyTriangleCallback *this@<ecx>,
        const btDispatcherInfo *a2@<eax>,
        const float *a3@<edi>,
        float a4@<xmm0>,
        btSoftBodyTriangleCallback *const thisa,
        btManifoldResult *resultOut,
        struct btManifoldResult *a7)
{
  btSoftBody *m_softBody; // ecx
  btMatrix3x3 *v8; // ecx
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float m_collisionMarginTriangle; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  unsigned int v34; // xmm1_4
  unsigned int v35; // xmm3_4
  unsigned int v36; // xmm2_4
  const float *v37; // [esp-4h] [ebp-110h]
  btMatrix3x3 v38; // [esp+8h] [ebp-104h] BYREF
  float v39; // [esp+38h] [ebp-D4h] BYREF
  float v40; // [esp+3Ch] [ebp-D0h] BYREF
  float v41; // [esp+40h] [ebp-CCh]
  float v42; // [esp+44h] [ebp-C8h] BYREF
  float v43; // [esp+48h] [ebp-C4h] BYREF
  btVector3 v44; // [esp+4Ch] [ebp-C0h] BYREF
  float v45; // [esp+5Ch] [ebp-B0h] BYREF
  float v46; // [esp+60h] [ebp-ACh]
  float v47; // [esp+64h] [ebp-A8h]
  float v48; // [esp+6Ch] [ebp-A0h]
  float v49; // [esp+70h] [ebp-9Ch]
  float v50; // [esp+74h] [ebp-98h]
  float v51; // [esp+7Ch] [ebp-90h]
  float v52; // [esp+80h] [ebp-8Ch]
  float v53; // [esp+84h] [ebp-88h]
  float v54; // [esp+9Ch] [ebp-70h]
  float v55; // [esp+A0h] [ebp-6Ch]
  float v56; // [esp+A4h] [ebp-68h]
  float v57; // [esp+ACh] [ebp-60h]
  float v58; // [esp+B0h] [ebp-5Ch]
  float v59; // [esp+B4h] [ebp-58h]
  float v60; // [esp+BCh] [ebp-50h] BYREF
  float v61; // [esp+C0h] [ebp-4Ch]
  float v62[2]; // [esp+C4h] [ebp-48h]
  btTransform v63; // [esp+CCh] [ebp-40h] BYREF

  m_softBody = thisa->m_softBody;
  thisa->m_dispatchInfoPtr = a2;
  thisa->m_collisionMarginTriangle = a4 + 0.059999999;
  thisa->m_resultOut = resultOut;
  m_softBody->getAabb(m_softBody, &v44, (btVector3 *)&v60);
  v57 = (float)(v60 - v44.mVec128.m128_f32[0]) * 0.5;
  v58 = (float)(v61 - v44.mVec128.m128_f32[1]) * 0.5;
  v59 = (float)(v62[0] - v44.mVec128.m128_f32[2]) * 0.5;
  v38.m_el[0].mVec128.m128_f32[1] = (float)(v44.mVec128.m128_f32[0] + v60) * 0.5;
  v38.m_el[0].mVec128.m128_f32[2] = (float)(v44.mVec128.m128_f32[1] + v61) * 0.5;
  v38.m_el[0].mVec128.m128_f32[3] = (float)(v62[0] + v44.mVec128.m128_f32[2]) * 0.5;
  btMatrix3x3::setIdentity(v8, (int)&v45);
  v9 = (float *)btTransform::inverse(&v63, (int)&thisa->m_triBody->m_worldTransform, &v63);
  v10 = *v9;
  v11 = v9[1];
  v12 = v38.m_el[0].mVec128.m128_f32[3] * v9[2];
  v41 = v9[2];
  v54 = (float)((float)(v12 + (float)(v10 * v38.m_el[0].mVec128.m128_f32[1]))
              + (float)(v38.m_el[0].mVec128.m128_f32[2] * v11))
      + v9[12];
  v13 = v9[6] * v38.m_el[0].mVec128.m128_f32[3];
  v38.m_el[0].mVec128.m128_f32[0] = v11;
  v14 = v38.m_el[0].mVec128.m128_f32[1] * v9[8];
  v15 = v9[9] * v38.m_el[0].mVec128.m128_f32[2];
  v55 = (float)((float)(v13 + (float)(v9[5] * v38.m_el[0].mVec128.m128_f32[2]))
              + (float)(v9[4] * v38.m_el[0].mVec128.m128_f32[1]))
      + v9[13];
  v16 = v9[10] * v52;
  v17 = (float)((float)((float)(v9[10] * v38.m_el[0].mVec128.m128_f32[3]) + v15) + v14) + v9[14];
  v18 = v9[9];
  v19 = v9[10];
  v56 = v17;
  v20 = v9[9];
  v38.m_el[2].mVec128.m128_f32[2] = (float)((float)(v18 * v50) + (float)(v19 * v53)) + (float)(v9[8] * v47);
  v21 = (float)((float)(v20 * v49) + v16) + (float)(v9[8] * v46);
  v22 = v9[9] * v48;
  v39 = v21;
  v23 = (float)(v22 + (float)(v19 * v51)) + (float)(v9[8] * v45);
  v24 = v9[6];
  v38.m_el[2].mVec128.m128_f32[3] = v23;
  v25 = (float)((float)(v9[5] * v50) + (float)(v24 * v53)) + (float)(v47 * v9[4]);
  v26 = v9[6] * v52;
  v43 = v25;
  v27 = (float)((float)(v9[5] * v49) + v26) + (float)(v46 * v9[4]);
  v28 = v9[6];
  v38.m_el[2].mVec128.m128_f32[0] = (float)((float)(v50 * v38.m_el[0].mVec128.m128_f32[0]) + (float)(v53 * v41))
                                  + (float)(v47 * v10);
  v42 = v27;
  v40 = (float)((float)(v9[5] * v48) + (float)(v28 * v51)) + (float)(v9[4] * v45);
  v38.m_el[2].mVec128.m128_f32[1] = (float)((float)(v49 * v38.m_el[0].mVec128.m128_f32[0]) + (float)(v52 * v41))
                                  + (float)(v46 * v10);
  v38.m_el[0].mVec128.m128_f32[0] = (float)((float)(v51 * v41) + (float)(v10 * v45))
                                  + (float)(v48 * v38.m_el[0].mVec128.m128_f32[0]);
  btMatrix3x3::setValue(
    &v38,
    (int)&v45,
    &v38.m_el[2].mVec128.m128_f32[1],
    v38.m_el[2].mVec128.m128_f32,
    &v40,
    &v42,
    &v43,
    &v38.m_el[2].mVec128.m128_f32[3],
    &v39,
    &v38.m_el[2].mVec128.m128_f32[2],
    a3);
  m_collisionMarginTriangle = thisa->m_collisionMarginTriangle;
  v38.m_el[0].mVec128.m128_f32[1] = m_collisionMarginTriangle + v57;
  v38.m_el[0].mVec128.m128_f32[2] = v58 + m_collisionMarginTriangle;
  v38.m_el[0].mVec128.m128_f32[3] = v59 + m_collisionMarginTriangle;
  v38.m_el[2].mVec128.m128_i32[1] = LODWORD(v53) & _mask__AbsFloat_;
  v38.m_el[2].mVec128.m128_i32[0] = LODWORD(v52) & _mask__AbsFloat_;
  LODWORD(v40) = LODWORD(v51) & _mask__AbsFloat_;
  LODWORD(v42) = LODWORD(v50) & _mask__AbsFloat_;
  LODWORD(v43) = LODWORD(v49) & _mask__AbsFloat_;
  v38.m_el[2].mVec128.m128_i32[3] = LODWORD(v48) & _mask__AbsFloat_;
  LODWORD(v39) = LODWORD(v47) & _mask__AbsFloat_;
  v38.m_el[2].mVec128.m128_i32[2] = LODWORD(v46) & _mask__AbsFloat_;
  v38.m_el[0].mVec128.m128_i32[0] = LODWORD(v45) & _mask__AbsFloat_;
  btMatrix3x3::setValue(
    &v38,
    (int)&v45,
    &v38.m_el[2].mVec128.m128_f32[2],
    &v39,
    &v38.m_el[2].mVec128.m128_f32[3],
    &v43,
    &v42,
    &v40,
    v38.m_el[2].mVec128.m128_f32,
    &v38.m_el[2].mVec128.m128_f32[1],
    v37);
  v30 = (float)((float)(v45 * v38.m_el[0].mVec128.m128_f32[1]) + (float)(v47 * v38.m_el[0].mVec128.m128_f32[3]))
      + (float)(v46 * v38.m_el[0].mVec128.m128_f32[2]);
  v31 = (float)((float)(v50 * v38.m_el[0].mVec128.m128_f32[3]) + (float)(v49 * v38.m_el[0].mVec128.m128_f32[2]))
      + (float)(v48 * v38.m_el[0].mVec128.m128_f32[1]);
  v32 = (float)((float)(v53 * v38.m_el[0].mVec128.m128_f32[3]) + (float)(v52 * v38.m_el[0].mVec128.m128_f32[2]))
      + (float)(v51 * v38.m_el[0].mVec128.m128_f32[1]);
  v44.mVec128.m128_f32[0] = v54 - v30;
  v33 = v30 + v54;
  v44.mVec128.m128_f32[1] = v55 - v31;
  *(float *)&v34 = v31 + v55;
  *(float *)&v35 = v56 - v32;
  *(float *)&v36 = v32 + v56;
  v44.mVec128.m128_u64[1] = v35;
  thisa->m_aabbMin = (btVector3)v44.mVec128;
  *(unsigned __int64 *)((char *)v44.mVec128.m128_u64 + 4) = __PAIR64__(v36, v34);
  v44.mVec128.m128_i32[3] = 0;
  thisa->m_aabbMax.mVec128.m128_f32[0] = v33;
  *(unsigned __int64 *)((char *)thisa->m_aabbMax.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v44.mVec128.m128_u64
                                                                                             + 4);
  thisa->m_aabbMax.mVec128.m128_i32[3] = v44.mVec128.m128_i32[3];
}
