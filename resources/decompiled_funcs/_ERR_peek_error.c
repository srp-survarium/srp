unsigned int __cdecl ERR_peek_error()
{
  err_state_st *state; // eax
  int bottom; // ecx

  state = ERR_get_state();
  bottom = state->bottom;
  if ( bottom == state->top )
    return 0;
  else
    return state->err_buffer[(bottom + 1) % 16];
}
