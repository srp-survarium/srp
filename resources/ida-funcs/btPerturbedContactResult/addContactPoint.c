void __thiscall btPerturbedContactResult::addContactPoint(
        btPerturbedContactResult *this,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float orgDepth)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float *v8; // eax
  float v9; // xmm4_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm4_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  float v47; // xmm6_4
  const btVector3 *v48; // eax
  float v49; // xmm0_4
  int *v50; // esi
  unsigned int v51; // xmm0_4
  unsigned int v52; // xmm1_4
  float *v53; // eax
  float v54; // xmm6_4
  float v55; // xmm4_4
  float v56; // xmm2_4
  float v57; // xmm0_4
  float v58; // xmm5_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm3_4
  float v62; // xmm7_4
  float v63; // xmm4_4
  float v64; // xmm3_4
  float v65; // xmm7_4
  float v66; // xmm3_4
  float v67; // xmm6_4
  float v68; // xmm5_4
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm3_4
  float v73; // xmm6_4
  float v74; // xmm7_4
  float v75; // xmm6_4
  float v76; // xmm5_4
  float v77; // xmm7_4
  float v78; // xmm6_4
  float v79; // xmm5_4
  float v80; // xmm7_4
  float v81; // xmm5_4
  float v82; // xmm6_4
  float v83; // xmm5_4
  float v84; // xmm7_4
  float v85; // xmm5_4
  float v86; // xmm6_4
  float v87; // xmm7_4
  float v88; // xmm6_4
  float v89; // xmm5_4
  float v90; // xmm7_4
  float v91; // xmm4_4
  float v92; // xmm6_4
  float v93; // xmm0_4
  float v94; // xmm4_4
  float v95; // xmm3_4
  float v96; // xmm1_4
  float v97; // xmm2_4
  btManifoldResult *m_originalManifoldResult; // ebx
  _DWORD *v99; // esi
  const float *v100; // [esp+4h] [ebp-F0h]
  btMatrix3x3 v101; // [esp+18h] [ebp-DCh] BYREF
  float v102; // [esp+4Ch] [ebp-A8h] BYREF
  float v103; // [esp+50h] [ebp-A4h] BYREF
  float v104; // [esp+54h] [ebp-A0h] BYREF
  float v105; // [esp+58h] [ebp-9Ch] BYREF
  float v106; // [esp+5Ch] [ebp-98h] BYREF
  float v107; // [esp+60h] [ebp-94h] BYREF
  float v108; // [esp+64h] [ebp-90h] BYREF
  float v109; // [esp+68h] [ebp-8Ch]
  float v110; // [esp+6Ch] [ebp-88h]
  float v111; // [esp+74h] [ebp-80h]
  float v112; // [esp+78h] [ebp-7Ch]
  float v113; // [esp+7Ch] [ebp-78h]
  float v114; // [esp+84h] [ebp-70h]
  float v115; // [esp+88h] [ebp-6Ch]
  float v116; // [esp+8Ch] [ebp-68h]
  float v117[2]; // [esp+94h] [ebp-60h] BYREF
  float v118; // [esp+9Ch] [ebp-58h]
  int v119; // [esp+A0h] [ebp-54h]
  _DWORD v120[4]; // [esp+A4h] [ebp-50h] BYREF
  btTransform v121; // [esp+B4h] [ebp-40h] BYREF

  if ( this->m_perturbA )
  {
    v5 = normalOnBInWorld->mVec128.m128_f32[2] * orgDepth;
    v6 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * orgDepth);
    v101.m_el[1].mVec128.m128_f32[0] = pointInWorld->mVec128.m128_f32[1]
                                     + (float)(normalOnBInWorld->mVec128.m128_f32[1] * orgDepth);
    v7 = pointInWorld->mVec128.m128_f32[2] + v5;
    v101.m_el[0].mVec128.m128_f32[3] = v6;
    v101.m_el[1].mVec128.m128_f32[1] = v7;
    v8 = (float *)btTransform::inverse((btTransform *)this, (int)&this->m_transformA, &v121);
    v9 = v8[14];
    v10 = v8[12];
    v11 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v12 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v13 = v8[13];
    v14 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v15 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v101.m_el[1].mVec128.m128_f32[3] = (float)((float)((float)(v11 * v9) + (float)(v12 * v10)) + (float)(v14 * v13))
                                     + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[0];
    v16 = (float)((float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v13)
                        + (float)(v15 * v9))
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v10))
        + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[1];
    v17 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v101.m_el[2].mVec128.m128_f32[0] = v16;
    v18 = (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v13)
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v9);
    v19 = v8[2] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v20 = (float)(v18 + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v10))
        + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[2];
    v21 = v8[6];
    v22 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v21;
    v101.m_el[2].mVec128.m128_f32[1] = v20;
    v23 = v8[10];
    v24 = v22 + (float)(v17 * v23);
    v25 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v26 = v24 + v19;
    v27 = v8[9];
    v101.m_el[0].mVec128.m128_f32[0] = v26;
    v28 = (float)(v25 * v8[5]) + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v27);
    v29 = v8[4];
    v30 = v8[8];
    v106 = v28 + (float)(v8[1] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
    v31 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v29)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v30))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * *v8);
    v32 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v33 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v21;
    v102 = v31;
    v34 = v33 + (float)(v32 * v23);
    v35 = v8[5];
    v36 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v107 = v34 + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v8[2]);
    v37 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v35;
    v38 = v8[4];
    v39 = (float)(v37 + (float)(v36 * v8[9]))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v8[1]);
    v40 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v105 = v39;
    v41 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v38;
    v42 = *v8;
    v103 = (float)(v41 + (float)(v40 * v8[8]))
         + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * *v8);
    v43 = (float)((float)(v12 * v8[2]) + (float)(v14 * v21)) + (float)(v11 * v23);
    v44 = (float)(v12 * v8[1]) + (float)(v14 * v8[5]);
    v45 = v11 * v8[9];
    v46 = (float)((float)(v12 * v42) + (float)(v14 * v8[4])) + (float)(v11 * v8[8]);
    v104 = v43;
    v101.m_el[0].mVec128.m128_f32[1] = v44 + v45;
    v101.m_el[0].mVec128.m128_f32[2] = v46;
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v101.m_el[0].m_floats[2],
      (int)&v108,
      &v101.m_el[0].mVec128.m128_f32[1],
      &v104,
      &v103,
      &v105,
      &v107,
      &v102,
      &v106,
      (const float *)&v101,
      v100);
    v47 = normalOnBInWorld->mVec128.m128_f32[2];
    v48 = normalOnBInWorld;
    v101.m_el[0].mVec128.m128_i32[2] = normalOnBInWorld->mVec128.m128_i32[1];
    v49 = (float)((float)((float)((float)((float)(v108 * v101.m_el[0].mVec128.m128_f32[3])
                                        + (float)(v109 * v101.m_el[1].mVec128.m128_f32[0]))
                                + (float)(v110 * v101.m_el[1].mVec128.m128_f32[1]))
                        + v101.m_el[1].mVec128.m128_f32[3])
                - pointInWorld->mVec128.m128_f32[0])
        * normalOnBInWorld->mVec128.m128_f32[0];
    v101.m_el[0].mVec128.m128_i32[1] = normalOnBInWorld->mVec128.m128_i32[0];
    v101.m_el[0].mVec128.m128_f32[0] = (float)(v49
                                             + (float)((float)((float)((float)((float)((float)(v111
                                                                                             * v101.m_el[0].mVec128.m128_f32[3])
                                                                                     + (float)(v112
                                                                                             * v101.m_el[1].mVec128.m128_f32[0]))
                                                                             + (float)(v113
                                                                                     * v101.m_el[1].mVec128.m128_f32[1]))
                                                                     + v101.m_el[2].mVec128.m128_f32[0])
                                                             - pointInWorld->mVec128.m128_f32[1])
                                                     * v101.m_el[0].mVec128.m128_f32[2]))
                                     + (float)((float)((float)((float)((float)((float)(v115
                                                                                     * v101.m_el[1].mVec128.m128_f32[0])
                                                                             + (float)(v116
                                                                                     * v101.m_el[1].mVec128.m128_f32[1]))
                                                                     + (float)(v114 * v101.m_el[0].mVec128.m128_f32[3]))
                                                             + v101.m_el[2].mVec128.m128_f32[1])
                                                     - pointInWorld->mVec128.m128_f32[2])
                                             * v47);
    v101.m_el[1].mVec128.m128_f32[3] = (float)(v101.m_el[0].mVec128.m128_f32[1] * v101.m_el[0].mVec128.m128_f32[0])
                                     + (float)((float)((float)((float)(v108 * v101.m_el[0].mVec128.m128_f32[3])
                                                             + (float)(v109 * v101.m_el[1].mVec128.m128_f32[0]))
                                                     + (float)(v110 * v101.m_el[1].mVec128.m128_f32[1]))
                                             + v101.m_el[1].mVec128.m128_f32[3]);
    v101.m_el[2].mVec128.m128_f32[0] = (float)(v101.m_el[0].mVec128.m128_f32[2] * v101.m_el[0].mVec128.m128_f32[0])
                                     + (float)((float)((float)((float)(v111 * v101.m_el[0].mVec128.m128_f32[3])
                                                             + (float)(v112 * v101.m_el[1].mVec128.m128_f32[0]))
                                                     + (float)(v113 * v101.m_el[1].mVec128.m128_f32[1]))
                                             + v101.m_el[2].mVec128.m128_f32[0]);
    v101.m_el[2].mVec128.m128_f32[1] = (float)(v47 * v101.m_el[0].mVec128.m128_f32[0])
                                     + (float)((float)((float)((float)(v115 * v101.m_el[1].mVec128.m128_f32[0])
                                                             + (float)(v116 * v101.m_el[1].mVec128.m128_f32[1]))
                                                     + (float)(v114 * v101.m_el[0].mVec128.m128_f32[3]))
                                             + v101.m_el[2].mVec128.m128_f32[1]);
    v101.m_el[2].mVec128.m128_i32[2] = 0;
    v50 = &v101.m_el[1].mVec128.m128_i32[3];
  }
  else
  {
    *(float *)&v51 = (float)(normalOnBInWorld->mVec128.m128_f32[1] * orgDepth) + pointInWorld->mVec128.m128_f32[1];
    *(float *)&v52 = (float)(normalOnBInWorld->mVec128.m128_f32[2] * orgDepth) + pointInWorld->mVec128.m128_f32[2];
    v101.m_el[0].mVec128.m128_f32[3] = pointInWorld->mVec128.m128_f32[0]
                                     + (float)(normalOnBInWorld->mVec128.m128_f32[0] * orgDepth);
    v101.m_el[1].mVec128.m128_u64[0] = __PAIR64__(v52, v51);
    v53 = (float *)btTransform::inverse((btTransform *)this, (int)&this->m_transformB, &v121);
    v54 = v53[13];
    v55 = v53[12];
    v56 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v57 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v58 = v53[14];
    v59 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v60 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v58;
    v101.m_el[1].mVec128.m128_f32[3] = (float)((float)((float)(v57 * v55) + (float)(v56 * v54)) + (float)(v59 * v58))
                                     + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[0];
    v61 = (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v54) + v60;
    v62 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v55;
    v63 = v55 * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v64 = (float)(v61 + v62) + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[1];
    v65 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v101.m_el[2].mVec128.m128_f32[0] = v64;
    v66 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v54;
    v67 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v58;
    v68 = v53[2] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v69 = (float)((float)(v66 + v67) + v63) + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[2];
    v70 = v53[6];
    v71 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v70;
    v101.m_el[2].mVec128.m128_f32[1] = v69;
    v72 = v53[10];
    v73 = v71 + (float)(v65 * v72);
    v74 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v75 = v73 + v68;
    v76 = v53[9];
    v101.m_el[0].mVec128.m128_f32[2] = v75;
    v77 = (float)(v74 * v53[5]) + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v76);
    v78 = v53[4];
    v79 = v53[8];
    v101.m_el[0].mVec128.m128_f32[1] = v77
                                     + (float)(v53[1] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
    v80 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v78)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v79))
        + (float)(*v53 * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
    v81 = v53[5];
    v103 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v70)
                 + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v72))
         + (float)(v53[2] * this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0]);
    v82 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v81;
    v83 = v53[9];
    v104 = v80;
    v84 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v83;
    v85 = v53[4];
    v86 = (float)(v82 + v84) + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v53[1]);
    v87 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v105 = v86;
    v88 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v85;
    v89 = *v53;
    v107 = (float)(v88 + (float)(v87 * v53[8]))
         + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * *v53);
    v90 = (float)((float)(v57 * v53[2]) + (float)(v56 * v70)) + (float)(v59 * v72);
    v91 = (float)(v57 * v53[1]) + (float)(v56 * v53[5]);
    v92 = v59 * v53[9];
    v93 = (float)((float)(v57 * v89) + (float)(v56 * v53[4])) + (float)(v59 * v53[8]);
    v102 = v90;
    v106 = v91 + v92;
    v101.m_el[0].mVec128.m128_f32[0] = v93;
    btMatrix3x3::setValue(
      &v101,
      (int)&v108,
      &v106,
      &v102,
      &v107,
      &v105,
      &v103,
      &v104,
      &v101.m_el[0].mVec128.m128_f32[1],
      &v101.m_el[0].mVec128.m128_f32[2],
      v100);
    v94 = pointInWorld->mVec128.m128_f32[1];
    v95 = pointInWorld->mVec128.m128_f32[2];
    v48 = normalOnBInWorld;
    v96 = (float)((float)((float)(v111 * pointInWorld->mVec128.m128_f32[0]) + (float)(v112 * v94)) + (float)(v113 * v95))
        + v101.m_el[2].mVec128.m128_f32[0];
    v97 = (float)(v114 * pointInWorld->mVec128.m128_f32[0]) + (float)(v115 * v94);
    v117[0] = (float)((float)((float)(v108 * pointInWorld->mVec128.m128_f32[0]) + (float)(v109 * v94))
                    + (float)(v110 * v95))
            + v101.m_el[1].mVec128.m128_f32[3];
    v119 = 0;
    v117[1] = v96;
    v118 = (float)(v97 + (float)(v116 * v95)) + v101.m_el[2].mVec128.m128_f32[1];
    v50 = (int *)v117;
    v101.m_el[0].mVec128.m128_f32[0] = (float)((float)(normalOnBInWorld->mVec128.m128_f32[2]
                                                     * (float)(v101.m_el[1].mVec128.m128_f32[1] - v118))
                                             + (float)(normalOnBInWorld->mVec128.m128_f32[1]
                                                     * (float)(v101.m_el[1].mVec128.m128_f32[0] - v96)))
                                     + (float)(normalOnBInWorld->mVec128.m128_f32[0]
                                             * (float)(v101.m_el[0].mVec128.m128_f32[3] - v117[0]));
  }
  m_originalManifoldResult = this->m_originalManifoldResult;
  v120[0] = *v50;
  v99 = v50 + 1;
  v120[1] = *v99++;
  v120[2] = *v99;
  v120[3] = v99[1];
  ((void (__thiscall *)(btManifoldResult *, const btVector3 *, _DWORD *, int))m_originalManifoldResult->addContactPoint)(
    m_originalManifoldResult,
    v48,
    v120,
    v101.m_el[0].mVec128.m128_i32[0]);
}
