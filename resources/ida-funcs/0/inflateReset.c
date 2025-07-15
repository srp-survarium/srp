int __cdecl inflateReset(z_stream_s *strm)
{
  internal_state *state; // eax

  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state )
    return -2;
  state[7].dummy = 0;
  strm->total_out = 0;
  strm->total_in = 0;
  strm->msg = 0;
  strm->adler = 1;
  state->dummy = 0;
  state[1].dummy = 0;
  state[3].dummy = 0;
  state[8].dummy = 0;
  state[10].dummy = 0;
  state[11].dummy = 0;
  state[12].dummy = 0;
  state[14].dummy = 0;
  state[15].dummy = 0;
  state[5].dummy = 0x8000;
  state[27].dummy = (int)&state[332];
  state[20].dummy = (int)&state[332];
  state[19].dummy = (int)&state[332];
  return 0;
}
