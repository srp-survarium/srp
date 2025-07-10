int __cdecl seek_helper(OggVorbis_File *vf, __int64 offset)
{
  if ( !vf->datasource )
    return -129;
  if ( !vf->callbacks.seek_func
    || ((int (__cdecl *)(void *, _DWORD, _DWORD, _DWORD))vf->callbacks.seek_func)(
         vf->datasource,
         offset,
         HIDWORD(offset),
         0) == -1 )
  {
    return -128;
  }
  vf->offset = offset;
  ogg_sync_reset(&vf->oy);
  return 0;
}
