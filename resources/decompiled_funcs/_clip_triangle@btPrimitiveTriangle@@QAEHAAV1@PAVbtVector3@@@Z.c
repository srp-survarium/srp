int __userpurge btPrimitiveTriangle::clip_triangle@<eax>(
        btPrimitiveTriangle *other@<eax>,
        btPrimitiveTriangle *this,
        btVector3 *clipped_points)
{
  float v3; // xmm0_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  long double v12; // st7
  float v13; // xmm6_4
  float v14; // xmm7_4
  int v15; // edi
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  __m128i *v22; // eax
  unsigned int v23; // xmm5_4
  __m128i *v24; // eax
  float v25; // xmm5_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  __m128i *v29; // eax
  __m128i *v30; // eax
  bool v31; // cl
  float v32; // xmm1_4
  float v33; // xmm0_4
  __m128i *v34; // eax
  __m128i *v35; // eax
  float v37; // xmm6_4
  float v38; // xmm2_4
  float v39; // xmm7_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  int v43; // ebx
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm1_4
  unsigned __int64 *v49; // esi
  unsigned int v50; // ebx
  int v51; // edi
  int v52; // ebx
  float *v53; // eax
  float v54; // xmm6_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  unsigned int v61; // xmm1_4
  float v62; // xmm4_4
  float v63; // xmm0_4
  unsigned int v64; // xmm1_4
  float v65; // xmm3_4
  float v66; // xmm0_4
  float v67; // xmm6_4
  float v68; // xmm1_4
  unsigned __int64 *v69; // esi
  float *v70; // eax
  int v71; // edi
  float v72; // xmm4_4
  float v73; // xmm3_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float *v76; // eax
  float v77; // xmm3_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  unsigned __int64 *v80; // eax
  unsigned int v81; // xmm3_4
  float v82; // xmm4_4
  float v83; // xmm5_4
  float v84; // xmm3_4
  float v85; // xmm2_4
  int v86; // edi
  float v87; // xmm6_4
  float v88; // xmm0_4
  float v89; // xmm0_4
  const vostok::math::float4x4 *v90; // xmm7_4
  float v91; // xmm1_4
  btVector3 *v92; // esi
  float *v93; // ecx
  float v94; // xmm3_4
  float v95; // xmm4_4
  float v96; // xmm2_4
  float v97; // xmm0_4
  unsigned int v98; // xmm1_4
  float v99; // xmm3_4
  float v100; // xmm4_4
  float v101; // xmm1_4
  bool v102; // cc
  float v103; // xmm2_4
  char v104; // dl
  float v105; // xmm0_4
  float v106; // xmm4_4
  float v107; // xmm3_4
  float v108; // xmm0_4
  unsigned int v109; // xmm1_4
  float v110; // xmm4_4
  float v111; // xmm0_4
  unsigned int v112; // xmm1_4
  bool v113; // zf
  btVector3 *v114; // esi
  float *v115; // ecx
  int v116; // ebx
  float v117; // xmm3_4
  float v118; // xmm0_4
  unsigned int v119; // xmm1_4
  float *v120; // eax
  bool v121; // cl
  float v122; // xmm2_4
  float v123; // xmm5_4
  float v124; // xmm1_4
  float v125; // xmm0_4
  float v126; // xmm7_4
  btVector3 *v127; // eax
  btVector3 *v128; // eax
  __int64 v129; // [esp+538h] [ebp-280h]
  unsigned __int64 v130; // [esp+538h] [ebp-280h]
  unsigned __int64 v131; // [esp+538h] [ebp-280h]
  unsigned __int64 v132; // [esp+538h] [ebp-280h]
  unsigned __int64 v133; // [esp+538h] [ebp-280h]
  unsigned __int64 v134; // [esp+538h] [ebp-280h]
  unsigned __int64 v135; // [esp+538h] [ebp-280h]
  unsigned __int64 v136; // [esp+538h] [ebp-280h]
  unsigned __int64 v137; // [esp+538h] [ebp-280h]
  unsigned __int64 v138; // [esp+538h] [ebp-280h]
  float v139; // [esp+550h] [ebp-268h]
  float v140; // [esp+550h] [ebp-268h]
  int v141; // [esp+550h] [ebp-268h]
  int v142; // [esp+554h] [ebp-264h]
  float v143; // [esp+554h] [ebp-264h]
  float v144; // [esp+558h] [ebp-260h]
  float v145; // [esp+558h] [ebp-260h]
  __int64 v146; // [esp+558h] [ebp-260h]
  __int64 v147; // [esp+558h] [ebp-260h]
  float v148; // [esp+55Ch] [ebp-25Ch]
  float v149; // [esp+55Ch] [ebp-25Ch]
  float v150; // [esp+560h] [ebp-258h]
  float v151; // [esp+560h] [ebp-258h]
  __int64 v152; // [esp+560h] [ebp-258h]
  __int64 v153; // [esp+560h] [ebp-258h]
  float v154; // [esp+560h] [ebp-258h]
  float v155; // [esp+560h] [ebp-258h]
  float v156; // [esp+560h] [ebp-258h]
  float v157; // [esp+568h] [ebp-250h]
  float v158; // [esp+568h] [ebp-250h]
  float v159; // [esp+568h] [ebp-250h]
  float v160; // [esp+568h] [ebp-250h]
  float v161; // [esp+56Ch] [ebp-24Ch]
  float v162; // [esp+56Ch] [ebp-24Ch]
  float v163; // [esp+56Ch] [ebp-24Ch]
  float v164; // [esp+56Ch] [ebp-24Ch]
  float v165; // [esp+570h] [ebp-248h]
  float v166; // [esp+570h] [ebp-248h]
  float v167; // [esp+570h] [ebp-248h]
  float v168; // [esp+570h] [ebp-248h]
  float v169; // [esp+57Ch] [ebp-23Ch]
  int v170; // [esp+57Ch] [ebp-23Ch]
  int v171; // [esp+57Ch] [ebp-23Ch]
  float v172; // [esp+580h] [ebp-238h]
  float v173; // [esp+580h] [ebp-238h]
  float v174; // [esp+580h] [ebp-238h]
  float v175; // [esp+580h] [ebp-238h]
  float v176; // [esp+580h] [ebp-238h]
  float v177; // [esp+584h] [ebp-234h]
  float v178; // [esp+584h] [ebp-234h]
  float v179; // [esp+584h] [ebp-234h]
  unsigned __int64 v180; // [esp+588h] [ebp-230h]
  unsigned __int64 v181; // [esp+588h] [ebp-230h]
  unsigned __int64 v182; // [esp+590h] [ebp-228h]
  float v183; // [esp+594h] [ebp-224h]
  float v184; // [esp+594h] [ebp-224h]
  float v185; // [esp+5A0h] [ebp-218h]
  float v186; // [esp+5A0h] [ebp-218h]
  float v187; // [esp+5A4h] [ebp-214h]
  unsigned int v188; // [esp+5A4h] [ebp-214h]
  float v189; // [esp+5A8h] [ebp-210h] BYREF
  float v190; // [esp+5ACh] [ebp-20Ch]
  float v191; // [esp+5B0h] [ebp-208h] BYREF
  float v192; // [esp+5B4h] [ebp-204h]
  __m128i v193; // [esp+5B8h] [ebp-200h] BYREF
  _BYTE v194[236]; // [esp+5CCh] [ebp-1ECh] BYREF
  btVector3 v195; // [esp+6B8h] [ebp-100h] BYREF
  char v196; // [esp+6CCh] [ebp-ECh] BYREF

  v3 = this->m_vertices[0].mVec128.m128_f32[0];
  v4 = this->m_vertices[1].mVec128.m128_f32[1];
  v5 = this->m_vertices[1].mVec128.m128_f32[2];
  v6 = this->m_plane.mVec128.m128_f32[2];
  v7 = this->m_plane.mVec128.m128_f32[1];
  v8 = this->m_plane.mVec128.m128_f32[0];
  v191 = this->m_vertices[1].mVec128.m128_f32[0];
  v192 = v3;
  v190 = this->m_vertices[0].mVec128.m128_f32[1];
  v139 = v4;
  v9 = v4 - v190;
  v187 = this->m_vertices[0].mVec128.m128_f32[2];
  v169 = v5;
  v10 = v5 - v187;
  v148 = (float)(v8 * v10) - (float)(v6 * (float)(v191 - v3));
  v144 = (float)(v6 * v9) - (float)(v7 * v10);
  v150 = (float)(v7 * (float)(v191 - v3)) - (float)(v8 * v9);
  v12 = sqrtf((float)((float)(v148 * v148) + (float)(v150 * v150)) + (float)(v144 * v144));
  v13 = other->m_vertices[0].mVec128.m128_f32[2];
  v14 = other->m_vertices[0].mVec128.m128_f32[1];
  v15 = 0;
  v142 = 0;
  v177 = 1.0 / v12;
  v16 = (float)((float)(v191 * (float)(v144 * v177)) + (float)(v169 * (float)(v150 * v177)))
      + (float)(v139 * (float)(v148 * v177));
  v145 = v144 * v177;
  v149 = v148 * v177;
  v151 = v150 * v177;
  v183 = v16;
  v191 = other->m_vertices[0].mVec128.m128_f32[0];
  v17 = (float)((float)((float)(v191 * v145) + (float)(v13 * v151)) + (float)(v14 * v149)) - v16;
  if ( v17 <= 0.00000011920929 )
  {
    v193 = (__m128i)other->m_vertices[0];
    v15 = 1;
    v142 = 1;
  }
  v18 = other->m_vertices[1].mVec128.m128_f32[2];
  v19 = other->m_vertices[1].mVec128.m128_f32[0];
  v140 = other->m_vertices[1].mVec128.m128_f32[1];
  v20 = (float)((float)((float)(v19 * v145) + (float)(v18 * v151)) + (float)(v140 * v149)) - v16;
  v172 = v18;
  v189 = v19;
  if ( v20 > 0.00000011920929 != v17 > 0.00000011920929 )
  {
    v21 = (float)(-1.0 / (float)(v20 - v17)) * v17;
    *(float *)&v129 = (float)(v191 * (float)(*(float *)&clear_value - v21)) + (float)(v19 * v21);
    v22 = &v193 + v15;
    *(float *)&v23 = (float)(v13 * (float)(*(float *)&clear_value - v21)) + (float)(v18 * v21);
    *((float *)&v129 + 1) = (float)(v14 * (float)(*(float *)&clear_value - v21)) + (float)(v140 * v21);
    v22->m128i_i64[0] = v129;
    ++v15;
    v22->m128i_i64[1] = v23;
    v142 = v15;
  }
  if ( v20 <= 0.00000011920929 )
  {
    v24 = &v193 + v15;
    v24->m128i_i64[0] = other->m_vertices[1].mVec128.m128_i64[0];
    ++v15;
    v24->m128i_i64[1] = other->m_vertices[1].mVec128.m128_i64[1];
    v142 = v15;
  }
  v25 = other->m_vertices[2].mVec128.m128_f32[2];
  v26 = other->m_vertices[2].mVec128.m128_f32[1];
  v178 = other->m_vertices[2].mVec128.m128_f32[0];
  v27 = (float)((float)((float)(v178 * v145) + (float)(v25 * v151)) + (float)(v26 * v149)) - v183;
  if ( v27 > 0.00000011920929 != v20 > 0.00000011920929 )
  {
    v28 = (float)(-1.0 / (float)(v27 - v20)) * v20;
    *(float *)&v146 = (float)(v189 * (float)(*(float *)&clear_value - v28)) + (float)(v178 * v28);
    *((float *)&v146 + 1) = (float)(v140 * (float)(*(float *)&clear_value - v28))
                          + (float)(other->m_vertices[2].mVec128.m128_f32[1] * v28);
    HIDWORD(v152) = 0;
    v29 = &v193 + v15;
    *(float *)&v152 = (float)(v172 * (float)(*(float *)&clear_value - v28)) + (float)(v25 * v28);
    v26 = other->m_vertices[2].mVec128.m128_f32[1];
    v29->m128i_i64[0] = v146;
    ++v15;
    v29->m128i_i64[1] = v152;
    v142 = v15;
  }
  if ( v27 <= 0.00000011920929 )
  {
    v30 = &v193 + v15;
    v30->m128i_i64[0] = other->m_vertices[2].mVec128.m128_i64[0];
    ++v15;
    v30->m128i_i64[1] = other->m_vertices[2].mVec128.m128_i64[1];
    v142 = v15;
  }
  v31 = v17 > 0.00000011920929;
  if ( v17 > 0.00000011920929 != v27 > 0.00000011920929 )
  {
    v32 = (float)(-1.0 / (float)(v17 - v27)) * v27;
    v33 = *(float *)&clear_value - v32;
    HIDWORD(v153) = 0;
    v34 = &v193 + v15;
    *(float *)&v147 = (float)(v178 * (float)(*(float *)&clear_value - v32)) + (float)(v191 * v32);
    *((float *)&v147 + 1) = (float)(v26 * (float)(*(float *)&clear_value - v32)) + (float)(v14 * v32);
    v34->m128i_i64[0] = v147;
    *(float *)&v153 = (float)(v25 * v33) + (float)(v13 * v32);
    ++v15;
    v34->m128i_i64[1] = v153;
    v142 = v15;
  }
  if ( !v31 )
  {
    v35 = &v193 + v15;
    v35->m128i_i64[0] = other->m_vertices[0].mVec128.m128_u64[0];
    ++v15;
    v35->m128i_i64[1] = other->m_vertices[0].mVec128.m128_i64[1];
    v142 = v15;
  }
  if ( !v15 )
    return 0;
  v37 = this->m_plane.mVec128.m128_f32[2];
  v38 = this->m_plane.mVec128.m128_f32[1];
  v39 = this->m_plane.mVec128.m128_f32[0];
  v179 = this->m_vertices[2].mVec128.m128_f32[0];
  v40 = v179 - this->m_vertices[1].mVec128.m128_f32[0];
  v185 = this->m_vertices[2].mVec128.m128_f32[1];
  v41 = v185 - this->m_vertices[1].mVec128.m128_f32[1];
  v189 = this->m_vertices[2].mVec128.m128_f32[2];
  v42 = v189 - this->m_vertices[1].mVec128.m128_f32[2];
  v165 = (float)(v38 * v40) - (float)(v39 * v41);
  v161 = (float)(v39 * v42) - (float)(v37 * v40);
  v157 = (float)(v37 * v41) - (float)(v38 * v42);
  v43 = 0;
  v141 = 0;
  v173 = 1.0 / sqrtf((float)((float)(v165 * v165) + (float)(v161 * v161)) + (float)(v157 * v157));
  v44 = v157 * v173;
  v45 = v161 * v173;
  v46 = v165 * v173;
  v47 = (float)((float)((float)(*(float *)v193.m128i_i32 * v44) + (float)(*(float *)&v193.m128i_i32[2] * v46))
              + (float)(*(float *)&v193.m128i_i32[1] * v45))
      - (float)((float)((float)(v189 * v46) + (float)(v185 * v45)) + (float)(v179 * v44));
  v158 = v157 * v173;
  v162 = v161 * v173;
  v166 = v165 * v173;
  v184 = (float)((float)(v189 * v46) + (float)(v185 * v45)) + (float)(v179 * v44);
  v174 = v47;
  if ( v47 <= 0.00000011920929 )
  {
    v43 = 1;
    v195.mVec128 = (__m128)_mm_load_si128(&v193);
    v141 = 1;
  }
  v48 = (float)((float)((float)(*(float *)v193.m128i_i32 * v44) + (float)(*(float *)&v193.m128i_i32[2] * v46))
              + (float)(*(float *)&v193.m128i_i32[1] * v45))
      - (float)((float)((float)(v189 * v46) + (float)(v185 * v45)) + (float)(v179 * v44));
  v170 = 1;
  if ( v15 > 1 )
  {
    if ( v15 - 1 >= 4 )
    {
      v49 = &v195.mVec128.m128_u64[2 * v43];
      v50 = v15 - 5;
      v51 = v141;
      v52 = (v50 >> 2) + 1;
      v53 = (float *)v194;
      v170 = 4 * v52 + 1;
      do
      {
        v54 = *v53;
        v55 = (float)((float)((float)(v166 * v53[1]) + (float)(v158 * *(v53 - 1))) + (float)(*v53 * v162)) - v184;
        if ( v55 > 0.00000011920929 != v48 > 0.00000011920929 )
        {
          v56 = *(v53 - 3);
          v57 = (float)(-1.0 / (float)(v55 - v48)) * v48;
          v58 = *(float *)&clear_value - v57;
          v154 = v53[1] * v57;
          *(float *)&v130 = (float)(*(v53 - 5) * (float)(*(float *)&clear_value - v57)) + (float)(v57 * *(v53 - 1));
          *((float *)&v130 + 1) = (float)(*(v53 - 4) * (float)(*(float *)&clear_value - v57)) + (float)(v57 * *v53);
          *v49 = v130;
          v49[1] = COERCE_UNSIGNED_INT((float)(v56 * v58) + v154);
          ++v51;
          v49 += 2;
        }
        if ( v55 <= 0.00000011920929 )
        {
          *v49 = *(_QWORD *)(v53 - 1);
          v49[1] = *(_QWORD *)(v53 + 1);
          ++v51;
          v49 += 2;
        }
        v59 = (float)((float)((float)(v166 * v53[5]) + (float)(v162 * v53[4])) + (float)(v158 * v53[3])) - v184;
        if ( v59 > 0.00000011920929 != v55 > 0.00000011920929 )
        {
          v60 = (float)(-1.0 / (float)(v59 - v55)) * v55;
          *(float *)&v61 = (float)((float)(*(float *)&clear_value - v60) * v53[1]) + (float)(v60 * v53[5]);
          *(float *)&v131 = (float)((float)(*(float *)&clear_value - v60) * *(v53 - 1)) + (float)(v60 * v53[3]);
          *((float *)&v131 + 1) = (float)(v54 * (float)(*(float *)&clear_value - v60)) + (float)(v53[4] * v60);
          *v49 = v131;
          v49[1] = v61;
          ++v51;
          v49 += 2;
        }
        if ( v59 <= 0.00000011920929 )
        {
          *v49 = *(_QWORD *)(v53 + 3);
          v49[1] = *(_QWORD *)(v53 + 5);
          ++v51;
          v49 += 2;
        }
        v62 = (float)((float)((float)(v166 * v53[9]) + (float)(v162 * v53[8])) + (float)(v158 * v53[7])) - v184;
        if ( v62 > 0.00000011920929 != v59 > 0.00000011920929 )
        {
          v63 = (float)(-1.0 / (float)(v62 - v59)) * v59;
          *(float *)&v64 = (float)((float)(*(float *)&clear_value - v63) * v53[5]) + (float)(v63 * v53[9]);
          *(float *)&v132 = (float)((float)(*(float *)&clear_value - v63) * v53[3]) + (float)(v53[7] * v63);
          *((float *)&v132 + 1) = (float)((float)(*(float *)&clear_value - v63) * v53[4]) + (float)(v53[8] * v63);
          *v49 = v132;
          v49[1] = v64;
          ++v51;
          v49 += 2;
        }
        if ( v62 <= 0.00000011920929 )
        {
          *v49 = *(_QWORD *)(v53 + 7);
          v49[1] = *(_QWORD *)(v53 + 9);
          ++v51;
          v49 += 2;
        }
        v65 = (float)((float)((float)(v53[13] * v166) + (float)(v162 * v53[12])) + (float)(v53[11] * v158)) - v184;
        if ( v65 > 0.00000011920929 != v62 > 0.00000011920929 )
        {
          v66 = (float)(-1.0 / (float)(v65 - v62)) * v62;
          v67 = v53[13] * v66;
          *(float *)&v133 = (float)((float)(*(float *)&clear_value - v66) * v53[7]) + (float)(v53[11] * v66);
          v68 = (float)(*(float *)&clear_value - v66) * v53[9];
          v47 = v174;
          *((float *)&v133 + 1) = (float)((float)(*(float *)&clear_value - v66) * v53[8]) + (float)(v66 * v53[12]);
          *v49 = v133;
          v49[1] = COERCE_UNSIGNED_INT(v68 + v67);
          ++v51;
          v49 += 2;
        }
        if ( v65 <= 0.00000011920929 )
        {
          *v49 = *(_QWORD *)(v53 + 11);
          v49[1] = *(_QWORD *)(v53 + 13);
          ++v51;
          v49 += 2;
        }
        v53 += 16;
        --v52;
        v48 = v65;
      }
      while ( v52 );
      v141 = v51;
      v43 = v51;
      v15 = v142;
    }
    if ( v170 < v15 )
    {
      v69 = &v195.mVec128.m128_u64[2 * v43];
      v70 = &v191 + 4 * v170;
      v71 = v142 - v170;
      do
      {
        v72 = (float)((float)((float)(v70[3] * v162) + (float)(v158 * v70[2])) + (float)(v166 * v70[4])) - v184;
        if ( v72 > 0.00000011920929 != v48 > 0.00000011920929 )
        {
          v73 = *v70;
          v74 = (float)(-1.0 / (float)(v72 - v48)) * v48;
          v75 = *(float *)&clear_value - v74;
          v155 = v70[4] * v74;
          *(float *)&v134 = (float)(*(v70 - 2) * (float)(*(float *)&clear_value - v74)) + (float)(v74 * v70[2]);
          *((float *)&v134 + 1) = (float)(*(v70 - 1) * (float)(*(float *)&clear_value - v74)) + (float)(v70[3] * v74);
          *v69 = v134;
          v69[1] = COERCE_UNSIGNED_INT((float)(v73 * v75) + v155);
          ++v43;
          v69 += 2;
        }
        if ( v72 <= 0.00000011920929 )
        {
          *v69 = *((_QWORD *)v70 + 1);
          v69[1] = *((_QWORD *)v70 + 2);
          ++v43;
          v69 += 2;
        }
        v70 += 4;
        --v71;
        v48 = v72;
      }
      while ( v71 );
      v15 = v142;
      v141 = v43;
    }
  }
  v76 = &v189 + 4 * v15;
  if ( v47 > 0.00000011920929 != v48 > 0.00000011920929 )
  {
    v77 = v76[2];
    v78 = (float)(-1.0 / (float)(v47 - v48)) * v48;
    v79 = v76[1];
    *(float *)&v180 = (float)((float)(*(float *)&clear_value - v78) * *v76) + (float)(v78 * *(float *)v193.m128i_i32);
    v80 = &v195.mVec128.m128_u64[2 * v43];
    *((float *)&v180 + 1) = (float)(v79 * (float)(*(float *)&clear_value - v78))
                          + (float)(*(float *)&v193.m128i_i32[1] * v78);
    *(float *)&v81 = (float)(v77 * (float)(*(float *)&clear_value - v78)) + (float)(*(float *)&v193.m128i_i32[2] * v78);
    *v80 = v180;
    ++v43;
    v80[1] = v81;
    v141 = v43;
  }
  if ( v47 <= 0.00000011920929 )
  {
    *((__m128i *)&v195 + v43++) = v193;
    v141 = v43;
  }
  if ( !v43 )
    return 0;
  v82 = v190 - this->m_vertices[2].mVec128.m128_f32[1];
  v83 = v187 - this->m_vertices[2].mVec128.m128_f32[2];
  v84 = v192 - this->m_vertices[2].mVec128.m128_f32[0];
  v85 = this->m_plane.mVec128.m128_f32[0];
  v167 = (float)(this->m_plane.mVec128.m128_f32[1] * v84) - (float)(v85 * v82);
  v159 = (float)(this->m_plane.mVec128.m128_f32[2] * v82) - (float)(this->m_plane.mVec128.m128_f32[1] * v83);
  v163 = (float)(v85 * v83) - (float)(this->m_plane.mVec128.m128_f32[2] * v84);
  v86 = 0;
  v175 = 1.0 / sqrtf((float)((float)(v167 * v167) + (float)(v163 * v163)) + (float)(v159 * v159));
  v87 = (float)((float)((float)(v159 * v175) * v192) + (float)((float)(v167 * v175) * v187))
      + (float)((float)(v163 * v175) * v190);
  v88 = v195.mVec128.m128_f32[2] * (float)(v167 * v175);
  v168 = v167 * v175;
  v89 = (float)((float)(v88 + (float)(v195.mVec128.m128_f32[1] * (float)(v163 * v175)))
              + (float)(v195.mVec128.m128_f32[0] * (float)(v159 * v175)))
      - v87;
  v160 = v159 * v175;
  v164 = v163 * v175;
  v143 = v89;
  if ( v89 <= 0.00000011920929 )
  {
    *clipped_points = (btVector3)v195.mVec128;
    v86 = 1;
  }
  v90 = clear_value;
  v91 = v89;
  v171 = 1;
  if ( v43 > 1 )
  {
    if ( v43 - 1 >= 4 )
    {
      v92 = &clipped_points[v86];
      v188 = ((unsigned int)(v43 - 5) >> 2) + 1;
      v93 = (float *)&v196;
      v171 = 4 * v188 + 1;
      do
      {
        v94 = *v93;
        v95 = *(v93 - 1);
        v189 = v93[1];
        v176 = v94;
        v96 = (float)((float)((float)(v160 * v95) + (float)(v189 * v168)) + (float)(v94 * v164)) - v87;
        if ( v96 > 0.00000011920929 != v91 > 0.00000011920929 )
        {
          v97 = (float)(-1.0 / (float)(v96 - v91)) * v91;
          *(float *)&v98 = (float)((float)(*(float *)&v90 - v97) * *(v93 - 3)) + (float)(v97 * v93[1]);
          *(float *)&v135 = (float)(*(v93 - 5) * (float)(*(float *)&v90 - v97)) + (float)(v97 * *(v93 - 1));
          *((float *)&v135 + 1) = (float)(*(v93 - 4) * (float)(*(float *)&v90 - v97)) + (float)(*v93 * v97);
          v92->mVec128.m128_u64[0] = v135;
          v92->mVec128.m128_u64[1] = v98;
          ++v86;
          ++v92;
        }
        if ( v96 <= 0.00000011920929 )
        {
          v92->mVec128.m128_u64[0] = *(_QWORD *)(v93 - 1);
          v92->mVec128.m128_u64[1] = *(_QWORD *)(v93 + 1);
          ++v86;
          ++v92;
        }
        v99 = v93[5];
        v100 = v93[3];
        v101 = v96;
        v102 = v96 <= 0.00000011920929;
        v190 = v93[4];
        v186 = v99;
        v103 = (float)((float)((float)(v160 * v100) + (float)(v99 * v168)) + (float)(v190 * v164)) - v87;
        v104 = !v102;
        if ( v103 > 0.00000011920929 != v104 )
        {
          v105 = (float)(-1.0 / (float)(v103 - v101)) * v101;
          v156 = v93[5] * v105;
          *(float *)&v136 = (float)((float)(*(float *)&v90 - v105) * *(v93 - 1)) + (float)(v93[3] * v105);
          *((float *)&v136 + 1) = (float)(v176 * (float)(*(float *)&v90 - v105)) + (float)(v93[4] * v105);
          v106 = v189 * (float)(*(float *)&v90 - v105);
          v92->mVec128.m128_u64[0] = v136;
          v92->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v106 + v156);
          ++v86;
          ++v92;
        }
        if ( v103 <= 0.00000011920929 )
        {
          v92->mVec128.m128_u64[0] = *(_QWORD *)(v93 + 3);
          v92->mVec128.m128_u64[1] = *(_QWORD *)(v93 + 5);
          ++v86;
          ++v92;
        }
        v107 = (float)((float)((float)(v168 * v93[9]) + (float)(v164 * v93[8])) + (float)(v160 * v93[7])) - v87;
        if ( v107 > 0.00000011920929 != v103 > 0.00000011920929 )
        {
          v108 = (float)(-1.0 / (float)(v107 - v103)) * v103;
          *(float *)&v137 = (float)((float)(*(float *)&v90 - v108) * v93[3]) + (float)(v93[7] * v108);
          *((float *)&v137 + 1) = (float)(v190 * (float)(*(float *)&v90 - v108)) + (float)(v93[8] * v108);
          *(float *)&v109 = (float)(v186 * (float)(*(float *)&v90 - v108)) + (float)(v93[9] * v108);
          v92->mVec128.m128_u64[0] = v137;
          v92->mVec128.m128_u64[1] = v109;
          ++v86;
          ++v92;
        }
        if ( v107 <= 0.00000011920929 )
        {
          v92->mVec128.m128_u64[0] = *(_QWORD *)(v93 + 7);
          v92->mVec128.m128_u64[1] = *(_QWORD *)(v93 + 9);
          ++v86;
          ++v92;
        }
        v110 = (float)((float)((float)(v168 * v93[13]) + (float)(v160 * v93[11])) + (float)(v164 * v93[12])) - v87;
        if ( v110 > 0.00000011920929 != v107 > 0.00000011920929 )
        {
          v111 = (float)(-1.0 / (float)(v110 - v107)) * v107;
          *(float *)&v112 = (float)((float)(*(float *)&v90 - v111) * v93[9]) + (float)(v111 * v93[13]);
          v92->mVec128.m128_u64[0] = __PAIR64__(
                                       (float)((float)(*(float *)&v90 - v111) * v93[8]) + (float)(v111 * v93[12]),
                                       (float)((float)(*(float *)&v90 - v111) * v93[7]) + (float)(v111 * v93[11]));
          v92->mVec128.m128_u64[1] = v112;
          ++v86;
          ++v92;
        }
        if ( v110 <= 0.00000011920929 )
        {
          v92->mVec128.m128_u64[0] = *(_QWORD *)(v93 + 11);
          v92->mVec128.m128_u64[1] = *(_QWORD *)(v93 + 13);
          ++v86;
          ++v92;
        }
        v93 += 16;
        v113 = v188-- == 1;
        v91 = v110;
      }
      while ( !v113 );
      v89 = v143;
    }
    if ( v171 < v43 )
    {
      v114 = &clipped_points[v86];
      v115 = (float *)&v194[16 * v171 + 228];
      v116 = v141 - v171;
      do
      {
        v117 = (float)((float)((float)(v164 * v115[3]) + (float)(v115[2] * v160)) + (float)(v115[4] * v168)) - v87;
        if ( v117 > 0.00000011920929 != v91 > 0.00000011920929 )
        {
          v118 = (float)(-1.0 / (float)(v117 - v91)) * v91;
          *(float *)&v119 = (float)((float)(*(float *)&v90 - v118) * *v115) + (float)(v115[4] * v118);
          *(float *)&v138 = (float)(*(v115 - 2) * (float)(*(float *)&v90 - v118)) + (float)(v115[2] * v118);
          *((float *)&v138 + 1) = (float)(*(v115 - 1) * (float)(*(float *)&v90 - v118)) + (float)(v118 * v115[3]);
          v114->mVec128.m128_u64[0] = v138;
          v114->mVec128.m128_u64[1] = v119;
          v89 = v143;
          ++v86;
          ++v114;
        }
        if ( v117 <= 0.00000011920929 )
        {
          v114->mVec128.m128_u64[0] = *((_QWORD *)v115 + 1);
          v114->mVec128.m128_u64[1] = *((_QWORD *)v115 + 2);
          ++v86;
          ++v114;
        }
        v115 += 4;
        --v116;
        v91 = v117;
      }
      while ( v116 );
      v43 = v141;
    }
  }
  v120 = (float *)&v194[16 * v43 + 220];
  v121 = v89 > 0.00000011920929;
  if ( v89 > 0.00000011920929 != v91 > 0.00000011920929 )
  {
    v122 = v120[2];
    v123 = (float)(-1.0 / (float)(v89 - v91)) * v91;
    v124 = v120[1];
    v125 = v195.mVec128.m128_f32[2] * v123;
    v126 = *(float *)&v90 - v123;
    *(float *)&v181 = (float)(*v120 * v126) + (float)(v123 * v195.mVec128.m128_f32[0]);
    v127 = &clipped_points[v86];
    HIDWORD(v182) = 0;
    *((float *)&v181 + 1) = (float)(v124 * v126) + (float)(v195.mVec128.m128_f32[1] * v123);
    v127->mVec128.m128_u64[0] = v181;
    *(float *)&v182 = (float)(v122 * v126) + v125;
    v127->mVec128.m128_u64[1] = v182;
    ++v86;
  }
  if ( !v121 )
  {
    v128 = &clipped_points[v86++];
    *v128 = (btVector3)v195.mVec128;
  }
  return v86;
}
