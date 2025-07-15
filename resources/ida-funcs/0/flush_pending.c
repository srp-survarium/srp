void __usercall flush_pending(z_stream_s *strm@<eax>)
{
  internal_state *state; // eax
  unsigned int dummy; // edi
  internal_state *v4; // eax
  internal_state *v5; // esi

  state = strm->state;
  dummy = state[5].dummy;
  if ( dummy > strm->avail_out )
    dummy = strm->avail_out;
  if ( dummy )
  {
    memcpy((int)strm->next_out, (const __m128i *)state[4].dummy, dummy);
    v4 = strm->state;
    strm->next_out += dummy;
    v4[4].dummy += dummy;
    strm->total_out += dummy;
    strm->avail_out -= dummy;
    strm->state[5].dummy -= dummy;
    v5 = strm->state;
    if ( !v5[5].dummy )
      v5[4].dummy = v5[2].dummy;
  }
}
