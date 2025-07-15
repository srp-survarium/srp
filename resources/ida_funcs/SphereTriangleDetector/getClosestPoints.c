void __thiscall SphereTriangleDetector::getClosestPoints(
        SphereTriangleDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *debugDraw,
        bool swapResults)
{
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  int v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  unsigned int v18; // xmm5_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  unsigned int v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  double m_contactBreakingThreshold; // st7
  __m128i v25; // xmm0
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  unsigned int v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm4_4
  unsigned int v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm3_4
  void (__thiscall *addContactPoint)(btDiscreteCollisionDetectorInterface::Result *, const btVector3 *, const btVector3 *, float); // edx
  float v45; // xmm4_4
  unsigned int v46; // xmm6_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  unsigned int v53; // xmm0_4
  float *timeOfImpact; // [esp+36Ch] [ebp-D4h]
  float v55; // [esp+370h] [ebp-D0h]
  float v56; // [esp+380h] [ebp-C0h]
  unsigned int v57; // [esp+380h] [ebp-C0h]
  float v58; // [esp+384h] [ebp-BCh]
  float v59; // [esp+384h] [ebp-BCh]
  float v60; // [esp+388h] [ebp-B8h]
  unsigned int v61; // [esp+388h] [ebp-B8h]
  unsigned int v62; // [esp+38Ch] [ebp-B4h]
  btVector3 resultNormal; // [esp+390h] [ebp-B0h] BYREF
  btVector3 v64; // [esp+3A0h] [ebp-A0h] BYREF
  float v65; // [esp+3B0h] [ebp-90h] BYREF
  float v66; // [esp+3B4h] [ebp-8Ch]
  __int64 v67; // [esp+3B8h] [ebp-88h]
  __m128i v68; // [esp+3C0h] [ebp-80h] BYREF
  __m128i v69; // [esp+3D0h] [ebp-70h] BYREF
  __m128i v70; // [esp+3E0h] [ebp-60h] BYREF
  float v71; // [esp+3F4h] [ebp-4Ch]
  __m128i v72; // [esp+400h] [ebp-40h]
  __m128i v73; // [esp+410h] [ebp-30h]
  __m128i v74; // [esp+420h] [ebp-20h]
  btVector3 sphereCenter; // [esp+430h] [ebp-10h] BYREF

  v5 = input->m_transformA.m_origin.mVec128.m128_f32[1] - input->m_transformB.m_origin.mVec128.m128_f32[1];
  v6 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0];
  v7 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0];
  v8 = input->m_transformA.m_origin.mVec128.m128_f32[0] - input->m_transformB.m_origin.mVec128.m128_f32[0];
  resultNormal.mVec128.m128_f32[2] = input->m_transformA.m_origin.mVec128.m128_f32[2]
                                   - input->m_transformB.m_origin.mVec128.m128_f32[2];
  v65 = 0.0;
  v9 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
  v58 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1];
  v64.mVec128.m128_f32[0] = (float)((float)(v7 * resultNormal.mVec128.m128_f32[2]) + (float)(v6 * v5))
                          + (float)(v9 * v8);
  v66 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1];
  v10 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
  resultNormal.mVec128.m128_f32[0] = v8;
  v11 = v10 * v8;
  v12 = input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[2];
  v13 = (float)((float)(v58 * resultNormal.mVec128.m128_f32[2]) + (float)(v66 * v5)) + v11;
  v14 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2];
  v64.mVec128.m128_f32[1] = v13;
  v56 = v14;
  v60 = *(float *)&v12;
  v15 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
  v16 = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2];
  v64.mVec128.m128_f32[2] = (float)((float)(v14 * resultNormal.mVec128.m128_f32[2]) + (float)(v60 * v5))
                          + (float)(v15 * resultNormal.mVec128.m128_f32[0]);
  v17 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
  v64.mVec128.m128_i32[3] = 0;
  *(float *)&v18 = (float)((float)(v15 * v16) + (float)(v60 * v17))
                 + (float)(v56 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  v19 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
  *((float *)&v67 + 1) = (float)((float)(v15 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1])
                               + (float)(v60 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v56 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1]);
  v20 = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[0];
  *(float *)&v67 = (float)((float)(v15 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v60 * v19))
                 + (float)(v56 * v20);
  *(float *)&v61 = (float)((float)(v10 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(v66 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v58 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v62 = (float)((float)(v10 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v66 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(v58 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1]);
  *(float *)&v57 = (float)((float)(v10 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v66 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]))
                 + (float)(v58 * v20);
  *(float *)&v21 = (float)((float)(v9 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(v6 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v7 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2]);
  v59 = (float)(v9 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1])
      + (float)(v6 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]);
  v22 = v9 * input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0];
  v23 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
  m_contactBreakingThreshold = this->m_contactBreakingThreshold;
  *(float *)&v68.m128i_i32[1] = v59 + (float)(v7 * input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1]);
  v69.m128i_i64[0] = __PAIR64__(v62, v57);
  *(float *)&timeOfImpact = m_contactBreakingThreshold;
  *(float *)v68.m128i_i32 = (float)(v22 + (float)(v6 * v23)) + (float)(v7 * v20);
  v69.m128i_i64[1] = v61;
  v68.m128i_i64[1] = v21;
  v72 = _mm_load_si128(&v68);
  v25 = _mm_load_si128(&v69);
  v70.m128i_i64[0] = v67;
  v73 = v25;
  v70.m128i_i64[1] = v18;
  v74 = _mm_load_si128(&v70);
  sphereCenter.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v64);
  if ( SphereTriangleDetector::collide(
         this,
         (int)this,
         input->m_transformA.m_basis.m_el,
         &sphereCenter,
         &v64,
         &resultNormal,
         &v65,
         timeOfImpact,
         v55) )
  {
    if ( swapResults )
    {
      v26 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
      v27 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
      v28 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
      v29 = (float)((float)(v27 * resultNormal.mVec128.m128_f32[2]) + (float)(v26 * resultNormal.mVec128.m128_f32[1]))
          + (float)(v28 * resultNormal.mVec128.m128_f32[0]);
      v30 = (float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1] * resultNormal.mVec128.m128_f32[1])
                  + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2] * resultNormal.mVec128.m128_f32[2]))
          + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * resultNormal.mVec128.m128_f32[0]);
      *(float *)&v31 = (float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1]
                                     * resultNormal.mVec128.m128_f32[1])
                             + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2]
                                     * resultNormal.mVec128.m128_f32[2]))
                     + (float)(resultNormal.mVec128.m128_f32[0] * input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0]);
      resultNormal.mVec128.m128_f32[0] = -v29;
      resultNormal.mVec128.m128_i32[1] = LODWORD(v30) ^ 0x80000000;
      v71 = v30 * v65;
      resultNormal.mVec128.m128_u64[1] = v31 ^ 0x80000000LL;
      v32 = (float)((float)(v28 * v64.mVec128.m128_f32[0]) + (float)(v27 * v64.mVec128.m128_f32[2]))
          + (float)(v26 * v64.mVec128.m128_f32[1]);
      v33 = (float)((float)((float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1]
                                          * v64.mVec128.m128_f32[1])
                                  + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2]
                                          * v64.mVec128.m128_f32[2]))
                          + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * v64.mVec128.m128_f32[0]))
                  + input->m_transformB.m_origin.mVec128.m128_f32[1])
          + (float)(v30 * v65);
      *(float *)&v34 = (float)((float)((float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1]
                                                     * v64.mVec128.m128_f32[1])
                                             + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2]
                                                     * v64.mVec128.m128_f32[2]))
                                     + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0]
                                             * v64.mVec128.m128_f32[0]))
                             + input->m_transformB.m_origin.mVec128.m128_f32[2])
                     + (float)(*(float *)&v31 * v65);
      v64.mVec128.m128_f32[0] = (float)(v32 + input->m_transformB.m_origin.mVec128.m128_f32[0]) + (float)(v29 * v65);
      v64.mVec128.m128_f32[1] = v33;
      v64.mVec128.m128_u64[1] = v34;
      ((void (__stdcall *)(btVector3 *, btVector3 *, _DWORD))output->addContactPoint)(&resultNormal, &v64, LODWORD(v65));
    }
    else
    {
      v35 = v64.mVec128.m128_f32[0];
      v36 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
      v37 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
      v38 = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
      v39 = v64.mVec128.m128_f32[1];
      v40 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2];
      v64.mVec128.m128_f32[0] = (float)((float)((float)(v37 * v64.mVec128.m128_f32[0])
                                              + (float)(v36 * v64.mVec128.m128_f32[2]))
                                      + (float)(v38 * v64.mVec128.m128_f32[1]))
                              + input->m_transformB.m_origin.mVec128.m128_f32[0];
      v41 = (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1] * v64.mVec128.m128_f32[1])
          + (float)(v40 * v64.mVec128.m128_f32[2]);
      v42 = v35 * input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0];
      v43 = v35 * input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0];
      addContactPoint = output->addContactPoint;
      v64.mVec128.m128_f32[1] = (float)(v41 + v42) + input->m_transformB.m_origin.mVec128.m128_f32[1];
      v45 = resultNormal.mVec128.m128_f32[1];
      *(float *)&v46 = (float)((float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1] * v39)
                                     + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2]
                                             * v64.mVec128.m128_f32[2]))
                             + v43)
                     + input->m_transformB.m_origin.mVec128.m128_f32[2];
      v47 = (float)(v36 * resultNormal.mVec128.m128_f32[2]) + (float)(v38 * resultNormal.mVec128.m128_f32[1]);
      v48 = resultNormal.mVec128.m128_f32[0];
      v49 = v47 + (float)(v37 * resultNormal.mVec128.m128_f32[0]);
      v50 = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2];
      resultNormal.mVec128.m128_f32[0] = v49;
      v51 = (float)((float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1] * resultNormal.mVec128.m128_f32[1])
                  + (float)(v50 * resultNormal.mVec128.m128_f32[2]))
          + (float)(input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * v48);
      v52 = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2];
      resultNormal.mVec128.m128_f32[1] = v51;
      *(float *)&v53 = (float)((float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1] * v45)
                             + (float)(v52 * resultNormal.mVec128.m128_f32[2]))
                     + (float)(input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0] * v48);
      v64.mVec128.m128_u64[1] = v46;
      resultNormal.mVec128.m128_u64[1] = v53;
      ((void (__stdcall *)(btVector3 *, btVector3 *, _DWORD))addContactPoint)(&resultNormal, &v64, LODWORD(v65));
    }
  }
}
