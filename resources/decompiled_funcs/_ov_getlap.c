void __cdecl ov_getlap(OggVorbis_File *vf, vorbis_info *vi, vorbis_dsp_state *vd, float **lappcm, int lapsize)
{
  int v5; // [esp+0h] [ebp-18h]
  int samples; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int ia; // [esp+Ch] [ebp-Ch]
  int ib; // [esp+Ch] [ebp-Ch]
  int lapcount; // [esp+10h] [ebp-8h]
  float **pcm; // [esp+14h] [ebp-4h] BYREF

  lapcount = 0;
  while ( lapcount < lapsize )
  {
    samples = vorbis_synthesis_pcmout(vd, &pcm);
    if ( samples )
    {
      if ( samples > lapsize - lapcount )
        samples = lapsize - lapcount;
      for ( i = 0; i < vi->channels; ++i )
        memcpy((unsigned __int8 *)&lappcm[i][lapcount], (unsigned __int8 *)pcm[i], 4 * samples);
      lapcount += samples;
      vorbis_synthesis_read(vd, samples);
    }
    else if ( fetch_and_process_packet(vf, 0, 1, 0) == -2 )
    {
      break;
    }
  }
  if ( lapcount < lapsize )
  {
    v5 = vorbis_synthesis_lapout(&vf->vd, &pcm);
    if ( v5 )
    {
      if ( v5 > lapsize - lapcount )
        v5 = lapsize - lapcount;
      for ( ib = 0; ib < vi->channels; ++ib )
        memcpy((unsigned __int8 *)&lappcm[ib][lapcount], (unsigned __int8 *)pcm[ib], 4 * v5);
    }
    else
    {
      for ( ia = 0; ia < vi->channels; ++ia )
        memset((unsigned __int8 *)&lappcm[ia][lapcount], 0, 4 * lapsize - lapcount);
    }
  }
}
