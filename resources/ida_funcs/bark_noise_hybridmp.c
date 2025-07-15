void __cdecl bark_noise_hybridmp(int n, int *b, const float *f, float *noise, const float offset, const int fixed)
{
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  void *v10; // esp
  double v11; // st5
  double v12; // st4
  unsigned int v13; // ecx
  double v14; // st3
  double v15; // st4
  double v16; // st6
  double v17; // st2
  double v18; // st7
  double v19; // st3
  double v20; // st7
  double v21; // rtt
  float *v22; // edx
  double v23; // st2
  double v24; // st1
  double v25; // st4
  double v26; // rt1
  double v27; // st6
  double v28; // st4
  double v29; // st3
  char *v30; // eax
  float *v31; // edx
  double v32; // st2
  int v33; // eax
  double v34; // st1
  double v35; // st4
  double v36; // rt2
  double v37; // st4
  float *v38; // edx
  double v39; // st3
  double v40; // st2
  double v41; // st4
  double v42; // st1
  double v43; // st4
  int v44; // eax
  double v45; // st3
  double v46; // st2
  float *v47; // eax
  float *v48; // edx
  double v49; // st1
  double v50; // st4
  double v51; // rt0
  float **v52; // eax
  double v53; // st3
  bool v54; // zf
  unsigned int v55; // eax
  double v56; // st1
  double v57; // st1
  float *v58; // edx
  double v59; // rt0
  double v60; // st2
  double v61; // st7
  int v62; // eax
  double v63; // st1
  double v64; // st4
  double v65; // rt2
  double v66; // rt0
  double v67; // st2
  double v68; // rt2
  double v69; // st5
  double v70; // st7
  int v71; // edx
  int v72; // eax
  int v73; // eax
  double v74; // st3
  double v75; // st4
  double v76; // st2
  double v77; // st5
  int v78; // eax
  int j; // edx
  int v80; // edx
  int v81; // eax
  int v82; // edx
  double v83; // st2
  double v84; // st1
  bool v85; // sf
  int v86; // edx
  int v87; // eax
  int v88; // edx
  double v89; // st2
  double v90; // st1
  bool v91; // cc
  int v92; // esi
  unsigned int v93; // ecx
  float *v94; // edi
  double v95; // st1
  double v96; // st1
  double v97; // st1
  double v98; // st1
  double v99; // st1
  float v100[2]; // [esp+0h] [ebp-84h] BYREF
  int v101; // [esp+8h] [ebp-7Ch] BYREF
  float *v102; // [esp+Ch] [ebp-78h] BYREF
  unsigned int v103; // [esp+10h] [ebp-74h] BYREF
  int v104; // [esp+14h] [ebp-70h]
  int v105; // [esp+18h] [ebp-6Ch]
  unsigned int v106; // [esp+1Ch] [ebp-68h]
  int v107; // [esp+20h] [ebp-64h]
  int v108; // [esp+24h] [ebp-60h]
  char *v109; // [esp+28h] [ebp-5Ch]
  char *v110; // [esp+2Ch] [ebp-58h]
  unsigned int v111; // [esp+30h] [ebp-54h]
  int v112; // [esp+34h] [ebp-50h]
  int v113; // [esp+38h] [ebp-4Ch]
  int v114; // [esp+3Ch] [ebp-48h]
  int v115; // [esp+40h] [ebp-44h]
  int v116; // [esp+44h] [ebp-40h]
  float *v117; // [esp+48h] [ebp-3Ch]
  float *v118; // [esp+4Ch] [ebp-38h]
  float **v119; // [esp+54h] [ebp-30h]
  float *v120; // [esp+58h] [ebp-2Ch]
  float v121; // [esp+5Ch] [ebp-28h]
  float v122; // [esp+60h] [ebp-24h]
  float v123; // [esp+64h] [ebp-20h]
  float v124; // [esp+68h] [ebp-1Ch]
  int v125; // [esp+6Ch] [ebp-18h]
  float v126; // [esp+70h] [ebp-14h]
  float v127; // [esp+74h] [ebp-10h]
  float v128; // [esp+78h] [ebp-Ch]
  float v129; // [esp+7Ch] [ebp-8h]
  float v130; // [esp+80h] [ebp-4h]
  int v131; // [esp+90h] [ebp+Ch]
  int v132; // [esp+90h] [ebp+Ch]
  int v133; // [esp+94h] [ebp+10h]
  float v134; // [esp+94h] [ebp+10h]
  int i; // [esp+94h] [ebp+10h]
  float v136; // [esp+94h] [ebp+10h]
  float v137; // [esp+94h] [ebp+10h]
  int v138; // [esp+94h] [ebp+10h]
  int v139; // [esp+94h] [ebp+10h]
  float v140; // [esp+94h] [ebp+10h]
  int v141; // [esp+94h] [ebp+10h]
  float v142; // [esp+94h] [ebp+10h]
  float v143; // [esp+94h] [ebp+10h]
  float v144; // [esp+94h] [ebp+10h]
  float v145; // [esp+94h] [ebp+10h]
  float v146; // [esp+94h] [ebp+10h]
  float v147; // [esp+94h] [ebp+10h]
  float v148; // [esp+9Ch] [ebp+18h]
  float v149; // [esp+9Ch] [ebp+18h]
  float v150; // [esp+9Ch] [ebp+18h]
  float v151; // [esp+9Ch] [ebp+18h]
  float v152; // [esp+9Ch] [ebp+18h]
  float v153; // [esp+9Ch] [ebp+18h]
  float v154; // [esp+9Ch] [ebp+18h]
  float v155; // [esp+9Ch] [ebp+18h]
  float v156; // [esp+9Ch] [ebp+18h]
  float v157; // [esp+9Ch] [ebp+18h]

  v6 = alloca(4 * n);
  v7 = alloca(4 * n);
  v8 = alloca(4 * n);
  v9 = alloca(4 * n);
  v111 = (unsigned int)v100;
  v10 = alloca(4 * n);
  v122 = 0.0;
  v123 = 0.0;
  v121 = 1.0;
  v130 = 0.0;
  v129 = 0.0;
  v11 = offset;
  v128 = *f + offset;
  v12 = v128;
  if ( v128 < 1.0 )
  {
    v128 = 1.0;
    v12 = (float)1.0;
  }
  v13 = v111;
  v125 = 1;
  v124 = v12 * v12 * 0.5;
  v14 = v124;
  v148 = v124 + 0.0;
  v124 = v148;
  v126 = v148;
  v127 = v12 * v14 + 0.0;
  v15 = v148;
  v16 = v148;
  v17 = v127;
  *(float *)v111 = v127;
  v100[0] = 0.0;
  v18 = 0.0;
  v149 = 1.0;
  if ( n <= 1 )
  {
    v27 = 1.0;
  }
  else
  {
    if ( n - 1 < 4 )
    {
      v20 = 1.0;
      v57 = v16;
      v27 = 1.0;
      v53 = v57;
      v56 = 0.0;
    }
    else
    {
      v19 = 1.0;
      v118 = (float *)(v13 + 4);
      v20 = 1.0;
      v117 = (float *)&v103;
      v119 = &v102;
      v120 = (float *)&v101;
      v116 = (char *)f - (char *)v100;
      v115 = 0;
      v114 = 0;
      v113 = v13 - (_DWORD)v100;
      v112 = 0;
      v108 = (char *)f - (char *)v100;
      v107 = 0;
      v106 = v13 - (_DWORD)v100;
      v105 = 0;
      v104 = (char *)f - (char *)v100;
      v103 = v13 - (_DWORD)v100;
      v102 = 0;
      v110 = (char *)f - v13;
      v109 = (char *)v100 - v13;
      v111 = ((unsigned int)(n - 5) >> 2) + 1;
      v125 = 4 * v111 + 1;
      while ( 1 )
      {
        v22 = v118;
        v128 = *(float *)((char *)v118 + (_DWORD)v110) + v11;
        v23 = v128;
        if ( v128 < 1.0 )
        {
          v128 = 1.0;
          v23 = (float)1.0;
        }
        v124 = v23 * v23;
        v24 = v15 + v124;
        v25 = v124;
        v124 = v24;
        v26 = v149 * v25;
        v126 = v16 + v26;
        v129 = v149 * v26 + v129;
        v127 = v25 * v23 + v127;
        v27 = v19;
        v130 = v26 * v23 + v130;
        v28 = v124;
        *(v120 - 1) = v124;
        v29 = v126;
        *((float *)v119 - 2) = v126;
        *(v117 - 3) = v129;
        v30 = v109;
        *v22 = v127;
        *(float *)((char *)v22 + (_DWORD)v30) = v130;
        v31 = v120;
        v150 = v149 + v27;
        v128 = *(float *)((char *)v120 + v116) + v11;
        v32 = v128;
        if ( v128 < 1.0 )
        {
          v128 = 1.0;
          v32 = (float)1.0;
        }
        v33 = v115;
        v124 = v32 * v32;
        v34 = v28 + v124;
        v35 = v124;
        v124 = v34;
        v36 = v150 * v35;
        v126 = v29 + v36;
        v129 = v150 * v36 + v129;
        v127 = v35 * v32 + v127;
        v130 = v32 * v36 + v130;
        v37 = v124;
        *v120 = v124;
        *(float *)((char *)v31 + v33) = v126;
        *(float *)((char *)v31 + v114) = v129;
        *(float *)((char *)v31 + v113) = v127;
        *(float *)((char *)v31 + v112) = v130;
        v38 = (float *)v119;
        v151 = v150 + v27;
        v128 = *(float *)((char *)v119 + v108) + v11;
        v39 = v128;
        if ( v128 < 1.0 )
        {
          v128 = 1.0;
          v39 = (float)1.0;
        }
        v124 = v39 * v39;
        v40 = v37 + v124;
        v41 = v124;
        v124 = v40;
        v42 = v151 * v41;
        v126 = v126 + v42;
        v129 = v151 * v42 + v129;
        v127 = v41 * v39 + v127;
        v130 = v42 * v39 + v130;
        v43 = v124;
        v120[1] = v124;
        v44 = v107;
        v45 = v126;
        *v38 = v126;
        *(float *)((char *)v38 + v44) = v129;
        *(float *)((char *)v38 + v106) = v127;
        *(float *)((char *)v38 + v105) = v130;
        v152 = v151 + v27;
        v128 = *(float *)((char *)v117 + v104) + v11;
        v46 = v128;
        if ( v128 < 1.0 )
        {
          v128 = 1.0;
          v46 = (float)1.0;
        }
        v47 = v120;
        v120 += 4;
        v118 += 4;
        v124 = v46 * v46;
        v117 += 4;
        v48 = v117;
        v49 = v43 + v124;
        v50 = v124;
        v124 = v49;
        v51 = v152 * v50;
        v126 = v45 + v51;
        v129 = v152 * v51 + v129;
        v127 = v50 * v46 + v127;
        v130 = v46 * v51 + v130;
        v15 = v124;
        v47[2] = v124;
        v52 = v119;
        v53 = v126;
        v119 += 4;
        v54 = v111-- == 1;
        *((float *)v52 + 1) = v126;
        v55 = v103;
        *(v48 - 4) = v129;
        v17 = v127;
        *(float *)((char *)v48 + v55 - 16) = v127;
        *(float *)((char *)v48 + (_DWORD)v102 - 16) = v130;
        v149 = v152 + v27;
        if ( v54 )
          break;
        v21 = v53;
        v19 = v27;
        v16 = v21;
      }
      v56 = 0.0;
    }
    if ( v125 >= n )
    {
      v18 = v56;
    }
    else
    {
      v102 = &v100[v125];
      v116 = (char *)f - (char *)v100;
      v115 = 0;
      v114 = 0;
      v113 = v13 - (_DWORD)v100;
      v112 = 0;
      v58 = v102;
      v133 = n - v125;
      do
      {
        v128 = *(float *)((char *)v58 + v116) + v11;
        v59 = v17;
        v60 = v20;
        v61 = v59;
        if ( v60 > v128 )
          v128 = v60;
        v62 = v115;
        ++v58;
        v54 = v133-- == 1;
        v124 = v128 * v128;
        v63 = v15 + v124;
        v64 = v124;
        v124 = v63;
        v65 = v149 * v64;
        v126 = v53 + v65;
        v129 = v149 * v65 + v129;
        v66 = v60;
        v67 = v61 + v64 * v128;
        v20 = v66;
        v127 = v67;
        v130 = v128 * v65 + v130;
        v15 = v124;
        *(v58 - 1) = v124;
        v53 = v126;
        *(float *)((char *)v58 + v62 - 4) = v126;
        *(float *)((char *)v58 + v114 - 4) = v129;
        v17 = v127;
        *(float *)((char *)v58 + v113 - 4) = v127;
        *(float *)((char *)v58 + v112 - 4) = v130;
        v149 = v149 + v27;
      }
      while ( !v54 );
      v18 = 0.0;
    }
  }
  v68 = v11;
  v69 = v18;
  v70 = v68;
  v71 = *b;
  v153 = v69;
  v72 = v71 >> 16;
  v125 = 0;
  if ( v71 >> 16 >= 0 )
  {
    v74 = v123;
    v75 = v121;
    v76 = v69;
    v77 = v122;
  }
  else
  {
    v119 = 0;
    while ( 1 )
    {
      v73 = -1 * v72;
      v124 = v100[(unsigned __int16)v71] + v100[v73];
      v126 = v100[(unsigned __int16)v71] - v100[v73];
      v129 = v100[(unsigned __int16)v71] + v100[v73];
      v127 = *(float *)(v13 + 4 * (unsigned __int16)v71) + *(float *)(v73 * 4 + v13);
      v130 = v100[(unsigned __int16)v71] - v100[v73];
      v122 = v127 * v129 - v130 * v126;
      v123 = v130 * v124 - v127 * v126;
      v121 = v124 * v129 - v126 * v126;
      v74 = v123;
      v75 = v121;
      v134 = (v153 * v123 + v122) / v121;
      v76 = v69;
      v77 = v122;
      if ( v76 > v134 )
        v134 = v76;
      *(float *)((char *)noise + (_DWORD)v119) = v134 - v70;
      ++v125;
      v153 = v153 + v27;
      v71 = b[v125];
      v119 = (float **)(4 * v125);
      v72 = v71 >> 16;
      if ( v71 >> 16 >= 0 )
        break;
      v69 = v76;
    }
  }
  v119 = (float **)(4 * v125);
  v78 = (unsigned __int16)b[v125];
  for ( i = b[v125] >> 16; v78 < n; i = b[v125] >> 16 )
  {
    v124 = v100[v78] - v100[i];
    v126 = v100[v78] - v100[i];
    v129 = v100[v78] - v100[i];
    v127 = *(float *)(v13 + 4 * v78) - *(float *)(v13 + 4 * i);
    v130 = v100[v78] - v100[i];
    v122 = v127 * v129 - v130 * v126;
    v123 = v130 * v124 - v127 * v126;
    v121 = v124 * v129 - v126 * v126;
    v74 = v123;
    v75 = v121;
    v136 = (v153 * v123 + v122) / v121;
    v77 = v122;
    if ( v76 > v136 )
      v136 = v76;
    *(float *)((char *)noise + (_DWORD)v119) = v136 - v70;
    ++v125;
    v153 = v153 + v27;
    v119 = (float **)(4 * v125);
    v78 = (unsigned __int16)b[v125];
  }
  for ( j = v125; j < n; v153 = v153 + v27 )
  {
    v137 = (v153 * v74 + v77) / v75;
    if ( v76 > v137 )
      v137 = v76;
    noise[j++] = v137 - v70;
  }
  if ( fixed > 0 )
  {
    v154 = v76;
    v131 = fixed / 2;
    v125 = 0;
    v138 = fixed / 2 - fixed;
    if ( v138 < 0 )
    {
      v102 = (float *)(4 * v131);
      v113 = v131 - fixed;
      v112 = 4 * v131;
      v139 = -4 * v138;
      v80 = v139;
      v111 = 4 * (fixed - v131);
      v81 = 4 * v131;
      do
      {
        v124 = *(float *)((char *)v100 + v80) + *(float *)((char *)v100 + v81);
        v126 = *(float *)((char *)v100 + v81) - *(float *)((char *)v100 + v80);
        v129 = *(float *)((char *)v100 + v80) + *(float *)((char *)v100 + v81);
        v127 = *(float *)(v80 + v13) + *(float *)(v81 + v13);
        v82 = v125;
        v130 = *(float *)((char *)v100 + v81) - *(float *)((char *)v100 + v139);
        v122 = v127 * v129 - v130 * v126;
        v123 = v130 * v124 - v127 * v126;
        v121 = v124 * v129 - v126 * v126;
        v74 = v123;
        v83 = v122;
        v75 = v121;
        v140 = (v154 * v123 + v122) / v121;
        v84 = v140 - v70;
        if ( noise[v125] > v84 )
          noise[v125] = v84;
        v112 += 4;
        v77 = v83;
        v81 = v112;
        v125 = v82 + 1;
        v154 = v154 + v27;
        v80 = v111 - 4;
        v85 = ++v113 < 0;
        v111 = v80;
        v139 = v80;
      }
      while ( v85 );
    }
    v86 = n;
    v102 = (float *)(v131 + v125);
    v87 = v131 + v125;
    if ( v131 + v125 < n )
    {
      v112 = v131 + v125;
      v141 = 4 * (v131 + v125 - fixed);
      v111 = 4 * v87;
      v113 = 4 * v87;
      v132 = 4 * (v125 + v131 - fixed);
      do
      {
        v124 = *(float *)((char *)v100 + v113) - *(float *)((char *)v100 + v141);
        v126 = *(float *)((char *)v100 + v113) - *(float *)((char *)v100 + v141);
        v129 = *(float *)((char *)v100 + v113) - *(float *)((char *)v100 + v141);
        v127 = *(float *)(v113 + v13) - *(float *)(v141 + v13);
        v88 = v125;
        v130 = *(float *)((char *)v100 + v113) - *(float *)((char *)v100 + v141);
        v122 = v127 * v129 - v130 * v126;
        v123 = v130 * v124 - v127 * v126;
        v121 = v124 * v129 - v126 * v126;
        v74 = v123;
        v89 = v122;
        v75 = v121;
        v142 = (v154 * v123 + v122) / v121;
        v90 = v142 - v70;
        if ( noise[v125] > v90 )
          noise[v125] = v90;
        v77 = v89;
        v132 += 4;
        v125 = v88 + 1;
        v154 = v154 + v27;
        v91 = v112 + 1 < n;
        v111 += 4;
        v113 = v111;
        ++v112;
        v141 = v132;
      }
      while ( v91 );
      v86 = n;
    }
    v92 = v125;
    if ( v125 < v86 )
    {
      if ( v86 - v125 >= 4 )
      {
        v93 = ((unsigned int)(v86 - v125 - 4) >> 2) + 1;
        v94 = &noise[v125 + 2];
        v125 += 4 * v93;
        do
        {
          v143 = (v154 * v74 + v77) / v75;
          v95 = v143 - v70;
          if ( *(v94 - 2) > v95 )
            *(v94 - 2) = v95;
          v155 = v154 + v27;
          v144 = (v155 * v74 + v77) / v75;
          v96 = v144 - v70;
          if ( *(v94 - 1) > v96 )
            *(v94 - 1) = v96;
          v156 = v155 + v27;
          v145 = (v156 * v74 + v77) / v75;
          v97 = v145 - v70;
          if ( *v94 > v97 )
            *v94 = v97;
          v157 = v156 + v27;
          v146 = (v157 * v74 + v77) / v75;
          v98 = v146 - v70;
          if ( v94[1] > v98 )
            v94[1] = v98;
          v94 += 4;
          --v93;
          v154 = v157 + v27;
        }
        while ( v93 );
        v92 = v125;
      }
      for ( ; v92 < v86; v154 = v154 + v27 )
      {
        v147 = (v154 * v74 + v77) / v75;
        v99 = v147 - v70;
        if ( noise[v92] > v99 )
          noise[v92] = v99;
        ++v92;
      }
    }
  }
}
