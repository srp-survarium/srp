int __fastcall GetPrimaryLen(int a1, char *pchLanguage)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; ++result )
  {
    v3 = *pchLanguage++;
    if ( (v3 < 65 || v3 > 90) && (unsigned __int8)(v3 - 97) > 0x19u )
      break;
  }
  return result;
}
