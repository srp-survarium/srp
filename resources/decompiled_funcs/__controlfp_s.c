int __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int newctrl, unsigned int mask)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState )
      *_CurrentState = _control87(0, 0);
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return 22;
  }
  else
  {
    v4 = mask & 0xFFF7FFFF;
    if ( _CurrentState )
      *_CurrentState = _control87(newctrl, v4);
    else
      _control87(newctrl, v4);
    return 0;
  }
}
