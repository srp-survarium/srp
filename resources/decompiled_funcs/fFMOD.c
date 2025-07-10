double __usercall fFMOD@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  long double v4; // st7
  char v6; // c2

  v4 = a1;
  do
  {
    if ( _adjust_fdiv == 1 )
      _adj_fprem();
    else
      a2 = __FPREM__(a2, v4);
  }
  while ( v6 );
  return a2;
}
