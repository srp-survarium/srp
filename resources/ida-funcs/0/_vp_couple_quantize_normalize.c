void __usercall _vp_couple_quantize_normalize(
        int blobno@<edx>,
        vorbis_info_psy_global *g@<eax>,
        vorbis_look_psy *p,
        vorbis_info_mapping0 *vi,
        float **mdct,
        int **iwork,
        unsigned __int8 *nonzero,
        int sliding_lowpass,
        int ch)
{
  vorbis_info_psy *v9; // ecx
  bool v10; // zf
  int v11; // edi
  float v12; // xmm0_4
  int v13; // eax
  double v14; // xmm0_8
  void *v15; // esp
  void *v16; // esp
  char *v17; // ebx
  void *v18; // esp
  char *v19; // esi
  void *v20; // esp
  void *v21; // esp
  void *v22; // esp
  void *v23; // esp
  void *v24; // esp
  void *v25; // esp
  void *v26; // esp
  int *v27; // ecx
  int *v28; // eax
  float *v29; // edx
  float *v30; // ecx
  char *v31; // edx
  float **v32; // ebx
  float *v33; // eax
  char *v34; // edi
  float *v35; // eax
  unsigned int v36; // eax
  int v37; // esi
  _DWORD *v38; // edi
  float *v39; // esi
  float v40; // xmm0_4
  float v41; // xmm1_4
  float *v42; // esi
  float *v43; // eax
  int v44; // edi
  float v45; // xmm0_4
  float *v46; // edi
  float v47; // xmm0_4
  int v48; // xmm0_4
  char *v49; // eax
  int v50; // edi
  int *coupling_ang; // eax
  int v52; // edx
  unsigned int v53; // eax
  char *v54; // ecx
  int v55; // ecx
  int *v56; // edx
  int *v57; // edx
  unsigned __int8 *v58; // eax
  bool v59; // cc
  float *v60; // esi
  char *v61; // eax
  int v62; // eax
  int v63; // edi
  int v64; // ebx
  float *v65; // ecx
  char *v66; // edx
  char *v67; // edx
  float v68; // xmm1_4
  float v69; // xmm4_4
  float v70; // xmm1_4
  float v71; // xmm1_4
  float v72; // xmm3_4
  int v73; // eax
  float v74; // xmm1_4
  int v75; // ebx
  int *v76; // edi
  int v77; // eax
  float *v78; // edx
  int v79; // eax
  signed int v80; // eax
  float v81; // xmm1_4
  float v82; // xmm1_4
  _DWORD *v83; // ebx
  int v84; // xmm0_4
  int *v85; // eax
  int coupling_steps; // edi
  unsigned __int8 *v87; // ecx
  int v88; // [esp+Ch] [ebp-4Ch] BYREF
  int v89; // [esp+10h] [ebp-48h] BYREF
  int v90; // [esp+18h] [ebp-40h]
  int v91; // [esp+1Ch] [ebp-3Ch]
  char *v92; // [esp+20h] [ebp-38h]
  int v93; // [esp+24h] [ebp-34h]
  int v94; // [esp+28h] [ebp-30h]
  char *v95; // [esp+2Ch] [ebp-2Ch]
  float v96; // [esp+30h] [ebp-28h]
  int v97; // [esp+34h] [ebp-24h]
  float v98; // [esp+38h] [ebp-20h]
  char *v99; // [esp+3Ch] [ebp-1Ch]
  char *v100; // [esp+40h] [ebp-18h]
  unsigned __int8 *dst; // [esp+44h] [ebp-14h]
  int v102; // [esp+48h] [ebp-10h]
  char *v103; // [esp+4Ch] [ebp-Ch]
  int n; // [esp+50h] [ebp-8h]
  float *v105; // [esp+54h] [ebp-4h]
  unsigned int count; // [esp+58h] [ebp+0h]
  char *v107; // [esp+5Ch] [ebp+4h]
  char *v108; // [esp+60h] [ebp+8h]
  int v109; // [esp+64h] [ebp+Ch]
  int *i; // [esp+68h] [ebp+10h]
  char *v111; // [esp+6Ch] [ebp+14h]
  char *v112; // [esp+70h] [ebp+18h]
  int *v113; // [esp+74h] [ebp+1Ch]
  int v114; // [esp+78h] [ebp+20h]
  int v115; // [esp+7Ch] [ebp+24h]
  int normal_partition; // [esp+80h] [ebp+28h]
  int v117; // [esp+84h] [ebp+2Ch]
  int v118; // [esp+88h] [ebp+30h]
  float *v119; // [esp+8Ch] [ebp+34h]
  int v120; // [esp+90h] [ebp+38h]
  int v121; // [esp+94h] [ebp+3Ch]
  int v122; // [esp+98h] [ebp+40h]
  char *v123; // [esp+9Ch] [ebp+44h]
  unsigned int v124; // [esp+A0h] [ebp+48h]
  float *v125; // [esp+A4h] [ebp+4Ch]
  int v126; // [esp+A8h] [ebp+50h]
  float *v127; // [esp+ACh] [ebp+54h]
  int v128; // [esp+B0h] [ebp+58h]

  v9 = p->vi;
  v10 = v9->normal_p == 0;
  n = p->n;
  if ( v10 )
    normal_partition = 16;
  else
    normal_partition = v9->normal_partition;
  v11 = ch;
  v102 = g->coupling_pointlimit[v9->blockflag][blobno];
  v12 = stereo_threshholds[g->coupling_prepointamp[blobno]];
  v13 = g->coupling_postpointamp[blobno];
  v96 = v12;
  v14 = stereo_threshholds[v13];
  v119 = (float *)(v13 * 8);
  v98 = v14;
  v15 = alloca(4 * ch);
  v111 = (char *)&v88;
  v16 = alloca(4 * ch);
  v17 = (char *)&v88;
  v100 = (char *)&v88;
  v18 = alloca(4 * ch);
  v19 = (char *)&v88;
  v99 = (char *)&v88;
  v20 = alloca(4 * ch);
  v113 = &v88;
  v21 = alloca(4 * ch);
  v120 = ch + vi->coupling_steps;
  dst = (unsigned __int8 *)&v88;
  v22 = alloca(4 * v120);
  v103 = (char *)&v88;
  if ( n > 1000 )
    v98 = *(double *)((char *)stereo_threshholds_limited + (_DWORD)v119);
  count = 4 * ch * normal_partition;
  v23 = alloca(count);
  *(_DWORD *)v111 = &v88;
  v24 = alloca(count);
  v25 = alloca(count);
  v88 = (int)&v88;
  v26 = alloca(count);
  v27 = v113;
  *v113 = (int)&v88;
  if ( ch > 1 )
  {
    v127 = 0;
    v123 = (char *)((char *)v27 - (char *)&v88);
    v124 = 4 * normal_partition;
    v28 = &v89;
    v119 = (float *)(v111 - (char *)&v88);
    v126 = ch - 1;
    do
    {
      *(int *)((char *)v28 + (_DWORD)v119) = v124 + *(_DWORD *)v111;
      v29 = v127;
      *v28 = v124 + v88;
      *(int *)((char *)v28 + (_DWORD)v29) = v124 + v88;
      *(int *)((char *)v28 + (_DWORD)v123) = v124 + *v113;
      v124 += 4 * normal_partition;
      ++v28;
      --v126;
    }
    while ( v126 );
  }
  if ( v120 > 0 )
  {
    memset(v103, 0, 4 * v120);
    v11 = ch;
  }
  v109 = 0;
  if ( n > 0 )
  {
    v124 = 0;
    v90 = -normal_partition;
    v91 = sliding_lowpass - n;
    v114 = n;
    v97 = v102 - n;
    do
    {
      v122 = v114;
      if ( normal_partition <= v114 )
        v122 = normal_partition;
      v117 = 0;
      memcpy(dst, nonzero, 4 * v11);
      memset(*v113, 0, count);
      if ( v11 > 0 )
      {
        v119 = (float *)((char *)iwork - (char *)dst);
        v127 = (float *)((char *)mdct - v19);
        v123 = (char *)(dst - (unsigned __int8 *)mdct);
        v107 = (char *)((char *)v113 - v19);
        v30 = (float *)(v111 - v19);
        v31 = (char *)(v100 - v19);
        v125 = (float *)(v103 - v19);
        v32 = (float **)v19;
        v105 = (float *)(v111 - v19);
        v108 = (char *)(v100 - v19);
        v115 = ch;
        v117 = ch;
        do
        {
          i = (int *)((int)v127 + (_DWORD)v32);
          v33 = (float *)&v123[(int)v127 + (_DWORD)v32];
          v34 = (char *)(v124 + *(_DWORD *)((char *)v119 + (_DWORD)v33));
          v10 = *(_DWORD *)v33 == 0;
          v120 = (int)v33;
          v118 = (int)v34;
          if ( v10 )
          {
            if ( v122 > 0 )
            {
              v49 = *(char **)((char *)v32 + (_DWORD)v30);
              v128 = (char *)*v32 - v49;
              v121 = *(char **)((char *)v32 + (_DWORD)v31) - v49;
              v120 = *(char **)((char *)v32 + (_DWORD)v107) - v49;
              v112 = (char *)(v118 - (_DWORD)v49);
              v118 = v122;
              do
              {
                *(float *)&v49[v128] = FLOAT_1_0eN10;
                v50 = v121;
                *(_DWORD *)v49 = 0;
                *(_DWORD *)&v49[v50] = 0;
                *(_DWORD *)&v49[v120] = 0;
                *(_DWORD *)&v49[(_DWORD)v112] = 0;
                v49 += 4;
                --v118;
              }
              while ( v118 );
            }
            *(float **)((char *)v32 + (_DWORD)v125) = 0;
          }
          else
          {
            if ( v122 > 0 )
            {
              v35 = *v32;
              v128 = v34 - (char *)*v32;
              v126 = v122;
              do
              {
                *v35 = FLOOR1_fromdB_LOOKUP_0[*(_DWORD *)((char *)v35 + v128)];
                ++v35;
                --v126;
              }
              while ( v126 );
            }
            v36 = v124 + *i;
            v37 = *(int *)((char *)v32 + (_DWORD)v107);
            v128 = 0;
            v126 = v37;
            if ( v122 > 0 )
            {
              v38 = (_DWORD *)v126;
              v120 = v114 + v97;
              v39 = *v32;
              v121 = v36 - (_DWORD)*v32;
              v112 = (char *)v39 - v126;
              do
              {
                if ( v128 < v120 )
                  v40 = v96;
                else
                  v40 = v98;
                v41 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(*(float *)((char *)v38 + (_DWORD)v112 + v121)) & _mask__AbsDouble_)
                    / *(float *)((char *)v38 + (_DWORD)v112);
                *v38 = v40 <= v41;
                ++v128;
                ++v38;
              }
              while ( v128 < v122 );
              v42 = *(float **)((char *)v32 + (_DWORD)v30);
              v43 = (float *)(v124 + *i);
              v121 = *(char **)((char *)v32 + (_DWORD)v31) - (char *)v42;
              v128 = (int)*v32;
              v128 -= (int)v42;
              v126 = v122;
              do
              {
                v44 = v121;
                v45 = *v43 * *v43;
                *v42 = v45;
                *(float *)((char *)v42 + v44) = v45;
                if ( *v43 < 0.0 )
                  *v42 = *v42 * -1.0;
                v46 = (float *)((char *)v42 + v128);
                v47 = *(float *)((char *)v42 + v128);
                ++v43;
                ++v42;
                v10 = v126-- == 1;
                *v46 = v47 * v47;
              }
              while ( !v10 );
              v34 = (char *)v118;
            }
            v48 = noise_normalize(
                    p,
                    *(float **)((char *)v32 + (_DWORD)v31),
                    v34,
                    v102,
                    *(float **)((char *)v32 + (_DWORD)v30),
                    *v32,
                    0,
                    *(float *)((char *)v32 + (_DWORD)v125),
                    v109,
                    v122);
            v19 = v99;
            v30 = v105;
            v31 = v108;
            *(float **)((char *)v32 + (_DWORD)v125) = (float *)v48;
          }
          ++v32;
          --v115;
        }
        while ( v115 );
        v17 = v100;
        v11 = ch;
      }
      v126 = 0;
      if ( vi->coupling_steps > 0 )
      {
        coupling_ang = vi->coupling_ang;
        v119 = (float *)&v103[4 * v117];
        for ( i = vi->coupling_ang; ; coupling_ang = i )
        {
          v52 = *coupling_ang;
          v53 = 4 * *(coupling_ang - 256);
          v54 = (char *)&iwork[v53 / 4][v124 / 4];
          v117 = *(_DWORD *)&v111[v53];
          v112 = v54;
          v55 = 4 * v52;
          v56 = iwork[v52];
          v108 = *(char **)&v111[v55];
          v57 = &v56[v124 / 4];
          v120 = *(_DWORD *)&v17[v53];
          v115 = *(_DWORD *)&v17[v55];
          v105 = *(float **)&v19[v53];
          v127 = *(float **)&v19[v55];
          v107 = (char *)v113[v53 / 4];
          v125 = (float *)v113[v55 / 4u];
          v58 = &dst[v53];
          if ( *(_DWORD *)v58 || *(_DWORD *)&dst[v55] )
          {
            v128 = 0;
            v59 = v122 <= 0;
            *(_DWORD *)&dst[v55] = 1;
            *(_DWORD *)v58 = 1;
            v60 = (float *)v117;
            if ( !v59 )
            {
              v93 = v114 + v91;
              v61 = v108;
              v108 = &v107[-v117];
              v117 = v115 - v117;
              v95 = (char *)(v112 - (char *)v60);
              v123 = (char *)(v120 - (_DWORD)v60);
              v94 = (char *)v127 - (char *)v60;
              v62 = v61 - (char *)v60;
              v63 = (char *)v125 - (char *)v60;
              v64 = (char *)v57 - (char *)v60;
              v65 = v60;
              v118 = v62;
              v121 = (char *)v125 - (char *)v60;
              v115 = (char *)v57 - (char *)v60;
              v92 = (char *)((char *)v105 - (char *)v60);
              do
              {
                if ( v128 < v93 )
                {
                  v66 = &v108[(_DWORD)v65];
                  if ( *(_DWORD *)&v108[(_DWORD)v65] || *(_DWORD *)((char *)v65 + v63) )
                  {
                    v71 = *(float *)((char *)v65 + v62);
                    v72 = *v65;
                    v125 = (float *)&v123[(_DWORD)v65];
                    v73 = v117;
                    v74 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v71) & _mask__AbsDouble_)
                        + COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v72) & _mask__AbsDouble_);
                    *v65 = v74;
                    *v125 = *(float *)((char *)v65 + v73) + *v125;
                    *(_DWORD *)((char *)v65 + v63) = 1;
                    *(_DWORD *)v66 = 1;
                    v75 = *(_DWORD *)((char *)v65 + v64);
                    v76 = (int *)((int)v65 + (_DWORD)v95);
                    v127 = *(float **)((char *)v65 + (_DWORD)v95);
                    v125 = (float *)v75;
                    if ( (int)abs32((int)v127) <= (int)abs32(v75) )
                    {
                      v78 = v125;
                      if ( (int)v125 <= 0 )
                        v79 = (char *)v125 - (char *)v127;
                      else
                        v79 = (char *)v127 - (char *)v125;
                      v64 = v115;
                      *(_DWORD *)((char *)v65 + v115) = v79;
                      *v76 = (int)v78;
                    }
                    else
                    {
                      if ( (int)v127 <= 0 )
                        v77 = (char *)v125 - (char *)v127;
                      else
                        v77 = (char *)v127 - (char *)v125;
                      v64 = v115;
                      *(_DWORD *)((char *)v65 + v115) = v77;
                    }
                    v80 = *(_DWORD *)((char *)v65 + v64);
                    if ( v80 >= (int)(2 * abs32(*v76)) )
                    {
                      *(_DWORD *)((char *)v65 + v64) = -v80;
                      *v76 = -*v76;
                    }
                    v62 = v118;
                    v63 = v121;
                  }
                  else
                  {
                    v67 = v123;
                    if ( v128 >= v114 + v97 )
                    {
                      v69 = *(float *)((char *)v65 + v62) + *v65;
                      v70 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(*(float *)((char *)v65 + v62)) & _mask__AbsDouble_)
                          + COERCE_DOUBLE(COERCE_UNSIGNED_INT64(*v65) & _mask__AbsDouble_);
                      *(float *)((char *)v65 + (_DWORD)v123) = v70;
                      if ( v69 < 0.0 )
                        LODWORD(v70) ^= _mask__NegFloat_;
                      *v65 = v70;
                    }
                    else
                    {
                      v68 = *v65 + *(float *)((char *)v65 + v62);
                      *v65 = v68;
                      *(_DWORD *)((char *)v65 + (_DWORD)v67) = LODWORD(v68) & _mask__AbsFloat_;
                    }
                    v63 = v121;
                    *(float *)((char *)v65 + v117) = 0.0;
                    *(float *)((char *)v65 + v62) = 0.0;
                    *(_DWORD *)((char *)v65 + v63) = 1;
                    *(float *)((char *)v65 + v64) = 0.0;
                  }
                }
                v125 = (float *)((char *)v65 + v94);
                v81 = *(float *)&v92[(_DWORD)v65];
                ++v128;
                v127 = (float *)&v92[(_DWORD)v65];
                v82 = v81 + *(float *)((char *)v65 + v94);
                *(float *)((char *)v65 + v94) = v82;
                *v127 = v82;
                ++v65;
              }
              while ( v128 < v122 );
            }
            v83 = v119;
            v84 = noise_normalize(p, (float *)v120, v112, v102, v60, v105, v107, *v119, v109, v122);
            v19 = v99;
            *v83 = v84;
            v119 = (float *)(v83 + 1);
            v17 = v100;
          }
          ++v126;
          ++i;
          if ( v126 >= vi->coupling_steps )
            break;
        }
        v11 = ch;
      }
      v109 += normal_partition;
      v124 += 4 * normal_partition;
      v114 += v90;
    }
    while ( v109 < n );
  }
  if ( vi->coupling_steps > 0 )
  {
    v85 = vi->coupling_ang;
    coupling_steps = vi->coupling_steps;
    do
    {
      v87 = &nonzero[4 * *(v85 - 256)];
      if ( *(_DWORD *)v87 || *(_DWORD *)&nonzero[4 * *v85] )
      {
        *(_DWORD *)v87 = 1;
        *(_DWORD *)&nonzero[4 * *v85] = 1;
      }
      ++v85;
      --coupling_steps;
    }
    while ( coupling_steps );
  }
}
