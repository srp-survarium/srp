BOOL __stdcall LangCountryEnumProc(char *a1)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  const char *v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  BOOL v9; // eax
  char *pchLanguage; // [esp-4h] [ebp-8Ch]
  char LCData[120]; // [esp+Ch] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = (const char *)LcidFromHexString(v2, a1);
  if ( !GetLocaleInfoA((LCID)v3, p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098, LCData, 120) )
    goto LABEL_2;
  if ( !_stricmp((int)GetLocaleInfoA, (int)v3, p_setloc_data->pchCountry, LCData) )
  {
    if ( !GetLocaleInfoA((LCID)v3, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, LCData, 120) )
      goto LABEL_2;
    if ( !_stricmp((int)GetLocaleInfoA, (int)v3, p_setloc_data->pchLanguage, LCData) )
    {
      p_setloc_data->iLcidState |= 0x304u;
      p_setloc_data->lcidLanguage = (unsigned int)v3;
LABEL_15:
      p_setloc_data->lcidCountry = (unsigned int)v3;
      goto LABEL_16;
    }
    if ( (p_setloc_data->iLcidState & 2) != 0 )
      goto LABEL_16;
    if ( !p_setloc_data->iPrimaryLen
      || (_strnicmp((int)GetLocaleInfoA, v3, p_setloc_data->pchLanguage, LCData, p_setloc_data->iPrimaryLen), v5) )
    {
      if ( (p_setloc_data->iLcidState & 1) == 0 && TestDefaultCountry((__int16)v3) )
      {
        p_setloc_data->iLcidState = v7 | 1;
        goto LABEL_15;
      }
    }
    else
    {
      pchLanguage = p_setloc_data->pchLanguage;
      p_setloc_data->iLcidState |= 2u;
      p_setloc_data->lcidCountry = (unsigned int)v3;
      strlen((unsigned __int8 *)pchLanguage);
      if ( v6 == p_setloc_data->iPrimaryLen )
        p_setloc_data->lcidLanguage = (unsigned int)v3;
    }
  }
LABEL_16:
  if ( (p_setloc_data->iLcidState & 0x300) == 0x300 )
    return (p_setloc_data->iLcidState & 4) == 0;
  if ( !GetLocaleInfoA((LCID)v3, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, LCData, 120) )
  {
LABEL_2:
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( !_stricmp((int)GetLocaleInfoA, (int)v3, p_setloc_data->pchLanguage, LCData) )
  {
    p_setloc_data->iLcidState |= 0x200u;
    if ( p_setloc_data->bAbbrevLanguage )
    {
      p_setloc_data->iLcidState |= 0x100u;
      goto LABEL_30;
    }
    if ( !p_setloc_data->iPrimaryLen
      || (strlen((unsigned __int8 *)p_setloc_data->pchLanguage), v8 != p_setloc_data->iPrimaryLen) )
    {
LABEL_29:
      p_setloc_data->iLcidState |= 0x100u;
LABEL_30:
      if ( !p_setloc_data->lcidLanguage )
        p_setloc_data->lcidLanguage = (unsigned int)v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v9 = TestDefaultLanguage((unsigned int)v3, 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage
      || !p_setloc_data->iPrimaryLen
      || _stricmp(0, (int)v3, p_setloc_data->pchLanguage, LCData) )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v9 = TestDefaultLanguage((unsigned int)v3, 0);
  }
  if ( v9 )
    goto LABEL_29;
  return (p_setloc_data->iLcidState & 4) == 0;
}
