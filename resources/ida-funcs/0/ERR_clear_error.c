void __usercall ERR_clear_error(int a1@<ebx>)
{
  err_state_st *state; // ecx
  char **err_data; // esi
  int v3; // ebp
  char *v4; // eax
  err_state_st *v5; // [esp+Ch] [ebp-4h]

  state = ERR_get_state(a1);
  v5 = state;
  err_data = state->err_data;
  v3 = 16;
  do
  {
    v4 = *err_data;
    *(err_data - 32) = 0;
    *(err_data - 16) = 0;
    if ( v4 && ((_BYTE)err_data[16] & 1) != 0 )
    {
      CRYPTO_free(v4);
      state = v5;
      *err_data = 0;
    }
    err_data[16] = 0;
    err_data[32] = 0;
    err_data[48] = (char *)-1;
    ++err_data;
    --v3;
  }
  while ( v3 );
  state->bottom = 0;
  state->top = 0;
}
