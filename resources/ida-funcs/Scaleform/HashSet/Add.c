void __thiscall Scaleform::HashSet<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::Add<unsigned short>(
        Scaleform::HashSet<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *this,
        const unsigned __int16 *key)
{
  int v2; // eax
  unsigned int v3; // edx
  int v4; // edi

  v2 = 2;
  v3 = 5381;
  do
  {
    v4 = *((unsigned __int8 *)key + --v2);
    v3 = v4 + 65599 * v3;
  }
  while ( v2 );
  Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::add<unsigned short>(
    this,
    this,
    key,
    v3);
}


void __thiscall Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::Add<unsigned int>(
        Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *this,
        const unsigned int *key)
{
  int v2; // eax
  unsigned int v3; // edx
  int v4; // edi

  v2 = 4;
  v3 = 5381;
  do
  {
    v4 = *((unsigned __int8 *)key + --v2);
    v3 = v4 + 65599 * v3;
  }
  while ( v2 );
  Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::add<unsigned int>(
    this,
    this,
    key,
    v3);
}
