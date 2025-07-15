void __userpurge btConvexPlaneCollisionAlgorithm::collideSingleContact(
        btConvexPlaneCollisionAlgorithm *this@<ecx>,
        int a2@<ebx>,
        const float *a3@<edi>,
        int a4@<esi>,
        const btQuaternion *perturbeRot,
        const btQuaternion *body0,
        btCollisionObject *body1,
        btCollisionObject *dispatchInfo,
        btManifoldResult *resultOut)
{
  char v9; // cl
  btCollisionObject *v10; // eax
  int m_collisionShape; // edx
  bool v12; // zf
  btCollisionObject *v13; // ecx
  btTransform *p_m_worldTransform; // eax
  float *v15; // ebx
  float *v16; // esi
  float *v17; // eax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm4_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  btTransform *v36; // ecx
  btTransform *v37; // eax
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm0_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm6_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm7_4
  float v50; // xmm6_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  unsigned int v53; // xmm6_4
  float v54; // xmm7_4
  float v55; // xmm6_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  int v59; // eax
  float v60; // xmm7_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm5_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  float v66; // xmm5_4
  float v67; // xmm3_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  btPersistentManifold *v70; // eax
  float v71; // xmm4_4
  float v72; // xmm3_4
  float v73; // xmm4_4
  float v74; // xmm0_4
  float v75; // xmm3_4
  float v76; // xmm4_4
  float v77; // xmm4_4
  float m_contactBreakingThreshold; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm4_4
  btManifoldResult_vtbl *v82; // eax
  float v83; // xmm3_4
  float v84; // xmm4_4
  float v85; // xmm7_4
  float v86; // xmm3_4
  float v87; // xmm2_4
  const float *v88; // [esp+Ch] [ebp-180h]
  const float *v89; // [esp+Ch] [ebp-180h]
  int v90; // [esp+Ch] [ebp-180h]
  float v93; // [esp+24h] [ebp-168h] BYREF
  btMatrix3x3 v94; // [esp+28h] [ebp-164h] BYREF
  int v95; // [esp+58h] [ebp-134h]
  float v96; // [esp+5Ch] [ebp-130h]
  float v97; // [esp+60h] [ebp-12Ch]
  float v98; // [esp+64h] [ebp-128h]
  int v99; // [esp+68h] [ebp-124h]
  float v100; // [esp+6Ch] [ebp-120h]
  float v101; // [esp+70h] [ebp-11Ch]
  float v102; // [esp+74h] [ebp-118h]
  int v103; // [esp+78h] [ebp-114h]
  float v104; // [esp+7Ch] [ebp-110h]
  float v105; // [esp+80h] [ebp-10Ch]
  float v106; // [esp+84h] [ebp-108h]
  int v107; // [esp+88h] [ebp-104h]
  float v108; // [esp+8Ch] [ebp-100h]
  float v109; // [esp+90h] [ebp-FCh]
  float v110; // [esp+94h] [ebp-F8h]
  float v111; // [esp+98h] [ebp-F4h] BYREF
  float v112; // [esp+9Ch] [ebp-F0h] BYREF
  float v113; // [esp+A0h] [ebp-ECh]
  float v114; // [esp+A4h] [ebp-E8h]
  float v115; // [esp+A8h] [ebp-E4h]
  unsigned __int64 v116; // [esp+ACh] [ebp-E0h] BYREF
  float v117; // [esp+B4h] [ebp-D8h] BYREF
  float v118; // [esp+B8h] [ebp-D4h] BYREF
  btTransform v119; // [esp+BCh] [ebp-D0h] BYREF
  int v120[3]; // [esp+FCh] [ebp-90h] BYREF
  float v121; // [esp+108h] [ebp-84h]
  float v122; // [esp+10Ch] [ebp-80h] BYREF
  float v123; // [esp+110h] [ebp-7Ch]
  float v124; // [esp+118h] [ebp-74h]
  float v125; // [esp+11Ch] [ebp-70h]
  float v126; // [esp+120h] [ebp-6Ch]
  float v127; // [esp+128h] [ebp-64h]
  float v128; // [esp+12Ch] [ebp-60h]
  float v129; // [esp+130h] [ebp-5Ch]
  float v130; // [esp+138h] [ebp-54h]
  float v131; // [esp+13Ch] [ebp-50h]
  float v132; // [esp+140h] [ebp-4Ch]
  float v133; // [esp+148h] [ebp-44h] BYREF
  btTransform v134; // [esp+14Ch] [ebp-40h] BYREF

  v9 = LOBYTE(perturbeRot[1].m_floats[0]);
  v10 = dispatchInfo;
  if ( !v9 )
    v10 = body1;
  m_collisionShape = (int)v10->m_collisionShape;
  v12 = v9 == 0;
  v13 = body1;
  if ( v12 )
    v13 = dispatchInfo;
  p_m_worldTransform = &v10->m_worldTransform;
  *(unsigned __int64 *)((char *)v94.m_el[2].mVec128.m128_u64 + 4) = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0];
  v94.m_el[2].mVec128.m128_i32[3] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[2];
  v95 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[3];
  v96 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
  v97 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
  v98 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
  v99 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[3];
  v100 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
  v101 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
  v102 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
  v15 = (float *)v13->m_collisionShape;
  v103 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[3];
  v104 = p_m_worldTransform->m_origin.mVec128.m128_f32[0];
  v105 = p_m_worldTransform->m_origin.mVec128.m128_f32[1];
  v106 = p_m_worldTransform->m_origin.mVec128.m128_f32[2];
  v107 = p_m_worldTransform->m_origin.mVec128.m128_i32[3];
  v16 = (float *)&v13->m_worldTransform;
  v94.m_el[2].mVec128.m128_i32[0] = m_collisionShape;
  v17 = (float *)btTransform::inverse((btTransform *)v13, (int)&v13->m_worldTransform, &v119);
  v18 = v17[1];
  v19 = *v17;
  v20 = v17[2];
  v21 = v17[5] * v105;
  v108 = (float)((float)((float)(*v17 * v104) + (float)(v18 * v105)) + (float)(v106 * v20)) + v17[12];
  v22 = (float)((float)((float)(v17[6] * v106) + v21) + (float)(v17[4] * v104)) + v17[13];
  v23 = v17[9] * v105;
  v109 = v22;
  v24 = (float)((float)((float)(v17[10] * v106) + v23) + (float)(v17[8] * v104)) + v17[14];
  v25 = v17[10] * v102;
  v110 = v24;
  v26 = (float)((float)(v17[9] * v98) + v25) + (float)(v17[8] * v94.m_el[2].mVec128.m128_f32[3]);
  v27 = v17[10] * v101;
  v94.m_el[0].mVec128.m128_f32[0] = v26;
  v28 = (float)((float)(v17[9] * v97) + v27) + (float)(v94.m_el[2].mVec128.m128_f32[2] * v17[8]);
  v29 = v17[10] * v100;
  v94.m_el[0].mVec128.m128_f32[3] = v28;
  v30 = (float)((float)(v17[9] * v96) + v29) + (float)(v94.m_el[2].mVec128.m128_f32[1] * v17[8]);
  v31 = v17[6] * v102;
  v93 = v30;
  v32 = (float)((float)(v17[5] * v98) + v31) + (float)(v94.m_el[2].mVec128.m128_f32[3] * v17[4]);
  v33 = v17[6] * v101;
  v94.m_el[1].mVec128.m128_f32[0] = v32;
  v34 = (float)((float)(v17[5] * v97) + v33) + (float)(v94.m_el[2].mVec128.m128_f32[2] * v17[4]);
  v35 = v17[6] * v100;
  v94.m_el[0].mVec128.m128_f32[1] = v34;
  v94.m_el[1].mVec128.m128_f32[2] = (float)((float)(v17[5] * v96) + v35)
                                  + (float)(v17[4] * v94.m_el[2].mVec128.m128_f32[1]);
  v94.m_el[1].mVec128.m128_f32[1] = (float)((float)(v94.m_el[2].mVec128.m128_f32[3] * v19) + (float)(v98 * v18))
                                  + (float)(v102 * v20);
  v94.m_el[1].mVec128.m128_f32[3] = (float)((float)(v94.m_el[2].mVec128.m128_f32[2] * v19) + (float)(v97 * v18))
                                  + (float)(v101 * v20);
  v94.m_el[0].mVec128.m128_f32[2] = (float)((float)(v19 * v94.m_el[2].mVec128.m128_f32[1]) + (float)(v96 * v18))
                                  + (float)(v100 * v20);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v94.m_el[0].m_floats[2],
    (int)&v122,
    &v94.m_el[1].mVec128.m128_f32[3],
    &v94.m_el[1].mVec128.m128_f32[1],
    &v94.m_el[1].mVec128.m128_f32[2],
    &v94.m_el[0].mVec128.m128_f32[1],
    v94.m_el[1].mVec128.m128_f32,
    &v93,
    &v94.m_el[0].mVec128.m128_f32[3],
    (const float *)&v94,
    a3);
  btMatrix3x3::setRotation(body0, &v119.m_basis);
  v94.m_el[0].mVec128.m128_f32[2] = (float)((float)(v119.m_basis.m_el[0].mVec128.m128_f32[2] * v100)
                                          + (float)(v119.m_basis.m_el[1].mVec128.m128_f32[2] * v101))
                                  + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[2] * v102);
  v94.m_el[1].mVec128.m128_f32[3] = (float)((float)(v119.m_basis.m_el[0].mVec128.m128_f32[1] * v100)
                                          + (float)(v119.m_basis.m_el[1].mVec128.m128_f32[1] * v101))
                                  + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[1] * v102);
  v94.m_el[1].mVec128.m128_f32[1] = (float)((float)(v101 * v119.m_basis.m_el[1].mVec128.m128_f32[0])
                                          + (float)(v102 * v119.m_basis.m_el[2].mVec128.m128_f32[0]))
                                  + (float)(v100 * v119.m_basis.m_el[0].mVec128.m128_f32[0]);
  v94.m_el[1].mVec128.m128_f32[2] = (float)((float)(v119.m_basis.m_el[0].mVec128.m128_f32[2] * v96)
                                          + (float)(v119.m_basis.m_el[1].mVec128.m128_f32[2] * v97))
                                  + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[2] * v98);
  v94.m_el[0].mVec128.m128_f32[0] = (float)((float)(v119.m_basis.m_el[0].mVec128.m128_f32[1] * v96)
                                          + (float)(v119.m_basis.m_el[1].mVec128.m128_f32[1] * v97))
                                  + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[1] * v98);
  v94.m_el[0].mVec128.m128_f32[3] = (float)((float)(v97 * v119.m_basis.m_el[1].mVec128.m128_f32[0])
                                          + (float)(v98 * v119.m_basis.m_el[2].mVec128.m128_f32[0]))
                                  + (float)(v96 * v119.m_basis.m_el[0].mVec128.m128_f32[0]);
  v93 = (float)((float)(v119.m_basis.m_el[1].mVec128.m128_f32[2] * v94.m_el[2].mVec128.m128_f32[2])
              + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[2] * v94.m_el[2].mVec128.m128_f32[3]))
      + (float)(v119.m_basis.m_el[0].mVec128.m128_f32[2] * v94.m_el[2].mVec128.m128_f32[1]);
  v94.m_el[1].mVec128.m128_f32[0] = (float)((float)(v119.m_basis.m_el[1].mVec128.m128_f32[1]
                                                  * v94.m_el[2].mVec128.m128_f32[2])
                                          + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[1]
                                                  * v94.m_el[2].mVec128.m128_f32[3]))
                                  + (float)(v119.m_basis.m_el[0].mVec128.m128_f32[1] * v94.m_el[2].mVec128.m128_f32[1]);
  v94.m_el[0].mVec128.m128_f32[1] = (float)((float)(v119.m_basis.m_el[1].mVec128.m128_f32[0]
                                                  * v94.m_el[2].mVec128.m128_f32[2])
                                          + (float)(v119.m_basis.m_el[2].mVec128.m128_f32[0]
                                                  * v94.m_el[2].mVec128.m128_f32[3]))
                                  + (float)(v119.m_basis.m_el[0].mVec128.m128_f32[0] * v94.m_el[2].mVec128.m128_f32[1]);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v94.m_el[0].m_floats[1],
    (int)&v94.m_el[2].mVec128.m128_i32[1],
    v94.m_el[1].mVec128.m128_f32,
    &v93,
    &v94.m_el[0].mVec128.m128_f32[3],
    (float *)&v94,
    &v94.m_el[1].mVec128.m128_f32[2],
    &v94.m_el[1].mVec128.m128_f32[1],
    &v94.m_el[1].mVec128.m128_f32[3],
    &v94.m_el[0].mVec128.m128_f32[2],
    v88);
  v37 = btTransform::inverse(v36, (int)&v94.m_el[2].mVec128.m128_i32[1], &v134);
  v38 = v16[10];
  v39 = v16[6];
  v40 = v16[2];
  v41 = v37->m_basis.m_el[2].mVec128.m128_f32[1];
  v42 = v41 * v16[5];
  v43 = (float)(v41 * v39) + (float)(v37->m_basis.m_el[2].mVec128.m128_f32[2] * v38);
  v94.m_el[1].mVec128.m128_f32[0] = v16[5];
  v44 = v43 + (float)(v40 * v37->m_basis.m_el[2].mVec128.m128_f32[0]);
  v45 = v42 + (float)(v37->m_basis.m_el[2].mVec128.m128_f32[2] * v16[9]);
  v46 = v16[8];
  v93 = v16[9];
  v94.m_el[1].mVec128.m128_f32[3] = v44;
  v47 = v16[1];
  v48 = *v16;
  v94.m_el[1].mVec128.m128_f32[1] = v45 + (float)(v47 * v37->m_basis.m_el[2].mVec128.m128_f32[0]);
  v49 = v41 * v16[4];
  v94.m_el[0].mVec128.m128_f32[0] = v16[4];
  v50 = v37->m_basis.m_el[2].mVec128.m128_f32[2] * v46;
  v94.m_el[0].mVec128.m128_f32[2] = v46;
  v94.m_el[1].mVec128.m128_f32[2] = (float)(v49 + v50) + (float)(v48 * v37->m_basis.m_el[2].mVec128.m128_f32[0]);
  v51 = v37->m_basis.m_el[1].mVec128.m128_f32[2];
  v118 = (float)((float)(v37->m_basis.m_el[1].mVec128.m128_f32[1] * v39) + (float)(v51 * v38))
       + (float)(v40 * v37->m_basis.m_el[1].mVec128.m128_f32[0]);
  v52 = v37->m_basis.m_el[1].mVec128.m128_f32[1] * v94.m_el[0].mVec128.m128_f32[0];
  *((float *)&v116 + 1) = (float)((float)(v37->m_basis.m_el[1].mVec128.m128_f32[1] * v94.m_el[1].mVec128.m128_f32[0])
                                + (float)(v51 * v93))
                        + (float)(v47 * v37->m_basis.m_el[1].mVec128.m128_f32[0]);
  *(float *)&v53 = (float)(v52 + (float)(v51 * v46)) + (float)(v48 * v37->m_basis.m_el[1].mVec128.m128_f32[0]);
  v94.m_el[0].mVec128.m128_i32[1] = v37->m_basis.m_el[0].mVec128.m128_i32[1];
  v54 = v37->m_basis.m_el[0].mVec128.m128_f32[0];
  v94.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v37->m_basis.m_el[0].mVec128.m128_i32[0], v53);
  v55 = v37->m_basis.m_el[0].mVec128.m128_f32[2];
  v117 = (float)((float)(v40 * v54) + (float)(v39 * v94.m_el[0].mVec128.m128_f32[1])) + (float)(v38 * v55);
  v93 = (float)((float)(v47 * v54) + (float)(v94.m_el[1].mVec128.m128_f32[0] * v94.m_el[0].mVec128.m128_f32[1]))
      + (float)(v93 * v55);
  v94.m_el[0].mVec128.m128_f32[0] = (float)((float)(v48 * v54)
                                          + (float)(v94.m_el[0].mVec128.m128_f32[0] * v94.m_el[0].mVec128.m128_f32[1]))
                                  + (float)(v46 * v55);
  btMatrix3x3::setValue(
    &v94,
    (int)&v119,
    &v93,
    &v117,
    &v94.m_el[0].mVec128.m128_f32[2],
    (float *)&v116 + 1,
    &v118,
    &v94.m_el[1].mVec128.m128_f32[2],
    &v94.m_el[1].mVec128.m128_f32[1],
    &v94.m_el[1].mVec128.m128_f32[3],
    v89);
  LODWORD(v56) = *((_DWORD *)v15 + 12) ^ _mask__NegFloat_;
  LODWORD(v57) = *((_DWORD *)v15 + 13) ^ _mask__NegFloat_;
  LODWORD(v58) = *((_DWORD *)v15 + 14) ^ _mask__NegFloat_;
  v59 = *(_DWORD *)v94.m_el[2].mVec128.m128_i32[0];
  v112 = (float)((float)(v56 * v119.m_basis.m_el[0].mVec128.m128_f32[0])
               + (float)(v57 * v119.m_basis.m_el[0].mVec128.m128_f32[1]))
       + (float)(v58 * v119.m_basis.m_el[0].mVec128.m128_f32[2]);
  v114 = (float)((float)(v56 * v119.m_basis.m_el[2].mVec128.m128_f32[0])
               + (float)(v57 * v119.m_basis.m_el[2].mVec128.m128_f32[1]))
       + (float)(v58 * v119.m_basis.m_el[2].mVec128.m128_f32[2]);
  v113 = (float)((float)(v56 * v119.m_basis.m_el[1].mVec128.m128_f32[0])
               + (float)(v57 * v119.m_basis.m_el[1].mVec128.m128_f32[1]))
       + (float)(v58 * v119.m_basis.m_el[1].mVec128.m128_f32[2]);
  v115 = 0.0;
  (*(void (__thiscall **)(int, int *, float *, int, int, int))(v59 + 56))(
    v94.m_el[2].mVec128.m128_i32[0],
    v120,
    &v112,
    v90,
    a4,
    a2);
  v60 = v15[12];
  v61 = (float)((float)((float)(v123 * v126) + (float)(v121 * v124)) + (float)(v122 * v125)) + v111;
  v62 = (float)((float)((float)(v123 * v129) + (float)(v122 * v128)) + (float)(v121 * v127)) + v112;
  v63 = (float)((float)((float)(v123 * v132) + (float)(v122 * v131)) + (float)(v121 * v130)) + v113;
  v64 = (float)((float)((float)(v60 * v61) + (float)(v15[13] * v62)) + (float)(v15[14] * v63)) - v15[16];
  v65 = v15[13] * v64;
  v66 = v63 - (float)(v15[14] * v64);
  v67 = v16[2];
  v94.m_el[2].mVec128.m128_f32[3] = v64;
  v68 = v61 - (float)(v60 * v64);
  v69 = v62 - v65;
  v70 = (btPersistentManifold *)LODWORD(perturbeRot->m_floats[3]);
  v71 = v16[5];
  v115 = (float)((float)((float)(v67 * v66) + (float)(v16[1] * v69)) + (float)(v68 * *v16)) + v16[12];
  v72 = (float)(v16[6] * v66) + (float)(v71 * v69);
  v73 = v68 * v16[4];
  v74 = v68 * v16[8];
  v75 = (float)(v72 + v73) + v16[13];
  v76 = v16[9];
  *(float *)&v116 = v75;
  v77 = v76 * v69;
  m_contactBreakingThreshold = v70->m_contactBreakingThreshold;
  *((float *)&v116 + 1) = (float)((float)((float)(v16[10] * v66) + v77) + v74) + v16[14];
  v117 = 0.0;
  resultOut->m_manifoldPtr = v70;
  if ( m_contactBreakingThreshold > v64 )
  {
    v79 = v15[13];
    v80 = v15[14];
    v81 = v16[6];
    v111 = (float)((float)(v16[1] * v79) + (float)(v16[2] * v80)) + (float)(v60 * *v16);
    v82 = resultOut->__vftable;
    v83 = (float)(v16[5] * v79) + (float)(v81 * v80);
    v84 = v60 * v16[4];
    v85 = v60 * v16[8];
    v112 = v83 + v84;
    v86 = v16[9] * v79;
    v87 = v16[10];
    v133 = v115;
    v134.m_basis.m_el[0].mVec128.m128_u64[0] = v116;
    v113 = (float)(v86 + (float)(v87 * v80)) + v85;
    v114 = 0.0;
    v134.m_basis.m_el[0].mVec128.m128_f32[2] = v117;
    ((void (__stdcall *)(float *, float *, int))v82->addContactPoint)(&v111, &v133, v94.m_el[2].mVec128.m128_i32[3]);
  }
}
