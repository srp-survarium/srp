void __usercall __lc_lctostr(int a1@<edi>, char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(a1, locale, sizeInBytes, names->szLanguage) )
    _invoke_watson(0, a1, (int)names);
  if ( names->szCountry[0] )
    _strcats(locale, sizeInBytes, 2, "_", names->szCountry);
  if ( names->szCodePage[0] )
    _strcats(locale, sizeInBytes, 2, ".", names->szCodePage);
}
