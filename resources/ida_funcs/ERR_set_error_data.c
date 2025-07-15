void __cdecl ERR_set_error_data(char *data, int flags)
{
  err_state_st *state; // eax
  err_state_st *v3; // edi
  int top; // esi

  state = ERR_get_state();
  v3 = state;
  top = state->top;
  if ( !top )
    top = 15;
  if ( state->err_data[top] )
  {
    if ( (state->err_data_flags[top] & 1) != 0 )
    {
      CRYPTO_free(state->err_data[top]);
      v3->err_data[top] = 0;
    }
    v3->err_data[top] = data;
    v3->err_data_flags[top] = flags;
  }
  else
  {
    state->err_data[top] = data;
    state->err_data_flags[top] = flags;
  }
}
