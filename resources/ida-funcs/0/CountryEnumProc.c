BOOL __userpurge CountryEnumProc@<eax>(int a1@<ebx>, char *a2)
{
  setloc_struct *p_setloc_data; // esi
  int v3; // ecx
  int v4; // edi
  char LCData[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v4 = LcidFromHexString(v3, a2);
  if ( GetLocaleInfoA(v4, p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098, LCData, 120) )
  {
    if ( !_stricmp(a1, v4, p_setloc_data->pchCountry, LCData) )
    {
      if ( TestDefaultCountry(v4) )
      {
        p_setloc_data->iLcidState |= 4u;
        p_setloc_data->lcidCountry = v4;
        p_setloc_data->lcidLanguage = v4;
      }
    }
    return (p_setloc_data->iLcidState & 4) == 0;
  }
  else
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
}
