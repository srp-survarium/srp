int __cdecl sub_509C40(
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
  char *v80; // [esp+9Ch] [ebp-1F0h]
  char *v81; // [esp+9Ch] [ebp-1F0h]
  char *siz; // [esp+A0h] [ebp-1ECh]
  int siza; // [esp+A0h] [ebp-1ECh]
  int sizb; // [esp+A0h] [ebp-1ECh]
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
  unsigned int i5; // [esp+FCh] [ebp-190h]
  int v113; // [esp+100h] [ebp-18Ch]
  unsigned int v114; // [esp+104h] [ebp-188h]
  unsigned int v115; // [esp+108h] [ebp-184h]
  unsigned int v116; // [esp+10Ch] [ebp-180h]
  unsigned int i4; // [esp+110h] [ebp-17Ch]
  int v118; // [esp+114h] [ebp-178h]
  unsigned __int8 *v119; // [esp+118h] [ebp-174h]
  unsigned __int8 *v120; // [esp+11Ch] [ebp-170h]
  unsigned int v121; // [esp+120h] [ebp-16Ch]
  int i3; // [esp+124h] [ebp-168h]
  unsigned __int8 *v123; // [esp+128h] [ebp-164h]
  int v124; // [esp+12Ch] [ebp-160h]
  int v125; // [esp+130h] [ebp-15Ch]
  unsigned __int8 *v126; // [esp+134h] [ebp-158h]
  unsigned __int8 *src; // [esp+138h] [ebp-154h]
  unsigned __int8 *v128; // [esp+13Ch] [ebp-150h]
  int v129; // [esp+140h] [ebp-14Ch]
  int v130; // [esp+144h] [ebp-148h]
  int v131; // [esp+148h] [ebp-144h]
  int v132; // [esp+14Ch] [ebp-140h]
  _BYTE *v133; // [esp+150h] [ebp-13Ch]
  int v134; // [esp+154h] [ebp-138h]
  int v135; // [esp+158h] [ebp-134h]
  unsigned __int8 v136[32]; // [esp+15Ch] [ebp-130h] BYREF
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
  unsigned __int8 v175[8]; // [esp+218h] [ebp-74h] BYREF
  int v176; // [esp+220h] [ebp-6Ch]
  int v177; // [esp+224h] [ebp-68h]
  int v178; // [esp+228h] [ebp-64h]
  unsigned __int8 dst[32]; // [esp+22Ch] [ebp-60h] BYREF
  unsigned __int8 *v180; // [esp+250h] [ebp-3Ch]
  int v181; // [esp+254h] [ebp-38h]
  BOOL v182; // [esp+258h] [ebp-34h]
  unsigned __int8 *v183; // [esp+25Ch] [ebp-30h]
  char *v184; // [esp+260h] [ebp-2Ch] BYREF
  int v185; // [esp+264h] [ebp-28h] BYREF
  int v186; // [esp+268h] [ebp-24h]
  int v187; // [esp+26Ch] [ebp-20h] BYREF
  int v188; // [esp+270h] [ebp-1Ch] BYREF
  int v189; // [esp+274h] [ebp-18h]
  unsigned __int8 *v190; // [esp+278h] [ebp-14h]
  unsigned __int8 *v191; // [esp+27Ch] [ebp-10h]
  int v192; // [esp+280h] [ebp-Ch]
  int v193; // [esp+284h] [ebp-8h]
  unsigned __int8 *v194; // [esp+288h] [ebp-4h]

  v185 = 0;
  v187 = 0;
  v186 = 0;
  v178 = *a1;
  v173 = 0;
  v188 = 0;
  v183 = *a2;
  v160 = v183;
  v190 = v183;
  v176 = 0;
  v193 = 0;
  v184 = *a3;
  v165 = 0;
  v194 = 0;
  v159 = 0;
  v162 = 0;
  v163 = (v178 & 0x800) != 0;
  v182 = (v178 & 0x200) != 0;
  v171 = (v178 & 0x200) == 0;
  v192 = -2;
  v166 = -2;
  v172 = -2;
  v189 = -2;
  v174 = (v178 & 1) != 0 ? 0x100 : 0;
  while ( 1 )
  {
    count = (unsigned __int8)*v184;
    if ( !count && v165 )
    {
      v184 = v165;
      v165 = 0;
      count = (unsigned __int8)*v184;
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
    if ( (unsigned int)v183 > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 )
      break;
    if ( v183 < v160 )
      v183 = v160;
    if ( 2147483627 - *a10 < v183 - v160 )
    {
      *a4 = 20;
      goto LABEL_988;
    }
    *a10 += v183 - v160;
    if ( v194 )
    {
      if ( v194 > v190 )
      {
        sub_509B90(v190, v194, v183 - v194);
        v183 -= v194 - v190;
        v194 = v190;
      }
    }
    else
    {
      v183 = v190;
    }
    v160 = v183;
LABEL_21:
    if ( v176 && count )
    {
      if ( count == 92 && v184[1] == 69 )
      {
        v176 = 0;
        ++v184;
        goto LABEL_2;
      }
      if ( v159 )
      {
        if ( !a10 )
          sub_511400(v159, v184, a9);
        v159 = 0;
      }
      if ( (v178 & 0x4000) != 0 )
      {
        v159 = v183;
        v183 = (unsigned __int8 *)sub_5113A0(v183, v184, a9);
      }
LABEL_967:
      v157 = 1;
      v158[0] = count;
      if ( v163 && (int)count >= 192 )
      {
        while ( (v184[1] & 0xC0) == 0x80 )
          v158[v157++] = *++v184;
      }
      goto LABEL_971;
    }
    v62 = count == 42 || count == 43 || count == 63 || count == 123 && sub_50F6E0(v184 + 1);
    v151 = v62;
    if ( !v62 )
    {
      if ( v159 )
      {
        v10 = v173--;
        if ( v10 <= 0 )
        {
          if ( !a10 )
            sub_511400(v159, v184, a9);
          v159 = 0;
        }
      }
    }
    if ( (v178 & 8) != 0 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + count) & 1) != 0 )
        goto LABEL_2;
      if ( count == 35 )
      {
        ++v184;
        while ( *v184 )
        {
          if ( *(_DWORD *)(a9 + 96) )
          {
            v61 = (unsigned int)v184 < *(_DWORD *)(a9 + 28)
               && _pcre_is_newline(v184, *(_DWORD *)(a9 + 96), *(_DWORD *)(a9 + 28), a9 + 100, v163);
            v60 = v61;
          }
          else
          {
            v59 = (unsigned int)v184 <= *(_DWORD *)(a9 + 28) - *(_DWORD *)(a9 + 100)
               && *v184 == *(_BYTE *)(a9 + 104)
               && (*(_DWORD *)(a9 + 100) == 1 || v184[1] == *(_BYTE *)(a9 + 105));
            v60 = v59;
          }
          if ( v60 )
          {
            v184 = &v184[*(_DWORD *)(a9 + 100) - 1];
            break;
          }
          ++v184;
          if ( v163 )
          {
            while ( (*v184 & 0xC0) == 0x80 )
              ++v184;
          }
        }
        if ( *v184 )
          goto LABEL_2;
        count = 0;
      }
    }
    if ( (v178 & 0x4000) != 0 && !v151 )
    {
      v159 = v183;
      v183 = (unsigned __int8 *)sub_5113A0(v183, v184, a9);
    }
    switch ( count )
    {
      case 0u:
      case 0x29u:
      case 0x7Cu:
        *a5 = v189;
        *a6 = v172;
        *a2 = v183;
        *a3 = v184;
        if ( !a10 )
          return 1;
        if ( 2147483627 - *a10 < v183 - v160 )
        {
          *a4 = 20;
          goto LABEL_988;
        }
        *a10 += v183 - v160;
        return 1;
      case 0x24u:
        v194 = 0;
        *v183++ = ((v178 & 2) != 0) + 27;
        break;
      case 0x28u:
        v154 = v178;
        v145 = 0;
        v186 = 127;
        v162 = *(_DWORD *)(a9 + 36);
        v144 = 0;
        if ( *++v184 == 42 && ((*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v184[1]) & 2) != 0 || v184[1] == 58) )
        {
          v96 = 0;
          last = (char *)&unk_8880C0;
          first = v184 + 1;
          v98 = 0;
          v194 = 0;
          do
            ++v184;
          while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v184) & 2) != 0 );
          v95 = v184 - first;
          if ( *v184 == 58 )
          {
            v98 = (unsigned __int8 *)++v184;
            while ( *v184 && *v184 != 41 )
              ++v184;
            v96 = v184 - (char *)v98;
          }
          if ( *v184 != 41 )
          {
            *a4 = 60;
            goto LABEL_988;
          }
          for ( i = 0; ; ++i )
          {
            if ( i >= 9 )
              goto LABEL_618;
            if ( v95 == dword_8880F0[3 * i] && !strncmp(first, last, v95) )
              break;
            last += dword_8880F0[3 * i] + 1;
          }
          if ( dword_8880F4[3 * i] == 152 )
          {
            if ( v96 )
            {
              *a4 = 59;
              goto LABEL_988;
            }
            *(_DWORD *)(a9 + 88) = 1;
            for ( j = *(int **)(a9 + 32); j; j = (int *)*j )
            {
              *v183++ = -102;
              *v183 = HIBYTE(*((_WORD *)j + 2));
              v183[1] = *((_WORD *)j + 2);
              v183 += 2;
            }
            *v183++ = (*(_DWORD *)(a9 + 72) > 0) - 104;
            if ( v189 == -2 )
              v189 = -1;
          }
          else if ( v96 )
          {
            if ( dword_8880F8[3 * i] < 0 )
            {
              *a4 = 59;
              goto LABEL_988;
            }
            *v183 = dword_8880F8[3 * i];
            v43 = *v183++;
            if ( v43 == 149 )
              *(_DWORD *)(a9 + 80) |= 0x40u;
            *v183++ = v96;
            memcpy(v183, v98, v96);
            v183 += v96;
            *v183++ = 0;
          }
          else
          {
            if ( dword_8880F4[3 * i] < 0 )
            {
              *a4 = 66;
              goto LABEL_988;
            }
            *v183 = dword_8880F4[3 * i];
            v42 = *v183++;
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
          if ( *v184 == 63 )
          {
            switch ( *++v184 )
            {
              case '!':
                if ( *++v184 == 41 )
                {
                  *v183++ = -105;
                  v194 = 0;
                  goto LABEL_2;
                }
                v186 = 120;
                ++*(_DWORD *)(a9 + 72);
                break;
              case '#':
                ++v184;
                while ( *v184 && *v184 != 41 )
                  ++v184;
                if ( *v184 )
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
                v186 = 129;
                if ( v184[1] == 63 && (v184[2] == 61 || v184[2] == 33 || v184[2] == 60) )
                  break;
                v183[3] = -121;
                v145 = 3;
                v148 = -1;
                if ( v184[1] == 82 && v184[2] == 38 )
                {
                  v147 = -1;
                  v184 += 2;
                  v183[3] = -119;
                }
                else if ( v184[1] == 60 )
                {
                  v147 = 62;
                  ++v184;
                }
                else if ( v184[1] == 39 )
                {
                  v147 = 39;
                  ++v184;
                }
                else
                {
                  v147 = 0;
                  if ( v184[1] == 45 || v184[1] == 43 )
                    v148 = (unsigned __int8)*++v184;
                }
                if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v184[1]) & 0x10) == 0 )
                {
                  ++v184;
                  *a4 = 28;
                  goto LABEL_988;
                }
                v156 = 0;
                v79 = ++v184;
                while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v184) & 0x10) != 0 )
                {
                  if ( (v156 & 0x80000000) == 0 )
                  {
                    if ( (byte_888D30[(unsigned __int8)*v184] & 4) != 0 )
                      v54 = 10 * v156 + (unsigned __int8)*v184 - 48;
                    else
                      v54 = -1;
                    v156 = v54;
                  }
                  ++v184;
                }
                siz = (char *)(v184 - v79);
                if ( v147 > 0 && (v44 = (unsigned __int8)*v184, ++v184, v44 != v147)
                  || (v45 = (unsigned __int8)*v184, ++v184, v45 != 41) )
                {
                  --v184;
                  *a4 = 26;
                  goto LABEL_988;
                }
                if ( !a10 )
                {
                  if ( v148 <= 0 )
                  {
                    v76 = *(const char **)(a9 + 40);
                    for ( k = 0; k < *(_DWORD *)(a9 + 44) && strncmp(v79, v76 + 2, (unsigned int)siz); ++k )
                      v76 += *(_DWORD *)(a9 + 48);
                    if ( k >= *(_DWORD *)(a9 + 44) )
                    {
                      v86 = sub_5101B0(a9, v79, (unsigned int)siz, (v178 & 8) != 0, v163);
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
                          for ( m = 1; m < (int)siz; ++m )
                          {
                            if ( (byte_888D30[(unsigned __int8)v79[m]] & 4) == 0 )
                            {
                              *a4 = 15;
                              goto LABEL_988;
                            }
                            v156 = 10 * v156 + (unsigned __int8)v79[m] - 48;
                          }
                          if ( !v156 )
                            v156 = 0xFFFF;
                          v183[3] = -119;
                          v183[4] = BYTE1(v156);
                          v183[5] = v156;
                        }
                        else if ( siz == (char *)6 && !strncmp(v79, "DEFINE", 6u) )
                        {
                          v183[3] = -117;
                          v145 = 1;
                        }
                        else
                        {
                          if ( (int)v156 <= 0 || (signed int)v156 > *(_DWORD *)(a9 + 60) )
                          {
                            *a4 = v156 != 0 ? 15 : 35;
                            goto LABEL_988;
                          }
                          v183[4] = BYTE1(v156);
                          v183[5] = v156;
                        }
                      }
                      else
                      {
                        v183[4] = BYTE1(v86);
                        v183[5] = v86;
                        ++v183[3];
                      }
                    }
                    else
                    {
                      v156 = *((unsigned __int8 *)v76 + 1) | (*(unsigned __int8 *)v76 << 8);
                      v183[4] = BYTE1(v156);
                      v183[5] = v156;
                      ++v183[3];
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
                    v183[4] = BYTE1(v156);
                    v183[5] = v156;
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
                v52 = v184[1];
                if ( v52 == 33 )
                {
                  v186 = 122;
                  ++*(_DWORD *)(a9 + 72);
                  v184 += 2;
                  break;
                }
                if ( v52 == 61 )
                {
                  v186 = 121;
                  ++*(_DWORD *)(a9 + 72);
                  v184 += 2;
                  break;
                }
                if ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)v184[1]) & 0x10) == 0 )
                {
                  ++v184;
                  *a4 = 24;
                  goto LABEL_988;
                }
LABEL_721:
                v147 = *v184++ != 60 ? 39 : 62;
                v80 = v184;
                while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v184) & 0x10) != 0 )
                  ++v184;
                siza = v184 - v80;
                if ( !a10 )
                {
                  v73 = 0;
                  v77 = *(unsigned __int8 **)(a9 + 40);
                  for ( n = 0; ; ++n )
                  {
                    if ( n >= *(_DWORD *)(a9 + 44) )
                      goto LABEL_745;
                    v72 = memcmp((unsigned __int8 *)v80, v77 + 2, siza);
                    if ( !v72 )
                    {
                      if ( v77[siza + 2] )
                      {
                        v72 = -1;
                      }
                      else
                      {
                        if ( (v77[1] | (*v77 << 8)) != *(_DWORD *)(a9 + 56) + 1 && (v178 & 0x80000) == 0 )
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
                  sub_509B90(&v77[*(_DWORD *)(a9 + 48)], v77, *(_DWORD *)(a9 + 48) * (*(_DWORD *)(a9 + 44) - n));
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
                  memcpy(v77 + 2, (unsigned __int8 *)v80, siza);
                  v77[siza + 2] = 0;
                  goto LABEL_755;
                }
                if ( (unsigned __int8)*v184 != v147 )
                {
                  *a4 = 42;
                  goto LABEL_988;
                }
                if ( *(int *)(a9 + 44) >= 10000 )
                {
                  *a4 = 49;
                  goto LABEL_988;
                }
                if ( siza + 3 > *(_DWORD *)(a9 + 48) )
                {
                  *(_DWORD *)(a9 + 48) = siza + 3;
                  if ( siza > 32 )
                  {
                    *a4 = 48;
                    goto LABEL_988;
                  }
                }
LABEL_755:
                ++*(_DWORD *)(a9 + 44);
                ++v184;
                goto LABEL_846;
              case '=':
                v186 = 119;
                ++*(_DWORD *)(a9 + 72);
                ++v184;
                break;
              case '>':
                v186 = 123;
                ++v184;
                break;
              case 'C':
                v159 = v183;
                v173 = 1;
                *v183++ = 112;
                for ( jj = 0; (byte_888D30[(unsigned __int8)*++v184] & 4) != 0; jj = 10 * jj
                                                                                   + (unsigned __int8)*v184
                                                                                   - 48 )
                  ;
                if ( *v184 != 41 )
                {
                  *a4 = 39;
                  goto LABEL_988;
                }
                if ( jj > 255 )
                {
                  *a4 = 38;
                  goto LABEL_988;
                }
                *v183++ = jj;
                *v183 = (unsigned __int16)((_WORD)v184 - *(_WORD *)(a9 + 24) + 1) >> 8;
                v183[1] = (_BYTE)v184 - *(_BYTE *)(a9 + 24) + 1;
                v183[2] = 0;
                v183[3] = 0;
                v183 += 4;
                v194 = 0;
                goto LABEL_2;
              case 'P':
                if ( *++v184 == 61 || *v184 == 62 )
                {
                  v153 = *v184 == 62;
                  v147 = 41;
                  goto LABEL_757;
                }
                if ( *v184 != 60 )
                {
                  *a4 = 41;
                  goto LABEL_988;
                }
                goto LABEL_721;
              case 'R':
                ++v184;
LABEL_782:
                v147 = 41;
                goto LABEL_783;
              case '|':
                v144 = 1;
LABEL_630:
                v186 = 125;
                ++v184;
                break;
              default:
                goto LABEL_821;
            }
          }
          else if ( (v178 & 0x1000) != 0 )
          {
            v186 = 125;
          }
          else
          {
LABEL_846:
            v183[3] = (unsigned __int16)++*(_DWORD *)(a9 + 56) >> 8;
            v183[4] = *(_DWORD *)(a9 + 56);
            v145 = 2;
          }
LABEL_847:
          v194 = v183;
          *v183 = v186;
          v161 = v183;
          v170 = *(_DWORD *)(a9 + 84);
          v141 = *(_DWORD *)(a9 + 56);
          v188 = 0;
          if ( v186 == 121 || v186 == 122 )
            v46 = sub_5096F0(
                    v154,
                    &v161,
                    &v184,
                    a4,
                    1,
                    v144,
                    v145,
                    a8 + (v186 == 129),
                    &v150,
                    &v155,
                    a7,
                    (_DWORD *)a9,
                    a10 != 0 ? &v188 : 0);
          else
            v46 = sub_5096F0(
                    v154,
                    &v161,
                    &v184,
                    a4,
                    0,
                    v144,
                    v145,
                    a8 + (v186 == 129),
                    &v150,
                    &v155,
                    a7,
                    (_DWORD *)a9,
                    a10 != 0 ? &v188 : 0);
          if ( !v46 )
            goto LABEL_988;
          if ( v186 == 123 && *(_DWORD *)(a9 + 56) <= v141 )
            *v183 = 124;
          if ( v186 >= 119 && v186 <= 122 )
            --*(_DWORD *)(a9 + 72);
          if ( v186 == 129 && !a10 )
          {
            v67 = v183;
            v68 = 0;
            do
            {
              ++v68;
              v67 += v67[2] | (v67[1] << 8);
            }
            while ( *v67 != 114 );
            if ( v183[3] == 139 )
            {
              if ( v68 > 1 )
              {
                *a4 = 54;
                goto LABEL_988;
              }
              v186 = 139;
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
          if ( *v184 != 41 )
          {
            *a4 = 14;
            goto LABEL_988;
          }
          if ( a10 )
          {
            if ( 2147483627 - *a10 < v188 - 6 )
            {
              *a4 = 20;
              goto LABEL_988;
            }
            *a10 = v188 + *a10 - 6;
            *++v183 = 0;
            v183[1] = 3;
            v183 += 2;
            *v183++ = 114;
            *v183 = 0;
            v183[1] = 3;
            v183 += 2;
          }
          else
          {
            v183 = v161;
            if ( v186 != 139 )
            {
              v192 = v172;
              v166 = v189;
              v193 = 0;
              if ( v186 < 123 )
              {
                if ( v186 == 119 && v155 >= 0 )
                  v172 = v155;
              }
              else
              {
                if ( v189 == -2 )
                {
                  if ( v150 < 0 )
                  {
                    v189 = -1;
                  }
                  else
                  {
                    v189 = v150;
                    v193 = 1;
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
        v185 = 0;
        v187 = -1;
        goto LABEL_355;
      case 0x2Bu:
        v185 = 1;
        v187 = -1;
        goto LABEL_355;
      case 0x2Eu:
        if ( v189 == -2 )
          v189 = -1;
        v166 = v189;
        v192 = v172;
        v194 = v183;
        *v183++ = ((v178 & 4) != 0) + 12;
        break;
      case 0x3Fu:
        v185 = 0;
        v187 = 1;
        goto LABEL_355;
      case 0x5Bu:
        v194 = v183;
        if ( (v184[1] == 58 || v184[1] == 46 || v184[1] == 61) && sub_510F60(v184, &v167) )
        {
          *a4 = v184[1] != 58 ? 31 : 13;
          goto LABEL_988;
        }
        for ( kk = 0; ; kk = 1 )
        {
          while ( 1 )
          {
            count = (unsigned __int8)*++v184;
            if ( count != 92 )
              break;
            if ( v184[1] == 69 )
            {
              ++v184;
            }
            else
            {
              if ( strncmp(v184 + 1, "Q\\E", 3u) )
                goto LABEL_108;
              v184 += 3;
            }
          }
          if ( kk || count != 94 )
            break;
        }
LABEL_108:
        if ( count == 93 && (*(_DWORD *)(a9 + 76) & 0x2000000) != 0 )
        {
          *v183++ = kk != 0 ? 13 : -105;
          if ( v189 == -2 )
            v189 = -1;
          v166 = v189;
          break;
        }
        v149 = 0;
        v146 = 0;
        v152 = -1;
        memset((int)dst, 0, sizeof(dst));
        v168 = 0;
        v191 = v183 + 4;
        v180 = v183 + 4;
        if ( count )
        {
          while ( 1 )
          {
            if ( v163 )
            {
              if ( (int)count > 127 )
              {
                count = (unsigned __int8)*v184;
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
                          count = v184[5] & 0x3F
                                | ((v184[4] & 0x3F) << 6)
                                | ((v184[3] & 0x3F) << 12)
                                | ((v184[2] & 0x3F) << 18)
                                | ((v184[1] & 0x3F) << 24)
                                | ((count & 1) << 30);
                          v184 += 5;
                        }
                        else
                        {
                          count = v184[4] & 0x3F
                                | ((v184[3] & 0x3F) << 6)
                                | ((v184[2] & 0x3F) << 12)
                                | ((v184[1] & 0x3F) << 18)
                                | ((count & 3) << 24);
                          v184 += 4;
                        }
                      }
                      else
                      {
                        count = v184[3] & 0x3F
                              | ((v184[2] & 0x3F) << 6)
                              | ((v184[1] & 0x3F) << 12)
                              | ((count & 7) << 18);
                        v184 += 3;
                      }
                    }
                    else
                    {
                      count = v184[2] & 0x3F | ((v184[1] & 0x3F) << 6) | ((count & 0xF) << 12);
                      v184 += 2;
                    }
                  }
                  else
                  {
                    count = *++v184 & 0x3F | ((count & 0x1F) << 6);
                  }
                }
              }
            }
            if ( a10 )
            {
              *a10 += v191 - v180;
              v191 = v180;
            }
            if ( v176 )
              break;
            if ( count == 91 && (v184[1] == 58 || v184[1] == 46 || v184[1] == 61) && sub_510F60(v184, &v167) )
            {
              v135 = 0;
              v134 = *(_DWORD *)(a9 + 8);
              if ( v184[1] != 58 )
              {
                *a4 = 31;
                goto LABEL_988;
              }
              v184 += 2;
              if ( *v184 == 94 )
              {
                v135 = 1;
                v149 = 1;
                ++v184;
              }
              v138 = sub_511050(v184, v167 - v184);
              if ( v138 < 0 )
              {
                *a4 = 30;
                goto LABEL_988;
              }
              if ( (v178 & 1) != 0 && v138 <= 2 )
                v138 = 0;
              v138 *= 3;
              memcpy(v136, (unsigned __int8 *)(dword_8881C8[v138] + v134), sizeof(v136));
              v139 = dword_8881CC[v138];
              v137 = dword_8881D0[v138];
              if ( v139 >= 0 )
              {
                if ( v137 < 0 )
                {
                  for ( count = 0; (int)count < 32; ++count )
                    v136[count] &= ~*(_BYTE *)(v134 + v139 + count);
                }
                else
                {
                  for ( count = 0; (int)count < 32; ++count )
                    v136[count] |= *(_BYTE *)(v134 + v139 + count);
                }
              }
              if ( v137 < 0 )
                v137 = -v137;
              if ( v137 == 1 )
              {
                v136[1] &= 0xC3u;
              }
              else if ( v137 == 2 )
              {
                v136[11] &= ~0x80u;
              }
              if ( v135 )
              {
                for ( count = 0; (int)count < 32; ++count )
                  dst[count] |= ~v136[count];
              }
              else
              {
                for ( count = 0; (int)count < 32; ++count )
                  dst[count] |= v136[count];
              }
              v184 = v167 + 1;
              v146 = 10;
              goto LABEL_312;
            }
            if ( count != 92 )
              goto LABEL_242;
            count = sub_50F7B0(&v184, a4, *(_DWORD *)(a9 + 56), v178, 1);
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
                        dst[count] |= ~v133[count + 64];
                      goto LABEL_312;
                    case 7u:
                      for ( count = 0; (int)count < 32; ++count )
                        dst[count] |= v133[count + 64];
                      goto LABEL_312;
                    case 8u:
                      v149 = 1;
                      for ( count = 0; (int)count < 32; ++count )
                        dst[count] |= ~v133[count];
                      dst[1] |= 8u;
                      goto LABEL_312;
                    case 9u:
                      dst[0] |= *v133;
                      dst[1] |= v133[1] & 0xF7;
                      for ( count = 2; (int)count < 32; ++count )
                        dst[count] |= v133[count];
                      goto LABEL_312;
                    case 10u:
                      v149 = 1;
                      for ( count = 0; (int)count < 32; ++count )
                        dst[count] |= ~v133[count + 160];
                      goto LABEL_312;
                    case 11u:
                      for ( count = 0; (int)count < 32; ++count )
                        dst[count] |= v133[count + 160];
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
                        dst[count] |= v132;
                      }
                      if ( v163 )
                      {
                        v168 = 1;
                        *v191++ = 2;
                        v19 = _pcre_ord2utf8(256, v191);
                        v191 += v19;
                        v20 = _pcre_ord2utf8(5759, v191);
                        v191 += v20;
                        *v191++ = 2;
                        v21 = _pcre_ord2utf8(5761, v191);
                        v191 += v21;
                        v22 = _pcre_ord2utf8(6157, v191);
                        v191 += v22;
                        *v191++ = 2;
                        v23 = _pcre_ord2utf8(6159, v191);
                        v191 += v23;
                        v24 = _pcre_ord2utf8(0x1FFF, v191);
                        v191 += v24;
                        *v191++ = 2;
                        v25 = _pcre_ord2utf8(8203, v191);
                        v191 += v25;
                        v26 = _pcre_ord2utf8(8238, v191);
                        v191 += v26;
                        *v191++ = 2;
                        v27 = _pcre_ord2utf8(8240, v191);
                        v191 += v27;
                        v28 = _pcre_ord2utf8(8286, v191);
                        v191 += v28;
                        *v191++ = 2;
                        v29 = _pcre_ord2utf8(8288, v191);
                        v191 += v29;
                        v30 = _pcre_ord2utf8(12287, v191);
                        v191 += v30;
                        *v191++ = 2;
                        v31 = _pcre_ord2utf8(12289, v191);
                        v191 += v31;
                        v32 = _pcre_ord2utf8(0x7FFFFFFF, v191);
                        v191 += v32;
                      }
                      goto LABEL_312;
                    case 19u:
                      dst[1] |= 2u;
                      dst[4] |= 1u;
                      dst[20] |= 1u;
                      if ( v163 )
                      {
                        v168 = 1;
                        *v191++ = 1;
                        v12 = _pcre_ord2utf8(5760, v191);
                        v191 += v12;
                        *v191++ = 1;
                        v13 = _pcre_ord2utf8(6158, v191);
                        v191 += v13;
                        *v191++ = 2;
                        v14 = _pcre_ord2utf8(0x2000, v191);
                        v191 += v14;
                        v15 = _pcre_ord2utf8(8202, v191);
                        v191 += v15;
                        *v191++ = 1;
                        v16 = _pcre_ord2utf8(8239, v191);
                        v191 += v16;
                        *v191++ = 1;
                        v17 = _pcre_ord2utf8(8287, v191);
                        v191 += v17;
                        *v191++ = 1;
                        v18 = _pcre_ord2utf8(12288, v191);
                        v191 += v18;
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
                        dst[count] |= v131;
                      }
                      if ( v163 )
                      {
                        v168 = 1;
                        *v191++ = 2;
                        v35 = _pcre_ord2utf8(256, v191);
                        v191 += v35;
                        v36 = _pcre_ord2utf8(8231, v191);
                        v191 += v36;
                        *v191++ = 2;
                        v37 = _pcre_ord2utf8(8233, v191);
                        v191 += v37;
                        v38 = _pcre_ord2utf8(0x7FFFFFFF, v191);
                        v191 += v38;
                      }
                      goto LABEL_312;
                    case 21u:
                      dst[1] |= 4u;
                      dst[1] |= 8u;
                      dst[1] |= 0x10u;
                      dst[1] |= 0x20u;
                      dst[16] |= 0x20u;
                      if ( v163 )
                      {
                        v168 = 1;
                        *v191++ = 2;
                        v33 = _pcre_ord2utf8(8232, v191);
                        v191 += v33;
                        v34 = _pcre_ord2utf8(8233, v191);
                        v191 += v34;
                      }
                      goto LABEL_312;
                    default:
                      if ( (v178 & 0x40) != 0 )
                      {
                        *a4 = 7;
                        goto LABEL_988;
                      }
                      v146 -= 2;
                      count = (unsigned __int8)*v184;
                      break;
                  }
                }
LABEL_242:
                while ( v184[1] == 92 && v184[2] == 69 )
                {
                  v176 = 0;
                  v184 += 2;
                }
                v140 = v184;
                if ( count == 13 || count == 10 )
                  *(_DWORD *)(a9 + 80) |= 0x20u;
                if ( v176 || v184[1] != 45 )
                  goto LABEL_304;
                for ( v184 += 2; *v184 == 92 && v184[1] == 69; v184 += 2 )
                  ;
                while ( *v184 == 92 && v184[1] == 81 )
                {
                  v184 += 2;
                  if ( *v184 != 92 || v184[1] != 69 )
                  {
                    v176 = 1;
                    break;
                  }
                  v184 += 2;
                }
                if ( !*v184 || !v176 && *v184 == 93 )
                {
                  v184 = v140;
LABEL_304:
                  if ( v163 && ((int)count > 255 || (v178 & 1) != 0 && (int)count > 127) )
                  {
                    v168 = 1;
                    *v191++ = 1;
                    v41 = _pcre_ord2utf8(count, v191);
                    v191 += v41;
                  }
                  else
                  {
                    dst[(int)count / 8] |= 1 << (count & 7);
                    if ( (v178 & 1) != 0 )
                    {
                      count = *(unsigned __int8 *)(*(_DWORD *)(a9 + 4) + count);
                      dst[(int)count / 8] |= 1 << (count & 7);
                    }
                    ++v146;
                    v152 = count;
                  }
                  goto LABEL_312;
                }
                if ( v163 )
                {
                  v130 = (unsigned __int8)*v184;
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
                            v130 = v184[5] & 0x3F
                                 | ((v184[4] & 0x3F) << 6)
                                 | ((v184[3] & 0x3F) << 12)
                                 | ((v184[2] & 0x3F) << 18)
                                 | ((v184[1] & 0x3F) << 24)
                                 | ((v130 & 1) << 30);
                            v184 += 5;
                          }
                          else
                          {
                            v130 = v184[4] & 0x3F
                                 | ((v184[3] & 0x3F) << 6)
                                 | ((v184[2] & 0x3F) << 12)
                                 | ((v184[1] & 0x3F) << 18)
                                 | ((v130 & 3) << 24);
                            v184 += 4;
                          }
                        }
                        else
                        {
                          v130 = v184[3] & 0x3F
                               | ((v184[2] & 0x3F) << 6)
                               | ((v184[1] & 0x3F) << 12)
                               | ((v130 & 7) << 18);
                          v184 += 3;
                        }
                      }
                      else
                      {
                        v130 = v184[2] & 0x3F | ((v184[1] & 0x3F) << 6) | ((v130 & 0xF) << 12);
                        v184 += 2;
                      }
                    }
                    else
                    {
                      v130 = *++v184 & 0x3F | ((v130 & 0x1F) << 6);
                    }
                  }
                }
                else
                {
                  v130 = (unsigned __int8)*v184;
                }
                if ( !v176 && v130 == 92 )
                {
                  v130 = sub_50F7B0(&v184, a4, *(_DWORD *)(a9 + 56), v178, 1);
                  if ( *a4 )
                    goto LABEL_988;
                  if ( v130 < 0 )
                  {
                    if ( v130 != -5 )
                    {
                      v184 = v140;
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
                if ( !v163 || v130 <= 255 && ((v178 & 1) == 0 || v130 <= 127) )
                  goto LABEL_298;
                v168 = 1;
                *v191++ = 2;
                v39 = _pcre_ord2utf8(count, v191);
                v191 += v39;
                v40 = _pcre_ord2utf8(v130, v191);
                v191 += v40;
                if ( (v178 & 1) != 0 && (int)count <= 127 )
                {
                  v130 = 127;
LABEL_298:
                  v146 += v130 - count + 1;
                  v152 = v130;
                  if ( !a10 )
                  {
                    while ( (int)count <= v130 )
                    {
                      dst[(int)count / 8] |= 1 << (count & 7);
                      if ( (v178 & 1) != 0 )
                      {
                        v129 = *(unsigned __int8 *)(*(_DWORD *)(a9 + 4) + count);
                        dst[v129 / 8] |= 1 << (v129 & 7);
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
                if ( v184[1] == 92 && v184[2] == 69 )
                  v184 += 2;
                else
                  v176 = 1;
                goto LABEL_312;
            }
            if ( -count != 25 )
              goto LABEL_183;
LABEL_312:
            count = (unsigned __int8)*++v184;
            if ( !count )
            {
              if ( !v165 )
                goto LABEL_317;
              v184 = v165;
              v165 = 0;
              count = (unsigned __int8)*++v184;
              if ( !count )
                goto LABEL_317;
            }
            if ( count == 93 && !v176 )
              goto LABEL_317;
          }
          if ( count == 92 && v184[1] == 69 )
          {
            v176 = 0;
            ++v184;
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
          if ( v189 == -2 )
            v189 = -1;
          v166 = v189;
          v192 = v172;
          if ( v168 && (!v149 || (v178 & 0x20000000) != 0) )
          {
            *v191++ = 0;
            *v183++ = 108;
            v183 += 2;
            *v183 = kk != 0;
            if ( v146 <= 0 )
            {
              v183 = v191;
            }
            else
            {
              *v183++ |= 2u;
              sub_509B90(v183 + 32, v183, v191 - v183);
              memcpy(v183, dst, 0x20u);
              v183 = v191 + 32;
            }
            v194[1] = (unsigned __int16)((_WORD)v183 - (_WORD)v194) >> 8;
            v194[2] = (_BYTE)v183 - (_BYTE)v194;
          }
          else
          {
            *v183++ = (kk != v149) + 106;
            if ( kk )
            {
              if ( !a10 )
              {
                for ( count = 0; (int)count < 32; ++count )
                  v183[count] = ~dst[count];
              }
            }
            else
            {
              memcpy(v183, dst, 0x20u);
            }
            v183 += 32;
          }
        }
        else
        {
          v192 = v172;
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
            v194 = v183;
            *v183++ = ((v178 & 1) != 0) + 29;
            for ( count = 0; (int)count < v157; ++count )
              *v183++ = v158[count];
            if ( v158[0] == 13 || v158[0] == 10 )
              *(_DWORD *)(a9 + 80) |= 0x20u;
            if ( v189 == -2 )
            {
              v166 = -1;
              v192 = v172;
              if ( v157 != 1 && v174 )
              {
                v172 = -1;
                v189 = -1;
              }
              else
              {
                v189 = v174 | v158[0];
                if ( v157 != 1 )
                  v172 = *(_DWORD *)(a9 + 84) | *(v183 - 1);
              }
            }
            else
            {
              v166 = v189;
              v192 = v172;
              if ( v157 == 1 || !v174 )
                v172 = *(_DWORD *)(a9 + 84) | v174 | *(v183 - 1);
            }
            break;
          }
          if ( v189 == -2 )
            v189 = -1;
          v166 = v189;
          *v183++ = ((v178 & 1) != 0) + 31;
          *v183++ = v152;
        }
        break;
      case 0x5Cu:
        v167 = v184;
        count = sub_50F7B0(&v184, a4, *(_DWORD *)(a9 + 56), v178, 0);
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
          if ( v184[1] == 92 && v184[2] == 69 )
            v184 += 2;
          else
            v176 = 1;
          break;
        }
        if ( -count == 25 )
          break;
        if ( v189 == -2 && (signed int)-count > 5 && (signed int)-count < 23 )
          v189 = -1;
        v166 = v189;
        v192 = v172;
        if ( -count == 27 )
        {
          v162 = *(_DWORD *)(a9 + 36);
          v147 = *++v184 != 60 ? 39 : 62;
          v145 = 0;
          v144 = 0;
          if ( v184[1] == 43 || v184[1] == 45 )
          {
            for ( mm = v184 + 2; (byte_888D30[(unsigned __int8)*mm] & 4) != 0; ++mm )
              ;
            if ( (unsigned __int8)*mm != v147 )
            {
              *a4 = 57;
              break;
            }
            ++v184;
          }
          else
          {
            v64 = 1;
            for ( nn = v184 + 1; *nn && (unsigned __int8)*nn != v147; ++nn )
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
            ++v184;
          }
LABEL_783:
          v148 = (unsigned __int8)*v184;
          if ( v148 == 43 )
          {
            if ( (byte_888D30[(unsigned __int8)*++v184] & 4) == 0 )
            {
              *a4 = 63;
              goto LABEL_988;
            }
            goto LABEL_790;
          }
          if ( v148 != 45 )
            goto LABEL_790;
          if ( (byte_888D30[(unsigned __int8)v184[1]] & 4) != 0 )
          {
            ++v184;
LABEL_790:
            v156 = 0;
            while ( (byte_888D30[(unsigned __int8)*v184] & 4) != 0 )
              v156 = 10 * v156 + (unsigned __int8)*v184++ - 48;
            if ( (unsigned __int8)*v184 != v147 )
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
            if ( *v184 != 41 && *v184 != 58 )
            {
              v51 = (unsigned __int8)*v184++;
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
                  --v184;
                  goto LABEL_988;
              }
            }
            break;
          }
          v154 = ~v92 & (v91 | v178);
          if ( *v184 != 41 )
          {
            v186 = 125;
            ++v184;
            goto LABEL_847;
          }
          if ( v183 == (unsigned __int8 *)(*(_DWORD *)(a9 + 20) + 3) && (!a10 || *a10 == 6) )
          {
            *(_DWORD *)(a9 + 76) = v154;
          }
          else
          {
            v182 = (v154 & 0x200) != 0;
            v171 = (v154 & 0x200) == 0;
            v174 = (v154 & 1) != 0 ? 0x100 : 0;
          }
          v178 = v154;
          *a1 = v154;
          v194 = 0;
        }
        else if ( -count == 28 )
        {
          if ( v184[1] != 60 && v184[1] != 39 && v184[1] != 123 )
          {
            *a4 = 69;
            break;
          }
          v153 = 0;
          if ( *++v184 == 60 )
            v50 = 62;
          else
            v50 = *v184 != 39 ? 125 : 39;
          v147 = v50;
LABEL_757:
          v81 = ++v184;
          while ( (*(_BYTE *)(*(_DWORD *)(a9 + 12) + (unsigned __int8)*v184) & 0x10) != 0 )
            ++v184;
          sizb = v184 - v81;
          if ( a10 )
          {
            if ( !sizb )
            {
              *a4 = 62;
              goto LABEL_988;
            }
            if ( (unsigned __int8)*v184 != v147 )
            {
              *a4 = 42;
              goto LABEL_988;
            }
            if ( sizb > 32 )
            {
              *a4 = 48;
              goto LABEL_988;
            }
            v70 = *(_DWORD *)(a9 + 28);
            *(_DWORD *)(a9 + 28) = v184;
            v156 = sub_5101B0(a9, v81, sizb, (v178 & 8) != 0, v163);
            *(_DWORD *)(a9 + 28) = v70;
            if ( (v156 & 0x80000000) != 0 )
              v156 = 0;
          }
          else
          {
            v78 = *(const char **)(a9 + 40);
            for ( i1 = 0; i1 < *(_DWORD *)(a9 + 44) && (strncmp(v81, v78 + 2, sizb) || v78[sizb + 2]); ++i1 )
              v78 += *(_DWORD *)(a9 + 48);
            if ( i1 >= *(_DWORD *)(a9 + 44) )
            {
              v156 = sub_5101B0(a9, v81, sizb, (v178 & 8) != 0, v163);
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
            v194 = v183;
            bracket = *(unsigned __int8 **)(a9 + 20);
            if ( !a10 )
            {
              *v183 = 0;
              if ( v156 )
                bracket = _pcre_find_bracket(*(unsigned __int8 **)(a9 + 20), *(unsigned __int8 **)(a9 + 20), v163, v156);
              if ( bracket )
              {
                if ( !(bracket[2] | (bracket[1] << 8)) && a8 <= 0 && sub_510F10(bracket, v183, a7, v163, a9) )
                {
                  *a4 = 40;
                  goto LABEL_988;
                }
              }
              else
              {
                if ( sub_5101B0(a9, 0, v156, (v178 & 8) != 0, v163) < 0 )
                {
                  *a4 = 15;
                  goto LABEL_988;
                }
                bracket = (unsigned __int8 *)(v156 + *(_DWORD *)(a9 + 20));
                if ( *(_DWORD *)(a9 + 36) >= (unsigned int)(*(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100) )
                {
                  *a4 = sub_50F610(a9);
                  if ( *a4 )
                    goto LABEL_988;
                }
                **(_BYTE **)(a9 + 36) = (unsigned __int16)((_WORD)v183 + 1 - *(_WORD *)(a9 + 20)) >> 8;
                *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = (_BYTE)v183 + 1 - *(_BYTE *)(a9 + 20);
                *(_DWORD *)(a9 + 36) += 2;
              }
            }
            *v183 = 111;
            v183[1] = (unsigned __int16)((_WORD)bracket - *(_WORD *)(a9 + 20)) >> 8;
            v183[2] = (_BYTE)bracket - *(_BYTE *)(a9 + 20);
            v183 += 3;
            v193 = 0;
            if ( v189 == -2 )
              v189 = -1;
          }
          else
          {
LABEL_937:
            if ( v189 == -2 )
              v189 = -1;
            v194 = v183;
            *v183++ = ((v178 & 1) != 0) + 109;
            *v183 = BYTE1(v156);
            v183[1] = v156;
            v183 += 2;
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
            v48 = v183;
          v194 = v48;
          if ( v163 || count != -14 )
            v47 = -count;
          else
            LOBYTE(v47) = 13;
          *v183++ = v47;
        }
        break;
      case 0x5Du:
        if ( (*(_DWORD *)(a9 + 76) & 0x2000000) == 0 )
          goto LABEL_967;
        *a4 = 64;
        goto LABEL_988;
      case 0x5Eu:
        v194 = 0;
        if ( (v178 & 2) != 0 )
        {
          if ( v189 == -2 )
            v189 = -1;
          *v183++ = 26;
        }
        else
        {
          *v183++ = 25;
        }
        break;
      case 0x7Bu:
        if ( !v151 )
          goto LABEL_967;
        v184 = (char *)sub_5100A0(v184 + 1, &v185, &v187, a4);
        if ( *a4 )
          goto LABEL_988;
LABEL_355:
        if ( !v194 )
        {
          *a4 = 9;
          goto LABEL_988;
        }
        if ( !v185 )
        {
          v189 = v166;
          v172 = v192;
        }
        v177 = v187 != v185 ? 0x200 : 0;
        v181 = 0;
        v143 = 0;
        v161 = v194;
        if ( v184[1] == 43 )
        {
          v169 = 0;
          v143 = 1;
          ++v184;
        }
        else if ( v184[1] == 63 )
        {
          v169 = v171;
          ++v184;
        }
        else
        {
          v169 = v182;
        }
        if ( *v194 == 111 )
        {
          sub_509B90(v194 + 3, v194, 3u);
          *v194 = 123;
          v194[1] = 0;
          v194[2] = 6;
          v194[6] = 114;
          v194[7] = 0;
          v194[8] = 6;
          v183 += 6;
          v188 = 9;
          if ( !a10 && *(_DWORD *)(a9 + 36) >= (unsigned int)(*(_DWORD *)(a9 + 16) + 2) )
          {
            v128 = (unsigned __int8 *)(*(unsigned __int8 *)(*(_DWORD *)(a9 + 36) - 1)
                                     | (*(unsigned __int8 *)(*(_DWORD *)(a9 + 36) - 2) << 8));
            if ( v128 == &v194[-*(_DWORD *)(a9 + 20) + 1] )
            {
              *(_BYTE *)(*(_DWORD *)(a9 + 36) - 2) = (unsigned __int16)((_WORD)v128 + 3) >> 8;
              *(_BYTE *)(*(_DWORD *)(a9 + 36) - 1) = (_BYTE)v128 + 3;
            }
          }
        }
        if ( *v194 == 29 || *v194 == 30 )
        {
          v181 = *v194 != 29 ? 0xD : 0;
          if ( v163 && (*(v183 - 1) & 0x80) != 0 )
          {
            for ( src = v183 - 1; (*src & 0xC0) == 0x80; --src )
              ;
            count = v183 - src;
            memcpy(v175, src, v183 - src);
            count |= 0x80u;
          }
          else
          {
            count = *(v183 - 1);
            if ( v185 > 1 )
              v172 = *(_DWORD *)(a9 + 84) | v174 | count;
          }
          if ( !v143 && v187 < 0 && sub_511450((int)v194, v163, v184 + 1, v178, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
          goto LABEL_396;
        }
        if ( *v194 == 31 || *v194 == 32 )
        {
          v181 = *v194 != 31 ? 39 : 26;
          count = v194[1];
          if ( !v143 && v187 < 0 && sub_511450((int)v194, v163, v184 + 1, v178, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
          goto LABEL_396;
        }
        if ( *v194 < 0x17u )
        {
          v181 = 52;
          count = *v194;
          if ( !v143 && v187 < 0 && sub_511450((int)v194, v163, v184 + 1, v178, a9) )
          {
            v169 = 0;
            v143 = 1;
          }
LABEL_396:
          if ( *v194 == 16 || *v194 == 15 )
          {
            v125 = v194[1];
            v124 = v194[2];
          }
          else
          {
            v124 = -1;
            v125 = -1;
          }
          v126 = v183;
          v183 = v194;
          if ( !v187 )
            goto LABEL_579;
          v169 += v181;
          if ( v185 )
          {
            if ( v185 == 1 )
            {
              if ( v187 == -1 )
              {
                *v183++ = v169 + 35;
              }
              else
              {
                v183 = v126;
                if ( v187 == 1 )
                  goto LABEL_579;
                *v183++ = v169 + 39;
                *v183 = (unsigned __int16)(v187 - 1) >> 8;
                v183[1] = v187 - 1;
                v183 += 2;
              }
            }
            else
            {
              *v183++ = v181 + 41;
              *v183 = BYTE1(v185);
              v183[1] = v185;
              v183 += 2;
              if ( v187 >= 0 )
              {
                if ( v187 != v185 )
                {
                  if ( v163 && (int)count >= 128 )
                  {
                    memcpy(v183, v175, count & 7);
                    v183 += count & 7;
                  }
                  else
                  {
                    *v183++ = count;
                  }
                  if ( v125 >= 0 )
                  {
                    *v183++ = v125;
                    *v183++ = v124;
                  }
                  v187 -= v185;
                  if ( v187 == 1 )
                  {
                    *v183++ = v169 + 37;
                  }
                  else
                  {
                    *v183++ = v169 + 39;
                    *v183 = BYTE1(v187);
                    v183[1] = v187;
                    v183 += 2;
                  }
                }
              }
              else
              {
                if ( v163 && (int)count >= 128 )
                {
                  memcpy(v183, v175, count & 7);
                  v183 += count & 7;
                }
                else
                {
                  *v183++ = count;
                  if ( v125 >= 0 )
                  {
                    *v183++ = v125;
                    *v183++ = v124;
                  }
                }
                *v183++ = v169 + 33;
              }
            }
          }
          else if ( v187 == -1 )
          {
            *v183++ = v169 + 33;
          }
          else if ( v187 == 1 )
          {
            *v183++ = v169 + 37;
          }
          else
          {
            *v183++ = v169 + 39;
            *v183 = BYTE1(v187);
            v183[1] = v187;
            v183 += 2;
          }
          if ( v163 && (int)count >= 128 )
          {
            memcpy(v183, v175, count & 7);
            v183 += count & 7;
          }
          else
          {
            *v183++ = count;
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
            v100 = v183 - v161;
            if ( v183 - v161 > 0 )
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
                  *v183 = 0;
                  sub_5110D0(v161, 3, v163, a9, v162);
                  sub_509B90(v161 + 3, v161, v100);
                  v183 += 3;
                  v100 += 3;
                  *v161 = 123;
                  *v183++ = 114;
                  *v183 = BYTE1(v100);
                  v183[1] = v100;
                  v183 += 2;
                  v161[1] = BYTE1(v100);
                  v161[2] = v100;
                  break;
              }
            }
          }
          goto LABEL_579;
        }
        if ( *v194 == 106 || *v194 == 107 || *v194 == 108 || *v194 == 109 || *v194 == 110 )
        {
          if ( !v187 )
          {
            v183 = v194;
            goto LABEL_579;
          }
          if ( v185 || v187 != -1 )
          {
            if ( v185 == 1 && v187 == -1 )
            {
              *v183++ = v169 + 100;
            }
            else if ( v185 || v187 != 1 )
            {
              *v183++ = v169 + 104;
              *v183 = BYTE1(v185);
              v183[1] = v185;
              v183 += 2;
              if ( v187 == -1 )
                v187 = 0;
              *v183 = BYTE1(v187);
              v183[1] = v187;
              v183 += 2;
            }
            else
            {
              *v183++ = v169 + 102;
            }
          }
          else
          {
            *v183++ = v169 + 98;
          }
          goto LABEL_544;
        }
        if ( *v194 >= 0x77u && *v194 <= 0x81u )
        {
          v121 = v183 - v194;
          v123 = 0;
          v120 = 0;
          if ( *v194 == 129 && v194[3] == 139 )
            goto LABEL_579;
          if ( *v194 < 0x7Bu )
          {
            if ( v185 > 0 )
              goto LABEL_579;
            if ( (unsigned int)v187 >= 2 )
              v187 = 1;
          }
          if ( v185 )
          {
            if ( v185 > 1 )
            {
              if ( a10 )
              {
                v118 = v188 * (v185 - 1);
                if ( (double)(v185 - 1) * (double)v188 > 2147483647.0 || 2147483627 - *a10 < v118 )
                {
                  *a4 = 20;
                  goto LABEL_988;
                }
                *a10 += v118;
              }
              else
              {
                if ( v193 && v172 < 0 )
                  v172 = v189;
                for ( i3 = 1; i3 < v185; ++i3 )
                {
                  v116 = *(_DWORD *)(a9 + 36);
                  memcpy(v183, v194, v121);
                  while ( *(_DWORD *)(a9 + 36) > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 - (v116 - v162) )
                  {
                    v115 = v162 - *(_DWORD *)(a9 + 16);
                    v114 = v116 - *(_DWORD *)(a9 + 16);
                    *a4 = sub_50F610(a9);
                    if ( *a4 )
                      goto LABEL_988;
                    v162 = v115 + *(_DWORD *)(a9 + 16);
                    v116 = v114 + *(_DWORD *)(a9 + 16);
                  }
                  for ( i4 = v162; i4 < v116; i4 += 2 )
                  {
                    **(_BYTE **)(a9 + 36) = (unsigned __int16)(v121 + _byteswap_ushort(*(_WORD *)i4)) >> 8;
                    *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = v121 + *(_BYTE *)(i4 + 1);
                    *(_DWORD *)(a9 + 36) += 2;
                  }
                  v162 = v116;
                  v183 += v121;
                }
              }
            }
            if ( v187 > 0 )
              v187 -= v185;
          }
          else
          {
            if ( v187 > 1 )
            {
              *v183 = 0;
              sub_5110D0(v194, 4, v163, a9, v162);
              sub_509B90(v194 + 4, v194, v121);
              v183 += 4;
              *v194++ = v169 - 116;
              *v194++ = 125;
              if ( v123 )
                v58 = (unsigned __int8 *)(v194 - v123);
              else
                v58 = 0;
              v119 = v58;
              v123 = v194;
              *v194 = BYTE1(v58);
              v194[1] = (unsigned __int8)v119;
              v194 += 2;
            }
            else
            {
              *v183 = 0;
              sub_5110D0(v194, 1, v163, a9, v162);
              sub_509B90(v194 + 1, v194, v121);
              ++v183;
              if ( !v187 )
              {
                *v194++ = -101;
                goto LABEL_579;
              }
              v120 = v194;
              *v194++ = v169 - 116;
            }
            --v187;
          }
          if ( v187 < 0 )
          {
            v103 = v183 - 3;
            v104 = &v183[-(*(v183 - 1) | (*(v183 - 2) << 8)) - 3];
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
                while ( !sub_510830(v102, v103, v163, a9) )
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
                  v101 = v183 - v104;
                  *v183 = 0;
                  sub_5110D0(v104, 3, v163, a9, v162);
                  sub_509B90(v104 + 3, v104, v101);
                  v183 += 3;
                  v101 += 3;
                  *v104 = 126;
                  *v183++ = 117;
                  *v183 = BYTE1(v101);
                  v183[1] = v101;
                  v183 += 2;
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
                if ( v185 < 2 )
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
            if ( a10 && v187 > 0 )
            {
              v113 = v187 * (v188 + 7) - 6;
              if ( (double)v187 * (double)(v188 + 7) > 2147483647.0 || 2147483627 - *a10 < v113 )
              {
                *a4 = 20;
                goto LABEL_988;
              }
              *a10 += v113;
            }
            else
            {
              for ( i3 = v187 - 1; i3 >= 0; --i3 )
              {
                v111 = *(_DWORD *)(a9 + 36);
                *v183++ = v169 - 116;
                if ( i3 )
                {
                  *v183++ = 125;
                  if ( v123 )
                    v57 = (unsigned __int8 *)(v183 - v123);
                  else
                    v57 = 0;
                  v110 = v57;
                  v123 = v183;
                  *v183 = BYTE1(v57);
                  v183[1] = (unsigned __int8)v110;
                  v183 += 2;
                }
                memcpy(v183, v194, v121);
                while ( *(_DWORD *)(a9 + 36) > *(_DWORD *)(a9 + 16) + *(_DWORD *)(a9 + 52) - 100 - (v111 - v162) )
                {
                  v109 = v162 - *(_DWORD *)(a9 + 16);
                  v108 = v111 - *(_DWORD *)(a9 + 16);
                  *a4 = sub_50F610(a9);
                  if ( *a4 )
                    goto LABEL_988;
                  v162 = v109 + *(_DWORD *)(a9 + 16);
                  v111 = v108 + *(_DWORD *)(a9 + 16);
                }
                for ( i5 = v162; i5 < v111; i5 += 2 )
                {
                  **(_BYTE **)(a9 + 36) = (unsigned __int16)((i3 != 0 ? 4 : 1) + v121 + _byteswap_ushort(*(_WORD *)i5)) >> 8;
                  *(_BYTE *)(*(_DWORD *)(a9 + 36) + 1) = (i3 != 0 ? 4 : 1) + v121 + *(_BYTE *)(i5 + 1);
                  *(_DWORD *)(a9 + 36) += 2;
                }
                v162 = v111;
                v183 += v121;
              }
            }
            while ( v123 )
            {
              v105 = (unsigned __int8 *)(v183 - v123 + 1);
              v106 = v123 - 1;
              v107 = v123[1] | (*v123 << 8);
              if ( v107 )
                v56 = &v123[-v107];
              else
                v56 = 0;
              v123 = v56;
              *v183++ = 114;
              *v183 = BYTE1(v105);
              v183[1] = (unsigned __int8)v105;
              v183 += 2;
              v106[1] = BYTE1(v105);
              v106[2] = (unsigned __int8)v105;
            }
          }
          goto LABEL_544;
        }
        if ( *v194 != 151 )
        {
          *a4 = 11;
          goto LABEL_988;
        }
LABEL_579:
        v194 = 0;
        *(_DWORD *)(a9 + 84) |= v177;
        break;
      default:
        goto LABEL_967;
    }
LABEL_2:
    ++v184;
  }
  *a4 = 52;
LABEL_988:
  *a3 = v184;
  return 0;
}
