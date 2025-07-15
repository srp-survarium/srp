void __cdecl _fassign_l(_CRT_FLOAT flag, _CRT_DOUBLE *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE d; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) )
  {
    _atodbl_l(&d, number, plocinfo);
    argument->x = d.x;
  }
  else
  {
    _atoflt_l(&flag, number, plocinfo);
    LODWORD(argument->x) = flag;
  }
}
