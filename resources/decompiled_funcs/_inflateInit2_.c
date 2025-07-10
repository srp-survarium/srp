int __cdecl inflateInit2_(z_stream_s *strm, int windowBits, const char *version, int stream_size)
{
  internal_state *v4; // eax
  int v6; // ecx

  if ( !version || *version != 49 || stream_size != 56 )
    return -6;
  if ( strm )
  {
    strm->msg = 0;
    if ( !strm->zalloc )
    {
      strm->zalloc = zcalloc;
      strm->opaque = 0;
    }
    if ( !strm->zfree )
      strm->zfree = jpeg_free_small;
    v4 = (internal_state *)strm->zalloc(strm->opaque, 1, 9520);
    if ( !v4 )
      return -4;
    v6 = windowBits;
    strm->state = v4;
    if ( windowBits >= 0 )
    {
      v4[2].dummy = (windowBits >> 4) + 1;
      if ( windowBits < 48 )
        v6 = windowBits & 0xF;
    }
    else
    {
      v4[2].dummy = 0;
      v6 = -windowBits;
    }
    if ( (unsigned int)(v6 - 8) <= 7 )
    {
      v4[9].dummy = v6;
      v4[13].dummy = 0;
      return inflateReset(strm);
    }
    strm->zfree(strm->opaque, v4);
    strm->state = 0;
  }
  return -2;
}
