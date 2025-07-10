long double __cdecl fabs(long double x)
{
  unsigned int v1; // edi
  int v2; // eax
  int v3; // eax
  long double result; // st7
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x) - 1;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( v3 )
      {
        if ( v3 == 1 )
          return _handle_qnan1(0x15u, x, v1);
        else
          return _except1((int)&savedregs, 8, 21, x, x + 1.0, v1);
      }
      else
      {
        _ctrlfp();
        return -x;
      }
    }
    else
    {
      _ctrlfp();
      return x;
    }
  }
  else
  {
    _ctrlfp();
    *(_QWORD *)&result = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFLL;
  }
  return result;
}
