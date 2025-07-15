char __thiscall Scaleform::GFx::AMP::ThreadMgr::HandleNextReceivedMessage(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::RefCountVImpl *v2; // esi
  Scaleform::GFx::AMP::MessageTypeRegistry *pObject; // edi
  const Scaleform::String *v4; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator *v5; // eax
  const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pHash; // ecx
  int Index; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int SizeMask; // ebx
  void *v10; // edi
  int v11; // ecx
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator result; // [esp+10h] [ebp-8h] BYREF

  v2 = (Scaleform::RefCountVImpl *)Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PopFront(&this->MsgUncompressedQueue);
  if ( v2 )
  {
    pObject = this->MsgTypeRegistry.pObject;
    v4 = (const Scaleform::String *)((int (__thiscall *)(Scaleform::RefCountVImpl *, int *))v2->__vftable[1].~Scaleform::RefCountVImpl)(
                                      v2,
                                      &v13);
    v5 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
           (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pObject->DescriptorMap,
           &result,
           v4);
    pHash = v5->pHash;
    Index = v5->Index;
    if ( pHash && (pTable = pHash->pTable) != 0 && Index <= (signed int)pTable->SizeMask )
      SizeMask = pTable[2 * Index + 2].SizeMask;
    else
      SizeMask = 0;
    v10 = (void *)(v13 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v13 & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    if ( SizeMask )
    {
      v11 = *(_DWORD *)(SizeMask + 8);
      if ( v11 )
      {
        (*(void (__thiscall **)(int, Scaleform::RefCountVImpl *))(*(_DWORD *)v11 + 4))(v11, v2);
        Scaleform::RefCountImpl::Release(v2);
        return 1;
      }
    }
    Scaleform::RefCountImpl::Release(v2);
  }
  return 0;
}
