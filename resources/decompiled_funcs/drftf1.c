void __usercall drftf1(float *c@<esi>, int *ifac@<edx>, int n, float *ch, float *wa)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ebx
  int v9; // edx
  int v10; // ecx
  float *v11; // eax
  float *v12; // edx
  bool v13; // zf
  int v14; // edx
  int v15; // ebx
  float *v16; // ecx
  unsigned int v17; // edx
  float *v18; // eax
  float *v19; // eax
  int v20; // edx
  double v21; // st7
  float *v22; // [esp-4h] [ebp-24h]
  float *v23; // [esp-4h] [ebp-24h]
  int *v24; // [esp+Ch] [ebp-14h]
  int na; // [esp+10h] [ebp-10h]
  int idl1; // [esp+14h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-4h]

  v5 = ifac[1];
  v6 = n;
  na = 1;
  v7 = n;
  if ( v5 > 0 )
  {
    v24 = &ifac[v5 + 1];
    v27 = ifac[1];
    do
    {
      v8 = v6 / *v24;
      v9 = 1 - na;
      na = 1 - na;
      v10 = n / v6;
      idl1 = v8 * v10;
      v7 -= v10 * (*v24 - 1);
      if ( *v24 == 4 )
      {
        if ( v9 )
        {
          v11 = ch;
          v12 = c;
        }
        else
        {
          v12 = ch;
          v11 = c;
        }
        dradf4(v11, v12, v10, v8, &wa[v7 - 1], &wa[v10 - 1 + v7], &wa[v10 - 1 + v10 + v7]);
      }
      else if ( *v24 == 2 )
      {
        v23 = &wa[v7 - 1];
        if ( v9 )
          dradf2(v10, ch, c, v8, v23);
        else
          dradf2(v10, c, ch, v8, v23);
      }
      else
      {
        if ( v10 == 1 )
          v9 = 1 - v9;
        v22 = &wa[v7 - 1];
        if ( v9 )
        {
          dradfg(ch, c, v10, *v24, v8, idl1, ch, ch, c, v22);
          na = 0;
        }
        else
        {
          dradfg(c, ch, v10, *v24, v8, idl1, c, c, ch, v22);
          na = 1;
        }
      }
      --v24;
      v13 = v27-- == 1;
      v6 = v8;
    }
    while ( !v13 );
    if ( na != 1 )
    {
      v14 = n;
      v15 = 0;
      if ( n >= 4 )
      {
        v16 = ch + 3;
        v17 = ((unsigned int)(n - 4) >> 2) + 1;
        v18 = c + 1;
        v15 = 4 * v17;
        do
        {
          v18 += 4;
          *(v18 - 5) = *(v16 - 3);
          v16 += 4;
          --v17;
          *(v18 - 4) = *(float *)((char *)v18 + (char *)ch - (char *)c - 16);
          *(v18 - 3) = *(v16 - 5);
          *(v18 - 2) = *(v16 - 4);
        }
        while ( v17 );
        v14 = n;
      }
      if ( v15 < v14 )
      {
        v19 = &c[v15];
        v20 = v14 - v15;
        do
        {
          v21 = *(float *)((char *)v19++ + (char *)ch - (char *)c);
          --v20;
          *(v19 - 1) = v21;
        }
        while ( v20 );
      }
    }
  }
}
