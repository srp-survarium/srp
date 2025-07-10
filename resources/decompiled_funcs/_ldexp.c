long double __cdecl ldexp(long double x, int exp)
{
  unsigned int v2; // edi
  int v3; // eax
  long double v5; // st7
  int v6; // eax
  long double v7; // st7
  long double v8; // st7
  double arg2; // [esp+8h] [ebp-20h]
  long double v10; // [esp+10h] [ebp-18h]
  unsigned int x_4; // [esp+18h] [ebp-10h]
  int oldexp; // [esp+24h] [ebp-4h] BYREF

  v2 = _ctrlfp(0x133Fu, 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) != 0x7FF0 )
  {
    if ( 0.0 == x )
    {
LABEL_6:
      _ctrlfp(v2, 0xFFFFu);
      return x;
    }
    v5 = _decomp(x, &oldexp);
    if ( exp >= 0 )
    {
      if ( oldexp > 0x7FFFFFFF - exp )
      {
LABEL_15:
        x_4 = v2;
        v10 = _copysign(_d_inf.dbl, v5);
        arg2 = (double)exp;
        return _except2(17, 25, x, arg2, v10, x_4);
      }
    }
    else if ( oldexp < (int)(0x80000000 - exp) )
    {
      goto LABEL_20;
    }
    v6 = oldexp + exp;
    if ( oldexp + exp > 2560 )
      goto LABEL_15;
    if ( v6 > 1024 )
    {
      v7 = _set_exp(v5, v6 - 1536);
      x_4 = v2;
      v10 = v7;
      arg2 = (double)exp;
      return _except2(17, 25, x, arg2, v10, x_4);
    }
    if ( v6 >= -2557 )
    {
      if ( v6 >= -1021 )
      {
        x = _set_exp(v5, v6);
        _ctrlfp(v2, 0xFFFFu);
        return x;
      }
      v8 = _set_exp(v5, v6 + 1536);
      return _except2(18, 25, x, (double)exp, v8, v2);
    }
LABEL_20:
    v8 = v5 * 0.0;
    return _except2(18, 25, x, (double)exp, v8, v2);
  }
  v3 = _sptype(x);
  if ( v3 > 0 )
  {
    if ( v3 > 2 )
    {
      if ( v3 == 3 )
        return _handle_qnan2(0x19u, x, (double)exp, v2);
      return _except2(8, 25, x, (double)exp, x + 1.0, v2);
    }
    goto LABEL_6;
  }
  return _except2(8, 25, x, (double)exp, x + 1.0, v2);
}
