__int64 __cdecl get_next_page(OggVorbis_File *vf, ogg_page *og, __int64 boundary)
{
  __int64 offset; // [esp+8h] [ebp-10h]
  int data; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  if ( boundary > 0 )
    boundary += vf->offset;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( boundary > 0 && vf->offset >= boundary )
        return -1;
      v6 = ogg_sync_pageseek(&vf->oy, og);
      if ( v6 >= 0 )
        break;
      vf->offset -= v6;
    }
    if ( v6 )
      break;
    if ( !boundary )
      return -1;
    data = get_data(vf);
    if ( !data )
      return -2;
    if ( data < 0 )
      return -128;
  }
  offset = vf->offset;
  vf->offset = offset + v6;
  return offset;
}
