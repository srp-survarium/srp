Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::Slots::Add(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *k,
        const Scaleform::GFx::AS3::SlotInfo *v)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Slots::Pair,332,Scaleform::ArrayDefaultPolicy> *p_VArray; // edi
  Scaleform::GFx::AS3::Slots::Pair *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // ebp
  int v14; // eax
  int v15; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v16; // edx
  unsigned int v17; // ebx
  Scaleform::GFx::ASStringNode *v18; // eax
  int v19; // eax
  Scaleform::GFx::AS3::AbsoluteIndex *v20; // eax
  unsigned int v21; // [esp-4h] [ebp-40h]
  unsigned int resulta; // [esp+10h] [ebp-2Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::Iterator it; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [esp+20h] [ebp-1Ch]
  int v26; // [esp+24h] [ebp-18h]
  Scaleform::GFx::AS3::SlotInfo other; // [esp+28h] [ebp-14h] BYREF

  pNode = k->pNode;
  resulta = this->VArray.Data.Size;
  if ( k->pNode )
  {
    ++pNode->RefCount;
    ++pNode->RefCount;
  }
  v25 = pNode;
  v26 = -1;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(&other, v);
  p_VArray = &this->VArray;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->VArray.Data,
    &this->VArray,
    this->VArray.Data.Size + 1);
  v7 = &this->VArray.Data.Data[this->VArray.Data.Size - 1];
  if ( &this->VArray.Data.Data[this->VArray.Data.Size] != (Scaleform::GFx::AS3::Slots::Pair *)28 )
  {
    v8 = v25;
    if ( v25 )
      ++v25->RefCount;
    v7->Key.pObject = v8;
    v7->Prev = v26;
    Scaleform::GFx::AS3::SlotInfo::SlotInfo(&v7->Value, &other);
  }
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&other);
  v9 = v25;
  if ( v25 )
  {
    v10 = v25->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( pNode )
  {
    v10 = pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v11 = (Scaleform::GFx::ASString *)k->pNode;
  if ( k->pNode )
    ++v11[3].pNode;
  pTable = this->Set.mHash.pTable;
  p_Set = &this->Set;
  k = v11;
  if ( pTable
    && (v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_Set,
                (const Scaleform::GFx::ASString *)&k,
                (int)v11[4].pNode & pTable->SizeMask),
        v14 >= 0) )
  {
    it.pHash = &p_Set->mHash;
    v15 = v14;
  }
  else
  {
    v15 = 0;
    it.pHash = 0;
  }
  if ( v11 )
  {
    v10 = v11[3].pNode-- == (Scaleform::GFx::ASStringNode *)1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v11);
  }
  if ( it.pHash && (v16 = it.pHash->pTable) != 0 && v15 <= (signed int)v16->SizeMask )
  {
    v19 = 3 * v15;
    v17 = resulta;
    v19 *= 4;
    p_VArray->Data.Data[resulta].Prev = *(unsigned int *)((char *)&v16[2].EntryCount + v19);
    *(unsigned int *)((char *)&it.pHash->pTable[2].EntryCount + v19) = resulta + this->FirstOwnSlotNum;
  }
  else
  {
    v17 = resulta;
    v = (const Scaleform::GFx::AS3::SlotInfo *)(resulta + this->FirstOwnSlotNum);
    if ( v11 )
      ++v11[3].pNode;
    k = v11;
    v21 = (unsigned int)v11[4].pNode;
    it.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&k;
    it.Index = (int)&v;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
      &p_Set->mHash,
      p_Set,
      (const Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef *)&it,
      v21);
    v18 = (Scaleform::GFx::ASStringNode *)k;
    if ( k )
    {
      --k[3].pNode;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    p_VArray->Data.Data[resulta].Prev = -1;
  }
  v20 = result;
  result->Index = v17 + this->FirstOwnSlotNum;
  return v20;
}
