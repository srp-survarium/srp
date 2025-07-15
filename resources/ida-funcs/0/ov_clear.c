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
      ogg_free_impl(vf->vi);
      ogg_free_impl(vf->vc);
    }
    if ( vf->dataoffsets )
      ogg_free_impl(vf->dataoffsets);
    if ( vf->pcmlengths )
      ogg_free_impl(vf->pcmlengths);
    if ( vf->serialnos )
      ogg_free_impl(vf->serialnos);
    if ( vf->offsets )
      ogg_free_impl(vf->offsets);
    ogg_sync_clear(&vf->oy);
    if ( vf->datasource && vf->callbacks.close_func )
      vf->callbacks.close_func(vf->datasource);
    memset((int)vf, 0, sizeof(OggVorbis_File));
  }
  return 0;
}
