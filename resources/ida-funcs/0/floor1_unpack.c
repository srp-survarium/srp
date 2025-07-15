unsigned __int8 *__cdecl floor1_unpack(vorbis_info *vi, oggpack_buffer *opb)
{
  _DWORD *codec_setup; // eax
  unsigned __int8 *v3; // edi
  signed int v4; // eax
  signed int *v5; // ebx
  signed int v6; // eax
  unsigned int *v7; // ebx
  signed int v8; // eax
  int v9; // ecx
  signed int v10; // eax
  int v11; // ecx
  bool v12; // cc
  signed int *v13; // ebx
  signed int v14; // eax
  int v15; // esi
  int v16; // edx
  unsigned __int8 *v17; // eax
  signed int v18; // esi
  signed int v19; // ecx
  int v20; // eax
  _DWORD base[65]; // [esp+Ch] [ebp-11Ch] BYREF
  int v24; // [esp+110h] [ebp-18h]
  _DWORD *v25; // [esp+114h] [ebp-14h]
  int v26; // [esp+118h] [ebp-10h]
  int bits; // [esp+11Ch] [ebp-Ch]
  _DWORD *v28; // [esp+120h] [ebp-8h]
  int v29; // [esp+124h] [ebp-4h]
  int v30; // [esp+130h] [ebp+8h]
  int v31; // [esp+130h] [ebp+8h]
  int v32; // [esp+130h] [ebp+8h]

  codec_setup = vi->codec_setup;
  v26 = 0;
  v29 = -1;
  v25 = codec_setup;
  v3 = ogg_calloc_impl(1u, 0x460u);
  v4 = oggpack_read(opb, 5u);
  v30 = 0;
  *(_DWORD *)v3 = v4;
  if ( v4 <= 0 )
  {
LABEL_7:
    v31 = 0;
    v24 = v29 + 1;
    if ( v29 + 1 <= 0 )
    {
LABEL_20:
      *((_DWORD *)v3 + 208) = oggpack_read(opb, 2u) + 1;
      bits = oggpack_read(opb, 4u);
      if ( bits >= 0 )
      {
        v12 = *(_DWORD *)v3 <= 0;
        v32 = 0;
        v29 = 0;
        if ( v12 )
        {
LABEL_30:
          v15 = v26;
          v16 = 1 << bits;
          v17 = v3 + 836;
          *((_DWORD *)v3 + 209) = 0;
          v18 = v15 + 2;
          v19 = 0;
          for ( *((_DWORD *)v3 + 210) = v16; v19 < v18; v17 += 4 )
            base[v19++] = v17;
          qsort((char *)base, v18, 4u, (int (__cdecl *)(const void *, const void *))icomp);
          v20 = 1;
          if ( v18 <= 1 )
            return v3;
          while ( *(_DWORD *)base[v20 - 1] != *(_DWORD *)base[v20] )
          {
            if ( ++v20 >= v18 )
              return v3;
          }
        }
        else
        {
          v28 = v3 + 4;
          while ( 1 )
          {
            v26 += *(_DWORD *)&v3[4 * *v28 + 128];
            if ( v26 > 63 )
              break;
            if ( v29 < v26 )
            {
              v13 = (signed int *)&v3[4 * v29 + 844];
              do
              {
                v14 = oggpack_read(opb, bits);
                *v13 = v14;
                if ( v14 < 0 || v14 >= 1 << bits )
                  goto err_out_4;
                ++v29;
                ++v13;
              }
              while ( v29 < v26 );
            }
            ++v32;
            ++v28;
            if ( v32 >= *(_DWORD *)v3 )
              goto LABEL_30;
          }
        }
      }
    }
    else
    {
      v28 = v3 + 320;
      v7 = (unsigned int *)(v3 + 256);
      while ( 1 )
      {
        *(v7 - 32) = oggpack_read(opb, 3u) + 1;
        v8 = oggpack_read(opb, 2u);
        *(v7 - 16) = v8;
        if ( v8 < 0 )
          break;
        if ( v8 )
          *v7 = oggpack_read(opb, 8u);
        if ( (*v7 & 0x80000000) != 0 || (signed int)*v7 >= v25[6] )
          break;
        v9 = *(v7 - 16);
        v29 = 0;
        if ( 1 << v9 > 0 )
        {
          bits = (int)v28;
          do
          {
            v10 = oggpack_read(opb, 8u) - 1;
            *(_DWORD *)bits = v10;
            if ( v10 < -1 || v10 >= v25[6] )
              goto err_out_4;
            v11 = *(v7 - 16);
            ++v29;
            bits += 4;
          }
          while ( v29 < 1 << v11 );
        }
        ++v31;
        v28 += 8;
        ++v7;
        if ( v31 >= v24 )
          goto LABEL_20;
      }
    }
  }
  else
  {
    v5 = (signed int *)(v3 + 4);
    while ( 1 )
    {
      v6 = oggpack_read(opb, 4u);
      *v5 = v6;
      if ( v6 < 0 )
        break;
      if ( v29 < v6 )
        v29 = v6;
      ++v30;
      ++v5;
      if ( v30 >= *(_DWORD *)v3 )
        goto LABEL_7;
    }
  }
err_out_4:
  floor1_free_info(v3);
  return 0;
}
