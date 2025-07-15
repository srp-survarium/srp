char __thiscall Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *className)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::FunctionRef> *p_RegisteredClasses; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v4; // edi
  const Scaleform::GFx::ASString *v5; // esi
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS2::FunctionRef *CaseInsensitive; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf

  p_RegisteredClasses = &this->RegisteredClasses;
  if ( psc->SWFVersion <= 6u )
  {
    v5 = className;
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        &this->RegisteredClasses,
                        className);
  }
  else
  {
    v4.pTable = p_RegisteredClasses->mHash.pTable;
    if ( !p_RegisteredClasses->mHash.pTable )
      return 0;
    v5 = className;
    v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           &this->RegisteredClasses.mHash,
           className,
           v4.pTable->SizeMask & className->pNode->HashFlags);
    if ( v6 < 0 )
      return 0;
    v7 = (int)(&v4.pTable[1].SizeMask + 5 * v6);
    if ( !v7 )
      return 0;
    CaseInsensitive = (Scaleform::GFx::AS2::FunctionRef *)(v7 + 4);
  }
  if ( !CaseInsensitive )
    return 0;
  if ( psc->SWFVersion <= 6u )
  {
    pNode = v5->pNode;
    v11 = v5->pNode->pLower == 0;
    className = v5;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString::NoCaseKey>(
      &p_RegisteredClasses->mHash,
      (const Scaleform::GFx::ASString::NoCaseKey *)&className);
    return 1;
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
      &p_RegisteredClasses->mHash,
      v5);
    return 1;
  }
}
