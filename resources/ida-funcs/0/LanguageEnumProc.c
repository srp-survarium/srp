BOOL __userpurge LanguageEnumProc@<eax>(int a1@<ebx>, char *a2)
{
  setloc_struct *p_setloc_data; // esi
  int v3; // ecx
  int v4; // edi
  BOOL v6; // eax
  char LCData[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v4 = LcidFromHexString(v3, a2);
  if ( !GetLocaleInfoA(v4, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, LCData, 120) )
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( !_stricmp(a1, v4, p_setloc_data->pchLanguage, LCData) )
  {
    if ( p_setloc_data->bAbbrevLanguage )
    {
LABEL_11:
      p_setloc_data->iLcidState |= 4u;
      p_setloc_data->lcidLanguage = v4;
      p_setloc_data->lcidCountry = v4;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v6 = TestDefaultLanguage(v4, 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage
      || !p_setloc_data->iPrimaryLen
      || _stricmp(a1, v4, p_setloc_data->pchLanguage, LCData) )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v6 = TestDefaultLanguage(v4, 0);
  }
  if ( v6 )
    goto LABEL_11;
  return (p_setloc_data->iLcidState & 4) == 0;
}
