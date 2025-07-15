unsigned int __cdecl ERR_peek_last_error()
{
  err_state_st *state; // eax
  int top; // ecx

  state = ERR_get_state();
  top = state->top;
  if ( state->bottom == top )
    return 0;
  else
    return state->err_buffer[top];
}
