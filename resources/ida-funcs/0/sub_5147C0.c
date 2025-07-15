int __cdecl sub_5147C0(
        unsigned __int8 *lhs,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        int a4,
        unsigned int *a5,
        int *a6,
        unsigned int a7)
{
  unsigned int v7; // ecx
  unsigned int v8; // edx
  int result; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  int v25; // edx
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // edx
  char *v34; // ecx
  int v35; // ecx
  int v36; // edx
  char *v37; // eax
  char *v47; // eax
  BOOL v48; // [esp+4h] [ebp-368h]
  BOOL v49; // [esp+8h] [ebp-364h]
  BOOL v50; // [esp+Ch] [ebp-360h]
  BOOL v51; // [esp+1Ch] [ebp-350h]
  BOOL v52; // [esp+20h] [ebp-34Ch]
  BOOL v53; // [esp+24h] [ebp-348h]
  BOOL v54; // [esp+28h] [ebp-344h]
  BOOL v55; // [esp+2Ch] [ebp-340h]
  BOOL v56; // [esp+30h] [ebp-33Ch]
  BOOL v57; // [esp+50h] [ebp-31Ch]
  BOOL v58; // [esp+54h] [ebp-318h]
  BOOL v59; // [esp+58h] [ebp-314h]
  BOOL v60; // [esp+74h] [ebp-2F8h]
  BOOL v61; // [esp+78h] [ebp-2F4h]
  BOOL v62; // [esp+7Ch] [ebp-2F0h]
  int v63; // [esp+84h] [ebp-2E8h]
  int v64; // [esp+8Ch] [ebp-2E0h]
  int v65; // [esp+94h] [ebp-2D8h]
  int v66; // [esp+9Ch] [ebp-2D0h]
  int v67; // [esp+A4h] [ebp-2C8h]
  BOOL v68; // [esp+A8h] [ebp-2C4h]
  BOOL v69; // [esp+ACh] [ebp-2C0h]
  BOOL v70; // [esp+B0h] [ebp-2BCh]
  BOOL v71; // [esp+CCh] [ebp-2A0h]
  BOOL v72; // [esp+D0h] [ebp-29Ch]
  BOOL v73; // [esp+D4h] [ebp-298h]
  BOOL v74; // [esp+DCh] [ebp-290h]
  BOOL v75; // [esp+E0h] [ebp-28Ch]
  BOOL v76; // [esp+104h] [ebp-268h]
  BOOL v77; // [esp+108h] [ebp-264h]
  BOOL v78; // [esp+10Ch] [ebp-260h]
  BOOL v79; // [esp+110h] [ebp-25Ch]
  BOOL v80; // [esp+114h] [ebp-258h]
  BOOL v81; // [esp+118h] [ebp-254h]
  BOOL v82; // [esp+11Ch] [ebp-250h]
  BOOL v83; // [esp+120h] [ebp-24Ch]
  BOOL v84; // [esp+124h] [ebp-248h]
  BOOL v85; // [esp+128h] [ebp-244h]
  BOOL v86; // [esp+12Ch] [ebp-240h]
  BOOL v87; // [esp+130h] [ebp-23Ch]
  BOOL v88; // [esp+134h] [ebp-238h]
  BOOL v89; // [esp+138h] [ebp-234h]
  BOOL v90; // [esp+13Ch] [ebp-230h]
  int v91; // [esp+140h] [ebp-22Ch]
  int v92; // [esp+144h] [ebp-228h]
  BOOL v93; // [esp+148h] [ebp-224h]
  BOOL v94; // [esp+14Ch] [ebp-220h]
  BOOL v95; // [esp+150h] [ebp-21Ch]
  int v96; // [esp+154h] [ebp-218h]
  BOOL v97; // [esp+158h] [ebp-214h]
  int v98; // [esp+160h] [ebp-20Ch]
  int v99; // [esp+164h] [ebp-208h]
  int v100; // [esp+168h] [ebp-204h]
  int v101; // [esp+16Ch] [ebp-200h]
  int v102; // [esp+170h] [ebp-1FCh]
  int v103; // [esp+174h] [ebp-1F8h]
  int v104; // [esp+178h] [ebp-1F4h]
  int v105; // [esp+17Ch] [ebp-1F0h]
  int v106; // [esp+180h] [ebp-1ECh]
  int v107; // [esp+184h] [ebp-1E8h]
  int v108; // [esp+188h] [ebp-1E4h]
  int v109; // [esp+18Ch] [ebp-1E0h]
  unsigned int v110; // [esp+190h] [ebp-1DCh]
  unsigned int v111; // [esp+194h] [ebp-1D8h]
  unsigned int v112; // [esp+198h] [ebp-1D4h]
  int v113; // [esp+19Ch] [ebp-1D0h]
  unsigned int v114; // [esp+1A0h] [ebp-1CCh]
  unsigned int v115; // [esp+1A4h] [ebp-1C8h]
  unsigned int v116; // [esp+1A8h] [ebp-1C4h]
  unsigned int v117; // [esp+1ACh] [ebp-1C0h]
  int v118; // [esp+1B0h] [ebp-1BCh]
  int v119; // [esp+1B4h] [ebp-1B8h]
  int v120; // [esp+1B8h] [ebp-1B4h]
  int v121; // [esp+1BCh] [ebp-1B0h]
  int v122; // [esp+1C0h] [ebp-1ACh]
  char *i; // [esp+1C4h] [ebp-1A8h]
  _DWORD *v124; // [esp+1C8h] [ebp-1A4h]
  unsigned int v125; // [esp+1CCh] [ebp-1A0h]
  int **v126; // [esp+1D0h] [ebp-19Ch]
  _DWORD v127[13]; // [esp+1D8h] [ebp-194h] BYREF
  unsigned __int8 *v128; // [esp+20Ch] [ebp-160h]
  int v129; // [esp+210h] [ebp-15Ch]
  unsigned __int8 *v130; // [esp+214h] [ebp-158h]
  unsigned __int8 *v131; // [esp+218h] [ebp-154h]
  unsigned __int8 *v132; // [esp+21Ch] [ebp-150h]
  int v133; // [esp+220h] [ebp-14Ch]
  _DWORD v134[13]; // [esp+224h] [ebp-148h] BYREF
  unsigned __int8 *v135; // [esp+258h] [ebp-114h]
  unsigned __int8 *v136; // [esp+25Ch] [ebp-110h]
  int v137; // [esp+260h] [ebp-10Ch]
  int v138; // [esp+264h] [ebp-108h]
  unsigned int v139; // [esp+268h] [ebp-104h]
  int v140; // [esp+26Ch] [ebp-100h]
  int v141; // [esp+270h] [ebp-FCh]
  int v142; // [esp+274h] [ebp-F8h]
  unsigned int v143; // [esp+278h] [ebp-F4h]
  int v144; // [esp+27Ch] [ebp-F0h]
  unsigned int v145; // [esp+280h] [ebp-ECh]
  void *rhs; // [esp+284h] [ebp-E8h]
  unsigned __int8 *v147; // [esp+288h] [ebp-E4h]
  BOOL v148; // [esp+28Ch] [ebp-E0h]
  unsigned __int8 *v149; // [esp+290h] [ebp-DCh]
  _DWORD v150[2]; // [esp+294h] [ebp-D8h] BYREF
  int v151; // [esp+29Ch] [ebp-D0h]
  int v152; // [esp+2A0h] [ebp-CCh]
  int v153; // [esp+2A4h] [ebp-C8h]
  int v154; // [esp+2A8h] [ebp-C4h]
  _BYTE v155[124]; // [esp+2ACh] [ebp-C0h] BYREF
  _DWORD v156[2]; // [esp+328h] [ebp-44h] BYREF
  unsigned __int8 *dst; // [esp+330h] [ebp-3Ch]
  int v158; // [esp+334h] [ebp-38h]
  char *v159; // [esp+338h] [ebp-34h]
  unsigned __int8 *v160; // [esp+33Ch] [ebp-30h]
  int v161; // [esp+340h] [ebp-2Ch]
  int v162; // [esp+344h] [ebp-28h]
  int v163; // [esp+348h] [ebp-24h]
  int v164; // [esp+34Ch] [ebp-20h]
  int j; // [esp+350h] [ebp-1Ch]
  BOOL v166; // [esp+354h] [ebp-18h]
  int v167; // [esp+358h] [ebp-14h]
  int v168; // [esp+35Ch] [ebp-10h]
  unsigned int siz; // [esp+360h] [ebp-Ch]
  BOOL v170; // [esp+364h] [ebp-8h]
  int v171; // [esp+368h] [ebp-4h]
  unsigned __int8 *k; // [esp+378h] [ebp+Ch]
  unsigned __int8 *v173; // [esp+378h] [ebp+Ch]
  unsigned __int8 *v174; // [esp+378h] [ebp+Ch]
  unsigned __int8 *v175; // [esp+378h] [ebp+Ch]
  unsigned __int8 *v176; // [esp+378h] [ebp+Ch]
  unsigned __int8 *v177; // [esp+378h] [ebp+Ch]

LABEL_1:
  v139 = a5[17];
  v7 = *a5;
  v8 = a5[1];
  ++*a5;
  if ( v7 >= v8 )
    return -8;
  if ( a7 >= a5[2] )
    return -21;
  if ( a5[37] == 2 )
  {
    v150[1] = lhs;
    v150[0] = a6;
    a6 = v150;
    a5[37] = 0;
  }
LABEL_7:
  while ( 2 )
  {
    v144 = 0;
    v166 = 0;
    v142 = *a2;
    switch ( v142 )
    {
      case 0:
      case 152:
      case 153:
        if ( lhs == a3 && v142 != 153 && !a5[40] && (a5[21] || a5[22] && a3 == (unsigned __int8 *)(a5[36] + a5[28])) )
          return 0;
        a5[31] = (unsigned int)lhs;
        a5[34] = a4;
        a5[30] = (unsigned int)a3;
        return v142 != 0 ? -999 : 1;
      case 1:
        goto LABEL_420;
      case 2:
        if ( lhs != (unsigned __int8 *)(a5[36] + a5[28]) )
          return 0;
        ++a2;
        continue;
      case 3:
        a3 = lhs;
        ++a2;
        continue;
      case 4:
      case 5:
        if ( v139 )
        {
          if ( lhs == (unsigned __int8 *)a5[28] )
          {
            v140 = 0;
          }
          else
          {
            for ( i = (char *)(lhs - 1); (*i & 0xC0) == 0x80; --i )
              ;
            if ( (unsigned int)i < a5[32] )
              a5[32] = (unsigned int)i;
            v143 = (unsigned __int8)*i;
            if ( v143 >= 0xC0 )
            {
              if ( (v143 & 0x20) != 0 )
              {
                if ( (v143 & 0x10) != 0 )
                {
                  if ( (v143 & 8) != 0 )
                  {
                    if ( (v143 & 4) != 0 )
                      v143 = i[5] & 0x3F
                           | ((i[4] & 0x3F) << 6)
                           | ((i[3] & 0x3F) << 12)
                           | ((i[2] & 0x3F) << 18)
                           | ((i[1] & 0x3F) << 24)
                           | ((v143 & 1) << 30);
                    else
                      v143 = i[4] & 0x3F
                           | ((i[3] & 0x3F) << 6)
                           | ((i[2] & 0x3F) << 12)
                           | ((i[1] & 0x3F) << 18)
                           | ((v143 & 3) << 24);
                  }
                  else
                  {
                    v143 = i[3] & 0x3F | ((i[2] & 0x3F) << 6) | ((i[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                  }
                }
                else
                {
                  v143 = i[2] & 0x3F | ((i[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                }
              }
              else
              {
                v143 = i[1] & 0x3F | ((v143 & 0x1F) << 6);
              }
            }
            v81 = v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 0x10) != 0;
            v140 = v81;
          }
          if ( (unsigned int)lhs < a5[29] )
          {
            v143 = *lhs;
            if ( v143 >= 0xC0 )
            {
              if ( (v143 & 0x20) != 0 )
              {
                if ( (v143 & 0x10) != 0 )
                {
                  if ( (v143 & 8) != 0 )
                  {
                    if ( (v143 & 4) != 0 )
                      v143 = lhs[5] & 0x3F
                           | ((lhs[4] & 0x3F) << 6)
                           | ((lhs[3] & 0x3F) << 12)
                           | ((lhs[2] & 0x3F) << 18)
                           | ((lhs[1] & 0x3F) << 24)
                           | ((v143 & 1) << 30);
                    else
                      v143 = lhs[4] & 0x3F
                           | ((lhs[3] & 0x3F) << 6)
                           | ((lhs[2] & 0x3F) << 12)
                           | ((lhs[1] & 0x3F) << 18)
                           | ((v143 & 3) << 24);
                  }
                  else
                  {
                    v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                  }
                }
                else
                {
                  v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                }
              }
              else
              {
                v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
              }
            }
            v80 = v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 0x10) != 0;
            v162 = v80;
          }
          else
          {
            if ( a5[33] )
            {
              if ( (unsigned int)lhs > a5[32] )
              {
                a5[23] = 1;
                if ( (int)a5[33] > 1 )
                  return -12;
              }
            }
            v162 = 0;
          }
        }
        else
        {
          if ( lhs == (unsigned __int8 *)a5[28] )
          {
            v140 = 0;
          }
          else
          {
            if ( (unsigned int)lhs <= a5[32] )
              a5[32] = (unsigned int)(lhs - 1);
            v140 = (*(_BYTE *)(a5[13] + *(lhs - 1)) & 0x10) != 0;
          }
          if ( (unsigned int)lhs < a5[29] )
          {
            v162 = (*(_BYTE *)(a5[13] + *lhs) & 0x10) != 0;
          }
          else
          {
            if ( a5[33] )
            {
              if ( (unsigned int)lhs > a5[32] )
              {
                a5[23] = 1;
                if ( (int)a5[33] > 1 )
                  return -12;
              }
            }
            v162 = 0;
          }
        }
        v16 = *a2++;
        if ( v16 == 5 )
          v79 = v162 == v140;
        else
          v79 = v162 != v140;
        if ( !v79 )
          continue;
        return 0;
      case 6:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 4) != 0 )
          return 0;
        ++a2;
        continue;
      case 7:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 4) == 0 )
          return 0;
        ++a2;
        continue;
      case 8:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 1) != 0 )
          return 0;
        ++a2;
        continue;
      case 9:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 1) == 0 )
          return 0;
        ++a2;
        continue;
      case 10:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 0x10) != 0 )
          return 0;
        ++a2;
        continue;
      case 11:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 0x10) == 0 )
          return 0;
        ++a2;
        continue;
      case 12:
        if ( a5[6] )
        {
          v78 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
          v77 = v78;
        }
        else
        {
          v76 = (unsigned int)lhs <= a5[29] - a5[7]
             && *lhs == *((unsigned __int8 *)a5 + 44)
             && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
          v77 = v76;
        }
        if ( !v77 )
          goto LABEL_581;
        return 0;
      case 13:
LABEL_581:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        ++lhs;
        if ( v139 )
        {
          while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
            ++lhs;
        }
        ++a2;
        continue;
      case 14:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        ++lhs;
        ++a2;
        continue;
      case 17:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 > 0xD )
        {
          if ( v143 != 133 && (v143 <= 0x2027 || v143 > 0x2029) )
            return 0;
        }
        else
        {
          if ( v143 == 13 )
          {
            if ( (unsigned int)lhs < a5[29] && *lhs == 10 )
              ++lhs;
            goto LABEL_758;
          }
          if ( v143 == 10 )
            goto LABEL_758;
          if ( v143 <= 0xA )
            return 0;
        }
        if ( a5[24] )
          return 0;
LABEL_758:
        ++a2;
        continue;
      case 18:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 > 0x180E )
        {
          if ( v143 > 0x205F )
          {
            if ( v143 == 12288 )
              return 0;
          }
          else if ( v143 == 8287 || v143 >= 0x2000 && (v143 <= 0x200A || v143 == 8239) )
          {
            return 0;
          }
        }
        else
        {
          if ( v143 == 6158 )
            return 0;
          if ( v143 > 0xA0 )
          {
            if ( v143 == 5760 )
              return 0;
          }
          else if ( v143 == 160 || v143 == 9 || v143 == 32 )
          {
            return 0;
          }
        }
        ++a2;
        continue;
      case 19:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 > 0x180E )
        {
          if ( v143 > 0x205F )
          {
            if ( v143 != 12288 )
              return 0;
          }
          else if ( v143 != 8287 && (v143 < 0x2000 || v143 > 0x200A && v143 != 8239) )
          {
            return 0;
          }
        }
        else if ( v143 != 6158 )
        {
          if ( v143 > 0xA0 )
          {
            if ( v143 != 5760 )
              return 0;
          }
          else if ( v143 != 160 && v143 != 9 && v143 != 32 )
          {
            return 0;
          }
        }
        ++a2;
        continue;
      case 20:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 > 0x85 )
        {
          if ( v143 >= 0x2028 && v143 <= 0x2029 )
            return 0;
        }
        else if ( v143 == 133 || v143 >= 0xA && v143 <= 0xD )
        {
          return 0;
        }
        ++a2;
        continue;
      case 21:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v143 > 0x85 )
        {
          if ( v143 < 0x2028 || v143 > 0x2029 )
            return 0;
        }
        else if ( v143 != 133 && (v143 < 0xA || v143 > 0xD) )
        {
          return 0;
        }
        ++a2;
        continue;
      case 23:
        goto LABEL_482;
      case 24:
        goto LABEL_475;
      case 25:
        if ( a5[15] && lhs == (unsigned __int8 *)a5[28] )
          return 0;
LABEL_420:
        if ( lhs != (unsigned __int8 *)a5[28] )
          return 0;
        ++a2;
        continue;
      case 26:
        if ( a5[15] && lhs == (unsigned __int8 *)a5[28] )
          return 0;
        if ( lhs != (unsigned __int8 *)a5[28] )
        {
          if ( lhs == (unsigned __int8 *)a5[29] )
            return 0;
          if ( a5[6] )
          {
            v90 = (unsigned int)lhs > a5[28] && _pcre_was_newline(lhs, a5[6], a5[28], a5 + 7, v139);
            v89 = v90;
          }
          else
          {
            v88 = (unsigned int)lhs >= a5[7] + a5[28]
               && lhs[-a5[7]] == *((unsigned __int8 *)a5 + 44)
               && (a5[7] == 1 || lhs[-a5[7] + 1] == *((unsigned __int8 *)a5 + 45));
            v89 = v88;
          }
          if ( !v89 )
            return 0;
        }
        ++a2;
        continue;
      case 27:
        if ( a5[16] )
          return 0;
        if ( a5[20] )
        {
LABEL_475:
          if ( (unsigned int)lhs < a5[29] )
            return 0;
          if ( a5[33] )
          {
            if ( (unsigned int)lhs > a5[32] )
            {
              a5[23] = 1;
              if ( (int)a5[33] > 1 )
                return -12;
            }
          }
          ++a2;
        }
        else
        {
LABEL_482:
          if ( (unsigned int)lhs < a5[29] )
          {
            if ( a5[6] )
            {
              v84 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
              v83 = v84;
            }
            else
            {
              v82 = (unsigned int)lhs <= a5[29] - a5[7]
                 && *lhs == *((unsigned __int8 *)a5 + 44)
                 && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
              v83 = v82;
            }
            if ( !v83 || lhs != (unsigned __int8 *)(a5[29] - a5[7]) )
              return 0;
          }
          if ( a5[33] )
          {
            if ( (unsigned int)lhs > a5[32] )
            {
              a5[23] = 1;
              if ( (int)a5[33] > 1 )
                return -12;
            }
          }
          ++a2;
        }
        continue;
      case 28:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[16] )
            return 0;
          if ( a5[33] )
          {
            if ( (unsigned int)lhs > a5[32] )
            {
              a5[23] = 1;
              if ( (int)a5[33] > 1 )
                return -12;
            }
          }
        }
        else
        {
          if ( a5[6] )
          {
            v87 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
            v86 = v87;
          }
          else
          {
            v85 = (unsigned int)lhs <= a5[29] - a5[7]
               && *lhs == *((unsigned __int8 *)a5 + 44)
               && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
            v86 = v85;
          }
          if ( !v86 )
            return 0;
        }
        ++a2;
        continue;
      case 29:
        if ( v139 )
        {
          siz = 1;
          v143 = *++a2;
          if ( v143 >= 0xC0 )
          {
            if ( (v143 & 0x20) != 0 )
            {
              if ( (v143 & 0x10) != 0 )
              {
                if ( (v143 & 8) != 0 )
                {
                  if ( (v143 & 4) != 0 )
                  {
                    v143 = a2[5] & 0x3F
                         | ((a2[4] & 0x3F) << 6)
                         | ((a2[3] & 0x3F) << 12)
                         | ((a2[2] & 0x3F) << 18)
                         | ((a2[1] & 0x3F) << 24)
                         | ((v143 & 1) << 30);
                    siz += 5;
                  }
                  else
                  {
                    v143 = a2[4] & 0x3F
                         | ((a2[3] & 0x3F) << 6)
                         | ((a2[2] & 0x3F) << 12)
                         | ((a2[1] & 0x3F) << 18)
                         | ((v143 & 3) << 24);
                    siz += 4;
                  }
                }
                else
                {
                  v143 = a2[3] & 0x3F | ((a2[2] & 0x3F) << 6) | ((a2[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                  siz += 3;
                }
              }
              else
              {
                v143 = a2[2] & 0x3F | ((a2[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                siz += 2;
              }
            }
            else
            {
              v143 = a2[1] & 0x3F | ((v143 & 0x1F) << 6);
              ++siz;
            }
          }
          if ( (int)siz <= (int)(a5[29] - (_DWORD)lhs) )
          {
            do
            {
              v19 = siz--;
              if ( v19 <= 0 )
                goto LABEL_7;
              v20 = *lhs;
              v21 = *a2;
              ++lhs;
              ++a2;
            }
            while ( v21 == v20 );
            return 0;
          }
          else if ( a5[33] && (unsigned int)lhs >= a5[29] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
          {
            return -12;
          }
          else
          {
            return 0;
          }
        }
        if ( (int)(a5[29] - (_DWORD)lhs) < 1 )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v22 = *lhs++;
        if ( a2[1] != v22 )
          return 0;
        a2 += 2;
        continue;
      case 30:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        if ( v139 )
        {
          siz = 1;
          v173 = a2 + 1;
          v143 = *v173;
          if ( v143 >= 0xC0 )
          {
            if ( (v143 & 0x20) != 0 )
            {
              if ( (v143 & 0x10) != 0 )
              {
                if ( (v143 & 8) != 0 )
                {
                  if ( (v143 & 4) != 0 )
                  {
                    v143 = v173[5] & 0x3F
                         | ((v173[4] & 0x3F) << 6)
                         | ((v173[3] & 0x3F) << 12)
                         | ((v173[2] & 0x3F) << 18)
                         | ((v173[1] & 0x3F) << 24)
                         | ((v143 & 1) << 30);
                    siz += 5;
                  }
                  else
                  {
                    v143 = v173[4] & 0x3F
                         | ((v173[3] & 0x3F) << 6)
                         | ((v173[2] & 0x3F) << 12)
                         | ((v173[1] & 0x3F) << 18)
                         | ((v143 & 3) << 24);
                    siz += 4;
                  }
                }
                else
                {
                  v143 = v173[3] & 0x3F | ((v173[2] & 0x3F) << 6) | ((v173[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                  siz += 3;
                }
              }
              else
              {
                v143 = v173[2] & 0x3F | ((v173[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                siz += 2;
              }
            }
            else
            {
              v143 = v173[1] & 0x3F | ((v143 & 0x1F) << 6);
              ++siz;
            }
          }
          if ( v143 >= 0x80 )
          {
            v117 = *lhs++;
            if ( v117 >= 0xC0 )
            {
              if ( (v117 & 0x20) != 0 )
              {
                if ( (v117 & 0x10) != 0 )
                {
                  if ( (v117 & 8) != 0 )
                  {
                    if ( (v117 & 4) != 0 )
                    {
                      v117 = lhs[4] & 0x3F
                           | ((lhs[3] & 0x3F) << 6)
                           | ((lhs[2] & 0x3F) << 12)
                           | ((lhs[1] & 0x3F) << 18)
                           | ((*lhs & 0x3F) << 24)
                           | ((v117 & 1) << 30);
                      lhs += 5;
                    }
                    else
                    {
                      v117 = lhs[3] & 0x3F
                           | ((lhs[2] & 0x3F) << 6)
                           | ((lhs[1] & 0x3F) << 12)
                           | ((*lhs & 0x3F) << 18)
                           | ((v117 & 3) << 24);
                      lhs += 4;
                    }
                  }
                  else
                  {
                    v117 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v117 & 7) << 18);
                    lhs += 3;
                  }
                }
                else
                {
                  v117 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v117 & 0xF) << 12);
                  lhs += 2;
                }
              }
              else
              {
                v117 = *lhs++ & 0x3F | ((v117 & 0x1F) << 6);
              }
            }
            a2 = &v173[siz];
            if ( v143 != v117 )
              return 0;
          }
          else
          {
            v23 = *(unsigned __int8 *)(a5[12] + *lhs);
            v24 = *(unsigned __int8 *)(a5[12] + *v173);
            ++lhs;
            a2 = v173 + 1;
            if ( v24 != v23 )
              return 0;
          }
        }
        else
        {
          v25 = *(unsigned __int8 *)(a5[12] + *lhs++);
          if ( *(unsigned __int8 *)(a5[12] + a2[1]) != v25 )
            return 0;
          a2 += 2;
        }
        continue;
      case 31:
      case 32:
        if ( (unsigned int)lhs >= a5[29] )
        {
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        v175 = a2 + 1;
        v143 = *lhs++;
        if ( v139 && v143 >= 0xC0 )
        {
          if ( (v143 & 0x20) != 0 )
          {
            if ( (v143 & 0x10) != 0 )
            {
              if ( (v143 & 8) != 0 )
              {
                if ( (v143 & 4) != 0 )
                {
                  v143 = lhs[4] & 0x3F
                       | ((lhs[3] & 0x3F) << 6)
                       | ((lhs[2] & 0x3F) << 12)
                       | ((lhs[1] & 0x3F) << 18)
                       | ((*lhs & 0x3F) << 24)
                       | ((v143 & 1) << 30);
                  lhs += 5;
                }
                else
                {
                  v143 = lhs[3] & 0x3F
                       | ((lhs[2] & 0x3F) << 6)
                       | ((lhs[1] & 0x3F) << 12)
                       | ((*lhs & 0x3F) << 18)
                       | ((v143 & 3) << 24);
                  lhs += 4;
                }
              }
              else
              {
                v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                lhs += 3;
              }
            }
            else
            {
              v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
              lhs += 2;
            }
          }
          else
          {
            v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
          }
        }
        if ( v142 == 32 )
        {
          if ( v143 < 0x100 )
            v143 = *(unsigned __int8 *)(a5[12] + v143);
          v30 = *(unsigned __int8 *)(a5[12] + *v175);
          a2 = v175 + 1;
          if ( v30 == v143 )
            return 0;
        }
        else
        {
          v31 = *v175;
          a2 = v175 + 1;
          if ( v31 == v143 )
            return 0;
        }
        continue;
      case 33:
      case 34:
      case 35:
      case 36:
      case 37:
      case 38:
      case 46:
      case 47:
      case 48:
      case 49:
      case 50:
      case 51:
        v143 = *a2 - (v142 >= 46 ? 46 : 33);
        v174 = a2 + 1;
        v166 = (v143 & 1) != 0;
        v163 = byte_888ECC[v143];
        v137 = byte_888ED4[v143];
        if ( !v137 )
          v137 = 0x7FFFFFFF;
        goto LABEL_1247;
      case 39:
      case 40:
      case 52:
      case 53:
        goto LABEL_1237;
      case 41:
      case 54:
        v137 = a2[2] | (a2[1] << 8);
        v163 = v137;
        v174 = a2 + 3;
        goto LABEL_1247;
      case 42:
      case 55:
        v144 = 1;
        v163 = 0;
        v137 = 0x7FFFFFFF;
        v174 = a2 + 1;
        goto LABEL_1247;
      case 43:
      case 56:
        v144 = 1;
        v163 = 1;
        v137 = 0x7FFFFFFF;
        v174 = a2 + 1;
        goto LABEL_1247;
      case 44:
      case 57:
        v144 = 1;
        v163 = 0;
        v137 = 1;
        v174 = a2 + 1;
        goto LABEL_1247;
      case 45:
      case 58:
        v144 = 1;
LABEL_1237:
        v163 = 0;
        v137 = a2[2] | (a2[1] << 8);
        v75 = *a2 == 40 || *a2 == 53;
        v166 = v75;
        v174 = a2 + 3;
LABEL_1247:
        if ( v139 )
        {
          siz = 1;
          rhs = v174;
          v143 = *v174;
          if ( v143 >= 0xC0 )
          {
            if ( (v143 & 0x20) != 0 )
            {
              if ( (v143 & 0x10) != 0 )
              {
                if ( (v143 & 8) != 0 )
                {
                  if ( (v143 & 4) != 0 )
                  {
                    v143 = v174[5] & 0x3F
                         | ((v174[4] & 0x3F) << 6)
                         | ((v174[3] & 0x3F) << 12)
                         | ((v174[2] & 0x3F) << 18)
                         | ((v174[1] & 0x3F) << 24)
                         | ((v143 & 1) << 30);
                    siz += 5;
                  }
                  else
                  {
                    v143 = v174[4] & 0x3F
                         | ((v174[3] & 0x3F) << 6)
                         | ((v174[2] & 0x3F) << 12)
                         | ((v174[1] & 0x3F) << 18)
                         | ((v143 & 3) << 24);
                    siz += 4;
                  }
                }
                else
                {
                  v143 = v174[3] & 0x3F | ((v174[2] & 0x3F) << 6) | ((v174[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                  siz += 3;
                }
              }
              else
              {
                v143 = v174[2] & 0x3F | ((v174[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                siz += 2;
              }
            }
            else
            {
              v143 = v174[1] & 0x3F | ((v143 & 0x1F) << 6);
              ++siz;
            }
          }
          a2 = &v174[siz];
          if ( (int)siz > 1 )
          {
            for ( j = 1; j <= v163; ++j )
            {
              if ( (unsigned int)lhs > a5[29] - siz || memcmp(lhs, (unsigned __int8 *)rhs, siz) )
              {
                if ( a5[33]
                  && (unsigned int)lhs >= a5[29]
                  && (unsigned int)lhs > a5[32]
                  && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
              lhs += siz;
            }
            if ( v163 != v137 )
            {
              if ( v166 )
              {
                for ( j = v163; ; ++j )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs > a5[29] - siz || memcmp(lhs, (unsigned __int8 *)rhs, siz) )
                    break;
                  lhs += siz;
                }
                if ( a5[33]
                  && (unsigned int)lhs >= a5[29]
                  && (unsigned int)lhs > a5[32]
                  && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
              v160 = lhs;
              for ( j = v163; ; ++j )
              {
                if ( j >= v137 )
                  goto LABEL_1296;
                if ( (unsigned int)lhs > a5[29] - siz || memcmp(lhs, (unsigned __int8 *)rhs, siz) )
                  break;
                lhs += siz;
              }
              if ( a5[33] )
              {
                if ( (unsigned int)lhs >= a5[29] && (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
LABEL_1296:
              if ( !v144 )
              {
                while ( 1 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( lhs == v160 )
                    break;
                  lhs -= siz;
                }
                return 0;
              }
            }
            continue;
          }
        }
        else
        {
          v143 = *v174;
          a2 = v174 + 1;
        }
        if ( v142 < 46 )
        {
          for ( j = 1; j <= v163; ++j )
          {
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v28 = *lhs++;
            if ( v143 != v28 )
              return 0;
          }
          if ( v163 != v137 )
          {
            if ( v166 )
            {
              for ( j = v163; ; ++j )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                if ( j >= v137 )
                  return 0;
                if ( (unsigned int)lhs >= a5[29] )
                  break;
                v29 = *lhs++;
                if ( v143 != v29 )
                  return 0;
              }
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v160 = lhs;
            for ( j = v163; j < v137; ++j )
            {
              if ( (unsigned int)lhs >= a5[29] )
              {
                if ( a5[33] )
                {
                  if ( (unsigned int)lhs > a5[32] )
                  {
                    a5[23] = 1;
                    if ( (int)a5[33] > 1 )
                      return -12;
                  }
                }
                break;
              }
              if ( v143 != *lhs )
                break;
              ++lhs;
            }
            if ( !v144 )
            {
              while ( lhs >= v160 )
              {
                v138 = sub_5147C0(lhs--, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
              }
              return 0;
            }
          }
        }
        else
        {
          v143 = *(unsigned __int8 *)(a5[12] + v143);
          for ( j = 1; j <= v163; ++j )
          {
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v26 = *(unsigned __int8 *)(a5[12] + *lhs++);
            if ( v143 != v26 )
              return 0;
          }
          if ( v163 != v137 )
          {
            if ( v166 )
            {
              for ( j = v163; ; ++j )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                if ( j >= v137 )
                  return 0;
                if ( (unsigned int)lhs >= a5[29] )
                  break;
                v27 = *(unsigned __int8 *)(a5[12] + *lhs++);
                if ( v143 != v27 )
                  return 0;
              }
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v160 = lhs;
            for ( j = v163; j < v137; ++j )
            {
              if ( (unsigned int)lhs >= a5[29] )
              {
                if ( a5[33] )
                {
                  if ( (unsigned int)lhs > a5[32] )
                  {
                    a5[23] = 1;
                    if ( (int)a5[33] > 1 )
                      return -12;
                  }
                }
                break;
              }
              if ( v143 != *(unsigned __int8 *)(a5[12] + *lhs) )
                break;
              ++lhs;
            }
            if ( !v144 )
            {
              while ( lhs >= v160 )
              {
                v138 = sub_5147C0(lhs--, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
              }
              return 0;
            }
          }
        }
        continue;
      case 59:
      case 60:
      case 61:
      case 62:
      case 63:
      case 64:
      case 72:
      case 73:
      case 74:
      case 75:
      case 76:
      case 77:
        v143 = *a2 - (v142 < 72 ? 59 : 72);
        v176 = a2 + 1;
        v166 = (v143 & 1) != 0;
        v163 = byte_888ECC[v143];
        v137 = byte_888ED4[v143];
        if ( !v137 )
          v137 = 0x7FFFFFFF;
        goto LABEL_1429;
      case 65:
      case 66:
      case 78:
      case 79:
        v163 = 0;
        v137 = a2[2] | (a2[1] << 8);
        v74 = *a2 == 66 || *a2 == 79;
        v166 = v74;
        v176 = a2 + 3;
        goto LABEL_1429;
      case 67:
      case 80:
        v137 = a2[2] | (a2[1] << 8);
        v163 = v137;
        v176 = a2 + 3;
        goto LABEL_1429;
      case 68:
      case 81:
        v144 = 1;
        v163 = 0;
        v137 = 0x7FFFFFFF;
        v176 = a2 + 1;
        goto LABEL_1429;
      case 69:
      case 82:
        v144 = 1;
        v163 = 1;
        v137 = 0x7FFFFFFF;
        v176 = a2 + 1;
        goto LABEL_1429;
      case 70:
      case 83:
        v144 = 1;
        v163 = 0;
        v137 = 1;
        v176 = a2 + 1;
        goto LABEL_1429;
      case 71:
      case 84:
        v144 = 1;
        v163 = 0;
        v137 = a2[2] | (a2[1] << 8);
        v176 = a2 + 3;
LABEL_1429:
        v143 = *v176;
        a2 = v176 + 1;
        if ( v142 < 72 )
        {
          if ( v139 )
          {
            for ( j = 1; ; ++j )
            {
              if ( j > v163 )
                goto LABEL_1590;
              if ( (unsigned int)lhs >= a5[29] )
                break;
              v112 = *lhs++;
              if ( v112 >= 0xC0 )
              {
                if ( (v112 & 0x20) != 0 )
                {
                  if ( (v112 & 0x10) != 0 )
                  {
                    if ( (v112 & 8) != 0 )
                    {
                      if ( (v112 & 4) != 0 )
                      {
                        v112 = lhs[4] & 0x3F
                             | ((lhs[3] & 0x3F) << 6)
                             | ((lhs[2] & 0x3F) << 12)
                             | ((lhs[1] & 0x3F) << 18)
                             | ((*lhs & 0x3F) << 24)
                             | ((v112 & 1) << 30);
                        lhs += 5;
                      }
                      else
                      {
                        v112 = lhs[3] & 0x3F
                             | ((lhs[2] & 0x3F) << 6)
                             | ((lhs[1] & 0x3F) << 12)
                             | ((*lhs & 0x3F) << 18)
                             | ((v112 & 3) << 24);
                        lhs += 4;
                      }
                    }
                    else
                    {
                      v112 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v112 & 7) << 18);
                      lhs += 3;
                    }
                  }
                  else
                  {
                    v112 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v112 & 0xF) << 12);
                    lhs += 2;
                  }
                }
                else
                {
                  v112 = *lhs++ & 0x3F | ((v112 & 0x1F) << 6);
                }
              }
              if ( v143 == v112 )
                return 0;
            }
            if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              return -12;
            else
              return 0;
          }
          for ( j = 1; j <= v163; ++j )
          {
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v35 = *lhs++;
            if ( v143 == v35 )
              return 0;
          }
LABEL_1590:
          if ( v163 != v137 )
          {
            if ( v166 )
            {
              if ( v139 )
              {
                for ( j = v163; ; ++j )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v111 = *lhs++;
                  if ( v111 >= 0xC0 )
                  {
                    if ( (v111 & 0x20) != 0 )
                    {
                      if ( (v111 & 0x10) != 0 )
                      {
                        if ( (v111 & 8) != 0 )
                        {
                          if ( (v111 & 4) != 0 )
                          {
                            v111 = lhs[4] & 0x3F
                                 | ((lhs[3] & 0x3F) << 6)
                                 | ((lhs[2] & 0x3F) << 12)
                                 | ((lhs[1] & 0x3F) << 18)
                                 | ((*lhs & 0x3F) << 24)
                                 | ((v111 & 1) << 30);
                            lhs += 5;
                          }
                          else
                          {
                            v111 = lhs[3] & 0x3F
                                 | ((lhs[2] & 0x3F) << 6)
                                 | ((lhs[1] & 0x3F) << 12)
                                 | ((*lhs & 0x3F) << 18)
                                 | ((v111 & 3) << 24);
                            lhs += 4;
                          }
                        }
                        else
                        {
                          v111 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v111 & 7) << 18);
                          lhs += 3;
                        }
                      }
                      else
                      {
                        v111 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v111 & 0xF) << 12);
                        lhs += 2;
                      }
                    }
                    else
                    {
                      v111 = *lhs++ & 0x3F | ((v111 & 0x1F) << 6);
                    }
                  }
                  if ( v143 == v111 )
                    return 0;
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
              else
              {
                for ( j = v163; ; ++j )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v36 = *lhs++;
                  if ( v143 == v36 )
                    return 0;
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
            }
            v160 = lhs;
            if ( v139 )
            {
              for ( j = v163; j < v137; ++j )
              {
                v109 = 1;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] )
                  {
                    if ( (unsigned int)lhs > a5[32] )
                    {
                      a5[23] = 1;
                      if ( (int)a5[33] > 1 )
                        return -12;
                    }
                  }
                  break;
                }
                v110 = *lhs;
                if ( v110 >= 0xC0 )
                {
                  if ( (v110 & 0x20) != 0 )
                  {
                    if ( (v110 & 0x10) != 0 )
                    {
                      if ( (v110 & 8) != 0 )
                      {
                        if ( (v110 & 4) != 0 )
                        {
                          v110 = lhs[5] & 0x3F
                               | ((lhs[4] & 0x3F) << 6)
                               | ((lhs[3] & 0x3F) << 12)
                               | ((lhs[2] & 0x3F) << 18)
                               | ((lhs[1] & 0x3F) << 24)
                               | ((v110 & 1) << 30);
                          v109 = 6;
                        }
                        else
                        {
                          v110 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((v110 & 3) << 24);
                          v109 = 5;
                        }
                      }
                      else
                      {
                        v110 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v110 & 7) << 18);
                        v109 = 4;
                      }
                    }
                    else
                    {
                      v110 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v110 & 0xF) << 12);
                      v109 = 3;
                    }
                  }
                  else
                  {
                    v110 = lhs[1] & 0x3F | ((v110 & 0x1F) << 6);
                    v109 = 2;
                  }
                }
                if ( v143 == v110 )
                  break;
                lhs += v109;
              }
              if ( !v144 )
              {
                while ( 1 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  v37 = (char *)lhs--;
                  if ( v37 == (char *)v160 )
                    break;
                  while ( (*lhs & 0xC0) == 0x80 )
                    --lhs;
                }
                return 0;
              }
            }
            else
            {
              for ( j = v163; j < v137; ++j )
              {
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] )
                  {
                    if ( (unsigned int)lhs > a5[32] )
                    {
                      a5[23] = 1;
                      if ( (int)a5[33] > 1 )
                        return -12;
                    }
                  }
                  break;
                }
                if ( v143 == *lhs )
                  break;
                ++lhs;
              }
              if ( !v144 )
              {
                while ( lhs >= v160 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  --lhs;
                }
                return 0;
              }
            }
          }
        }
        else
        {
          v143 = *(unsigned __int8 *)(a5[12] + v143);
          if ( v139 )
          {
            for ( j = 1; ; ++j )
            {
              if ( j > v163 )
                goto LABEL_1466;
              if ( (unsigned int)lhs >= a5[29] )
                break;
              v116 = *lhs++;
              if ( v116 >= 0xC0 )
              {
                if ( (v116 & 0x20) != 0 )
                {
                  if ( (v116 & 0x10) != 0 )
                  {
                    if ( (v116 & 8) != 0 )
                    {
                      if ( (v116 & 4) != 0 )
                      {
                        v116 = lhs[4] & 0x3F
                             | ((lhs[3] & 0x3F) << 6)
                             | ((lhs[2] & 0x3F) << 12)
                             | ((lhs[1] & 0x3F) << 18)
                             | ((*lhs & 0x3F) << 24)
                             | ((v116 & 1) << 30);
                        lhs += 5;
                      }
                      else
                      {
                        v116 = lhs[3] & 0x3F
                             | ((lhs[2] & 0x3F) << 6)
                             | ((lhs[1] & 0x3F) << 12)
                             | ((*lhs & 0x3F) << 18)
                             | ((v116 & 3) << 24);
                        lhs += 4;
                      }
                    }
                    else
                    {
                      v116 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v116 & 7) << 18);
                      lhs += 3;
                    }
                  }
                  else
                  {
                    v116 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v116 & 0xF) << 12);
                    lhs += 2;
                  }
                }
                else
                {
                  v116 = *lhs++ & 0x3F | ((v116 & 0x1F) << 6);
                }
              }
              if ( v116 < 0x100 )
                v116 = *(unsigned __int8 *)(a5[12] + v116);
              if ( v143 == v116 )
                return 0;
            }
            if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              return -12;
            else
              return 0;
          }
          for ( j = 1; j <= v163; ++j )
          {
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v32 = *(unsigned __int8 *)(a5[12] + *lhs++);
            if ( v143 == v32 )
              return 0;
          }
LABEL_1466:
          if ( v163 != v137 )
          {
            if ( v166 )
            {
              if ( v139 )
              {
                for ( j = v163; ; ++j )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v115 = *lhs++;
                  if ( v115 >= 0xC0 )
                  {
                    if ( (v115 & 0x20) != 0 )
                    {
                      if ( (v115 & 0x10) != 0 )
                      {
                        if ( (v115 & 8) != 0 )
                        {
                          if ( (v115 & 4) != 0 )
                          {
                            v115 = lhs[4] & 0x3F
                                 | ((lhs[3] & 0x3F) << 6)
                                 | ((lhs[2] & 0x3F) << 12)
                                 | ((lhs[1] & 0x3F) << 18)
                                 | ((*lhs & 0x3F) << 24)
                                 | ((v115 & 1) << 30);
                            lhs += 5;
                          }
                          else
                          {
                            v115 = lhs[3] & 0x3F
                                 | ((lhs[2] & 0x3F) << 6)
                                 | ((lhs[1] & 0x3F) << 12)
                                 | ((*lhs & 0x3F) << 18)
                                 | ((v115 & 3) << 24);
                            lhs += 4;
                          }
                        }
                        else
                        {
                          v115 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v115 & 7) << 18);
                          lhs += 3;
                        }
                      }
                      else
                      {
                        v115 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v115 & 0xF) << 12);
                        lhs += 2;
                      }
                    }
                    else
                    {
                      v115 = *lhs++ & 0x3F | ((v115 & 0x1F) << 6);
                    }
                  }
                  if ( v115 < 0x100 )
                    v115 = *(unsigned __int8 *)(a5[12] + v115);
                  if ( v143 == v115 )
                    return 0;
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
              else
              {
                for ( j = v163; ; ++j )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v33 = *(unsigned __int8 *)(a5[12] + *lhs++);
                  if ( v143 == v33 )
                    return 0;
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
            }
            v160 = lhs;
            if ( v139 )
            {
              for ( j = v163; j < v137; ++j )
              {
                v113 = 1;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] )
                  {
                    if ( (unsigned int)lhs > a5[32] )
                    {
                      a5[23] = 1;
                      if ( (int)a5[33] > 1 )
                        return -12;
                    }
                  }
                  break;
                }
                v114 = *lhs;
                if ( v114 >= 0xC0 )
                {
                  if ( (v114 & 0x20) != 0 )
                  {
                    if ( (v114 & 0x10) != 0 )
                    {
                      if ( (v114 & 8) != 0 )
                      {
                        if ( (v114 & 4) != 0 )
                        {
                          v114 = lhs[5] & 0x3F
                               | ((lhs[4] & 0x3F) << 6)
                               | ((lhs[3] & 0x3F) << 12)
                               | ((lhs[2] & 0x3F) << 18)
                               | ((lhs[1] & 0x3F) << 24)
                               | ((v114 & 1) << 30);
                          v113 = 6;
                        }
                        else
                        {
                          v114 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((v114 & 3) << 24);
                          v113 = 5;
                        }
                      }
                      else
                      {
                        v114 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v114 & 7) << 18);
                        v113 = 4;
                      }
                    }
                    else
                    {
                      v114 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v114 & 0xF) << 12);
                      v113 = 3;
                    }
                  }
                  else
                  {
                    v114 = lhs[1] & 0x3F | ((v114 & 0x1F) << 6);
                    v113 = 2;
                  }
                }
                if ( v114 < 0x100 )
                  v114 = *(unsigned __int8 *)(a5[12] + v114);
                if ( v143 == v114 )
                  break;
                lhs += v113;
              }
              if ( !v144 )
              {
                while ( 1 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  v34 = (char *)lhs--;
                  if ( v34 == (char *)v160 )
                    break;
                  while ( (*lhs & 0xC0) == 0x80 )
                    --lhs;
                }
                return 0;
              }
            }
            else
            {
              for ( j = v163; j < v137; ++j )
              {
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] )
                  {
                    if ( (unsigned int)lhs > a5[32] )
                    {
                      a5[23] = 1;
                      if ( (int)a5[33] > 1 )
                        return -12;
                    }
                  }
                  break;
                }
                if ( v143 == *(unsigned __int8 *)(a5[12] + *lhs) )
                  break;
                ++lhs;
              }
              if ( !v144 )
              {
                while ( lhs >= v160 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  --lhs;
                }
                return 0;
              }
            }
          }
        }
        continue;
      case 85:
      case 86:
      case 87:
      case 88:
      case 89:
      case 90:
        v143 = *a2 - 85;
        v177 = a2 + 1;
        v166 = (v143 & 1) != 0;
        v163 = byte_888ECC[v143];
        v137 = byte_888ED4[v143];
        if ( !v137 )
          v137 = 0x7FFFFFFF;
        goto LABEL_1684;
      case 91:
      case 92:
        v163 = 0;
        v137 = a2[2] | (a2[1] << 8);
        v166 = *a2 == 92;
        v177 = a2 + 3;
        goto LABEL_1684;
      case 93:
        v137 = a2[2] | (a2[1] << 8);
        v163 = v137;
        v166 = 1;
        v177 = a2 + 3;
        goto LABEL_1684;
      case 94:
        v144 = 1;
        v163 = 0;
        v137 = 0x7FFFFFFF;
        v177 = a2 + 1;
        goto LABEL_1684;
      case 95:
        v144 = 1;
        v163 = 1;
        v137 = 0x7FFFFFFF;
        v177 = a2 + 1;
        goto LABEL_1684;
      case 96:
        v144 = 1;
        v163 = 0;
        v137 = 1;
        v177 = a2 + 1;
        goto LABEL_1684;
      case 97:
        v144 = 1;
        v163 = 0;
        v137 = a2[2] | (a2[1] << 8);
        v177 = a2 + 3;
LABEL_1684:
        v168 = *v177;
        a2 = v177 + 1;
        if ( v163 <= 0 )
          goto LABEL_2182;
        if ( v139 )
        {
          switch ( v168 )
          {
            case 6:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  v143 = *lhs++;
                  if ( v143 >= 0xC0 )
                  {
                    if ( (v143 & 0x20) != 0 )
                    {
                      if ( (v143 & 0x10) != 0 )
                      {
                        if ( (v143 & 8) != 0 )
                        {
                          if ( (v143 & 4) != 0 )
                          {
                            v143 = lhs[4] & 0x3F
                                 | ((lhs[3] & 0x3F) << 6)
                                 | ((lhs[2] & 0x3F) << 12)
                                 | ((lhs[1] & 0x3F) << 18)
                                 | ((*lhs & 0x3F) << 24)
                                 | ((v143 & 1) << 30);
                            lhs += 5;
                          }
                          else
                          {
                            v143 = lhs[3] & 0x3F
                                 | ((lhs[2] & 0x3F) << 6)
                                 | ((lhs[1] & 0x3F) << 12)
                                 | ((*lhs & 0x3F) << 18)
                                 | ((v143 & 3) << 24);
                            lhs += 4;
                          }
                        }
                        else
                        {
                          v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                          lhs += 3;
                        }
                      }
                      else
                      {
                        v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                        lhs += 2;
                      }
                    }
                    else
                    {
                      v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                    }
                  }
                  if ( v143 >= 0x80 || (*(_BYTE *)(a5[13] + v143) & 4) == 0 )
                  {
                    ++j;
                    continue;
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 7:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( *lhs < 0x80u )
                  {
                    if ( *(_BYTE *)(a5[13] + *lhs++) & 4 )
                    {
                      ++j;
                      continue;
                    }
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 8:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( *lhs >= 0x80u || (*(_BYTE *)(a5[13] + *lhs) & 1) == 0 )
                  {
                    do
                      ++lhs;
                    while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 );
                    ++j;
                    continue;
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 9:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( *lhs < 0x80u )
                  {
                    if ( *(_BYTE *)(a5[13] + *lhs++) & 1 )
                    {
                      ++j;
                      continue;
                    }
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 10:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( *lhs >= 0x80u || (*(_BYTE *)(a5[13] + *lhs) & 0x10) == 0 )
                  {
                    do
                      ++lhs;
                    while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 );
                    ++j;
                    continue;
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 11:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( *lhs < 0x80u )
                  {
                    if ( *(_BYTE *)(a5[13] + *lhs++) & 0x10 )
                    {
                      ++j;
                      continue;
                    }
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 12:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  if ( a5[6] )
                  {
                    v73 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                    v72 = v73;
                  }
                  else
                  {
                    v71 = (unsigned int)lhs <= a5[29] - a5[7]
                       && *lhs == *((unsigned __int8 *)a5 + 44)
                       && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                    v72 = v71;
                  }
                  if ( !v72 )
                  {
                    ++lhs;
                    while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
                      ++lhs;
                    ++j;
                    continue;
                  }
                  return 0;
                }
                else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
            case 13:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs < a5[29] )
                {
                  ++lhs;
                  while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
                    ++lhs;
                  ++j;
                  continue;
                }
                break;
              }
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            case 14:
              if ( (unsigned int)lhs > a5[29] - v163 )
                return 0;
              lhs += v163;
              goto LABEL_2182;
            case 17:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                    return -12;
                  else
                    return 0;
                }
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 > 0xD )
                {
                  if ( v143 == 133 || v143 > 0x2027 && v143 <= 0x2029 )
                    goto LABEL_1766;
                }
                else
                {
                  if ( v143 == 13 )
                  {
                    if ( (unsigned int)lhs < a5[29] && *lhs == 10 )
                      ++lhs;
                    goto LABEL_1734;
                  }
                  if ( v143 == 10 )
                  {
LABEL_1734:
                    ++j;
                    continue;
                  }
                  if ( v143 > 0xA )
                  {
LABEL_1766:
                    if ( a5[24] )
                      return 0;
                    goto LABEL_1734;
                  }
                }
                return 0;
              }
            case 18:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                    return -12;
                  else
                    return 0;
                }
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 > 0x180E )
                {
                  if ( v143 <= 0x205F )
                  {
                    if ( v143 != 8287 && (v143 < 0x2000 || v143 > 0x200A && v143 != 8239) )
                      goto LABEL_1771;
                    return 0;
                  }
                  if ( v143 == 12288 )
                    return 0;
                }
                else
                {
                  if ( v143 == 6158 )
                    return 0;
                  if ( v143 <= 0xA0 )
                  {
                    if ( v143 != 160 && v143 != 9 && v143 != 32 )
                      goto LABEL_1771;
                    return 0;
                  }
                  if ( v143 == 5760 )
                    return 0;
                }
LABEL_1771:
                ++j;
                continue;
              }
            case 19:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                    return -12;
                  else
                    return 0;
                }
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 > 0x180E )
                {
                  if ( v143 <= 0x205F )
                  {
                    if ( v143 != 8287 && (v143 < 0x2000 || v143 > 0x200A && v143 != 8239) )
                      return 0;
                    goto LABEL_1843;
                  }
                  if ( v143 == 12288 )
                    goto LABEL_1843;
                }
                else
                {
                  if ( v143 == 6158 )
                    goto LABEL_1843;
                  if ( v143 <= 0xA0 )
                  {
                    if ( v143 != 160 && v143 != 9 && v143 != 32 )
                      return 0;
LABEL_1843:
                    ++j;
                    continue;
                  }
                  if ( v143 == 5760 )
                    goto LABEL_1843;
                }
                return 0;
              }
            case 20:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                    return -12;
                  else
                    return 0;
                }
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 > 0x85 )
                {
                  if ( v143 < 0x2028 || v143 > 0x2029 )
                    goto LABEL_1846;
                }
                else if ( v143 != 133 && (v143 < 0xA || v143 > 0xD) )
                {
LABEL_1846:
                  ++j;
                  continue;
                }
                return 0;
              }
            case 21:
              j = 1;
              while ( 2 )
              {
                if ( j > v163 )
                  goto LABEL_2182;
                if ( (unsigned int)lhs >= a5[29] )
                {
                  if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                    return -12;
                  else
                    return 0;
                }
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 > 0x85 )
                {
                  if ( v143 < 0x2028 || v143 > 0x2029 )
                    return 0;
                }
                else if ( v143 != 133 && (v143 < 0xA || v143 > 0xD) )
                {
                  return 0;
                }
                ++j;
                continue;
              }
            default:
              return -14;
          }
        }
        switch ( v168 )
        {
          case 6:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( !(*(_BYTE *)(a5[13] + *lhs++) & 4) )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 7:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( *(_BYTE *)(a5[13] + *lhs++) & 4 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 8:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( !(*(_BYTE *)(a5[13] + *lhs++) & 1) )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 9:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( *(_BYTE *)(a5[13] + *lhs++) & 1 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 10:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( !(*(_BYTE *)(a5[13] + *lhs++) & 0x10) )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 11:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( *(_BYTE *)(a5[13] + *lhs++) & 0x10 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 12:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( a5[6] )
                {
                  v70 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                  v69 = v70;
                }
                else
                {
                  v68 = (unsigned int)lhs <= a5[29] - a5[7]
                     && *lhs == *((unsigned __int8 *)a5 + 44)
                     && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                  v69 = v68;
                }
                if ( !v69 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 13:
            if ( (unsigned int)lhs > a5[29] - v163 )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            lhs += v163;
            goto LABEL_2182;
          case 14:
            if ( (unsigned int)lhs > a5[29] - v163 )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            lhs += v163;
LABEL_2182:
            if ( v163 == v137 )
              continue;
            if ( v166 )
            {
              if ( v139 )
              {
                j = v163;
                while ( 1 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  if ( v168 == 12 )
                  {
                    if ( a5[6] )
                    {
                      v62 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                      v61 = v62;
                    }
                    else
                    {
                      v60 = (unsigned int)lhs <= a5[29] - a5[7]
                         && *lhs == *((unsigned __int8 *)a5 + 44)
                         && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                      v61 = v60;
                    }
                    if ( v61 )
                      return 0;
                  }
                  v143 = *lhs++;
                  if ( v143 >= 0xC0 )
                  {
                    if ( (v143 & 0x20) != 0 )
                    {
                      if ( (v143 & 0x10) != 0 )
                      {
                        if ( (v143 & 8) != 0 )
                        {
                          if ( (v143 & 4) != 0 )
                          {
                            v143 = lhs[4] & 0x3F
                                 | ((lhs[3] & 0x3F) << 6)
                                 | ((lhs[2] & 0x3F) << 12)
                                 | ((lhs[1] & 0x3F) << 18)
                                 | ((*lhs & 0x3F) << 24)
                                 | ((v143 & 1) << 30);
                            lhs += 5;
                          }
                          else
                          {
                            v143 = lhs[3] & 0x3F
                                 | ((lhs[2] & 0x3F) << 6)
                                 | ((lhs[1] & 0x3F) << 12)
                                 | ((*lhs & 0x3F) << 18)
                                 | ((v143 & 3) << 24);
                            lhs += 4;
                          }
                        }
                        else
                        {
                          v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                          lhs += 3;
                        }
                      }
                      else
                      {
                        v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                        lhs += 2;
                      }
                    }
                    else
                    {
                      v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                    }
                  }
                  switch ( v168 )
                  {
                    case 6:
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 4) == 0 )
                        goto LABEL_2186;
                      return 0;
                    case 7:
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 4) != 0 )
                        goto LABEL_2186;
                      return 0;
                    case 8:
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 1) == 0 )
                        goto LABEL_2186;
                      return 0;
                    case 9:
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 1) != 0 )
                        goto LABEL_2186;
                      return 0;
                    case 10:
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 0x10) == 0 )
                        goto LABEL_2186;
                      return 0;
                    case 11:
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 0x10) != 0 )
                        goto LABEL_2186;
                      return 0;
                    case 12:
                    case 13:
                    case 14:
                      goto LABEL_2186;
                    case 17:
                      if ( v143 > 0xD )
                      {
                        if ( v143 != 133 && (v143 <= 0x2027 || v143 > 0x2029) )
                          return 0;
                      }
                      else
                      {
                        if ( v143 == 13 )
                        {
                          if ( (unsigned int)lhs < a5[29] && *lhs == 10 )
                            ++lhs;
                          goto LABEL_2186;
                        }
                        if ( v143 == 10 )
                          goto LABEL_2186;
                        if ( v143 <= 0xA )
                          return 0;
                      }
                      if ( a5[24] )
                        return 0;
                      goto LABEL_2186;
                    case 18:
                      if ( v143 > 0x180E )
                      {
                        if ( v143 > 0x205F )
                        {
                          if ( v143 == 12288 )
                            return 0;
                        }
                        else if ( v143 == 8287 || v143 >= 0x2000 && (v143 <= 0x200A || v143 == 8239) )
                        {
                          return 0;
                        }
                      }
                      else
                      {
                        if ( v143 == 6158 )
                          return 0;
                        if ( v143 > 0xA0 )
                        {
                          if ( v143 == 5760 )
                            return 0;
                        }
                        else if ( v143 == 160 || v143 == 9 || v143 == 32 )
                        {
                          return 0;
                        }
                      }
                      goto LABEL_2186;
                    case 19:
                      if ( v143 > 0x180E )
                      {
                        if ( v143 > 0x205F )
                        {
                          if ( v143 != 12288 )
                            return 0;
                        }
                        else if ( v143 != 8287 && (v143 < 0x2000 || v143 > 0x200A && v143 != 8239) )
                        {
                          return 0;
                        }
                      }
                      else if ( v143 != 6158 )
                      {
                        if ( v143 > 0xA0 )
                        {
                          if ( v143 != 5760 )
                            return 0;
                        }
                        else if ( v143 != 160 && v143 != 9 && v143 != 32 )
                        {
                          return 0;
                        }
                      }
                      goto LABEL_2186;
                    case 20:
                      if ( v143 > 0x85 )
                      {
                        if ( v143 >= 0x2028 && v143 <= 0x2029 )
                          return 0;
                      }
                      else if ( v143 == 133 || v143 >= 0xA && v143 <= 0xD )
                      {
                        return 0;
                      }
                      goto LABEL_2186;
                    case 21:
                      if ( v143 > 0x85 )
                      {
                        if ( v143 < 0x2028 || v143 > 0x2029 )
                          return 0;
                      }
                      else if ( v143 != 133 && (v143 < 0xA || v143 > 0xD) )
                      {
                        return 0;
                      }
LABEL_2186:
                      ++j;
                      break;
                    default:
                      return -14;
                  }
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
              else
              {
                j = v163;
                while ( 1 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  if ( j >= v137 )
                    return 0;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  if ( v168 == 12 )
                  {
                    if ( a5[6] )
                    {
                      v59 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                      v58 = v59;
                    }
                    else
                    {
                      v57 = (unsigned int)lhs <= a5[29] - a5[7]
                         && *lhs == *((unsigned __int8 *)a5 + 44)
                         && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                      v58 = v57;
                    }
                    if ( v58 )
                      return 0;
                  }
                  v143 = *lhs++;
                  switch ( v168 )
                  {
                    case 6:
                      if ( (*(_BYTE *)(a5[13] + v143) & 4) == 0 )
                        goto LABEL_2321;
                      return 0;
                    case 7:
                      if ( (*(_BYTE *)(a5[13] + v143) & 4) != 0 )
                        goto LABEL_2321;
                      return 0;
                    case 8:
                      if ( (*(_BYTE *)(a5[13] + v143) & 1) == 0 )
                        goto LABEL_2321;
                      return 0;
                    case 9:
                      if ( (*(_BYTE *)(a5[13] + v143) & 1) != 0 )
                        goto LABEL_2321;
                      return 0;
                    case 10:
                      if ( (*(_BYTE *)(a5[13] + v143) & 0x10) == 0 )
                        goto LABEL_2321;
                      return 0;
                    case 11:
                      if ( (*(_BYTE *)(a5[13] + v143) & 0x10) != 0 )
                        goto LABEL_2321;
                      return 0;
                    case 12:
                    case 13:
                    case 14:
                      goto LABEL_2321;
                    case 17:
                      switch ( v143 )
                      {
                        case 0xAu:
                          goto LABEL_2321;
                        case 0xBu:
                        case 0xCu:
                        case 0x85u:
                          if ( !a5[24] )
                            goto LABEL_2321;
                          result = 0;
                          break;
                        case 0xDu:
                          if ( (unsigned int)lhs < a5[29] && *lhs == 10 )
                            ++lhs;
                          goto LABEL_2321;
                        default:
                          result = 0;
                          break;
                      }
                      return result;
                    case 18:
                      if ( v143 != 9 && v143 != 32 && v143 != 160 )
                        goto LABEL_2321;
                      return 0;
                    case 19:
                      if ( v143 == 9 || v143 == 32 || v143 == 160 )
                        goto LABEL_2321;
                      return 0;
                    case 20:
                      if ( v143 < 0xA || v143 > 0xD && v143 != 133 )
                        goto LABEL_2321;
                      return 0;
                    case 21:
                      if ( v143 < 0xA || v143 > 0xD && v143 != 133 )
                        return 0;
LABEL_2321:
                      ++j;
                      break;
                    default:
                      return -14;
                  }
                }
                if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                  return -12;
                else
                  return 0;
              }
            }
            v160 = lhs;
            if ( v139 )
            {
              switch ( v168 )
              {
                case 6:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v103 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v103 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v103 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v103 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v103 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v103 = 2;
                        }
                      }
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 4) == 0 )
                      {
                        lhs += v103;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 7:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v102 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v102 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v102 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v102 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v102 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v102 = 2;
                        }
                      }
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 4) != 0 )
                      {
                        lhs += v102;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 8:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v101 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v101 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v101 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v101 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v101 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v101 = 2;
                        }
                      }
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 1) == 0 )
                      {
                        lhs += v101;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 9:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v100 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v100 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v100 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v100 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v100 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v100 = 2;
                        }
                      }
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 1) != 0 )
                      {
                        lhs += v100;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 10:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v99 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v99 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v99 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v99 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v99 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v99 = 2;
                        }
                      }
                      if ( v143 >= 0x100 || (*(_BYTE *)(a5[13] + v143) & 0x10) == 0 )
                      {
                        lhs += v99;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 11:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v98 = 1;
                    if ( (unsigned int)lhs < a5[29] )
                    {
                      v143 = *lhs;
                      if ( v143 >= 0xC0 )
                      {
                        if ( (v143 & 0x20) != 0 )
                        {
                          if ( (v143 & 0x10) != 0 )
                          {
                            if ( (v143 & 8) != 0 )
                            {
                              if ( (v143 & 4) != 0 )
                              {
                                v143 = lhs[5] & 0x3F
                                     | ((lhs[4] & 0x3F) << 6)
                                     | ((lhs[3] & 0x3F) << 12)
                                     | ((lhs[2] & 0x3F) << 18)
                                     | ((lhs[1] & 0x3F) << 24)
                                     | ((v143 & 1) << 30);
                                v98 = 6;
                              }
                              else
                              {
                                v143 = lhs[4] & 0x3F
                                     | ((lhs[3] & 0x3F) << 6)
                                     | ((lhs[2] & 0x3F) << 12)
                                     | ((lhs[1] & 0x3F) << 18)
                                     | ((v143 & 3) << 24);
                                v98 = 5;
                              }
                            }
                            else
                            {
                              v143 = lhs[3] & 0x3F
                                   | ((lhs[2] & 0x3F) << 6)
                                   | ((lhs[1] & 0x3F) << 12)
                                   | ((v143 & 7) << 18);
                              v98 = 4;
                            }
                          }
                          else
                          {
                            v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                            v98 = 3;
                          }
                        }
                        else
                        {
                          v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                          v98 = 2;
                        }
                      }
                      if ( v143 < 0x100 && (*(_BYTE *)(a5[13] + v143) & 0x10) != 0 )
                      {
                        lhs += v98;
                        ++j;
                        continue;
                      }
                    }
                    else if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                    goto LABEL_2718;
                  }
                case 12:
                  if ( v137 == 0x7FFFFFFF )
                  {
                    for ( j = v163; ; ++j )
                    {
                      if ( j >= v137 )
                        goto LABEL_2718;
                      if ( (unsigned int)lhs >= a5[29] )
                        break;
                      if ( a5[6] )
                      {
                        v53 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                        v52 = v53;
                      }
                      else
                      {
                        v51 = (unsigned int)lhs <= a5[29] - a5[7]
                           && *lhs == *((unsigned __int8 *)a5 + 44)
                           && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                        v52 = v51;
                      }
                      if ( v52 )
                        goto LABEL_2718;
                      ++lhs;
                      while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
                        ++lhs;
                    }
                    if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                  }
                  else
                  {
                    for ( j = v163; ; ++j )
                    {
                      if ( j >= v137 )
                        goto LABEL_2718;
                      if ( (unsigned int)lhs >= a5[29] )
                        break;
                      if ( a5[6] )
                      {
                        v56 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                        v55 = v56;
                      }
                      else
                      {
                        v54 = (unsigned int)lhs <= a5[29] - a5[7]
                           && *lhs == *((unsigned __int8 *)a5 + 44)
                           && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                        v55 = v54;
                      }
                      if ( v55 )
                        goto LABEL_2718;
                      ++lhs;
                      while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
                        ++lhs;
                    }
                    if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                  }
                  goto LABEL_2718;
                case 13:
                  if ( v137 == 0x7FFFFFFF )
                  {
                    lhs = (unsigned __int8 *)a5[29];
                    if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                  }
                  else
                  {
                    for ( j = v163; ; ++j )
                    {
                      if ( j >= v137 )
                        goto LABEL_2718;
                      if ( (unsigned int)lhs >= a5[29] )
                        break;
                      ++lhs;
                      while ( (unsigned int)lhs < a5[29] && (*lhs & 0xC0) == 0x80 )
                        ++lhs;
                    }
                    if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                  }
                  goto LABEL_2718;
                case 14:
                  v143 = v137 - v163;
                  if ( v137 - v163 <= a5[29] - (unsigned int)lhs )
                  {
                    lhs += v143;
                  }
                  else
                  {
                    lhs = (unsigned __int8 *)a5[29];
                    if ( a5[33] )
                    {
                      if ( (unsigned int)lhs > a5[32] )
                      {
                        a5[23] = 1;
                        if ( (int)a5[33] > 1 )
                          return -12;
                      }
                    }
                  }
                  goto LABEL_2718;
                case 17:
                  j = v163;
                  while ( j < v137 )
                  {
                    v108 = 1;
                    if ( (unsigned int)lhs >= a5[29] )
                    {
                      if ( a5[33] )
                      {
                        if ( (unsigned int)lhs > a5[32] )
                        {
                          a5[23] = 1;
                          if ( (int)a5[33] > 1 )
                            return -12;
                        }
                      }
                      break;
                    }
                    v143 = *lhs;
                    if ( v143 >= 0xC0 )
                    {
                      if ( (v143 & 0x20) != 0 )
                      {
                        if ( (v143 & 0x10) != 0 )
                        {
                          if ( (v143 & 8) != 0 )
                          {
                            if ( (v143 & 4) != 0 )
                            {
                              v143 = lhs[5] & 0x3F
                                   | ((lhs[4] & 0x3F) << 6)
                                   | ((lhs[3] & 0x3F) << 12)
                                   | ((lhs[2] & 0x3F) << 18)
                                   | ((lhs[1] & 0x3F) << 24)
                                   | ((v143 & 1) << 30);
                              v108 = 6;
                            }
                            else
                            {
                              v143 = lhs[4] & 0x3F
                                   | ((lhs[3] & 0x3F) << 6)
                                   | ((lhs[2] & 0x3F) << 12)
                                   | ((lhs[1] & 0x3F) << 18)
                                   | ((v143 & 3) << 24);
                              v108 = 5;
                            }
                          }
                          else
                          {
                            v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                            v108 = 4;
                          }
                        }
                        else
                        {
                          v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                          v108 = 3;
                        }
                      }
                      else
                      {
                        v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                        v108 = 2;
                      }
                    }
                    if ( v143 == 13 )
                    {
                      if ( (unsigned int)++lhs < a5[29] )
                      {
                        if ( *lhs == 10 )
                          ++lhs;
                        goto LABEL_2482;
                      }
                    }
                    else if ( v143 == 10
                           || !a5[24] && (v143 == 11 || v143 == 12 || v143 == 133 || v143 == 8232 || v143 == 8233) )
                    {
                      lhs += v108;
LABEL_2482:
                      ++j;
                      continue;
                    }
                    break;
                  }
LABEL_2718:
                  if ( !v144 )
                  {
                    while ( 1 )
                    {
                      v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                      if ( v138 )
                        return v138;
                      v47 = (char *)lhs--;
                      if ( v47 == (char *)v160 )
                        break;
                      while ( (*lhs & 0xC0) == 0x80 )
                        --lhs;
                      if ( v168 == 17 && lhs > v160 && *lhs == 10 && *(lhs - 1) == 13 )
                        --lhs;
                    }
                    return 0;
                  }
                  continue;
                case 18:
                case 19:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v106 = 1;
                    if ( (unsigned int)lhs >= a5[29] )
                    {
                      if ( a5[33] )
                      {
                        if ( (unsigned int)lhs > a5[32] )
                        {
                          a5[23] = 1;
                          if ( (int)a5[33] > 1 )
                            return -12;
                        }
                      }
                      goto LABEL_2718;
                    }
                    v143 = *lhs;
                    if ( v143 >= 0xC0 )
                    {
                      if ( (v143 & 0x20) != 0 )
                      {
                        if ( (v143 & 0x10) != 0 )
                        {
                          if ( (v143 & 8) != 0 )
                          {
                            if ( (v143 & 4) != 0 )
                            {
                              v143 = lhs[5] & 0x3F
                                   | ((lhs[4] & 0x3F) << 6)
                                   | ((lhs[3] & 0x3F) << 12)
                                   | ((lhs[2] & 0x3F) << 18)
                                   | ((lhs[1] & 0x3F) << 24)
                                   | ((v143 & 1) << 30);
                              v106 = 6;
                            }
                            else
                            {
                              v143 = lhs[4] & 0x3F
                                   | ((lhs[3] & 0x3F) << 6)
                                   | ((lhs[2] & 0x3F) << 12)
                                   | ((lhs[1] & 0x3F) << 18)
                                   | ((v143 & 3) << 24);
                              v106 = 5;
                            }
                          }
                          else
                          {
                            v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                            v106 = 4;
                          }
                        }
                        else
                        {
                          v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                          v106 = 3;
                        }
                      }
                      else
                      {
                        v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                        v106 = 2;
                      }
                    }
                    if ( v143 > 0x180E )
                    {
                      if ( v143 <= 0x205F )
                      {
                        if ( v143 != 8287 && (v143 < 0x2000 || v143 > 0x200A && v143 != 8239) )
                          break;
                        goto LABEL_2550;
                      }
                      if ( v143 == 12288 )
                        goto LABEL_2550;
                    }
                    else
                    {
                      if ( v143 == 6158 )
                        goto LABEL_2550;
                      if ( v143 <= 0xA0 )
                      {
                        if ( v143 != 160 && v143 != 9 && v143 != 32 )
                          break;
LABEL_2550:
                        v107 = 1;
LABEL_2551:
                        if ( v107 != (v168 == 18) )
                        {
                          lhs += v106;
                          ++j;
                          continue;
                        }
                        goto LABEL_2718;
                      }
                      if ( v143 == 5760 )
                        goto LABEL_2550;
                    }
                    break;
                  }
                  v107 = 0;
                  goto LABEL_2551;
                case 20:
                case 21:
                  j = v163;
                  while ( 2 )
                  {
                    if ( j >= v137 )
                      goto LABEL_2718;
                    v104 = 1;
                    if ( (unsigned int)lhs >= a5[29] )
                    {
                      if ( a5[33] )
                      {
                        if ( (unsigned int)lhs > a5[32] )
                        {
                          a5[23] = 1;
                          if ( (int)a5[33] > 1 )
                            return -12;
                        }
                      }
                      goto LABEL_2718;
                    }
                    v143 = *lhs;
                    if ( v143 >= 0xC0 )
                    {
                      if ( (v143 & 0x20) != 0 )
                      {
                        if ( (v143 & 0x10) != 0 )
                        {
                          if ( (v143 & 8) != 0 )
                          {
                            if ( (v143 & 4) != 0 )
                            {
                              v143 = lhs[5] & 0x3F
                                   | ((lhs[4] & 0x3F) << 6)
                                   | ((lhs[3] & 0x3F) << 12)
                                   | ((lhs[2] & 0x3F) << 18)
                                   | ((lhs[1] & 0x3F) << 24)
                                   | ((v143 & 1) << 30);
                              v104 = 6;
                            }
                            else
                            {
                              v143 = lhs[4] & 0x3F
                                   | ((lhs[3] & 0x3F) << 6)
                                   | ((lhs[2] & 0x3F) << 12)
                                   | ((lhs[1] & 0x3F) << 18)
                                   | ((v143 & 3) << 24);
                              v104 = 5;
                            }
                          }
                          else
                          {
                            v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                            v104 = 4;
                          }
                        }
                        else
                        {
                          v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                          v104 = 3;
                        }
                      }
                      else
                      {
                        v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                        v104 = 2;
                      }
                    }
                    if ( v143 > 0x85 )
                    {
                      if ( v143 < 0x2028 || v143 > 0x2029 )
                        goto LABEL_2579;
                    }
                    else if ( v143 != 133 && (v143 < 0xA || v143 > 0xD) )
                    {
LABEL_2579:
                      v105 = 0;
                      goto LABEL_2581;
                    }
                    v105 = 1;
LABEL_2581:
                    if ( v105 != (v168 == 20) )
                    {
                      lhs += v104;
                      ++j;
                      continue;
                    }
                    goto LABEL_2718;
                  }
                default:
                  return -14;
              }
            }
            break;
          case 17:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                v67 = *lhs++;
                switch ( v67 )
                {
                  case 10:
                    goto LABEL_2036;
                  case 11:
                  case 12:
                  case 133:
                    if ( !a5[24] )
                      goto LABEL_2036;
                    return 0;
                  case 13:
                    if ( (unsigned int)lhs < a5[29] && *lhs == 10 )
                      ++lhs;
LABEL_2036:
                    ++j;
                    continue;
                  default:
                    return 0;
                }
              }
              break;
            }
            if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              return -12;
            else
              return 0;
          case 18:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                v66 = *lhs++;
                if ( v66 != 9 && v66 != 32 && v66 != 160 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 19:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                v65 = *lhs++;
                if ( v65 == 9 || v65 == 32 || v65 == 160 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 20:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                v64 = *lhs++;
                if ( v64 < 10 || v64 > 13 && v64 != 133 )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          case 21:
            j = 1;
            while ( 2 )
            {
              if ( j > v163 )
                goto LABEL_2182;
              if ( (unsigned int)lhs < a5[29] )
              {
                v63 = *lhs++;
                if ( v63 >= 10 && (v63 <= 13 || v63 == 133) )
                {
                  ++j;
                  continue;
                }
                return 0;
              }
              else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
              {
                return -12;
              }
              else
              {
                return 0;
              }
            }
          default:
            return -14;
        }
        switch ( v168 )
        {
          case 6:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 4) == 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 7:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 4) != 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 8:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 1) == 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 9:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 1) != 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 10:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 0x10) == 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 11:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( (*(_BYTE *)(a5[13] + *lhs) & 0x10) != 0 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 12:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                if ( a5[6] )
                {
                  v50 = (unsigned int)lhs < a5[29] && _pcre_is_newline(lhs, a5[6], a5[29], a5 + 7, v139);
                  v49 = v50;
                }
                else
                {
                  v48 = (unsigned int)lhs <= a5[29] - a5[7]
                     && *lhs == *((unsigned __int8 *)a5 + 44)
                     && (a5[7] == 1 || lhs[1] == *((unsigned __int8 *)a5 + 45));
                  v49 = v48;
                }
                if ( !v49 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 13:
          case 14:
            v143 = v137 - v163;
            if ( v137 - v163 <= a5[29] - (unsigned int)lhs )
            {
              lhs += v143;
            }
            else
            {
              lhs = (unsigned __int8 *)a5[29];
              if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
            }
            goto LABEL_2908;
          case 17:
            j = v163;
            while ( j < v137 )
            {
              if ( (unsigned int)lhs >= a5[29] )
              {
                if ( a5[33] )
                {
                  if ( (unsigned int)lhs > a5[32] )
                  {
                    a5[23] = 1;
                    if ( (int)a5[33] > 1 )
                      return -12;
                  }
                }
                break;
              }
              v143 = *lhs;
              if ( v143 == 13 )
              {
                if ( (unsigned int)++lhs < a5[29] )
                {
                  if ( *lhs == 10 )
                    ++lhs;
                  goto LABEL_2764;
                }
              }
              else if ( v143 == 10 || !a5[24] && (v143 == 11 || v143 == 12 || v143 == 133) )
              {
                ++lhs;
LABEL_2764:
                ++j;
                continue;
              }
              break;
            }
LABEL_2908:
            if ( !v144 )
            {
              while ( lhs >= v160 )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                --lhs;
                if ( v168 == 17 && lhs > v160 && *lhs == 10 && *(lhs - 1) == 13 )
                  --lhs;
              }
              return 0;
            }
            break;
          case 18:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                v143 = *lhs;
                if ( v143 != 9 && v143 != 32 && v143 != 160 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 19:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                v143 = *lhs;
                if ( v143 == 9 || v143 == 32 || v143 == 160 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 20:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                v143 = *lhs;
                if ( v143 != 10 && v143 != 11 && v143 != 12 && v143 != 13 && v143 != 133 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          case 21:
            j = v163;
            while ( 2 )
            {
              if ( j >= v137 )
                goto LABEL_2908;
              if ( (unsigned int)lhs < a5[29] )
              {
                v143 = *lhs;
                if ( v143 == 10 || v143 == 11 || v143 == 12 || v143 == 13 || v143 == 133 )
                {
                  ++lhs;
                  ++j;
                  continue;
                }
              }
              else if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_2908;
            }
          default:
            return -14;
        }
        continue;
      case 106:
      case 107:
        v147 = a2 + 1;
        a2 += 33;
        switch ( *a2 )
        {
          case 'b':
          case 'c':
          case 'd':
          case 'e':
          case 'f':
          case 'g':
            v143 = *a2++ - 98;
            v166 = (v143 & 1) != 0;
            v163 = byte_888ECC[v143];
            v137 = byte_888ED4[v143];
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            break;
          case 'h':
          case 'i':
            v166 = *a2 == 105;
            v163 = a2[2] | (a2[1] << 8);
            v137 = a2[4] | (a2[3] << 8);
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            a2 += 5;
            break;
          default:
            v137 = 1;
            v163 = 1;
            break;
        }
        if ( !v139 )
        {
          for ( j = 1; j <= v163; ++j )
          {
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            v143 = *lhs++;
            if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
              return 0;
          }
LABEL_989:
          if ( v163 != v137 )
          {
            if ( !v166 )
            {
              v160 = lhs;
              if ( v139 )
              {
                for ( j = v163; ; ++j )
                {
                  if ( j >= v137 )
                    goto LABEL_1059;
                  v119 = 1;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v143 = *lhs;
                  if ( v143 >= 0xC0 )
                  {
                    if ( (v143 & 0x20) != 0 )
                    {
                      if ( (v143 & 0x10) != 0 )
                      {
                        if ( (v143 & 8) != 0 )
                        {
                          if ( (v143 & 4) != 0 )
                          {
                            v143 = lhs[5] & 0x3F
                                 | ((lhs[4] & 0x3F) << 6)
                                 | ((lhs[3] & 0x3F) << 12)
                                 | ((lhs[2] & 0x3F) << 18)
                                 | ((lhs[1] & 0x3F) << 24)
                                 | ((v143 & 1) << 30);
                            v119 = 6;
                          }
                          else
                          {
                            v143 = lhs[4] & 0x3F
                                 | ((lhs[3] & 0x3F) << 6)
                                 | ((lhs[2] & 0x3F) << 12)
                                 | ((lhs[1] & 0x3F) << 18)
                                 | ((v143 & 3) << 24);
                            v119 = 5;
                          }
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                          v119 = 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                        v119 = 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                      v119 = 2;
                    }
                  }
                  if ( v143 <= 0xFF )
                  {
                    if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
                      goto LABEL_1059;
                  }
                  else if ( v142 == 106 )
                  {
                    goto LABEL_1059;
                  }
                  lhs += v119;
                }
                if ( a5[33] )
                {
                  if ( (unsigned int)lhs > a5[32] )
                  {
                    a5[23] = 1;
                    if ( (int)a5[33] > 1 )
                      return -12;
                  }
                }
                while ( 1 )
                {
LABEL_1059:
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  v17 = (char *)lhs--;
                  if ( v17 == (char *)v160 )
                    break;
                  while ( (*lhs & 0xC0) == 0x80 )
                    --lhs;
                }
              }
              else
              {
                for ( j = v163; ; ++j )
                {
                  if ( j >= v137 )
                    goto LABEL_1076;
                  if ( (unsigned int)lhs >= a5[29] )
                    break;
                  v143 = *lhs;
                  if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
                    goto LABEL_1076;
                  ++lhs;
                }
                if ( a5[33] )
                {
                  if ( (unsigned int)lhs > a5[32] )
                  {
                    a5[23] = 1;
                    if ( (int)a5[33] > 1 )
                      return -12;
                  }
                }
LABEL_1076:
                while ( lhs >= v160 )
                {
                  v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                  if ( v138 )
                    return v138;
                  --lhs;
                }
              }
              return 0;
            }
            if ( v139 )
            {
              for ( j = v163; ; ++j )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                if ( j >= v137 )
                  return 0;
                if ( (unsigned int)lhs >= a5[29] )
                  break;
                v143 = *lhs++;
                if ( v143 >= 0xC0 )
                {
                  if ( (v143 & 0x20) != 0 )
                  {
                    if ( (v143 & 0x10) != 0 )
                    {
                      if ( (v143 & 8) != 0 )
                      {
                        if ( (v143 & 4) != 0 )
                        {
                          v143 = lhs[4] & 0x3F
                               | ((lhs[3] & 0x3F) << 6)
                               | ((lhs[2] & 0x3F) << 12)
                               | ((lhs[1] & 0x3F) << 18)
                               | ((*lhs & 0x3F) << 24)
                               | ((v143 & 1) << 30);
                          lhs += 5;
                        }
                        else
                        {
                          v143 = lhs[3] & 0x3F
                               | ((lhs[2] & 0x3F) << 6)
                               | ((lhs[1] & 0x3F) << 12)
                               | ((*lhs & 0x3F) << 18)
                               | ((v143 & 3) << 24);
                          lhs += 4;
                        }
                      }
                      else
                      {
                        v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                        lhs += 3;
                      }
                    }
                    else
                    {
                      v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                      lhs += 2;
                    }
                  }
                  else
                  {
                    v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                  }
                }
                if ( v143 <= 0xFF )
                {
                  if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
                    return 0;
                }
                else if ( v142 == 106 )
                {
                  return 0;
                }
              }
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            else
            {
              for ( j = v163; ; ++j )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                if ( j >= v137 )
                  return 0;
                if ( (unsigned int)lhs >= a5[29] )
                  break;
                v143 = *lhs++;
                if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
                  return 0;
              }
              if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
          }
          continue;
        }
        for ( j = 1; ; ++j )
        {
          if ( j > v163 )
            goto LABEL_989;
          if ( (unsigned int)lhs >= a5[29] )
            break;
          v143 = *lhs++;
          if ( v143 >= 0xC0 )
          {
            if ( (v143 & 0x20) != 0 )
            {
              if ( (v143 & 0x10) != 0 )
              {
                if ( (v143 & 8) != 0 )
                {
                  if ( (v143 & 4) != 0 )
                  {
                    v143 = lhs[4] & 0x3F
                         | ((lhs[3] & 0x3F) << 6)
                         | ((lhs[2] & 0x3F) << 12)
                         | ((lhs[1] & 0x3F) << 18)
                         | ((*lhs & 0x3F) << 24)
                         | ((v143 & 1) << 30);
                    lhs += 5;
                  }
                  else
                  {
                    v143 = lhs[3] & 0x3F
                         | ((lhs[2] & 0x3F) << 6)
                         | ((lhs[1] & 0x3F) << 12)
                         | ((*lhs & 0x3F) << 18)
                         | ((v143 & 3) << 24);
                    lhs += 4;
                  }
                }
                else
                {
                  v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                  lhs += 3;
                }
              }
              else
              {
                v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                lhs += 2;
              }
            }
            else
            {
              v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
            }
          }
          if ( v143 <= 0xFF )
          {
            if ( ((1 << (v143 & 7)) & v147[v143 >> 3]) == 0 )
              return 0;
          }
          else if ( v142 == 106 )
          {
            return 0;
          }
        }
        if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
          return -12;
        else
          return 0;
      case 108:
        v147 = a2 + 3;
        a2 += a2[2] | (a2[1] << 8);
        switch ( *a2 )
        {
          case 'b':
          case 'c':
          case 'd':
          case 'e':
          case 'f':
          case 'g':
            v143 = *a2++ - 98;
            v166 = (v143 & 1) != 0;
            v163 = byte_888ECC[v143];
            v137 = byte_888ED4[v143];
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            break;
          case 'h':
          case 'i':
            v166 = *a2 == 105;
            v163 = a2[2] | (a2[1] << 8);
            v137 = a2[4] | (a2[3] << 8);
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            a2 += 5;
            break;
          default:
            v137 = 1;
            v163 = 1;
            break;
        }
        j = 1;
        while ( 2 )
        {
          if ( j <= v163 )
          {
            if ( (unsigned int)lhs < a5[29] )
            {
              v143 = *lhs++;
              if ( v139 && v143 >= 0xC0 )
              {
                if ( (v143 & 0x20) != 0 )
                {
                  if ( (v143 & 0x10) != 0 )
                  {
                    if ( (v143 & 8) != 0 )
                    {
                      if ( (v143 & 4) != 0 )
                      {
                        v143 = lhs[4] & 0x3F
                             | ((lhs[3] & 0x3F) << 6)
                             | ((lhs[2] & 0x3F) << 12)
                             | ((lhs[1] & 0x3F) << 18)
                             | ((*lhs & 0x3F) << 24)
                             | ((v143 & 1) << 30);
                        lhs += 5;
                      }
                      else
                      {
                        v143 = lhs[3] & 0x3F
                             | ((lhs[2] & 0x3F) << 6)
                             | ((lhs[1] & 0x3F) << 12)
                             | ((*lhs & 0x3F) << 18)
                             | ((v143 & 3) << 24);
                        lhs += 4;
                      }
                    }
                    else
                    {
                      v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                      lhs += 3;
                    }
                  }
                  else
                  {
                    v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                    lhs += 2;
                  }
                }
                else
                {
                  v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
                }
              }
              if ( _pcre_xclass(v143, v147) )
              {
                ++j;
                continue;
              }
              return 0;
            }
            else if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            {
              return -12;
            }
            else
            {
              return 0;
            }
          }
          break;
        }
        if ( v163 == v137 )
          continue;
        if ( v166 )
        {
          for ( j = v163; ; ++j )
          {
            v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            if ( v138 )
              return v138;
            if ( j >= v137 )
              return 0;
            if ( (unsigned int)lhs >= a5[29] )
              break;
            v143 = *lhs++;
            if ( v139 && v143 >= 0xC0 )
            {
              if ( (v143 & 0x20) != 0 )
              {
                if ( (v143 & 0x10) != 0 )
                {
                  if ( (v143 & 8) != 0 )
                  {
                    if ( (v143 & 4) != 0 )
                    {
                      v143 = lhs[4] & 0x3F
                           | ((lhs[3] & 0x3F) << 6)
                           | ((lhs[2] & 0x3F) << 12)
                           | ((lhs[1] & 0x3F) << 18)
                           | ((*lhs & 0x3F) << 24)
                           | ((v143 & 1) << 30);
                      lhs += 5;
                    }
                    else
                    {
                      v143 = lhs[3] & 0x3F
                           | ((lhs[2] & 0x3F) << 6)
                           | ((lhs[1] & 0x3F) << 12)
                           | ((*lhs & 0x3F) << 18)
                           | ((v143 & 3) << 24);
                      lhs += 4;
                    }
                  }
                  else
                  {
                    v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((*lhs & 0x3F) << 12) | ((v143 & 7) << 18);
                    lhs += 3;
                  }
                }
                else
                {
                  v143 = lhs[1] & 0x3F | ((*lhs & 0x3F) << 6) | ((v143 & 0xF) << 12);
                  lhs += 2;
                }
              }
              else
              {
                v143 = *lhs++ & 0x3F | ((v143 & 0x1F) << 6);
              }
            }
            if ( !_pcre_xclass(v143, v147) )
              return 0;
          }
          if ( a5[33] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
            return -12;
          else
            return 0;
        }
        else
        {
          v160 = lhs;
          for ( j = v163; j < v137; ++j )
          {
            v118 = 1;
            if ( (unsigned int)lhs >= a5[29] )
            {
              if ( a5[33] )
              {
                if ( (unsigned int)lhs > a5[32] )
                {
                  a5[23] = 1;
                  if ( (int)a5[33] > 1 )
                    return -12;
                }
              }
              goto LABEL_1158;
            }
            v143 = *lhs;
            if ( v139 && v143 >= 0xC0 )
            {
              if ( (v143 & 0x20) != 0 )
              {
                if ( (v143 & 0x10) != 0 )
                {
                  if ( (v143 & 8) != 0 )
                  {
                    if ( (v143 & 4) != 0 )
                    {
                      v143 = lhs[5] & 0x3F
                           | ((lhs[4] & 0x3F) << 6)
                           | ((lhs[3] & 0x3F) << 12)
                           | ((lhs[2] & 0x3F) << 18)
                           | ((lhs[1] & 0x3F) << 24)
                           | ((v143 & 1) << 30);
                      v118 = 6;
                    }
                    else
                    {
                      v143 = lhs[4] & 0x3F
                           | ((lhs[3] & 0x3F) << 6)
                           | ((lhs[2] & 0x3F) << 12)
                           | ((lhs[1] & 0x3F) << 18)
                           | ((v143 & 3) << 24);
                      v118 = 5;
                    }
                  }
                  else
                  {
                    v143 = lhs[3] & 0x3F | ((lhs[2] & 0x3F) << 6) | ((lhs[1] & 0x3F) << 12) | ((v143 & 7) << 18);
                    v118 = 4;
                  }
                }
                else
                {
                  v143 = lhs[2] & 0x3F | ((lhs[1] & 0x3F) << 6) | ((v143 & 0xF) << 12);
                  v118 = 3;
                }
              }
              else
              {
                v143 = lhs[1] & 0x3F | ((v143 & 0x1F) << 6);
                v118 = 2;
              }
            }
            if ( !_pcre_xclass(v143, v147) )
              goto LABEL_1158;
            lhs += v118;
          }
          while ( 1 )
          {
LABEL_1158:
            v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            if ( v138 )
              return v138;
            v18 = (char *)lhs--;
            if ( v18 == (char *)v160 )
              break;
            if ( v139 )
            {
              while ( (*lhs & 0xC0) == 0x80 )
                --lhs;
            }
          }
          return 0;
        }
      case 109:
      case 110:
        v170 = v142 == 110;
        v153 = 2 * (a2[2] | (a2[1] << 8));
        a2 += 3;
        if ( v153 < a4 && *(int *)(a5[3] + 4 * v153) >= 0 )
          siz = *(_DWORD *)(a5[3] + 4 * v153 + 4) - *(_DWORD *)(a5[3] + 4 * v153);
        else
          siz = (a5[18] != 0) - 1;
        switch ( *a2 )
        {
          case 'b':
          case 'c':
          case 'd':
          case 'e':
          case 'f':
          case 'g':
            v143 = *a2++ - 98;
            v166 = (v143 & 1) != 0;
            v163 = byte_888ECC[v143];
            v137 = byte_888ED4[v143];
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            goto LABEL_902;
          case 'h':
          case 'i':
            v166 = *a2 == 105;
            v163 = a2[2] | (a2[1] << 8);
            v137 = a2[4] | (a2[3] << 8);
            if ( !v137 )
              v137 = 0x7FFFFFFF;
            a2 += 5;
LABEL_902:
            if ( !siz )
              continue;
            j = 1;
            while ( 2 )
            {
              if ( j <= v163 )
              {
                v122 = sub_523460(v153, lhs, siz, a5, v170);
                if ( v122 >= 0 )
                {
                  lhs += v122;
                  ++j;
                  continue;
                }
                if ( a5[33]
                  && (unsigned int)lhs >= a5[29]
                  && (unsigned int)lhs > a5[32]
                  && (a5[23] = 1, (int)a5[33] > 1) )
                {
                  return -12;
                }
                else
                {
                  return 0;
                }
              }
              break;
            }
            if ( v163 == v137 )
              continue;
            if ( v166 )
            {
              for ( j = v163; ; ++j )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                if ( j >= v137 )
                  return 0;
                v121 = sub_523460(v153, lhs, siz, a5, v170);
                if ( v121 < 0 )
                  break;
                lhs += v121;
              }
              if ( a5[33] && (unsigned int)lhs >= a5[29] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                result = -12;
              else
                result = 0;
            }
            else
            {
              v160 = lhs;
              for ( j = v163; j < v137; ++j )
              {
                v120 = sub_523460(v153, lhs, siz, a5, v170);
                if ( v120 < 0 )
                {
                  if ( a5[33] )
                  {
                    if ( (unsigned int)lhs >= a5[29] && (unsigned int)lhs > a5[32] )
                    {
                      a5[23] = 1;
                      if ( (int)a5[33] > 1 )
                        return -12;
                    }
                  }
                  break;
                }
                lhs += v120;
              }
              while ( lhs >= v160 )
              {
                v138 = sub_5147C0(lhs, (int)a2, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
                if ( v138 )
                  return v138;
                lhs -= siz;
              }
              result = 0;
            }
            break;
          default:
            siz = sub_523460(v153, lhs, siz, a5, v170);
            if ( (siz & 0x80000000) != 0 )
            {
              if ( a5[33] && (unsigned int)lhs >= a5[29] && (unsigned int)lhs > a5[32] && (a5[23] = 1, (int)a5[33] > 1) )
                return -12;
              else
                return 0;
            }
            lhs += siz;
            continue;
        }
        return result;
      case 111:
        v136 = (unsigned __int8 *)(a5[27] + (a2[2] | (a2[1] << 8)));
        if ( v136 == (unsigned __int8 *)a5[27] )
          v91 = 0;
        else
          v91 = v136[4] | (v136[3] << 8);
        v126 = (int **)a5[40];
        while ( 2 )
        {
          if ( v126 )
          {
            if ( (int *)v91 != v126[1] || lhs != (unsigned __int8 *)v126[4] )
            {
              v126 = (int **)*v126;
              continue;
            }
            return -26;
          }
          break;
        }
        v156[1] = v91;
        v159 = (char *)lhs;
        v156[0] = a5[40];
        a5[40] = (unsigned int)v156;
        a2 += 3;
        v158 = a5[4];
        if ( v158 > 30 )
        {
          dst = (unsigned __int8 *)pcre_malloc(4 * v158);
          if ( !dst )
            return -6;
        }
        else
        {
          dst = v155;
        }
        memcpy(dst, (unsigned __int8 *)a5[3], 4 * v158);
        v148 = *v136 >= 0x82u;
        while ( 1 )
        {
          if ( v148 )
            a5[37] = 2;
          v138 = sub_5147C0(
                   lhs,
                   (int)&v136[(unsigned __int8)_pcre_OP_lengths[*v136]],
                   (int)a3,
                   a4,
                   (int)a5,
                   (int)a6,
                   a7 + 1);
          memcpy((unsigned __int8 *)a5[3], dst, 4 * v158);
          a5[40] = v156[0];
          if ( v138 == 1 || v138 == -999 )
            break;
          if ( v138 && v138 != -992 )
          {
            if ( dst != v155 )
              pcre_free(dst);
            return v138;
          }
          a5[40] = (unsigned int)v156;
          v136 += v136[2] | (v136[1] << 8);
          if ( *v136 != 113 )
          {
            a5[40] = v156[0];
            if ( dst != v155 )
              pcre_free(dst);
            return 0;
          }
        }
        if ( dst != v155 )
          pcre_free(dst);
        lhs = (unsigned __int8 *)a5[31];
        a3 = (unsigned __int8 *)a5[30];
        continue;
      case 112:
        if ( !pcre_callout )
          goto LABEL_314;
        v127[0] = 2;
        v127[1] = a2[1];
        v127[2] = a5[3];
        v127[3] = a5[28];
        v127[4] = a5[29] - a5[28];
        v127[5] = &a3[-a5[28]];
        v127[6] = &lhs[-a5[28]];
        v127[10] = a2[3] | (a2[2] << 8);
        v127[11] = a2[5] | (a2[4] << 8);
        v127[7] = a4 / 2;
        v127[8] = a5[35];
        v127[9] = a5[41];
        v127[12] = a5[43];
        v138 = pcre_callout(v127);
        if ( v138 > 0 )
          return 0;
        if ( v138 < 0 )
          return v138;
LABEL_314:
        a2 += 6;
        continue;
      case 113:
        do
          a2 += a2[2] | (a2[1] << 8);
        while ( *a2 == 113 );
        continue;
      case 114:
      case 115:
      case 116:
      case 117:
        v161 = (int)&a2[-(a2[2] | (a2[1] << 8))];
        if ( *(unsigned __int8 *)v161 >= 0x82u || *(_BYTE *)v161 == 123 )
        {
          v149 = (unsigned __int8 *)a6[1];
          a6 = (int *)*a6;
        }
        else
        {
          v149 = 0;
        }
        if ( *(unsigned __int8 *)v161 >= 0x77u && *(unsigned __int8 *)v161 <= 0x7Au || *(_BYTE *)v161 == 124 )
        {
          a5[31] = (unsigned int)lhs;
          a5[34] = a4;
          a5[30] = (unsigned int)a3;
          return 1;
        }
        if ( *(_BYTE *)v161 != 127
          && *(unsigned __int8 *)v161 != 132
          && *(unsigned __int8 *)v161 != 128
          && *(unsigned __int8 *)v161 != 133 )
        {
          goto LABEL_386;
        }
        v141 = *(unsigned __int8 *)(v161 + 4) | (*(unsigned __int8 *)(v161 + 3) << 8);
        v153 = 2 * v141;
        if ( a5[40] && *(_DWORD *)(a5[40] + 4) == v141 )
        {
          a5[31] = (unsigned int)lhs;
          a5[30] = (unsigned int)a3;
          return 1;
        }
        a5[35] = v141;
        if ( v153 < (int)a5[5] )
        {
          if ( v153 > a4 )
          {
            v124 = (_DWORD *)(a5[3] + 4 * a4);
            v125 = a5[3] + 4 * v153;
            while ( (unsigned int)v124 < v125 )
              *v124++ = -1;
          }
          *(_DWORD *)(a5[3] + 4 * v153) = *(_DWORD *)(a5[3] + 4 * (a5[4] - v141));
          *(_DWORD *)(a5[3] + 4 * v153 + 4) = &lhs[-a5[28]];
          if ( a4 <= v153 )
            a4 = v153 + 2;
        }
        else
        {
          a5[14] = 1;
        }
LABEL_386:
        if ( *a2 == 114 || lhs == v149 )
        {
          if ( *(_BYTE *)v161 == 123 )
          {
            v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            if ( v138 )
              return v138;
            a5[44] = v161;
            return -996;
          }
          a2 += 3;
          continue;
        }
        if ( *a2 == 117 )
        {
          a5[31] = (unsigned int)lhs;
          a5[34] = a4;
          return -997;
        }
        if ( *a2 == 116 )
        {
          v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          if ( v138 )
            return v138;
          if ( *(_BYTE *)v161 == 123 )
          {
            v138 = sub_5147C0(lhs, v161, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            if ( v138 )
              return v138;
            a5[44] = v161;
            return -996;
          }
          if ( *(unsigned __int8 *)v161 >= 0x82u )
          {
            a5[37] = 2;
            result = sub_5147C0(lhs, v161, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            v138 = result;
            return result;
          }
          a2 = (unsigned __int8 *)v161;
        }
        else
        {
          if ( *(unsigned __int8 *)v161 >= 0x82u )
            a5[37] = 2;
          v138 = sub_5147C0(lhs, v161, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          if ( v138 == -996 && a5[44] == v161 )
            v138 = 0;
          if ( v138 )
            return v138;
          if ( *(_BYTE *)v161 == 123 )
          {
            v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
            if ( v138 )
              return v138;
            a5[44] = v161;
            return -996;
          }
          a2 += 3;
        }
        goto LABEL_1;
      case 118:
        if ( v139 )
        {
          j = a2[2] | (a2[1] << 8);
          while ( 1 )
          {
            v15 = j--;
            if ( v15 <= 0 )
              break;
            if ( (unsigned int)--lhs < a5[28] )
              return 0;
            while ( (*lhs & 0xC0) == 0x80 )
              --lhs;
          }
        }
        else
        {
          lhs -= a2[2] | (a2[1] << 8);
          if ( (unsigned int)lhs < a5[28] )
            return 0;
        }
        if ( (unsigned int)lhs < a5[32] )
          a5[32] = (unsigned int)lhs;
        a2 += 3;
        continue;
      case 119:
      case 121:
        if ( a5[37] == 1 )
        {
          v148 = 1;
          a5[37] = 0;
        }
        else
        {
          v148 = 0;
        }
        while ( 1 )
        {
          v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, 0, a7 + 1);
          if ( v138 == 1 || v138 == -999 )
            break;
          if ( v138 && v138 != -992 )
            return v138;
          a2 += a2[2] | (a2[1] << 8);
          if ( *a2 != 113 )
            goto LABEL_271;
        }
        a3 = (unsigned __int8 *)a5[30];
LABEL_271:
        if ( *a2 == 114 )
          return 0;
        if ( v148 )
          return 1;
        do
          a2 += a2[2] | (a2[1] << 8);
        while ( *a2 == 113 );
        a2 += 3;
        a4 = a5[34];
        continue;
      case 120:
      case 122:
        if ( a5[37] == 1 )
        {
          v148 = 1;
          a5[37] = 0;
        }
        else
        {
          v148 = 0;
        }
        while ( 1 )
        {
          v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, 0, a7 + 1);
          if ( v138 == 1 || v138 == -999 )
            return 0;
          if ( v138 == -994 || v138 == -995 || v138 == -998 )
            break;
          if ( v138 && v138 != -992 )
            return v138;
          a2 += a2[2] | (a2[1] << 8);
          if ( *a2 != 113 )
            goto LABEL_292;
        }
        do
          a2 += a2[2] | (a2[1] << 8);
        while ( *a2 == 113 );
LABEL_292:
        if ( v148 )
          return 1;
        a2 += 3;
        continue;
      case 123:
      case 125:
      case 130:
        goto LABEL_97;
      case 124:
        v161 = (int)a2;
        v149 = lhs;
        while ( 1 )
        {
          v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          if ( v138 == 1 )
            break;
          if ( v138 == -992 )
          {
            v152 = (int)&a2[a2[2] | (a2[1] << 8)];
            if ( a5[30] < v152 && (*a2 == 113 || *(_BYTE *)v152 == 113) )
              v138 = 0;
          }
          if ( v138 )
            return v138;
          a2 += a2[2] | (a2[1] << 8);
          if ( *a2 != 113 )
            goto LABEL_69;
        }
        a3 = (unsigned __int8 *)a5[30];
LABEL_69:
        if ( *a2 != 124 && *a2 != 113 )
          return 0;
        do
          a2 += a2[2] | (a2[1] << 8);
        while ( *a2 == 113 );
        a4 = a5[34];
        lhs = (unsigned __int8 *)a5[31];
        if ( *a2 == 114 || lhs == v149 )
        {
          a2 += 3;
          continue;
        }
        if ( *a2 == 116 )
        {
          v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          if ( v138 )
            return v138;
          a2 = (unsigned __int8 *)v161;
        }
        else
        {
          a5[37] = 2;
          v138 = sub_5147C0(lhs, v161, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          if ( v138 )
            return v138;
          a2 += 3;
        }
        goto LABEL_1;
      case 126:
      case 131:
        goto LABEL_140;
      case 127:
      case 132:
        v141 = a2[4] | (a2[3] << 8);
        v153 = 2 * v141;
        if ( 2 * v141 < (int)a5[5] )
        {
          v171 = *(_DWORD *)(a5[3] + 4 * v153);
          v164 = *(_DWORD *)(a5[3] + 4 * v153 + 4);
          v154 = *(_DWORD *)(a5[3] + 4 * (a5[4] - v141));
          v145 = a5[35];
          *(_DWORD *)(a5[3] + 4 * (a5[4] - v141)) = &lhs[-a5[28]];
          do
          {
            if ( v142 >= 130 )
              a5[37] = 2;
            v138 = sub_5147C0(
                     lhs,
                     (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]],
                     (int)a3,
                     a4,
                     (int)a5,
                     (int)a6,
                     a7 + 1);
            if ( v138 == -996 )
              break;
            if ( v138 == -992 )
            {
              v152 = (int)&a2[a2[2] | (a2[1] << 8)];
              if ( a5[30] < v152 && (*a2 == 113 || *(_BYTE *)v152 == 113) )
                v138 = 0;
            }
            if ( v138 )
              return v138;
            a5[35] = v145;
            a2 += a2[2] | (a2[1] << 8);
          }
          while ( *a2 == 113 );
          *(_DWORD *)(a5[3] + 4 * v153) = v171;
          *(_DWORD *)(a5[3] + 4 * v153 + 4) = v164;
          *(_DWORD *)(a5[3] + 4 * (a5[4] - v141)) = v154;
          return v138;
        }
LABEL_97:
        while ( 2 )
        {
          if ( v142 >= 130 || v142 == 123 )
          {
            a5[37] = 2;
LABEL_103:
            v138 = sub_5147C0(
                     lhs,
                     (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]],
                     (int)a3,
                     a4,
                     (int)a5,
                     (int)a6,
                     a7 + 1);
            if ( v138 == -992 )
            {
              v152 = (int)&a2[a2[2] | (a2[1] << 8)];
              if ( a5[30] < v152 && (*a2 == 113 || *(_BYTE *)v152 == 113) )
                v138 = 0;
            }
            if ( v138 )
            {
              if ( v138 == -996 )
              {
                v135 = a2;
                if ( *a2 != 123 )
                {
                  while ( *v135 == 113 )
                    v135 += v135[2] | (v135[1] << 8);
                  v135 -= v135[2] | (v135[1] << 8);
                }
                if ( (unsigned __int8 *)a5[44] == v135 )
                  return 0;
              }
              return v138;
            }
            a2 += a2[2] | (a2[1] << 8);
            if ( *a2 != 113 )
              return 0;
            continue;
          }
          break;
        }
        if ( a5[25] || a2[a2[2] | (a2[1] << 8)] == 113 )
          goto LABEL_103;
        a2 += (unsigned __int8)_pcre_OP_lengths[*a2];
        goto LABEL_1;
      case 128:
      case 133:
        v162 = 0;
        goto LABEL_120;
      case 129:
      case 134:
        v167 = a2[2] | (a2[1] << 8);
        if ( a2[3] != 112 )
          goto LABEL_165;
        if ( !pcre_callout )
          goto LABEL_164;
        v134[0] = 2;
        v134[1] = a2[4];
        v134[2] = a5[3];
        v134[3] = a5[28];
        v134[4] = a5[29] - a5[28];
        v134[5] = &a3[-a5[28]];
        v134[6] = &lhs[-a5[28]];
        v134[10] = a2[6] | (a2[5] << 8);
        v134[11] = a2[8] | (a2[7] << 8);
        v134[7] = a4 / 2;
        v134[8] = a5[35];
        v134[9] = a5[41];
        v134[12] = a5[43];
        v138 = pcre_callout(v134);
        if ( v138 > 0 )
          return 0;
        if ( v138 < 0 )
          return v138;
LABEL_164:
        a2 += 6;
LABEL_165:
        v151 = a2[3];
        switch ( v151 )
        {
          case 137:
          case 138:
            if ( a5[40] )
            {
              v133 = a2[5] | (a2[4] << 8);
              v97 = v133 == 0xFFFF || v133 == *(_DWORD *)(a5[40] + 4);
              v148 = v97;
              if ( !v97 && v151 == 138 )
              {
                v132 = (unsigned __int8 *)a5[10];
                for ( j = 0; j < (int)a5[8] && (v132[1] | (*v132 << 8)) != v133; ++j )
                  v132 += a5[9];
                if ( j < (int)a5[8] )
                {
                  v131 = v132;
                  do
                  {
                    if ( (unsigned int)v131 <= a5[10] )
                      break;
                    v131 -= a5[9];
                    strcmp(v132 + 2, v131 + 2);
                    if ( v11 )
                      break;
                    v148 = (v131[1] | (*v131 << 8)) == *(_DWORD *)(a5[40] + 4);
                  }
                  while ( !v148 );
                  if ( !v148 )
                  {
                    v131 = v132;
                    ++j;
                    while ( j < (int)a5[8] )
                    {
                      v131 += a5[9];
                      strcmp(v132 + 2, v131 + 2);
                      if ( v12 )
                        break;
                      v148 = (v131[1] | (*v131 << 8)) == *(_DWORD *)(a5[40] + 4);
                      if ( v148 )
                        break;
                      ++j;
                    }
                  }
                }
              }
              if ( v148 )
                v96 = 3;
              else
                v96 = a2[2] | (a2[1] << 8);
              k = &a2[v96];
            }
            else
            {
              v148 = 0;
              k = &a2[a2[2] | (a2[1] << 8)];
            }
            break;
          case 135:
          case 136:
            v153 = 2 * (a2[5] | (a2[4] << 8));
            v95 = v153 < a4 && *(int *)(a5[3] + 4 * v153) >= 0;
            v148 = v95;
            if ( !v95 && v151 == 136 )
            {
              v129 = v153 >> 1;
              v130 = (unsigned __int8 *)a5[10];
              for ( j = 0; j < (int)a5[8] && (v130[1] | (*v130 << 8)) != v129; ++j )
                v130 += a5[9];
              if ( j < (int)a5[8] )
              {
                v128 = v130;
                do
                {
                  if ( (unsigned int)v128 <= a5[10] )
                    break;
                  v128 -= a5[9];
                  strcmp(v130 + 2, v128 + 2);
                  if ( v13 )
                    break;
                  v153 = 2 * (v128[1] | (*v128 << 8));
                  v94 = v153 < a4 && *(int *)(a5[3] + 4 * v153) >= 0;
                  v148 = v94;
                }
                while ( !v94 );
                if ( !v148 )
                {
                  v128 = v130;
                  ++j;
                  while ( j < (int)a5[8] )
                  {
                    v128 += a5[9];
                    strcmp(v130 + 2, v128 + 2);
                    if ( v14 )
                      break;
                    v153 = 2 * (v128[1] | (*v128 << 8));
                    v93 = v153 < a4 && *(int *)(a5[3] + 4 * v153) >= 0;
                    v148 = v93;
                    if ( v93 )
                      break;
                    ++j;
                  }
                }
              }
            }
            if ( v148 )
              v92 = 3;
            else
              v92 = a2[2] | (a2[1] << 8);
            k = &a2[v92];
            break;
          case 139:
            v148 = 0;
            k = &a2[a2[2] | (a2[1] << 8)];
            break;
          default:
            a5[37] = 1;
            v138 = sub_5147C0(lhs, (int)(a2 + 3), (int)a3, a4, (int)a5, 0, a7 + 1);
            if ( v138 == 1 )
            {
              if ( (int)a5[34] > a4 )
                a4 = a5[34];
              v148 = 1;
              for ( k = &a2[(a2[5] | (a2[4] << 8)) + 3]; *k == 113; k += k[2] | (k[1] << 8) )
                ;
            }
            else
            {
              if ( v138 && v138 != -992 )
                return v138;
              v148 = 0;
              k = &a2[v167];
            }
            break;
        }
        if ( !v148 && *k != 113 )
        {
          a2 = k + 3;
          continue;
        }
        if ( v142 == 134 )
        {
          a5[37] = 2;
          result = sub_5147C0(lhs, (int)(k + 3), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
          v138 = result;
          return result;
        }
        a2 = k + 3;
        goto LABEL_1;
      case 140:
        v152 = (int)(a2 + 1);
        v138 = sub_5147C0(lhs, (int)(a2 + 1), (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( v138 )
          return v138;
        do
          v152 += *(unsigned __int8 *)(v152 + 2) | (*(unsigned __int8 *)(v152 + 1) << 8);
        while ( *(_BYTE *)v152 == 113 );
        a2 = (unsigned __int8 *)(v152 + 3);
        continue;
      case 141:
        v152 = (int)(a2 + 1);
        do
          v152 += *(unsigned __int8 *)(v152 + 2) | (*(unsigned __int8 *)(v152 + 1) << 8);
        while ( *(_BYTE *)v152 == 113 );
        v138 = sub_5147C0(lhs, v152 + 3, (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( v138 )
          return v138;
        ++a2;
        continue;
      case 142:
        v142 = *++a2;
        v162 = 1;
        if ( v142 != 128 && v142 != 133 )
          goto LABEL_141;
LABEL_120:
        v141 = a2[4] | (a2[3] << 8);
        v153 = 2 * v141;
        if ( 2 * v141 >= (int)a5[5] )
        {
LABEL_140:
          v162 = 0;
LABEL_141:
          v140 = 0;
          v167 = (int)&a2[-a5[27]];
          do
          {
            while ( 1 )
            {
              if ( v142 >= 130 )
                a5[37] = 2;
              v138 = sub_5147C0(
                       lhs,
                       (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]],
                       (int)a3,
                       a4,
                       (int)a5,
                       (int)a6,
                       a7 + 1);
              if ( v138 != -997 )
                break;
              a4 = a5[34];
              lhs = (unsigned __int8 *)a5[31];
              a2 = (unsigned __int8 *)(v167 + a5[27]);
              v140 = 1;
            }
            if ( v138 == -992 )
            {
              v152 = (int)&a2[a2[2] | (a2[1] << 8)];
              if ( a5[30] < v152 && (*a2 == 113 || *(_BYTE *)v152 == 113) )
                v138 = 0;
            }
            if ( v138 )
              return v138;
            a2 += a2[2] | (a2[1] << 8);
          }
          while ( *a2 == 113 );
          if ( !v140 && !v162 )
            return 0;
          a2 += 3;
        }
        else
        {
          v140 = 0;
          v167 = (int)&a2[-a5[27]];
          v171 = *(_DWORD *)(a5[3] + 4 * v153);
          v164 = *(_DWORD *)(a5[3] + 4 * v153 + 4);
          v154 = *(_DWORD *)(a5[3] + 4 * (a5[4] - v141));
          v145 = a5[35];
          do
          {
            while ( 1 )
            {
              *(_DWORD *)(a5[3] + 4 * (a5[4] - v141)) = &lhs[-a5[28]];
              if ( v142 >= 130 )
                a5[37] = 2;
              v138 = sub_5147C0(
                       lhs,
                       (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]],
                       (int)a3,
                       a4,
                       (int)a5,
                       (int)a6,
                       a7 + 1);
              if ( v138 != -997 )
                break;
              a4 = a5[34];
              lhs = (unsigned __int8 *)a5[31];
              a2 = (unsigned __int8 *)(v167 + a5[27]);
              v145 = a5[35];
              v140 = 1;
            }
            if ( v138 == -992 )
            {
              v152 = (int)&a2[a2[2] | (a2[1] << 8)];
              if ( a5[30] < v152 && (*a2 == 113 || *(_BYTE *)v152 == 113) )
                v138 = 0;
            }
            if ( v138 )
              return v138;
            a5[35] = v145;
            a2 += a2[2] | (a2[1] << 8);
          }
          while ( *a2 == 113 );
          if ( !v140 )
          {
            *(_DWORD *)(a5[3] + 4 * v153) = v171;
            *(_DWORD *)(a5[3] + 4 * v153 + 4) = v164;
            *(_DWORD *)(a5[3] + 4 * (a5[4] - v141)) = v154;
          }
          if ( !v162 && !v140 )
            return 0;
          a2 += 3;
        }
        continue;
      case 143:
        a5[43] = (unsigned int)(a2 + 2);
        a5[42] = 0;
        v138 = sub_5147C0(
                 lhs,
                 (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2] + a2[1]],
                 (int)a3,
                 a4,
                 (int)a5,
                 (int)a6,
                 a7 + 1);
        if ( (v138 == 1 || v138 == -999) && !a5[42] )
        {
          a5[42] = (unsigned int)(a2 + 2);
        }
        else if ( v138 == -993 )
        {
          strcmp(a2 + 2, (unsigned __int8 *)a5[30]);
          if ( !v10 )
          {
            a5[30] = (unsigned int)lhs;
            return -994;
          }
        }
        return v138;
      case 144:
        v138 = sub_5147C0(lhs, (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]], (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( !v138 || v138 == -992 )
          return -995;
        else
          return v138;
      case 145:
        a5[43] = (unsigned int)(a2 + 2);
        a5[42] = 0;
        v138 = sub_5147C0(
                 lhs,
                 (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2] + a2[1]],
                 (int)a3,
                 a4,
                 (int)a5,
                 (int)a6,
                 a7 + 1);
        if ( (v138 == 1 || v138 == -999) && !a5[42] )
          a5[42] = (unsigned int)(a2 + 2);
        if ( !v138 || v138 == -992 )
          return -995;
        else
          return v138;
      case 146:
        v138 = sub_5147C0(lhs, (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]], (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( v138 && v138 != -995 && v138 != -992 )
          return v138;
        a5[30] = (unsigned int)lhs;
        return -994;
      case 147:
        if ( !a5[26] )
        {
          v138 = sub_5147C0(
                   lhs,
                   (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2] + a2[1]],
                   (int)a3,
                   a4,
                   (int)a5,
                   (int)a6,
                   a7 + 1);
          if ( v138 && v138 != -995 && v138 != -992 )
            return v138;
          a5[30] = (unsigned int)(a2 + 2);
          return -993;
        }
        a2 += (unsigned __int8)_pcre_OP_lengths[*a2] + a2[1];
        continue;
      case 148:
        v138 = sub_5147C0(lhs, (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]], (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( v138 )
          return v138;
        a5[30] = (unsigned int)a2;
        return -992;
      case 149:
        a5[43] = (unsigned int)(a2 + 2);
        a5[42] = 0;
        v138 = sub_5147C0(
                 lhs,
                 (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2] + a2[1]],
                 (int)a3,
                 a4,
                 (int)a5,
                 (int)a6,
                 a7 + 1);
        if ( (v138 == 1 || v138 == -999) && !a5[42] )
          a5[42] = (unsigned int)(a2 + 2);
        if ( v138 )
          return v138;
        a5[30] = (unsigned int)a2;
        return -992;
      case 150:
        v138 = sub_5147C0(lhs, (int)&a2[(unsigned __int8)_pcre_OP_lengths[*a2]], (int)a3, a4, (int)a5, (int)a6, a7 + 1);
        if ( !v138 || v138 == -995 || v138 == -994 || v138 == -993 || v138 == -992 )
          return -998;
        else
          return v138;
      case 151:
        return 0;
      case 154:
        v141 = a2[2] | (a2[1] << 8);
        v153 = 2 * v141;
        a5[35] = v141;
        if ( v153 < (int)a5[5] )
        {
          *(_DWORD *)(a5[3] + 4 * v153) = *(_DWORD *)(a5[3] + 4 * (a5[4] - v141));
          *(_DWORD *)(a5[3] + 4 * v153 + 4) = &lhs[-a5[28]];
          if ( a4 <= v153 )
            a4 = v153 + 2;
        }
        else
        {
          a5[14] = 1;
        }
        a2 += 3;
        continue;
      case 155:
        v152 = (int)(a2 + 1);
        do
          v152 += *(unsigned __int8 *)(v152 + 2) | (*(unsigned __int8 *)(v152 + 1) << 8);
        while ( *(_BYTE *)v152 == 113 );
        a2 = (unsigned __int8 *)(v152 + 3);
        continue;
      default:
        return -5;
    }
  }
}
