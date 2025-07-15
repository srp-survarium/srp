int __cdecl floor1_inverse2(vorbis_block *vb, _DWORD *in, _DWORD *memo, float *out)
{
  __int64 v4; // rax
  _DWORD *v5; // edx
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // esi
  int v11; // ecx
  float *v12; // eax
  float *v13; // edx
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]
  _DWORD *v18; // [esp+20h] [ebp+8h]

  v4 = *((int *)vb->vd->vi->codec_setup + vb->W);
  LODWORD(v4) = v4 - HIDWORD(v4);
  v5 = memo;
  v6 = (int)v4 >> 1;
  v7 = in[324];
  if ( memo )
  {
    v8 = *memo * *(_DWORD *)(v7 + 832);
    v16 = 0;
    v15 = 0;
    if ( v8 >= 0 )
    {
      if ( v8 > 255 )
        v8 = 255;
    }
    else
    {
      v8 = 0;
    }
    v17 = 1;
    if ( (int)in[321] > 1 )
    {
      v18 = in + 66;
      while ( 1 )
      {
        v9 = v5[*v18];
        if ( (v9 & 0x7FFF) == v9 )
        {
          v10 = (v9 & 0x7FFF) * *(_DWORD *)(v7 + 832);
          v16 = *(_DWORD *)(v7 + 4 * *v18 + 836);
          if ( v10 >= 0 )
          {
            if ( v10 > 255 )
              v10 = 255;
          }
          else
          {
            v10 = 0;
          }
          render_line(v10, v6, v15, *(_DWORD *)(v7 + 4 * *v18 + 836), v8, out);
          v15 = v16;
          v8 = v10;
        }
        ++v17;
        ++v18;
        if ( v17 >= in[321] )
          break;
        v5 = memo;
      }
    }
    v11 = v16;
    if ( v16 < v6 )
    {
      v12 = (float *)&FLOOR1_fromdB_LOOKUP[v8];
      do
      {
        v13 = &out[v11++];
        *v13 = *v12 * *v13;
      }
      while ( v11 < v6 );
    }
    return 1;
  }
  else
  {
    memset((int)out, 0, 4 * v6);
    return 0;
  }
}
