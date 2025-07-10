int __cdecl floor1_inverse2(vorbis_block *vb, _DWORD *in, _DWORD *memo, float *out)
{
  __int64 v4; // rax
  int v5; // ebp
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // ecx
  int v11; // esi
  int v12; // esi
  int v13; // esi
  unsigned int v14; // edx
  float *v15; // eax
  int lx; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]
  vorbis_block *vba; // [esp+1Ch] [ebp+4h]

  v4 = *((int *)vb->vd->vi->codec_setup + vb->W);
  v5 = in[324];
  v6 = v4 - HIDWORD(v4);
  v7 = memo;
  v8 = 0;
  v9 = v6 >> 1;
  if ( memo )
  {
    v10 = *memo * *(_DWORD *)(v5 + 832);
    lx = 0;
    if ( v10 >= 0 )
    {
      if ( v10 > 255 )
        v10 = 255;
    }
    else
    {
      v10 = 0;
    }
    j = 1;
    if ( (int)in[321] > 1 )
    {
      vba = (vorbis_block *)(in + 66);
      while ( 1 )
      {
        v11 = v7[(int)vba->pcm];
        if ( (v11 & 0x7FFF) == v11 )
        {
          v8 = *(_DWORD *)(v5 + 4 * (int)vba->pcm + 836);
          v12 = (v11 & 0x7FFF) * *(_DWORD *)(v5 + 832);
          if ( v12 >= 0 )
          {
            if ( v12 > 255 )
              v12 = 255;
          }
          else
          {
            v12 = 0;
          }
          render_line(v9, lx, v8, v10, out);
          lx = v8;
          v10 = v12;
        }
        vba = (vorbis_block *)((char *)vba + 4);
        if ( ++j >= in[321] )
          break;
        v7 = memo;
      }
    }
    v13 = v8;
    if ( v8 < v9 )
    {
      if ( v9 - v8 >= 4 )
      {
        v14 = ((unsigned int)(v9 - v8 - 4) >> 2) + 1;
        v15 = &out[v8 + 2];
        v13 = v8 + 4 * v14;
        do
        {
          v15 += 4;
          --v14;
          *(v15 - 6) = FLOOR1_fromdB_LOOKUP[v10] * *(v15 - 6);
          *(v15 - 5) = FLOOR1_fromdB_LOOKUP[v10] * *(v15 - 5);
          *(v15 - 4) = FLOOR1_fromdB_LOOKUP[v10] * *(v15 - 4);
          *(v15 - 3) = *(v15 - 3) * FLOOR1_fromdB_LOOKUP[v10];
        }
        while ( v14 );
      }
      for ( ; v13 < v9; out[v13 - 1] = FLOOR1_fromdB_LOOKUP[v10] * out[v13 - 1] )
        ++v13;
    }
    return 1;
  }
  else
  {
    memset((int)out, 0, 4 * v9);
    return 0;
  }
}
