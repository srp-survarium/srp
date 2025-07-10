void __fastcall _vp_couple_quantize_normalize(
        vorbis_info_psy_global *g,
        int blobno,
        vorbis_look_psy *p,
        vorbis_info_mapping0 *vi,
        float **mdct,
        int **iwork,
        int *nonzero,
        int sliding_lowpass,
        int ch)
{
  vorbis_info_psy *v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // ecx
  void *v13; // esp
  void *v14; // esp
  void *v15; // esp
  float **v16; // ebx
  void *v17; // esp
  void *v18; // esp
  void *v19; // esp
  int v20; // edi
  void *v21; // esp
  void *v22; // esp
  void *v23; // esp
  void *v24; // esp
  int v25; // eax
  int v26; // edx
  int *v27; // ecx
  float *v28; // edi
  char *v29; // edx
  float *v30; // esi
  double v31; // st7
  double v32; // st6
  float **v33; // esi
  char *v34; // eax
  float *v35; // edi
  int v36; // ebx
  int v37; // eax
  unsigned int v38; // ecx
  float *v39; // edx
  float *v40; // ebx
  double v41; // st7
  double v42; // st7
  int v43; // eax
  char *v44; // edx
  int v45; // ecx
  int v46; // ebx
  float *v47; // ebx
  int v48; // edx
  double v49; // st7
  int v50; // edi
  double v51; // st6
  int v52; // ecx
  float *v53; // eax
  float *v54; // edx
  int v55; // edi
  int *v56; // ebx
  float *v57; // ecx
  unsigned int v58; // edi
  float *v59; // ebx
  float *v60; // eax
  double v61; // st5
  float *v62; // eax
  double v63; // st5
  int v64; // eax
  double v65; // st5
  float *v66; // eax
  double v67; // st5
  float *v68; // eax
  double v69; // st5
  double v70; // st5
  int v71; // eax
  float *v72; // ebx
  char *v73; // ebx
  float *v74; // ecx
  int v75; // edi
  float *v76; // edx
  int v77; // eax
  double v78; // st5
  double v79; // st5
  int *v80; // ebx
  int v81; // eax
  char *v82; // ecx
  char *v83; // edx
  char *v84; // ebx
  float *v85; // edi
  double v86; // st7
  bool v87; // cc
  int v88; // eax
  int v89; // ecx
  int *v90; // edi
  int *v91; // edx
  float *v92; // esi
  int *v93; // ebx
  double v94; // st6
  int *v95; // ebx
  char *v96; // edi
  float *v97; // ecx
  double v98; // rt2
  float *v99; // edx
  char *v100; // edx
  double v101; // st5
  char *v102; // eax
  long double v103; // st5
  bool v104; // pf
  double v105; // st5
  double v106; // rtt
  double v107; // st6
  double v108; // st7
  int v109; // eax
  int v110; // edi
  __int64 v111; // rax
  int v112; // edx
  int v113; // eax
  double v114; // rt0
  int v115; // eax
  double v116; // rt1
  char *v117; // edx
  double v118; // st5
  double v119; // st5
  int v120; // eax
  double v121; // st7
  float *v122; // eax
  int *v123; // eax
  int coupling_steps; // esi
  int v125; // ecx
  int *v126; // ecx
  int v127; // [esp+14h] [ebp-54h] BYREF
  int v128; // [esp+18h] [ebp-50h] BYREF
  int v129; // [esp+20h] [ebp-48h]
  float prepoint; // [esp+24h] [ebp-44h]
  int *iM; // [esp+28h] [ebp-40h]
  unsigned __int8 *dst; // [esp+2Ch] [ebp-3Ch]
  char *v133; // [esp+30h] [ebp-38h]
  int v134; // [esp+34h] [ebp-34h]
  char *v135; // [esp+38h] [ebp-30h]
  unsigned int count; // [esp+3Ch] [ebp-2Ch]
  int v137; // [esp+40h] [ebp-28h]
  int v138; // [esp+44h] [ebp-24h]
  float postpoint; // [esp+48h] [ebp-20h]
  float *acc; // [esp+4Ch] [ebp-1Ch]
  float **quant; // [esp+50h] [ebp-18h]
  int *nz; // [esp+54h] [ebp-14h]
  int limit; // [esp+58h] [ebp-10h]
  int n; // [esp+5Ch] [ebp-Ch]
  int v145; // [esp+60h] [ebp-8h]
  float *reA; // [esp+64h] [ebp-4h]
  float **raw; // [esp+68h] [ebp+0h]
  char *v148; // [esp+6Ch] [ebp+4h]
  int i; // [esp+70h] [ebp+8h]
  int partition; // [esp+74h] [ebp+Ch]
  int *flags; // [esp+78h] [ebp+10h]
  float **floor; // [esp+7Ch] [ebp+14h]
  float *q; // [esp+80h] [ebp+18h]
  int *fA; // [esp+84h] [ebp+1Ch]
  int v155; // [esp+88h] [ebp+20h]
  char *v156; // [esp+8Ch] [ebp+24h]
  int **flag; // [esp+90h] [ebp+28h]
  unsigned int v158; // [esp+94h] [ebp+2Ch]
  int step; // [esp+98h] [ebp+30h]
  int j; // [esp+9Ch] [ebp+34h]
  float *v161; // [esp+A0h] [ebp+38h]
  int *coupling_ang; // [esp+A4h] [ebp+3Ch]
  char *v163; // [esp+A8h] [ebp+40h]
  float *floorA; // [esp+ACh] [ebp+44h]
  float *v165; // [esp+B0h] [ebp+48h]
  float *qeA; // [esp+B4h] [ebp+4Ch]
  int B; // [esp+B8h] [ebp+50h]
  int jn; // [esp+BCh] [ebp+54h]
  float *f; // [esp+C0h] [ebp+58h]

  v9 = p->vi;
  v10 = v9->normal_p == 0;
  n = p->n;
  if ( v10 )
    partition = 16;
  else
    partition = v9->normal_partition;
  limit = g->coupling_pointlimit[v9->blockflag][blobno];
  v11 = g->coupling_prepointamp[blobno];
  v12 = 2 * g->coupling_postpointamp[blobno];
  prepoint = stereo_threshholds[v11];
  v12 *= 2;
  postpoint = *(double *)((char *)stereo_threshholds + 2 * v12);
  step = 2 * v12;
  v13 = alloca(4 * ch);
  raw = (float **)&v127;
  v14 = alloca(4 * ch);
  quant = (float **)&v127;
  v15 = alloca(4 * ch);
  v16 = (float **)&v127;
  floor = (float **)&v127;
  v17 = alloca(4 * ch);
  flag = (int **)&v127;
  v18 = alloca(4 * ch);
  v155 = vi->coupling_steps + ch;
  nz = &v127;
  v19 = alloca(4 * v155);
  acc = (float *)&v127;
  if ( n > 1000 )
    postpoint = *(double *)((char *)stereo_threshholds_limited + step);
  v20 = 4 * ch * partition;
  count = v20;
  v21 = alloca(v20);
  *raw = (float *)&v127;
  v22 = alloca(v20);
  v23 = alloca(v20);
  v127 = (int)&v127;
  v24 = alloca(v20);
  *flag = &v127;
  if ( ch > 1 )
  {
    q = 0;
    f = (float *)((char *)flag - (char *)&v127);
    v25 = 4 * partition;
    v26 = (char *)raw - (char *)&v127;
    flags = (int *)(4 * partition);
    v27 = &v128;
    step = (char *)raw - (char *)&v127;
    B = ch - 1;
    while ( 1 )
    {
      *(int *)((char *)v27 + v26) = (int)*raw + v25;
      v28 = q;
      *v27 = v25 + v127;
      *(int *)((char *)v27 + (_DWORD)v28) = v25 + v127;
      v29 = (char *)*flag + v25;
      v25 += (int)flags;
      *(int *)((char *)v27++ + (_DWORD)f) = (int)v29;
      --B;
      if ( *(float *)&B == 0.0 )
        break;
      v26 = step;
    }
  }
  if ( v155 > 0 )
    memset(acc, 0, 4 * v155);
  i = 0;
  if ( n > 0 )
  {
    dst = (unsigned __int8 *)*flag;
    v129 = -partition;
    v134 = sliding_lowpass - n;
    v158 = 0;
    v145 = n;
    v137 = limit - n;
    do
    {
      jn = v145;
      if ( partition <= v145 )
        jn = partition;
      v30 = 0;
      memcpy((unsigned __int8 *)nz, (unsigned __int8 *)nonzero, 4 * ch);
      memset((int)dst, 0, count);
      if ( ch <= 0 )
      {
        v86 = 0.0;
      }
      else
      {
        v31 = 1.0e-10;
        v32 = 0.0;
        q = (float *)((char *)iwork - (char *)nz);
        step = (char *)nz - (char *)mdct;
        v156 = (char *)((char *)mdct - (char *)v16);
        coupling_ang = (int *)((char *)raw - (char *)v16);
        v163 = (char *)((char *)quant - (char *)v16);
        v148 = (char *)((char *)flag - (char *)v16);
        fA = (int *)((char *)acc - (char *)v16);
        v33 = v16;
        v155 = ch;
        reA = (float *)ch;
        do
        {
          v34 = &v156[(_DWORD)v33 + step];
          v35 = (float *)(v158 + *(_DWORD *)((char *)q + (_DWORD)v34));
          v10 = *(_DWORD *)v34 == 0;
          floorA = v35;
          if ( v10 )
          {
            if ( jn > 0 )
            {
              v81 = *(int *)((char *)v33 + (_DWORD)coupling_ang);
              v82 = (char *)*v33 - v81;
              v83 = *(char **)((char *)v33 + (_DWORD)v163) - v81;
              v84 = *(char **)((char *)v33 + (_DWORD)v148) - v81;
              qeA = (float *)((char *)v35 - v81);
              floorA = (float *)jn;
              do
              {
                v85 = qeA;
                *(float *)&v82[v81] = v31;
                v81 += 4;
                v10 = floorA == (float *)1;
                floorA = (float *)((char *)floorA - 1);
                *(float *)(v81 - 4) = v32;
                *(float *)&v83[v81 - 4] = v32;
                *(_DWORD *)&v84[v81 - 4] = 0;
                *(float *)((char *)v85 + v81 - 4) = 0.0;
              }
              while ( !v10 );
            }
            *(float *)((char *)v33 + (_DWORD)fA) = v32;
          }
          else
          {
            v36 = 0;
            if ( jn >= 4 )
            {
              v37 = (int)(*v33 + 1);
              v38 = ((unsigned int)(jn - 4) >> 2) + 1;
              f = (float *)((char *)v35 - (char *)*v33);
              v39 = v35 + 3;
              j = 4 * v38;
              do
              {
                v40 = f;
                *(float *)(v37 - 4) = FLOOR1_fromdB_LOOKUP_0[*((_DWORD *)v39 - 3)];
                v41 = FLOOR1_fromdB_LOOKUP_0[*(_DWORD *)((char *)v40 + v37)];
                v37 += 16;
                *(float *)(v37 - 16) = v41;
                v42 = FLOOR1_fromdB_LOOKUP_0[*((_DWORD *)v39 - 1)];
                v39 += 4;
                --v38;
                *(float *)(v37 - 12) = v42;
                *(float *)(v37 - 8) = FLOOR1_fromdB_LOOKUP_0[*((_DWORD *)v39 - 4)];
              }
              while ( v38 );
              v36 = j;
            }
            if ( v36 < jn )
            {
              v43 = (int)&(*v33)[v36];
              v44 = (char *)((char *)v35 - (char *)*v33);
              v45 = jn - v36;
              do
              {
                v46 = *(_DWORD *)&v44[v43];
                v43 += 4;
                --v45;
                *(float *)(v43 - 4) = FLOOR1_fromdB_LOOKUP_0[v46];
              }
              while ( v45 );
            }
            v47 = *v33;
            f = (float *)((char *)v33 + (_DWORD)v156);
            flag_lossless(
              v47,
              *(char **)((char *)v33 + (_DWORD)v148),
              limit,
              prepoint,
              postpoint,
              &(*(float **)((char *)v33 + (_DWORD)v156))[v158 / 4],
              i,
              jn);
            v48 = 0;
            if ( jn < 4 )
            {
              v49 = -1.0;
              v51 = 0.0;
            }
            else
            {
              v49 = -1.0;
              v50 = *(_DWORD *)f;
              v51 = 0.0;
              v52 = *(int *)((char *)v33 + (_DWORD)coupling_ang);
              v53 = *(float **)((char *)v33 + (_DWORD)v163);
              v54 = v47 + 2;
              f = (float *)(*(_DWORD *)f + v158 + 8);
              v165 = (float *)(v50 + v158 + 4);
              v55 = *(int *)((char *)v33 + (_DWORD)coupling_ang);
              B = (int)v53 - v55;
              v56 = (int *)((char *)*v33 - v55);
              v161 = v53;
              v57 = (float *)(v52 + 4);
              v58 = ((unsigned int)(jn - 4) >> 2) + 1;
              qeA = (float *)((char *)v53 - (char *)*v33);
              flags = v56;
              v59 = f;
              j = 4 * v58;
              do
              {
                v60 = v161;
                *(float *)&f = *(v59 - 2) * *(v59 - 2);
                v61 = *(float *)&f;
                *(v57 - 1) = *(float *)&f;
                *v60 = v61;
                if ( *(v59 - 2) < 0.0 )
                  *(v57 - 1) = *(v57 - 1) * -1.0;
                v62 = v165;
                *(v54 - 2) = *(v54 - 2) * *(v54 - 2);
                v63 = *v62;
                v64 = B;
                *(float *)&f = v63 * v63;
                v65 = *(float *)&f;
                *v57 = *(float *)&f;
                *(float *)((char *)v57 + v64) = v65;
                if ( *v165 < 0.0 )
                  *v57 = *v57 * -1.0;
                *(float *)((char *)flags + (_DWORD)v57) = *(float *)((char *)flags + (_DWORD)v57)
                                                        * *(float *)((char *)flags + (_DWORD)v57);
                v66 = qeA;
                *(float *)&f = *v59 * *v59;
                v67 = *(float *)&f;
                v57[1] = *(float *)&f;
                *(float *)((char *)v66 + (_DWORD)v54) = v67;
                if ( *v59 < 0.0 )
                  v57[1] = v57[1] * -1.0;
                v68 = v161;
                *v54 = *v54 * *v54;
                *(float *)&f = v59[1] * v59[1];
                v69 = *(float *)&f;
                v57[2] = *(float *)&f;
                v68[3] = v69;
                if ( v59[1] < 0.0 )
                  v57[2] = v57[2] * -1.0;
                v70 = v54[1];
                v161 += 4;
                v165 += 4;
                v57 += 4;
                v59 += 4;
                v54[1] = v70 * v70;
                v54 += 4;
                --v58;
              }
              while ( v58 );
              v35 = floorA;
              v48 = j;
            }
            if ( v48 < jn )
            {
              v71 = *(int *)((char *)v33 + (_DWORD)coupling_ang);
              v72 = *v33;
              v165 = (float *)(*(_DWORD *)&v156[(_DWORD)v33] + 4 * (v48 + i));
              B = *(int *)((char *)v33 + (_DWORD)v163) - v71;
              v73 = (char *)v72 - v71;
              v74 = (float *)(v71 + 4 * v48);
              v75 = jn - v48;
              v76 = v165;
              do
              {
                v77 = B;
                *(float *)&qeA = *v76 * *v76;
                v78 = *(float *)&qeA;
                *v74 = *(float *)&qeA;
                *(float *)((char *)v74 + v77) = v78;
                if ( v51 > *v76 )
                  *v74 = *v74 * v49;
                ++v76;
                v79 = *(float *)&v73[(_DWORD)v74] * *(float *)&v73[(_DWORD)v74];
                ++v74;
                --v75;
                *(float *)&v73[(_DWORD)v74 - 4] = v79;
              }
              while ( v75 );
              v35 = floorA;
            }
            v80 = fA;
            *(float *)((char *)v33 + (_DWORD)v80) = noise_normalize(
                                                      p,
                                                      *(float **)((char *)v33 + (_DWORD)v163),
                                                      limit,
                                                      *(float **)((char *)v33 + (_DWORD)coupling_ang),
                                                      *v33,
                                                      0,
                                                      *(float *)((char *)v33 + (_DWORD)fA),
                                                      i,
                                                      jn,
                                                      (char *)v35);
            v31 = 1.0e-10;
            v32 = 0.0;
          }
          ++v33;
          --v155;
        }
        while ( v155 );
        v30 = reA;
        v86 = v32;
        v16 = floor;
      }
      v87 = vi->coupling_steps <= 0;
      step = 0;
      if ( !v87 )
      {
        v161 = &acc[(_DWORD)v30];
        coupling_ang = vi->coupling_ang;
        do
        {
          v88 = *(coupling_ang - 256);
          v89 = *coupling_ang;
          v90 = &iwork[v88][v158 / 4];
          v91 = &iwork[*coupling_ang][v158 / 4];
          v92 = raw[v88];
          reA = raw[*coupling_ang];
          q = quant[v88];
          qeA = quant[v89];
          f = floor[v88];
          floorA = floor[v89];
          flags = flag[v88];
          fA = flag[v89];
          v93 = nz;
          v10 = nz[v88] == 0;
          iM = v90;
          if ( v10 && !nz[v89] )
          {
            v16 = floor;
          }
          else
          {
            v87 = jn <= 0;
            nz[v89] = 1;
            v93[v88] = 1;
            j = 0;
            if ( !v87 )
            {
              v94 = 0.0;
              v138 = v145 + v134;
              v156 = (char *)((char *)reA - (char *)v92);
              v155 = (char *)qeA - (char *)v92;
              v163 = (char *)((char *)q - (char *)v92);
              v165 = (float *)((char *)fA - (char *)v92);
              reA = (float *)((char *)flags - (char *)v92);
              v133 = (char *)((char *)floorA - (char *)v92);
              v95 = (int *)((char *)v91 - (char *)v92);
              v96 = (char *)((char *)v90 - (char *)v92);
              v97 = v92;
              fA = (int *)((char *)v91 - (char *)v92);
              v148 = v96;
              v135 = (char *)((char *)f - (char *)v92);
              while ( 1 )
              {
                if ( j >= v138 )
                {
                  v116 = v94;
                  v107 = v86;
                  v108 = v116;
                }
                else
                {
                  v99 = reA;
                  if ( *(_DWORD *)((char *)v97 + (_DWORD)reA) || *(_DWORD *)((char *)v97 + (_DWORD)v165) )
                  {
                    v109 = v155;
                    *v97 = fabs(*(float *)((char *)v97 + (_DWORD)v156)) + fabs(*v97);
                    *(float *)((char *)v97 + (_DWORD)v163) = *(float *)((char *)v97 + v109)
                                                           + *(float *)((char *)v97 + (_DWORD)v163);
                    *(_DWORD *)((char *)v97 + (_DWORD)v165) = 1;
                    *(_DWORD *)((char *)v97 + (_DWORD)v99) = 1;
                    v110 = *(_DWORD *)((char *)v97 + (_DWORD)v96);
                    v111 = *(int *)((char *)v97 + (_DWORD)v95);
                    B = v111;
                    if ( (int)abs32(v110) <= (int)((HIDWORD(v111) ^ v111) - HIDWORD(v111)) )
                    {
                      v112 = B;
                      if ( B <= 0 )
                        v113 = B - v110;
                      else
                        v113 = v110 - B;
                      v95 = fA;
                      v96 = v148;
                      *(_DWORD *)((char *)v97 + (_DWORD)fA) = v113;
                      *(_DWORD *)((char *)v97 + (_DWORD)v96) = v112;
                    }
                    else
                    {
                      v95 = fA;
                      if ( v110 <= 0 )
                        *(_DWORD *)((char *)v97 + (_DWORD)fA) = B - v110;
                      else
                        *(_DWORD *)((char *)v97 + (_DWORD)fA) = v110 - B;
                      v96 = v148;
                    }
                    v114 = v94;
                    v107 = v86;
                    v108 = v114;
                    v115 = *(_DWORD *)((char *)v97 + (_DWORD)v96);
                    floorA = *(float **)((char *)v97 + (_DWORD)v95);
                    if ( (int)floorA >= (int)(2 * abs32(v115)) )
                    {
                      *(_DWORD *)((char *)v97 + (_DWORD)v95) = -(int)floorA;
                      *(_DWORD *)((char *)v97 + (_DWORD)v96) = -*(_DWORD *)((char *)v97 + (_DWORD)v96);
                    }
                  }
                  else
                  {
                    v100 = v156;
                    v101 = *(float *)((char *)v97 + (_DWORD)v156) + *v97;
                    if ( j >= v145 + v137 )
                    {
                      v104 = v101 >= v94;
                      *(float *)&B = fabs(*(float *)((char *)v97 + (_DWORD)v156)) + fabs(*v97);
                      v105 = *(float *)&B;
                      *(float *)((char *)v97 + (_DWORD)v163) = *(float *)&B;
                      if ( !v104 )
                        v105 = -v105;
                      *v97 = v105;
                    }
                    else
                    {
                      v102 = v163;
                      *(float *)&qeA = v101;
                      v103 = *(float *)&qeA;
                      *v97 = *(float *)&qeA;
                      *(float *)((char *)v97 + (_DWORD)v102) = fabs(v103);
                    }
                    v106 = v94;
                    v107 = v86;
                    v108 = v106;
                    *(float *)((char *)v97 + v155) = v107;
                    *(float *)((char *)v97 + (_DWORD)v100) = v107;
                    *(_DWORD *)((char *)v97 + (_DWORD)v165) = 1;
                    *(float *)((char *)v97 + (_DWORD)v95) = 0.0;
                  }
                }
                v117 = v135;
                v118 = *(float *)((char *)v97 + (_DWORD)v135) + *(float *)((char *)v97 + (_DWORD)v133);
                ++v97;
                *(float *)&qeA = v118;
                v119 = *(float *)&qeA;
                *(float *)((char *)v97 + (_DWORD)v133 - 4) = *(float *)&qeA;
                v120 = j + 1;
                *(float *)((char *)v97 + (_DWORD)v117 - 4) = v119;
                j = v120;
                if ( v120 >= jn )
                  break;
                v98 = v107;
                v94 = v108;
                v86 = v98;
              }
              v90 = iM;
            }
            v16 = floor;
            v121 = noise_normalize(p, q, limit, v92, f, (char *)flags, *v161, i, jn, (char *)v90);
            v122 = v161;
            *v161 = v121;
            v86 = 0.0;
            v161 = v122 + 1;
          }
          ++coupling_ang;
          v87 = ++step < vi->coupling_steps;
        }
        while ( v87 );
      }
      v145 += v129;
      v158 += 4 * partition;
      i += partition;
    }
    while ( i < n );
  }
  if ( vi->coupling_steps > 0 )
  {
    v123 = vi->coupling_ang;
    coupling_steps = vi->coupling_steps;
    do
    {
      v125 = *(v123 - 256);
      v10 = nonzero[v125] == 0;
      v126 = &nonzero[v125];
      if ( !v10 || nonzero[*v123] )
      {
        *v126 = 1;
        nonzero[*v123] = 1;
      }
      ++v123;
      --coupling_steps;
    }
    while ( coupling_steps );
  }
}
