void __usercall dradfg(
        int ido@<esi>,
        float *ch@<eax>,
        unsigned int a3@<ebx>,
        unsigned int a4@<edi>,
        int ip,
        int l1,
        int idl1,
        float *cc,
        float *c1,
        float *c2,
        float *ch2,
        float *wa)
{
  __m128 v12; // xmm0
  __m128i v14; // xmm0
  int v15; // ebx
  float v16; // xmm6_4
  float *v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  float *v21; // edx
  float *v22; // eax
  float *v23; // edx
  float *v24; // ecx
  unsigned int v25; // eax
  float v26; // xmm0_4
  bool v27; // zf
  float *v28; // edx
  unsigned int v29; // eax
  float *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float *v33; // edx
  float *v34; // eax
  unsigned int v35; // ecx
  float *v36; // ebx
  int v37; // eax
  float *v38; // ecx
  float *v39; // eax
  int v40; // eax
  float *v41; // ecx
  float *v42; // ecx
  float *v43; // ecx
  float *v44; // edx
  unsigned int v45; // eax
  float *v46; // eax
  int v47; // edx
  int v48; // eax
  float *v49; // ecx
  float *v50; // edx
  float *v51; // eax
  int v52; // ecx
  __int128 v53; // xmm5
  float v54; // xmm2_4
  float *v55; // eax
  int v56; // ecx
  __int128 v57; // xmm0
  float v58; // xmm1_4
  float *v59; // edx
  float v60; // xmm1_4
  float *v61; // edx
  __int128 v62; // xmm4
  float v63; // xmm3_4
  int v64; // ecx
  __int128 v65; // xmm1
  float v66; // xmm7_4
  float *v67; // edx
  float v68; // xmm7_4
  float *v69; // edx
  int v70; // edx
  float v71; // xmm0_4
  int v72; // eax
  float *v73; // eax
  double v74; // st7
  double v75; // st7
  int v76; // eax
  int v77; // edx
  float *v78; // ecx
  int v79; // ebx
  int v80; // eax
  unsigned int v81; // ecx
  float *v82; // ecx
  float *v83; // edi
  float *v84; // edx
  float *v85; // ecx
  float *v86; // edi
  float *v87; // ecx
  float *v88; // edx
  float *v89; // edi
  float *v90; // eax
  float *v91; // edx
  float *v92; // edi
  float *v93; // ebx
  unsigned int v94; // ecx
  long double v95; // [esp-8h] [ebp-5Ch]
  float *v96; // [esp+0h] [ebp-54h]
  float *v97; // [esp+0h] [ebp-54h]
  int v98; // [esp+0h] [ebp-54h]
  int v99; // [esp+0h] [ebp-54h]
  float *v100; // [esp+0h] [ebp-54h]
  float *v101; // [esp+4h] [ebp-50h]
  float *v102; // [esp+4h] [ebp-50h]
  float *v103; // [esp+8h] [ebp-4Ch]
  float *v104; // [esp+Ch] [ebp-48h]
  int v105; // [esp+Ch] [ebp-48h]
  int v106; // [esp+Ch] [ebp-48h]
  int v107; // [esp+Ch] [ebp-48h]
  int v108; // [esp+Ch] [ebp-48h]
  int v109; // [esp+Ch] [ebp-48h]
  int v110; // [esp+Ch] [ebp-48h]
  int v111; // [esp+Ch] [ebp-48h]
  float v112; // [esp+10h] [ebp-44h]
  int v113; // [esp+10h] [ebp-44h]
  int v114; // [esp+10h] [ebp-44h]
  int v115; // [esp+10h] [ebp-44h]
  unsigned int v116; // [esp+10h] [ebp-44h]
  int v117; // [esp+10h] [ebp-44h]
  int v118; // [esp+14h] [ebp-40h]
  int v119; // [esp+14h] [ebp-40h]
  int v120; // [esp+14h] [ebp-40h]
  int v121; // [esp+14h] [ebp-40h]
  int v122; // [esp+14h] [ebp-40h]
  int v123; // [esp+14h] [ebp-40h]
  int v124; // [esp+18h] [ebp-3Ch]
  int v125; // [esp+18h] [ebp-3Ch]
  int v126; // [esp+18h] [ebp-3Ch]
  int v127; // [esp+18h] [ebp-3Ch]
  int v128; // [esp+18h] [ebp-3Ch]
  int v129; // [esp+18h] [ebp-3Ch]
  int v130; // [esp+18h] [ebp-3Ch]
  int v131; // [esp+18h] [ebp-3Ch]
  int v132; // [esp+1Ch] [ebp-38h]
  float *v133; // [esp+1Ch] [ebp-38h]
  int v134; // [esp+20h] [ebp-34h]
  int v135; // [esp+20h] [ebp-34h]
  float *v136; // [esp+20h] [ebp-34h]
  unsigned int v137; // [esp+20h] [ebp-34h]
  float *v138; // [esp+20h] [ebp-34h]
  int v139; // [esp+20h] [ebp-34h]
  float *v140; // [esp+20h] [ebp-34h]
  float *v141; // [esp+20h] [ebp-34h]
  float *v142; // [esp+20h] [ebp-34h]
  float *v143; // [esp+20h] [ebp-34h]
  float *v144; // [esp+20h] [ebp-34h]
  float *v145; // [esp+20h] [ebp-34h]
  float *v146; // [esp+20h] [ebp-34h]
  float *v147; // [esp+20h] [ebp-34h]
  unsigned int v148; // [esp+24h] [ebp-30h]
  float *v149; // [esp+24h] [ebp-30h]
  float *v150; // [esp+24h] [ebp-30h]
  int v151; // [esp+24h] [ebp-30h]
  float *v152; // [esp+24h] [ebp-30h]
  float *v153; // [esp+24h] [ebp-30h]
  float *v154; // [esp+24h] [ebp-30h]
  float *v155; // [esp+24h] [ebp-30h]
  float *v156; // [esp+24h] [ebp-30h]
  float *v157; // [esp+24h] [ebp-30h]
  float *v158; // [esp+24h] [ebp-30h]
  int v159; // [esp+28h] [ebp-2Ch]
  float *v160; // [esp+28h] [ebp-2Ch]
  float *v161; // [esp+28h] [ebp-2Ch]
  float *v162; // [esp+28h] [ebp-2Ch]
  float *v163; // [esp+28h] [ebp-2Ch]
  float *v164; // [esp+28h] [ebp-2Ch]
  float *v165; // [esp+28h] [ebp-2Ch]
  float *v166; // [esp+28h] [ebp-2Ch]
  float *v167; // [esp+28h] [ebp-2Ch]
  float *v168; // [esp+2Ch] [ebp-28h]
  int v169; // [esp+2Ch] [ebp-28h]
  float *v170; // [esp+2Ch] [ebp-28h]
  float *v171; // [esp+2Ch] [ebp-28h]
  float *v172; // [esp+2Ch] [ebp-28h]
  float *v173; // [esp+2Ch] [ebp-28h]
  float *v174; // [esp+30h] [ebp-24h]
  float *v175; // [esp+30h] [ebp-24h]
  float *v176; // [esp+30h] [ebp-24h]
  float *v177; // [esp+30h] [ebp-24h]
  float *v178; // [esp+34h] [ebp-20h]
  float *v179; // [esp+34h] [ebp-20h]
  int v180; // [esp+34h] [ebp-20h]
  float *v181; // [esp+34h] [ebp-20h]
  float *v182; // [esp+34h] [ebp-20h]
  float *v183; // [esp+34h] [ebp-20h]
  int v184; // [esp+38h] [ebp-1Ch]
  float *v185; // [esp+3Ch] [ebp-18h]
  float *v186; // [esp+3Ch] [ebp-18h]
  float *v187; // [esp+3Ch] [ebp-18h]
  int v188; // [esp+3Ch] [ebp-18h]
  float *v189; // [esp+3Ch] [ebp-18h]
  float *v190; // [esp+3Ch] [ebp-18h]
  int v191; // [esp+3Ch] [ebp-18h]
  float *v192; // [esp+40h] [ebp-14h]
  float *v193; // [esp+40h] [ebp-14h]
  int v194; // [esp+40h] [ebp-14h]
  float *v195; // [esp+40h] [ebp-14h]
  int v196; // [esp+40h] [ebp-14h]
  float *v197; // [esp+40h] [ebp-14h]
  float *v198; // [esp+40h] [ebp-14h]
  float *v199; // [esp+44h] [ebp-10h]
  float *v200; // [esp+44h] [ebp-10h]
  int v201; // [esp+44h] [ebp-10h]
  float *v202; // [esp+44h] [ebp-10h]
  int v203; // [esp+44h] [ebp-10h]
  int v204; // [esp+44h] [ebp-10h]
  int v205; // [esp+44h] [ebp-10h]
  float *v206; // [esp+48h] [ebp-Ch]
  float *v207; // [esp+48h] [ebp-Ch]
  int v208; // [esp+48h] [ebp-Ch]
  int v209; // [esp+48h] [ebp-Ch]
  int v210; // [esp+48h] [ebp-Ch]
  int v211; // [esp+48h] [ebp-Ch]
  int v212; // [esp+48h] [ebp-Ch]
  float *v213; // [esp+48h] [ebp-Ch]
  int v214; // [esp+4Ch] [ebp-8h]
  int v215; // [esp+4Ch] [ebp-8h]
  int v216; // [esp+50h] [ebp-4h]
  float *v217; // [esp+5Ch] [ebp+8h]
  float *v218; // [esp+5Ch] [ebp+8h]
  float *v219; // [esp+5Ch] [ebp+8h]
  float *v220; // [esp+64h] [ebp+10h]
  float *v221; // [esp+64h] [ebp+10h]
  float *v222; // [esp+64h] [ebp+10h]
  int v223; // [esp+64h] [ebp+10h]
  int v224; // [esp+64h] [ebp+10h]

  v12 = (__m128)LODWORD(pi_x2_13);
  v12.m128_f32[0] = 6.2831855 / (float)ip;
  v95 = COERCE_DOUBLE(__PAIR64__(a3, a4));
  v14 = (__m128i)_mm_cvtps_pd(v12);
  __libm_sse2_cos(v95);
  *(float *)v14.m128i_i32 = *(double *)v14.m128i_i64;
  v112 = *(float *)v14.m128i_i32;
  *(double *)v14.m128i_i64 = (float)(6.2831855 / (float)ip);
  __libm_sse2_sin(v14);
  v132 = (ido - 1) >> 1;
  v214 = l1 * ido;
  v15 = (ip + 1) >> 1;
  v16 = 6.2831855 / (float)ip;
  v216 = v15;
  v184 = ip * ido;
  if ( ido != 1 )
  {
    if ( idl1 > 0 )
    {
      v17 = ch2;
      v18 = idl1;
      do
      {
        *v17 = *(float *)((char *)v17 + (char *)c2 - (char *)ch2);
        ++v17;
        --v18;
      }
      while ( v18 );
    }
    v19 = ip;
    if ( ip > 1 )
    {
      v185 = ch;
      v134 = ip - 1;
      do
      {
        v185 += v214;
        if ( l1 > 0 )
        {
          v20 = (char *)c1 - (char *)ch;
          v124 = l1;
          v21 = v185;
          while ( 1 )
          {
            *v21 = *(float *)((char *)v21 + v20);
            v21 += ido;
            if ( !--v124 )
              break;
            v20 = (char *)c1 - (char *)ch;
          }
        }
        --v134;
      }
      while ( v134 );
    }
    if ( v132 <= l1 )
    {
      if ( ip > 1 )
      {
        v193 = &wa[-ido - 1];
        v187 = c1 - 1;
        v179 = ch;
        v159 = ip - 1;
        do
        {
          v193 += ido;
          v179 += v214;
          v187 += v214;
          if ( ido > 2 )
          {
            v28 = v193;
            v200 = v179;
            v207 = v187;
            v29 = ((unsigned int)(ido - 3) >> 1) + 1;
            v148 = v29;
            do
            {
              v200 += 2;
              v207 += 2;
              v28 += 2;
              v136 = v28;
              if ( l1 > 0 )
              {
                v168 = v200;
                v30 = v207;
                v126 = l1;
                do
                {
                  *(float *)((char *)v30 + (char *)ch - (char *)c1) = (float)(*v28 * v30[1])
                                                                    + (float)(*(v28 - 1) * *v30);
                  v31 = *(v28 - 1);
                  v32 = *v28 * *v30;
                  v28 = v136;
                  *v168 = (float)(v31 * v30[1]) - v32;
                  v168 += ido;
                  v30 += ido;
                  --v126;
                }
                while ( v126 );
                v29 = v148;
              }
              v19 = ip;
              v148 = --v29;
            }
            while ( v29 );
          }
          --v159;
        }
        while ( v159 );
      }
    }
    else if ( ip > 1 )
    {
      v199 = &wa[-ido - 1];
      v22 = &ch[-ido];
      v23 = &c1[-ido - 1];
      v135 = ip - 1;
      do
      {
        v22 += v214;
        v23 += v214;
        v199 += ido;
        v104 = v22;
        if ( l1 <= 0 )
        {
          v15 = (ip + 1) >> 1;
        }
        else
        {
          v192 = v22;
          v206 = v23;
          v125 = l1;
          do
          {
            v192 += ido;
            v206 += ido;
            if ( ido > 2 )
            {
              v24 = v206;
              v178 = v192;
              v186 = v199;
              v25 = ((unsigned int)(ido - 3) >> 1) + 1;
              do
              {
                v186 += 2;
                v26 = v24[3] * *v186;
                v178 += 2;
                v24 += 2;
                --v25;
                *(float *)((char *)v24 + (char *)ch - (char *)c1) = v26 + (float)(*v24 * *(v186 - 1));
                *v178 = (float)(*(v186 - 1) * v24[1]) - (float)(*v24 * *v186);
              }
              while ( v25 );
              v22 = v104;
            }
            v27 = v125-- == 1;
            v15 = (ip + 1) >> 1;
          }
          while ( !v27 );
        }
        --v135;
      }
      while ( v135 );
      v19 = ip;
    }
    v201 = 0;
    v194 = v19 * v214;
    if ( v132 >= l1 )
    {
      if ( v15 > 1 )
      {
        v40 = v19 * v214;
        v170 = &ch[v40 - 1];
        v150 = c1;
        v161 = &c1[v40];
        v41 = ch - 1;
        v128 = v15 - 1;
        while ( 1 )
        {
          v150 += v214;
          v161 -= v214;
          v170 -= v214;
          v42 = &v41[v214];
          v97 = v42;
          if ( l1 > 0 )
          {
            v189 = v150;
            v202 = v161;
            v138 = v170;
            v195 = v42;
            v119 = l1;
            do
            {
              if ( ido > 2 )
              {
                v43 = v195;
                v44 = v138;
                v175 = v189;
                v181 = v202;
                v209 = (char *)c1 - (char *)ch;
                v45 = ((unsigned int)(ido - 3) >> 1) + 1;
                do
                {
                  v175 += 2;
                  v181 += 2;
                  v43 += 2;
                  v44 += 2;
                  --v45;
                  *(float *)((char *)v43 + v209) = *v43 + *v44;
                  *(float *)((char *)v44 + v209) = v43[1] - v44[1];
                  *v175 = v44[1] + v43[1];
                  *v181 = *v44 - *v43;
                }
                while ( v45 );
                v15 = (ip + 1) >> 1;
              }
              v189 += ido;
              v195 += ido;
              v202 += ido;
              v138 += ido;
              --v119;
            }
            while ( v119 );
          }
          if ( !--v128 )
            break;
          v41 = v97;
        }
      }
    }
    else if ( v15 > 1 )
    {
      v169 = -ido;
      v33 = &c1[-ido];
      v34 = &ch[-ido - 1];
      v118 = v15 - 1;
      do
      {
        v201 += v214;
        v169 += v214;
        v194 -= v214;
        v33 += v214;
        v34 += v214;
        v101 = v33;
        v96 = v34;
        v188 = v201;
        if ( ido <= 2 )
        {
          v15 = (ip + 1) >> 1;
        }
        else
        {
          v180 = v169;
          v174 = v33;
          v35 = ((unsigned int)(ido - 3) >> 1) + 1;
          v160 = v34;
          v137 = v35;
          do
          {
            v188 += 2;
            v174 += 2;
            v160 += 2;
            v180 += 2;
            if ( l1 > 0 )
            {
              v36 = v174;
              v37 = v194 - v201 + v180;
              v208 = (char *)c1 - (char *)ch;
              v149 = &c1[v37];
              v38 = v160;
              v39 = &ch[v37 - 1];
              v127 = l1;
              do
              {
                v149 += ido;
                v38 += ido;
                v39 += ido;
                v36 += ido;
                v27 = v127-- == 1;
                *(float *)((char *)v38 + v208) = *v38 + *v39;
                *(float *)((char *)v39 + v208) = v38[1] - v39[1];
                *v36 = v39[1] + v38[1];
                *v149 = *v39 - *v38;
              }
              while ( !v27 );
              v35 = v137;
              v33 = v101;
              v34 = v96;
            }
            v15 = (ip + 1) >> 1;
            v137 = --v35;
          }
          while ( v35 );
        }
        --v118;
      }
      while ( v118 );
    }
  }
  if ( idl1 > 0 )
  {
    v46 = c2;
    v47 = idl1;
    do
    {
      *v46 = *(float *)((char *)v46 + (char *)ch2 - (char *)c2);
      ++v46;
      --v47;
    }
    while ( v47 );
  }
  v48 = idl1 * ip;
  v203 = 0;
  v196 = idl1 * ip;
  if ( v15 > 1 )
  {
    v139 = -ido;
    v49 = &ch[-ido];
    v151 = v15 - 1;
    do
    {
      v203 += v214;
      v139 += v214;
      v196 -= v214;
      v49 += v214;
      if ( l1 > 0 )
      {
        v210 = (char *)c1 - (char *)ch;
        v50 = v49;
        v51 = &ch[v196 + v139 - v203];
        v120 = l1;
        do
        {
          v51 += ido;
          v50 += ido;
          v27 = v120-- == 1;
          *(float *)((char *)v50 + v210) = *v51 + *v50;
          *(float *)((char *)v51 + v210) = *v51 - *v50;
        }
        while ( !v27 );
        v15 = (ip + 1) >> 1;
      }
      v27 = v151-- == 1;
      v48 = idl1 * ip;
    }
    while ( !v27 );
  }
  v52 = idl1;
  v53 = LODWORD(s_bm_current_air_resistance);
  v54 = 0.0;
  v121 = idl1 * (ip - 1);
  if ( v15 <= 1 )
  {
    v55 = c2;
  }
  else
  {
    v190 = &ch2[v48];
    v105 = v15 - 1;
    v55 = c2;
    v197 = ch2;
    do
    {
      v211 = 0;
      v56 = 4 * v52;
      v197 = (float *)((char *)v197 + v56);
      v190 = (float *)((char *)v190 - v56);
      v57 = v53;
      *(float *)&v57 = (float)(*(float *)&v53 * v112) - (float)(v54 * v16);
      v98 = v56;
      v52 = idl1;
      v54 = (float)(*(float *)&v53 * v16) + (float)(v54 * v112);
      v53 = v57;
      if ( idl1 > 0 )
      {
        v162 = &c2[v121];
        v171 = v190;
        v152 = v197;
        v140 = (float *)((char *)c2 + v98);
        do
        {
          v58 = *v140++;
          v59 = v152++;
          *v59 = (float)(v58 * *(float *)&v57) + c2[v211];
          v60 = *v162;
          v61 = v171;
          ++v162;
          ++v171;
          ++v211;
          *v61 = v60 * v54;
        }
        while ( v211 < idl1 );
      }
      v62 = v57;
      v63 = v54;
      if ( v15 > 2 )
      {
        v153 = &c2[idl1];
        v141 = &c2[v121];
        v204 = v15 - 2;
        do
        {
          v64 = 4 * v52;
          v153 = (float *)((char *)v153 + v64);
          v141 = (float *)((char *)v141 - v64);
          v52 = idl1;
          v65 = v62;
          *(float *)&v65 = (float)(*(float *)&v62 * *(float *)&v57) - (float)(v63 * v54);
          v63 = (float)(v63 * *(float *)&v57) + (float)(*(float *)&v62 * v54);
          v62 = v65;
          if ( idl1 > 0 )
          {
            v182 = v190;
            v176 = v141;
            v172 = v197;
            v163 = v153;
            v129 = idl1;
            do
            {
              v66 = *v163;
              v67 = v172;
              ++v163;
              ++v172;
              *v67 = (float)(v66 * *(float *)&v65) + *v67;
              v68 = *v176;
              v69 = v182;
              ++v176;
              ++v182;
              v27 = v129-- == 1;
              *v69 = (float)(v68 * v63) + *v69;
            }
            while ( !v27 );
          }
          --v204;
        }
        while ( v204 );
      }
      --v105;
    }
    while ( v105 );
  }
  if ( v15 > 1 )
  {
    v220 = v55;
    v106 = v15 - 1;
    do
    {
      v212 = 0;
      v220 += v52;
      if ( v52 > 0 )
      {
        v142 = v220;
        do
        {
          v70 = v212++;
          v71 = *v142++;
          ch2[v70] = v71 + ch2[v70];
        }
        while ( v212 < v52 );
      }
      --v106;
    }
    while ( v106 );
  }
  if ( ido >= l1 )
  {
    if ( l1 > 0 )
    {
      v164 = cc;
      v155 = ch;
      v114 = l1;
      do
      {
        if ( ido > 0 )
        {
          v144 = v164;
          v221 = v155;
          v108 = ido;
          do
          {
            v75 = *v221++;
            *v144++ = v75;
            --v108;
          }
          while ( v108 );
        }
        v155 += ido;
        v164 += v184;
        --v114;
      }
      while ( v114 );
    }
  }
  else if ( ido > 0 )
  {
    v72 = (char *)cc - (char *)ch;
    v154 = ch;
    v113 = ido;
    do
    {
      if ( l1 > 0 )
      {
        v73 = (float *)((char *)v154 + v72);
        v143 = v154;
        v107 = l1;
        do
        {
          v74 = *v143;
          v143 += ido;
          *v73 = v74;
          v73 += v184;
          --v107;
        }
        while ( v107 );
        v72 = (char *)cc - (char *)ch;
      }
      ++v154;
      --v113;
    }
    while ( v113 );
  }
  v76 = ip * v214;
  v77 = 2 * ido;
  if ( v15 > 1 )
  {
    v145 = &ch[v76];
    v222 = ch;
    v217 = cc;
    v115 = v15 - 1;
    do
    {
      v217 += 2 * ido;
      v222 += v214;
      v145 -= v214;
      if ( l1 > 0 )
      {
        v78 = v217;
        v156 = v222;
        v165 = v145;
        v109 = l1;
        while ( 1 )
        {
          *(v78 - 1) = *v156;
          *v78 = *v165;
          v156 += ido;
          v165 += ido;
          if ( !--v109 )
            break;
          v78 += v184;
        }
      }
      --v115;
    }
    while ( v115 );
  }
  if ( ido != 1 )
  {
    if ( v132 >= l1 )
    {
      if ( v216 > 1 )
      {
        v219 = &ch[v76 + 2];
        v111 = 2 * ido;
        v84 = cc + 2;
        v85 = cc - 2;
        v86 = ch + 2;
        v131 = v214;
        v123 = v216 - 1;
        while ( 1 )
        {
          v219 = (float *)((char *)v219 - v131 * 4);
          v87 = &v85[v111];
          v88 = &v84[v111];
          v89 = &v86[v131];
          v100 = v87;
          v102 = v88;
          v103 = v89;
          if ( l1 > 0 )
          {
            v147 = v87;
            v224 = 4 * v184;
            v158 = v89;
            v133 = v88;
            v167 = v219;
            v117 = l1;
            do
            {
              if ( ido > 2 )
              {
                v90 = v158;
                v91 = v167;
                v92 = v133;
                v93 = v147;
                v94 = ((unsigned int)(ido - 3) >> 1) + 1;
                do
                {
                  *(v92 - 1) = *(v90 - 1) + *(v91 - 1);
                  *(v93 - 1) = *(v90 - 1) - *(v91 - 1);
                  *v92 = *v90 + *v91;
                  *v93 = *v91 - *v90;
                  v92 += 2;
                  v91 += 2;
                  v90 += 2;
                  v93 -= 2;
                  --v94;
                }
                while ( v94 );
              }
              v133 = (float *)((char *)v133 + v224);
              v147 = (float *)((char *)v147 + v224);
              v158 += ido;
              v167 += ido;
              --v117;
            }
            while ( v117 );
          }
          if ( !--v123 )
            break;
          v85 = v100;
          v86 = v103;
          v84 = v102;
        }
      }
    }
    else
    {
      v191 = 0;
      if ( v216 > 1 )
      {
        v157 = &ch[v76 + 2];
        v130 = 4 * v214;
        v79 = -2;
        v166 = cc - 2;
        v80 = 4;
        v146 = ch + 2;
        v122 = v216 - 1;
        do
        {
          v80 += -2 * ido;
          v191 += v77;
          v166 += 2 * ido;
          v146 = (float *)((char *)v146 + v130);
          v157 = (float *)((char *)v157 - v130);
          v79 += v77;
          v99 = v79;
          if ( ido > 2 )
          {
            v213 = v146;
            v177 = v157;
            v183 = v166;
            v81 = ((unsigned int)(ido - 3) >> 1) + 1;
            v215 = v80;
            v205 = v79;
            v116 = v81;
            do
            {
              if ( l1 > 0 )
              {
                v223 = 4 * v184;
                v198 = v183;
                v218 = &cc[v191 + v215 + v205];
                v173 = v213;
                v82 = v177;
                v110 = l1;
                v83 = v213;
                do
                {
                  *(v218 - 1) = *(v82 - 1) + *(v83 - 1);
                  *(v198 - 1) = *(v83 - 1) - *(v82 - 1);
                  *v218 = *v82 + *v83;
                  *v198 = *v82 - *v83;
                  v218 = (float *)((char *)v218 + v223);
                  v198 = (float *)((char *)v198 + v223);
                  v83 = &v173[ido];
                  v82 += ido;
                  v27 = v110-- == 1;
                  v173 = v83;
                }
                while ( !v27 );
                v79 = v99;
                v81 = v116;
              }
              v177 += 2;
              v183 -= 2;
              v205 -= 2;
              v213 += 2;
              v215 += 4;
              v116 = --v81;
            }
            while ( v81 );
          }
          --v122;
        }
        while ( v122 );
      }
    }
  }
}
