void __usercall ERR_set_error_data(int a1@<ebx>, char *data, int flags)
{
  err_state_st *state; // eax
  err_state_st *v4; // edi
  int top; // esi

  state = ERR_get_state(a1);
  v4 = state;
  top = state->top;
  if ( !top )
    top = 15;
  if ( state->err_data[top] )
  {
    if ( (state->err_data_flags[top] & 1) != 0 )
    {
      CRYPTO_free(state->err_data[top]);
      v4->err_data[top] = 0;
    }
    v4->err_data[top] = data;
    v4->err_data_flags[top] = flags;
  }
  else
  {
    state->err_data[top] = data;
    state->err_data_flags[top] = flags;
  }
}
