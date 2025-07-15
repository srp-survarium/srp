int __cdecl memcmp(unsigned __int8 *lhs, unsigned __int8 *rhs, unsigned int siz)
{
  unsigned int v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 *v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  int v24; // esi
  int v25; // esi
  int v26; // esi
  int v27; // esi
  int v28; // esi
  int v29; // esi
  int v30; // esi
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // ecx
  int result; // eax
  int v34; // edx
  int v35; // esi
  int v36; // esi
  int v37; // esi
  int v38; // edx
  int v39; // esi
  int v40; // esi
  int v41; // esi
  int v42; // edx
  int v43; // esi
  int v44; // esi
  int v45; // esi
  int v46; // edx
  int v47; // esi
  int v48; // esi
  int v49; // esi
  int v50; // esi
  int v51; // esi
  int v52; // esi
  int v53; // edx
  int v54; // esi
  int v55; // esi
  int v56; // esi
  int v57; // edx
  int v58; // esi
  int v59; // edx
  int v60; // esi
  int v61; // esi
  int v62; // edx
  int v63; // esi
  int v64; // esi
  int v65; // esi
  int v66; // edx
  int v67; // esi
  int v68; // esi
  int v69; // esi
  int v70; // edx
  int v71; // esi
  int v72; // esi
  int v73; // esi
  int v74; // edx
  int v75; // esi
  int v76; // esi
  int v77; // esi
  int v78; // edx
  int v79; // esi
  int v80; // esi
  int v81; // esi
  int v82; // esi
  int v83; // esi
  int v84; // esi
  int v85; // edx
  int v86; // esi
  int v87; // esi
  int v88; // esi
  int v89; // edx
  int v90; // esi
  int v91; // esi
  int v92; // esi
  int v93; // edx
  int v94; // esi
  int v95; // esi
  int v96; // esi
  int v97; // edx
  int v98; // esi
  int v99; // esi
  int v100; // esi
  int v101; // edx
  int v102; // esi
  int v103; // esi
  int v104; // esi
  int v105; // edx
  int v106; // esi
  int v107; // esi
  int v108; // esi
  int v109; // esi
  int v110; // esi
  int v111; // esi
  int v112; // edx
  int v113; // esi
  int v114; // esi
  int v115; // esi
  int v116; // esi
  int v117; // edx
  int v118; // esi
  int v119; // esi
  int v120; // esi
  int v121; // edx
  int v122; // esi
  int v123; // esi
  int v124; // esi
  int v125; // edx
  int v126; // esi
  int v127; // esi
  int v128; // esi
  int v129; // edx
  int v130; // esi
  int v131; // esi
  int v132; // esi
  int v133; // esi
  int v134; // esi
  int v135; // esi
  int v136; // edx
  int v137; // esi
  int v138; // esi
  int v139; // esi
  int v140; // edx
  int v141; // esi
  int v142; // esi
  int v143; // esi
  int v144; // esi
  int v145; // eax
  int v146; // eax
  int v147; // eax
  int v148; // eax
  int v149; // ecx
  int v150; // eax
  int v151; // eax
  int v152; // eax

  v3 = siz;
  switch ( siz )
  {
    case 0u:
      return 0;
    case 1u:
      v148 = *lhs;
      v149 = *rhs;
LABEL_426:
      result = v148 - v149;
      if ( result )
        return 2 * (result > 0) - 1;
      return result;
    case 2u:
      v152 = *lhs - *rhs;
      if ( v152 )
      {
        result = 2 * (v152 > 0) - 1;
        if ( result )
          return result;
      }
      v148 = lhs[1];
      v149 = rhs[1];
      goto LABEL_426;
    case 3u:
      v150 = *lhs - *rhs;
      if ( v150 )
      {
        result = 2 * (v150 > 0) - 1;
        if ( result )
          return result;
      }
      v151 = lhs[1] - rhs[1];
      if ( v151 )
      {
        result = 2 * (v151 > 0) - 1;
        if ( result )
          return result;
      }
      v148 = lhs[2];
      v149 = rhs[2];
      goto LABEL_426;
    case 4u:
      v145 = *lhs - *rhs;
      if ( v145 )
      {
        result = 2 * (v145 > 0) - 1;
        if ( result )
          return result;
      }
      v146 = lhs[1] - rhs[1];
      if ( v146 )
      {
        result = 2 * (v146 > 0) - 1;
        if ( result )
          return result;
      }
      v147 = lhs[2] - rhs[2];
      if ( v147 )
      {
        result = 2 * (v147 > 0) - 1;
        if ( result )
          return result;
      }
      v148 = lhs[3];
      v149 = rhs[3];
      goto LABEL_426;
  }
  v4 = rhs;
  v5 = lhs;
  while ( v3 >= 0x20 )
  {
    if ( *(_DWORD *)v5 == *(_DWORD *)v4 )
    {
      v7 = 0;
    }
    else
    {
      v6 = *v5 - *v4;
      if ( v6 )
      {
        v7 = 2 * (v6 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v8 = v5[1] - v4[1];
      if ( v8 )
      {
        v7 = 2 * (v8 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v9 = v5[2] - v4[2];
      if ( v9 )
      {
        v7 = 2 * (v9 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[3] - v4[3];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 1) == *((_DWORD *)v4 + 1) )
    {
      v7 = 0;
    }
    else
    {
      v10 = v5[4] - v4[4];
      if ( v10 )
      {
        v7 = 2 * (v10 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v11 = v5[5] - v4[5];
      if ( v11 )
      {
        v7 = 2 * (v11 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v12 = v5[6] - v4[6];
      if ( v12 )
      {
        v7 = 2 * (v12 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[7] - v4[7];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 2) == *((_DWORD *)v4 + 2) )
    {
      v7 = 0;
    }
    else
    {
      v13 = v5[8] - v4[8];
      if ( v13 )
      {
        v7 = 2 * (v13 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v14 = v5[9] - v4[9];
      if ( v14 )
      {
        v7 = 2 * (v14 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v15 = v5[10] - v4[10];
      if ( v15 )
      {
        v7 = 2 * (v15 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[11] - v4[11];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 3) == *((_DWORD *)v4 + 3) )
    {
      v7 = 0;
    }
    else
    {
      v16 = v5[12] - v4[12];
      if ( v16 )
      {
        v7 = 2 * (v16 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v17 = v5[13] - v4[13];
      if ( v17 )
      {
        v7 = 2 * (v17 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v18 = v5[14] - v4[14];
      if ( v18 )
      {
        v7 = 2 * (v18 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[15] - v4[15];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 4) == *((_DWORD *)v4 + 4) )
    {
      v7 = 0;
    }
    else
    {
      v19 = v5[16] - v4[16];
      if ( v19 )
      {
        v7 = 2 * (v19 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v20 = v5[17] - v4[17];
      if ( v20 )
      {
        v7 = 2 * (v20 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v21 = v5[18] - v4[18];
      if ( v21 )
      {
        v7 = 2 * (v21 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[19] - v4[19];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 5) == *((_DWORD *)v4 + 5) )
    {
      v7 = 0;
    }
    else
    {
      v22 = v5[20] - v4[20];
      if ( v22 )
      {
        v7 = 2 * (v22 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v23 = v5[21] - v4[21];
      if ( v23 )
      {
        v7 = 2 * (v23 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v24 = v5[22] - v4[22];
      if ( v24 )
      {
        v7 = 2 * (v24 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[23] - v4[23];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 6) == *((_DWORD *)v4 + 6) )
    {
      v7 = 0;
    }
    else
    {
      v25 = v5[24] - v4[24];
      if ( v25 )
      {
        v7 = 2 * (v25 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v26 = v5[25] - v4[25];
      if ( v26 )
      {
        v7 = 2 * (v26 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v27 = v5[26] - v4[26];
      if ( v27 )
      {
        v7 = 2 * (v27 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[27] - v4[27];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    if ( *((_DWORD *)v5 + 7) == *((_DWORD *)v4 + 7) )
    {
      v7 = 0;
    }
    else
    {
      v28 = v5[28] - v4[28];
      if ( v28 )
      {
        v7 = 2 * (v28 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v29 = v5[29] - v4[29];
      if ( v29 )
      {
        v7 = 2 * (v29 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v30 = v5[30] - v4[30];
      if ( v30 )
      {
        v7 = 2 * (v30 > 0) - 1;
        if ( v7 )
          return v7;
      }
      v7 = v5[31] - v4[31];
      if ( v7 )
        v7 = 2 * (v7 > 0) - 1;
    }
    if ( v7 )
      return v7;
    v5 += 32;
    v4 += 32;
    v3 -= 32;
  }
  v31 = &v5[v3];
  v32 = &v4[v3];
  switch ( v3 )
  {
    case 1u:
      goto $LN103;
    case 2u:
      goto $LN88_2;
    case 3u:
      goto $LN73_1;
    case 4u:
      goto $LN120_1;
    case 5u:
      goto $LN105;
    case 6u:
      goto $LN90_2;
    case 7u:
      goto $LN75_1;
    case 8u:
      goto $LN122_1;
    case 9u:
      goto $LN107;
    case 0xAu:
      goto $LN92;
    case 0xBu:
      goto $LN77_0;
    case 0xCu:
      goto $LN124_0;
    case 0xDu:
      goto $LN109_0;
    case 0xEu:
      goto $LN94_0;
    case 0xFu:
      goto $LN79;
    case 0x10u:
      goto $LN126;
    case 0x11u:
      goto $LN111_1;
    case 0x12u:
      goto $LN96_1;
    case 0x13u:
      goto $LN81;
    case 0x14u:
      goto $LN128_1;
    case 0x15u:
      goto $LN113_1;
    case 0x16u:
      goto $LN98_1;
    case 0x17u:
      goto $LN83_0;
    case 0x18u:
      goto $LN130_4;
    case 0x19u:
      goto $LN115;
    case 0x1Au:
      goto $LN100_5;
    case 0x1Bu:
      goto $LN85_0;
    case 0x1Cu:
      v34 = *((_DWORD *)v31 - 7);
      if ( v34 == *((_DWORD *)v32 - 7) )
      {
        v7 = 0;
      }
      else
      {
        v35 = (unsigned __int8)v34 - *(v32 - 28);
        if ( v35 )
        {
          v7 = 2 * (v35 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v36 = *(v31 - 27) - *(v32 - 27);
        if ( v36 )
        {
          v7 = 2 * (v36 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v37 = *(v31 - 26) - *(v32 - 26);
        if ( v37 )
        {
          v7 = 2 * (v37 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 25) - *(v32 - 25);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN130_4:
      v38 = *((_DWORD *)v31 - 6);
      if ( v38 == *((_DWORD *)v32 - 6) )
      {
        v7 = 0;
      }
      else
      {
        v39 = (unsigned __int8)v38 - *(v32 - 24);
        if ( v39 )
        {
          v7 = 2 * (v39 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v40 = *(v31 - 23) - *(v32 - 23);
        if ( v40 )
        {
          v7 = 2 * (v40 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v41 = *(v31 - 22) - *(v32 - 22);
        if ( v41 )
        {
          v7 = 2 * (v41 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 21) - *(v32 - 21);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN128_1:
      v42 = *((_DWORD *)v31 - 5);
      if ( v42 == *((_DWORD *)v32 - 5) )
      {
        v7 = 0;
      }
      else
      {
        v43 = (unsigned __int8)v42 - *(v32 - 20);
        if ( v43 )
        {
          v7 = 2 * (v43 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v44 = *(v31 - 19) - *(v32 - 19);
        if ( v44 )
        {
          v7 = 2 * (v44 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v45 = *(v31 - 18) - *(v32 - 18);
        if ( v45 )
        {
          v7 = 2 * (v45 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 17) - *(v32 - 17);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN126:
      v46 = *((_DWORD *)v31 - 4);
      if ( v46 == *((_DWORD *)v32 - 4) )
      {
        v7 = 0;
      }
      else
      {
        v47 = (unsigned __int8)v46 - *(v32 - 16);
        if ( v47 )
        {
          v7 = 2 * (v47 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v48 = *(v31 - 15) - *(v32 - 15);
        if ( v48 )
        {
          v7 = 2 * (v48 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v49 = *(v31 - 14) - *(v32 - 14);
        if ( v49 )
        {
          v7 = 2 * (v49 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 13) - *(v32 - 13);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN124_0:
      if ( *((_DWORD *)v31 - 3) == *((_DWORD *)v32 - 3) )
      {
        v7 = 0;
      }
      else
      {
        v50 = *(v31 - 12) - *(v32 - 12);
        if ( v50 )
        {
          v7 = 2 * (v50 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v51 = *(v31 - 11) - *(v32 - 11);
        if ( v51 )
        {
          v7 = 2 * (v51 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v52 = *(v31 - 10) - *(v32 - 10);
        if ( v52 )
        {
          v7 = 2 * (v52 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 9) - *(v32 - 9);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN122_1:
      v53 = *((_DWORD *)v31 - 2);
      if ( v53 == *((_DWORD *)v32 - 2) )
      {
        v7 = 0;
      }
      else
      {
        v54 = (unsigned __int8)v53 - *(v32 - 8);
        if ( v54 )
        {
          v7 = 2 * (v54 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v55 = *(v31 - 7) - *(v32 - 7);
        if ( v55 )
        {
          v7 = 2 * (v55 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v56 = *(v31 - 6) - *(v32 - 6);
        if ( v56 )
        {
          v7 = 2 * (v56 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 5) - *(v32 - 5);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN120_1:
      v57 = *((_DWORD *)v31 - 1);
      if ( v57 == *((_DWORD *)v32 - 1) )
      {
        result = 0;
      }
      else
      {
        v58 = (unsigned __int8)v57 - *(v32 - 4);
        if ( (!v58 || (v59 = 2 * (v58 > 0) - 1, 2 * (v58 > 0) == 1))
          && ((v60 = *(v31 - 3) - *(v32 - 3)) == 0 || (v59 = 2 * (v60 > 0) - 1, 2 * (v60 > 0) == 1))
          && ((v61 = *(v31 - 2) - *(v32 - 2)) == 0 || (v59 = 2 * (v61 > 0) - 1, 2 * (v61 > 0) == 1)) )
        {
          result = *(v31 - 1) - *(v32 - 1);
          if ( result )
            result = 2 * (result > 0) - 1;
        }
        else
        {
          result = v59;
        }
      }
      if ( !result )
        return 0;
      return result;
    case 0x1Du:
      v62 = *(_DWORD *)(v31 - 29);
      if ( v62 == *(_DWORD *)(v32 - 29) )
      {
        v7 = 0;
      }
      else
      {
        v63 = (unsigned __int8)v62 - *(v32 - 29);
        if ( v63 )
        {
          v7 = 2 * (v63 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v64 = *(v31 - 28) - *(v32 - 28);
        if ( v64 )
        {
          v7 = 2 * (v64 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v65 = *(v31 - 27) - *(v32 - 27);
        if ( v65 )
        {
          v7 = 2 * (v65 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 26) - *(v32 - 26);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN115:
      v66 = *(_DWORD *)(v31 - 25);
      if ( v66 == *(_DWORD *)(v32 - 25) )
      {
        v7 = 0;
      }
      else
      {
        v67 = (unsigned __int8)v66 - *(v32 - 25);
        if ( v67 )
        {
          v7 = 2 * (v67 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v68 = *(v31 - 24) - *(v32 - 24);
        if ( v68 )
        {
          v7 = 2 * (v68 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v69 = *(v31 - 23) - *(v32 - 23);
        if ( v69 )
        {
          v7 = 2 * (v69 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 22) - *(v32 - 22);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN113_1:
      v70 = *(_DWORD *)(v31 - 21);
      if ( v70 == *(_DWORD *)(v32 - 21) )
      {
        v7 = 0;
      }
      else
      {
        v71 = (unsigned __int8)v70 - *(v32 - 21);
        if ( v71 )
        {
          v7 = 2 * (v71 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v72 = *(v31 - 20) - *(v32 - 20);
        if ( v72 )
        {
          v7 = 2 * (v72 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v73 = *(v31 - 19) - *(v32 - 19);
        if ( v73 )
        {
          v7 = 2 * (v73 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 18) - *(v32 - 18);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN111_1:
      v74 = *(_DWORD *)(v31 - 17);
      if ( v74 == *(_DWORD *)(v32 - 17) )
      {
        v7 = 0;
      }
      else
      {
        v75 = (unsigned __int8)v74 - *(v32 - 17);
        if ( v75 )
        {
          v7 = 2 * (v75 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v76 = *(v31 - 16) - *(v32 - 16);
        if ( v76 )
        {
          v7 = 2 * (v76 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v77 = *(v31 - 15) - *(v32 - 15);
        if ( v77 )
        {
          v7 = 2 * (v77 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 14) - *(v32 - 14);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN109_0:
      v78 = *(_DWORD *)(v31 - 13);
      if ( v78 == *(_DWORD *)(v32 - 13) )
      {
        v7 = 0;
      }
      else
      {
        v79 = (unsigned __int8)v78 - *(v32 - 13);
        if ( v79 )
        {
          v7 = 2 * (v79 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v80 = *(v31 - 12) - *(v32 - 12);
        if ( v80 )
        {
          v7 = 2 * (v80 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v81 = *(v31 - 11) - *(v32 - 11);
        if ( v81 )
        {
          v7 = 2 * (v81 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 10) - *(v32 - 10);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN107:
      if ( *(_DWORD *)(v31 - 9) == *(_DWORD *)(v32 - 9) )
      {
        v7 = 0;
      }
      else
      {
        v82 = *(v31 - 9) - *(v32 - 9);
        if ( v82 )
        {
          v7 = 2 * (v82 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v83 = *(v31 - 8) - *(v32 - 8);
        if ( v83 )
        {
          v7 = 2 * (v83 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v84 = *(v31 - 7) - *(v32 - 7);
        if ( v84 )
        {
          v7 = 2 * (v84 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 6) - *(v32 - 6);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN105:
      v85 = *(_DWORD *)(v31 - 5);
      if ( v85 == *(_DWORD *)(v32 - 5) )
      {
        v7 = 0;
      }
      else
      {
        v86 = (unsigned __int8)v85 - *(v32 - 5);
        if ( v86 )
        {
          v7 = 2 * (v86 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v87 = *(v31 - 4) - *(v32 - 4);
        if ( v87 )
        {
          v7 = 2 * (v87 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v88 = *(v31 - 3) - *(v32 - 3);
        if ( v88 )
        {
          v7 = 2 * (v88 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 2) - *(v32 - 2);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
      goto $LN103;
    case 0x1Eu:
      v89 = *(_DWORD *)(v31 - 30);
      if ( v89 == *(_DWORD *)(v32 - 30) )
      {
        v7 = 0;
      }
      else
      {
        v90 = (unsigned __int8)v89 - *(v32 - 30);
        if ( v90 )
        {
          v7 = 2 * (v90 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v91 = *(v31 - 29) - *(v32 - 29);
        if ( v91 )
        {
          v7 = 2 * (v91 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v92 = *(v31 - 28) - *(v32 - 28);
        if ( v92 )
        {
          v7 = 2 * (v92 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 27) - *(v32 - 27);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN100_5:
      v93 = *(_DWORD *)(v31 - 26);
      if ( v93 == *(_DWORD *)(v32 - 26) )
      {
        v7 = 0;
      }
      else
      {
        v94 = (unsigned __int8)v93 - *(v32 - 26);
        if ( v94 )
        {
          v7 = 2 * (v94 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v95 = *(v31 - 25) - *(v32 - 25);
        if ( v95 )
        {
          v7 = 2 * (v95 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v96 = *(v31 - 24) - *(v32 - 24);
        if ( v96 )
        {
          v7 = 2 * (v96 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 23) - *(v32 - 23);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN98_1:
      v97 = *(_DWORD *)(v31 - 22);
      if ( v97 == *(_DWORD *)(v32 - 22) )
      {
        v7 = 0;
      }
      else
      {
        v98 = (unsigned __int8)v97 - *(v32 - 22);
        if ( v98 )
        {
          v7 = 2 * (v98 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v99 = *(v31 - 21) - *(v32 - 21);
        if ( v99 )
        {
          v7 = 2 * (v99 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v100 = *(v31 - 20) - *(v32 - 20);
        if ( v100 )
        {
          v7 = 2 * (v100 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 19) - *(v32 - 19);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN96_1:
      v101 = *(_DWORD *)(v31 - 18);
      if ( v101 == *(_DWORD *)(v32 - 18) )
      {
        v7 = 0;
      }
      else
      {
        v102 = (unsigned __int8)v101 - *(v32 - 18);
        if ( v102 )
        {
          v7 = 2 * (v102 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v103 = *(v31 - 17) - *(v32 - 17);
        if ( v103 )
        {
          v7 = 2 * (v103 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v104 = *(v31 - 16) - *(v32 - 16);
        if ( v104 )
        {
          v7 = 2 * (v104 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 15) - *(v32 - 15);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN94_0:
      v105 = *(_DWORD *)(v31 - 14);
      if ( v105 == *(_DWORD *)(v32 - 14) )
      {
        v7 = 0;
      }
      else
      {
        v106 = (unsigned __int8)v105 - *(v32 - 14);
        if ( v106 )
        {
          v7 = 2 * (v106 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v107 = *(v31 - 13) - *(v32 - 13);
        if ( v107 )
        {
          v7 = 2 * (v107 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v108 = *(v31 - 12) - *(v32 - 12);
        if ( v108 )
        {
          v7 = 2 * (v108 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 11) - *(v32 - 11);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN92:
      if ( *(_DWORD *)(v31 - 10) == *(_DWORD *)(v32 - 10) )
      {
        v7 = 0;
      }
      else
      {
        v109 = *(v31 - 10) - *(v32 - 10);
        if ( v109 )
        {
          v7 = 2 * (v109 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v110 = *(v31 - 9) - *(v32 - 9);
        if ( v110 )
        {
          v7 = 2 * (v110 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v111 = *(v31 - 8) - *(v32 - 8);
        if ( v111 )
        {
          v7 = 2 * (v111 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 7) - *(v32 - 7);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN90_2:
      v112 = *(_DWORD *)(v31 - 6);
      if ( v112 == *(_DWORD *)(v32 - 6) )
      {
        v7 = 0;
      }
      else
      {
        v113 = (unsigned __int8)v112 - *(v32 - 6);
        if ( v113 )
        {
          v7 = 2 * (v113 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v114 = *(v31 - 5) - *(v32 - 5);
        if ( v114 )
        {
          v7 = 2 * (v114 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v115 = *(v31 - 4) - *(v32 - 4);
        if ( v115 )
        {
          v7 = 2 * (v115 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 3) - *(v32 - 3);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN88_2:
      if ( *((_WORD *)v31 - 1) == *((_WORD *)v32 - 1) )
        return 0;
      goto LABEL_336;
    case 0x1Fu:
      if ( *(_DWORD *)(v31 - 31) == *(_DWORD *)(v32 - 31) )
      {
        v7 = 0;
      }
      else
      {
        v118 = *(v31 - 31) - *(v32 - 31);
        if ( v118 )
        {
          v7 = 2 * (v118 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v119 = *(v31 - 30) - *(v32 - 30);
        if ( v119 )
        {
          v7 = 2 * (v119 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v120 = *(v31 - 29) - *(v32 - 29);
        if ( v120 )
        {
          v7 = 2 * (v120 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 28) - *(v32 - 28);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN85_0:
      v121 = *(_DWORD *)(v31 - 27);
      if ( v121 == *(_DWORD *)(v32 - 27) )
      {
        v7 = 0;
      }
      else
      {
        v122 = (unsigned __int8)v121 - *(v32 - 27);
        if ( v122 )
        {
          v7 = 2 * (v122 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v123 = *(v31 - 26) - *(v32 - 26);
        if ( v123 )
        {
          v7 = 2 * (v123 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v124 = *(v31 - 25) - *(v32 - 25);
        if ( v124 )
        {
          v7 = 2 * (v124 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 24) - *(v32 - 24);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN83_0:
      v125 = *(_DWORD *)(v31 - 23);
      if ( v125 == *(_DWORD *)(v32 - 23) )
      {
        v7 = 0;
      }
      else
      {
        v126 = (unsigned __int8)v125 - *(v32 - 23);
        if ( v126 )
        {
          v7 = 2 * (v126 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v127 = *(v31 - 22) - *(v32 - 22);
        if ( v127 )
        {
          v7 = 2 * (v127 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v128 = *(v31 - 21) - *(v32 - 21);
        if ( v128 )
        {
          v7 = 2 * (v128 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 20) - *(v32 - 20);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN81:
      v129 = *(_DWORD *)(v31 - 19);
      if ( v129 == *(_DWORD *)(v32 - 19) )
      {
        v7 = 0;
      }
      else
      {
        v130 = (unsigned __int8)v129 - *(v32 - 19);
        if ( v130 )
        {
          v7 = 2 * (v130 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v131 = *(v31 - 18) - *(v32 - 18);
        if ( v131 )
        {
          v7 = 2 * (v131 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v132 = *(v31 - 17) - *(v32 - 17);
        if ( v132 )
        {
          v7 = 2 * (v132 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 16) - *(v32 - 16);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN79:
      if ( *(_DWORD *)(v31 - 15) == *(_DWORD *)(v32 - 15) )
      {
        v7 = 0;
      }
      else
      {
        v133 = *(v31 - 15) - *(v32 - 15);
        if ( v133 )
        {
          v7 = 2 * (v133 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v134 = *(v31 - 14) - *(v32 - 14);
        if ( v134 )
        {
          v7 = 2 * (v134 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v135 = *(v31 - 13) - *(v32 - 13);
        if ( v135 )
        {
          v7 = 2 * (v135 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 12) - *(v32 - 12);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN77_0:
      v136 = *(_DWORD *)(v31 - 11);
      if ( v136 == *(_DWORD *)(v32 - 11) )
      {
        v7 = 0;
      }
      else
      {
        v137 = (unsigned __int8)v136 - *(v32 - 11);
        if ( v137 )
        {
          v7 = 2 * (v137 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v138 = *(v31 - 10) - *(v32 - 10);
        if ( v138 )
        {
          v7 = 2 * (v138 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v139 = *(v31 - 9) - *(v32 - 9);
        if ( v139 )
        {
          v7 = 2 * (v139 > 0) - 1;
          if ( v7 )
            return v7;
        }
        v7 = *(v31 - 8) - *(v32 - 8);
        if ( v7 )
          v7 = 2 * (v7 > 0) - 1;
      }
      if ( v7 )
        return v7;
$LN75_1:
      v140 = *(_DWORD *)(v31 - 7);
      if ( v140 != *(_DWORD *)(v32 - 7) )
      {
        v141 = (unsigned __int8)v140 - *(v32 - 7);
        if ( !v141 || (v7 = 2 * (v141 > 0) - 1) == 0 )
        {
          v142 = *(v31 - 6) - *(v32 - 6);
          if ( !v142 || (v7 = 2 * (v142 > 0) - 1) == 0 )
          {
            v143 = *(v31 - 5) - *(v32 - 5);
            if ( !v143 || (v7 = 2 * (v143 > 0) - 1) == 0 )
            {
              v7 = *(v31 - 4) - *(v32 - 4);
              if ( v7 )
                v7 = 2 * (v7 > 0) - 1;
              goto LABEL_415;
            }
          }
        }
        return v7;
      }
      v7 = 0;
LABEL_415:
      if ( v7 )
        return v7;
$LN73_1:
      v144 = *(v31 - 3) - *(v32 - 3);
      if ( v144 )
      {
        v117 = 2 * (v144 > 0) - 1;
        if ( 2 * (v144 > 0) != 1 )
          return v117;
      }
LABEL_336:
      v116 = *(v31 - 2) - *(v32 - 2);
      if ( v116 )
      {
        v117 = 2 * (v116 > 0) - 1;
        if ( 2 * (v116 > 0) != 1 )
          return v117;
      }
$LN103:
      result = *(v31 - 1) - *(v32 - 1);
      if ( result )
        return 2 * (result > 0) - 1;
      return result;
    default:
      return 0;
  }
}
