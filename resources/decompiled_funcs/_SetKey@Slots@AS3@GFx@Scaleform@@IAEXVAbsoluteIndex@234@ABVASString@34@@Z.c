void __thiscall Scaleform::GFx::AS3::Slots::SetKey(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::ASString *k)
{
  Scaleform::GFx::AS3::Slots::Pair *v4; // edi
  Scaleform::GFx::ASString *pNode; // esi
  Scaleform::GFx::ASStringNode *pObject; // ecx
  bool v7; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // ebx
  int v10; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *v11; // ebp
  int v12; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v13; // ecx
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v14; // edi
  Scaleform::GFx::ASStringNode *v15; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *pFirst; // edx
  unsigned int v17; // [esp-8h] [ebp-24h]
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v19; // [esp+14h] [ebp-8h]
  unsigned int index; // [esp+18h] [ebp-4h] BYREF

  index = ind.Index - this->FirstOwnSlotNum;
  v4 = &this->VArray.Data.Data[index];
  v19 = 28 * index;
  pNode = (Scaleform::GFx::ASString *)k->pNode;
  key.pFirst = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)this;
  if ( (Scaleform::GFx::ASString *)v4->Key.pObject != pNode )
  {
    if ( pNode )
      ++pNode[3].pNode;
    pObject = v4->Key.pObject;
    if ( v4->Key.pObject )
    {
      v7 = pObject->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    }
    v4->Key.pObject = (Scaleform::GFx::ASStringNode *)pNode;
    if ( pNode )
      ++pNode[3].pNode;
    pTable = this->Set.mHash.pTable;
    p_Set = &this->Set;
    k = pNode;
    if ( pTable
      && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_Set,
                  (const Scaleform::GFx::ASString *)&k,
                  (int)pNode[4].pNode & pTable->SizeMask),
          v10 >= 0) )
    {
      v11 = p_Set;
      v12 = v10;
    }
    else
    {
      v11 = 0;
      v12 = 0;
    }
    if ( pNode )
    {
      v7 = pNode[3].pNode-- == (Scaleform::GFx::ASStringNode *)1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pNode);
    }
    if ( v11 && (v13 = v11->mHash.pTable) != 0 && v12 <= (signed int)v13->SizeMask )
    {
      pFirst = key.pFirst;
      *(Scaleform::GFx::ASStringManager **)((char *)&key.pFirst[2].pObject->pManager + v19) = (Scaleform::GFx::ASStringManager *)*(&v13[2].EntryCount + 3 * v12);
      *(&v11->mHash.pTable[2].EntryCount + 3 * v12) = (unsigned int)pFirst->pObject + index;
    }
    else
    {
      v14 = key.pFirst;
      index += (unsigned int)key.pFirst->pObject;
      if ( pNode )
        ++pNode[3].pNode;
      k = pNode;
      v17 = (unsigned int)pNode[4].pNode;
      key.pFirst = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&k;
      key.pSecond = &index;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
        &p_Set->mHash,
        p_Set,
        &key,
        v17);
      v15 = (Scaleform::GFx::ASStringNode *)k;
      if ( k )
      {
        --k[3].pNode;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
      *(Scaleform::GFx::ASStringManager **)((char *)&v14[2].pObject->pManager + v19) = (Scaleform::GFx::ASStringManager *)-1;
    }
  }
}
