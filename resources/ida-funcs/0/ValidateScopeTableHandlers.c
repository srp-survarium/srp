int __usercall ValidateScopeTableHandlers@<eax>(
        unsigned __int8 *pImageBase@<edi>,
        int dwTryLevel@<ecx>,
        _SCOPETABLE_ENTRY *pScopeTable)
{
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v4; // edx
  _SCOPETABLE_ENTRY *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // ecx
  _BYTE *FilterFunc; // ecx
  unsigned int v9; // esi
  unsigned int VirtualAddress; // ecx

  PESection = 0;
  v4 = -1;
  if ( dwTryLevel == -1 )
    return 1;
  while ( 1 )
  {
    v5 = &pScopeTable[dwTryLevel];
    v6 = ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000;
    if ( v6 != v4 )
      break;
LABEL_9:
    FilterFunc = v5->FilterFunc;
    if ( FilterFunc )
    {
      v9 = (FilterFunc - pImageBase) & 0xFFFFF000;
      if ( v9 != v4 )
      {
        VirtualAddress = PESection->VirtualAddress;
        if ( v9 < VirtualAddress || v9 >= VirtualAddress + PESection->Misc.PhysicalAddress )
        {
          PESection = _FindPESection(pImageBase, v9);
          if ( !PESection || (PESection->Characteristics & 0x20000000) == 0 )
            return 0;
        }
        v4 = v9;
      }
    }
    dwTryLevel = v5->EnclosingLevel;
    if ( v5->EnclosingLevel == -1 )
      return 1;
  }
  if ( PESection && (v7 = PESection->VirtualAddress, v6 >= v7) && v6 < v7 + PESection->Misc.PhysicalAddress
    || (PESection = _FindPESection(pImageBase, ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000)) != 0
    && (PESection->Characteristics & 0x20000000) != 0 )
  {
    v4 = v6;
    goto LABEL_9;
  }
  return 0;
}
