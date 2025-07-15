int __usercall ov_read_filter@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        char *buffer,
        int length,
        int bigendianp,
        int word,
        int sgned,
        int *bitstream,
        void (__cdecl *filter)(float **, int, int, void *),
        void *filter_param)
{
  int v11; // [esp+8h] [ebp-48h]
  float *v12; // [esp+Ch] [ebp-44h]
  char *v13; // [esp+10h] [ebp-40h]
  float *v14; // [esp+14h] [ebp-3Ch]
  char *v15; // [esp+18h] [ebp-38h]
  int v16; // [esp+1Ch] [ebp-34h]
  int v17; // [esp+24h] [ebp-2Ch]
  int v18; // [esp+24h] [ebp-2Ch]
  int v19; // [esp+24h] [ebp-2Ch]
  int v20; // [esp+24h] [ebp-2Ch]
  __int16 v21; // [esp+24h] [ebp-2Ch]
  int channels; // [esp+28h] [ebp-28h]
  int v23; // [esp+30h] [ebp-20h]
  int v24; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  int m; // [esp+38h] [ebp-18h]
  int jj; // [esp+38h] [ebp-18h]
  int kk; // [esp+38h] [ebp-18h]
  int nn; // [esp+38h] [ebp-18h]
  int is_big_endian; // [esp+3Ch] [ebp-14h]
  int n; // [esp+40h] [ebp-10h]
  int j; // [esp+44h] [ebp-Ch]
  int k; // [esp+44h] [ebp-Ch]
  int ii; // [esp+44h] [ebp-Ch]
  int mm; // [esp+44h] [ebp-Ch]
  int i1; // [esp+44h] [ebp-Ch]
  float **pcm; // [esp+4Ch] [ebp-4h] BYREF

  is_big_endian = host_is_big_endian();
  if ( vf->ready_state < 2 )
    return -131;
  while ( 1 )
  {
    if ( vf->ready_state == 4 )
    {
      n = vorbis_synthesis_pcmout(&vf->vd, &pcm);
      if ( n )
        break;
    }
    v24 = fetch_and_process_packet(a1, vf, 0, 1, 1);
    if ( v24 == -2 )
      return 0;
    if ( v24 <= 0 )
      return v24;
  }
  if ( n <= 0 )
    return n;
  channels = ov_info(vf, -1)->channels;
  v23 = channels * word;
  if ( n > length / (channels * word) )
    n = length / v23;
  if ( n <= 0 )
    return -131;
  if ( filter )
    filter(pcm, channels, n, filter_param);
  if ( word == 1 )
  {
    vorbis_fpu_setround();
    for ( i = 0; i < n; ++i )
    {
      for ( j = 0; j < channels; ++j )
      {
        v17 = vorbis_ftoi(pcm[j][i] * 128.0);
        if ( v17 <= 127 )
        {
          if ( v17 < -128 )
            LOBYTE(v17) = 0x80;
        }
        else
        {
          LOBYTE(v17) = 127;
        }
        *buffer++ = (sgned != 0 ? 0 : 0x80) + v17;
      }
    }
  }
  else
  {
    v16 = sgned != 0 ? 0 : 0x8000;
    if ( is_big_endian == bigendianp )
    {
      if ( sgned )
      {
        vorbis_fpu_setround();
        for ( k = 0; k < channels; ++k )
        {
          v14 = pcm[k];
          v15 = &buffer[2 * k];
          for ( m = 0; m < n; ++m )
          {
            v18 = vorbis_ftoi(v14[m] * 32768.0);
            if ( v18 <= 0x7FFF )
            {
              if ( v18 < -32768 )
                LOWORD(v18) = 0x8000;
            }
            else
            {
              LOWORD(v18) = 0x7FFF;
            }
            *(_WORD *)v15 = v18;
            v15 += 2 * channels;
          }
        }
      }
      else
      {
        vorbis_fpu_setround();
        for ( ii = 0; ii < channels; ++ii )
        {
          v12 = pcm[ii];
          v13 = &buffer[2 * ii];
          for ( jj = 0; jj < n; ++jj )
          {
            v19 = vorbis_ftoi(v12[jj] * 32768.0);
            if ( v19 <= 0x7FFF )
            {
              if ( v19 < -32768 )
                LOWORD(v19) = 0x8000;
            }
            else
            {
              LOWORD(v19) = 0x7FFF;
            }
            *(_WORD *)v13 = v16 + v19;
            v13 += 2 * channels;
          }
        }
      }
    }
    else if ( bigendianp )
    {
      vorbis_fpu_setround();
      for ( kk = 0; kk < n; ++kk )
      {
        for ( mm = 0; mm < channels; ++mm )
        {
          v20 = vorbis_ftoi(pcm[mm][kk] * 32768.0);
          if ( v20 <= 0x7FFF )
          {
            if ( v20 < -32768 )
              LOWORD(v20) = 0x8000;
          }
          else
          {
            LOWORD(v20) = 0x7FFF;
          }
          v21 = v16 + v20;
          *buffer = HIBYTE(v21);
          buffer[1] = v21;
          buffer += 2;
        }
      }
    }
    else
    {
      vorbis_fpu_setround();
      for ( nn = 0; nn < n; ++nn )
      {
        for ( i1 = 0; i1 < channels; ++i1 )
        {
          v11 = vorbis_ftoi(pcm[i1][nn] * 32768.0);
          if ( v11 <= 0x7FFF )
          {
            if ( v11 < -32768 )
              LOWORD(v11) = 0x8000;
          }
          else
          {
            LOWORD(v11) = 0x7FFF;
          }
          *(_WORD *)buffer = v16 + v11;
          buffer += 2;
        }
      }
    }
  }
  vorbis_fpu_restore();
  vorbis_synthesis_read(&vf->vd, n);
  vf->pcm_offset += n << vorbis_synthesis_halfrate_p(vf->vi);
  if ( bitstream )
    *bitstream = vf->current_link;
  return v23 * n;
}
