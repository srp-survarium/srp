unsigned __int8 *__cdecl res0_look(vorbis_dsp_state *vd, _DWORD *vr)
{
  unsigned __int8 *v3; // esi
  _DWORD *codec_setup; // edi
  int *v5; // eax
  unsigned __int8 *v6; // eax
  bool v7; // cc
  unsigned int v8; // ecx
  signed int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  void *v14; // eax
  int v15; // edi
  int i; // ecx
  int v17; // ebx
  int v19; // [esp+Ch] [ebp-18h]
  int v20; // [esp+10h] [ebp-14h]
  int v21; // [esp+14h] [ebp-10h]
  signed int v22; // [esp+18h] [ebp-Ch]
  _DWORD *v23; // [esp+1Ch] [ebp-8h]
  int v24; // [esp+20h] [ebp-4h]
  int v25; // [esp+2Ch] [ebp+8h]
  int v26; // [esp+2Ch] [ebp+8h]
  unsigned int *v27; // [esp+30h] [ebp+Ch]
  int v28; // [esp+30h] [ebp+Ch]

  v3 = ogg_calloc_impl(1u, 0x2Cu);
  codec_setup = vd->vi->codec_setup;
  v24 = 0;
  v22 = 0;
  *(_DWORD *)v3 = vr;
  *((_DWORD *)v3 + 1) = vr[3];
  *((_DWORD *)v3 + 3) = codec_setup[712];
  v5 = (int *)(codec_setup[712] + 56 * vr[5]);
  *((_DWORD *)v3 + 4) = v5;
  v21 = *v5;
  v6 = ogg_calloc_impl(*((_DWORD *)v3 + 1), 4u);
  v25 = 0;
  v7 = *((_DWORD *)v3 + 1) <= 0;
  *((_DWORD *)v3 + 5) = v6;
  if ( !v7 )
  {
    v27 = vr + 6;
    do
    {
      v8 = *v27;
      v9 = 0;
      if ( *v27 )
      {
        do
        {
          ++v9;
          v8 >>= 1;
        }
        while ( v8 );
        v19 = v9;
        if ( v9 )
        {
          if ( v9 > v22 )
            v22 = v9;
          *(_DWORD *)(*((_DWORD *)v3 + 5) + 4 * v25) = ogg_calloc_impl(v9, 4u);
          v10 = 0;
          v20 = 0;
          if ( v19 > 0 )
          {
            v23 = &vr[v24 + 70];
            do
            {
              if ( ((1 << v10) & *v27) != 0 )
              {
                v11 = codec_setup[712] + 56 * *v23;
                v10 = v20;
                ++v24;
                ++v23;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 5) + 4 * v25) + 4 * v20) = v11;
              }
              v20 = ++v10;
            }
            while ( v10 < v19 );
          }
        }
      }
      ++v25;
      ++v27;
    }
    while ( v25 < *((_DWORD *)v3 + 1) );
  }
  v12 = v21;
  v13 = 1;
  *((_DWORD *)v3 + 6) = 1;
  if ( v21 > 0 )
  {
    do
    {
      v13 *= *((_DWORD *)v3 + 1);
      --v12;
    }
    while ( v12 );
    *((_DWORD *)v3 + 6) = v13;
  }
  *((_DWORD *)v3 + 2) = v22;
  v14 = ogg_malloc_impl(4 * *((_DWORD *)v3 + 6));
  v15 = 0;
  v7 = *((_DWORD *)v3 + 6) <= 0;
  *((_DWORD *)v3 + 7) = v14;
  if ( !v7 )
  {
    do
    {
      v28 = v15;
      v26 = *((_DWORD *)v3 + 6) / *((_DWORD *)v3 + 1);
      *(_DWORD *)(*((_DWORD *)v3 + 7) + 4 * v15) = ogg_malloc_impl(4 * v21);
      for ( i = 0; i < v21; ++i )
      {
        v17 = v28 / v26;
        v28 %= v26;
        v26 /= *((int *)v3 + 1);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 7) + 4 * v15) + 4 * i) = v17;
      }
      ++v15;
    }
    while ( v15 < *((_DWORD *)v3 + 6) );
  }
  return v3;
}
