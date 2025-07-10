Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *__thiscall Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString className)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::GlobalContext::ClassRegEntry> *p_BuiltinClassesRegistry; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v3; // esi
  Scaleform::GFx::ASStringNode *pNode; // edi
  signed int v5; // eax
  int p_SizeMask; // eax
  int v7; // esi

  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  v3.pTable = p_BuiltinClassesRegistry->mHash.pTable;
  pNode = className.pNode;
  if ( p_BuiltinClassesRegistry->mHash.pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &p_BuiltinClassesRegistry->mHash,
               &className,
               className.pNode->HashFlags & v3.pTable->SizeMask),
        v5 >= 0)
    && (p_SizeMask = (int)&v3.pTable[2 * v5 + 1].SizeMask) != 0
    && (v7 = p_SizeMask + 4, p_SizeMask != -4) )
  {
    if ( !--pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)v7;
  }
  else
  {
    if ( !--pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 0;
  }
}
