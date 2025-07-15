void __cdecl seed_chase(float *seeds, int linesper, int n)
{
  void *v3; // esp
  void *v4; // esp
  int v5; // eax
  int v6; // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  int *v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // [esp+0h] [ebp-20h] BYREF
  int v13; // [esp+4h] [ebp-1Ch] BYREF
  int v14; // [esp+Ch] [ebp-14h]
  int v15; // [esp+10h] [ebp-10h]
  int *v16; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]

  v3 = alloca(4 * n);
  v4 = alloca(4 * n);
  v5 = 0;
  v6 = 0;
  for ( i = 0; v5 < n; ++v5 )
  {
    if ( v6 >= 2 )
    {
      v7 = seeds[v5];
      if ( *((float *)&v12 + v6 - 1) <= v7 )
      {
        v18 = 0;
        v16 = &v12 + v6 - 2;
        do
        {
          if ( v5 >= linesper + *(&v12 + v6 - 1) )
            break;
          if ( v6 <= 1 )
            break;
          if ( *(float *)((char *)v16 + v18) < *((float *)&v12 + v6 - 1) )
            break;
          if ( v5 >= linesper + *v16 )
            break;
          --v16;
          v8 = *((float *)&v12 + v6-- - 2);
        }
        while ( v8 <= v7 );
      }
      *((float *)&v12 + v6) = v7;
    }
    else
    {
      *(&v12 + v6) = SLODWORD(seeds[v5]);
    }
    *(&v12 + v6++) = v5;
  }
  v9 = 0;
  v16 = 0;
  if ( v6 > 0 )
  {
    v18 = 0;
    v10 = &v13;
    do
    {
      if ( (int)v9 >= v6 - 1 || *(float *)((char *)v10 + v18) <= *((float *)&v12 + (_DWORD)v9) )
        v11 = *(v10 - 1) + linesper + 1;
      else
        v11 = *v10;
      if ( v11 > n )
        v11 = n;
      if ( i < v11 )
      {
        v15 = *(&v12 + (_DWORD)v9);
        v14 = v11 - i;
        memset32(&seeds[i], v15, v11 - i);
        i += v14;
        v9 = v16;
      }
      v9 = (int *)((char *)v9 + 1);
      ++v10;
      v16 = v9;
    }
    while ( (int)v9 < v6 );
  }
}
