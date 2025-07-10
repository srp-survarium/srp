int __cdecl ERR_pop_to_mark()
{
  err_state_st *state; // esi
  int top; // ecx
  int v2; // eax
  int v3; // eax

  state = ERR_get_state();
  while ( state->bottom != state->top )
  {
    top = state->top;
    if ( (state->err_flags[top] & 1) != 0 )
      break;
    state->err_flags[top] = 0;
    state->err_buffer[state->top] = 0;
    v2 = state->top;
    if ( state->err_data[v2] && (state->err_data_flags[v2] & 1) != 0 )
    {
      CRYPTO_free(state->err_data[v2]);
      state->err_data[state->top] = 0;
    }
    state->err_data_flags[state->top] = 0;
    state->err_file[state->top] = 0;
    state->err_line[state->top--] = -1;
    if ( state->top == -1 )
      state->top = 15;
  }
  v3 = state->top;
  if ( state->bottom == v3 )
    return 0;
  state->err_flags[v3] &= ~1u;
  return 1;
}
