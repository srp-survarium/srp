long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double result; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newcw, 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(v1, 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(0xBu, x, v1);
    }
    return _except1(8, 11, x, x + 1.0, v1);
  }
  else
  {
    result = _frnd(x);
    if ( x == result || (v1 & 0x20) != 0 )
    {
      _ctrlfp(v1, 0xFFFFu);
      return result;
    }
    else
    {
      return _except1(16, 11, x, result, v1);
    }
  }
}
