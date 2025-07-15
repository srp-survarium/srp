_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( !*((_WORD *)v2 + 3) )
    return 0;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return 0;
  }
  return result;
}
