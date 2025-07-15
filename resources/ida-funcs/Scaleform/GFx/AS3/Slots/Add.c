Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::Slots::Add(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *k,
        const Scaleform::GFx::AS3::SlotInfo *v)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Slots::Pair,332,Scaleform::ArrayDefaultPolicy> *p_VArray; // edi
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::Slots::Pair *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // ecx
  bool v11; // zf
  Scaleform::GFx::ASString *v12; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // ebp
  int v15; // eax
  int v16; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v17; // edx
  unsigned int v18; // ebx
  Scaleform::GFx::ASStringNode *v19; // eax
  int v20; // eax
  Scaleform::GFx::AS3::AbsoluteIndex *v21; // eax
  unsigned int v22; // [esp-4h] [ebp-44h]
  unsigned int resulta; // [esp+10h] [ebp-30h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::Iterator it; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v26; // [esp+20h] [ebp-20h]
  int v27; // [esp+24h] [ebp-1Ch]
  Scaleform::GFx::AS3::SlotInfo other; // [esp+28h] [ebp-18h] BYREF

  pNode = k->pNode;
  resulta = this->VArray.Data.Size;
  if ( k->pNode )
  {
    ++pNode->RefCount;
    ++pNode->RefCount;
  }
  v26 = pNode;
  v27 = -1;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(&other, v);
  p_VArray = &this->VArray;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->VArray.Data,
    &this->VArray,
    this->VArray.Data.Size + 1);
  Size = this->VArray.Data.Size;
  v8 = &this->VArray.Data.Data[Size - 1];
  if ( &this->VArray.Data.Data[Size] != (Scaleform::GFx::AS3::Slots::Pair *)32 )
  {
    v9 = v26;
    if ( v26 )
      ++v26->RefCount;
    v8->Key.pObject = v9;
    v8->Prev = v27;
    Scaleform::GFx::AS3::SlotInfo::SlotInfo(&v8->Value, &other);
  }
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&other);
  v10 = v26;
  if ( v26 )
  {
    v11 = v26->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( pNode )
  {
    v11 = pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v12 = (Scaleform::GFx::ASString *)k->pNode;
  if ( k->pNode )
    ++v12[3].pNode;
  pTable = this->Set.mHash.pTable;
  p_Set = &this->Set;
  k = v12;
  if ( pTable
    && (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_Set,
                (const Scaleform::GFx::ASString *)&k,
                (int)v12[4].pNode & pTable->SizeMask),
        v15 >= 0) )
  {
    it.pHash = &p_Set->mHash;
    v16 = v15;
  }
  else
  {
    v16 = 0;
    it.pHash = 0;
  }
  if ( v12 )
  {
    v11 = v12[3].pNode-- == (Scaleform::GFx::ASStringNode *)1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v12);
  }
  if ( it.pHash && (v17 = it.pHash->pTable) != 0 && v16 <= (signed int)v17->SizeMask )
  {
    v20 = 3 * v16;
    v18 = resulta;
    v20 *= 4;
    p_VArray->Data.Data[resulta].Prev = *(unsigned int *)((char *)&v17[2].EntryCount + v20);
    *(unsigned int *)((char *)&it.pHash->pTable[2].EntryCount + v20) = resulta + this->FirstOwnSlotNum;
  }
  else
  {
    v18 = resulta;
    v = (const Scaleform::GFx::AS3::SlotInfo *)(resulta + this->FirstOwnSlotNum);
    if ( v12 )
      ++v12[3].pNode;
    k = v12;
    v22 = (unsigned int)v12[4].pNode;
    it.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&k;
    it.Index = (int)&v;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
      &p_Set->mHash,
      p_Set,
      (const Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef *)&it,
      v22);
    v19 = (Scaleform::GFx::ASStringNode *)k;
    if ( k )
    {
      --k[3].pNode;
      if ( !v19->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    }
    p_VArray->Data.Data[resulta].Prev = -1;
  }
  v21 = result;
  result->Index = v18 + this->FirstOwnSlotNum;
  return v21;
}
