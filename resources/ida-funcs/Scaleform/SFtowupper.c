int __cdecl Scaleform::SFtowupper(int charCode)
{
  int result; // eax
  int v2; // ecx
  int v3; // edx

  result = (unsigned __int16)charCode;
  v2 = BYTE1(charCode);
  v3 = UnicodeToUpperBits[v2];
  if ( UnicodeToUpperBits[v2]
    && (v3 == 1 || (UnicodeToUpperBits[v3 + ((unsigned __int8)charCode >> 4)] & (1 << (charCode & 0xF))) != 0) )
  {
    charCode = (unsigned __int16)charCode;
    return UnicodeToUpperTable[Scaleform::Alg::LowerBoundSliced<Scaleform::GUnicodePairType const [641],unsigned short,bool (__cdecl *)(Scaleform::GUnicodePairType const &,unsigned short)>(
                                 (const Scaleform::GUnicodePairType (*)[677])UnicodeToUpperTable,
                                 0,
                                 0x280u,
                                 (unsigned __int16 *)&charCode,
                                 (bool (__cdecl *)(const Scaleform::GUnicodePairType *, unsigned __int16))Scaleform::CmpUnicodeKey)].Value;
  }
  return result;
}
