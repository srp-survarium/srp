int __thiscall Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::findIndex<unsigned int>(
        Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *this,
        const Scaleform::GFx::ASString *key)
{
  int v3; // eax
  int v4; // edx
  int v5; // ebx

  if ( !this->pTable )
    return -1;
  v3 = 4;
  v4 = 5381;
  do
  {
    v5 = *((unsigned __int8 *)key + --v3);
    v4 = v5 + 65599 * v4;
  }
  while ( v3 );
  return Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::findIndexCore<Scaleform::GFx::ASString>(
           this,
           key,
           v4 & this->pTable->SizeMask);
}
