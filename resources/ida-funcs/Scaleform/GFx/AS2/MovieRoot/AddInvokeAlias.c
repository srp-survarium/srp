void __thiscall Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        const Scaleform::GFx::ASString *alias,
        Scaleform::GFx::CharacterHandle *pthisChar,
        Scaleform::GFx::AS2::Object *pthisObj,
        const Scaleform::GFx::AS2::FunctionRef *func)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *v6; // eax
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *pInvokeAliases; // ecx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo v9; // [esp+10h] [ebp-14h] BYREF

  if ( !this->pInvokeAliases )
  {
    v6 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                                            Scaleform::Memory::pGlobalHeap,
                                                                                            4,
                                                                                            0);
    if ( v6 )
      v6->mHash.pTable = 0;
    else
      v6 = 0;
    this->pInvokeAliases = v6;
  }
  memset(&v9.Function, 0, 9);
  if ( pthisObj )
    pthisObj->RefCount = (pthisObj->RefCount + 1) & 0x8FFFFFFF;
  v9.ThisObject.pObject = pthisObj;
  if ( pthisChar )
    ++pthisChar->RefCount;
  v9.ThisChar.pObject = pthisChar;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&v9.Function, func);
  pInvokeAliases = this->pInvokeAliases;
  key.pFirst = alias;
  key.pSecond = &v9;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
    &pInvokeAliases->mHash,
    pInvokeAliases,
    &key);
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::~InvokeAliasInfo(&v9);
}
