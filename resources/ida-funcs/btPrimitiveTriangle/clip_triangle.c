int __userpurge btPrimitiveTriangle::clip_triangle@<eax>(
        btPrimitiveTriangle *this@<ecx>,
        float *a2@<eax>,
        btPrimitiveTriangle *other,
        btVector3 *clipped_points)
{
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  char v17; // dl
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  int v21; // edi
  _QWORD *v22; // edi
  int v23; // edi
  _QWORD *v24; // edi
  float v25; // xmm4_4
  float v26; // xmm6_4
  int v27; // edi
  _QWORD *v28; // edi
  int v29; // edi
  _QWORD *v30; // edi
  int v31; // edx
  float v32; // xmm4_4
  _QWORD *v33; // edi
  _DWORD *v34; // edi
  float v36; // xmm7_4
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm6_4
  float v40; // xmm7_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float *v43; // esi
  float *v44; // ecx
  float v45; // xmm6_4
  bool v46; // dl
  float v47; // xmm4_4
  unsigned __int64 *v48; // edi
  unsigned __int64 *v49; // edi
  bool v50; // zf
  float *v51; // esi
  float v52; // xmm4_4
  int v53; // edi
  char *v54; // edi
  int v55; // edi
  char *v56; // edi
  float v57; // xmm6_4
  float v58; // xmm7_4
  float v59; // xmm2_4
  float v60; // xmm4_4
  float v61; // xmm7_4
  float v62; // xmm2_4
  float v63; // xmm6_4
  btVector3 *v64; // edx
  unsigned __int64 *v65; // ecx
  float v66; // xmm4_4
  float v67; // xmm6_4
  float *v68; // eax
  float v69; // xmm6_4
  btVector3 *v70; // edi
  float v71; // xmm0_4
  btVector3 *v72; // edi
  int v73; // [esp+10h] [ebp-2A0h]
  int v74; // [esp+10h] [ebp-2A0h]
  int v75; // [esp+14h] [ebp-29Ch]
  float v76; // [esp+18h] [ebp-298h]
  float v77; // [esp+18h] [ebp-298h]
  float v78; // [esp+1Ch] [ebp-294h]
  float v79; // [esp+20h] [ebp-290h]
  float v80; // [esp+20h] [ebp-290h]
  float v81; // [esp+20h] [ebp-290h]
  float v82; // [esp+24h] [ebp-28Ch]
  float v83; // [esp+24h] [ebp-28Ch]
  float v84; // [esp+24h] [ebp-28Ch]
  float v85; // [esp+24h] [ebp-28Ch]
  float v86; // [esp+24h] [ebp-28Ch]
  float v87; // [esp+24h] [ebp-28Ch]
  float v88; // [esp+24h] [ebp-28Ch]
  float v89; // [esp+28h] [ebp-288h]
  float v90; // [esp+28h] [ebp-288h]
  float v91; // [esp+28h] [ebp-288h]
  float v92; // [esp+28h] [ebp-288h]
  float v93; // [esp+28h] [ebp-288h]
  float v94; // [esp+30h] [ebp-280h]
  float v95; // [esp+30h] [ebp-280h]
  float v96; // [esp+34h] [ebp-27Ch]
  float v97; // [esp+34h] [ebp-27Ch]
  float v98; // [esp+34h] [ebp-27Ch]
  float v99; // [esp+34h] [ebp-27Ch]
  float v100; // [esp+38h] [ebp-278h]
  float v101; // [esp+38h] [ebp-278h]
  float v102; // [esp+38h] [ebp-278h]
  float v103; // [esp+4Ch] [ebp-264h]
  unsigned __int64 *v104; // [esp+4Ch] [ebp-264h]
  float v105; // [esp+50h] [ebp-260h]
  float v106; // [esp+54h] [ebp-25Ch]
  float v107; // [esp+54h] [ebp-25Ch]
  float v108; // [esp+6Ch] [ebp-244h]
  float v109; // [esp+6Ch] [ebp-244h]
  float v110; // [esp+6Ch] [ebp-244h]
  float v111; // [esp+70h] [ebp-240h]
  float v112; // [esp+70h] [ebp-240h]
  int v113; // [esp+70h] [ebp-240h]
  float v114; // [esp+74h] [ebp-23Ch]
  int v115; // [esp+74h] [ebp-23Ch]
  float v116; // [esp+78h] [ebp-238h]
  float *v117; // [esp+78h] [ebp-238h]
  float v118; // [esp+7Ch] [ebp-234h]
  float v119; // [esp+80h] [ebp-230h]
  float v120; // [esp+84h] [ebp-22Ch]
  float v121; // [esp+88h] [ebp-228h]
  float v122; // [esp+8Ch] [ebp-224h]
  float v123; // [esp+9Ch] [ebp-214h]
  float v124; // [esp+9Ch] [ebp-214h]
  float v125; // [esp+9Ch] [ebp-214h]
  _BYTE v126[4]; // [esp+A0h] [ebp-210h] BYREF
  float v127; // [esp+A4h] [ebp-20Ch]
  unsigned __int64 v128; // [esp+B0h] [ebp-200h] BYREF
  _QWORD v129[31]; // [esp+B8h] [ebp-1F8h] BYREF
  unsigned __int64 v130; // [esp+1B0h] [ebp-100h] BYREF
  unsigned __int64 v131; // [esp+1B8h] [ebp-F8h] BYREF

  v4 = a2[14];
  v5 = a2[12];
  v105 = a2[4] - *a2;
  v106 = a2[5] - a2[1];
  v118 = a2[1];
  v6 = a2[6] - a2[2];
  v114 = a2[2];
  v7 = a2[13];
  v116 = *a2;
  v8 = (float)(v4 * v106) - (float)(v7 * v6);
  v9 = (float)(v5 * v6) - (float)(v4 * v105);
  v10 = (float)(v7 * v105) - (float)(v5 * v106);
  v73 = 0;
  v11 = s_bm_current_air_resistance;
  v12 = s_bm_current_air_resistance / fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v8 * v8));
  v96 = v9 * v12;
  v13 = v8 * v12;
  v14 = v10 * v12;
  v15 = v14;
  v123 = (float)((float)(a2[5] * (float)(v9 * v12)) + (float)(a2[4] * v13)) + (float)(v14 * a2[6]);
  v120 = this->m_vertices[0].mVec128.m128_f32[1];
  v121 = this->m_vertices[0].mVec128.m128_f32[0];
  v16 = (float)((float)((float)(v120 * (float)(v9 * v12)) + (float)(this->m_vertices[0].mVec128.m128_f32[0] * v13))
              + (float)(v14 * this->m_vertices[0].mVec128.m128_f32[2]))
      - v123;
  v17 = 1;
  v111 = this->m_vertices[0].mVec128.m128_f32[2];
  if ( v16 <= 0.00000011920929 )
  {
    v128 = this->m_vertices[0].mVec128.m128_u64[0];
    v129[0] = this->m_vertices[0].mVec128.m128_u64[1];
    v73 = 1;
  }
  v103 = this->m_vertices[1].mVec128.m128_f32[2];
  v18 = this->m_vertices[1].mVec128.m128_f32[0];
  v122 = this->m_vertices[1].mVec128.m128_f32[1];
  v19 = (float)((float)((float)(v122 * v96) + (float)(v18 * v13)) + (float)(v14 * v103)) - v123;
  v108 = v18;
  if ( v19 <= 0.00000011920929 )
    v17 = 0;
  if ( v17 != v16 > 0.00000011920929 )
  {
    LODWORD(v20) = COERCE_UNSIGNED_INT(v16 / (float)(v19 - v16)) ^ _mask__NegFloat_;
    v107 = v122 * v20;
    v127 = v120 * (float)(s_bm_current_air_resistance - v20);
    v79 = (float)(v121 * (float)(s_bm_current_air_resistance - v20)) + (float)(v18 * v20);
    v21 = 2 * v73++;
    v15 = v14;
    v89 = (float)(v111 * (float)(s_bm_current_air_resistance - v20)) + (float)(v103 * v20);
    v19 = (float)((float)((float)(v122 * v96) + (float)(v18 * v13)) + (float)(v14 * v103)) - v123;
    v22 = &v129[v21 - 1];
    v82 = v127 + v107;
    *(float *)v22 = v79;
    v22 = (_QWORD *)((char *)v22 + 4);
    *(float *)v22 = v82;
    v22 = (_QWORD *)((char *)v22 + 4);
    *(float *)v22 = v89;
    *((_DWORD *)v22 + 1) = 0;
  }
  if ( !v17 )
  {
    v23 = 2 * v73++;
    v24 = &v129[v23 - 1];
    *(_DWORD *)v24 = this->m_vertices[1].mVec128.m128_i32[0];
    v24 = (_QWORD *)((char *)v24 + 4);
    *(_DWORD *)v24 = this->m_vertices[1].mVec128.m128_i32[1];
    *(_QWORD *)((char *)v24 + 4) = this->m_vertices[1].mVec128.m128_u64[1];
  }
  v78 = this->m_vertices[2].mVec128.m128_f32[2];
  v119 = this->m_vertices[2].mVec128.m128_f32[1];
  v76 = this->m_vertices[2].mVec128.m128_f32[0];
  v25 = (float)((float)((float)(v76 * v13) + (float)(v15 * v78)) + (float)(v119 * v96)) - v123;
  if ( v25 > 0.00000011920929 != v19 > 0.00000011920929 )
  {
    LODWORD(v26) = COERCE_UNSIGNED_INT(v19 / (float)(v25 - v19)) ^ _mask__NegFloat_;
    v27 = 2 * v73++;
    v28 = &v129[v27 - 1];
    *(float *)v28 = (float)(v108 * (float)(v11 - v26)) + (float)(v76 * v26);
    v28 = (_QWORD *)((char *)v28 + 4);
    *(float *)v28 = (float)(v122 * (float)(v11 - v26)) + (float)(v119 * v26);
    v28 = (_QWORD *)((char *)v28 + 4);
    *(float *)v28 = (float)(v103 * (float)(v11 - v26)) + (float)(v78 * v26);
    *((_DWORD *)v28 + 1) = 0;
  }
  if ( v25 <= 0.00000011920929 )
  {
    v29 = 2 * v73++;
    v30 = &v129[v29 - 1];
    *(_DWORD *)v30 = this->m_vertices[2].mVec128.m128_i32[0];
    v30 = (_QWORD *)((char *)v30 + 4);
    *(_DWORD *)v30 = this->m_vertices[2].mVec128.m128_i32[1];
    *(_QWORD *)((char *)v30 + 4) = this->m_vertices[2].mVec128.m128_u64[1];
  }
  v31 = v73;
  if ( v16 > 0.00000011920929 != v25 > 0.00000011920929 )
  {
    LODWORD(v32) = COERCE_UNSIGNED_INT(v25 / (float)(v16 - v25)) ^ _mask__NegFloat_;
    v33 = &v129[2 * v73 - 1];
    *(float *)v33 = (float)(v76 * (float)(v11 - v32)) + (float)(v121 * v32);
    v33 = (_QWORD *)((char *)v33 + 4);
    *(float *)v33 = (float)(v119 * (float)(v11 - v32)) + (float)(v120 * v32);
    v33 = (_QWORD *)((char *)v33 + 4);
    *(float *)v33 = (float)(v78 * (float)(v11 - v32)) + (float)(v111 * v32);
    v31 = v73 + 1;
    *((_DWORD *)v33 + 1) = 0;
    ++v73;
  }
  if ( v16 <= 0.00000011920929 )
  {
    v34 = &v129[2 * v31 - 1];
    *v34++ = this->m_vertices[0].mVec128.m128_i32[0];
    *v34++ = this->m_vertices[0].mVec128.m128_i32[1];
    *v34 = this->m_vertices[0].mVec128.m128_i32[2];
    ++v31;
    v34[1] = this->m_vertices[0].mVec128.m128_i32[3];
    v73 = v31;
  }
  if ( !v31 )
    return 0;
  v36 = a2[13];
  v37 = a2[10] - a2[6];
  v112 = a2[8];
  v80 = v112 - a2[4];
  v109 = a2[14];
  v83 = a2[9] - a2[5];
  v38 = (float)(v83 * v109) - (float)(v37 * v36);
  v97 = (float)(v37 * a2[12]) - (float)(v109 * v80);
  v39 = (float)(v36 * v80) - (float)(v83 * a2[12]);
  v75 = 0;
  v40 = fsqrt((float)((float)(v39 * v39) + (float)(v97 * v97)) + (float)(v38 * v38));
  v94 = v38 * (float)(v11 / v40);
  v100 = v39 * (float)(v11 / v40);
  v98 = v97 * (float)(v11 / v40);
  v41 = (float)((float)((float)(*(float *)&v128 * v94) + (float)(*(float *)v129 * v100))
              + (float)(*((float *)&v128 + 1) * v98))
      - (float)((float)((float)(v100 * a2[10]) + (float)(v98 * a2[9])) + (float)(v112 * v94));
  v124 = (float)((float)(v100 * a2[10]) + (float)(v98 * a2[9])) + (float)(v112 * v94);
  if ( v41 <= 0.00000011920929 )
  {
    v130 = v128;
    v131 = v129[0];
    v75 = 1;
  }
  v42 = v41;
  if ( v31 > 1 )
  {
    v104 = &v130 + 2 * v75;
    v43 = (float *)v129;
    v113 = v31 - 1;
    do
    {
      v44 = v43 + 2;
      v45 = (float)((float)((float)(v98 * v43[3]) + (float)(v43[2] * v94)) + (float)(v43[4] * v100)) - v124;
      v46 = v45 > 0.00000011920929;
      if ( v45 > 0.00000011920929 != v42 > 0.00000011920929 )
      {
        LODWORD(v47) = COERCE_UNSIGNED_INT(v42 / (float)(v45 - v42)) ^ _mask__NegFloat_;
        ++v75;
        v48 = v104;
        v104 += 2;
        v84 = (float)(*(v43 - 1) * (float)(v11 - v47)) + (float)(v47 * v43[3]);
        v45 = (float)((float)((float)(v98 * v43[3]) + (float)(v43[2] * v94)) + (float)(v43[4] * v100)) - v124;
        v90 = (float)((float)(v11 - v47) * *v43) + (float)(v43[4] * v47);
        *(float *)v48 = (float)(*(v43 - 2) * (float)(v11 - v47)) + (float)(*v44 * v47);
        v48 = (unsigned __int64 *)((char *)v48 + 4);
        *(float *)v48 = v84;
        v48 = (unsigned __int64 *)((char *)v48 + 4);
        *(float *)v48 = v90;
        *((_DWORD *)v48 + 1) = 0;
      }
      if ( !v46 )
      {
        v49 = v104;
        ++v75;
        v104 += 2;
        *(float *)v49 = *v44;
        v49 = (unsigned __int64 *)((char *)v49 + 4);
        *(float *)v49 = v43[3];
        v49 = (unsigned __int64 *)((char *)v49 + 4);
        *(float *)v49 = v43[4];
        *((float *)v49 + 1) = v43[5];
      }
      v50 = v113-- == 1;
      v43 += 4;
      v42 = v45;
    }
    while ( !v50 );
    v31 = v73;
  }
  v51 = (float *)&v126[16 * v31];
  if ( v41 > 0.00000011920929 != v42 > 0.00000011920929 )
  {
    LODWORD(v52) = COERCE_UNSIGNED_INT(v42 / (float)(v41 - v42)) ^ _mask__NegFloat_;
    v53 = 16 * v75++;
    v54 = (char *)&v130 + v53;
    v85 = (float)(v51[1] * (float)(v11 - v52)) + (float)(*((float *)&v128 + 1) * v52);
    v91 = (float)(v51[2] * (float)(v11 - v52)) + (float)(*(float *)v129 * v52);
    *(float *)v54 = (float)((float)(v11 - v52) * *v51) + (float)(v52 * *(float *)&v128);
    v54 += 4;
    *(float *)v54 = v85;
    v54 += 4;
    *(float *)v54 = v91;
    *((_DWORD *)v54 + 1) = 0;
  }
  if ( v41 <= 0.00000011920929 )
  {
    v55 = 16 * v75++;
    v56 = (char *)&v130 + v55;
    *(_DWORD *)v56 = v128;
    v56 += 4;
    *(_DWORD *)v56 = HIDWORD(v128);
    *(_QWORD *)(v56 + 4) = v129[0];
  }
  if ( !v75 )
    return 0;
  v57 = a2[14];
  v58 = v114 - a2[10];
  v81 = v116 - a2[8];
  v77 = a2[13];
  v86 = v118 - a2[9];
  v59 = (float)(v57 * v86) - (float)(v77 * v58);
  v110 = a2[12];
  v60 = (float)(v110 * v58) - (float)(v57 * v81);
  v101 = (float)(v77 * v81) - (float)(v110 * v86);
  v74 = 0;
  v61 = fsqrt((float)((float)(v101 * v101) + (float)(v60 * v60)) + (float)(v59 * v59));
  v95 = v59 * (float)(v11 / v61);
  v102 = v101 * (float)(v11 / v61);
  v99 = v60 * (float)(v11 / v61);
  v62 = (float)((float)((float)(*(float *)&v131 * v102) + (float)(*((float *)&v130 + 1) * v99))
              + (float)(*(float *)&v130 * v95))
      - (float)((float)((float)(v102 * v114) + (float)(v99 * v118)) + (float)(v95 * v116));
  v125 = (float)((float)(v102 * v114) + (float)(v99 * v118)) + (float)(v95 * v116);
  if ( v62 <= 0.00000011920929 )
  {
    other->m_vertices[0].mVec128.m128_u64[0] = v130;
    other->m_vertices[0].mVec128.m128_u64[1] = v131;
    v74 = 1;
  }
  v63 = v62;
  if ( v75 > 1 )
  {
    v64 = &other->m_vertices[v74];
    v65 = &v131;
    v115 = v75 - 1;
    do
    {
      v66 = (float)((float)((float)(*((float *)v65 + 2) * v95) + (float)(v102 * *((float *)v65 + 4)))
                  + (float)(v99 * *((float *)v65 + 3)))
          - v125;
      v117 = (float *)(v65 + 1);
      if ( v66 > 0.00000011920929 != v63 > 0.00000011920929 )
      {
        ++v74;
        LODWORD(v67) = COERCE_UNSIGNED_INT(v63 / (float)(v66 - v63)) ^ _mask__NegFloat_;
        v87 = (float)(*((float *)v65 - 1) * (float)(v11 - v67)) + (float)(v67 * *((float *)v65 + 3));
        v92 = (float)((float)(v11 - v67) * *(float *)v65) + (float)(v67 * *((float *)v65 + 4));
        v64->mVec128.m128_f32[0] = (float)(*((float *)v65 - 2) * (float)(v11 - v67)) + (float)(*v117 * v67);
        v64->mVec128.m128_f32[1] = v87;
        v64->mVec128.m128_f32[2] = v92;
        v64->mVec128.m128_i32[3] = 0;
        ++v64;
      }
      if ( v66 <= 0.00000011920929 )
      {
        ++v74;
        v64->mVec128.m128_f32[0] = *v117;
        v64->mVec128.m128_i32[1] = *((_DWORD *)v65 + 3);
        v64->mVec128.m128_i32[2] = *((_DWORD *)v65 + 4);
        v64->mVec128.m128_i32[3] = *((_DWORD *)v65 + 5);
        ++v64;
      }
      v50 = v115-- == 1;
      v65 += 2;
      v63 = v66;
    }
    while ( !v50 );
  }
  v68 = (float *)&v129[2 * v75 + 29];
  if ( v62 > 0.00000011920929 != v63 > 0.00000011920929 )
  {
    LODWORD(v69) = COERCE_UNSIGNED_INT(v63 / (float)(v62 - v63)) ^ _mask__NegFloat_;
    v70 = &other->m_vertices[v74++];
    v71 = v11 - v69;
    v88 = (float)(v68[1] * v71) + (float)(*((float *)&v130 + 1) * v69);
    v93 = (float)(v68[2] * v71) + (float)(*(float *)&v131 * v69);
    v70->mVec128.m128_f32[0] = (float)(v71 * *v68) + (float)(v69 * *(float *)&v130);
    v70 = (btVector3 *)((char *)v70 + 4);
    v70->mVec128.m128_f32[0] = v88;
    v70 = (btVector3 *)((char *)v70 + 4);
    v70->mVec128.m128_f32[0] = v93;
    v70->mVec128.m128_i32[1] = 0;
  }
  if ( v62 <= 0.00000011920929 )
  {
    v72 = &other->m_vertices[v74++];
    v72->mVec128.m128_i32[0] = v130;
    v72 = (btVector3 *)((char *)v72 + 4);
    v72->mVec128.m128_i32[0] = HIDWORD(v130);
    *(unsigned __int64 *)((char *)v72->mVec128.m128_u64 + 4) = v131;
  }
  return v74;
}
