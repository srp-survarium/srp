void __usercall ERR_put_error(
        int a1@<ebx>,
        unsigned __int8 lib,
        __int16 func,
        __int16 reason,
        const char *file,
        int line)
{
  err_state_st *state; // esi
  int v7; // eax
  int bottom; // ecx
  int top; // eax

  state = ERR_get_state(a1);
  v7 = (state->top + 1) % 16;
  bottom = state->bottom;
  state->top = v7;
  if ( v7 == bottom )
    state->bottom = (bottom + 1) % 16;
  state->err_flags[v7] = 0;
  state->err_buffer[state->top] = reason & 0xFFF | (lib << 24) | ((func & 0xFFF) << 12);
  state->err_file[state->top] = file;
  state->err_line[state->top] = line;
  top = state->top;
  if ( state->err_data[top] )
  {
    if ( (state->err_data_flags[top] & 1) != 0 )
    {
      CRYPTO_free(state->err_data[top]);
      state->err_data[state->top] = 0;
      state->err_data_flags[state->top] = 0;
    }
    else
    {
      state->err_data_flags[top] = 0;
    }
  }
  else
  {
    state->err_data_flags[top] = 0;
  }
}
