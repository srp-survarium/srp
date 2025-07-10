int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}
