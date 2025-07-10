BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase((unsigned __int8 *)&_sbh_sizeHeaderList)
      && (PESection = _FindPESection(
                        (unsigned __int8 *)&_sbh_sizeHeaderList,
                        pTarget - (unsigned __int8 *)&_sbh_sizeHeaderList)) != 0
      && (PESection->Characteristics & 0x80000000) == 0;
}
