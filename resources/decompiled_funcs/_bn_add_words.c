unsigned int __cdecl bn_add_words(int *a1, unsigned int *a2, unsigned int *a3, int a4)
{
  unsigned int result; // eax
  unsigned int v8; // ebp
  unsigned int v9; // eax
  int v10; // kr40_4
  unsigned int v11; // eax
  int v12; // kr48_4
  unsigned int v13; // eax
  int v14; // kr50_4
  unsigned int v15; // eax
  int v16; // kr58_4
  unsigned int v17; // eax
  int v18; // kr60_4
  unsigned int v19; // eax
  int v20; // kr68_4
  unsigned int v21; // eax
  int v22; // kr70_4
  int v23; // kr78_4
  int v24; // kr80_4
  unsigned __int64 v25; // kr90_8
  unsigned __int64 v26; // krA0_8
  unsigned __int64 v27; // krB0_8
  unsigned __int64 v28; // krC0_8
  unsigned __int64 v29; // krD0_8
  unsigned __int64 v30; // krE0_8

  result = 0;
  v8 = a4 & 0xFFFFFFF8;
  if ( (a4 & 0xFFFFFFF8) != 0 )
  {
    do
    {
      v10 = *a3 + result + *a2;
      v9 = (*a3 + result + (unsigned __int64)*a2) >> 32;
      *a1 = v10;
      v12 = a3[1] + v9 + a2[1];
      v11 = (a3[1] + v9 + (unsigned __int64)a2[1]) >> 32;
      a1[1] = v12;
      v14 = a3[2] + v11 + a2[2];
      v13 = (a3[2] + v11 + (unsigned __int64)a2[2]) >> 32;
      a1[2] = v14;
      v16 = a3[3] + v13 + a2[3];
      v15 = (a3[3] + v13 + (unsigned __int64)a2[3]) >> 32;
      a1[3] = v16;
      v18 = a3[4] + v15 + a2[4];
      v17 = (a3[4] + v15 + (unsigned __int64)a2[4]) >> 32;
      a1[4] = v18;
      v20 = a3[5] + v17 + a2[5];
      v19 = (a3[5] + v17 + (unsigned __int64)a2[5]) >> 32;
      a1[5] = v20;
      v22 = a3[6] + v19 + a2[6];
      v21 = (a3[6] + v19 + (unsigned __int64)a2[6]) >> 32;
      a1[6] = v22;
      v23 = a3[7] + v21 + a2[7];
      result = (a3[7] + v21 + (unsigned __int64)a2[7]) >> 32;
      a1[7] = v23;
      a2 += 8;
      a3 += 8;
      a1 += 8;
      v8 -= 8;
    }
    while ( v8 );
  }
  if ( (a4 & 7) != 0 )
  {
    v24 = *a3 + result + *a2;
    result = (*a3 + result + (unsigned __int64)*a2) >> 32;
    *a1 = v24;
    if ( (a4 & 7) != 1 )
    {
      v25 = a3[1] + result + (unsigned __int64)a2[1];
      result = HIDWORD(v25);
      a1[1] = v25;
      if ( (a4 & 7) != 2 )
      {
        v26 = a3[2] + HIDWORD(v25) + (unsigned __int64)a2[2];
        result = HIDWORD(v26);
        a1[2] = v26;
        if ( (a4 & 7) != 3 )
        {
          v27 = a3[3] + HIDWORD(v26) + (unsigned __int64)a2[3];
          result = HIDWORD(v27);
          a1[3] = v27;
          if ( (a4 & 7) != 4 )
          {
            v28 = a3[4] + HIDWORD(v27) + (unsigned __int64)a2[4];
            result = HIDWORD(v28);
            a1[4] = v28;
            if ( (a4 & 7) != 5 )
            {
              v29 = a3[5] + HIDWORD(v28) + (unsigned __int64)a2[5];
              result = HIDWORD(v29);
              a1[5] = v29;
              if ( (a4 & 7) != 6 )
              {
                v30 = a3[6] + HIDWORD(v29) + (unsigned __int64)a2[6];
                result = HIDWORD(v30);
                a1[6] = v30;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
