BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  if ( *(_WORD *)pImageBase == 23117 && (v2 = &pImageBase[*((_DWORD *)pImageBase + 15)], *(_DWORD *)v2 == 17744) )
    return *((_WORD *)v2 + 12) == 267;
  else
    return 0;
}
