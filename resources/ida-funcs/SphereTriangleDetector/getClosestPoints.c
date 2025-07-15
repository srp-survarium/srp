void __thiscall SphereTriangleDetector::getClosestPoints(
        SphereTriangleDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *debugDraw,
        bool swapResults)
{
  float v5; // xmm6_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm5_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  double v36; // st7
  float v37; // xmm5_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm4_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float contactBreakingThreshold; // [esp+0h] [ebp-104h]
  const float *v60; // [esp+4h] [ebp-100h]
  float timeOfImpact; // [esp+10h] [ebp-F4h] BYREF
  unsigned __int64 depth; // [esp+14h] [ebp-F0h] BYREF
  float v63[3]; // [esp+1Ch] [ebp-E8h]
  float v64; // [esp+28h] [ebp-DCh] BYREF
  float v65; // [esp+2Ch] [ebp-D8h] BYREF
  float v66; // [esp+30h] [ebp-D4h] BYREF
  btVector3 resultNormal; // [esp+34h] [ebp-D0h] BYREF
  float v68; // [esp+4Ch] [ebp-B8h] BYREF
  btVector3 *sphereCenter; // [esp+50h] [ebp-B4h]
  float v70; // [esp+54h] [ebp-B0h] BYREF
  float v71; // [esp+58h] [ebp-ACh]
  float v72; // [esp+5Ch] [ebp-A8h]
  int v73; // [esp+60h] [ebp-A4h]
  float v74; // [esp+70h] [ebp-94h] BYREF
  btMatrix3x3 v75; // [esp+74h] [ebp-90h] BYREF
  int v76; // [esp+A4h] [ebp-60h]
  int v77; // [esp+A8h] [ebp-5Ch]
  int v78; // [esp+ACh] [ebp-58h]
  int v79; // [esp+B0h] [ebp-54h]
  int v80; // [esp+B4h] [ebp-50h]
  int v81; // [esp+B8h] [ebp-4Ch]
  int v82; // [esp+BCh] [ebp-48h]
  int v83; // [esp+C0h] [ebp-44h]
  btVector3 v84; // [esp+C4h] [ebp-40h]
  int v85; // [esp+D4h] [ebp-30h]
  int v86; // [esp+D8h] [ebp-2Ch]
  int v87; // [esp+DCh] [ebp-28h]
  int v88; // [esp+E0h] [ebp-24h]
  int v89; // [esp+E4h] [ebp-20h]
  int v90; // [esp+E8h] [ebp-1Ch]
  int v91; // [esp+ECh] [ebp-18h]
  int v92; // [esp+F0h] [ebp-14h]
  btVector3 point; // [esp+F4h] [ebp-10h] BYREF

  sphereCenter = (btVector3 *)this;
  v5 = input->m_transformA.m_origin.mVec128.m128_f32[1] - input->m_transformB.m_origin.mVec128.m128_f32[1];
  v6 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0];
  v7 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0];
  v8 = input->m_transformA.m_origin.mVec128.m128_f32[0] - input->m_transformB.m_origin.mVec128.m128_f32[0];
  v72 = input->m_transformA.m_origin.mVec128.m128_f32[2] - input->m_transformB.m_origin.mVec128.m128_f32[2];
  timeOfImpact = 0.0;
  v9 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
  v66 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1];
  *(float *)&depth = (float)((float)(v7 * v72) + (float)(v6 * v5)) + (float)(v9 * v8);
  v68 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1];
  v10 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
  v11 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2];
  *((float *)&depth + 1) = (float)((float)(v66 * v72) + (float)(v68 * v5)) + (float)(v10 * v8);
  v64 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2];
  v65 = v11;
  v12 = v11 * v5;
  v13 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2];
  v70 = v8;
  v14 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
  v63[0] = (float)((float)(v64 * v72) + v12) + (float)(v14 * v70);
  v63[1] = 0.0;
  v15 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
  v16 = (float)((float)(v14 * v13) + (float)(v65 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]))
      + (float)(v64 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  v17 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1];
  v75.m_el[0].mVec128.m128_f32[2] = v16;
  v18 = v14 * v17;
  v19 = v65 * v15;
  v20 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0];
  v21 = (float)(v18 + v19) + (float)(v64 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1]);
  v22 = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[0];
  v75.m_el[0].mVec128.m128_f32[1] = v21;
  v23 = (float)((float)(v14 * v20) + (float)(v65 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]))
      + (float)(v64 * v22);
  v24 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
  v64 = v23;
  v25 = v68;
  v26 = v68 * v24;
  v27 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1];
  v28 = (float)((float)(v10 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2]) + v26)
      + (float)(v66 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  v29 = v68;
  v68 = v28;
  v30 = v10 * v27;
  v31 = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1];
  v65 = (float)(v30 + (float)(v29 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1])) + (float)(v66 * v31);
  v32 = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[0];
  v66 = (float)((float)(v10 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0])
              + (float)(v25 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]))
      + (float)(v66 * v32);
  v33 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1];
  v75.m_el[0].mVec128.m128_f32[3] = (float)((float)(v9 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v6 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]))
                                  + (float)(v7 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  v34 = (float)((float)(v9 * v33) + (float)(v6 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v7 * v31);
  v35 = (float)((float)(v9 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0])
              + (float)(v6 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]))
      + (float)(v7 * v32);
  v74 = v34;
  v75.m_el[0].mVec128.m128_f32[0] = v35;
  btMatrix3x3::setValue(
    &v75,
    (int)&v75.m_el[2],
    &v74,
    &v75.m_el[0].mVec128.m128_f32[3],
    &v66,
    &v65,
    &v68,
    &v64,
    &v75.m_el[0].mVec128.m128_f32[1],
    &v75.m_el[0].mVec128.m128_f32[2],
    v60);
  v84.mVec128 = (__m128)v75.m_el[2];
  v85 = v76;
  v86 = v77;
  v87 = v78;
  v88 = v79;
  v36 = sphereCenter->mVec128.m128_f32[3];
  v89 = v80;
  v90 = v81;
  v91 = v82;
  v92 = v83;
  contactBreakingThreshold = v36;
  point.mVec128.m128_u64[0] = depth;
  point.mVec128.m128_u64[1] = LODWORD(v63[0]);
  if ( SphereTriangleDetector::collide(
         (SphereTriangleDetector *)&point,
         sphereCenter,
         &point,
         &resultNormal,
         (float *)&depth,
         &timeOfImpact,
         contactBreakingThreshold) )
  {
    if ( swapResults )
    {
      v37 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
      v38 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
      v39 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2] * v63[0];
      sphereCenter = (btVector3 *)input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2];
      v40 = (float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1] * *((float *)&depth + 1)) + v39)
          + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)&depth);
      v41 = (float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1] * *((float *)&depth + 1))
                  + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2] * v63[0]))
          + (float)(*(float *)&depth * input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0]);
      v42 = (float)((float)((float)(v63[0] * *(float *)&sphereCenter) + (float)(*((float *)&depth + 1) * v37))
                  + (float)(v38 * *(float *)&depth))
          * timeOfImpact;
      LODWORD(v70) = COERCE_UNSIGNED_INT(
                       (float)((float)(v63[0] * *(float *)&sphereCenter) + (float)(*((float *)&depth + 1) * v37))
                     + (float)(v38 * *(float *)&depth))
                   ^ _mask__NegFloat_;
      v75.m_el[1].mVec128.m128_f32[1] = v40 * timeOfImpact;
      LODWORD(v71) = LODWORD(v40) ^ _mask__NegFloat_;
      LODWORD(v72) = LODWORD(v41) ^ _mask__NegFloat_;
      v43 = (float)((float)((float)(v38 * resultNormal.mVec128.m128_f32[0])
                          + (float)(resultNormal.mVec128.m128_f32[2] * *(float *)&sphereCenter))
                  + (float)(resultNormal.mVec128.m128_f32[1] * v37))
          + input->m_transformB.m_origin.mVec128.m128_f32[0];
      v44 = resultNormal.mVec128.m128_f32[0] * input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0];
      v45 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1];
      v46 = (float)((float)((float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1]
                                          * resultNormal.mVec128.m128_f32[1])
                                  + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2]
                                          * resultNormal.mVec128.m128_f32[2]))
                          + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0]
                                  * resultNormal.mVec128.m128_f32[0]))
                  + input->m_transformB.m_origin.mVec128.m128_f32[1])
          + v75.m_el[1].mVec128.m128_f32[1];
      v75.m_el[1].mVec128.m128_f32[2] = v41 * timeOfImpact;
      v47 = (float)((float)((float)((float)(v45 * resultNormal.mVec128.m128_f32[1])
                                  + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2]
                                          * resultNormal.mVec128.m128_f32[2]))
                          + v44)
                  + input->m_transformB.m_origin.mVec128.m128_f32[2])
          + (float)(v41 * timeOfImpact);
      v73 = 0;
      *(float *)&depth = v43 + v42;
      *((float *)&depth + 1) = v46;
      v63[0] = v47;
      v63[1] = 0.0;
      ((void (__thiscall *)(btDiscreteCollisionDetectorInterface::Result *, float *, unsigned __int64 *, _DWORD))output->addContactPoint)(
        output,
        &v70,
        &depth,
        LODWORD(timeOfImpact));
    }
    else
    {
      v48 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
      v49 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
      v50 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2] * resultNormal.mVec128.m128_f32[2];
      v51 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)&depth;
      v70 = (float)((float)((float)(input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0]
                                  * resultNormal.mVec128.m128_f32[0])
                          + (float)(resultNormal.mVec128.m128_f32[2] * v48))
                  + (float)(resultNormal.mVec128.m128_f32[1] * v49))
          + input->m_transformB.m_origin.mVec128.m128_f32[0];
      v52 = (float)((float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1]
                                  * resultNormal.mVec128.m128_f32[1])
                          + v50)
                  + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * resultNormal.mVec128.m128_f32[0]))
          + input->m_transformB.m_origin.mVec128.m128_f32[1];
      v53 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2] * resultNormal.mVec128.m128_f32[2];
      v71 = v52;
      v54 = (float)((float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1]
                                  * resultNormal.mVec128.m128_f32[1])
                          + v53)
                  + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0] * resultNormal.mVec128.m128_f32[0]))
          + input->m_transformB.m_origin.mVec128.m128_f32[2];
      v55 = (float)((float)(v63[0] * v48) + (float)(*((float *)&depth + 1) * v49)) + v51;
      v56 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2] * v63[0];
      resultNormal.mVec128.m128_f32[1] = (float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1]
                                                       * *((float *)&depth + 1))
                                               + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2] * v63[0]))
                                       + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0]
                                               * *(float *)&depth);
      v57 = (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1] * *((float *)&depth + 1)) + v56;
      v58 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&depth;
      v72 = v54;
      v73 = 0;
      resultNormal.mVec128.m128_f32[0] = v55;
      resultNormal.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v57 + v58);
      ((void (__thiscall *)(btDiscreteCollisionDetectorInterface::Result *, btVector3 *, float *, _DWORD))output->addContactPoint)(
        output,
        &resultNormal,
        &v70,
        LODWORD(timeOfImpact));
    }
  }
}
