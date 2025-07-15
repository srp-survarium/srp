void __thiscall Scaleform::GFx::AS3::Slots::SetKey(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::ASString *k)
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Slots::Pair *Data; // ecx
  Scaleform::GFx::ASString *pNode; // esi
  Scaleform::GFx::ASStringNode **v7; // edi
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // ebx
  int v12; // eax
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *v13; // ebp
  int v14; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v15; // ecx
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v16; // edi
  unsigned int v17; // edx
  Scaleform::GFx::ASStringNode *v18; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *pFirst; // edx
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v21; // [esp+14h] [ebp-8h]
  unsigned int index; // [esp+18h] [ebp-4h] BYREF

  v4 = ind.Index - this->FirstOwnSlotNum;
  Data = this->VArray.Data.Data;
  pNode = (Scaleform::GFx::ASString *)k->pNode;
  index = v4;
  v4 *= 32;
  v7 = (Scaleform::GFx::ASStringNode **)((char *)&Data->Key.pObject + v4);
  key.pFirst = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)this;
  v21 = v4;
  if ( *(Scaleform::GFx::ASString **)((char *)&Data->Key.pObject + v4) != pNode )
  {
    if ( pNode )
      ++pNode[3].pNode;
    v8 = *v7;
    if ( *v7 )
    {
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    *v7 = (Scaleform::GFx::ASStringNode *)pNode;
    if ( pNode )
      ++pNode[3].pNode;
    pTable = this->Set.mHash.pTable;
    p_Set = &this->Set;
    k = pNode;
    if ( pTable
      && (v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_Set,
                  (const Scaleform::GFx::ASString *)&k,
                  (int)pNode[4].pNode & pTable->SizeMask),
          v12 >= 0) )
    {
      v13 = p_Set;
      v14 = v12;
    }
    else
    {
      v13 = 0;
      v14 = 0;
    }
    if ( pNode )
    {
      v9 = pNode[3].pNode-- == (Scaleform::GFx::ASStringNode *)1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pNode);
    }
    if ( v13 && (v15 = v13->mHash.pTable) != 0 && v14 <= (signed int)v15->SizeMask )
    {
      pFirst = key.pFirst;
      *(Scaleform::GFx::ASStringManager **)((char *)&key.pFirst[2].pObject->pManager + v21) = (Scaleform::GFx::ASStringManager *)*(&v15[2].EntryCount + 3 * v14);
      *(&v13->mHash.pTable[2].EntryCount + 3 * v14) = (unsigned int)pFirst->pObject + index;
    }
    else
    {
      v16 = key.pFirst;
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
      v18 = (Scaleform::GFx::ASStringNode *)k;
      if ( k )
      {
        --k[3].pNode;
        if ( !v18->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      *(Scaleform::GFx::ASStringManager **)((char *)&v16[2].pObject->pManager + v21) = (Scaleform::GFx::ASStringManager *)-1;
    }
  }
}
