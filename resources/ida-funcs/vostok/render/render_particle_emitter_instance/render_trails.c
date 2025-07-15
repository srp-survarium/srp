void __thiscall vostok::render::render_particle_emitter_instance::render_trails(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::float3 *view_location,
        vostok::particle::base_particle *start_particle,
        unsigned int num_particles,
        int a5)
{
  float y; // eax
  char v6; // bl
  unsigned int v7; // edx
  unsigned int v8; // eax
  char *v9; // ebx
  float x; // esi
  char *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ecx
  unsigned int v14; // edi
  float *v15; // edx
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  vostok::render::vertex_buffer *v19; // ecx
  float v20; // xmm1_4
  unsigned int v21; // ebx
  float v22; // xmm3_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // eax
  __m128i y_low; // xmm0
  vostok::math::float3_pod *v32; // ecx
  vostok::math::float3 *v33; // eax
  float *v34; // edi
  float v35; // xmm6_4
  float v36; // xmm4_4
  float v37; // xmm5_4
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm6_4
  float v41; // xmm1_4
  float *v42; // edi
  float *v43; // edi
  float *v44; // eax
  float v45; // xmm7_4
  float v46; // xmm6_4
  float *v47; // edi
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm3_4
  float v51; // xmm7_4
  float v52; // xmm2_4
  float *v53; // edi
  float v54; // xmm2_4
  float *v55; // edi
  float *v56; // edi
  float *v57; // eax
  float v58; // xmm7_4
  float *v59; // ecx
  float *v60; // edi
  float v61; // xmm3_4
  float v62; // xmm2_4
  float *v63; // edi
  float *v64; // edi
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  _DWORD *v69; // eax
  float *v70; // esi
  float v71; // xmm7_4
  float v72; // xmm3_4
  float v73; // xmm4_4
  float z; // xmm5_4
  float *v75; // edi
  float *v76; // edi
  char *v77; // eax
  float *v78; // edi
  float v79; // xmm7_4
  float v80; // xmm6_4
  float v81; // xmm7_4
  float v82; // xmm2_4
  float *v83; // edi
  float v84; // xmm2_4
  float *v85; // edi
  float *v86; // edi
  float v87; // xmm2_4
  int v88; // ecx
  float *v89; // ecx
  float v90; // xmm7_4
  float *v91; // edi
  float v92; // xmm2_4
  float *v93; // edi
  float *v94; // edi
  float v95; // xmm2_4
  float v96; // xmm2_4
  float v97; // xmm5_4
  float v98; // xmm2_4
  float *v99; // edi
  float *v100; // esi
  float *v101; // edi
  float *v102; // edi
  bool v103; // zf
  unsigned int i; // edi
  int v105; // eax
  _WORD *v106; // ebx
  unsigned int v107; // edi
  int v108; // ecx
  _WORD *v109; // ebx
  float v110; // eax
  vostok::render::untyped_buffer *v111; // ecx
  int v112; // edx
  vostok::render::res_geometry *v113; // ecx
  unsigned int v114; // edi
  vostok::render::backend *v115; // ecx
  float v116; // [esp+0h] [ebp-26Ch]
  vostok::math::float3 v117; // [esp+10h] [ebp-25Ch] BYREF
  float v118; // [esp+20h] [ebp-24Ch]
  float v119; // [esp+2Ch] [ebp-240h]
  vostok::math::float3 v120; // [esp+34h] [ebp-238h]
  float v121; // [esp+44h] [ebp-228h]
  float v122[17]; // [esp+4Ch] [ebp-220h] BYREF
  float v123; // [esp+90h] [ebp-1DCh]
  float v124; // [esp+94h] [ebp-1D8h]
  float v125; // [esp+98h] [ebp-1D4h]
  vostok::math::float3_pod v126; // [esp+9Ch] [ebp-1D0h] BYREF
  vostok::math::float3_pod v127; // [esp+A8h] [ebp-1C4h] BYREF
  float v128; // [esp+B4h] [ebp-1B8h]
  float v129; // [esp+B8h] [ebp-1B4h]
  float v130; // [esp+BCh] [ebp-1B0h]
  vostok::math::float3_pod v131; // [esp+C0h] [ebp-1ACh] BYREF
  vostok::math::float3 v132; // [esp+CCh] [ebp-1A0h] BYREF
  vostok::math::float3_pod v133; // [esp+D8h] [ebp-194h] BYREF
  float v134; // [esp+E4h] [ebp-188h]
  float v135; // [esp+E8h] [ebp-184h]
  float v136; // [esp+ECh] [ebp-180h]
  float v137[3]; // [esp+F0h] [ebp-17Ch] BYREF
  vostok::math::float3 v138; // [esp+FCh] [ebp-170h] BYREF
  float v139; // [esp+108h] [ebp-164h]
  float v140; // [esp+10Ch] [ebp-160h]
  float v141; // [esp+110h] [ebp-15Ch]
  vostok::math::float3 v142; // [esp+114h] [ebp-158h] BYREF
  float v143; // [esp+120h] [ebp-14Ch]
  float v144; // [esp+124h] [ebp-148h]
  float v145; // [esp+128h] [ebp-144h]
  vostok::math::float3 v146; // [esp+12Ch] [ebp-140h] BYREF
  float v147; // [esp+138h] [ebp-134h]
  float v148; // [esp+13Ch] [ebp-130h]
  float v149; // [esp+140h] [ebp-12Ch]
  vostok::math::float3 v150; // [esp+144h] [ebp-128h] BYREF
  float v151[3]; // [esp+150h] [ebp-11Ch] BYREF
  vostok::math::float3 v152; // [esp+15Ch] [ebp-110h] BYREF
  vostok::math::float3 v153; // [esp+168h] [ebp-104h] BYREF
  vostok::math::float3 v154; // [esp+174h] [ebp-F8h] BYREF
  vostok::math::float3 v155; // [esp+180h] [ebp-ECh] BYREF
  int v156; // [esp+18Ch] [ebp-E0h]
  int v157; // [esp+190h] [ebp-DCh]
  float v158; // [esp+194h] [ebp-D8h]
  float v159; // [esp+198h] [ebp-D4h]
  float v160; // [esp+19Ch] [ebp-D0h]
  int v161; // [esp+1A0h] [ebp-CCh]
  float v162; // [esp+1A4h] [ebp-C8h]
  float v163; // [esp+1A8h] [ebp-C4h]
  float v164; // [esp+1ACh] [ebp-C0h]
  float v165; // [esp+1B0h] [ebp-BCh]
  float v166; // [esp+1B4h] [ebp-B8h]
  int v167; // [esp+1B8h] [ebp-B4h]
  int v168; // [esp+1BCh] [ebp-B0h]
  float v169; // [esp+1C0h] [ebp-ACh]
  int v170; // [esp+1C4h] [ebp-A8h]
  float v171; // [esp+1C8h] [ebp-A4h]
  char *v172; // [esp+1CCh] [ebp-A0h]
  float v173; // [esp+1D0h] [ebp-9Ch]
  float v174; // [esp+1D4h] [ebp-98h]
  unsigned int v_offset; // [esp+1D8h] [ebp-94h] BYREF
  float v176; // [esp+1DCh] [ebp-90h]
  unsigned int v177; // [esp+1E0h] [ebp-8Ch]
  float v178; // [esp+1E4h] [ebp-88h]
  float *v179; // [esp+1E8h] [ebp-84h]
  unsigned int v180; // [esp+1ECh] [ebp-80h]
  float v181; // [esp+1F0h] [ebp-7Ch]
  float v182; // [esp+1F4h] [ebp-78h]
  float v183; // [esp+1F8h] [ebp-74h]
  float v184; // [esp+1FCh] [ebp-70h]
  unsigned int i_offset; // [esp+200h] [ebp-6Ch] BYREF
  float v186; // [esp+204h] [ebp-68h]
  float v187; // [esp+208h] [ebp-64h]
  float v188; // [esp+20Ch] [ebp-60h]
  vostok::math::float3 v189; // [esp+210h] [ebp-5Ch] BYREF
  unsigned int v_count; // [esp+21Ch] [ebp-50h]
  vostok::math::float3 v191; // [esp+220h] [ebp-4Ch] BYREF
  float v192; // [esp+22Ch] [ebp-40h]
  float v193; // [esp+230h] [ebp-3Ch]
  vostok::math::float3 v194; // [esp+234h] [ebp-38h]
  unsigned int v195; // [esp+240h] [ebp-2Ch]
  float *v196; // [esp+244h] [ebp-28h]
  float v197; // [esp+248h] [ebp-24h]
  char *v198; // [esp+24Ch] [ebp-20h]
  unsigned int v199; // [esp+250h] [ebp-1Ch]
  float v200; // [esp+254h] [ebp-18h]
  unsigned int v201; // [esp+258h] [ebp-14h]
  char v202; // [esp+25Fh] [ebp-Dh]
  float *v203; // [esp+260h] [ebp-Ch]
  float *v204; // [esp+264h] [ebp-8h]
  float *v205; // [esp+268h] [ebp-4h]
  unsigned __int16 v206; // [esp+278h] [ebp+Ch]
  __int16 v207; // [esp+27Ch] [ebp+10h]
  unsigned int v208; // [esp+27Ch] [ebp+10h]
  unsigned __int16 j; // [esp+280h] [ebp+14h]

  y = view_location[29].y;
  if ( y != 0.0 )
  {
    v201 = *(_DWORD *)LODWORD(y);
    if ( v201 <= 1 )
      v201 = 1;
    v180 = *(_DWORD *)(LODWORD(y) + 4);
    if ( v180 <= 1 )
      v180 = 1;
    v6 = *(_BYTE *)(LODWORD(y) + 12);
    i_offset = 0;
    v_offset = 0;
    v7 = a5 - 1;
    v8 = 6 * a5 * v201;
    v202 = v6;
    v195 = a5 - 1;
    v_count = 2 * a5 * v201;
    if ( !v6 )
    {
      v_count = 4 * v201 * (1 - ((1 - v7) & ((1 - (unsigned __int64)v7) >> 32)));
      v8 = 6 * v201 * (1 - ((1 - v7) & ((1 - (unsigned __int64)v7) >> 32)));
    }
    v9 = vostok::render::index_buffer::lock((vostok::render::index_buffer *)LODWORD(view_location[27].x), &i_offset, v8);
    x = view_location[24].x;
    v172 = v9;
    v11 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(x), &v_offset, v_count, 0x30u);
    v12 = v195;
    v13 = num_particles;
    v205 = (float *)v11;
    v192 = 0.0;
    if ( v195 )
    {
      v14 = v195;
      do
      {
        --v14;
        v15 = *(float **)(v13 + 208);
        v16 = v15[7] - *(float *)(v13 + 28);
        v17 = v15[6] - *(float *)(v13 + 24);
        v18 = v15[5] - *(float *)(v13 + 20);
        v192 = (float)((float)((float)(v16 * v16) + (float)(v17 * v17)) + (float)(v18 * v18)) + v192;
        v13 = (unsigned int)v15;
      }
      while ( v14 );
    }
    v19 = (vostok::render::vertex_buffer *)v201;
    v193 = 0.0;
    v176 = 3.1415927 / (double)v201;
    if ( v201 )
    {
      v20 = s_bm_current_air_resistance;
      v177 = v201;
      while ( 1 )
      {
        v21 = num_particles;
        v19 = 0;
        v200 = 0.0;
        v179 = 0;
        v199 = 0;
        if ( !v195 )
          goto LABEL_29;
        v22 = v20 / v192;
        v160 = v20 / v192;
        *(_QWORD *)&v142.x = 0;
        v142.z = v20;
        *(_QWORD *)&v150.x = 0;
        v150.z = v20;
        *(_QWORD *)&v152.x = 0;
        v152.z = v20;
        *(_QWORD *)&v138.x = LODWORD(v20);
        v138.z = 0.0;
        *(_QWORD *)&v132.x = 0;
        v132.z = v20;
        v197 = (float)v180;
        v198 = v11 + 40;
        v203 = (float *)(v11 + 24);
        v204 = (float *)(v11 + 12);
        while ( 1 )
        {
          v23 = *(float **)(v21 + 208);
          v24 = v23[6] - *(float *)(v21 + 24);
          v25 = v23[5] - *(float *)(v21 + 20);
          v26 = v23[7] - *(float *)(v21 + 28);
          v27 = v24 * v24;
          v28 = v25 * v25;
          v196 = v23;
          v126.x = start_particle->color.x - *(float *)(v21 + 20);
          v126.y = start_particle->color.y - *(float *)(v21 + 24);
          v29 = start_particle->color.z - *(float *)(v21 + 28);
          v178 = (float)((float)((float)(v26 * v26) + v27) + v28) * v22;
          v126.z = v29;
          vostok::math::normalize_safe(&v126, &v142, &v155);
          v131.x = v196[5] - *(float *)(v21 + 20);
          v131.y = v196[6] - *(float *)(v21 + 24);
          v131.z = v196[7] - *(float *)(v21 + 28);
          vostok::math::normalize_safe(&v131, &v150, &v189);
          if ( v199 )
          {
            *(_QWORD *)&v146.x = 0;
            v146.z = s_bm_current_air_resistance;
            v127.x = v196[5] - v179[5];
            v127.y = v196[6] - v179[6];
            v127.z = v196[7] - v179[7];
            v189 = *vostok::math::normalize_safe(&v127, &v146, &v117);
          }
          v30 = view_location[30].x;
          v181 = *(float *)v21 * *(float *)LODWORD(v30);
          v182 = *(float *)(LODWORD(v30) + 4) * *(float *)(v21 + 4);
          v183 = *(float *)(LODWORD(v30) + 8) * *(float *)(v21 + 8);
          v184 = *(float *)(LODWORD(v30) + 12) * *(float *)(v21 + 12);
          v163 = v197 * v200;
          y_low = (__m128i)LODWORD(v189.y);
          *(float *)y_low.m128i_i32 = (float)(v189.y * v155.x) - (float)(v155.y * v189.x);
          v133.x = (float)(v189.z * v155.y) - (float)(v189.y * v155.z);
          v133.y = (float)(v155.z * v189.x) - (float)(v189.z * v155.x);
          v133.z = *(float *)y_low.m128i_i32;
          vostok::math::normalize_safe(&v133, &v152, &v191);
          if ( a5 != 2 && v199 == a5 - 2 )
            v189 = v120;
          v116 = v193;
          v33 = vostok::math::float3_pod::normalize_safe(v32, &v189, &v189.x);
          vostok::math::create_rotation(v33, (int)v122, y_low, v116);
          v194.x = (float)((float)((float)(v122[0] * v191.x) + (float)(v122[8] * v191.z)) + (float)(v122[4] * v191.y))
                 + v122[12];
          v194.y = (float)((float)((float)(v122[9] * v191.z) + (float)(v122[5] * v191.y)) + (float)(v122[1] * v191.x))
                 + v122[13];
          v194.z = (float)((float)((float)(v122[10] * v191.z) + (float)(v122[6] * v191.y)) + (float)(v122[2] * v191.x))
                 + v122[14];
          v191 = v194;
          vostok::math::normalize_safe(&v191, &v138, &v153);
          vostok::math::normalize_safe(&v189, &v132, &v154);
          v34 = v205;
          v188 = (float)(v154.y * v153.x) - (float)(v153.y * v154.x);
          v186 = (float)(v154.z * v153.y) - (float)(v154.y * v153.z);
          v187 = (float)(v153.z * v154.x) - (float)(v154.z * v153.x);
          if ( !v202 )
          {
            v71 = *(float *)(v21 + 120);
            v72 = v194.x;
            v73 = v194.y;
            z = v194.z;
            v147 = (float)(v194.x * v71) + *(float *)(v21 + 20);
            v148 = *(float *)(v21 + 24) + (float)(v194.y * v71);
            v149 = *(float *)(v21 + 28) + (float)(v194.z * v71);
            *v205 = v147;
            v75 = v34 + 1;
            *v75 = v148;
            v75[1] = v149;
            v76 = v204;
            v77 = v198;
            *v204 = v186;
            *++v76 = v187;
            v76[1] = v188;
            v78 = v203;
            *v203 = v181;
            *++v78 = v182;
            *++v78 = v183;
            v78[1] = v184;
            v156 = 0;
            *(_DWORD *)v77 = 0;
            v157 = 0;
            *((_DWORD *)v77 + 1) = 0;
            v79 = *(float *)(v21 + 120);
            v118 = v73 * v79;
            v80 = z * v79;
            v81 = *(float *)(v21 + 20) - (float)(v72 * v79);
            v82 = *(float *)(v21 + 24) - v118;
            v205 += 12;
            v83 = v205;
            v204 += 12;
            v203 += 12;
            v144 = v82;
            v84 = *(float *)(v21 + 28);
            v143 = v81;
            v145 = v84 - v80;
            *v205 = v81;
            *++v83 = v144;
            v83[1] = v145;
            v85 = v204;
            v20 = s_bm_current_air_resistance;
            *v204 = v186;
            *++v85 = v187;
            v85[1] = v188;
            v86 = v203;
            *v203 = v181;
            *++v86 = v182;
            ++v86;
            v77 += 48;
            v166 = v20;
            v167 = 0;
            *v86 = v183;
            v87 = v197;
            *(float *)v77 = v166;
            v88 = v167;
            v86[1] = v184;
            *((_DWORD *)v77 + 1) = v88;
            v89 = v196;
            v90 = v196[30];
            v205 += 12;
            v91 = v205;
            v162 = v87;
            v204 += 12;
            v203 += 12;
            v139 = (float)(v72 * v90) + v196[5];
            v92 = v196[6];
            v119 = v73 * v90;
            v140 = v92 + (float)(v73 * v90);
            v141 = v196[7] + (float)(z * v90);
            *v205 = v139;
            *++v91 = v140;
            v91[1] = v141;
            v93 = v204;
            *v204 = v186;
            *++v93 = v187;
            v93[1] = v188;
            v94 = v203;
            v95 = v197;
            *v203 = v181;
            *++v94 = v182;
            ++v94;
            v205 += 12;
            v204 += 12;
            v203 += 12;
            *v94 = v183;
            v94[1] = v184;
            v77 += 48;
            v174 = v95;
            v161 = 0;
            *(_DWORD *)v77 = 0;
            *((float *)v77 + 1) = v162;
            v96 = v89[30];
            v97 = z * v96;
            v137[0] = v89[5] - (float)(v72 * v96);
            v137[1] = v89[6] - (float)(v73 * v96);
            v98 = v89[7];
            v173 = v20;
            v69 = v77 + 48;
            *(float *)v69 = v20;
            v19 = (vostok::render::vertex_buffer *)LODWORD(v174);
            v137[2] = v98 - v97;
            v70 = v137;
            goto LABEL_26;
          }
          v35 = *(float *)(v21 + 120);
          v36 = v194.x;
          v37 = v194.y;
          v38 = v194.z * v35;
          v39 = v194.y * v35;
          v40 = *(float *)(v21 + 20) + (float)(v194.x * v35);
          v135 = *(float *)(v21 + 24) + v39;
          v41 = *(float *)(v21 + 28);
          v134 = v40;
          v136 = v41 + v38;
          *v205 = v40;
          v42 = v34 + 1;
          *v42 = v135;
          v42[1] = v136;
          v43 = v204;
          v44 = (float *)v198;
          v45 = v163;
          v46 = v194.z;
          *v204 = v186;
          *++v43 = v187;
          v43[1] = v188;
          v47 = v203;
          *v203 = v181;
          *++v47 = v182;
          *++v47 = v183;
          v47[1] = v184;
          v168 = 0;
          *v44 = 0.0;
          v169 = v45;
          v44[1] = v45;
          v165 = v45;
          v48 = *(float *)(v21 + 120);
          v49 = v46 * v48;
          v50 = v37 * v48;
          v51 = *(float *)(v21 + 20) - (float)(v36 * v48);
          v52 = *(float *)(v21 + 24);
          v205 += 12;
          v53 = v205;
          v204 += 12;
          v203 += 12;
          v129 = v52 - v50;
          v54 = *(float *)(v21 + 28);
          v128 = v51;
          v130 = v54 - v49;
          *v205 = v51;
          *++v53 = v129;
          v53[1] = v130;
          v55 = v204;
          v20 = s_bm_current_air_resistance;
          *v204 = v186;
          *++v55 = v187;
          v55[1] = v188;
          v56 = v203;
          *v203 = v181;
          *++v56 = v182;
          ++v56;
          v44 += 12;
          v164 = v20;
          *v56 = v183;
          v205 += 12;
          v204 += 12;
          v203 += 12;
          *v44 = v164;
          v44[1] = v165;
          v57 = v44 + 12;
          v56[1] = v184;
          v198 = (char *)v57;
          if ( a5 == 2 || (v19 = (vostok::render::vertex_buffer *)(a5 - 2), v199 == a5 - 2) )
          {
            v58 = *(float *)(v21 + 120);
            v59 = v196;
            v60 = v205;
            v61 = v197 * (float)(v178 + v200);
            v200 = v178 + v200;
            v123 = (float)(v36 * v58) + v196[5];
            v62 = v196[6];
            v121 = v37 * v58;
            v124 = v62 + (float)(v37 * v58);
            v125 = v196[7] + (float)(v194.z * v58);
            *v205 = v123;
            *++v60 = v124;
            v60[1] = v125;
            v63 = v204;
            *v204 = v186;
            *++v63 = v187;
            v63[1] = v188;
            v64 = v203;
            v65 = v194.z;
            *v203 = v181;
            *++v64 = v182;
            ++v64;
            v205 += 12;
            v204 += 12;
            v203 += 12;
            *v64 = v183;
            v64[1] = v184;
            v171 = v61;
            v159 = v61;
            v170 = 0;
            *v57 = 0.0;
            v57[1] = v171;
            v66 = *(float *)(v21 + 120);
            v67 = v65 * v66;
            v151[0] = v59[5] - (float)(v36 * v66);
            v151[1] = v59[6] - (float)(v37 * v66);
            v68 = v59[7];
            v158 = v20;
            v69 = v57 + 12;
            *(float *)v69 = v20;
            v19 = (vostok::render::vertex_buffer *)LODWORD(v159);
            v151[2] = v68 - v67;
            v70 = v151;
LABEL_26:
            v99 = v205;
            *v205 = *v70;
            v100 = v70 + 1;
            *++v99 = *v100;
            v99[1] = v100[1];
            v101 = v204;
            v205 += 12;
            v204 += 12;
            *v101++ = v186;
            *v101 = v187;
            v101[1] = v188;
            v102 = v203;
            v203 += 12;
            *v102++ = v181;
            v69[1] = v19;
            *v102++ = v182;
            *v102 = v183;
            v198 = (char *)(v69 + 12);
            v102[1] = v184;
          }
          ++v199;
          *(_QWORD *)&v120.x = *(_QWORD *)&v189.x;
          v179 = (float *)v21;
          v21 = *(_DWORD *)(v21 + 208);
          v200 = v178 + v200;
          v120.z = v189.z;
          if ( v199 >= v195 )
            break;
          v22 = v160;
        }
        v11 = (char *)v205;
LABEL_29:
        v103 = v177-- == 1;
        v193 = v176 + v193;
        if ( v103 )
        {
          v9 = v172;
          v12 = v195;
          break;
        }
      }
    }
    if ( v202 )
    {
      v206 = 0;
      if ( v201 )
      {
        v207 = 0;
        do
        {
          for ( i = 0; i < v12; ++i )
          {
            v105 = (unsigned __int16)(2 * (i + v207));
            *(_WORD *)v9 = v105;
            v106 = v9 + 2;
            *v106++ = v105 + 1;
            v19 = (vostok::render::vertex_buffer *)(v105 + 3);
            *v106++ = v105 + 3;
            *v106++ = v105;
            *v106++ = v105 + 3;
            *v106 = v105 + 2;
            v9 = (char *)(v106 + 1);
          }
          ++v206;
          v207 += a5;
        }
        while ( v206 < v201 );
      }
    }
    else
    {
      for ( j = 0; j < v201; ++j )
      {
        v107 = 0;
        if ( v12 )
        {
          v208 = v_count / v201;
          do
          {
            v108 = (unsigned __int16)(j * v208 + 4 * v107);
            *(_WORD *)v9 = v108;
            v109 = v9 + 2;
            *v109++ = v108 + 1;
            *v109++ = v108 + 3;
            *v109++ = v108;
            *v109++ = v108 + 3;
            v19 = (vostok::render::vertex_buffer *)(v108 + 2);
            *v109 = (_WORD)v19;
            v9 = (char *)(v109 + 1);
            ++v107;
          }
          while ( v107 < v12 );
        }
      }
    }
    vostok::render::vertex_buffer::unlock(v19, (int *)LODWORD(view_location[24].x));
    v110 = view_location[27].x;
    v111 = *(vostok::render::untyped_buffer **)(LODWORD(v110) + 16);
    v112 = *(_DWORD *)LODWORD(v110);
    *(_DWORD *)(LODWORD(v110) + 8) += v111;
    vostok::render::untyped_buffer::unmap(v111, v112);
    vostok::render::res_geometry::apply(v113, LODWORD(view_location[21].y));
    v114 = 6 * v201 * v12;
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v114,
      v115,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      i_offset,
      v_offset);
    vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_triangles.value += v114 / 3;
  }
}
