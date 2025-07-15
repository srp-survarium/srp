int __cdecl ov_read_filter(
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
  int v10; // [esp+8h] [ebp-48h]
  float *v11; // [esp+Ch] [ebp-44h]
  char *v12; // [esp+10h] [ebp-40h]
  float *src; // [esp+14h] [ebp-3Ch]
  __int16 *dest; // [esp+18h] [ebp-38h]
  int v15; // [esp+1Ch] [ebp-34h]
  int val; // [esp+24h] [ebp-2Ch]
  int vala; // [esp+24h] [ebp-2Ch]
  int valb; // [esp+24h] [ebp-2Ch]
  int valc; // [esp+24h] [ebp-2Ch]
  __int16 vald; // [esp+24h] [ebp-2Ch]
  int channels; // [esp+28h] [ebp-28h]
  __int16 fpu; // [esp+2Ch] [ebp-24h] BYREF
  int bytespersample; // [esp+30h] [ebp-20h]
  int ret; // [esp+34h] [ebp-1Ch]
  int j; // [esp+38h] [ebp-18h]
  int host_endian; // [esp+3Ch] [ebp-14h]
  int samples; // [esp+40h] [ebp-10h]
  int i; // [esp+44h] [ebp-Ch]
  int hs; // [esp+48h] [ebp-8h]
  float **pcm; // [esp+4Ch] [ebp-4h] BYREF

  host_endian = host_is_big_endian();
  if ( vf->ready_state < 2 )
    return -131;
  while ( 1 )
  {
    if ( vf->ready_state == 4 )
    {
      samples = vorbis_synthesis_pcmout(&vf->vd, &pcm);
      if ( samples )
        break;
    }
    ret = fetch_and_process_packet(vf, 0, 1, 1);
    if ( ret == -2 )
      return 0;
    if ( ret <= 0 )
      return ret;
  }
  if ( samples <= 0 )
    return samples;
  channels = ov_info(vf, -1)->channels;
  bytespersample = channels * word;
  if ( samples > length / (channels * word) )
    samples = length / bytespersample;
  if ( samples <= 0 )
    return -131;
  if ( filter )
    filter(pcm, channels, samples, filter_param);
  if ( word == 1 )
  {
    vorbis_fpu_setround(&fpu);
    for ( j = 0; j < samples; ++j )
    {
      for ( i = 0; i < channels; ++i )
      {
        val = vorbis_ftoi(pcm[i][j] * 128.0);
        if ( val <= 127 )
        {
          if ( val < -128 )
            LOBYTE(val) = 0x80;
        }
        else
        {
          LOBYTE(val) = 127;
        }
        *buffer++ = (sgned != 0 ? 0 : 0x80) + val;
      }
    }
  }
  else
  {
    v15 = sgned != 0 ? 0 : 0x8000;
    if ( host_endian == bigendianp )
    {
      if ( sgned )
      {
        vorbis_fpu_setround(&fpu);
        for ( i = 0; i < channels; ++i )
        {
          src = pcm[i];
          dest = (__int16 *)&buffer[2 * i];
          for ( j = 0; j < samples; ++j )
          {
            vala = vorbis_ftoi(src[j] * 32768.0);
            if ( vala <= 0x7FFF )
            {
              if ( vala < -32768 )
                LOWORD(vala) = 0x8000;
            }
            else
            {
              LOWORD(vala) = 0x7FFF;
            }
            *dest = vala;
            dest += channels;
          }
        }
      }
      else
      {
        vorbis_fpu_setround(&fpu);
        for ( i = 0; i < channels; ++i )
        {
          v11 = pcm[i];
          v12 = &buffer[2 * i];
          for ( j = 0; j < samples; ++j )
          {
            valb = vorbis_ftoi(v11[j] * 32768.0);
            if ( valb <= 0x7FFF )
            {
              if ( valb < -32768 )
                LOWORD(valb) = 0x8000;
            }
            else
            {
              LOWORD(valb) = 0x7FFF;
            }
            *(_WORD *)v12 = v15 + valb;
            v12 += 2 * channels;
          }
        }
      }
    }
    else if ( bigendianp )
    {
      vorbis_fpu_setround(&fpu);
      for ( j = 0; j < samples; ++j )
      {
        for ( i = 0; i < channels; ++i )
        {
          valc = vorbis_ftoi(pcm[i][j] * 32768.0);
          if ( valc <= 0x7FFF )
          {
            if ( valc < -32768 )
              LOWORD(valc) = 0x8000;
          }
          else
          {
            LOWORD(valc) = 0x7FFF;
          }
          vald = v15 + valc;
          *buffer = HIBYTE(vald);
          buffer[1] = vald;
          buffer += 2;
        }
      }
    }
    else
    {
      vorbis_fpu_setround(&fpu);
      for ( j = 0; j < samples; ++j )
      {
        for ( i = 0; i < channels; ++i )
        {
          v10 = vorbis_ftoi(pcm[i][j] * 32768.0);
          if ( v10 <= 0x7FFF )
          {
            if ( v10 < -32768 )
              LOWORD(v10) = 0x8000;
          }
          else
          {
            LOWORD(v10) = 0x7FFF;
          }
          *(_WORD *)buffer = v15 + v10;
          buffer += 2;
        }
      }
    }
  }
  vorbis_fpu_restore(fpu);
  vorbis_synthesis_read(&vf->vd, samples);
  hs = vorbis_synthesis_halfrate_p(vf->vi);
  vf->pcm_offset += samples << hs;
  if ( bitstream )
    *bitstream = vf->current_link;
  return bytespersample * samples;
}
