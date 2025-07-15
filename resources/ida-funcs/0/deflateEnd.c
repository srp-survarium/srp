unsigned int __cdecl deflateEnd(z_stream_s *strm)
{
  internal_state *state; // eax
  int dummy; // edi
  void *v4; // eax
  internal_state *v5; // edx
  internal_state *v6; // edx
  internal_state *v7; // edx

  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state )
    return -2;
  dummy = state[1].dummy;
  if ( dummy != 42 && dummy != 69 && dummy != 73 && dummy != 91 && dummy != 103 && dummy != 113 && dummy != 666 )
    return -2;
  v4 = (void *)state[2].dummy;
  if ( v4 )
    strm->zfree(strm->opaque, v4);
  v5 = strm->state;
  if ( v5[17].dummy )
    strm->zfree(strm->opaque, (void *)v5[17].dummy);
  v6 = strm->state;
  if ( v6[16].dummy )
    strm->zfree(strm->opaque, (void *)v6[16].dummy);
  v7 = strm->state;
  if ( v7[14].dummy )
    strm->zfree(strm->opaque, (void *)v7[14].dummy);
  strm->zfree(strm->opaque, strm->state);
  strm->state = 0;
  return dummy != 113 ? 0 : 0xFFFFFFFD;
}
