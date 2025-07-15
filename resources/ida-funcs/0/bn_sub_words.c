unsigned int __cdecl bn_sub_words(_DWORD *a1, _DWORD *a2, unsigned int *a3, int a4)
{
  unsigned int result; // eax
  unsigned int v8; // ebp
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // edx
  bool v13; // cf
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ecx
  unsigned int v39; // ecx
  unsigned int v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // ecx
  unsigned int v49; // ecx
  unsigned int v50; // edx
  unsigned int v51; // ecx
  unsigned int v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // ecx
  unsigned int v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // ecx

  result = 0;
  v8 = a4 & 0xFFFFFFF8;
  if ( (a4 & 0xFFFFFFF8) != 0 )
  {
    do
    {
      v9 = *a2 - result;
      v10 = (v9 < *a3) + (*a2 < result);
      *a1 = v9 - *a3;
      v11 = a2[1];
      v12 = a3[1];
      v13 = v11 < v10;
      v14 = v11 - v10;
      v15 = (v14 < v12) + v13;
      a1[1] = v14 - v12;
      v16 = a2[2];
      v17 = a3[2];
      v13 = v16 < v15;
      v18 = v16 - v15;
      v19 = (v18 < v17) + v13;
      a1[2] = v18 - v17;
      v20 = a2[3];
      v21 = a3[3];
      v13 = v20 < v19;
      v22 = v20 - v19;
      v23 = (v22 < v21) + v13;
      a1[3] = v22 - v21;
      v24 = a2[4];
      v25 = a3[4];
      v13 = v24 < v23;
      v26 = v24 - v23;
      v27 = (v26 < v25) + v13;
      a1[4] = v26 - v25;
      v28 = a2[5];
      v29 = a3[5];
      v13 = v28 < v27;
      v30 = v28 - v27;
      v31 = (v30 < v29) + v13;
      a1[5] = v30 - v29;
      v32 = a2[6];
      v33 = a3[6];
      v13 = v32 < v31;
      v34 = v32 - v31;
      v35 = (v34 < v33) + v13;
      a1[6] = v34 - v33;
      v36 = a2[7];
      v37 = a3[7];
      v13 = v36 < v35;
      v38 = v36 - v35;
      result = (v38 < v37) + v13;
      a1[7] = v38 - v37;
      a2 += 8;
      a3 += 8;
      a1 += 8;
      v8 -= 8;
    }
    while ( v8 );
  }
  if ( (a4 & 7) != 0 )
  {
    v39 = *a2 - result;
    result = (v39 < *a3) + (*a2 < result);
    *a1 = v39 - *a3;
    if ( (a4 & 7) != 1 )
    {
      v40 = a2[1];
      v41 = a3[1];
      v13 = v40 < result;
      v42 = v40 - result;
      result = (v42 < v41) + v13;
      a1[1] = v42 - v41;
      if ( (a4 & 7) != 2 )
      {
        v43 = a2[2];
        v44 = a3[2];
        v13 = v43 < result;
        v45 = v43 - result;
        result = (v45 < v44) + v13;
        a1[2] = v45 - v44;
        if ( (a4 & 7) != 3 )
        {
          v46 = a2[3];
          v47 = a3[3];
          v13 = v46 < result;
          v48 = v46 - result;
          result = (v48 < v47) + v13;
          a1[3] = v48 - v47;
          if ( (a4 & 7) != 4 )
          {
            v49 = a2[4];
            v50 = a3[4];
            v13 = v49 < result;
            v51 = v49 - result;
            result = (v51 < v50) + v13;
            a1[4] = v51 - v50;
            if ( (a4 & 7) != 5 )
            {
              v52 = a2[5];
              v53 = a3[5];
              v13 = v52 < result;
              v54 = v52 - result;
              result = (v54 < v53) + v13;
              a1[5] = v54 - v53;
              if ( (a4 & 7) != 6 )
              {
                v55 = a2[6];
                v56 = a3[6];
                v13 = v55 < result;
                v57 = v55 - result;
                result = (v57 < v56) + v13;
                a1[6] = v57 - v56;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
