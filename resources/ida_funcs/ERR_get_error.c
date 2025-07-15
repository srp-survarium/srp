unsigned int __cdecl ERR_get_error()
{
  err_state_st *state; // edi
  int bottom; // eax
  int v3; // esi
  unsigned int v4; // ebx
  char *v5; // eax

  state = ERR_get_state();
  bottom = state->bottom;
  if ( bottom == state->top )
    return 0;
  v3 = (bottom + 1) % 16;
  v4 = state->err_buffer[v3];
  state->bottom = v3;
  v5 = state->err_data[v3];
  state->err_buffer[v3] = 0;
  if ( v5 )
  {
    if ( (state->err_data_flags[v3] & 1) != 0 )
    {
      CRYPTO_free(v5);
      state->err_data[v3] = 0;
    }
  }
  state->err_data_flags[v3] = 0;
  return v4;
}
