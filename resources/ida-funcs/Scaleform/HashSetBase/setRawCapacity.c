void __thiscall Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::setRawCapacity(
        Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *this,
        void *pheapAddr,
        Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > newSize)
{
  int v3; // edi
  Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *v4; // ebp
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // edx
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebp
  int v13; // [esp+8h] [ebp-8h] BYREF
  Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *v14; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = this;
  v14 = this;
  if ( newSize.pTable )
  {
    if ( (unsigned int)newSize.pTable >= 8 )
      v5 = 1 << (Scaleform::Alg::UpperBit((unsigned int)&newSize.pTable[-1].SizeMask + 3) + 1);
    else
      v5 = 8;
    newSize.pTable = 0;
    v13 = 2;
    newSize.pTable = (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12 * v5 + 8, &v13);
    newSize.pTable->EntryCount = 0;
    newSize.pTable->SizeMask = v5 - 1;
    if ( v5 )
    {
      v6 = 0;
      do
      {
        *(unsigned int *)((char *)&newSize.pTable[1].EntryCount + v6) = -2;
        v6 += 12;
        --v5;
      }
      while ( v5 );
    }
    if ( v4->pTable )
    {
      v7 = v4->pTable->SizeMask + 1;
      do
      {
        v8 = (int)&v4->pTable[1] + v3;
        if ( *(_DWORD *)v8 != -2 )
        {
          v9 = (int)&v4->pTable[2] + v3;
          v10 = 2;
          v11 = 5381;
          do
          {
            v12 = *(unsigned __int8 *)(v10 + v9 - 1);
            --v10;
            v11 = v12 + 65599 * v11;
          }
          while ( v10 );
          Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::add<unsigned short>(
            &newSize,
            pheapAddr,
            (const unsigned __int16 *)(v8 + 8),
            v11);
          v4 = v14;
          *(_DWORD *)v8 = -2;
        }
        v3 += 12;
        --v7;
      }
      while ( v7 );
      if ( v4->pTable )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->pTable);
    }
    v4->pTable = newSize.pTable;
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > *)this);
  }
}


void __thiscall Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::setRawCapacity(
        Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *this,
        void *pheapAddr,
        Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > newSize)
{
  int v3; // edi
  Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *v4; // ebp
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // edx
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebp
  int v13; // [esp+8h] [ebp-8h] BYREF
  Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *v14; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = this;
  v14 = this;
  if ( newSize.pTable )
  {
    if ( (unsigned int)newSize.pTable >= 8 )
      v5 = 1 << (Scaleform::Alg::UpperBit((unsigned int)&newSize.pTable[-1].SizeMask + 3) + 1);
    else
      v5 = 8;
    newSize.pTable = 0;
    v13 = 2;
    newSize.pTable = (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > >::TableType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pheapAddr, 12 * v5 + 8, &v13);
    newSize.pTable->EntryCount = 0;
    newSize.pTable->SizeMask = v5 - 1;
    if ( v5 )
    {
      v6 = 0;
      do
      {
        *(unsigned int *)((char *)&newSize.pTable[1].EntryCount + v6) = -2;
        v6 += 12;
        --v5;
      }
      while ( v5 );
    }
    if ( v4->pTable )
    {
      v7 = v4->pTable->SizeMask + 1;
      do
      {
        v8 = (int)&v4->pTable[1] + v3;
        if ( *(_DWORD *)v8 != -2 )
        {
          v9 = (int)&v4->pTable[2] + v3;
          v10 = 4;
          v11 = 5381;
          do
          {
            v12 = *(unsigned __int8 *)(v10 + v9 - 1);
            --v10;
            v11 = v12 + 65599 * v11;
          }
          while ( v10 );
          Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::add<unsigned int>(
            &newSize,
            pheapAddr,
            (const unsigned int *)(v8 + 8),
            v11);
          v4 = v14;
          *(_DWORD *)v8 = -2;
        }
        v3 += 12;
        --v7;
      }
      while ( v7 );
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->pTable);
    }
    v4->pTable = newSize.pTable;
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)this);
  }
}
