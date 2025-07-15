void __thiscall Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageTypeRegistry(
        Scaleform::GFx::AMP::MessageTypeRegistry *this,
        const Scaleform::GFx::AMP::MessageTypeRegistry *other)
{
  int *pTable; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  _DWORD *v5; // ecx
  int *v6; // edx
  signed int v7; // ebp
  int v8; // eax
  int v9; // edi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_DescriptorMap; // esi
  const Scaleform::String *v11; // ebx
  unsigned int v12; // eax
  int v13; // eax
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v14; // ecx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v15; // ecx
  unsigned int SizeMask; // ebx
  const Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor> *v17; // eax
  const Scaleform::String *v18; // ecx
  Scaleform::GFx::AMP::BaseMessageTypeDescriptor *pObject; // eax
  unsigned int v20; // eax
  int v21; // edi
  Scaleform::GFx::Resource *v22; // ecx
  _DWORD *v23; // edi
  Scaleform::RefCountVImpl *v24; // ecx
  unsigned int v25; // eax
  _DWORD *v26; // ecx
  int *v28; // [esp+14h] [ebp-10h]
  Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+1Ch] [ebp-8h] BYREF

  pTable = (int *)other->DescriptorMap.mHash.pTable;
  if ( pTable )
  {
    v4 = pTable[1];
    v3 = 0;
    v5 = pTable + 2;
    do
    {
      if ( *v5 != -2 )
        break;
      ++v3;
      v5 += 4;
    }
    while ( v3 <= v4 );
    pTable = (int *)&other->DescriptorMap;
  }
  else
  {
    v3 = 0;
  }
  v6 = pTable;
  v28 = pTable;
  v7 = v3;
  while ( v6 )
  {
    v8 = *v6;
    if ( !*v6 || v7 > *(_DWORD *)(v8 + 4) )
      break;
    v9 = 16 * v7;
    p_DescriptorMap = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->DescriptorMap;
    v11 = (const Scaleform::String *)(16 * v7 + v8 + 16);
    if ( this->DescriptorMap.mHash.pTable
      && (v12 = Scaleform::String::BernsteinHashFunctionCIS(
                  (char *)((v11->HeapTypeBits & 0xFFFFFFFC) + 8),
                  *(_DWORD *)(v11->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
                  0x1505u),
          v13 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String>(
                  p_DescriptorMap,
                  v11,
                  v12 & p_DescriptorMap->pTable->SizeMask),
          v13 >= 0) )
    {
      v14 = &this->DescriptorMap;
    }
    else
    {
      v14 = 0;
      v13 = 0;
    }
    if ( v14
      && (v15 = v14->mHash.pTable) != 0
      && v13 <= (signed int)v15->SizeMask
      && (SizeMask = v15[2 * v13 + 2].SizeMask) != 0 )
    {
      v21 = *(_DWORD *)(v9 + *v28 + 20);
      v22 = *(Scaleform::GFx::Resource **)(v21 + 8);
      v23 = (_DWORD *)(v21 + 8);
      if ( v22 )
        Scaleform::RefCountImpl::AddRef(v22);
      v24 = *(Scaleform::RefCountVImpl **)(SizeMask + 8);
      if ( v24 )
        Scaleform::RefCountImpl::Release(v24);
      *(_DWORD *)(SizeMask + 8) = *v23;
    }
    else
    {
      v17 = (const Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor> *)(v9 + *v28);
      v18 = (const Scaleform::String *)&v17[4];
      key.pSecond = v17 + 5;
      pObject = v17[4].pObject;
      key.pFirst = v18;
      v20 = Scaleform::String::BernsteinHashFunctionCIS(
              (char *)(((unsigned int)pObject & 0xFFFFFFFC) + 8),
              *(_DWORD *)((unsigned int)pObject & 0xFFFFFFFC) & 0x7FFFFFFF,
              0x1505u);
      Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)p_DescriptorMap,
        p_DescriptorMap,
        &key,
        v20);
    }
    v6 = v28;
    v25 = *(_DWORD *)(*v28 + 4);
    if ( v7 <= (int)v25 && ++v7 <= v25 )
    {
      v26 = (_DWORD *)(16 * v7 + *v28 + 8);
      do
      {
        if ( *v26 != -2 )
          break;
        ++v7;
        v26 += 4;
      }
      while ( v7 <= v25 );
    }
  }
}
