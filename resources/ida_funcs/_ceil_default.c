long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double result; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(0xCu, x, v1);
    }
    return _except1((int)&savedregs, 8, 12, x, x + 1.0, v1);
  }
  else
  {
    result = _frnd(x);
    if ( x == result || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return result;
    }
    else
    {
      return _except1((int)&savedregs, 16, 12, x, result, v1);
    }
  }
}
