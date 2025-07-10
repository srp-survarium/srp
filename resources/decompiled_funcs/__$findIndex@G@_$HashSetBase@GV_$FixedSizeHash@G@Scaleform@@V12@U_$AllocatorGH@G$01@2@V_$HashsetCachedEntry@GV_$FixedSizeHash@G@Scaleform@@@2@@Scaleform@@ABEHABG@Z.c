int __thiscall Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndex<unsigned short>(
        Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *this,
        const unsigned __int16 *key)
{
  int v3; // eax
  int v4; // edx
  int v5; // ebx

  if ( !this->pTable )
    return -1;
  v3 = 2;
  v4 = 5381;
  do
  {
    v5 = *((unsigned __int8 *)key + --v3);
    v4 = v5 + 65599 * v4;
  }
  while ( v3 );
  return Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndexCore<unsigned short>(
           this,
           key,
           v4 & this->pTable->SizeMask);
}
