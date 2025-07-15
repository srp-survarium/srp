void __thiscall Scaleform::GFx::AS3::MovieRoot::AddInvokeAlias(
        Scaleform::GFx::AS3::MovieRoot *this,
        const Scaleform::GFx::ASString *alias,
        const Scaleform::GFx::AS3::Value *closure)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *v4; // eax
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *pInvokeAliases; // ecx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [esp+8h] [ebp-8h] BYREF

  if ( !this->pInvokeAliases )
  {
    v4 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       4,
                                                                       0);
    if ( v4 )
      v4->mHash.pTable = 0;
    else
      v4 = 0;
    this->pInvokeAliases = v4;
  }
  pInvokeAliases = this->pInvokeAliases;
  key.pFirst = alias;
  key.pSecond = closure;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
    &pInvokeAliases->mHash,
    (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)pInvokeAliases,
    &key);
}
