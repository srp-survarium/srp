_DWORD *__cdecl jpeg_core_output_dimensions(_DWORD *a1)
{
  int v1; // eax
  unsigned int v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  _DWORD *result; // eax
  int v25; // ecx
  int v26; // [esp-14h] [ebp-18h]
  int v27; // [esp-14h] [ebp-18h]
  int v28; // [esp-10h] [ebp-14h]
  int v29; // [esp-10h] [ebp-14h]
  int v30; // [esp-10h] [ebp-14h]
  int v31; // [esp-Ch] [ebp-10h]

  v1 = a1[96];
  v2 = a1[13];
  v3 = v1 * a1[12];
  if ( v3 > v2 )
  {
    if ( v3 > 2 * v2 )
    {
      if ( v3 > 3 * v2 )
      {
        if ( v3 > 4 * v2 )
        {
          if ( v3 > 5 * v2 )
          {
            if ( v3 > 6 * v2 )
            {
              if ( v3 > 7 * v2 )
              {
                if ( v3 > 8 * v2 )
                {
                  if ( v3 > 9 * v2 )
                  {
                    if ( v3 > 10 * v2 )
                    {
                      if ( v3 > 11 * v2 )
                      {
                        if ( v3 > 12 * v2 )
                        {
                          if ( v3 > 13 * v2 )
                          {
                            if ( v3 > 14 * v2 )
                            {
                              if ( v3 > 15 * v2 )
                              {
                                v22 = jdiv_round_up(16 * a1[7], v1);
                                v23 = a1[8];
                                a1[23] = v22;
                                a1[24] = jdiv_round_up(16 * v23, a1[96]);
                                v6 = 16;
                              }
                              else
                              {
                                a1[23] = jdiv_round_up(15 * a1[7], v1);
                                a1[24] = jdiv_round_up(15 * a1[8], a1[96]);
                                v6 = 15;
                              }
                            }
                            else
                            {
                              a1[23] = jdiv_round_up(14 * a1[7], v1);
                              a1[24] = jdiv_round_up(14 * a1[8], a1[96]);
                              v6 = 14;
                            }
                          }
                          else
                          {
                            v20 = jdiv_round_up(13 * a1[7], v1);
                            v21 = 13 * a1[8];
                            a1[23] = v20;
                            a1[24] = jdiv_round_up(v21, a1[96]);
                            v6 = 13;
                          }
                        }
                        else
                        {
                          a1[23] = jdiv_round_up(12 * a1[7], v1);
                          a1[24] = jdiv_round_up(12 * a1[8], a1[96]);
                          v6 = 12;
                        }
                      }
                      else
                      {
                        v18 = jdiv_round_up(11 * a1[7], v1);
                        v19 = 11 * a1[8];
                        a1[23] = v18;
                        a1[24] = jdiv_round_up(v19, a1[96]);
                        v6 = 11;
                      }
                    }
                    else
                    {
                      a1[23] = jdiv_round_up(10 * a1[7], v1);
                      a1[24] = jdiv_round_up(10 * a1[8], a1[96]);
                      v6 = 10;
                    }
                  }
                  else
                  {
                    a1[23] = jdiv_round_up(9 * a1[7], v1);
                    a1[24] = jdiv_round_up(9 * a1[8], a1[96]);
                    v6 = 9;
                  }
                }
                else
                {
                  v16 = jdiv_round_up(8 * a1[7], v1);
                  v17 = 2 * a1[8];
                  a1[23] = v16;
                  a1[24] = jdiv_round_up(4 * v17, a1[96]);
                  v6 = 8;
                }
              }
              else
              {
                v14 = jdiv_round_up(7 * a1[7], v1);
                v15 = a1[96];
                a1[23] = v14;
                a1[24] = jdiv_round_up(7 * a1[8], v15);
                v6 = 7;
              }
            }
            else
            {
              v12 = jdiv_round_up(6 * a1[7], v1);
              v13 = a1[96];
              a1[23] = v12;
              a1[24] = jdiv_round_up(6 * a1[8], v13);
              v6 = 6;
            }
          }
          else
          {
            v10 = jdiv_round_up(5 * a1[7], v1);
            v11 = a1[96];
            a1[23] = v10;
            a1[24] = jdiv_round_up(5 * a1[8], v11);
            v6 = 5;
          }
        }
        else
        {
          v9 = jdiv_round_up(4 * a1[7], v1);
          v30 = a1[96];
          v27 = 4 * a1[8];
          a1[23] = v9;
          a1[24] = jdiv_round_up(v27, v30);
          v6 = 4;
        }
      }
      else
      {
        v7 = jdiv_round_up(3 * a1[7], v1);
        v8 = a1[96];
        a1[23] = v7;
        a1[24] = jdiv_round_up(3 * a1[8], v8);
        v6 = 3;
      }
    }
    else
    {
      v5 = jdiv_round_up(2 * a1[7], v1);
      v29 = a1[96];
      v26 = 2 * a1[8];
      a1[23] = v5;
      a1[24] = jdiv_round_up(v26, v29);
      v6 = 2;
    }
    a1[70] = v6;
    a1[71] = v6;
  }
  else
  {
    v4 = jdiv_round_up(a1[7], v1);
    v31 = a1[96];
    v28 = a1[8];
    a1[23] = v4;
    a1[24] = jdiv_round_up(v28, v31);
    a1[70] = 1;
    a1[71] = 1;
  }
  result = (_DWORD *)a1[49];
  v25 = 0;
  if ( (int)a1[9] > 0 )
  {
    result += 10;
    do
    {
      *(result - 1) = a1[70];
      *result = a1[71];
      ++v25;
      result += 22;
    }
    while ( v25 < a1[9] );
  }
  return result;
}
