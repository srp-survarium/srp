void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **),
        const Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *ed,
        bool useCapture)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  unsigned int v7; // eax
  unsigned int SizeMask; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v9; // edx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v13; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *v14; // ebp
  int v15; // edi
  unsigned int Size; // ebx
  Scaleform::GFx::AS3::Value *p_mFunction; // esi
  unsigned int v18; // edi
  Scaleform::GFx::AS3::Value *v19; // esi
  unsigned int v20; // eax
  unsigned int *v21; // ecx
  int v22; // [esp+10h] [ebp-10h]
  int v23; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *it; // [esp+18h] [ebp-8h]
  unsigned int it_4; // [esp+1Ch] [ebp-4h]

  pTable = this->mHash.pTable;
  if ( this->mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = 0;
    v9 = pTable + 1;
    do
    {
      if ( v9->EntryCount != -2 )
        break;
      ++v7;
      v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v9 + 12);
    }
    while ( v7 <= SizeMask );
  }
  else
  {
    this = 0;
    v7 = 0;
  }
  v10 = this;
  v11 = v7;
  it = this;
  it_4 = v7;
  while ( 1 )
  {
    v12 = 0;
    if ( !v10 )
      break;
    v13 = v10->mHash.pTable;
    if ( !v10->mHash.pTable || (signed int)v11 > (signed int)v13->SizeMask )
      break;
    v14 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *)*(&v13[2].EntryCount + 3 * v11);
    v23 = 12 * v11;
    if ( !v14 )
      goto LABEL_30;
    if ( vm->InDestructor )
    {
      if ( !v14->Data.Size )
        goto LABEL_30;
      v15 = 0;
      Size = v14->Data.Size;
      do
      {
        p_mFunction = &v14->Data.Data[v15].mFunction;
        if ( Scaleform::GFx::AS3::Value::IsValidWeakRef(p_mFunction)
          && (p_mFunction->Flags & 0x1F) > 0xA
          && (p_mFunction->Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, p_mFunction, op);
        }
        ++v15;
        --Size;
      }
      while ( Size );
    }
    else
    {
      v18 = v14->Data.Size;
      if ( !v18 )
        goto LABEL_30;
      v22 = 0;
      do
      {
        v19 = &v14->Data.Data[v22].mFunction;
        if ( Scaleform::GFx::AS3::Value::IsValidWeakRef(v19) )
        {
          if ( (v19->Flags & 0x1F) > 0xA && (v19->Flags & 0x200) == 0 )
            Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v19, op);
          ++v12;
          ++v22;
        }
        else
        {
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            v14,
            v12);
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
            ed,
            (const Scaleform::GFx::ASString *)((char *)&it->mHash.pTable[1].SizeMask + v23),
            useCapture,
            --v18);
        }
      }
      while ( v12 < v18 );
    }
    v10 = it;
    v11 = it_4;
LABEL_30:
    v20 = v10->mHash.pTable->SizeMask;
    if ( (int)v11 <= (int)v20 )
    {
      it_4 = ++v11;
      if ( v11 <= v20 )
      {
        v21 = &v10->mHash.pTable[1].EntryCount + 3 * v11;
        do
        {
          if ( *v21 != -2 )
            break;
          ++v11;
          v21 += 3;
          it_4 = v11;
        }
        while ( v11 <= v20 );
      }
    }
  }
}
