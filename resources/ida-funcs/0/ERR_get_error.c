unsigned int __usercall ERR_get_error@<eax>(int a1@<ebx>)
{
  err_state_st *state; // edi
  int bottom; // eax
  int v4; // esi
  unsigned int v5; // ebx
  char *v6; // eax

  state = ERR_get_state(a1);
  bottom = state->bottom;
  if ( bottom == state->top )
    return 0;
  v4 = (bottom + 1) % 16;
  v5 = state->err_buffer[v4];
  state->bottom = v4;
  v6 = state->err_data[v4];
  state->err_buffer[v4] = 0;
  if ( v6 )
  {
    if ( (state->err_data_flags[v4] & 1) != 0 )
    {
      CRYPTO_free(v6);
      state->err_data[v4] = 0;
    }
  }
  state->err_data_flags[v4] = 0;
  return v5;
}
