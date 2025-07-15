void __thiscall Scaleform::GFx::AS3::EventChains::AddToChain(
        Scaleform::GFx::AS3::EventChains *this,
        Scaleform::GFx::EventId::IdCode evtId,
        Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::GFx::EventId::IdCode v3; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // esi
  signed int Index; // eax
  int p_SizeMask; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **v8; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v10; // esi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v11; // edi
  unsigned int Size; // ecx
  Scaleform::GFx::DisplayObject *v13; // edi
  unsigned int v14; // eax
  Scaleform::GFx::DisplayObject **p_pObject; // edx
  unsigned int v16; // ecx
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v17; // eax
  Scaleform::GFx::EventId::IdCode v18; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v19; // [esp+10h] [ebp-10h] BYREF
  char v20; // [esp+14h] [ebp-Ch]
  Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeRef key; // [esp+18h] [ebp-8h] BYREF

  v3 = evtId;
  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable
    && (Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::findIndexCore<int>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)this,
                  (Scaleform::GFx::MovieDefImpl *const *)&evtId,
                  evtId & pTable->SizeMask),
        Index >= 0)
    && (p_SizeMask = (int)&pTable[2 * Index + 1].SizeMask) != 0
    && (v8 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 4)) != 0 )
  {
    v10 = *v8;
  }
  else
  {
    evtId = Event_EnterFrame;
    v9 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 12, &evtId);
    if ( v9 )
    {
      v9->Data = 0;
      v9->Size = 0;
      v9->Policy.Capacity = 0;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    key.pSecond = (const Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *)&v19;
    v19 = v10;
    v20 = 1;
    v18 = v3;
    key.pFirst = (const int *)&v18;
    Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeRef>(
      &this->Chains.mHash,
      (Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> *)this,
      &key,
      v3);
    if ( v19 && v20 )
    {
      v20 = 0;
      v11 = v19;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>(v19);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
    }
  }
  Size = v10->Size;
  v13 = obj;
  v14 = 0;
  if ( !Size )
    goto LABEL_18;
  p_pObject = &v10->Data->pObject;
  while ( *p_pObject != obj )
  {
    ++v14;
    ++p_pObject;
    if ( v14 >= Size )
      goto LABEL_18;
  }
  if ( v14 == -1 )
  {
LABEL_18:
    if ( obj )
      ++obj->RefCount;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v10,
      v10,
      v10->Size + 1);
    v16 = v10->Size;
    v17 = &v10->Data[v16 - 1];
    if ( &v10->Data[v16] != (Scaleform::Ptr<Scaleform::GFx::DisplayObject> *)4 )
    {
      if ( v13 )
        ++v13->RefCount;
      v17->pObject = v13;
    }
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
  }
}
