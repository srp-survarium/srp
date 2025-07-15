int __cdecl ov_clear(OggVorbis_File *vf)
{
  int i; // [esp+0h] [ebp-4h]

  if ( vf )
  {
    vorbis_block_clear(&vf->vb);
    vorbis_dsp_clear(&vf->vd);
    ogg_stream_clear(&vf->os);
    if ( vf->vi && vf->links )
    {
      for ( i = 0; i < vf->links; ++i )
      {
        vorbis_info_clear(&vf->vi[i]);
        vorbis_comment_clear(&vf->vc[i]);
      }
      free(vf->vi);
      free(vf->vc);
    }
    if ( vf->dataoffsets )
      free(vf->dataoffsets);
    if ( vf->pcmlengths )
      free(vf->pcmlengths);
    if ( vf->serialnos )
      free(vf->serialnos);
    if ( vf->offsets )
      free(vf->offsets);
    ogg_sync_clear(&vf->oy);
    if ( vf->datasource && vf->callbacks.close_func )
      vf->callbacks.close_func(vf->datasource);
    memset((unsigned __int8 *)vf, 0, sizeof(OggVorbis_File));
  }
  return 0;
}
