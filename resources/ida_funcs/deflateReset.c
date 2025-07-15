int __cdecl deflateReset(z_stream_s *strm)
{
  internal_state *state; // esi
  int dummy; // eax
  int v3; // eax
  unsigned int v4; // eax

  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state || !strm->zalloc || !strm->zfree )
    return -2;
  strm->total_out = 0;
  strm->total_in = 0;
  strm->msg = 0;
  strm->data_type = 2;
  state[4].dummy = state[2].dummy;
  dummy = state[6].dummy;
  state[5].dummy = 0;
  if ( dummy < 0 )
    state[6].dummy = -dummy;
  v3 = state[6].dummy;
  state[1].dummy = v3 != 0 ? 42 : 113;
  if ( v3 == 2 )
    v4 = crc32(0, 0, 0);
  else
    v4 = adler32(0, 0, 0);
  strm->adler = v4;
  state[10].dummy = 0;
  _tr_init(state);
  lm_init(state);
  return 0;
}
