int __cdecl _powhlp(double x, long double y, long double *result)
{
  long double dbl; // st7
  int v4; // esi
  long double v5; // st6
  double *v6; // eax
  int v7; // eax

  dbl = 0.0;
  v4 = 0;
  v5 = x;
  if ( x < 0.0 )
    v5 = -x;
  if ( HIDWORD(y) == 2146435072 )
  {
    if ( !LODWORD(y) )
    {
      if ( v5 <= 1.0 )
      {
        v6 = result;
        if ( v5 >= 1.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
      goto LABEL_6;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( v5 > 1.0 )
      goto LABEL_27;
    v6 = result;
    if ( v5 < 1.0 )
    {
      dbl = _d_inf.dbl;
LABEL_28:
      *v6 = dbl;
      return v4;
    }
    *result = _d_ind.dbl;
    return 1;
  }
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( !LODWORD(x) )
    {
      if ( y <= 0.0 )
      {
        v6 = result;
        if ( y >= 0.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
LABEL_6:
      dbl = _d_inf.dbl;
LABEL_27:
      v6 = result;
      goto LABEL_28;
    }
  }
  else if ( x == -INFINITY )
  {
    v7 = _d_inttype(y);
    dbl = 0.0;
    if ( y <= 0.0 )
    {
      if ( y >= 0.0 )
      {
        dbl = 1.0;
      }
      else if ( v7 == 1 )
      {
        dbl = _d_mzero.dbl;
      }
    }
    else
    {
      dbl = _d_inf.dbl;
      if ( v7 == 1 )
        dbl = -_d_inf.dbl;
    }
    goto LABEL_27;
  }
  return v4;
}
