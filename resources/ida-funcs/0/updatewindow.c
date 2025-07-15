int __usercall updatewindow@<eax>(z_stream_s *strm@<ebx>, unsigned int out@<eax>)
{
  internal_state *state; // esi
  void *v4; // eax
  int dummy; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned __int8 *next_out; // ecx
  int v10; // edx
  int v11; // eax
  unsigned int v12; // ebp
  unsigned int v13; // edi
  int v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // ecx

  state = strm->state;
  if ( !state[13].dummy )
  {
    v4 = strm->zalloc(strm->opaque, 1 << state[9].dummy, 1);
    state[13].dummy = (int)v4;
    if ( !v4 )
      return 1;
  }
  if ( !state[10].dummy )
  {
    dummy = state[9].dummy;
    state[12].dummy = 0;
    state[11].dummy = 0;
    state[10].dummy = 1 << dummy;
  }
  v7 = out - strm->avail_out;
  v8 = state[10].dummy;
  next_out = strm->next_out;
  v10 = state[13].dummy;
  if ( v7 < v8 )
  {
    v12 = v8 - state[12].dummy;
    if ( v12 > v7 )
      v12 = v7;
    memcpy(state[12].dummy + v10, (const __m128i *)&next_out[-v7], v12);
    v13 = v7 - v12;
    if ( v13 )
    {
      memcpy(state[13].dummy, (const __m128i *)&strm->next_out[-v13], v13);
      v14 = state[10].dummy;
      state[12].dummy = v13;
      state[11].dummy = v14;
      return 0;
    }
    else
    {
      state[12].dummy += v12;
      v15 = state[10].dummy;
      if ( state[12].dummy == v15 )
        state[12].dummy = 0;
      v16 = state[11].dummy;
      if ( v16 < v15 )
        state[11].dummy = v12 + v16;
      return 0;
    }
  }
  else
  {
    memcpy(v10, (const __m128i *)&next_out[-v8], state[10].dummy);
    v11 = state[10].dummy;
    state[12].dummy = 0;
    state[11].dummy = v11;
    return 0;
  }
}
