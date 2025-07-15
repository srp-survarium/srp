void __usercall ov_getlap(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        vorbis_info *vi,
        vorbis_dsp_state *vd,
        float **lappcm,
        int lapsize)
{
  int v6; // [esp+0h] [ebp-18h]
  int n; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int k; // [esp+Ch] [ebp-Ch]
  int j; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  float **pcm; // [esp+14h] [ebp-4h] BYREF

  v11 = 0;
  while ( v11 < lapsize )
  {
    n = vorbis_synthesis_pcmout(vd, &pcm);
    if ( n )
    {
      if ( n > lapsize - v11 )
        n = lapsize - v11;
      for ( i = 0; i < vi->channels; ++i )
        memcpy((unsigned __int8 *)&lappcm[i][v11], (unsigned __int8 *)pcm[i], 4 * n);
      v11 += n;
      vorbis_synthesis_read(vd, n);
    }
    else if ( fetch_and_process_packet(a1, vf, 0, 1, 0) == -2 )
    {
      break;
    }
  }
  if ( v11 < lapsize )
  {
    v6 = vorbis_synthesis_lapout(&vf->vd, &pcm);
    if ( v6 )
    {
      if ( v6 > lapsize - v11 )
        v6 = lapsize - v11;
      for ( j = 0; j < vi->channels; ++j )
        memcpy((unsigned __int8 *)&lappcm[j][v11], (unsigned __int8 *)pcm[j], 4 * v6);
    }
    else
    {
      for ( k = 0; k < vi->channels; ++k )
        memset((int)&lappcm[k][v11], 0, 4 * lapsize - v11);
    }
  }
}
