int __cdecl ERR_set_mark()
{
  err_state_st *state; // eax

  state = ERR_get_state();
  if ( state->bottom == state->top )
    return 0;
  state->err_flags[state->top] |= 1u;
  return 1;
}
