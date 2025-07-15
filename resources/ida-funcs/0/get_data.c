int __cdecl get_data(OggVorbis_File *vf)
{
  char *v2; // [esp+0h] [ebp-8h]
  int bytes; // [esp+4h] [ebp-4h]

  *_errno() = 0;
  if ( !vf->callbacks.read_func )
    return -1;
  if ( !vf->datasource )
    return 0;
  v2 = ogg_sync_buffer(&vf->oy, 2048);
  bytes = vf->callbacks.read_func(v2, 1u, 2048u, vf->datasource);
  if ( bytes > 0 )
    ogg_sync_wrote(&vf->oy, bytes);
  if ( bytes || !*_errno() )
    return bytes;
  else
    return -1;
}
