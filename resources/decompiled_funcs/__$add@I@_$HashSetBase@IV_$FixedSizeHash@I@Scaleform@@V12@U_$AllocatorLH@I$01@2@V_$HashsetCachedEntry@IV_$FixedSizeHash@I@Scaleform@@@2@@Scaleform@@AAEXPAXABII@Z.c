void __thiscall Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::add<unsigned int>(
        Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *this,
        void *pmemAddr,
        const unsigned int *key,
        unsigned int hashValue)
{
  Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *pTable; // eax
  unsigned int v6; // eax
  Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *v7; // esi
  unsigned int v8; // ebp
  int *v9; // ecx
  int v10; // edx
  unsigned int *v11; // ebx
  int v12; // edi
  int v13; // edi
  bool v14; // zf
  unsigned int *i; // edi
  int v16; // edi

  pTable = this->pTable;
  if ( this->pTable )
  {
    if ( 5 * pTable->EntryCount > 4 * pTable->SizeMask + 4 )
      Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::setRawCapacity(
        this,
        pmemAddr,
        2 * pTable->SizeMask + 2);
  }
  else
  {
    Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::setRawCapacity(
      this,
      pmemAddr,
      8u);
  }
  v6 = this->pTable->SizeMask & hashValue;
  ++this->pTable->EntryCount;
  v7 = this->pTable;
  v8 = *(&v7[1].EntryCount + 3 * v6);
  v9 = (int *)&v7[1] + 3 * v6;
  if ( v8 == -2 )
  {
    *v9 = -1;
    *(&v7[2].EntryCount + 3 * v6) = *key;
    *(&v7[1].SizeMask + 3 * v6) = v6;
  }
  else
  {
    v10 = v6;
    do
      v10 = v7->SizeMask & (v10 + 1);
    while ( *(&v7[1].EntryCount + 3 * v10) != -2 );
    v11 = &v7[1].EntryCount + 3 * v10;
    v12 = *(&v7[1].SizeMask + 3 * v6);
    if ( v12 == v6 )
    {
      if ( (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *)((char *)v7 + 12 * v10) != (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *)-8 )
      {
        *v11 = v8;
        *(&v7[1].SizeMask + 3 * v10) = *(&v7[1].SizeMask + 3 * v6);
        *(&v7[2].EntryCount + 3 * v10) = *(&v7[2].EntryCount + 3 * v6);
      }
      *(&v7[2].EntryCount + 3 * v6) = *key;
      *v9 = v10;
      *(&v7[1].SizeMask + 3 * v6) = v6;
    }
    else
    {
      v13 = 3 * v12;
      v14 = *(&v7[1].EntryCount + v13) == v6;
      for ( i = &v7[1].EntryCount + v13; !v14; i = &v7[1].EntryCount + v16 )
      {
        v16 = 3 * *i;
        v14 = *(&v7[1].EntryCount + v16) == v6;
      }
      if ( (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *)((char *)v7 + 12 * v10) != (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *)-8 )
      {
        *v11 = v8;
        *(&v7[1].SizeMask + 3 * v10) = *(&v7[1].SizeMask + 3 * v6);
        *(&v7[2].EntryCount + 3 * v10) = *(&v7[2].EntryCount + 3 * v6);
      }
      *i = v10;
      *(&v7[2].EntryCount + 3 * v6) = *key;
      *v9 = -1;
      *(&v7[1].SizeMask + 3 * v6) = v6;
    }
  }
}
