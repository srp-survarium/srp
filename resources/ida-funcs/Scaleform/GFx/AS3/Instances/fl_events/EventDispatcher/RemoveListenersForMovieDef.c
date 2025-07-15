void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::MovieDefImpl *defimpl,
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *hash)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v4; // edx
  signed int v5; // ebx
  unsigned int SizeMask; // edx
  unsigned int v7; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v9; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *v10; // ebp
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v11; // esi
  int v12; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Traits_vtbl *v14; // edx
  Scaleform::GFx::AS3::Traits_vtbl **VObj; // ecx
  int v16; // eax
  unsigned int v17; // eax
  unsigned int *v18; // ecx
  int v19; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *it; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+28h] [ebp+8h]

  pTable = hash->mHash.pTable;
  if ( hash->mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = 0;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2 )
        break;
      ++v7;
      v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v8 + 12);
    }
    while ( v7 <= SizeMask );
    it = hash;
    v5 = v7;
    v4 = hash;
  }
  else
  {
    v4 = 0;
    it = 0;
    v5 = 0;
  }
  while ( v4 )
  {
    v9 = v4->mHash.pTable;
    if ( !v4->mHash.pTable || v5 > (signed int)v9->SizeMask )
      break;
    v10 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *)*(&v9[2].EntryCount + 3 * v5);
    i = 0;
    if ( !v10->Data.Size )
      goto LABEL_25;
    v19 = 0;
    do
    {
      v11 = &v10->Data.Data[v19];
      if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef(&v11->mFunction) )
        goto LABEL_22;
      v12 = v11->mFunction.Flags & 0x1F;
      if ( v12 == 7 )
      {
        VObj = (Scaleform::GFx::AS3::Traits_vtbl **)v11->mFunction.value.VS._2.VObj;
        goto LABEL_18;
      }
      if ( v12 == 17 )
      {
        VObj = (Scaleform::GFx::AS3::Traits_vtbl **)v11->mFunction.value.VS._2.VObj->pTraits.pObject;
LABEL_18:
        v14 = *VObj;
        goto LABEL_19;
      }
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, &v11->mFunction);
      v14 = ValueTraits->__vftable;
      VObj = (Scaleform::GFx::AS3::Traits_vtbl **)ValueTraits;
LABEL_19:
      v16 = ((int (__fastcall *)(Scaleform::GFx::AS3::Traits_vtbl **))v14->GetFilePtr)(VObj);
      if ( v16 && *(Scaleform::GFx::MovieDefImpl **)(*(_DWORD *)(v16 + 60) + 184) == defimpl )
      {
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          v10,
          i);
        continue;
      }
LABEL_22:
      ++i;
      ++v19;
    }
    while ( i < v10->Data.Size );
    v4 = it;
LABEL_25:
    v17 = v4->mHash.pTable->SizeMask;
    if ( v5 <= (int)v17 && ++v5 <= v17 )
    {
      v18 = &v4->mHash.pTable[1].EntryCount + 3 * v5;
      do
      {
        if ( *v18 != -2 )
          break;
        ++v5;
        v18 += 3;
      }
      while ( v5 <= v17 );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // eax

  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
      this,
      defimpl,
      &pObject->CaptureListeners);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
      this,
      defimpl,
      &this->pImpl.pObject->Listeners);
  }
}
