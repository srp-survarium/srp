void __usercall fill_state(vostok::input::mouse::state *result@<ecx>, _DIMOUSESTATE2 *state@<eax>)
{
  result->buttons = 0;
  if ( state->rgbButtons[0] )
    result->buttons |= 1u;
  if ( state->rgbButtons[1] )
    result->buttons |= 2u;
  if ( state->rgbButtons[2] )
    result->buttons |= 4u;
  if ( state->rgbButtons[3] )
    result->buttons |= 8u;
  if ( state->rgbButtons[4] )
    result->buttons |= 0x10u;
  if ( state->rgbButtons[5] )
    result->buttons |= 0x20u;
  if ( state->rgbButtons[6] )
    result->buttons |= 0x40u;
  if ( state->rgbButtons[7] )
    result->buttons |= 0x80u;
  result->x = state->lX;
  result->y = state->lY;
  result->z = state->lZ;
}
