int __cdecl ov_initprime(OggVorbis_File *vf)
{
  int ret; // [esp+0h] [ebp-8h]

  while ( vf->ready_state != 4 || !vorbis_synthesis_pcmout(&vf->vd, 0) )
  {
    ret = fetch_and_process_packet(vf, 0, 1, 0);
    if ( ret < 0 && ret != -3 )
      return ret;
  }
  return 0;
}
