int __usercall _controlfp_s@<eax>(int a1@<ebx>, unsigned int *_CurrentState, unsigned int newctrl, unsigned int mask)
{
  unsigned int v5; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState )
      *_CurrentState = _control87(0, 0);
    *_errno() = 22;
    _invalid_parameter(a1, 22, 0);
    return 22;
  }
  else
  {
    v5 = mask & 0xFFF7FFFF;
    if ( _CurrentState )
      *_CurrentState = _control87(newctrl, v5);
    else
      _control87(newctrl, v5);
    return 0;
  }
}
