void __fastcall fmtint(
        unsigned int *currlen,
        unsigned int *maxlen,
        const __m128i **sbuffer,
        char **buffer,
        __int64 value,
        unsigned int base,
        int min,
        int max,
        char flags)
{
  int v9; // ebp
  unsigned __int64 v10; // rax
  unsigned int v11; // ecx
  const char *v12; // esi
  unsigned __int64 v13; // rcx
  int v14; // ebx
  int v15; // esi
  int v16; // ecx
  int v17; // eax
  char v18; // al
  char v19; // al
  int v20; // ebp
  unsigned __int64 v21; // [esp-10h] [ebp-60h]
  int v22; // [esp+10h] [ebp-40h]
  int v23; // [esp+10h] [ebp-40h]
  int v24; // [esp+14h] [ebp-3Ch]
  const char *v26; // [esp+24h] [ebp-2Ch]
  _DWORD v28[8]; // [esp+2Ch] [ebp-24h]

  v9 = 0;
  v28[0] = 0;
  v26 = uri;
  v22 = 0;
  if ( max < 0 )
    max = 0;
  v11 = HIDWORD(value);
  LODWORD(v10) = value;
  if ( (flags & 0x40) == 0 )
  {
    if ( value >= 0 )
    {
      if ( (flags & 2) != 0 )
      {
        v28[0] = 43;
      }
      else if ( (flags & 4) != 0 )
      {
        v28[0] = 32;
      }
    }
    else
    {
      LODWORD(v10) = -(int)value;
      v28[0] = 45;
      v11 = (unsigned __int64)-value >> 32;
    }
  }
  if ( (flags & 8) != 0 )
  {
    if ( base == 8 )
    {
      v26 = "0";
    }
    else if ( base == 16 )
    {
      v26 = "0x";
    }
  }
  if ( (flags & 0x20) != 0 )
    v22 = 1;
  do
  {
    v12 = "0123456789ABCDEF";
    if ( !v22 )
      v12 = "0123456789abcdef";
    v21 = __PAIR64__(v11, v10);
    v13 = __PAIR64__(v11, v10) % base;
    v10 = v21 / base;
    *((_BYTE *)&v28[1] + v9) = v12[v13];
    v11 = HIDWORD(v10);
    ++v9;
  }
  while ( v10 && v9 < 26 );
  if ( v9 == 26 )
    v9 = 25;
  *((_BYTE *)&v28[1] + v9) = 0;
  v23 = max - v9;
  v14 = max;
  if ( max < v9 )
    v14 = v9;
  v15 = v28[0];
  v16 = min - (v28[0] != 0) - strlen(v26) - v14;
  v24 = v16;
  if ( v23 < 0 )
    v23 = 0;
  if ( v16 < 0 )
  {
    v24 = 0;
    v16 = 0;
  }
  if ( (flags & 0x10) != 0 )
  {
    if ( v23 < v16 )
      v23 = v16;
    v24 = 0;
    v16 = 0;
  }
  if ( (flags & 1) != 0 )
  {
    v16 = -v16;
    v24 = v16;
  }
  if ( v16 > 0 )
  {
    do
    {
      doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
      v17 = v24 - 1;
      v24 = v17;
    }
    while ( v17 > 0 );
    v15 = v28[0];
    v16 = v17;
  }
  if ( v15 )
  {
    doapr_outch(sbuffer, buffer, maxlen, currlen, v15);
    v16 = v24;
  }
  v18 = *v26;
  if ( *v26 )
  {
    do
    {
      doapr_outch(sbuffer, buffer, maxlen, currlen, v18);
      v18 = *++v26;
    }
    while ( *v26 );
    v16 = v24;
  }
  if ( v23 > 0 )
  {
    do
    {
      doapr_outch(sbuffer, buffer, maxlen, currlen, 48);
      --v23;
    }
    while ( v23 > 0 );
    v16 = v24;
  }
  if ( v9 > 0 )
  {
    do
    {
      v19 = *((_BYTE *)v28 + v9-- + 3);
      doapr_outch(sbuffer, buffer, maxlen, currlen, v19);
    }
    while ( v9 > 0 );
    v16 = v24;
  }
  if ( v16 < 0 )
  {
    v20 = -v16;
    do
    {
      doapr_outch(sbuffer, buffer, maxlen, currlen, 32);
      --v20;
    }
    while ( v20 );
  }
}
