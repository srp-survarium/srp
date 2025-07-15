unsigned __int8 *__cdecl floor1_look(vorbis_dsp_state *vd, int *in)
{
  unsigned __int8 *v3; // esi
  int v4; // ecx
  int v5; // edi
  _DWORD *v6; // eax
  signed int v7; // edi
  signed int v8; // eax
  _DWORD *v9; // ecx
  signed int v10; // eax
  int *v11; // ecx
  signed int v12; // eax
  _DWORD *v13; // ecx
  signed int i; // eax
  int v15; // edi
  int *v16; // ecx
  _DWORD *v17; // eax
  int v18; // edi
  int v19; // edx
  _DWORD base[65]; // [esp+Ch] [ebp-120h] BYREF
  int v22; // [esp+110h] [ebp-1Ch]
  int v23; // [esp+114h] [ebp-18h]
  int v24; // [esp+118h] [ebp-14h]
  int v25; // [esp+11Ch] [ebp-10h]
  int v26; // [esp+120h] [ebp-Ch]
  int *v27; // [esp+124h] [ebp-8h]
  int v28; // [esp+128h] [ebp-4h]
  int v29; // [esp+138h] [ebp+Ch]

  v3 = ogg_calloc_impl(1u, 0x520u);
  *((_DWORD *)v3 + 324) = in;
  *((_DWORD *)v3 + 322) = in[210];
  v4 = *in;
  v5 = 0;
  if ( *in > 0 )
  {
    v6 = in + 1;
    do
    {
      v5 += in[*v6++ + 32];
      --v4;
    }
    while ( v4 );
  }
  v7 = v5 + 2;
  v8 = 0;
  *((_DWORD *)v3 + 321) = v7;
  if ( v7 > 0 )
  {
    v9 = in + 209;
    do
      base[v8++] = v9++;
    while ( v8 < v7 );
  }
  qsort((char *)base, v7, 4u, (int (__cdecl *)(const void *, const void *))icomp);
  v10 = 0;
  if ( v7 > 0 )
  {
    v11 = (int *)(v3 + 260);
    do
      *v11++ = (base[v10++] - (int)in - 836) >> 2;
    while ( v10 < v7 );
  }
  v12 = 0;
  if ( v7 > 0 )
  {
    v13 = v3 + 260;
    do
      *(_DWORD *)&v3[4 * *v13++ + 520] = v12++;
    while ( v12 < v7 );
  }
  for ( i = 0; i < v7; ++i )
    *(_DWORD *)&v3[4 * i] = in[*(_DWORD *)&v3[4 * i + 260] + 209];
  switch ( in[208] )
  {
    case 1:
      *((_DWORD *)v3 + 323) = 256;
      break;
    case 2:
      *((_DWORD *)v3 + 323) = 128;
      break;
    case 3:
      *((_DWORD *)v3 + 323) = 86;
      break;
    case 4:
      *((_DWORD *)v3 + 323) = 64;
      break;
  }
  v15 = v7 - 2;
  if ( v15 > 0 )
  {
    v28 = 2;
    v16 = (int *)(v3 + 780);
    v17 = in + 211;
    v23 = v15;
    do
    {
      v18 = *((_DWORD *)v3 + 322);
      v22 = 0;
      v25 = 1;
      v24 = 0;
      v26 = v18;
      v29 = 0;
      if ( v28 > 0 )
      {
        v27 = in + 209;
        do
        {
          v19 = *v27;
          if ( *v27 > v24 && v19 < *v17 )
          {
            v22 = v29;
            v24 = v19;
          }
          if ( v19 < v26 && v19 > *v17 )
          {
            v25 = v29;
            v26 = v19;
          }
          ++v29;
          ++v27;
        }
        while ( v29 < v28 );
      }
      v16[63] = v22;
      *v16 = v25;
      ++v17;
      ++v16;
      ++v28;
      --v23;
    }
    while ( v23 );
  }
  return v3;
}
