void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) )
  {
    _atodbl_l(&doubletemp, number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(&flag, number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}
