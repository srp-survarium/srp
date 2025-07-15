long double __cdecl _ceil_default(long double x)
{
  __int16 v1; // bx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
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
        return _handle_qnan1(0xCu, x);
    }
    return _except1((int)&savedregs, 8u, 0xCu, x, x + 1.0, v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1((int)&savedregs, 0x10u, 0xCu, x, v4, v1);
    }
  }
}
