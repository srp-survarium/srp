void __usercall GetLcidFromLangCountry(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  int v2; // eax
  bool v3; // zf
  int PrimaryLen; // eax
  int iLcidState; // eax
  unsigned __int8 *pchCountry; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  strlen((unsigned __int8 *)_psetloc_data->pchLanguage);
  pchCountry = (unsigned __int8 *)_psetloc_data->pchCountry;
  _psetloc_data->bAbbrevLanguage = v1 == 3;
  strlen(pchCountry);
  _psetloc_data->lcidLanguage = 0;
  v3 = _psetloc_data->bAbbrevLanguage == 0;
  _psetloc_data->bAbbrevCountry = v2 == 3;
  if ( v3 )
    PrimaryLen = GetPrimaryLen(v7, _psetloc_data->pchLanguage);
  else
    PrimaryLen = 2;
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(LangCountryEnumProc, 1u);
  iLcidState = _psetloc_data->iLcidState;
  if ( (iLcidState & 0x100) == 0 || (iLcidState & 0x200) == 0 || (iLcidState & 7) == 0 )
    _psetloc_data->iLcidState = 0;
}
