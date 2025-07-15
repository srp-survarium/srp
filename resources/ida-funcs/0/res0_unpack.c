unsigned __int8 *__cdecl res0_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  unsigned __int8 *v2; // edi
  _DWORD *codec_setup; // ebx
  signed int v4; // eax
  unsigned int v5; // ebx
  signed int v6; // eax
  signed int v7; // eax
  int i; // eax
  signed int v9; // eax
  signed int *v10; // ecx
  int v11; // eax
  _DWORD *v12; // edx
  int *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  _DWORD *v18; // [esp+Ch] [ebp-Ch]
  unsigned int *v19; // [esp+10h] [ebp-8h]
  unsigned __int8 *v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  int v22; // [esp+20h] [ebp+8h]
  int v23; // [esp+20h] [ebp+8h]
  int v24; // [esp+20h] [ebp+8h]

  v21 = 0;
  v2 = ogg_calloc_impl(1u, 0xB18u);
  codec_setup = vi->codec_setup;
  v18 = codec_setup;
  *(_DWORD *)v2 = oggpack_read(opb, 0x18u);
  *((_DWORD *)v2 + 1) = oggpack_read(opb, 0x18u);
  *((_DWORD *)v2 + 2) = oggpack_read(opb, 0x18u) + 1;
  *((_DWORD *)v2 + 3) = oggpack_read(opb, 6u) + 1;
  v4 = oggpack_read(opb, 8u);
  *((_DWORD *)v2 + 5) = v4;
  if ( v4 >= 0 )
  {
    v22 = 0;
    if ( *((int *)v2 + 3) <= 0 )
    {
LABEL_12:
      v23 = 0;
      if ( v21 <= 0 )
      {
LABEL_16:
        v11 = *((_DWORD *)v2 + 5);
        if ( v11 < codec_setup[6] )
        {
          v24 = 0;
          if ( v21 <= 0 )
          {
LABEL_22:
            v13 = (int *)codec_setup[v11 + 456];
            v14 = v13[1];
            v15 = *v13;
            v16 = 1;
            if ( v15 >= 1 )
            {
              while ( 1 )
              {
                v16 *= *((_DWORD *)v2 + 3);
                if ( v16 > v14 )
                  break;
                if ( --v15 <= 0 )
                {
                  *((_DWORD *)v2 + 4) = v16;
                  return v2;
                }
              }
            }
          }
          else
          {
            v12 = v2 + 280;
            while ( *v12 < codec_setup[6] && *(_DWORD *)(codec_setup[*v12 + 456] + 12) )
            {
              ++v24;
              ++v12;
              if ( v24 >= v21 )
                goto LABEL_22;
            }
          }
        }
      }
      else
      {
        v20 = v2 + 280;
        while ( 1 )
        {
          v9 = oggpack_read(opb, 8u);
          if ( v9 < 0 )
            break;
          v10 = (signed int *)v20;
          ++v23;
          v20 += 4;
          *v10 = v9;
          if ( v23 >= v21 )
            goto LABEL_16;
        }
      }
    }
    else
    {
      v19 = (unsigned int *)(v2 + 24);
      while ( 1 )
      {
        v5 = oggpack_read(opb, 3u);
        v6 = oggpack_read(opb, 1u);
        if ( v6 < 0 )
          break;
        if ( v6 )
        {
          v7 = oggpack_read(opb, 5u);
          if ( v7 < 0 )
            break;
          v5 |= 8 * v7;
        }
        *v19 = v5;
        for ( i = 0; v5; v5 >>= 1 )
          i += v5 & 1;
        v21 += i;
        ++v22;
        ++v19;
        if ( v22 >= *((_DWORD *)v2 + 3) )
        {
          codec_setup = v18;
          goto LABEL_12;
        }
      }
    }
  }
  res0_free_info(v2);
  return 0;
}
