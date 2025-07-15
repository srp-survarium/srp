int __cdecl vorbis_block_clear(vorbis_block *vb)
{
  oggpack_buffer **internal; // ebx
  oggpack_buffer **v3; // edi
  unsigned __int8 *dst; // [esp+10h] [ebp+8h]

  internal = (oggpack_buffer **)vb->internal;
  _vorbis_block_ripcord(vb);
  if ( vb->localstore )
    ogg_free_impl(vb->localstore);
  if ( internal )
  {
    dst = 0;
    v3 = internal + 3;
    do
    {
      oggpack_writeclear(*v3);
      if ( dst != (unsigned __int8 *)7 )
        ogg_free_impl(*v3);
      ++dst;
      ++v3;
    }
    while ( (int)dst < 15 );
    ogg_free_impl(internal);
  }
  memset((int)vb, 0, sizeof(vorbis_block));
  return 0;
}
