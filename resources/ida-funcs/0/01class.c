int **__usercall 01class@<eax>(vorbis_block *vb@<eax>, _DWORD *vl, int **in, int ch)
{
  _DWORD *v5; // edi
  int v6; // ebx
  char *v7; // eax
  int v8; // ebx
  int *v9; // esi
  char *v10; // eax
  int *v11; // ecx
  signed int v12; // eax
  int v13; // ecx
  int *v14; // eax
  int v15; // eax
  bool v16; // zf
  float v18; // [esp+Ch] [ebp-34h]
  int v19; // [esp+14h] [ebp-2Ch]
  int v20; // [esp+18h] [ebp-28h]
  int v21; // [esp+1Ch] [ebp-24h]
  int v22; // [esp+20h] [ebp-20h]
  int v23; // [esp+24h] [ebp-1Ch]
  char *i; // [esp+28h] [ebp-18h]
  int v25; // [esp+2Ch] [ebp-14h]
  int v26; // [esp+30h] [ebp-10h]
  int v27; // [esp+34h] [ebp-Ch]
  int v28; // [esp+38h] [ebp-8h]
  int v29; // [esp+3Ch] [ebp-4h]
  int v30; // [esp+3Ch] [ebp-4h]

  v5 = (_DWORD *)*vl;
  v19 = *(_DWORD *)(*vl + 12);
  v20 = *(_DWORD *)(*vl + 8);
  v27 = (v5[1] - *v5) / v20;
  v6 = 0;
  for ( i = _vorbis_block_alloc(vb, 4 * ch); v6 < ch; ++v6 )
  {
    v7 = _vorbis_block_alloc(vb, 4 * v27);
    *(_DWORD *)&i[4 * v6] = v7;
    memset((int)v7, 0, 4 * v27);
  }
  v28 = 0;
  if ( v27 > 0 )
  {
    v25 = 0;
    do
    {
      v8 = v25 + *v5;
      if ( ch > 0 )
      {
        v9 = (int *)i;
        v22 = v19 - 1;
        v10 = (char *)((char *)in - i);
        v21 = ch;
        while ( 1 )
        {
          v26 = 0;
          v29 = 0;
          if ( v20 > 0 )
          {
            v11 = (int *)(*(int *)((char *)v9 + (_DWORD)v10) + 4 * v8);
            v23 = v20;
            do
            {
              v12 = abs32(*v11);
              if ( v12 > v26 )
                v26 = v12;
              v29 += v12;
              ++v11;
              --v23;
            }
            while ( v23 );
          }
          v13 = 0;
          v18 = 100.0 / (double)v20;
          v30 = (int)(float)((float)v29 * v18);
          if ( v22 > 0 )
          {
            v14 = v5 + 646;
            do
            {
              if ( v26 <= *(v14 - 64) && (*v14 < 0 || v30 < *v14) )
                break;
              ++v13;
              ++v14;
            }
            while ( v13 < v22 );
          }
          v15 = *v9++;
          v16 = v21-- == 1;
          *(_DWORD *)(v15 + 4 * v28) = v13;
          if ( v16 )
            break;
          v10 = (char *)((char *)in - i);
        }
      }
      ++v28;
      v25 += v20;
    }
    while ( v28 < v27 );
  }
  ++vl[10];
  return (int **)i;
}
