void __cdecl drfti1(int n, float *wa, int *ifac)
{
  int v3; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  int *v8; // ebx
  int *v9; // ecx
  int v10; // edx
  bool v11; // zf
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  float *v15; // esi
  unsigned int v16; // edi
  float *v17; // esi
  float fi; // [esp+10h] [ebp-24h]
  int is; // [esp+14h] [ebp-20h]
  int l1; // [esp+18h] [ebp-1Ch]
  int *v21; // [esp+1Ch] [ebp-18h]
  float arg; // [esp+20h] [ebp-14h]
  int j; // [esp+24h] [ebp-10h]
  int ja; // [esp+24h] [ebp-10h]
  int nl; // [esp+28h] [ebp-Ch]
  float argh; // [esp+2Ch] [ebp-8h]
  float argld; // [esp+30h] [ebp-4h]
  int ld; // [esp+40h] [ebp+Ch]

  v3 = n;
  v4 = 0;
  v5 = -1;
  v6 = 0;
  do
  {
L101:
    j = ++v5;
    if ( v5 >= 4 )
      v4 += 2;
    else
      v4 = ntryh[v5];
    v7 = v3 / v4;
  }
  while ( v3 % v4 );
  v8 = &ifac[v6];
  while ( 1 )
  {
    ++v8;
    ++v6;
    v3 = v7;
    v8[1] = v4;
    if ( v4 == 2 && v6 != 1 )
    {
      if ( v6 > 1 )
      {
        v9 = v8;
        v10 = v6 - 1;
        do
        {
          v9[1] = *v9;
          --v9;
          --v10;
        }
        while ( v10 );
        v3 = v7;
      }
      ifac[2] = 2;
    }
    if ( v7 == 1 )
      break;
    v7 /= v4;
    if ( v3 != v4 * v7 )
    {
      v5 = j;
      goto L101;
    }
  }
  ifac[1] = v6;
  v11 = v6 == 1;
  v12 = v6 - 1;
  *ifac = n;
  is = 0;
  l1 = 1;
  if ( !v11 && v12 > 0 )
  {
    v21 = ifac + 2;
    nl = v12;
    do
    {
      v13 = l1 * *v21;
      ld = 0;
      v14 = n / v13;
      if ( *v21 - 1 > 0 )
      {
        ja = *v21 - 1;
        do
        {
          ld += l1;
          fi = 0.0;
          if ( v14 > 2 )
          {
            v15 = &wa[is];
            v16 = ((unsigned int)(v14 - 3) >> 1) + 1;
            do
            {
              fi = fi + 1.0;
              argh = 6.283185482025146 / (double)n;
              argld = (double)ld * argh;
              arg = fi * argld;
              *v15 = cos(arg);
              v17 = v15 + 1;
              *v17 = sin(arg);
              v15 = v17 + 1;
              --v16;
            }
            while ( v16 );
          }
          is += v14;
          --ja;
        }
        while ( ja );
      }
      ++v21;
      v11 = nl-- == 1;
      l1 = v13;
    }
    while ( !v11 );
  }
}
