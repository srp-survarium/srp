char __thiscall Scaleform::GFx::AS2::GlobalContext::FindRegisteredClass(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *className,
        Scaleform::GFx::AS2::FunctionRef *pctorFunction)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::FunctionRef> *p_RegisteredClasses; // ecx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324> > v5; // esi
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS2::FunctionRef *CaseInsensitive; // eax

  p_RegisteredClasses = &this->RegisteredClasses;
  if ( psc->SWFVersion <= 6u )
  {
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        p_RegisteredClasses,
                        className);
  }
  else
  {
    v5.mHash.pTable = p_RegisteredClasses->mHash.pTable;
    if ( !p_RegisteredClasses->mHash.pTable )
      return 0;
    v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           &p_RegisteredClasses->mHash,
           className,
           v5.mHash.pTable->SizeMask & className->pNode->HashFlags);
    if ( v6 < 0 )
      return 0;
    v7 = (int)(&v5.mHash.pTable[1].SizeMask + 5 * v6);
    if ( !v7 )
      return 0;
    CaseInsensitive = (Scaleform::GFx::AS2::FunctionRef *)(v7 + 4);
  }
  if ( !CaseInsensitive )
    return 0;
  if ( pctorFunction )
    Scaleform::GFx::AS2::FunctionRefBase::Assign(pctorFunction, CaseInsensitive);
  return 1;
}
