int __thiscall Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndexCore<unsigned short>(
        Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *this,
        const unsigned __int16 *key,
        unsigned int hashValue)
{
  Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *pTable; // esi
  char *v4; // ecx
  int result; // eax

  pTable = this->pTable;
  v4 = (char *)&this->pTable[1] + 12 * hashValue;
  result = hashValue;
  if ( *(&pTable[1].EntryCount + 3 * hashValue) == -2 || *((_DWORD *)v4 + 1) != hashValue )
    return -1;
  while ( *((_DWORD *)v4 + 1) != hashValue || *((_WORD *)v4 + 4) != *key )
  {
    result = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 == -1 )
      return -1;
    v4 = (char *)&pTable[1] + 12 * result;
  }
  return result;
}
