int __cdecl local_book_besterror(char *a)
{
  int *v1; // ecx
  int v2; // eax
  int v3; // edx
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // edi
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int *v21; // esi
  char *v22; // esi
  int v23; // ecx
  int v24; // edx
  int *v25; // ecx
  int *v26; // ecx
  _DWORD v28[8]; // [esp+Ch] [ebp-64h] BYREF
  _DWORD v29[8]; // [esp+2Ch] [ebp-44h] BYREF
  int v30; // [esp+4Ch] [ebp-24h]
  int v31; // [esp+50h] [ebp-20h]
  int v32; // [esp+54h] [ebp-1Ch]
  int *v33; // [esp+58h] [ebp-18h]
  int v34; // [esp+5Ch] [ebp-14h]
  int v35; // [esp+60h] [ebp-10h]
  int v36; // [esp+64h] [ebp-Ch]
  int v37; // [esp+68h] [ebp-8h]
  int v38; // [esp+6Ch] [ebp-4h]

  v2 = *v1;
  v3 = v1[12];
  v4 = 0;
  v36 = v1[13];
  v5 = v1[11] >> 1;
  v37 = v2;
  v35 = v5;
  v38 = 0;
  memset(v28, 0, sizeof(v28));
  if ( v36 == 1 )
  {
    if ( v2 > 0 )
    {
      v34 = (int)&v28[v2];
      v12 = a - (char *)v28;
      v32 = a - (char *)v28;
      v31 = v37;
      while ( 1 )
      {
        v34 -= 4;
        v13 = *(_DWORD *)(v34 + v12) - v3;
        v14 = v13 >= v5 ? 2 * (v13 - v5) : 2 * (v5 - v13) - 1;
        if ( v14 >= 0 )
        {
          v15 = v1[11];
          v33 = (int *)(v14 < v15 ? v14 : v15 - 1);
        }
        else
        {
          v33 = 0;
        }
        v16 = (int)v33 + v1[11] * v38;
        v11 = v31-- == 1;
        v38 = v16;
        *(_DWORD *)v34 = v3 + v13;
        if ( v11 )
          break;
        v5 = v35;
        v12 = v32;
      }
    }
  }
  else if ( v2 > 0 )
  {
    v34 = v36 >> 1;
    v6 = &v28[v2];
    v7 = a - (char *)v28;
    v32 = a - (char *)v28;
    v31 = v37;
    while ( 1 )
    {
      v8 = (v34 + *(_DWORD *)((char *)--v6 + v7) - v3) / v36;
      v9 = v8 >= v35 ? 2 * (v8 - v35) : 2 * (v35 - v8) - 1;
      if ( v9 >= 0 )
      {
        v10 = v1[11];
        v33 = (int *)(v9 < v10 ? v9 : v10 - 1);
      }
      else
      {
        v33 = 0;
      }
      v38 = (int)v33 + v1[11] * v38;
      v3 = v1[12];
      v11 = v31-- == 1;
      *v6 = v3 + v36 * v8;
      if ( v11 )
        break;
      v7 = v32;
    }
  }
  v17 = v1[3];
  if ( *(int *)(*(_DWORD *)(v17 + 8) + 4 * v38) <= 0 )
  {
    v18 = v1[11];
    v32 = -1;
    v19 = v1[1];
    v20 = v3 + v36 * (v18 - 1);
    memset(v29, 0, sizeof(v29));
    v35 = 0;
    v30 = v19;
    if ( v19 > 0 )
    {
      v21 = *(int **)(v17 + 8);
      v33 = v21;
      do
      {
        if ( *v21 > 0 )
        {
          v34 = 0;
          if ( v37 > 0 )
          {
            v22 = a;
            v31 = v37;
            do
            {
              v23 = *(_DWORD *)&v22[(char *)v29 - a] - *(_DWORD *)v22;
              v22 += 4;
              v34 += v23 * v23;
              --v31;
            }
            while ( v31 );
          }
          if ( v32 == -1 || v34 < v32 )
          {
            qmemcpy(v28, v29, sizeof(v28));
            v32 = v34;
            v38 = v35;
          }
        }
        v24 = 0;
        if ( v29[0] >= v20 )
        {
          v25 = v29;
          do
          {
            ++v24;
            *v25 = 0;
            v25 = &v29[v24];
          }
          while ( *v25 >= v20 );
        }
        v26 = &v29[v24];
        if ( *v26 >= 0 )
          *v26 += v36;
        *v26 = -*v26;
        ++v35;
        v21 = ++v33;
      }
      while ( v35 < v30 );
    }
  }
  if ( v38 > -1 && v37 > 0 )
  {
    do
    {
      *(_DWORD *)a -= v28[v4++];
      a += 4;
    }
    while ( v4 < v37 );
  }
  return v38;
}
