void __usercall drftf1(float *wa@<edi>, int *ifac@<edx>, int n, float *c, float *ch)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // esi
  int v9; // ecx
  float *v10; // ecx
  float *v11; // eax
  bool v12; // zf
  int v13; // edx
  float *v14; // eax
  int v15; // [esp-14h] [ebp-34h]
  float *v16; // [esp-8h] [ebp-28h]
  float *v17; // [esp-4h] [ebp-24h]
  float *v18; // [esp-4h] [ebp-24h]
  float *v19; // [esp-4h] [ebp-24h]
  int v20; // [esp+Ch] [ebp-14h]
  int v21; // [esp+10h] [ebp-10h]
  int *v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h]
  int v24; // [esp+1Ch] [ebp-4h]

  v5 = ifac[1];
  v6 = n;
  v20 = 1;
  v7 = n;
  if ( v5 > 0 )
  {
    v22 = &ifac[v5 + 1];
    v24 = ifac[1];
    do
    {
      v8 = *v22;
      v21 = v7 / *v22;
      v9 = n / v7;
      v23 = v21 * v9;
      v6 -= v9 * (*v22 - 1);
      v20 = 1 - v20;
      if ( *v22 == 4 )
      {
        v19 = &wa[v9 - 1 + v6 + v9];
        v16 = &wa[v9 - 1 + v6];
        v15 = v9;
        if ( v20 )
        {
          v10 = c;
          v11 = ch;
        }
        else
        {
          v10 = ch;
          v11 = c;
        }
        dradf4(v11, v10, v15, v21, &wa[v6 - 1], v16, v19);
      }
      else if ( v8 == 2 )
      {
        v18 = &wa[v6 - 1];
        if ( v20 )
          dradf2(v9, ch, v21, c, v18);
        else
          dradf2(v9, c, v21, ch, v18);
      }
      else
      {
        if ( v9 == 1 )
          v20 = 1 - v20;
        v17 = &wa[v6 - 1];
        if ( v20 )
        {
          dradfg(v9, c, v6, (unsigned int)wa, v8, v21, v23, ch, ch, ch, c, v17);
          v20 = 0;
        }
        else
        {
          dradfg(v9, ch, v6, (unsigned int)wa, v8, v21, v23, c, c, c, ch, v17);
          v20 = 1;
        }
      }
      --v22;
      v12 = v24-- == 1;
      v7 = v21;
    }
    while ( !v12 );
    if ( v20 != 1 )
    {
      v13 = n;
      if ( n > 0 )
      {
        v14 = c;
        do
        {
          *v14 = *(float *)((char *)v14 + (char *)ch - (char *)c);
          ++v14;
          --v13;
        }
        while ( v13 );
      }
    }
  }
}
