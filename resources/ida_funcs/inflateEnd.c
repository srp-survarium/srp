int __cdecl inflateEnd(z_stream_s *strm)
{
  internal_state *state; // eax
  void (__cdecl *zfree)(void *, void *); // ecx
  void *dummy; // eax

  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state )
    return -2;
  zfree = strm->zfree;
  if ( !zfree )
    return -2;
  dummy = (void *)state[13].dummy;
  if ( dummy )
    zfree(strm->opaque, dummy);
  strm->zfree(strm->opaque, strm->state);
  strm->state = 0;
  return 0;
}
