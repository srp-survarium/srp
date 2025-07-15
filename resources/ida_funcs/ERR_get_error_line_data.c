unsigned int __cdecl ERR_get_error_line_data(const char **file, int *line, const char **data, int *flags)
{
  err_state_st *state; // edi
  int bottom; // eax
  int v7; // esi
  unsigned int v8; // ebp
  const char *v9; // eax
  const char *v10; // eax

  state = ERR_get_state();
  bottom = state->bottom;
  if ( bottom == state->top )
    return 0;
  v7 = (bottom + 1) % 16;
  v8 = state->err_buffer[v7];
  state->bottom = v7;
  state->err_buffer[v7] = 0;
  if ( file && line )
  {
    v9 = state->err_file[v7];
    if ( v9 )
    {
      *file = v9;
      *line = state->err_line[v7];
    }
    else
    {
      *file = "NA";
      *line = 0;
    }
  }
  v10 = state->err_data[v7];
  if ( data )
  {
    if ( v10 )
    {
      *data = v10;
      if ( flags )
        *flags = state->err_data_flags[v7];
    }
    else
    {
      *data = (const char *)&buf;
      if ( flags )
      {
        *flags = 0;
        return v8;
      }
    }
    return v8;
  }
  else
  {
    if ( v10 )
    {
      if ( (state->err_data_flags[v7] & 1) != 0 )
      {
        CRYPTO_free(state->err_data[v7]);
        state->err_data[v7] = 0;
      }
    }
    state->err_data_flags[v7] = 0;
    return v8;
  }
}
