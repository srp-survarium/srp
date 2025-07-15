char *__cdecl __AdjustPointer(char *pThis, const PMD *pmd)
{
  char *result; // eax

  result = &pThis[pmd->mdisp];
  if ( pmd->pdisp >= 0 )
    result += pmd->pdisp + *(_DWORD *)(*(_DWORD *)&pThis[pmd->pdisp] + pmd->vdisp);
  return result;
}
