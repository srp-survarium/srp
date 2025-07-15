void ERR_clear_error()
{
  err_state_st *state; // ecx
  char **err_data; // esi
  int v2; // ebp
  char *v3; // eax
  err_state_st *v4; // [esp+Ch] [ebp-4h]

  state = ERR_get_state();
  v4 = state;
  err_data = state->err_data;
  v2 = 16;
  do
  {
    v3 = *err_data;
    *(err_data - 32) = 0;
    *(err_data - 16) = 0;
    if ( v3 && ((_BYTE)err_data[16] & 1) != 0 )
    {
      CRYPTO_free(v3);
      state = v4;
      *err_data = 0;
    }
    err_data[16] = 0;
    err_data[32] = 0;
    err_data[48] = (char *)-1;
    ++err_data;
    --v2;
  }
  while ( v2 );
  state->bottom = 0;
  state->top = 0;
}
