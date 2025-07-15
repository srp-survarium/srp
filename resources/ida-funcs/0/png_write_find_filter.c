char __cdecl png_write_find_filter(int a1, int a2)
{
  char result; // al
  int v3; // [esp+4h] [ebp-1E8h]
  char v4; // [esp+8h] [ebp-1E4h]
  char v5; // [esp+Ch] [ebp-1E0h]
  int v6; // [esp+10h] [ebp-1DCh]
  int v7; // [esp+14h] [ebp-1D8h]
  int v8; // [esp+18h] [ebp-1D4h]
  int v9; // [esp+1Ch] [ebp-1D0h]
  char v10; // [esp+20h] [ebp-1CCh]
  char v11; // [esp+24h] [ebp-1C8h]
  int v12; // [esp+28h] [ebp-1C4h]
  int v13; // [esp+2Ch] [ebp-1C0h]
  int v14; // [esp+30h] [ebp-1BCh]
  int v15; // [esp+34h] [ebp-1B8h]
  int v16; // [esp+38h] [ebp-1B4h]
  int v17; // [esp+3Ch] [ebp-1B0h]
  int v18; // [esp+40h] [ebp-1ACh]
  int v19; // [esp+44h] [ebp-1A8h]
  int v20; // [esp+48h] [ebp-1A4h]
  int i1; // [esp+4Ch] [ebp-1A0h]
  int nn; // [esp+50h] [ebp-19Ch]
  unsigned int v23; // [esp+54h] [ebp-198h]
  unsigned int v24; // [esp+54h] [ebp-198h]
  unsigned int v25; // [esp+58h] [ebp-194h]
  unsigned int v26; // [esp+58h] [ebp-194h]
  int v27; // [esp+5Ch] [ebp-190h]
  int v28; // [esp+64h] [ebp-188h]
  int v29; // [esp+6Ch] [ebp-180h]
  int v30; // [esp+70h] [ebp-17Ch]
  int v31; // [esp+74h] [ebp-178h]
  int mm; // [esp+78h] [ebp-174h]
  unsigned int v33; // [esp+7Ch] [ebp-170h]
  unsigned int v34; // [esp+7Ch] [ebp-170h]
  unsigned int v35; // [esp+80h] [ebp-16Ch]
  unsigned int v36; // [esp+80h] [ebp-16Ch]
  unsigned __int8 *v37; // [esp+84h] [ebp-168h]
  unsigned int v38; // [esp+88h] [ebp-164h]
  _BYTE *v39; // [esp+8Ch] [ebp-160h]
  _BYTE *v40; // [esp+90h] [ebp-15Ch]
  _BYTE *v41; // [esp+94h] [ebp-158h]
  unsigned int v42; // [esp+98h] [ebp-154h]
  unsigned int v43; // [esp+9Ch] [ebp-150h]
  unsigned __int8 *v44; // [esp+A0h] [ebp-14Ch]
  int v45; // [esp+A4h] [ebp-148h]
  int v46; // [esp+A4h] [ebp-148h]
  int v47; // [esp+A8h] [ebp-144h]
  int v48; // [esp+B0h] [ebp-13Ch]
  int v49; // [esp+B8h] [ebp-134h]
  int v50; // [esp+BCh] [ebp-130h]
  int v51; // [esp+C0h] [ebp-12Ch]
  unsigned __int8 *v52; // [esp+C4h] [ebp-128h]
  _BYTE *v53; // [esp+C8h] [ebp-124h]
  _BYTE *v54; // [esp+CCh] [ebp-120h]
  _BYTE *v55; // [esp+D0h] [ebp-11Ch]
  unsigned int v56; // [esp+D4h] [ebp-118h]
  unsigned __int8 *v57; // [esp+D8h] [ebp-114h]
  int kk; // [esp+DCh] [ebp-110h]
  unsigned int v59; // [esp+E0h] [ebp-10Ch]
  unsigned int v60; // [esp+E0h] [ebp-10Ch]
  unsigned int v61; // [esp+E4h] [ebp-108h]
  unsigned int v62; // [esp+E4h] [ebp-108h]
  int jj; // [esp+E8h] [ebp-104h]
  unsigned int v64; // [esp+ECh] [ebp-100h]
  unsigned int v65; // [esp+ECh] [ebp-100h]
  unsigned int v66; // [esp+F0h] [ebp-FCh]
  unsigned int v67; // [esp+F0h] [ebp-FCh]
  unsigned __int8 *v68; // [esp+F4h] [ebp-F8h]
  unsigned int v69; // [esp+F8h] [ebp-F4h]
  _BYTE *v70; // [esp+FCh] [ebp-F0h]
  _BYTE *v71; // [esp+100h] [ebp-ECh]
  unsigned __int8 *v72; // [esp+104h] [ebp-E8h]
  unsigned int v73; // [esp+108h] [ebp-E4h]
  unsigned int v74; // [esp+10Ch] [ebp-E0h]
  int v75; // [esp+110h] [ebp-DCh]
  int v76; // [esp+110h] [ebp-DCh]
  unsigned __int8 *v77; // [esp+114h] [ebp-D8h]
  _BYTE *v78; // [esp+118h] [ebp-D4h]
  _BYTE *v79; // [esp+11Ch] [ebp-D0h]
  unsigned __int8 *v80; // [esp+120h] [ebp-CCh]
  unsigned int v81; // [esp+124h] [ebp-C8h]
  int ii; // [esp+128h] [ebp-C4h]
  unsigned int v83; // [esp+12Ch] [ebp-C0h]
  unsigned int v84; // [esp+12Ch] [ebp-C0h]
  unsigned int v85; // [esp+130h] [ebp-BCh]
  unsigned int v86; // [esp+130h] [ebp-BCh]
  int n; // [esp+134h] [ebp-B8h]
  unsigned int v88; // [esp+138h] [ebp-B4h]
  unsigned int v89; // [esp+138h] [ebp-B4h]
  unsigned int v90; // [esp+13Ch] [ebp-B0h]
  unsigned int v91; // [esp+13Ch] [ebp-B0h]
  unsigned int v92; // [esp+140h] [ebp-ACh]
  _BYTE *v93; // [esp+144h] [ebp-A8h]
  _BYTE *v94; // [esp+148h] [ebp-A4h]
  _BYTE *v95; // [esp+14Ch] [ebp-A0h]
  unsigned int v96; // [esp+150h] [ebp-9Ch]
  unsigned int v97; // [esp+154h] [ebp-98h]
  int v98; // [esp+158h] [ebp-94h]
  _BYTE *v99; // [esp+15Ch] [ebp-90h]
  _BYTE *v100; // [esp+160h] [ebp-8Ch]
  _BYTE *v101; // [esp+164h] [ebp-88h]
  unsigned int v102; // [esp+168h] [ebp-84h]
  int m; // [esp+16Ch] [ebp-80h]
  unsigned int v104; // [esp+170h] [ebp-7Ch]
  unsigned int v105; // [esp+170h] [ebp-7Ch]
  unsigned int v106; // [esp+174h] [ebp-78h]
  unsigned int v107; // [esp+174h] [ebp-78h]
  int j; // [esp+178h] [ebp-74h]
  unsigned int v109; // [esp+17Ch] [ebp-70h]
  unsigned int v110; // [esp+17Ch] [ebp-70h]
  unsigned int v111; // [esp+180h] [ebp-6Ch]
  unsigned int v112; // [esp+180h] [ebp-6Ch]
  _BYTE *k; // [esp+184h] [ebp-68h]
  unsigned int v114; // [esp+188h] [ebp-64h]
  _BYTE *v115; // [esp+18Ch] [ebp-60h]
  _BYTE *v116; // [esp+190h] [ebp-5Ch]
  unsigned int v117; // [esp+194h] [ebp-58h]
  unsigned int v118; // [esp+198h] [ebp-54h]
  _BYTE *v119; // [esp+1A0h] [ebp-4Ch]
  _BYTE *v120; // [esp+1A4h] [ebp-48h]
  _BYTE *v121; // [esp+1A8h] [ebp-44h]
  unsigned int v122; // [esp+1ACh] [ebp-40h]
  int i; // [esp+1B0h] [ebp-3Ch]
  unsigned int v124; // [esp+1B4h] [ebp-38h]
  unsigned int v125; // [esp+1B4h] [ebp-38h]
  unsigned int v126; // [esp+1B8h] [ebp-34h]
  unsigned int v127; // [esp+1B8h] [ebp-34h]
  unsigned int v128; // [esp+1BCh] [ebp-30h]
  unsigned __int8 *v129; // [esp+1C0h] [ebp-2Ch]
  unsigned int v130; // [esp+1C4h] [ebp-28h]
  _BYTE *v131; // [esp+1CCh] [ebp-20h]
  unsigned int v132; // [esp+1D0h] [ebp-1Ch]
  int v133; // [esp+1D4h] [ebp-18h]
  unsigned __int8 v134; // [esp+1DBh] [ebp-11h]
  unsigned int v135; // [esp+1DCh] [ebp-10h]
  _BYTE *v136; // [esp+1E0h] [ebp-Ch]
  int v137; // [esp+1E4h] [ebp-8h]
  unsigned int v138; // [esp+1E8h] [ebp-4h]

  v134 = *(_BYTE *)(a1 + 314);
  v135 = *(_DWORD *)(a2 + 4);
  v137 = *(unsigned __int8 *)(a1 + 517);
  v138 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
  v133 = *(_DWORD *)(a1 + 260);
  v136 = *(_BYTE **)(a1 + 264);
  v131 = v136;
  v132 = 0x7FFFFFFF;
  if ( (v134 & 8) != 0 && v134 != 8 )
  {
    v128 = 0;
    v130 = 0;
    v129 = v136 + 1;
    while ( v130 < v135 )
    {
      if ( *v129 >= 0x80u )
        v20 = 256 - *v129;
      else
        v20 = *v129;
      v128 += v20;
      ++v130;
      ++v129;
    }
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v124 = (unsigned __int16)v128;
      v126 = (v128 >> 10) & 0x3FFFC0;
      for ( i = 0; i < v137; ++i )
      {
        if ( !*(_BYTE *)(*(_DWORD *)(a1 + 520) + i) )
        {
          v124 = (v124 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * i)) >> 8;
          v126 = (v126 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * i)) >> 8;
        }
      }
      v125 = (v124 * **(unsigned __int16 **)(a1 + 532)) >> 3;
      v127 = (v126 * **(unsigned __int16 **)(a1 + 532)) >> 3;
      if ( v127 <= 0x3FFFC0 )
        v128 = v125 + (v127 << 10);
      else
        v128 = 0x7FFFFFFF;
    }
    v132 = v128;
  }
  if ( v134 == 16 )
  {
    v122 = 0;
    v120 = v136 + 1;
    v121 = (_BYTE *)(*(_DWORD *)(a1 + 268) + 1);
    while ( v122 < v138 )
    {
      *v121 = *v120;
      ++v122;
      ++v120;
      ++v121;
    }
    v119 = v136 + 1;
    while ( v122 < v135 )
    {
      *v121 = *v120 - *v119;
      ++v122;
      ++v120;
      ++v119;
      ++v121;
    }
    v136 = *(_BYTE **)(a1 + 268);
  }
  else if ( (v134 & 0x10) != 0 )
  {
    v114 = 0;
    v117 = v132;
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v111 = (unsigned __int16)v132;
      v109 = (v132 >> 10) & 0x3FFFC0;
      for ( j = 0; j < v137; ++j )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + j) == 1 )
        {
          v111 = (v111 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * j)) >> 8;
          v109 = (v109 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * j)) >> 8;
        }
      }
      v112 = (v111 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 2)) >> 3;
      v110 = (v109 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 2)) >> 3;
      if ( v110 <= 0x3FFFC0 )
        v117 = v112 + (v110 << 10);
      else
        v117 = 0x7FFFFFFF;
    }
    v118 = 0;
    v115 = v136 + 1;
    v116 = (_BYTE *)(*(_DWORD *)(a1 + 268) + 1);
    while ( v118 < v138 )
    {
      *v116 = *v115;
      if ( (unsigned __int8)*v116 >= 0x80u )
        v19 = 256 - (unsigned __int8)*v116;
      else
        v19 = (unsigned __int8)*v116;
      v114 += v19;
      ++v118;
      ++v115;
      ++v116;
    }
    for ( k = v136 + 1; v118 < v135; ++k )
    {
      *v116 = *v115 - *k;
      v18 = (unsigned __int8)*v116 >= 0x80u ? 256 - (unsigned __int8)*v116 : (unsigned __int8)*v116;
      v114 += v18;
      if ( v114 > v117 )
        break;
      ++v118;
      ++v115;
      ++v116;
    }
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v104 = (unsigned __int16)v114;
      v106 = (v114 >> 10) & 0x3FFFC0;
      for ( m = 0; m < v137; ++m )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + m) == 1 )
        {
          v104 = (v104 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * m)) >> 8;
          v106 = (v106 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * m)) >> 8;
        }
      }
      v105 = (v104 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 2)) >> 3;
      v107 = (v106 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 2)) >> 3;
      if ( v107 <= 0x3FFFC0 )
        v114 = v105 + (v107 << 10);
      else
        v114 = 0x7FFFFFFF;
    }
    if ( v114 < v132 )
    {
      v132 = v114;
      v136 = *(_BYTE **)(a1 + 268);
    }
  }
  if ( v134 == 32 )
  {
    v102 = 0;
    v99 = v131 + 1;
    v100 = (_BYTE *)(*(_DWORD *)(a1 + 272) + 1);
    v101 = (_BYTE *)(v133 + 1);
    while ( v102 < v135 )
    {
      *v100 = *v99 - *v101;
      ++v102;
      ++v99;
      ++v101;
      ++v100;
    }
    v136 = *(_BYTE **)(a1 + 272);
  }
  else if ( (v134 & 0x20) != 0 )
  {
    v92 = 0;
    v96 = v132;
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v90 = (unsigned __int16)v132;
      v88 = (v132 >> 10) & 0x3FFFC0;
      for ( n = 0; n < v137; ++n )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + n) == 2 )
        {
          v90 = (v90 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * n)) >> 8;
          v88 = (v88 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * n)) >> 8;
        }
      }
      v91 = (v90 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 4)) >> 3;
      v89 = (v88 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 4)) >> 3;
      if ( v89 <= 0x3FFFC0 )
        v96 = v91 + (v89 << 10);
      else
        v96 = 0x7FFFFFFF;
    }
    v97 = 0;
    v93 = v131 + 1;
    v94 = (_BYTE *)(*(_DWORD *)(a1 + 272) + 1);
    v95 = (_BYTE *)(v133 + 1);
    while ( v97 < v135 )
    {
      *v94 = *v93 - *v95;
      v98 = (unsigned __int8)*v94++;
      ++v95;
      ++v93;
      v17 = v98 >= 128 ? 256 - v98 : v98;
      v92 += v17;
      if ( v92 > v96 )
        break;
      ++v97;
    }
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v83 = (unsigned __int16)v92;
      v85 = (v92 >> 10) & 0x3FFFC0;
      for ( ii = 0; ii < v137; ++ii )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + ii) == 2 )
        {
          v83 = (v83 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * ii)) >> 8;
          v85 = (v85 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * ii)) >> 8;
        }
      }
      v84 = (v83 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 4)) >> 3;
      v86 = (v85 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 4)) >> 3;
      if ( v86 <= 0x3FFFC0 )
        v92 = v84 + (v86 << 10);
      else
        v92 = 0x7FFFFFFF;
    }
    if ( v92 < v132 )
    {
      v132 = v92;
      v136 = *(_BYTE **)(a1 + 272);
    }
  }
  if ( v134 == 64 )
  {
    v81 = 0;
    v78 = v131 + 1;
    v79 = (_BYTE *)(*(_DWORD *)(a1 + 276) + 1);
    v80 = (unsigned __int8 *)(v133 + 1);
    while ( v81 < v138 )
    {
      *v79++ = *v78++ - *v80++ / 2;
      ++v81;
    }
    v77 = v131 + 1;
    while ( v81 < v135 )
    {
      *v79++ = *v78++ - (*v77++ + *v80++) / 2;
      ++v81;
    }
    v136 = *(_BYTE **)(a1 + 276);
  }
  else if ( (v134 & 0x40) != 0 )
  {
    v69 = 0;
    v73 = v132;
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v66 = (unsigned __int16)v132;
      v64 = (v132 >> 10) & 0x3FFFC0;
      for ( jj = 0; jj < v137; ++jj )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + jj) == 3 )
        {
          v66 = (v66 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * jj)) >> 8;
          v64 = (v64 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * jj)) >> 8;
        }
      }
      v67 = (v66 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 6)) >> 3;
      v65 = (v64 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 6)) >> 3;
      if ( v65 <= 0x3FFFC0 )
        v73 = v67 + (v65 << 10);
      else
        v73 = 0x7FFFFFFF;
    }
    v74 = 0;
    v70 = v131 + 1;
    v71 = (_BYTE *)(*(_DWORD *)(a1 + 276) + 1);
    v72 = (unsigned __int8 *)(v133 + 1);
    while ( v74 < v138 )
    {
      *v71 = *v70 - *v72 / 2;
      v75 = (unsigned __int8)*v71++;
      ++v72;
      ++v70;
      if ( v75 >= 128 )
        v16 = 256 - v75;
      else
        v16 = v75;
      v69 += v16;
      ++v74;
    }
    v68 = v131 + 1;
    while ( v74 < v135 )
    {
      *v71 = *v70 - (*v68 + *v72) / 2;
      v76 = (unsigned __int8)*v71++;
      ++v68;
      ++v72;
      ++v70;
      v15 = v76 >= 128 ? 256 - v76 : v76;
      v69 += v15;
      if ( v69 > v73 )
        break;
      ++v74;
    }
    if ( *(_BYTE *)(a1 + 516) == 2 )
    {
      v59 = (unsigned __int16)v69;
      v61 = (v69 >> 10) & 0x3FFFC0;
      for ( kk = 0; kk < v137; ++kk )
      {
        if ( !*(_BYTE *)(*(_DWORD *)(a1 + 520) + kk) )
        {
          v59 = (v59 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * kk)) >> 8;
          v61 = (v61 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * kk)) >> 8;
        }
      }
      v60 = (v59 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 6)) >> 3;
      v62 = (v61 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 6)) >> 3;
      if ( v62 <= 0x3FFFC0 )
        v69 = v60 + (v62 << 10);
      else
        v69 = 0x7FFFFFFF;
    }
    if ( v69 < v132 )
    {
      v132 = v69;
      v136 = *(_BYTE **)(a1 + 276);
    }
  }
  if ( v134 == 128 )
  {
    v56 = 0;
    v53 = v131 + 1;
    v54 = (_BYTE *)(*(_DWORD *)(a1 + 280) + 1);
    v55 = (_BYTE *)(v133 + 1);
    while ( v56 < v138 )
    {
      *v54++ = *v53++ - *v55++;
      ++v56;
    }
    v52 = v131 + 1;
    v57 = (unsigned __int8 *)(v133 + 1);
    while ( v56 < v135 )
    {
      v48 = (unsigned __int8)*v55++;
      v47 = *v57++;
      v50 = *v52++;
      v51 = v48 - v47;
      v49 = v50 - v47;
      if ( v48 - v47 >= 0 )
        v14 = v48 - v47;
      else
        v14 = v47 - v48;
      if ( v49 >= 0 )
        v13 = v50 - v47;
      else
        v13 = v47 - v50;
      if ( v49 + v51 >= 0 )
        v12 = v49 + v51;
      else
        v12 = -(v49 + v51);
      if ( v14 > v13 || v14 > v12 )
      {
        if ( v13 > v12 )
          v10 = v47;
        else
          v10 = v48;
        v11 = v10;
      }
      else
      {
        v11 = v50;
      }
      *v54++ = *v53++ - v11;
      ++v56;
    }
    v136 = *(_BYTE **)(a1 + 280);
    sub_47C670(a1, v136, *(_DWORD *)(a2 + 4) + 1);
  }
  else
  {
    if ( (v134 & 0x80) != 0 )
    {
      v38 = 0;
      v42 = v132;
      if ( *(_BYTE *)(a1 + 516) == 2 )
      {
        v35 = (unsigned __int16)v132;
        v33 = (v132 >> 10) & 0x3FFFC0;
        for ( mm = 0; mm < v137; ++mm )
        {
          if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + mm) == 4 )
          {
            v35 = (v35 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * mm)) >> 8;
            v33 = (v33 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 528) + 2 * mm)) >> 8;
          }
        }
        v36 = (v35 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 8)) >> 3;
        v34 = (v33 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 536) + 8)) >> 3;
        if ( v34 <= 0x3FFFC0 )
          v42 = v36 + (v34 << 10);
        else
          v42 = 0x7FFFFFFF;
      }
      v43 = 0;
      v39 = v131 + 1;
      v40 = (_BYTE *)(*(_DWORD *)(a1 + 280) + 1);
      v41 = (_BYTE *)(v133 + 1);
      while ( v43 < v138 )
      {
        *v40 = *v39 - *v41;
        v45 = (unsigned __int8)*v40++;
        ++v41;
        ++v39;
        if ( v45 >= 128 )
          v9 = 256 - v45;
        else
          v9 = v45;
        v38 += v9;
        ++v43;
      }
      v37 = v131 + 1;
      v44 = (unsigned __int8 *)(v133 + 1);
      while ( v43 < v135 )
      {
        v28 = (unsigned __int8)*v41++;
        v27 = *v44++;
        v30 = *v37++;
        v31 = v28 - v27;
        v29 = v30 - v27;
        v8 = v28 - v27 >= 0 ? v28 - v27 : v27 - v28;
        v7 = v29 >= 0 ? v30 - v27 : v27 - v30;
        v6 = v29 + v31 >= 0 ? v29 + v31 : -(v29 + v31);
        if ( v8 > v7 || v8 > v6 )
        {
          v4 = v7 > v6 ? v27 : v28;
          v5 = v4;
        }
        else
        {
          v5 = v30;
        }
        *v40 = *v39 - v5;
        v46 = (unsigned __int8)*v40++;
        ++v39;
        v3 = v46 >= 128 ? 256 - v46 : v46;
        v38 += v3;
        if ( v38 > v42 )
          break;
        ++v43;
      }
      if ( *(_BYTE *)(a1 + 516) == 2 )
      {
        v23 = (unsigned __int16)v38;
        v25 = (v38 >> 10) & 0x3FFFC0;
        for ( nn = 0; nn < v137; ++nn )
        {
          if ( *(_BYTE *)(*(_DWORD *)(a1 + 520) + nn) == 4 )
          {
            v23 = (v23 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * nn)) >> 8;
            v25 = (v25 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 524) + 2 * nn)) >> 8;
          }
        }
        v24 = (v23 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 8)) >> 3;
        v26 = (v25 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 532) + 8)) >> 3;
        if ( v26 <= 0x3FFFC0 )
          v38 = v24 + (v26 << 10);
        else
          v38 = 0x7FFFFFFF;
      }
      if ( v38 < v132 )
        v136 = *(_BYTE **)(a1 + 280);
    }
    sub_47C670(a1, v136, *(_DWORD *)(a2 + 4) + 1);
  }
  result = a1;
  if ( *(_BYTE *)(a1 + 517) )
  {
    for ( i1 = 1; i1 < v137; ++i1 )
      *(_BYTE *)(*(_DWORD *)(a1 + 520) + i1) = *(_BYTE *)(i1 + *(_DWORD *)(a1 + 520) - 1);
    result = *v136;
    *(_BYTE *)(*(_DWORD *)(a1 + 520) + i1) = *v136;
  }
  return result;
}
