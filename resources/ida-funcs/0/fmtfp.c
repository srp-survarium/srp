void __fastcall fmtfp(
        const __m128i **sbuffer,
        char **buffer,
        unsigned int *currlen,
        unsigned int *maxlen,
        double fvalue,
        int min,
        int max,
        char flags)
{
  double v10; // st7
  int v11; // ebp
  int v12; // eax
  double v13; // st6
  double i; // st5
  int j; // eax
  double v16; // st6
  int v17; // ecx
  int v18; // edx
  int v19; // ebp
  int v20; // ebp
  char v21; // dl
  char v22; // dl
  int v23; // ebp
  int v24; // [esp+10h] [ebp-44h]
  int v25; // [esp+14h] [ebp-40h]
  int v26; // [esp+1Ch] [ebp-38h]
  int v27; // [esp+1Ch] [ebp-38h]
  int v28; // [esp+20h] [ebp-34h]
  _DWORD v29[11]; // [esp+24h] [ebp-30h]

  v28 = 0;
  v25 = 0;
  v24 = 0;
  if ( max < 0 )
    max = 6;
  if ( fvalue >= 0.0 )
  {
    v10 = fvalue;
    if ( (flags & 2) != 0 )
    {
      v28 = 43;
    }
    else if ( (flags & 4) != 0 )
    {
      v28 = 32;
    }
  }
  else
  {
    v28 = 45;
    v10 = -fvalue;
  }
  v11 = (int)v10;
  v12 = max;
  v29[0] = (int)v10;
  if ( max > 9 )
  {
    max = 9;
    v12 = 9;
  }
  v13 = 1.0;
  for ( i = 1.0; v12; i = i * 10.0 )
    --v12;
  v26 = (int)i;
  if ( i - (double)(int)i >= 0.5 )
    ++v26;
  for ( j = max; j; v13 = v13 * 10.0 )
    --j;
  v16 = v13 * (v10 - (double)v29[0]);
  v17 = (int)v16;
  v29[0] = (int)v16;
  if ( v16 - (double)(int)v16 >= 0.5 )
    ++v17;
  if ( v17 >= v26 )
  {
    ++v11;
    v17 -= v26;
  }
  do
  {
    *((_BYTE *)&v29[1] + v25) = a0123456789abcd_3[v11 % 10];
    v18 = v25 + 1;
    v11 /= 10;
    ++v25;
  }
  while ( v11 && v18 < 20 );
  if ( v18 == 20 )
  {
    v25 = 19;
    v18 = 19;
  }
  *((_BYTE *)&v29[1] + v18) = 0;
  do
  {
    *((_BYTE *)&v29[6] + v24) = a0123456789abcd_3[v17 % 10];
    v19 = v24 + 1;
    v24 = v19;
    v17 /= 10;
  }
  while ( v19 < max );
  if ( v19 == 20 )
    v24 = 19;
  *((_BYTE *)&v29[6] + v24) = 0;
  v20 = min - (v28 != 0) - v25 - max - 1;
  v27 = max - v24;
  if ( max - v24 < 0 )
    v27 = 0;
  if ( v20 < 0 )
    v20 = 0;
  if ( (flags & 1) != 0 )
    v20 = -v20;
  if ( (flags & 0x10) != 0 )
  {
    if ( v20 > 0 )
    {
      if ( v28 )
      {
        doapr_outch(sbuffer, buffer, maxlen, currlen, v28);
        --v20;
        v28 = 0;
      }
      for ( ; v20 > 0; --v20 )
        doapr_outch(sbuffer, buffer, maxlen, currlen, 48);
    }
  }
  else
  {
    for ( ; v20 > 0; --v20 )
      doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
  }
  if ( v28 )
    doapr_outch(sbuffer, buffer, maxlen, currlen, v28);
  while ( v25 > 0 )
  {
    v21 = *((_BYTE *)v29 + v25-- + 3);
    doapr_outch(sbuffer, buffer, maxlen, currlen, v21);
  }
  if ( max > 0 || (flags & 8) != 0 )
  {
    doapr_outch(sbuffer, buffer, maxlen, currlen, 46);
    while ( v24 > 0 )
    {
      v22 = *((_BYTE *)&v29[5] + v24-- + 3);
      doapr_outch(sbuffer, buffer, maxlen, currlen, v22);
    }
  }
  for ( ; v27 > 0; --v27 )
    doapr_outch(sbuffer, buffer, maxlen, currlen, 48);
  if ( v20 < 0 )
  {
    v23 = -v20;
    do
    {
      doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
      --v23;
    }
    while ( v23 );
  }
}
