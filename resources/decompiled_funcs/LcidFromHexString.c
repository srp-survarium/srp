int __fastcall LcidFromHexString(int a1, char *lpHexString)
{
  int i; // esi
  char v3; // cl

  for ( i = 0; ; i = 16 * i + v3 - 48 )
  {
    v3 = *lpHexString;
    if ( !*lpHexString )
      break;
    ++lpHexString;
    if ( (unsigned __int8)(v3 - 97) > 5u )
    {
      if ( (unsigned __int8)(v3 - 65) <= 5u )
        v3 -= 7;
    }
    else
    {
      v3 -= 39;
    }
  }
  return i;
}
