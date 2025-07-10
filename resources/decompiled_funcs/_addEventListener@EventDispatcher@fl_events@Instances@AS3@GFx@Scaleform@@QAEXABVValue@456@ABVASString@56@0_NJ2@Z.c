void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Value *listener,
        bool useCapture,
        int priority,
        bool useWeakReference)
{
  bool v7; // zf
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *p_pImpl; // esi
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v10; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v13; // ebp
  int v14; // eax
  unsigned int *v15; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> **v16; // ebp
  Scaleform::MemoryHeap *v17; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *v20; // eax
  unsigned int Size; // ebp
  unsigned int v22; // ebx
  int v23; // esi
  Scaleform::GFx::AS3::Value *v24; // edi
  unsigned int v25; // ebx
  unsigned int v26; // edi
  unsigned int v27; // esi
  Scaleform::GFx::AS3::Value *p_mFunction; // ebp
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v29; // edi
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::ASStringNode *v31; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  unsigned __int8 *v33; // ecx
  Scaleform::GFx::AS3::Traits *v34; // eax
  unsigned int Flags; // eax
  unsigned int v36; // edi
  unsigned int *p_Size; // ebx
  unsigned int v38; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *v39; // ebp
  int v40; // esi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v41; // eax
  unsigned int v42; // esi
  unsigned int v43; // esi
  int v44; // eax
  unsigned int v45; // [esp-4h] [ebp-44h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *plistenersArr; // [esp+10h] [ebp-30h] BYREF
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *v47; // [esp+14h] [ebp-2Ch]
  unsigned int i; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v49; // [esp+1Ch] [ebp-24h]
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [esp+20h] [ebp-20h] BYREF
  int v51; // [esp+28h] [ebp-18h]
  Scaleform::GFx::AS3::Value v52; // [esp+30h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *evtType; // [esp+48h] [ebp+8h]

  v7 = this->pImpl.pObject == 0;
  p_pImpl = &this->pImpl;
  v49 = this;
  v47 = &this->pImpl;
  if ( v7 )
  {
    MHeap = this->pTraits.pObject->pVM->MHeap;
    v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *)MHeap->Alloc(MHeap, 12u, 0);
    if ( v10 )
    {
      v10->CaptureListeners.mHash.pTable = 0;
      v10->Listeners.mHash.pTable = 0;
      v10->Flags = 0;
      v10->CaptureButtonHandlersCnt = 0;
      v10->ButtonHandlersCnt = 0;
    }
    else
    {
      v10 = 0;
    }
    Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::operator=(
      p_pImpl,
      v10);
  }
  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_pImpl->pObject;
  if ( !useCapture )
    ++pObject;
  pNode = type->pNode;
  ++pNode->RefCount;
  v13.pTable = pObject->pTable;
  i = (unsigned int)pNode;
  if ( v13.pTable
    && (v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                pObject,
                (const Scaleform::GFx::ASString *)&i,
                pNode->HashFlags & v13.pTable->SizeMask),
        v14 >= 0)
    && (v15 = &v13.pTable[1].SizeMask + 3 * v14) != 0 )
  {
    v16 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> **)(v15 + 1);
  }
  else
  {
    v16 = 0;
  }
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v16 )
  {
    v20 = *v16;
    plistenersArr = *v16;
  }
  else
  {
    v17 = v49->pTraits.pObject->pVM->MHeap;
    v18 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *)v17->Alloc(v17, 12u, 0);
    if ( v18 )
    {
      v18->Data.Data = 0;
      v18->Data.Size = 0;
      v18->Data.Policy.Capacity = 0;
      plistenersArr = v18;
    }
    else
    {
      plistenersArr = 0;
    }
    i = (unsigned int)type->pNode;
    ++*(_DWORD *)(i + 12);
    key.pFirst = (const Scaleform::GFx::ASString *)&i;
    v45 = *(_DWORD *)(i + 16);
    key.pSecond = &plistenersArr;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pObject,
      pObject,
      &key,
      v45);
    v19 = (Scaleform::GFx::ASStringNode *)i;
    --*(_DWORD *)(i + 12);
    if ( !v19->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v20 = plistenersArr;
  }
  Size = v20->Data.Size;
  v22 = 0;
  i = 0;
  if ( !Size )
  {
LABEL_29:
    v25 = v20->Data.Size;
    v26 = i;
    if ( i < v25 )
    {
      v27 = i;
      while ( 1 )
      {
        p_mFunction = &v20->Data.Data[v27].mFunction;
        if ( Scaleform::GFx::AS3::Value::IsValidWeakRef(p_mFunction)
          && Scaleform::GFx::AS3::StrictEqual(p_mFunction, listener) )
        {
          return;
        }
        ++v26;
        ++v27;
        if ( v26 >= v25 )
          break;
        v20 = plistenersArr;
      }
    }
    v29 = v49;
    pVM = v49->pTraits.pObject->pVM;
    v31 = type->pNode;
    StringManagerRef = pVM->StringManagerRef;
    ++v31->RefCount;
    evtType = v31;
    if ( v31 == StringManagerRef->Builtins[34].pNode )
    {
      *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) |= 0x80000u;
      v47->pObject->Flags |= 1u;
      v33 = (unsigned __int8 *)2;
    }
    else if ( v31 == StringManagerRef->Builtins[35].pNode )
    {
      v47->pObject->Flags |= 0x20u;
      v33 = &vostok::memory::s_CRT_arena[5574221];
    }
    else if ( v31 == StringManagerRef->Builtins[36].pNode )
    {
      v47->pObject->Flags |= 0x40u;
      v33 = &vostok::memory::s_CRT_arena[5574222];
    }
    else if ( v31 == StringManagerRef->Builtins[28].pNode )
    {
      v47->pObject->Flags |= 2u;
      v33 = &vostok::memory::s_CRT_arena[5574217];
    }
    else if ( v31 == StringManagerRef->Builtins[33].pNode )
    {
      v47->pObject->Flags |= 4u;
      v33 = &vostok::memory::s_CRT_arena[5574218];
    }
    else if ( v31 == StringManagerRef->Builtins[44].pNode )
    {
      v47->pObject->Flags |= 8u;
      v33 = &vostok::memory::s_CRT_arena[5574219];
    }
    else
    {
      if ( v31 != StringManagerRef->Builtins[45].pNode )
      {
        if ( StringManagerRef->Builtins[49].pNode == v31
          || StringManagerRef->Builtins[53].pNode == v31
          || StringManagerRef->Builtins[47].pNode == v31
          || StringManagerRef->Builtins[48].pNode == v31
          || StringManagerRef->Builtins[52].pNode == v31
          || StringManagerRef->Builtins[51].pNode == v31
          || StringManagerRef->Builtins[56].pNode == v31
          || StringManagerRef->Builtins[55].pNode == v31 )
        {
          if ( useCapture )
          {
            if ( v47->pObject->CaptureButtonHandlersCnt != 0xFF )
              ++v47->pObject->CaptureButtonHandlersCnt;
          }
          else if ( v47->pObject->ButtonHandlersCnt != 0xFF )
          {
            ++v47->pObject->ButtonHandlersCnt;
          }
        }
        goto LABEL_67;
      }
      v47->pObject->Flags |= 0x10u;
      v33 = &vostok::memory::s_CRT_arena[5574220];
    }
    if ( !plistenersArr->Data.Size )
    {
      v34 = v29->pTraits.pObject;
      if ( (unsigned int)(v34->TraitsType - 17) <= 0xC && (v34->Flags & 0x20) == 0 )
        Scaleform::GFx::AS3::EventChains::AddToChain(
          (Scaleform::GFx::AS3::EventChains *)&pVM[1].__vftable[22],
          (Scaleform::GFx::EventId::IdCode)v33,
          (Scaleform::GFx::DisplayObject *)v29[1]._pRCC);
    }
LABEL_67:
    Flags = listener->Flags;
    v51 = priority;
    v52.Bonus.pWeakProxy = listener->Bonus.pWeakProxy;
    v52.value.VNumber = listener->value.VNumber;
    v52.Flags = Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(listener);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(listener);
    }
    v36 = plistenersArr->Data.Size;
    p_Size = &plistenersArr->Data.Size;
    v38 = v36 + 1;
    v39 = plistenersArr;
    if ( v36 + 1 >= v36 )
    {
      if ( v38 >= plistenersArr->Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &plistenersArr->Data,
          plistenersArr,
          v38 + (v38 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener>::DestructArray(
        &plistenersArr->Data.Data[v38],
        0xFFFFFFFF);
      if ( v38 < v39->Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v39->Data,
          v39,
          v36 + 1);
    }
    *p_Size = v38;
    if ( v38 > v36 )
    {
      v40 = 1;
      v41 = &v39->Data.Data[v36];
      do
      {
        if ( v41 )
        {
          v41->Priority = 0;
          v41->mFunction.Flags = 0;
          v41->mFunction.Bonus.pWeakProxy = 0;
        }
        ++v41;
        --v40;
      }
      while ( v40 );
    }
    v42 = i;
    if ( i < *p_Size - 1 )
      memmove((unsigned __int8 *)&v39->Data.Data[i + 1], (unsigned __int8 *)&v39->Data.Data[i], 24 * (*p_Size - i - 1));
    v43 = v42;
    v44 = (int)&v39->Data.Data[v43];
    if ( v44 )
    {
      *(_DWORD *)v44 = v51;
      *(Scaleform::GFx::AS3::Value *)(v44 + 8) = v52;
      if ( (v52.Flags & 0x1F) > 9 )
      {
        if ( (v52.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(&v52);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v52);
      }
    }
    if ( (v52.Flags & 0x1F) > 9 )
    {
      if ( (v52.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v52);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v52);
    }
    if ( useWeakReference )
      Scaleform::GFx::AS3::Value::MakeWeakRef(&plistenersArr->Data.Data[v43].mFunction);
    v7 = evtType->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(evtType);
    return;
  }
  v23 = 0;
  while ( 1 )
  {
    v24 = &v20->Data.Data[v23].mFunction;
    if ( Scaleform::GFx::AS3::Value::IsValidWeakRef(v24) && Scaleform::GFx::AS3::StrictEqual(v24, listener) )
      break;
    v20 = plistenersArr;
    if ( priority <= (signed int)plistenersArr->Data.Data[v23].Priority )
    {
      ++v22;
      ++v23;
      if ( v22 < Size )
        continue;
    }
    i = v22;
    goto LABEL_29;
  }
}
