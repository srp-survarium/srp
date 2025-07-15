int __usercall vorbis_unpack_books@<eax>(oggpack_buffer *opb@<eax>, __int128 a2@<xmm0>, vorbis_info *vi)
{
  _DWORD *codec_setup; // ebx
  signed int v6; // eax
  static_codebook **v7; // edi
  static_codebook *v8; // eax
  signed int v9; // edi
  signed int v10; // eax
  _DWORD *v11; // edi
  unsigned int v12; // eax
  void *v13; // eax
  signed int v14; // eax
  _DWORD *v15; // edi
  unsigned int v16; // eax
  void *v17; // eax
  signed int v18; // eax
  _DWORD *v19; // edi
  unsigned int v20; // eax
  void *v21; // eax
  signed int v22; // eax
  unsigned __int8 **v23; // edi
  unsigned __int8 *v24; // eax
  int v25; // eax
  int v26; // [esp+8h] [ebp-4h]
  int v27; // [esp+8h] [ebp-4h]
  int v28; // [esp+8h] [ebp-4h]
  int v29; // [esp+8h] [ebp-4h]
  int v30; // [esp+8h] [ebp-4h]
  int v31; // [esp+8h] [ebp-4h]

  codec_setup = vi->codec_setup;
  if ( !codec_setup )
    return -129;
  v6 = oggpack_read(opb, 8u) + 1;
  codec_setup[6] = v6;
  if ( v6 > 0 )
  {
    v26 = 0;
    v7 = (static_codebook **)(codec_setup + 456);
    while ( 1 )
    {
      v8 = vorbis_staticbook_unpack(opb, a2);
      *v7 = v8;
      if ( !v8 )
        break;
      ++v26;
      ++v7;
      if ( v26 >= codec_setup[6] )
      {
        v9 = oggpack_read(opb, 6u) + 1;
        if ( v9 > 0 )
        {
          v27 = 0;
          while ( !oggpack_read(opb, 0x10u) )
          {
            if ( ++v27 >= v9 )
            {
              v10 = oggpack_read(opb, 6u) + 1;
              codec_setup[4] = v10;
              if ( v10 > 0 )
              {
                v28 = 0;
                v11 = codec_setup + 264;
                while ( 1 )
                {
                  v12 = oggpack_read(opb, 0x10u);
                  *(v11 - 64) = v12;
                  if ( v12 > 1 )
                    break;
                  v13 = _floor_P[v12]->unpack(vi, opb);
                  *v11 = v13;
                  if ( !v13 )
                    break;
                  ++v28;
                  ++v11;
                  if ( v28 >= codec_setup[4] )
                  {
                    v14 = oggpack_read(opb, 6u) + 1;
                    codec_setup[5] = v14;
                    if ( v14 > 0 )
                    {
                      v29 = 0;
                      v15 = codec_setup + 392;
                      while ( 1 )
                      {
                        v16 = oggpack_read(opb, 0x10u);
                        *(v15 - 64) = v16;
                        if ( v16 > 2 )
                          break;
                        v17 = _residue_P[v16]->unpack(vi, opb);
                        *v15 = v17;
                        if ( !v17 )
                          break;
                        ++v29;
                        ++v15;
                        if ( v29 >= codec_setup[5] )
                        {
                          v18 = oggpack_read(opb, 6u) + 1;
                          codec_setup[3] = v18;
                          if ( v18 > 0 )
                          {
                            v30 = 0;
                            v19 = codec_setup + 136;
                            while ( 1 )
                            {
                              v20 = oggpack_read(opb, 0x10u);
                              *(v19 - 64) = v20;
                              if ( v20 )
                                break;
                              v21 = _mapping_P[0]->unpack(vi, opb);
                              *v19 = v21;
                              if ( !v21 )
                                break;
                              ++v30;
                              ++v19;
                              if ( v30 >= codec_setup[3] )
                              {
                                v22 = oggpack_read(opb, 6u) + 1;
                                codec_setup[2] = v22;
                                if ( v22 > 0 )
                                {
                                  v31 = 0;
                                  v23 = (unsigned __int8 **)(codec_setup + 8);
                                  while ( 1 )
                                  {
                                    *v23 = ogg_calloc_impl(1u, 0x10u);
                                    *(_DWORD *)*v23 = oggpack_read(opb, 1u);
                                    *((_DWORD *)*v23 + 1) = oggpack_read(opb, 0x10u);
                                    *((_DWORD *)*v23 + 2) = oggpack_read(opb, 0x10u);
                                    *((_DWORD *)*v23 + 3) = oggpack_read(opb, 8u);
                                    v24 = *v23;
                                    if ( *((int *)*v23 + 1) >= 1 )
                                      break;
                                    if ( *((int *)v24 + 2) >= 1 )
                                      break;
                                    v25 = *((_DWORD *)v24 + 3);
                                    if ( v25 >= codec_setup[3] || v25 < 0 )
                                      break;
                                    ++v31;
                                    ++v23;
                                    if ( v31 >= codec_setup[2] )
                                    {
                                      if ( oggpack_read(opb, 1u) != 1 )
                                        goto err_out_1;
                                      return 0;
                                    }
                                  }
                                }
                                goto err_out_1;
                              }
                            }
                          }
                          goto err_out_1;
                        }
                      }
                    }
                    goto err_out_1;
                  }
                }
              }
              goto err_out_1;
            }
          }
        }
        break;
      }
    }
  }
err_out_1:
  vorbis_info_clear(vi);
  return -133;
}
