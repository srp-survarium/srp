int __cdecl sub_488490(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  _DWORD *v7; // esi
  int *v8; // eax
  int *v9; // ecx
  int v10; // edx
  int v11; // ebp
  int v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v17; // [esp+0h] [ebp-4h]

  v4 = a4;
  v5 = a2;
  v6 = a3;
  if ( a3 >= a4 )
    return a3;
  v17 = 2 * a3;
  v7 = (_DWORD *)(32 * a3 + a2 + 12);
  while ( 1 )
  {
    v8 = v17 > v4 ? sub_488080(v5, v6) : sub_488050(v5, v6);
    v9 = v8;
    if ( !v8 )
      break;
    *(v7 - 2) = v8[1];
    *v7 = v8[3];
    v7[2] = v8[5];
    *(v7 - 3) = *v8;
    *(v7 - 1) = v8[2];
    v7[1] = v8[4];
    v10 = 12 * (v8[3] - v8[2]);
    v11 = 1;
    if ( 16 * (v8[1] - *v8) > v10 )
    {
      v10 = 16 * (v8[1] - *v8);
      v11 = 0;
    }
    if ( 8 * (v8[5] - v8[4]) > v10 )
      v11 = 2;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          v13 = (v8[4] + v8[5]) / 2;
          v9[5] = v13;
          v7[1] = v13 + 1;
        }
      }
      else
      {
        v14 = (v8[2] + v8[3]) / 2;
        v9[3] = v14;
        *(v7 - 1) = v14 + 1;
      }
    }
    else
    {
      v15 = (*v8 + v8[1]) / 2;
      v9[1] = v15;
      *(v7 - 3) = v15 + 1;
    }
    sub_4880B0(v9);
    sub_4880B0(v7 - 3);
    v4 = a4;
    v17 += 2;
    v6 = a3 + 1;
    v7 += 8;
    if ( ++a3 >= a4 )
      break;
    v5 = a2;
  }
  return v6;
}
