bool __usercall Scaleform::GFx::AS2::GAS_ParseNumber@<al>(char *a1@<ecx>, int a2@<edi>, long double *retVal)
{
  char v3; // al
  long double v4; // st7
  char *v5; // eax
  bool result; // al
  char *v7; // [esp+0h] [ebp-4h] BYREF

  v7 = a1;
  result = 0;
  if ( a1 )
  {
    v3 = *a1;
    if ( *a1 )
    {
      if ( v3 >= 48 && v3 <= 57 || v3 == 43 || v3 == 45 || v3 == 46 )
      {
        v4 = Scaleform::SFstrtod(a2, a1, &v7);
        v5 = v7;
        *retVal = v4;
        if ( !v5 || !*v5 )
          return 1;
      }
    }
  }
  return result;
}
