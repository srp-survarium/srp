int __cdecl sub_624FE0(
        int *a1,
        unsigned __int8 **a2,
        char **a3,
        int *a4,
        int *a5,
        int *a6,
        int a7,
        int a8,
        int a9,
        _DWORD *a10)
{
  int v10; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // edx
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  unsigned int v47; // [esp+0h] [ebp-28Ch]
  unsigned __int8 *v48; // [esp+4h] [ebp-288h]
  int v49; // [esp+8h] [ebp-284h]
  int v50; // [esp+Ch] [ebp-280h]
  int v51; // [esp+18h] [ebp-274h]
  char v52; // [esp+1Ch] [ebp-270h]
  signed int v53; // [esp+20h] [ebp-26Ch]
  unsigned int v54; // [esp+24h] [ebp-268h]
  int v55; // [esp+30h] [ebp-25Ch]
  unsigned __int8 *v56; // [esp+34h] [ebp-258h]
  unsigned __int8 *v57; // [esp+38h] [ebp-254h]
  unsigned __int8 *v58; // [esp+44h] [ebp-248h]
  BOOL v59; // [esp+58h] [ebp-234h]
  BOOL v60; // [esp+5Ch] [ebp-230h]
  BOOL v61; // [esp+60h] [ebp-22Ch]
  BOOL v62; // [esp+64h] [ebp-228h]
  int *i2; // [esp+68h] [ebp-224h]
  int v64; // [esp+6Ch] [ebp-220h]
  char *nn; // [esp+70h] [ebp-21Ch]
  char *mm; // [esp+70h] [ebp-21Ch]
  unsigned __int8 *v67; // [esp+74h] [ebp-218h]
  int v68; // [esp+78h] [ebp-214h]
  unsigned __int8 *bracket; // [esp+7Ch] [ebp-210h]
  int v70; // [esp+80h] [ebp-20Ch]
  unsigned __int8 *v71; // [esp+84h] [ebp-208h]
  int v72; // [esp+88h] [ebp-204h]
  int v73; // [esp+8Ch] [ebp-200h]
  int jj; // [esp+90h] [ebp-1FCh]
  int *v75; // [esp+94h] [ebp-1F8h]
  const char *v76; // [esp+98h] [ebp-1F4h]
  unsigned __int8 *v77; // [esp+98h] [ebp-1F4h]
  const char *v78; // [esp+98h] [ebp-1F4h]
  char *v79; // [esp+9Ch] [ebp-1F0h]
  __m128i *v80; // [esp+9Ch] [ebp-1F0h]
  char *v81; // [esp+9Ch] [ebp-1F0h]
  char *v82; // [esp+A0h] [ebp-1ECh]
  int v83; // [esp+A0h] [ebp-1ECh]
  int v84; // [esp+A0h] [ebp-1ECh]
  int k; // [esp+A4h] [ebp-1E8h]
  int v86; // [esp+A4h] [ebp-1E8h]
  int m; // [esp+A4h] [ebp-1E8h]
  int n; // [esp+A4h] [ebp-1E8h]
  int ii; // [esp+A4h] [ebp-1E8h]
  int i1; // [esp+A4h] [ebp-1E8h]
  int v91; // [esp+A8h] [ebp-1E4h] BYREF
  int v92; // [esp+ACh] [ebp-1E0h] BYREF
  int *j; // [esp+B0h] [ebp-1DCh]
  char *first; // [esp+B4h] [ebp-1D8h]
  unsigned int v95; // [esp+B8h] [ebp-1D4h]
  unsigned int v96; // [esp+BCh] [ebp-1D0h]
  int i; // [esp+C0h] [ebp-1CCh]
  unsigned __int8 *v98; // [esp+C4h] [ebp-1C8h]
  char *last; // [esp+C8h] [ebp-1C4h]
  unsigned int v100; // [esp+CCh] [ebp-1C0h]
  unsigned int v101; // [esp+D0h] [ebp-1BCh]
  unsigned __int8 *v102; // [esp+D4h] [ebp-1B8h]
  unsigned __int8 *v103; // [esp+D8h] [ebp-1B4h]
  unsigned __int8 *v104; // [esp+DCh] [ebp-1B0h]
  unsigned __int8 *v105; // [esp+E0h] [ebp-1ACh]
  unsigned __int8 *v106; // [esp+E4h] [ebp-1A8h]
  int v107; // [esp+E8h] [ebp-1A4h]
  unsigned int v108; // [esp+ECh] [ebp-1A0h]
  unsigned int v109; // [esp+F0h] [ebp-19Ch]
  unsigned __int8 *v110; // [esp+F4h] [ebp-198h]
  unsigned int v111; // [esp+F8h] [ebp-194h]
  unsigned int i6; // [esp+FCh] [ebp-190h]
  int v113; // [esp+100h] [ebp-18Ch]
  unsigned int v114; // [esp+104h] [ebp-188h]
  unsigned int v115; // [esp+108h] [ebp-184h]
  unsigned int v116; // [esp+10Ch] [ebp-180h]
  unsigned int i5; // [esp+110h] [ebp-17Ch]
  int v118; // [esp+114h] [ebp-178h]
  unsigned __int8 *v119; // [esp+118h] [ebp-174h]
  unsigned __int8 *v120; // [esp+11Ch] [ebp-170h]
  unsigned int v121; // [esp+120h] [ebp-16Ch]
  int i4; // [esp+124h] [ebp-168h]
  unsigned __int8 *v123; // [esp+128h] [ebp-164h]
  int v124; // [esp+12Ch] [ebp-160h]
  int v125; // [esp+130h] [ebp-15Ch]
  unsigned __int8 *v126; // [esp+134h] [ebp-158h]
  unsigned __int8 *i3; // [esp+138h] [ebp-154h]
  unsigned __int8 *v128; // [esp+13Ch] [ebp-150h]
  int v129; // [esp+140h] [ebp-14Ch]
  int v130; // [esp+144h] [ebp-148h]
  int v131; // [esp+148h] [ebp-144h]
  int v132; // [esp+14Ch] [ebp-140h]
  _BYTE *v133; // [esp+150h] [ebp-13Ch]
  int v134; // [esp+154h] [ebp-138h]
  int v135; // [esp+158h] [ebp-134h]
  unsigned __int8 dst[32]; // [esp+15Ch] [ebp-130h] BYREF
  int v137; // [esp+17Ch] [ebp-110h]
  int v138; // [esp+180h] [ebp-10Ch]
  int v139; // [esp+184h] [ebp-108h]
  char *v140; // [esp+188h] [ebp-104h]
  int v141; // [esp+18Ch] [ebp-100h]
  int kk; // [esp+190h] [ebp-FCh]
  int v143; // [esp+194h] [ebp-F8h]
  int v144; // [esp+198h] [ebp-F4h]
  int v145; // [esp+19Ch] [ebp-F0h]
  int v146; // [esp+1A0h] [ebp-ECh]
  int v147; // [esp+1A4h] [ebp-E8h]
  int v148; // [esp+1A8h] [ebp-E4h]
  int v149; // [esp+1ACh] [ebp-E0h]
  int v150; // [esp+1B0h] [ebp-DCh] BYREF
  BOOL v151; // [esp+1B4h] [ebp-D8h]
  signed int v152; // [esp+1B8h] [ebp-D4h]
  BOOL v153; // [esp+1BCh] [ebp-D0h]
  int v154; // [esp+1C0h] [ebp-CCh]
  int v155; // [esp+1C4h] [ebp-C8h] BYREF
  unsigned int v156; // [esp+1C8h] [ebp-C4h]
  signed int v157; // [esp+1CCh] [ebp-C0h]
  _BYTE v158[8]; // [esp+1D0h] [ebp-BCh] BYREF
  unsigned __int8 *v159; // [esp+1D8h] [ebp-B4h]
  unsigned __int8 *v160; // [esp+1DCh] [ebp-B0h]
  unsigned __int8 *v161; // [esp+1E0h] [ebp-ACh] BYREF
  unsigned int v162; // [esp+1E4h] [ebp-A8h]
  int v163; // [esp+1E8h] [ebp-A4h]
  unsigned int count; // [esp+1ECh] [ebp-A0h]
  char *v165; // [esp+1F0h] [ebp-9Ch]
  int v166; // [esp+1F4h] [ebp-98h]
  char *v167; // [esp+1F8h] [ebp-94h] BYREF
  int v168; // [esp+1FCh] [ebp-90h]
  int v169; // [esp+200h] [ebp-8Ch]
  int v170; // [esp+204h] [ebp-88h]
  BOOL v171; // [esp+208h] [ebp-84h]
  int v172; // [esp+20Ch] [ebp-80h]
  int v173; // [esp+210h] [ebp-7Ch]
  int v174; // [esp+214h] [ebp-78h]
  __m128i v175; // [esp+218h] [ebp-74h] BYREF
  int v176; // [esp+228h] [ebp-64h]
  unsigned __int8 src[32]; // [esp+22Ch] [ebp-60h] BYREF
  unsigned __int8 *v178; // [esp+250h] [ebp-3Ch]
  int v179; // [esp+254h] [ebp-38h]
  BOOL v180; // [esp+258h] [ebp-34h]
  unsigned __int8 *v181; // [esp+25Ch] [ebp-30h]
  char *v182; // [esp+260h] [ebp-2Ch] BYREF
  int v183; // [esp+264h] [ebp-28h] BYREF
  int v184; // [esp+268h] [ebp-24h]
  int v185; // [esp+26Ch] [ebp-20h] BYREF
  int v186; // [esp+270h] [ebp-1Ch] BYREF
  int v187; // [esp+274h] [ebp-18h]
  unsigned __int8 *v188; // [esp+278h] [ebp-14h]
  unsigned __int8 *v189; // [esp+27Ch] [ebp-10h]
  int v190; // [esp+280h] [ebp-Ch]
  int v191; // [esp+284h] [ebp-8h]
  unsigned __int8 *v192; // [esp+288h] [ebp-4h]

  v183 = 0;
  v185 = 0;
  v184 = 0;
  v176 = *a1;
  v173 = 0;
  v186 = 0;
  v181 = *a2;
  v160 = v181;
  v188 = v181;
  v175.m128i_i32[2] = 0;
  v191 = 0;
  v182 = *a3;
  v165 = 0;
  v192 = 0;
  v159 = 0;
  v162 = 0;
  v163 = (v176 & 0x800) != 0;
  v180 = (v176 & 0x200) != 0;
  v171 = (v176 & 0x200) == 0;
  v190 = -2;
  v166 = -2;
  v172 = -2;
  v187 = -2;
  v174 = (v176 & 1) != 0 ? 0x100 : 0;
  while ( 1 )
  {
    count = (unsigned __int8)*v182;
    if ( !count && v165 )
    {
      v182 = v165;
      v165 = 0;
      count = (unsigned __int8)*v182;
    }
    if ( !a10 )
    {
      if ( *(_DWORD *)(a9 + 36) > (unsigned int)(*(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100) )
      {
        *a4 = 52;
        goto LABEL_988;
      }
      goto LABEL_21;
    }
    if ( (unsigned int)v181 > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 )
      break;
    if ( v181 < v160 )
      v181 = v160;
    if ( 2147483627 - *a10 < v181 - v160 )
    {
      *a4 = 20;
      goto LABEL_988;
    }
    *a10 += v181 - v160;
    if ( v192 )
    {
      if ( v192 > v188 )
      {
        sub_624F30(v188, v192, v181 - v192);
        v181 -= v192 - v188;
        v192 = v188;
      }
    }
    else
    {
      v181 = v188;
    }
    v160 = v181;
LABEL_21:
    if ( v175.m128i_i32[2] && count )
    {
      if ( count == 92 && v182[1] == 69 )
      {
        v175.m128i_i32[2] = 0;
        ++v182;
        goto LABEL_2;
      }
      if ( v159 )
      {
        if ( !a10 )
          sub_62C7A0(v159, v182, a9);
        v159 = 0;
      }
      if ( (v176 & 0x4000) != 0 )
      {
        v159 = v181;
        v181 = (unsigned __int8 *)sub_62C740(v181, v182, a9);
      }
LABEL_967:
      v157 = 1;
      v158[0] = count;
      if ( v163 && (int)count >= 192 )
      {
        while ( (v182[1] & 0xC0) == 0x80 )
          v158[v157++] = *++v182;
      }
      goto LABEL_971;
    }
    v62 = count == 42 || count == 43 || count == 63 || count == 123 && sub_62AA80(v182 + 1);
    v151 = v62;
    if ( !v62 )
    {
      if ( v159 )
      {
        v10 = v173--;
        if ( v10 <= 0 )
        {
          if ( !a10 )
            sub_62C7A0(v159, v182, a9);
          v159 = 0;
        }
      }
    }
    if ( (v176 & 8) != 0 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + count) & 1) != 0 )
        goto LABEL_2;
      if ( count == 35 )
      {
        ++v182;
        while ( *v182 )
        {
          if ( *(_DWORD *)(a9 + 96) )
          {
            v61 = (unsigned int)v182 < *(_DWORD *)(a9 + 28)
               && _pcre_is_newline(v182, *(_DWORD *)(a9 + 96), *(_DWORD *)(a9 + 28), a9 + 100, v163);
            v60 = v61;
          }
          else
          {
            v59 = (unsigned int)v182 <= *(_DWORD *)(a9 + 28) - *(_DWORD *)(a9 + 100)
               && *v182 == *(_BYTE *)(a9 + 104)
               && (*(_DWORD *)(a9 + 100) == 1 || v182[1] == *(_BYTE *)(a9 + 105));
            v60 = v59;
          }
          if ( v60 )
          {
            v182 = &v182[*(_DWORD *)(a9 + 100) - 1];
            break;
          }
          ++v182;
          if ( v163 )
          {
            while ( (*v182 & 0xC0) == 0x80 )
              ++v182;
          }
        }
        if ( *v182 )
          goto LABEL_2;
        count = 0;
      }
    }
    if ( (v176 & 0x4000) != 0 && !v151 )
    {
      v159 = v181;
      v181 = (unsigned __int8 *)sub_62C740(v181, v182, a9);
    }
    switch ( count )
    {
      case 0u:
      case 0x29u:
      case 0x7Cu:
        *a5 = v187;
        *a6 = v172;
        *a2 = v181;
        *a3 = v182;
        if ( !a10 )
          return 1;
        if ( 2147483627 - *a10 < v181 - v160 )
        {
          *a4 = 20;
          goto LABEL_988;
        }
        *a10 += v181 - v160;
        return 1;
      case 0x24u:
        v192 = 0;
        *v181++ = ((v176 & 2) != 0) + 27;
        break;
      case 0x28u:
        v154 = v176;
        v145 = 0;
        v184 = 127;
        v162 = *(_DWORD *)(a9 + 36);
        v144 = 0;
        if ( *++v182 == 42 && ((*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v182[1]) & 2) != 0 || v182[1] == 58) )
        {
          v96 = 0;
          last = (char *)&unk_72BB38;
          first = v182 + 1;
          v98 = 0;
          v192 = 0;
          do
            ++v182;
          while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v182) & 2) != 0 );
          v95 = v182 - first;
          if ( *v182 == 58 )
          {
            v98 = (unsigned __int8 *)++v182;
            while ( *v182 && *v182 != 41 )
              ++v182;
            v96 = v182 - (char *)v98;
          }
          if ( *v182 != 41 )
          {
            *a4 = 60;
            goto LABEL_988;
          }
          for ( i = 0; ; ++i )
          {
            if ( i >= 9 )
              goto LABEL_618;
            if ( v95 == dword_72BB68[3 * i] && !strncmp(first, last, v95) )
              break;
            last += dword_72BB68[3 * i] + 1;
          }
          if ( dword_72BB6C[3 * i] == 152 )
          {
            if ( v96 )
            {
              *a4 = 59;
              goto LABEL_988;
            }
            *(_DWORD *)(a9 + 88) = 1;
            for ( j = *(int **)(a9 + 32); j; j = (int *)*j )
            {
              *v181++ = -102;
              *v181 = HIBYTE(*((_WORD *)j + 2));
              v181[1] = *((_WORD *)j + 2);
              v181 += 2;
            }
            *v181++ = (*(_DWORD *)(a9 + 72) > 0) - 104;
            if ( v187 == -2 )
              v187 = -1;
          }
          else if ( v96 )
          {
            if ( dword_72BB70[3 * i] < 0 )
            {
              *a4 = 59;
              goto LABEL_988;
            }
            *v181 = dword_72BB70[3 * i];
            v43 = *v181++;
            if ( v43 == 149 )
              *(_DWORD *)(a9 + 80) |= 0x40u;
            *v181++ = v96;
            memcpy((int)v181, (const __m128i *)v98, v96);
            v181 += v96;
            *v181++ = 0;
          }
          else
          {
            if ( dword_72BB6C[3 * i] < 0 )
            {
              *a4 = 66;
              goto LABEL_988;
            }
            *v181 = dword_72BB6C[3 * i];
            v42 = *v181++;
            if ( v42 == 148 )
              *(_DWORD *)(a9 + 80) |= 0x40u;
          }
LABEL_618:
          if ( i >= 9 )
          {
            *a4 = 60;
            goto LABEL_988;
          }
        }
        else
        {
          if ( *v182 == 63 )
          {
            switch ( *++v182 )
            {
              case '!':
                if ( *++v182 == 41 )
                {
                  *v181++ = -105;
                  v192 = 0;
                  goto LABEL_2;
                }
                v184 = 120;
                ++*(_DWORD *)(a9 + 72);
                break;
              case '#':
                ++v182;
                while ( *v182 && *v182 != 41 )
                  ++v182;
                if ( *v182 )
                  goto LABEL_2;
                *a4 = 18;
                goto LABEL_988;
              case '&':
                v147 = 41;
                v153 = 1;
                goto LABEL_757;
              case '\'':
                goto LABEL_721;
              case '(':
                v184 = 129;
                if ( v182[1] == 63 && (v182[2] == 61 || v182[2] == 33 || v182[2] == 60) )
                  break;
                v181[3] = -121;
                v145 = 3;
                v148 = -1;
                if ( v182[1] == 82 && v182[2] == 38 )
                {
                  v147 = -1;
                  v182 += 2;
                  v181[3] = -119;
                }
                else if ( v182[1] == 60 )
                {
                  v147 = 62;
                  ++v182;
                }
                else if ( v182[1] == 39 )
                {
                  v147 = 39;
                  ++v182;
                }
                else
                {
                  v147 = 0;
                  if ( v182[1] == 45 || v182[1] == 43 )
                    v148 = (unsigned __int8)*++v182;
                }
                if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v182[1]) & 0x10) == 0 )
                {
                  ++v182;
                  *a4 = 28;
                  goto LABEL_988;
                }
                v156 = 0;
                v79 = ++v182;
                while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v182) & 0x10) != 0 )
                {
                  if ( (v156 & 0x80000000) == 0 )
                  {
                    if ( (byte_72C7A8[(unsigned __int8)*v182] & 4) != 0 )
                      v54 = 10 * v156 + (unsigned __int8)*v182 - 48;
                    else
                      v54 = -1;
                    v156 = v54;
                  }
                  ++v182;
                }
                v82 = (char *)(v182 - v79);
                if ( v147 > 0 && (v44 = (unsigned __int8)*v182, ++v182, v44 != v147)
                  || (v45 = (unsigned __int8)*v182, ++v182, v45 != 41) )
                {
                  --v182;
                  *a4 = 26;
                  goto LABEL_988;
                }
                if ( !a10 )
                {
                  if ( v148 <= 0 )
                  {
                    v76 = *(const char **)(a9 + 40);
                    for ( k = 0; k < *(_DWORD *)(a9 + 44) && strncmp(v79, v76 + 2, (unsigned int)v82); ++k )
                      v76 += *(_DWORD *)(a9 + 48);
                    if ( k >= *(_DWORD *)(a9 + 44) )
                    {
                      v86 = sub_62B550(a9, v79, (unsigned int)v82, (v176 & 8) != 0, v163);
                      if ( v86 <= 0 )
                      {
                        if ( v147 )
                        {
                          *a4 = 15;
                          goto LABEL_988;
                        }
                        if ( *v79 == 82 )
                        {
                          v156 = 0;
                          for ( m = 1; m < (int)v82; ++m )
                          {
                            if ( (byte_72C7A8[(unsigned __int8)v79[m]] & 4) == 0 )
                            {
                              *a4 = 15;
                              goto LABEL_988;
                            }
                            v156 = 10 * v156 + (unsigned __int8)v79[m] - 48;
                          }
                          if ( !v156 )
                            v156 = 0xFFFF;
                          v181[3] = -119;
                          v181[4] = BYTE1(v156);
                          v181[5] = v156;
                        }
                        else if ( v82 == (char *)6 && !strncmp(v79, "DEFINE", 6u) )
                        {
                          v181[3] = -117;
                          v145 = 1;
                        }
                        else
                        {
                          if ( (int)v156 <= 0 || (signed int)v156 > *(_DWORD *)(a9 + 60) )
                          {
                            *a4 = v156 != 0 ? 15 : 35;
                            goto LABEL_988;
                          }
                          v181[4] = BYTE1(v156);
                          v181[5] = v156;
                        }
                      }
                      else
                      {
                        v181[4] = BYTE1(v86);
                        v181[5] = v86;
                        ++v181[3];
                      }
                    }
                    else
                    {
                      v156 = *((unsigned __int8 *)v76 + 1) | (*(unsigned __int8 *)v76 << 8);
                      v181[4] = BYTE1(v156);
                      v181[5] = v156;
                      ++v181[3];
                    }
                  }
                  else
                  {
                    if ( (int)v156 <= 0 )
                    {
                      *a4 = 58;
                      goto LABEL_988;
                    }
                    if ( v148 == 45 )
                      v53 = *(_DWORD *)(a9 + 56) - v156 + 1;
                    else
                      v53 = *(_DWORD *)(a9 + 56) + v156;
                    v156 = v53;
                    if ( v53 <= 0 || (signed int)v156 > *(_DWORD *)(a9 + 60) )
                    {
                      *a4 = 15;
                      goto LABEL_988;
                    }
                    v181[4] = BYTE1(v156);
                    v181[5] = v156;
                  }
                }
                break;
              case '+':
              case '-':
              case '0':
              case '1':
              case '2':
              case '3':
              case '4':
              case '5':
              case '6':
              case '7':
              case '8':
              case '9':
                goto LABEL_782;
              case ':':
                goto LABEL_630;
              case '<':
                v52 = v182[1];
                if ( v52 == 33 )
                {
                  v184 = 122;
                  ++*(_DWORD *)(a9 + 72);
                  v182 += 2;
                  break;
                }
                if ( v52 == 61 )
                {
                  v184 = 121;
                  ++*(_DWORD *)(a9 + 72);
                  v182 += 2;
                  break;
                }
                if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v182[1]) & 0x10) == 0 )
                {
                  ++v182;
                  *a4 = 24;
                  goto LABEL_988;
                }
LABEL_721:
                v147 = *v182++ != 60 ? 39 : 62;
                v80 = (__m128i *)v182;
                while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v182) & 0x10) != 0 )
                  ++v182;
                v83 = v182 - (char *)v80;
                if ( !a10 )
                {
                  v73 = 0;
                  v77 = *(unsigned __int8 **)(a9 + 40);
                  for ( n = 0; ; ++n )
                  {
                    if ( n >= *(_DWORD *)(a9 + 44) )
                      goto LABEL_745;
                    v72 = memcmp((unsigned __int8 *)v80, v77 + 2, v83);
                    if ( !v72 )
                    {
                      if ( v77[v83 + 2] )
                      {
                        v72 = -1;
                      }
                      else
                      {
                        if ( (v77[1] | (*v77 << 8)) != *(_DWORD *)(a9 + 56) + 1 && (v176 & 0x80000) == 0 )
                        {
                          *a4 = 43;
                          goto LABEL_988;
                        }
                        v73 = 1;
                      }
                    }
                    if ( v72 < 0 )
                      break;
                    v77 += *(_DWORD *)(a9 + 48);
                  }
                  sub_624F30(&v77[*(_DWORD *)(a9 + 48)], v77, *(_DWORD *)(a9 + 48) * (*(_DWORD *)(a9 + 44) - n));
LABEL_745:
                  if ( !v73 )
                  {
                    v71 = *(unsigned __int8 **)(a9 + 40);
                    for ( ii = 0; ii < *(_DWORD *)(a9 + 44); ++ii )
                    {
                      if ( v71 == v77 )
                      {
                        --ii;
                      }
                      else if ( (v71[1] | (*v71 << 8)) == *(_DWORD *)(a9 + 56) + 1 )
                      {
                        *a4 = 65;
                        goto LABEL_988;
                      }
                      v71 += *(_DWORD *)(a9 + 48);
                    }
                  }
                  *v77 = (unsigned __int16)(*(_WORD *)(a9 + 56) + 1) >> 8;
                  v77[1] = *(_DWORD *)(a9 + 56) + 1;
                  memcpy((int)(v77 + 2), v80, v83);
                  v77[v83 + 2] = 0;
                  goto LABEL_755;
                }
                if ( (unsigned __int8)*v182 != v147 )
                {
                  *a4 = 42;
                  goto LABEL_988;
                }
                if ( *(int *)(a9 + 44) >= 10000 )
                {
                  *a4 = 49;
                  goto LABEL_988;
                }
                if ( v83 + 3 > *(_DWORD *)(a9 + 48) )
                {
                  *(_DWORD *)(a9 + 48) = v83 + 3;
                  if ( v83 > 32 )
                  {
                    *a4 = 48;
                    goto LABEL_988;
                  }
                }
LABEL_755:
                ++*(_DWORD *)(a9 + 44);
                ++v182;
                goto LABEL_846;
              case '=':
                v184 = 119;
                ++*(_DWORD *)(a9 + 72);
                ++v182;
                break;
              case '>':
                v184 = 123;
                ++v182;
                break;
              case 'C':
                v159 = v181;
                v173 = 1;
                *v181++ = 112;
                for ( jj = 0; (byte_72C7A8[(unsigned __int8)*++v182] & 4) != 0; jj = 10 * jj
                                                                                   + (unsigned __int8)*v182
                                                                                   - 48 )
                  ;
                if ( *v182 != 41 )
                {
                  *a4 = 39;
                  goto LABEL_988;
                }
                if ( jj > 255 )
                {
                  *a4 = 38;
                  goto LABEL_988;
                }
                *v181++ = jj;
                *v181 = (unsigned __int16)((_WORD)v182 - *(_WORD *)(a9 + 24) + 1) >> 8;
                v181[1] = (_BYTE)v182 - *(_BYTE *)(a9 + 24) + 1;
                v181[2] = 0;
                v181[3] = 0;
                v181 += 4;
                v192 = 0;
                goto LABEL_2;
              case 'P':
                if ( *++v182 == 61 || *v182 == 62 )
                {
                  v153 = *v182 == 62;
                  v147 = 41;
                  goto LABEL_757;
                }
                if ( *v182 != 60 )
                {
                  *a4 = 41;
                  goto LABEL_988;
                }
                goto LABEL_721;
              case 'R':
                ++v182;
LABEL_782:
                v147 = 41;
                goto LABEL_783;
              case '|':
                v144 = 1;
LABEL_630:
                v184 = 125;
                ++v182;
                break;
              default:
                goto LABEL_821;
            }
          }
          else if ( (v176 & 0x1000) != 0 )
          {
            v184 = 125;
          }
          else
          {
LABEL_846:
            v181[3] = (unsigned __int16)++*(_DWORD *)(a9 + 56) >> 8;
            v181[4] = *(_DWORD *)(a9 + 56);
            v145 = 2;
          }
LABEL_847:
          v192 = v181;
          *v181 = v184;
          v161 = v181;
          v170 = *(_DWORD *)(a9 + 84);
          v141 = *(_DWORD *)(a9 + 56);
          v186 = 0;
          if ( v184 == 121 || v184 == 122 )
            v46 = sub_624A90(
                    v154,
                    &v161,
                    &v182,
                    a4,
                    1,
                    v144,
                    v145,
                    a8 + (v184 == 129),
                    &v150,
                    &v155,
                    a7,
                    (_DWORD *)a9,
                    a10 != 0 ? &v186 : 0);
          else
            v46 = sub_624A90(
                    v154,
                    &v161,
                    &v182,
                    a4,
                    0,
                    v144,
                    v145,
                    a8 + (v184 == 129),
                    &v150,
                    &v155,
                    a7,
                    (_DWORD *)a9,
                    a10 != 0 ? &v186 : 0);
          if ( !v46 )
            goto LABEL_988;
          if ( v184 == 123 && *(_DWORD *)(a9 + 56) <= v141 )
            *v181 = 124;
          if ( v184 >= 119 && v184 <= 122 )
            --*(_DWORD *)(a9 + 72);
          if ( v184 == 129 && !a10 )
          {
            v67 = v181;
            v68 = 0;
            do
            {
              ++v68;
              v67 += v67[2] | (v67[1] << 8);
            }
            while ( *v67 != 114 );
            if ( v181[3] == 139 )
            {
              if ( v68 > 1 )
              {
                *a4 = 54;
                goto LABEL_988;
              }
              v184 = 139;
            }
            else
            {
              if ( v68 > 2 )
              {
                *a4 = 27;
                goto LABEL_988;
              }
              if ( v68 == 1 )
              {
                v155 = -1;
                v150 = -1;
              }
            }
          }
          if ( *v182 != 41 )
          {
            *a4 = 14;
            goto LABEL_988;
          }
          if ( a10 )
          {
            if ( 2147483627 - *a10 < v186 - 6 )
            {
              *a4 = 20;
              goto LABEL_988;
            }
            *a10 = v186 + *a10 - 6;
            *++v181 = 0;
            v181[1] = 3;
            v181 += 2;
            *v181++ = 114;
            *v181 = 0;
            v181[1] = 3;
            v181 += 2;
          }
          else
          {
            v181 = v161;
            if ( v184 != 139 )
            {
              v190 = v172;
              v166 = v187;
              v191 = 0;
              if ( v184 < 123 )
              {
                if ( v184 == 119 && v155 >= 0 )
                  v172 = v155;
              }
              else
              {
                if ( v187 == -2 )
                {
                  if ( v150 < 0 )
                  {
                    v187 = -1;
                  }
                  else
                  {
                    v187 = v150;
                    v191 = 1;
                  }
                  v166 = -1;
                }
                else if ( v150 >= 0 && v155 < 0 )
                {
                  v155 = v170 | v150;
                }
                if ( v155 >= 0 )
                  v172 = v155;
              }
            }
          }
        }
        break;
      case 0x2Au:
        v183 = 0;
        v185 = -1;
        goto LABEL_355;
      case 0x2Bu:
        v183 = 1;
        v185 = -1;
        goto LABEL_355;
      case 0x2Eu:
        if ( v187 == -2 )
          v187 = -1;
        v166 = v187;
        v190 = v172;
        v192 = v181;
        *v181++ = ((v176 & 4) != 0) + 12;
        break;
      case 0x3Fu:
        v183 = 0;
        v185 = 1;
        goto LABEL_355;
      case 0x5Bu:
        v192 = v181;
        if ( (v182[1] == 58 || v182[1] == 46 || v182[1] == 61) && sub_62C300(v182, &v167) )
        {
          *a4 = v182[1] != 58 ? 31 : 13;
          goto LABEL_988;
        }
        for ( kk = 0; ; kk = 1 )
        {
          while ( 1 )
          {
            count = (unsigned __int8)*++v182;
            if ( count != 92 )
              break;
            if ( v182[1] == 69 )
            {
              ++v182;
            }
            else
            {
              if ( strncmp(v182 + 1, "Q\\E", 3u) )
                goto LABEL_108;
              v182 += 3;
            }
          }
          if ( kk || count != 94 )
            break;
        }
LABEL_108:
        if ( count == 93 && (*(_DWORD *)(a9 + 76) & 0x2000000) != 0 )
        {
          *v181++ = kk != 0 ? 13 : -105;
          if ( v187 == -2 )
            v187 = -1;
          v166 = v187;
          break;
        }
        v149 = 0;
        v146 = 0;
        v152 = -1;
        memset((int)src, 0, sizeof(src));
        v168 = 0;
        v189 = v181 + 4;
        v178 = v181 + 4;
        if ( count )
        {
          while ( 1 )
          {
            if ( v163 )
            {
              if ( (int)count > 127 )
              {
                count = (unsigned __int8)*v182;
                if ( (int)count >= 192 )
                {
                  if ( (count & 0x20) != 0 )
                  {
                    if ( (count & 0x10) != 0 )
                    {
                      if ( (count & 8) != 0 )
                      {
                        if ( (count & 4) != 0 )
                        {
                          count = v182[5] & 0x3F
                                | ((v182[4] & 0x3F) << 6)
                                | ((v182[3] & 0x3F) << 12)
                                | ((v182[2] & 0x3F) << 18)
                                | ((v182[1] & 0x3F) << 24)
                                | ((count & 1) << 30);
                          v182 += 5;
                        }
                        else
                        {
                          count = v182[4] & 0x3F
                                | ((v182[3] & 0x3F) << 6)
                                | ((v182[2] & 0x3F) << 12)
                                | ((v182[1] & 0x3F) << 18)
                                | ((count & 3) << 24);
                          v182 += 4;
                        }
                      }
                      else
                      {
                        count = v182[3] & 0x3F
                              | ((v182[2] & 0x3F) << 6)
                              | ((v182[1] & 0x3F) << 12)
                              | ((count & 7) << 18);
                        v182 += 3;
                      }
                    }
                    else
                    {
                      count = v182[2] & 0x3F | ((v182[1] & 0x3F) << 6) | ((count & 0xF) << 12);
                      v182 += 2;
                    }
                  }
                  else
                  {
                    count = *++v182 & 0x3F | ((count & 0x1F) << 6);
                  }
                }
              }
            }
            if ( a10 )
            {
              *a10 += v189 - v178;
              v189 = v178;
            }
            if ( v175.m128i_i32[2] )
              break;
            if ( count == 91 && (v182[1] == 58 || v182[1] == 46 || v182[1] == 61) && sub_62C300(v182, &v167) )
            {
              v135 = 0;
              v134 = *(_DWORD *)(a9 + 8);
              if ( v182[1] != 58 )
              {
                *a4 = 31;
                goto LABEL_988;
              }
              v182 += 2;
              if ( *v182 == 94 )
              {
                v135 = 1;
                v149 = 1;
                ++v182;
              }
              v138 = sub_62C3F0(v182, v167 - v182);
              if ( v138 < 0 )
              {
                *a4 = 30;
                goto LABEL_988;
              }
              if ( (v176 & 1) != 0 && v138 <= 2 )
                v138 = 0;
              v138 *= 3;
              memcpy((int)dst, (const __m128i *)(dword_72BC40[v138] + v134), sizeof(dst));
              v139 = dword_72BC44[v138];
              v137 = dword_72BC48[v138];
              if ( v139 >= 0 )
              {
                if ( v137 < 0 )
                {
                  for ( count = 0; (int)count < 32; ++count )
                    dst[count] &= ~*(_BYTE *)(v134 + v139 + count);
                }
                else
                {
                  for ( count = 0; (int)count < 32; ++count )
                    dst[count] |= *(_BYTE *)(v134 + v139 + count);
                }
              }
              if ( v137 < 0 )
                v137 = -v137;
              if ( v137 == 1 )
              {
                dst[1] &= 0xC3u;
              }
              else if ( v137 == 2 )
              {
                dst[11] &= ~0x80u;
              }
              if ( v135 )
              {
                for ( count = 0; (int)count < 32; ++count )
                  src[count] |= ~dst[count];
              }
              else
              {
                for ( count = 0; (int)count < 32; ++count )
                  src[count] |= dst[count];
              }
              v182 = v167 + 1;
              v146 = 10;
              goto LABEL_312;
            }
            if ( count != 92 )
              goto LABEL_242;
            count = sub_62AB50(&v182, a4, *(_DWORD *)(a9 + 56), v176, 1);
            if ( *a4 )
              goto LABEL_988;
            switch ( -count )
            {
              case 5u:
                count = 8;
LABEL_183:
                if ( (count & 0x80000000) != 0 )
                {
                  v133 = *(_BYTE **)(a9 + 8);
                  v146 += 2;
                  switch ( -count )
                  {
                    case 6u:
                      v149 = 1;
                      for ( count = 0; (int)count < 32; ++count )
                        src[count] |= ~v133[count + 64];
                      goto LABEL_312;
                    case 7u:
                      for ( count = 0; (int)count < 32; ++count )
                        src[count] |= v133[count + 64];
                      goto LABEL_312;
                    case 8u:
                      v149 = 1;
                      for ( count = 0; (int)count < 32; ++count )
                        src[count] |= ~v133[count];
                      src[1] |= 8u;
                      goto LABEL_312;
                    case 9u:
                      src[0] |= *v133;
                      src[1] |= v133[1] & 0xF7;
                      for ( count = 2; (int)count < 32; ++count )
                        src[count] |= v133[count];
                      goto LABEL_312;
                    case 10u:
                      v149 = 1;
                      for ( count = 0; (int)count < 32; ++count )
                        src[count] |= ~v133[count + 160];
                      goto LABEL_312;
                    case 11u:
                      for ( count = 0; (int)count < 32; ++count )
                        src[count] |= v133[count + 160];
                      goto LABEL_312;
                    case 18u:
                      for ( count = 0; (int)count < 32; ++count )
                      {
                        v132 = 255;
                        switch ( count )
                        {
                          case 1u:
                            v132 ^= 2u;
                            break;
                          case 4u:
                            v132 ^= 1u;
                            break;
                          case 0x14u:
                            v132 ^= 1u;
                            break;
                        }
                        src[count] |= v132;
                      }
                      if ( v163 )
                      {
                        v168 = 1;
                        *v189++ = 2;
                        v19 = _pcre_ord2utf8(256, v189);
                        v189 += v19;
                        v20 = _pcre_ord2utf8(5759, v189);
                        v189 += v20;
                        *v189++ = 2;
                        v21 = _pcre_ord2utf8(5761, v189);
                        v189 += v21;
                        v22 = _pcre_ord2utf8(6157, v189);
                        v189 += v22;
                        *v189++ = 2;
                        v23 = _pcre_ord2utf8(6159, v189);
                        v189 += v23;
                        v24 = _pcre_ord2utf8(0x1FFF, v189);
                        v189 += v24;
                        *v189++ = 2;
                        v25 = _pcre_ord2utf8(8203, v189);
                        v189 += v25;
                        v26 = _pcre_ord2utf8(8238, v189);
                        v189 += v26;
                        *v189++ = 2;
                        v27 = _pcre_ord2utf8(8240, v189);
                        v189 += v27;
                        v28 = _pcre_ord2utf8(8286, v189);
                        v189 += v28;
                        *v189++ = 2;
                        v29 = _pcre_ord2utf8(8288, v189);
                        v189 += v29;
                        v30 = _pcre_ord2utf8(12287, v189);
                        v189 += v30;
                        *v189++ = 2;
                        v31 = _pcre_ord2utf8(12289, v189);
                        v189 += v31;
                        v32 = _pcre_ord2utf8(0x7FFFFFFF, v189);
                        v189 += v32;
                      }
                      goto LABEL_312;
                    case 19u:
                      src[1] |= 2u;
                      src[4] |= 1u;
                      src[20] |= 1u;
                      if ( v163 )
                      {
                        v168 = 1;
                        *v189++ = 1;
                        v12 = _pcre_ord2utf8(5760, v189);
                        v189 += v12;
                        *v189++ = 1;
                        v13 = _pcre_ord2utf8(6158, v189);
                        v189 += v13;
                        *v189++ = 2;
                        v14 = _pcre_ord2utf8(0x2000, v189);
                        v189 += v14;
                        v15 = _pcre_ord2utf8(8202, v189);
                        v189 += v15;
                        *v189++ = 1;
                        v16 = _pcre_ord2utf8(8239, v189);
                        v189 += v16;
                        *v189++ = 1;
                        v17 = _pcre_ord2utf8(8287, v189);
                        v189 += v17;
                        *v189++ = 1;
                        v18 = _pcre_ord2utf8(12288, v189);
                        v189 += v18;
                      }
                      goto LABEL_312;
                    case 20u:
                      for ( count = 0; (int)count < 32; ++count )
                      {
                        v131 = 255;
                        if ( count == 1 )
                        {
                          v131 ^= 4u;
                          v131 ^= 8u;
                          v131 ^= 0x10u;
                          v131 ^= 0x20u;
                        }
                        else if ( count == 16 )
                        {
                          v131 ^= 0x20u;
                        }
                        src[count] |= v131;
                      }
                      if ( v163 )
                      {
                        v168 = 1;
                        *v189++ = 2;
                        v35 = _pcre_ord2utf8(256, v189);
                        v189 += v35;
                        v36 = _pcre_ord2utf8(8231, v189);
                        v189 += v36;
                        *v189++ = 2;
                        v37 = _pcre_ord2utf8(8233, v189);
                        v189 += v37;
                        v38 = _pcre_ord2utf8(0x7FFFFFFF, v189);
                        v189 += v38;
                      }
                      goto LABEL_312;
                    case 21u:
                      src[1] |= 4u;
                      src[1] |= 8u;
                      src[1] |= 0x10u;
                      src[1] |= 0x20u;
                      src[16] |= 0x20u;
                      if ( v163 )
                      {
                        v168 = 1;
                        *v189++ = 2;
                        v33 = _pcre_ord2utf8(8232, v189);
                        v189 += v33;
                        v34 = _pcre_ord2utf8(8233, v189);
                        v189 += v34;
                      }
                      goto LABEL_312;
                    default:
                      if ( (v176 & 0x40) != 0 )
                      {
                        *a4 = 7;
                        goto LABEL_988;
                      }
                      v146 -= 2;
                      count = (unsigned __int8)*v182;
                      break;
                  }
                }
LABEL_242:
                while ( v182[1] == 92 && v182[2] == 69 )
                {
                  v175.m128i_i32[2] = 0;
                  v182 += 2;
                }
                v140 = v182;
                if ( count == 13 || count == 10 )
                  *(_DWORD *)(a9 + 80) |= 0x20u;
                if ( v175.m128i_i32[2] || v182[1] != 45 )
                  goto LABEL_304;
                for ( v182 += 2; *v182 == 92 && v182[1] == 69; v182 += 2 )
                  ;
                while ( *v182 == 92 && v182[1] == 81 )
                {
                  v182 += 2;
                  if ( *v182 != 92 || v182[1] != 69 )
                  {
                    v175.m128i_i32[2] = 1;
                    break;
                  }
                  v182 += 2;
                }
                if ( !*v182 || !v175.m128i_i32[2] && *v182 == 93 )
                {
                  v182 = v140;
LABEL_304:
                  if ( v163 && ((int)count > 255 || (v176 & 1) != 0 && (int)count > 127) )
                  {
                    v168 = 1;
                    *v189++ = 1;
                    v41 = _pcre_ord2utf8(count, v189);
                    v189 += v41;
                  }
                  else
                  {
                    src[(int)count / 8] |= 1 << (count & 7);
                    if ( (v176 & 1) != 0 )
                    {
                      count = *(unsigned __int8 *)(*(_DWORD *)(a9 + 4) + count);
                      src[(int)count / 8] |= 1 << (count & 7);
                    }
                    ++v146;
                    v152 = count;
                  }
                  goto LABEL_312;
                }
                if ( v163 )
                {
                  v130 = (unsigned __int8)*v182;
                  if ( v130 >= 192 )
                  {
                    if ( (v130 & 0x20) != 0 )
                    {
                      if ( (v130 & 0x10) != 0 )
                      {
                        if ( (v130 & 8) != 0 )
                        {
                          if ( (v130 & 4) != 0 )
                          {
                            v130 = v182[5] & 0x3F
                                 | ((v182[4] & 0x3F) << 6)
                                 | ((v182[3] & 0x3F) << 12)
                                 | ((v182[2] & 0x3F) << 18)
                                 | ((v182[1] & 0x3F) << 24)
                                 | ((v130 & 1) << 30);
                            v182 += 5;
                          }
                          else
                          {
                            v130 = v182[4] & 0x3F
                                 | ((v182[3] & 0x3F) << 6)
                                 | ((v182[2] & 0x3F) << 12)
                                 | ((v182[1] & 0x3F) << 18)
                                 | ((v130 & 3) << 24);
                            v182 += 4;
                          }
                        }
                        else
                        {
                          v130 = v182[3] & 0x3F
                               | ((v182[2] & 0x3F) << 6)
                               | ((v182[1] & 0x3F) << 12)
                               | ((v130 & 7) << 18);
                          v182 += 3;
                        }
                      }
                      else
                      {
                        v130 = v182[2] & 0x3F | ((v182[1] & 0x3F) << 6) | ((v130 & 0xF) << 12);
                        v182 += 2;
                      }
                    }
                    else
                    {
                      v130 = *++v182 & 0x3F | ((v130 & 0x1F) << 6);
                    }
                  }
                }
                else
                {
                  v130 = (unsigned __int8)*v182;
                }
                if ( !v175.m128i_i32[2] && v130 == 92 )
                {
                  v130 = sub_62AB50(&v182, a4, *(_DWORD *)(a9 + 56), v176, 1);
                  if ( *a4 )
                    goto LABEL_988;
                  if ( v130 < 0 )
                  {
                    if ( v130 != -5 )
                    {
                      v182 = v140;
                      goto LABEL_304;
                    }
                    v130 = 8;
                  }
                }
                if ( v130 < (int)count )
                {
                  *a4 = 8;
                  goto LABEL_988;
                }
                if ( v130 == count )
                  goto LABEL_304;
                if ( v130 == 13 || v130 == 10 )
                  *(_DWORD *)(a9 + 80) |= 0x20u;
                if ( !v163 || v130 <= 255 && ((v176 & 1) == 0 || v130 <= 127) )
                  goto LABEL_298;
                v168 = 1;
                *v189++ = 2;
                v39 = _pcre_ord2utf8(count, v189);
                v189 += v39;
                v40 = _pcre_ord2utf8(v130, v189);
                v189 += v40;
                if ( (v176 & 1) != 0 && (int)count <= 127 )
                {
                  v130 = 127;
LABEL_298:
                  v146 += v130 - count + 1;
                  v152 = v130;
                  if ( !a10 )
                  {
                    while ( (int)count <= v130 )
                    {
                      src[(int)count / 8] |= 1 << (count & 7);
                      if ( (v176 & 1) != 0 )
                      {
                        v129 = *(unsigned __int8 *)(*(_DWORD *)(a9 + 4) + count);
                        src[v129 / 8] |= 1 << (v129 & 7);
                      }
                      ++count;
                    }
                  }
                  goto LABEL_312;
                }
                goto LABEL_312;
              case 0xCu:
                *a4 = 71;
                goto LABEL_988;
              case 0x1Au:
                if ( v182[1] == 92 && v182[2] == 69 )
                  v182 += 2;
                else
                  v175.m128i_i32[2] = 1;
                goto LABEL_312;
            }
            if ( -count != 25 )
              goto LABEL_183;
LABEL_312:
            count = (unsigned __int8)*++v182;
            if ( !count )
            {
              if ( !v165 )
                goto LABEL_317;
              v182 = v165;
              v165 = 0;
              count = (unsigned __int8)*++v182;
              if ( !count )
                goto LABEL_317;
            }
            if ( count == 93 && !v175.m128i_i32[2] )
              goto LABEL_317;
          }
          if ( count == 92 && v182[1] == 69 )
          {
            v175.m128i_i32[2] = 0;
            ++v182;
            goto LABEL_312;
          }
          goto LABEL_242;
        }
LABEL_317:
        if ( !count )
        {
          *a4 = 6;
          goto LABEL_988;
        }
        if ( v146 != 1 || v168 || v163 && kk && v152 >= 128 )
        {
          if ( v187 == -2 )
            v187 = -1;
          v166 = v187;
          v190 = v172;
          if ( v168 && (!v149 || (v176 & 0x20000000) != 0) )
          {
            *v189++ = 0;
            *v181++ = 108;
            v181 += 2;
            *v181 = kk != 0;
            if ( v146 <= 0 )
            {
              v181 = v189;
            }
            else
            {
              *v181++ |= 2u;
              sub_624F30(v181 + 32, v181, v189 - v181);
              memcpy((int)v181, (const __m128i *)src, 0x20u);
              v181 = v189 + 32;
            }
            v192[1] = (unsigned __int16)((_WORD)v181 - (_WORD)v192) >> 8;
            v192[2] = (_BYTE)v181 - (_BYTE)v192;
          }
          else
          {
            *v181++ = (kk != v149) + 106;
            if ( kk )
            {
              if ( !a10 )
              {
                for ( count = 0; (int)count < 32; ++count )
                  v181[count] = ~src[count];
              }
            }
            else
            {
              memcpy((int)v181, (const __m128i *)src, 0x20u);
            }
            v181 += 32;
          }
        }
        else
        {
          v190 = v172;
          if ( !kk )
          {
            if ( v163 && v152 > 127 )
            {
              v157 = _pcre_ord2utf8(v152, v158);
            }
            else
            {
              v158[0] = v152;
              v157 = 1;
            }
LABEL_971:
            v192 = v181;
            *v181++ = ((v176 & 1) != 0) + 29;
            for ( count = 0; (int)count < v157; ++count )
              *v181++ = v158[count];
            if ( v158[0] == 13 || v158[0] == 10 )
              *(_DWORD *)(a9 + 80) |= 0x20u;
            if ( v187 == -2 )
            {
              v166 = -1;
              v190 = v172;
              if ( v157 != 1 && v174 )
              {
                v172 = -1;
                v187 = -1;
              }
              else
              {
                v187 = v174 | v158[0];
                if ( v157 != 1 )
                  v172 = *(_DWORD *)(a9 + 84) | *(v181 - 1);
              }
            }
            else
            {
              v166 = v187;
              v190 = v172;
              if ( v157 == 1 || !v174 )
                v172 = *(_DWORD *)(a9 + 84) | v174 | *(v181 - 1);
            }
            break;
          }
          if ( v187 == -2 )
            v187 = -1;
          v166 = v187;
          *v181++ = ((v176 & 1) != 0) + 31;
          *v181++ = v152;
        }
        break;
      case 0x5Cu:
        v167 = v182;
        count = sub_62AB50(&v182, a4, *(_DWORD *)(a9 + 56), v176, 0);
        if ( *a4 )
          goto LABEL_988;
        if ( (count & 0x80000000) == 0 )
        {
          if ( v163 && (int)count > 127 )
          {
            v157 = _pcre_ord2utf8(count, v158);
          }
          else
          {
            v158[0] = count;
            v157 = 1;
          }
          goto LABEL_971;
        }
        if ( -count == 26 )
        {
          if ( v182[1] == 92 && v182[2] == 69 )
            v182 += 2;
          else
            v175.m128i_i32[2] = 1;
          break;
        }
        if ( -count == 25 )
          break;
        if ( v187 == -2 && (signed int)-count > 5 && (signed int)-count < 23 )
          v187 = -1;
        v166 = v187;
        v190 = v172;
        if ( -count == 27 )
        {
          v162 = *(_DWORD *)(a9 + 36);
          v147 = *++v182 != 60 ? 39 : 62;
          v145 = 0;
          v144 = 0;
          if ( v182[1] == 43 || v182[1] == 45 )
          {
            for ( mm = v182 + 2; (byte_72C7A8[(unsigned __int8)*mm] & 4) != 0; ++mm )
              ;
            if ( (unsigned __int8)*mm != v147 )
            {
              *a4 = 57;
              break;
            }
            ++v182;
          }
          else
          {
            v64 = 1;
            for ( nn = v182 + 1; *nn && (unsigned __int8)*nn != v147; ++nn )
            {
              if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*nn) & 4) == 0 )
                v64 = 0;
              if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*nn) & 0x10) == 0 )
                break;
            }
            if ( (unsigned __int8)*nn != v147 )
            {
              *a4 = 57;
              break;
            }
            if ( !v64 )
            {
              v153 = 1;
              goto LABEL_757;
            }
            ++v182;
          }
LABEL_783:
          v148 = (unsigned __int8)*v182;
          if ( v148 == 43 )
          {
            if ( (byte_72C7A8[(unsigned __int8)*++v182] & 4) == 0 )
            {
              *a4 = 63;
              goto LABEL_988;
            }
            goto LABEL_790;
          }
          if ( v148 != 45 )
            goto LABEL_790;
          if ( (byte_72C7A8[(unsigned __int8)v182[1]] & 4) != 0 )
          {
            ++v182;
LABEL_790:
            v156 = 0;
            while ( (byte_72C7A8[(unsigned __int8)*v182] & 4) != 0 )
              v156 = 10 * v156 + (unsigned __int8)*v182++ - 48;
            if ( (unsigned __int8)*v182 != v147 )
            {
              *a4 = 29;
              goto LABEL_988;
            }
            if ( v148 == 45 )
            {
              if ( !v156 )
              {
                *a4 = 58;
                goto LABEL_988;
              }
              v156 = *(_DWORD *)(a9 + 56) - v156 + 1;
              if ( (int)v156 <= 0 )
              {
                *a4 = 15;
                goto LABEL_988;
              }
            }
            else if ( v148 == 43 )
            {
              if ( !v156 )
              {
                *a4 = 58;
                goto LABEL_988;
              }
              v156 += *(_DWORD *)(a9 + 56);
            }
            goto LABEL_805;
          }
LABEL_821:
          v92 = 0;
          v91 = 0;
          v75 = &v91;
          while ( 2 )
          {
            if ( *v182 != 41 && *v182 != 58 )
            {
              v51 = (unsigned __int8)*v182++;
              switch ( v51 )
              {
                case '-':
                  v75 = &v92;
                  continue;
                case 'J':
                  *v75 |= 0x80000u;
                  *(_DWORD *)(a9 + 80) |= 0x10u;
                  continue;
                case 'U':
                  *v75 |= 0x200u;
                  continue;
                case 'X':
                  *v75 |= 0x40u;
                  continue;
                case 'i':
                  *v75 |= 1u;
                  continue;
                case 'm':
                  *v75 |= 2u;
                  continue;
                case 's':
                  *v75 |= 4u;
                  continue;
                case 'x':
                  *v75 |= 8u;
                  continue;
                default:
                  *a4 = 12;
                  --v182;
                  goto LABEL_988;
              }
            }
            break;
          }
          v154 = ~v92 & (v91 | v176);
          if ( *v182 != 41 )
          {
            v184 = 125;
            ++v182;
            goto LABEL_847;
          }
          if ( v181 == (unsigned __int8 *)(*(_DWORD *)(a9 + 20) + 3) && (!a10 || *a10 == 6) )
          {
            *(_DWORD *)(a9 + 76) = v154;
          }
          else
          {
            v180 = (v154 & 0x200) != 0;
            v171 = (v154 & 0x200) == 0;
            v174 = (v154 & 1) != 0 ? 0x100 : 0;
          }
          v176 = v154;
          *a1 = v154;
          v192 = 0;
        }
        else if ( -count == 28 )
        {
          if ( v182[1] != 60 && v182[1] != 39 && v182[1] != 123 )
          {
            *a4 = 69;
            break;
          }
          v153 = 0;
          if ( *++v182 == 60 )
            v50 = 62;
          else
            v50 = *v182 != 39 ? 125 : 39;
          v147 = v50;
LABEL_757:
          v81 = ++v182;
          while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v182) & 0x10) != 0 )
            ++v182;
          v84 = v182 - v81;
          if ( a10 )
          {
            if ( !v84 )
            {
              *a4 = 62;
              goto LABEL_988;
            }
            if ( (unsigned __int8)*v182 != v147 )
            {
              *a4 = 42;
              goto LABEL_988;
            }
            if ( v84 > 32 )
            {
              *a4 = 48;
              goto LABEL_988;
            }
            v70 = *(_DWORD *)(a9 + 28);
            *(_DWORD *)(a9 + 28) = v182;
            v156 = sub_62B550(a9, v81, v84, (v176 & 8) != 0, v163);
            *(_DWORD *)(a9 + 28) = v70;
            if ( (v156 & 0x80000000) != 0 )
              v156 = 0;
          }
          else
          {
            v78 = *(const char **)(a9 + 40);
            for ( i1 = 0; i1 < *(_DWORD *)(a9 + 44) && (strncmp(v81, v78 + 2, v84) || v78[v84 + 2]); ++i1 )
              v78 += *(_DWORD *)(a9 + 48);
            if ( i1 >= *(_DWORD *)(a9 + 44) )
            {
              v156 = sub_62B550(a9, v81, v84, (v176 & 8) != 0, v163);
              if ( (int)v156 <= 0 )
              {
                *a4 = 15;
                goto LABEL_988;
              }
            }
            else
            {
              v156 = *((unsigned __int8 *)v78 + 1) | (*(unsigned __int8 *)v78 << 8);
            }
          }
          if ( v153 )
          {
LABEL_805:
            v192 = v181;
            bracket = *(unsigned __int8 **)(a9 + 20);
            if ( !a10 )
            {
              *v181 = 0;
              if ( v156 )
                bracket = _pcre_find_bracket(*(unsigned __int8 **)(a9 + 20), *(unsigned __int8 **)(a9 + 20), v163, v156);
              if ( bracket )
              {
                if ( !(bracket[2] | (bracket[1] << 8)) && a8 <= 0 && sub_62C2B0(bracket, v181, a7, v163, a9) )
                {
                  *a4 = 40;
                  goto LABEL_988;
                }
              }
              else
              {
                if ( sub_62B550(a9, 0, v156, (v176 & 8) != 0, v163) < 0 )
                {
                  *a4 = 15;
                  goto LABEL_988;
                }
                bracket = (unsigned __int8 *)(v156 + *(_DWORD *)(a9 + 20));
                if ( *(_DWORD *)(a9 + 36) >= (unsigned int)(*(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100) )
                {
                  *a4 = sub_62A9B0(a9);
                  if ( *a4 )
                    goto LABEL_988;
                }
                **(_BYTE **)(a9 + 36) = (unsigned __int16)((_WORD)v181 + 1 - *(_WORD *)(a9 + 20)) >> 8;
                *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = (_BYTE)v181 + 1 - *(_BYTE *)(a9 + 20);
                *(_DWORD *)(a9 + 36) += 2;
              }
            }
            *v181 = 111;
            v181[1] = (unsigned __int16)((_WORD)bracket - *(_WORD *)(a9 + 20)) >> 8;
            v181[2] = (_BYTE)bracket - *(_BYTE *)(a9 + 20);
            v181 += 3;
            v191 = 0;
            if ( v187 == -2 )
              v187 = -1;
          }
          else
          {
LABEL_937:
            if ( v187 == -2 )
              v187 = -1;
            v192 = v181;
            *v181++ = ((v176 & 1) != 0) + 109;
            *v181 = BYTE1(v156);
            v181[1] = v156;
            v181 += 2;
            if ( (int)v156 >= 32 )
              v49 = 1;
            else
              v49 = 1 << v156;
            *(_DWORD *)(a9 + 68) |= v49;
            if ( (signed int)v156 > *(_DWORD *)(a9 + 64) )
              *(_DWORD *)(a9 + 64) = v156;
            for ( i2 = *(int **)(a9 + 32); i2; i2 = (int *)*i2 )
            {
              if ( *((unsigned __int16 *)i2 + 2) == v156 )
              {
                *((_WORD *)i2 + 3) = 1;
                goto LABEL_2;
              }
            }
          }
        }
        else
        {
          if ( (signed int)-count >= 35 )
          {
            v156 = -count - 35;
            goto LABEL_937;
          }
          if ( -count == 22 || -count == 15 || -count == 16 )
          {
            *a4 = 45;
            goto LABEL_988;
          }
          if ( (signed int)-count <= 5 || (signed int)-count >= 23 )
            v48 = 0;
          else
            v48 = v181;
          v192 = v48;
          if ( v163 || count != -14 )
            v47 = -count;
          else
            LOBYTE(v47) = 13;
          *v181++ = v47;
        }
        break;
      case 0x5Du:
        if ( (*(_DWORD *)(a9 + 76) & 0x2000000) == 0 )
          goto LABEL_967;
        *a4 = 64;
        goto LABEL_988;
      case 0x5Eu:
        v192 = 0;
        if ( (v176 & 2) != 0 )
        {
          if ( v187 == -2 )
            v187 = -1;
          *v181++ = 26;
        }
        else
        {
          *v181++ = 25;
        }
        break;
      case 0x7Bu:
        if ( !v151 )
          goto LABEL_967;
        v182 = (char *)sub_62B440(v182 + 1, &v183, &v185, a4);
        if ( *a4 )
          goto LABEL_988;
LABEL_355:
        if ( !v192 )
        {
          *a4 = 9;
          goto LABEL_988;
        }
        if ( !v183 )
        {
          v187 = v166;
          v172 = v190;
        }
        v175.m128i_i32[3] = v185 != v183 ? 0x200 : 0;
        v179 = 0;
        v143 = 0;
        v161 = v192;
        if ( v182[1] == 43 )
        {
          v169 = 0;
          v143 = 1;
          ++v182;
        }
        else if ( v182[1] == 63 )
        {
          v169 = v171;
          ++v182;
        }
        else
        {
          v169 = v180;
        }
        if ( *v192 == 111 )
        {
          sub_624F30(v192 + 3, v192, 3u);
          *v192 = 123;
          v192[1] = 0;
          v192[2] = 6;
          v192[6] = 114;
          v192[7] = 0;
          v192[8] = 6;
          v181 += 6;
          v186 = 9;
          if ( !a10 && *(_DWORD *)(a9 + 36) >= (unsigned int)(*(_DWORD *)(a9 + 16) + 2) )
          {
            v128 = (unsigned __int8 *)(*(unsigned __int8 *)(*(_DWORD *)(a9 + 36) - 1)
                                     | (*(unsigned __int8 *)(*(_DWORD *)(a9 + 36) - 2) << 8));
            if ( v128 == &v192[-*(_DWORD *)(a9 + 20) + 1] )
            {
              *(_BYTE *)(*(_DWORD *)(a9 + 36) - 2) = (unsigned __int16)((_WORD)v128 + 3) >> 8;
              *(_BYTE *)(*(_DWORD *)(a9 + 36) - 1) = (_BYTE)v128 + 3;
            }
          }
        }
        if ( *v192 == 29 || *v192 == 30 )
        {
          v179 = *v192 != 29 ? 0xD : 0;
          if ( v163 && (*(v181 - 1) & 0x80) != 0 )
          {
            for ( i3 = v181 - 1; (*i3 & 0xC0) == 0x80; --i3 )
              ;
            count = v181 - i3;
            memcpy((int)&v175, (const __m128i *)i3, v181 - i3);
            count |= 0x80u;
          }
          else
          {
            count = *(v181 - 1);
            if ( v183 > 1 )
              v172 = *(_DWORD *)(a9 + 84) | v174 | count;
          }
          if ( !v143 && v185 < 0 && sub_62C7F0((int)v192, v163, v182 + 1, v176, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
          goto LABEL_396;
        }
        if ( *v192 == 31 || *v192 == 32 )
        {
          v179 = *v192 != 31 ? 39 : 26;
          count = v192[1];
          if ( !v143 && v185 < 0 && sub_62C7F0((int)v192, v163, v182 + 1, v176, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
          goto LABEL_396;
        }
        if ( *v192 < 0x17u )
        {
          v179 = 52;
          count = *v192;
          if ( !v143 && v185 < 0 && sub_62C7F0((int)v192, v163, v182 + 1, v176, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
LABEL_396:
          if ( *v192 == 16 || *v192 == 15 )
          {
            v125 = v192[1];
            v124 = v192[2];
          }
          else
          {
            v124 = -1;
            v125 = -1;
          }
          v126 = v181;
          v181 = v192;
          if ( !v185 )
            goto LABEL_579;
          v169 += v179;
          if ( v183 )
          {
            if ( v183 == 1 )
            {
              if ( v185 == -1 )
              {
                *v181++ = v169 + 35;
              }
              else
              {
                v181 = v126;
                if ( v185 == 1 )
                  goto LABEL_579;
                *v181++ = v169 + 39;
                *v181 = (unsigned __int16)(v185 - 1) >> 8;
                v181[1] = v185 - 1;
                v181 += 2;
              }
            }
            else
            {
              *v181++ = v179 + 41;
              *v181 = BYTE1(v183);
              v181[1] = v183;
              v181 += 2;
              if ( v185 >= 0 )
              {
                if ( v185 != v183 )
                {
                  if ( v163 && (int)count >= 128 )
                  {
                    memcpy((int)v181, &v175, count & 7);
                    v181 += count & 7;
                  }
                  else
                  {
                    *v181++ = count;
                  }
                  if ( v125 >= 0 )
                  {
                    *v181++ = v125;
                    *v181++ = v124;
                  }
                  v185 -= v183;
                  if ( v185 == 1 )
                  {
                    *v181++ = v169 + 37;
                  }
                  else
                  {
                    *v181++ = v169 + 39;
                    *v181 = BYTE1(v185);
                    v181[1] = v185;
                    v181 += 2;
                  }
                }
              }
              else
              {
                if ( v163 && (int)count >= 128 )
                {
                  memcpy((int)v181, &v175, count & 7);
                  v181 += count & 7;
                }
                else
                {
                  *v181++ = count;
                  if ( v125 >= 0 )
                  {
                    *v181++ = v125;
                    *v181++ = v124;
                  }
                }
                *v181++ = v169 + 33;
              }
            }
          }
          else if ( v185 == -1 )
          {
            *v181++ = v169 + 33;
          }
          else if ( v185 == 1 )
          {
            *v181++ = v169 + 37;
          }
          else
          {
            *v181++ = v169 + 39;
            *v181 = BYTE1(v185);
            v181[1] = v185;
            v181 += 2;
          }
          if ( v163 && (int)count >= 128 )
          {
            memcpy((int)v181, &v175, count & 7);
            v181 += count & 7;
          }
          else
          {
            *v181++ = count;
          }
LABEL_544:
          if ( v143 )
          {
            if ( *v161 == 93 )
            {
              if ( v161[3] == 16 || v161[3] == 15 )
                v55 = 2;
              else
                v55 = 0;
              v161 += v55 + (unsigned __int8)_pcre_OP_lengths[*v161];
            }
            else if ( *v161 == 41 || *v161 == 67 )
            {
              v161 += (unsigned __int8)_pcre_OP_lengths[*v161];
              if ( v163 )
              {
                if ( *(v161 - 1) >= 0xC0u )
                  v161 += (unsigned __int8)_pcre_utf8_table4[*(v161 - 1) & 0x3F];
              }
            }
            v100 = v181 - v161;
            if ( v181 - v161 > 0 )
            {
              switch ( *v161 )
              {
                case '!':
                  *v161 = 42;
                  break;
                case '#':
                  *v161 = 43;
                  break;
                case '%':
                  *v161 = 44;
                  break;
                case '\'':
                  *v161 = 45;
                  break;
                case '.':
                  *v161 = 55;
                  break;
                case '0':
                  *v161 = 56;
                  break;
                case '2':
                  *v161 = 57;
                  break;
                case '4':
                  *v161 = 58;
                  break;
                case ';':
                  *v161 = 68;
                  break;
                case '=':
                  *v161 = 69;
                  break;
                case '?':
                  *v161 = 70;
                  break;
                case 'A':
                  *v161 = 71;
                  break;
                case 'H':
                  *v161 = 81;
                  break;
                case 'J':
                  *v161 = 82;
                  break;
                case 'L':
                  *v161 = 83;
                  break;
                case 'N':
                  *v161 = 84;
                  break;
                case 'U':
                  *v161 = 94;
                  break;
                case 'W':
                  *v161 = 95;
                  break;
                case 'Y':
                  *v161 = 96;
                  break;
                case '[':
                  *v161 = 97;
                  break;
                default:
                  *v181 = 0;
                  sub_62C470(v161, 3, v163, a9, v162);
                  sub_624F30(v161 + 3, v161, v100);
                  v181 += 3;
                  v100 += 3;
                  *v161 = 123;
                  *v181++ = 114;
                  *v181 = BYTE1(v100);
                  v181[1] = v100;
                  v181 += 2;
                  v161[1] = BYTE1(v100);
                  v161[2] = v100;
                  break;
              }
            }
          }
          goto LABEL_579;
        }
        if ( *v192 == 106 || *v192 == 107 || *v192 == 108 || *v192 == 109 || *v192 == 110 )
        {
          if ( !v185 )
          {
            v181 = v192;
            goto LABEL_579;
          }
          if ( v183 || v185 != -1 )
          {
            if ( v183 == 1 && v185 == -1 )
            {
              *v181++ = v169 + 100;
            }
            else if ( v183 || v185 != 1 )
            {
              *v181++ = v169 + 104;
              *v181 = BYTE1(v183);
              v181[1] = v183;
              v181 += 2;
              if ( v185 == -1 )
                v185 = 0;
              *v181 = BYTE1(v185);
              v181[1] = v185;
              v181 += 2;
            }
            else
            {
              *v181++ = v169 + 102;
            }
          }
          else
          {
            *v181++ = v169 + 98;
          }
          goto LABEL_544;
        }
        if ( *v192 >= 0x77u && *v192 <= 0x81u )
        {
          v121 = v181 - v192;
          v123 = 0;
          v120 = 0;
          if ( *v192 == 129 && v192[3] == 139 )
            goto LABEL_579;
          if ( *v192 < 0x7Bu )
          {
            if ( v183 > 0 )
              goto LABEL_579;
            if ( (unsigned int)v185 >= 2 )
              v185 = 1;
          }
          if ( v183 )
          {
            if ( v183 > 1 )
            {
              if ( a10 )
              {
                v118 = v186 * (v183 - 1);
                if ( (double)(v183 - 1) * (double)v186 > 2147483647.0 || 2147483627 - *a10 < v118 )
                {
                  *a4 = 20;
                  goto LABEL_988;
                }
                *a10 += v118;
              }
              else
              {
                if ( v191 && v172 < 0 )
                  v172 = v187;
                for ( i4 = 1; i4 < v183; ++i4 )
                {
                  v116 = *(_DWORD *)(a9 + 36);
                  memcpy((int)v181, (const __m128i *)v192, v121);
                  while ( *(_DWORD *)(a9 + 36) > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 - (v116 - v162) )
                  {
                    v115 = v162 - *(_DWORD *)(a9 + 16);
                    v114 = v116 - *(_DWORD *)(a9 + 16);
                    *a4 = sub_62A9B0(a9);
                    if ( *a4 )
                      goto LABEL_988;
                    v162 = v115 + *(_DWORD *)(a9 + 16);
                    v116 = v114 + *(_DWORD *)(a9 + 16);
                  }
                  for ( i5 = v162; i5 < v116; i5 += 2 )
                  {
                    **(_BYTE **)(a9 + 36) = (unsigned __int16)(v121 + _byteswap_ushort(*(_WORD *)i5)) >> 8;
                    *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = v121 + *(_BYTE *)(i5 + 1);
                    *(_DWORD *)(a9 + 36) += 2;
                  }
                  v162 = v116;
                  v181 += v121;
                }
              }
            }
            if ( v185 > 0 )
              v185 -= v183;
          }
          else
          {
            if ( v185 > 1 )
            {
              *v181 = 0;
              sub_62C470(v192, 4, v163, a9, v162);
              sub_624F30(v192 + 4, v192, v121);
              v181 += 4;
              *v192++ = v169 - 116;
              *v192++ = 125;
              if ( v123 )
                v58 = (unsigned __int8 *)(v192 - v123);
              else
                v58 = 0;
              v119 = v58;
              v123 = v192;
              *v192 = BYTE1(v58);
              v192[1] = (unsigned __int8)v119;
              v192 += 2;
            }
            else
            {
              *v181 = 0;
              sub_62C470(v192, 1, v163, a9, v162);
              sub_624F30(v192 + 1, v192, v121);
              ++v181;
              if ( !v185 )
              {
                *v192++ = -101;
                goto LABEL_579;
              }
              v120 = v192;
              *v192++ = v169 - 116;
            }
            --v185;
          }
          if ( v185 < 0 )
          {
            v103 = v181 - 3;
            v104 = &v181[-(*(v181 - 1) | (*(v181 - 2) << 8)) - 3];
            if ( (*v104 == 123 || *v104 == 124) && v143 )
              *v104 = 125;
            if ( *v104 == 123 || *v104 == 124 )
            {
              *v103 = v169 + 115;
            }
            else
            {
              if ( !a10 )
              {
                v102 = v104;
                while ( !sub_62BBD0(v102, v103, v163, a9) )
                {
                  v102 += v102[2] | (v102[1] << 8);
                  if ( *v102 != 113 )
                    goto LABEL_531;
                }
                *v104 += 5;
              }
LABEL_531:
              if ( v143 )
              {
                if ( *v104 == 129 || *v104 == 134 )
                {
                  v101 = v181 - v104;
                  *v181 = 0;
                  sub_62C470(v104, 3, v163, a9, v162);
                  sub_624F30(v104 + 3, v104, v101);
                  v181 += 3;
                  v101 += 3;
                  *v104 = 126;
                  *v181++ = 117;
                  *v181 = BYTE1(v101);
                  v181[1] = v101;
                  v181 += 2;
                  v104[1] = BYTE1(v101);
                  v104[2] = v101;
                }
                else
                {
                  ++*v104;
                  *v103 = 117;
                }
                if ( v120 )
                  *v120 = -114;
                if ( v183 < 2 )
                  v143 = 0;
              }
              else
              {
                *v103 = v169 + 115;
              }
            }
          }
          else
          {
            if ( a10 && v185 > 0 )
            {
              v113 = v185 * (v186 + 7) - 6;
              if ( (double)v185 * (double)(v186 + 7) > 2147483647.0 || 2147483627 - *a10 < v113 )
              {
                *a4 = 20;
                goto LABEL_988;
              }
              *a10 += v113;
            }
            else
            {
              for ( i4 = v185 - 1; i4 >= 0; --i4 )
              {
                v111 = *(_DWORD *)(a9 + 36);
                *v181++ = v169 - 116;
                if ( i4 )
                {
                  *v181++ = 125;
                  if ( v123 )
                    v57 = (unsigned __int8 *)(v181 - v123);
                  else
                    v57 = 0;
                  v110 = v57;
                  v123 = v181;
                  *v181 = BYTE1(v57);
                  v181[1] = (unsigned __int8)v110;
                  v181 += 2;
                }
                memcpy((int)v181, (const __m128i *)v192, v121);
                while ( *(_DWORD *)(a9 + 36) > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 - (v111 - v162) )
                {
                  v109 = v162 - *(_DWORD *)(a9 + 16);
                  v108 = v111 - *(_DWORD *)(a9 + 16);
                  *a4 = sub_62A9B0(a9);
                  if ( *a4 )
                    goto LABEL_988;
                  v162 = v109 + *(_DWORD *)(a9 + 16);
                  v111 = v108 + *(_DWORD *)(a9 + 16);
                }
                for ( i6 = v162; i6 < v111; i6 += 2 )
                {
                  **(_BYTE **)(a9 + 36) = (unsigned __int16)((i4 != 0 ? 4 : 1) + v121 + _byteswap_ushort(*(_WORD *)i6)) >> 8;
                  *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = (i4 != 0 ? 4 : 1) + v121 + *(_BYTE *)(i6 + 1);
                  *(_DWORD *)(a9 + 36) += 2;
                }
                v162 = v111;
                v181 += v121;
              }
            }
            while ( v123 )
            {
              v105 = (unsigned __int8 *)(v181 - v123 + 1);
              v106 = v123 - 1;
              v107 = v123[1] | (*v123 << 8);
              if ( v107 )
                v56 = &v123[-v107];
              else
                v56 = 0;
              v123 = v56;
              *v181++ = 114;
              *v181 = BYTE1(v105);
              v181[1] = (unsigned __int8)v105;
              v181 += 2;
              v106[1] = BYTE1(v105);
              v106[2] = (unsigned __int8)v105;
            }
          }
          goto LABEL_544;
        }
        if ( *v192 != 151 )
        {
          *a4 = 11;
          goto LABEL_988;
        }
LABEL_579:
        v192 = 0;
        *(_DWORD *)(a9 + 84) |= v175.m128i_u32[3];
        break;
      default:
        goto LABEL_967;
    }
LABEL_2:
    ++v182;
  }
  *a4 = 52;
LABEL_988:
  *a3 = v182;
  return 0;
}
