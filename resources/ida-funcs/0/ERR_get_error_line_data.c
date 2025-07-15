unsigned int __usercall ERR_get_error_line_data@<eax>(
        int a1@<ebx>,
        const char **file,
        int *line,
        const char **data,
        int *flags)
{
  err_state_st *state; // edi
  int bottom; // eax
  int v8; // esi
  unsigned int v9; // ebp
  const char *v10; // eax
  const char *v11; // eax

  state = ERR_get_state(a1);
  bottom = state->bottom;
  if ( bottom == state->top )
    return 0;
  v8 = (bottom + 1) % 16;
  v9 = state->err_buffer[v8];
  state->bottom = v8;
  state->err_buffer[v8] = 0;
  if ( file && line )
  {
    v10 = state->err_file[v8];
    if ( v10 )
    {
      *file = v10;
      *line = state->err_line[v8];
    }
    else
    {
      *file = "NA";
      *line = 0;
    }
  }
  v11 = state->err_data[v8];
  if ( data )
  {
    if ( v11 )
    {
      *data = v11;
      if ( flags )
        *flags = state->err_data_flags[v8];
    }
    else
    {
      *data = uri;
      if ( flags )
      {
        *flags = 0;
        return v9;
      }
    }
    return v9;
  }
  else
  {
    if ( v11 )
    {
      if ( (state->err_data_flags[v8] & 1) != 0 )
      {
        CRYPTO_free(state->err_data[v8]);
        state->err_data[v8] = 0;
      }
    }
    state->err_data_flags[v8] = 0;
    return v9;
  }
}
