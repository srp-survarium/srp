void __usercall GetLcidFromLanguage(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  BOOL v2; // eax
  int PrimaryLen; // eax
  int v4; // [esp-4h] [ebp-4h]

  strlen((unsigned __int8 *)_psetloc_data->pchLanguage);
  v2 = v1 == 3;
  _psetloc_data->bAbbrevLanguage = v2;
  if ( v2 )
    PrimaryLen = 2;
  else
    PrimaryLen = GetPrimaryLen(v4, _psetloc_data->pchLanguage);
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(LanguageEnumProc, 1u);
  if ( (_psetloc_data->iLcidState & 4) == 0 )
    _psetloc_data->iLcidState = 0;
}
