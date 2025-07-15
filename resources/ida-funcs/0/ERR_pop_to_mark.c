int __usercall ERR_pop_to_mark@<eax>(int a1@<ebx>)
{
  err_state_st *state; // esi
  int top; // ecx
  int v3; // eax
  int v4; // eax

  state = ERR_get_state(a1);
  while ( state->bottom != state->top )
  {
    top = state->top;
    if ( (state->err_flags[top] & 1) != 0 )
      break;
    state->err_flags[top] = 0;
    state->err_buffer[state->top] = 0;
    v3 = state->top;
    if ( state->err_data[v3] && (state->err_data_flags[v3] & 1) != 0 )
    {
      CRYPTO_free(state->err_data[v3]);
      state->err_data[state->top] = 0;
    }
    state->err_data_flags[state->top] = 0;
    state->err_file[state->top] = 0;
    state->err_line[state->top--] = -1;
    if ( state->top == -1 )
      state->top = 15;
  }
  v4 = state->top;
  if ( state->bottom == v4 )
    return 0;
  state->err_flags[v4] &= ~1u;
  return 1;
}
