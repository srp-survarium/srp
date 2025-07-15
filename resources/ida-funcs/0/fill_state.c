void __usercall fill_state(vostok::input::mouse::state *result@<eax>, _DIMOUSESTATE2 *state@<esi>)
{
  unsigned int i; // edi

  result->buttons = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( state->rgbButtons[i] )
      result->buttons |= 1 << i;
  }
  result->x = state->lX;
  result->y = state->lY;
  result->z = state->lZ;
}
