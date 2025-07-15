BOOL __stdcall LangCountryEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  int v3; // edi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  BOOL v8; // eax
  char *pchLanguage; // [esp-4h] [ebp-8Ch]
  char rgcInfo[120]; // [esp+Ch] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(v2, lpLcidString);
  if ( !GetLocaleInfoA(v3, p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098, rgcInfo, 120) )
    goto LABEL_2;
  if ( !_stricmp(p_setloc_data->pchCountry, rgcInfo) )
  {
    if ( !GetLocaleInfoA(v3, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, rgcInfo, 120) )
      goto LABEL_2;
    if ( !_stricmp(p_setloc_data->pchLanguage, rgcInfo) )
    {
      p_setloc_data->iLcidState |= 0x304u;
      p_setloc_data->lcidLanguage = v3;
LABEL_15:
      p_setloc_data->lcidCountry = v3;
      goto LABEL_16;
    }
    if ( (p_setloc_data->iLcidState & 2) != 0 )
      goto LABEL_16;
    if ( p_setloc_data->iPrimaryLen && !_strnicmp(p_setloc_data->pchLanguage, rgcInfo, p_setloc_data->iPrimaryLen) )
    {
      pchLanguage = p_setloc_data->pchLanguage;
      p_setloc_data->iLcidState |= 2u;
      p_setloc_data->lcidCountry = v3;
      strlen((unsigned __int8 *)pchLanguage);
      if ( v5 == p_setloc_data->iPrimaryLen )
        p_setloc_data->lcidLanguage = v3;
    }
    else if ( (p_setloc_data->iLcidState & 1) == 0 && TestDefaultCountry(v3) )
    {
      p_setloc_data->iLcidState = v6 | 1;
      goto LABEL_15;
    }
  }
LABEL_16:
  if ( (p_setloc_data->iLcidState & 0x300) == 0x300 )
    return (p_setloc_data->iLcidState & 4) == 0;
  if ( !GetLocaleInfoA(v3, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, rgcInfo, 120) )
  {
LABEL_2:
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( !_stricmp(p_setloc_data->pchLanguage, rgcInfo) )
  {
    p_setloc_data->iLcidState |= 0x200u;
    if ( p_setloc_data->bAbbrevLanguage )
    {
      p_setloc_data->iLcidState |= 0x100u;
      goto LABEL_30;
    }
    if ( !p_setloc_data->iPrimaryLen
      || (strlen((unsigned __int8 *)p_setloc_data->pchLanguage), v7 != p_setloc_data->iPrimaryLen) )
    {
LABEL_29:
      p_setloc_data->iLcidState |= 0x100u;
LABEL_30:
      if ( !p_setloc_data->lcidLanguage )
        p_setloc_data->lcidLanguage = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v8 = TestDefaultLanguage(v3, 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage || !p_setloc_data->iPrimaryLen || _stricmp(p_setloc_data->pchLanguage, rgcInfo) )
      return (p_setloc_data->iLcidState & 4) == 0;
    v8 = TestDefaultLanguage(v3, 0);
  }
  if ( v8 )
    goto LABEL_29;
  return (p_setloc_data->iLcidState & 4) == 0;
}
