void __cdecl seed_chase(float *seeds, int linesper, int n)
{
  void *v3; // esp
  void *v4; // esp
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  float *v8; // esi
  float *v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st7
  int *v13; // ecx
  int v14; // edi
  unsigned int v15; // eax
  float *v16; // ecx
  double v17; // st7
  unsigned int v18; // ecx
  float *v19; // edi
  bool v20; // cc
  int v21; // [esp+0h] [ebp-20h] BYREF
  _BYTE v22[8]; // [esp+4h] [ebp-1Ch] BYREF
  int v23; // [esp+Ch] [ebp-14h]
  int v24; // [esp+10h] [ebp-10h]
  int *i; // [esp+14h] [ebp-Ch]
  int v26; // [esp+18h] [ebp-8h]
  _DWORD *v27; // [esp+1Ch] [ebp-4h]

  v3 = alloca(4 * n);
  v4 = alloca(4 * n);
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = (float *)&v21;
  for ( i = 0; v6 < n; ++v7 )
  {
    v9 = seeds;
    if ( v7 >= 2 )
    {
      v10 = seeds[v6];
      if ( *(float *)&v22[4 * v7 - 8] <= v10 )
      {
        v27 = &v22[4 * v7 - 12];
        v26 = 0;
        do
        {
          if ( v6 >= linesper + *(_DWORD *)&v22[4 * v7 - 8] )
            break;
          if ( v7 <= 1 )
            break;
          if ( *(float *)((char *)v27 + v26) < (double)*(float *)&v22[4 * v7 - 8] )
            break;
          if ( v6 >= linesper + *v27 )
            break;
          v11 = *(float *)&v22[4 * v7 - 12];
          --v27;
          --v7;
        }
        while ( v11 <= v10 );
        v5 = (int)i;
      }
      v9 = seeds;
    }
    v12 = v9[v6];
    *(_DWORD *)&v22[4 * v7 - 4] = v6;
    *(float *)&v22[4 * v7 - 4] = v12;
    ++v6;
  }
  v27 = 0;
  if ( v7 > 0 )
  {
    v13 = (int *)v22;
    i = (int *)v22;
    v26 = 0;
    do
    {
      if ( (int)v27 >= v7 - 1 || *v8 >= (double)*(float *)((char *)v13 + v26) )
        v14 = *(v13 - 1) + linesper + 1;
      else
        v14 = *v13;
      if ( v14 > n )
        v14 = n;
      if ( v5 < v14 )
      {
        if ( v14 - v5 >= 4 )
        {
          v15 = ((unsigned int)(v14 - v5 - 4) >> 2) + 1;
          v16 = &seeds[v5 + 2];
          v5 += 4 * v15;
          do
          {
            v16 += 4;
            --v15;
            *(v16 - 6) = *v8;
            *(v16 - 5) = *v8;
            *(v16 - 4) = *v8;
            *(v16 - 3) = *v8;
          }
          while ( v15 );
          v13 = i;
        }
        if ( v5 < v14 )
        {
          v17 = *v8;
          v23 = v14 - v5;
          *(float *)&v24 = v17;
          v18 = v14 - v5;
          v19 = &seeds[v5];
          v5 += v23;
          memset32(v19, v24, v18);
          v13 = i;
        }
      }
      ++v13;
      ++v8;
      v20 = (int)v27 + 1 < v7;
      v27 = (_DWORD *)((char *)v27 + 1);
      i = v13;
    }
    while ( v20 );
  }
}
