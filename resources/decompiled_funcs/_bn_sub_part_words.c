unsigned int __cdecl bn_sub_part_words(_DWORD *a1, _DWORD *a2, unsigned int *a3, int a4, int a5)
{
  unsigned int result; // eax
  unsigned int v9; // ebp
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  bool v14; // cf
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // edx
  unsigned int v39; // ecx
  unsigned int v40; // ecx
  unsigned int v41; // ecx
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  unsigned int i; // ebp
  int v48; // ecx
  int v49; // eax
  unsigned int v50; // edx
  int v51; // ecx
  int v52; // eax
  unsigned int v53; // edx
  int v54; // ecx
  int v55; // eax
  unsigned int v56; // edx
  int v57; // ecx
  int v58; // eax
  unsigned int v59; // edx
  int v60; // ecx
  int v61; // eax
  unsigned int v62; // edx
  int v63; // ecx
  int v64; // eax
  unsigned int v65; // edx
  int v66; // ecx
  int v67; // eax
  unsigned int v68; // edx
  unsigned int v69; // ecx
  int v70; // ecx
  unsigned int v71; // edx
  int v72; // ecx
  unsigned int v73; // edx
  int v74; // ecx
  unsigned int v75; // edx
  int v76; // ecx
  unsigned int v77; // edx
  int v78; // ecx
  unsigned int v79; // edx
  int v80; // ecx
  unsigned int v81; // edx
  int v82; // ecx
  int v83; // ebp
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // ecx
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  int v91; // ebp
  int v92; // ebp
  unsigned int v93; // ecx
  int v94; // ebp
  unsigned int v95; // ecx
  int v96; // ebp
  unsigned int v97; // ecx
  int v98; // ebp
  unsigned int v99; // ecx
  int v100; // ebp
  unsigned int v101; // ecx
  unsigned int v102; // ecx

  result = 0;
  v9 = a4 & 0xFFFFFFF8;
  if ( (a4 & 0xFFFFFFF8) != 0 )
  {
    do
    {
      v10 = *a2 - result;
      v11 = (v10 < *a3) + (*a2 < result);
      *a1 = v10 - *a3;
      v12 = a2[1];
      v13 = a3[1];
      v14 = v12 < v11;
      v15 = v12 - v11;
      v16 = (v15 < v13) + v14;
      a1[1] = v15 - v13;
      v17 = a2[2];
      v18 = a3[2];
      v14 = v17 < v16;
      v19 = v17 - v16;
      v20 = (v19 < v18) + v14;
      a1[2] = v19 - v18;
      v21 = a2[3];
      v22 = a3[3];
      v14 = v21 < v20;
      v23 = v21 - v20;
      v24 = (v23 < v22) + v14;
      a1[3] = v23 - v22;
      v25 = a2[4];
      v26 = a3[4];
      v14 = v25 < v24;
      v27 = v25 - v24;
      v28 = (v27 < v26) + v14;
      a1[4] = v27 - v26;
      v29 = a2[5];
      v30 = a3[5];
      v14 = v29 < v28;
      v31 = v29 - v28;
      v32 = (v31 < v30) + v14;
      a1[5] = v31 - v30;
      v33 = a2[6];
      v34 = a3[6];
      v14 = v33 < v32;
      v35 = v33 - v32;
      v36 = (v35 < v34) + v14;
      a1[6] = v35 - v34;
      v37 = a2[7];
      v38 = a3[7];
      v14 = v37 < v36;
      v39 = v37 - v36;
      result = (v39 < v38) + v14;
      a1[7] = v39 - v38;
      a2 += 8;
      a3 += 8;
      a1 += 8;
      v9 -= 8;
    }
    while ( v9 );
  }
  if ( (a4 & 7) != 0 )
  {
    v40 = *a2 - result;
    result = (v40 < *a3) + (*a2 < result);
    *a1 = v40 - *a3;
    ++a2;
    ++a3;
    ++a1;
    if ( (a4 & 7) != 1 )
    {
      v41 = *a2 - result;
      result = (v41 < *a3) + (*a2 < result);
      *a1 = v41 - *a3;
      ++a2;
      ++a3;
      ++a1;
      if ( (a4 & 7) != 2 )
      {
        v42 = *a2 - result;
        result = (v42 < *a3) + (*a2 < result);
        *a1 = v42 - *a3;
        ++a2;
        ++a3;
        ++a1;
        if ( (a4 & 7) != 3 )
        {
          v43 = *a2 - result;
          result = (v43 < *a3) + (*a2 < result);
          *a1 = v43 - *a3;
          ++a2;
          ++a3;
          ++a1;
          if ( (a4 & 7) != 4 )
          {
            v44 = *a2 - result;
            result = (v44 < *a3) + (*a2 < result);
            *a1 = v44 - *a3;
            ++a2;
            ++a3;
            ++a1;
            if ( (a4 & 7) != 5 )
            {
              v45 = *a2 - result;
              result = (v45 < *a3) + (*a2 < result);
              *a1 = v45 - *a3;
              ++a2;
              ++a3;
              ++a1;
              if ( (a4 & 7) != 6 )
              {
                v46 = *a2 - result;
                result = (v46 < *a3) + (*a2 < result);
                *a1 = v46 - *a3;
                ++a2;
                ++a3;
                ++a1;
              }
            }
          }
        }
      }
    }
  }
  if ( a5 )
  {
    if ( a5 < 0 )
    {
      for ( i = -a5 & 0xFFFFFFF8; i; i -= 8 )
      {
        v48 = -result;
        v49 = (-result < *a3) + (result != 0);
        *a1 = v48 - *a3;
        v50 = a3[1];
        v51 = -v49;
        v52 = (-v49 < v50) + (v49 != 0);
        a1[1] = v51 - v50;
        v53 = a3[2];
        v54 = -v52;
        v55 = (-v52 < v53) + (v52 != 0);
        a1[2] = v54 - v53;
        v56 = a3[3];
        v57 = -v55;
        v58 = (-v55 < v56) + (v55 != 0);
        a1[3] = v57 - v56;
        v59 = a3[4];
        v60 = -v58;
        v61 = (-v58 < v59) + (v58 != 0);
        a1[4] = v60 - v59;
        v62 = a3[5];
        v63 = -v61;
        v64 = (-v61 < v62) + (v61 != 0);
        a1[5] = v63 - v62;
        v65 = a3[6];
        v66 = -v64;
        v67 = (-v64 < v65) + (v64 != 0);
        a1[6] = v66 - v65;
        v68 = a3[7];
        v69 = -v67 - v68;
        result = (-v67 < v68) + (v67 != 0);
        a1[7] = v69;
        a3 += 8;
        a1 += 8;
      }
      if ( (-(char)a5 & 7) != 0 )
      {
        v70 = -result;
        result = (-result < *a3) + (result != 0);
        *a1 = v70 - *a3;
        if ( (-(char)a5 & 7) != 1 )
        {
          v71 = a3[1];
          v72 = -result;
          result = (-result < v71) + (result != 0);
          a1[1] = v72 - v71;
          if ( (-(char)a5 & 7) != 2 )
          {
            v73 = a3[2];
            v74 = -result;
            result = (-result < v73) + (result != 0);
            a1[2] = v74 - v73;
            if ( (-(char)a5 & 7) != 3 )
            {
              v75 = a3[3];
              v76 = -result;
              result = (-result < v75) + (result != 0);
              a1[3] = v76 - v75;
              if ( (-(char)a5 & 7) != 4 )
              {
                v77 = a3[4];
                v78 = -result;
                result = (-result < v77) + (result != 0);
                a1[4] = v78 - v77;
                if ( (-(char)a5 & 7) != 5 )
                {
                  v79 = a3[5];
                  v80 = -result;
                  result = (-result < v79) + (result != 0);
                  a1[5] = v80 - v79;
                  if ( (-(char)a5 & 7) != 6 )
                  {
                    v81 = a3[6];
                    v82 = -result;
                    result = (-result < v81) + (result != 0);
                    a1[6] = v82 - v81;
                  }
                }
              }
            }
          }
        }
      }
      return result;
    }
    v83 = a5 & 0x7FFFFFF8;
    if ( (a5 & 0xFFFFFFF8) != 0 )
    {
      while ( 1 )
      {
        v14 = *a2 < result;
        *a1 = *a2 - result;
        if ( !v14 )
          goto $L035pw_nc0;
        v84 = a2[1];
        a1[1] = v84 - result;
        if ( v84 >= result )
          goto $L036pw_nc1;
        v85 = a2[2];
        a1[2] = v85 - result;
        if ( v85 >= result )
          goto $L037pw_nc2;
        v86 = a2[3];
        a1[3] = v86 - result;
        if ( v86 >= result )
          goto $L038pw_nc3;
        v87 = a2[4];
        a1[4] = v87 - result;
        if ( v87 >= result )
          goto $L039pw_nc4;
        v88 = a2[5];
        a1[5] = v88 - result;
        if ( v88 >= result )
          goto $L040pw_nc5;
        v89 = a2[6];
        a1[6] = v89 - result;
        if ( v89 >= result )
          goto $L041pw_nc6;
        v90 = a2[7];
        a1[7] = v90 - result;
        if ( v90 >= result )
          break;
        a2 += 8;
        a1 += 8;
        v83 -= 8;
        if ( !v83 )
          goto $L033pw_pos_finish;
      }
      while ( 1 )
      {
        a2 += 8;
        a1 += 8;
        v83 -= 8;
        if ( !v83 )
          break;
        *a1 = *a2;
$L035pw_nc0:
        a1[1] = a2[1];
$L036pw_nc1:
        a1[2] = a2[2];
$L037pw_nc2:
        a1[3] = a2[3];
$L038pw_nc3:
        a1[4] = a2[4];
$L039pw_nc4:
        a1[5] = a2[5];
$L040pw_nc5:
        a1[6] = a2[6];
$L041pw_nc6:
        a1[7] = a2[7];
      }
      v91 = a5 & 7;
      if ( (a5 & 7) == 0 )
        return 0;
      *a1 = *a2;
    }
    else
    {
$L033pw_pos_finish:
      v91 = a5 & 7;
      if ( (a5 & 7) == 0 )
        return result;
      v14 = *a2 < result;
      *a1 = *a2 - result;
      if ( v14 )
      {
        v92 = v91 - 1;
        if ( !v92 )
          return result;
        v93 = a2[1];
        a1[1] = v93 - result;
        if ( v93 < result )
        {
          v94 = v92 - 1;
          if ( !v94 )
            return result;
          v95 = a2[2];
          a1[2] = v95 - result;
          if ( v95 < result )
          {
            v96 = v94 - 1;
            if ( !v96 )
              return result;
            v97 = a2[3];
            a1[3] = v97 - result;
            if ( v97 < result )
            {
              v98 = v96 - 1;
              if ( !v98 )
                return result;
              v99 = a2[4];
              a1[4] = v99 - result;
              if ( v99 < result )
              {
                v100 = v98 - 1;
                if ( !v100 )
                  return result;
                v101 = a2[5];
                a1[5] = v101 - result;
                if ( v101 < result )
                {
                  if ( v100 == 1 )
                    return result;
                  v102 = a2[6];
                  a1[6] = v102 - result;
                  return v102 < result;
                }
                goto $L048pw_tail_nc5;
              }
$L047pw_tail_nc4:
              v100 = v98 - 1;
              if ( v100 )
              {
                a1[5] = a2[5];
$L048pw_tail_nc5:
                if ( v100 != 1 )
                  a1[6] = a2[6];
              }
              return 0;
            }
$L046pw_tail_nc3:
            v98 = v96 - 1;
            if ( !v98 )
              return 0;
            a1[4] = a2[4];
            goto $L047pw_tail_nc4;
          }
$L045pw_tail_nc2:
          v96 = v94 - 1;
          if ( !v96 )
            return 0;
          a1[3] = a2[3];
          goto $L046pw_tail_nc3;
        }
$L044pw_tail_nc1:
        v94 = v92 - 1;
        if ( !v94 )
          return 0;
        a1[2] = a2[2];
        goto $L045pw_tail_nc2;
      }
    }
    v92 = v91 - 1;
    if ( !v92 )
      return 0;
    a1[1] = a2[1];
    goto $L044pw_tail_nc1;
  }
  return result;
}
