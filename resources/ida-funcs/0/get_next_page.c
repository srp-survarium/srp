__int64 __cdecl get_next_page(OggVorbis_File *vf, ogg_page *og, __int64 boundary)
{
  __int64 offset; // [esp+8h] [ebp-10h]
  int ret; // [esp+10h] [ebp-8h]
  int more; // [esp+14h] [ebp-4h]

  if ( boundary > 0 )
    boundary += vf->offset;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( boundary > 0 && vf->offset >= boundary )
        return -1;
      more = ogg_sync_pageseek(&vf->oy, og);
      if ( more >= 0 )
        break;
      vf->offset -= more;
    }
    if ( more )
      break;
    if ( !boundary )
      return -1;
    ret = get_data(vf);
    if ( !ret )
      return -2;
    if ( ret < 0 )
      return -128;
  }
  offset = vf->offset;
  vf->offset = offset + more;
  return offset;
}
