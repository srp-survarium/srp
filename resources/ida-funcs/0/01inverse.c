int __cdecl 01inverse(
        vorbis_block *vb,
        _DWORD **vl,
        float **in,
        int ch,
        int (__cdecl *decodepart)(codebook *, float *, oggpack_buffer *, int))
{
  _DWORD *v6; // edi
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  void *v12; // esp
  bool v13; // cc
  int v14; // eax
  int v15; // edx
  int v16; // eax
  _DWORD *v17; // esi
  int v18; // ecx
  codebook *v19; // ecx
  _DWORD v21[3]; // [esp+0h] [ebp-38h] BYREF
  char *v22; // [esp+Ch] [ebp-2Ch]
  int v23; // [esp+10h] [ebp-28h]
  int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+18h] [ebp-20h]
  int v26; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v27; // [esp+20h] [ebp-18h]
  int v28; // [esp+24h] [ebp-14h]
  int v29; // [esp+28h] [ebp-10h]
  int v30; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  int v32; // [esp+34h] [ebp-4h]
  int v33; // [esp+44h] [ebp+Ch]
  int v34; // [esp+44h] [ebp+Ch]
  int v35; // [esp+44h] [ebp+Ch]

  v6 = *vl;
  v7 = (*vl)[1];
  v30 = (*vl)[2];
  v8 = *vl[4];
  v9 = vb->pcmend >> 1;
  if ( v7 < v9 )
    v9 = v7;
  v10 = v9 - *v6;
  v23 = *vl[4];
  if ( v10 > 0 )
  {
    v24 = v10 / v30;
    v11 = (v10 / v30 + v8 - 1) / v8;
    v12 = alloca(4 * ch);
    v27 = v21;
    v33 = 0;
    if ( ch > 0 )
    {
      v25 = 4 * v11;
      do
        v21[v33++] = _vorbis_block_alloc(vb, v25);
      while ( v33 < ch );
    }
    v13 = (int)vl[2] <= 0;
    v32 = 0;
    if ( !v13 )
    {
      while ( 1 )
      {
        v31 = 0;
        if ( v24 > 0 )
          break;
LABEL_27:
        if ( ++v32 >= (int)vl[2] )
          return 0;
      }
      v28 = 0;
      while ( 1 )
      {
        if ( !v32 )
        {
          v34 = 0;
          if ( ch > 0 )
            break;
        }
LABEL_16:
        v29 = 0;
        if ( v23 > 0 )
        {
          v25 = v30 * v31;
          while ( v31 < v24 )
          {
            v35 = 0;
            if ( ch > 0 )
            {
              v17 = v27;
              v26 = 1 << v32;
              v22 = (char *)((char *)in - (char *)v27);
              do
              {
                v18 = *(_DWORD *)(*(_DWORD *)(v28 + *v17) + 4 * v29);
                if ( (v26 & v6[v18 + 6]) != 0 )
                {
                  v19 = *(codebook **)(vl[5][v18] + 4 * v32);
                  if ( v19 )
                  {
                    if ( decodepart(
                           v19,
                           (float *)(*(_DWORD *)((char *)v17 + (_DWORD)v22) + 4 * (v25 + *v6)),
                           &vb->opb,
                           v30) == -1 )
                      return 0;
                  }
                }
                ++v35;
                ++v17;
              }
              while ( v35 < ch );
            }
            ++v29;
            v25 += v30;
            ++v31;
            if ( v29 >= v23 )
              break;
          }
        }
        v28 += 4;
        if ( v31 >= v24 )
          goto LABEL_27;
      }
      while ( 1 )
      {
        v14 = vorbis_book_decode((codebook *)vl[4], &vb->opb);
        if ( v14 == -1 )
          break;
        if ( v14 >= v6[4] )
          break;
        v15 = v34;
        v16 = vl[7][v14];
        *(_DWORD *)(v28 + v27[v34]) = v16;
        if ( !v16 )
          break;
        ++v34;
        if ( v15 + 1 >= ch )
          goto LABEL_16;
      }
    }
  }
  return 0;
}
