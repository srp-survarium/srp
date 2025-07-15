char __thiscall Scaleform::GFx::AS2::Object::Watch(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *prop,
        const Scaleform::GFx::AS2::FunctionRef *callback,
        const Scaleform::GFx::AS2::Value *userData)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // eax
  Scaleform::GFx::AS2::Object::Watchpoint v8; // [esp+Ch] [ebp-1Ch] BYREF

  memset(&v8, 0, 9);
  v8.UserData.T.Type = 0;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&v8.Callback, callback);
  Scaleform::GFx::AS2::Value::operator=(&v8.UserData, userData);
  if ( !this->Members.mHash.pTable )
  {
    v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)psc->pContext->pHeap->Alloc(psc->pContext->pHeap, 4, 0);
    if ( v6 )
      v6->EntryCount = 0;
    else
      v6 = 0;
    this->Members.mHash.pTable = v6;
  }
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
    (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)this->Members.mHash.pTable,
    prop,
    &v8,
    psc->SWFVersion > 6u);
  Scaleform::GFx::AS2::Object::Watchpoint::~Watchpoint(&v8);
  return 1;
}
