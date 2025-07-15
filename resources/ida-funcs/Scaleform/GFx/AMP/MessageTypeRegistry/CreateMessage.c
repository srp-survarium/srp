Scaleform::GFx::AMP::Message *__thiscall Scaleform::GFx::AMP::MessageTypeRegistry::CreateMessage(
        Scaleform::GFx::AMP::MessageTypeRegistry *this,
        const Scaleform::String *messageTypeName)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator *v2; // eax
  const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pHash; // ecx
  int Index; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int SizeMask; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator result; // [esp+4h] [ebp-8h] BYREF

  v2 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
         (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->DescriptorMap,
         &result,
         messageTypeName);
  pHash = v2->pHash;
  Index = v2->Index;
  if ( pHash
    && (pTable = pHash->pTable) != 0
    && Index <= (signed int)pTable->SizeMask
    && (SizeMask = pTable[2 * Index + 2].SizeMask) != 0 )
  {
    return (Scaleform::GFx::AMP::Message *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)SizeMask + 4))(SizeMask);
  }
  else
  {
    return 0;
  }
}


Scaleform::GFx::AMP::MessageHeartbeat *__thiscall Scaleform::GFx::AMP::MessageTypeRegistry::CreateMessage<Scaleform::GFx::AMP::MessageHeartbeat>(
        Scaleform::GFx::AMP::MessageTypeRegistry *this)
{
  Scaleform::GFx::AMP::Message *v2; // eax
  void *v3; // esi
  Scaleform::GFx::AMP::Message *v4; // edi
  Scaleform::String messageTypeName; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&messageTypeName, (const __m128i *)"Heartbeat");
  v2 = Scaleform::GFx::AMP::MessageTypeRegistry::CreateMessage(this, &messageTypeName);
  v3 = (void *)(messageTypeName.HeapTypeBits & 0xFFFFFFFC);
  v4 = v2;
  if ( InterlockedExchangeAdd((volatile LONG *)((messageTypeName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  return (Scaleform::GFx::AMP::MessageHeartbeat *)v4;
}
