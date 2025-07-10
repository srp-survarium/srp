void __userpurge btPerturbedContactResult::addContactPoint(
        btPerturbedContactResult *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float orgDepth)
{
  float v8; // xmm2_4
  float v9; // xmm3_4
  int v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  int v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  unsigned int v33; // xmm0_4
  unsigned int v34; // xmm1_4
  float *v35; // eax
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm6_4
  float v57; // xmm7_4
  float v58; // xmm1_4
  float v59; // xmm6_4
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm7_4
  float v65; // xmm2_4
  float v66; // xmm6_4
  float v67; // xmm4_4
  float v68; // xmm7_4
  float v69; // xmm4_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  unsigned int v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  int v76; // [esp+D0h] [ebp-B4h]
  int v77; // [esp+D4h] [ebp-B0h]
  int v78; // [esp+D8h] [ebp-ACh]
  float v79; // [esp+DCh] [ebp-A8h]
  float newDepth; // [esp+E0h] [ebp-A4h]
  float newDeptha; // [esp+E0h] [ebp-A4h]
  float v82; // [esp+E4h] [ebp-A0h]
  float v83; // [esp+E4h] [ebp-A0h]
  float v84; // [esp+E8h] [ebp-9Ch]
  float v85; // [esp+ECh] [ebp-98h]
  float v86; // [esp+F0h] [ebp-94h]
  __m128i v87; // [esp+F4h] [ebp-90h] BYREF
  __m128i v88; // [esp+104h] [ebp-80h] BYREF
  float v89; // [esp+114h] [ebp-70h]
  float v90; // [esp+118h] [ebp-6Ch]
  float v91; // [esp+11Ch] [ebp-68h]
  float v92; // [esp+120h] [ebp-64h]
  int v93; // [esp+124h] [ebp-60h]
  float v94; // [esp+128h] [ebp-5Ch]
  float v95; // [esp+12Ch] [ebp-58h]
  int v96; // [esp+130h] [ebp-54h]
  __m128i v97; // [esp+134h] [ebp-50h] BYREF
  btTransform v98; // [esp+144h] [ebp-40h] BYREF

  if ( this->m_perturbA )
  {
    v8 = normalOnBInWorld->mVec128.m128_f32[2] * orgDepth;
    v9 = pointInWorld->mVec128.m128_f32[0] + (float)(normalOnBInWorld->mVec128.m128_f32[0] * orgDepth);
    *(float *)&v87.m128i_i32[1] = pointInWorld->mVec128.m128_f32[1]
                                + (float)(normalOnBInWorld->mVec128.m128_f32[1] * orgDepth);
    *(float *)&v10 = pointInWorld->mVec128.m128_f32[2] + v8;
    *(float *)v87.m128i_i32 = v9;
    v87.m128i_i32[2] = v10;
    v11 = (float *)btTransform::inverse(&this->m_transformA, &v98);
    v12 = v11[12];
    v13 = v11[13];
    v14 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v15 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v16 = v11[14];
    v17 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v18 = (float)((float)(v15 * v12) + (float)(v14 * v13)) + (float)(v17 * v16);
    *(float *)&v88.m128i_i32[1] = (float)((float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                        * v13)
                                                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                        * v16))
                                        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v12))
                                + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[1];
    v19 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v13;
    v20 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v16;
    v21 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v12;
    v22 = v11[2] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v23 = v19 + v20;
    v24 = v11[10];
    *(float *)&v25 = (float)(v23 + v21) + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[2];
    v26 = v11[6];
    v27 = v18 + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[0];
    v88.m128i_i32[2] = v25;
    v82 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v26)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v24))
        + v22;
    v86 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v11[5])
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v11[9]))
        + (float)(v11[1] * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
    v85 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v11[6])
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v24))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v11[2]);
    v84 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v11[5])
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v11[9]))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v11[1]);
    v79 = (float)(v15 * v11[1]) + (float)(v14 * v11[5]);
    v28 = (float)((float)((float)(*(float *)&v87.m128i_i32[1] * (float)(v79 + (float)(v17 * v11[9])))
                        + (float)(*(float *)&v87.m128i_i32[2]
                                * (float)((float)((float)(v15 * v11[2]) + (float)(v14 * v11[6])) + (float)(v17 * v11[10]))))
                + (float)((float)((float)((float)(v15 * *v11) + (float)(v14 * v11[4])) + (float)(v17 * v11[8]))
                        * *(float *)v87.m128i_i32))
        + v27;
    v29 = normalOnBInWorld->mVec128.m128_f32[2];
    v30 = normalOnBInWorld->mVec128.m128_f32[1];
    v31 = (float)((float)((float)(*(float *)&v87.m128i_i32[1] * v84) + (float)(*(float *)&v87.m128i_i32[2] * v85))
                + (float)((float)((float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                * v11[4])
                                        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                * v11[8]))
                                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * *v11))
                        * *(float *)v87.m128i_i32))
        + *(float *)&v88.m128i_i32[1];
    v95 = (float)((float)((float)(*(float *)&v87.m128i_i32[1] * v86) + (float)(*(float *)&v87.m128i_i32[2] * v82))
                + (float)((float)((float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                * v11[4])
                                        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                * v11[8]))
                                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * *v11))
                        * *(float *)v87.m128i_i32))
        + *(float *)&v25;
    v32 = (float)((float)((float)(v28 - pointInWorld->mVec128.m128_f32[0]) * normalOnBInWorld->mVec128.m128_f32[0])
                + (float)((float)(v31 - pointInWorld->mVec128.m128_f32[1]) * v30))
        + (float)((float)(v95 - pointInWorld->mVec128.m128_f32[2]) * v29);
    *(float *)v87.m128i_i32 = (float)(normalOnBInWorld->mVec128.m128_f32[0] * v32) + v28;
    *(float *)&v87.m128i_i32[1] = (float)(v30 * v32) + v31;
    v87.m128i_i64[1] = COERCE_UNSIGNED_INT((float)(v29 * v32) + v95);
    newDepth = v32;
    v97 = _mm_load_si128(&v87);
  }
  else
  {
    *(float *)&v33 = (float)(normalOnBInWorld->mVec128.m128_f32[1] * orgDepth) + pointInWorld->mVec128.m128_f32[1];
    *(float *)&v34 = (float)(normalOnBInWorld->mVec128.m128_f32[2] * orgDepth) + pointInWorld->mVec128.m128_f32[2];
    *(float *)v87.m128i_i32 = pointInWorld->mVec128.m128_f32[0]
                            + (float)(normalOnBInWorld->mVec128.m128_f32[0] * orgDepth);
    *(__int64 *)((char *)v87.m128i_i64 + 4) = __PAIR64__(v34, v33);
    v35 = (float *)btTransform::inverse(&this->m_transformB, &v98);
    v36 = v35[12];
    v37 = v35[13];
    v38 = v35[14];
    v39 = v35[10];
    v40 = (float)((float)(v36 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v37 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
        + (float)(v38 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
    v41 = v35[5];
    v94 = (float)((float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v37)
                        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v38))
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v36))
        + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[1];
    v42 = v40 + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[0];
    v43 = v35[4];
    v44 = (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v37)
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v38);
    v45 = v35[2];
    v46 = (float)(v44 + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v36))
        + this->m_unPerturbedTransform.m_origin.mVec128.m128_f32[2];
    v47 = v35[6];
    v48 = v35[1];
    v95 = v46;
    v49 = this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v47;
    v79 = v47;
    v50 = v35[9];
    v92 = (float)(v49 + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v39))
        + (float)(v45 * this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
    v86 = v41;
    v85 = v50;
    v51 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v41)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v50))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v48);
    v52 = v35[8];
    v83 = v39;
    v90 = v51;
    newDeptha = v52;
    v53 = *v35;
    v84 = v43;
    v54 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v43)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v52))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * *v35);
    v55 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v79)
                + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v39))
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v45);
    v56 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v85;
    v57 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v89 = v55;
    v58 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v86) + v56)
        + (float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v48);
    v59 = this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * newDeptha;
    v91 = v58;
    v60 = (float)((float)(this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v84) + v59)
        + (float)(v53 * this->m_unPerturbedTransform.m_basis.m_el[1].mVec128.m128_f32[0]);
    v61 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v82 = (float)((float)(v45 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v79 * v57))
        + (float)(v83 * v61);
    v62 = this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v63 = (float)((float)(v48 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v86 * v62))
        + (float)(v85 * v61);
    v64 = v84 * v62;
    v65 = newDeptha * v61;
    v66 = pointInWorld->mVec128.m128_f32[2];
    v67 = (float)(v53 * this->m_unPerturbedTransform.m_basis.m_el[0].mVec128.m128_f32[0]) + v64;
    v68 = pointInWorld->mVec128.m128_f32[1];
    v69 = (float)((float)((float)(v67 + v65) * pointInWorld->mVec128.m128_f32[0]) + (float)(v68 * v63))
        + (float)(v66 * v82);
    v70 = pointInWorld->mVec128.m128_f32[0];
    v71 = v60 * pointInWorld->mVec128.m128_f32[0];
    *(float *)v88.m128i_i32 = v69 + v42;
    *(float *)&v88.m128i_i32[1] = (float)((float)(v71 + (float)(v68 * v91)) + (float)(v66 * v89)) + v94;
    *(float *)&v72 = (float)((float)((float)(v54 * v70) + (float)(v68 * v90)) + (float)(v66 * v92)) + v95;
    v88.m128i_i64[1] = v72;
    v73 = normalOnBInWorld->mVec128.m128_f32[2] * (float)(*(float *)&v87.m128i_i32[2] - *(float *)&v72);
    v74 = normalOnBInWorld->mVec128.m128_f32[1];
    v97 = _mm_load_si128(&v88);
    newDepth = (float)(v73 + (float)(v74 * (float)(*(float *)&v87.m128i_i32[1] - *(float *)&v88.m128i_i32[1])))
             + (float)(normalOnBInWorld->mVec128.m128_f32[0] * (float)(*(float *)v87.m128i_i32 - (float)(v69 + v42)));
  }
  ((void (__stdcall *)(const btVector3 *, __m128i *, _DWORD, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, int))this->m_originalManifoldResult->addContactPoint)(
    normalOnBInWorld,
    &v97,
    LODWORD(newDepth),
    a3,
    a4,
    a2,
    v76,
    v77,
    v78,
    LODWORD(v79),
    LODWORD(newDepth),
    LODWORD(v82),
    LODWORD(v84),
    LODWORD(v85),
    LODWORD(v86),
    v87.m128i_i32[0],
    v87.m128i_i32[1],
    v87.m128i_i32[2],
    v87.m128i_i32[3],
    v88.m128i_i32[0],
    v88.m128i_i32[1],
    v88.m128i_i32[2],
    v88.m128i_i32[3],
    LODWORD(v89),
    LODWORD(v90),
    LODWORD(v91),
    LODWORD(v92),
    v93,
    LODWORD(v94),
    LODWORD(v95),
    v96);
}
