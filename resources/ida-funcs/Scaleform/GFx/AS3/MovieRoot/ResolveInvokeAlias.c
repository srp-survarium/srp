Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(
        Scaleform::GFx::AS3::MovieRoot *this,
        __m128i *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *pInvokeAliases; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v5; // edi
  signed int v6; // eax
  int v7; // eax
  int v8; // edi

  if ( !this->pInvokeAliases )
    return 0;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, pstr);
  ++StringNode->RefCount;
  pInvokeAliases = this->pInvokeAliases;
  v5.pTable = pInvokeAliases->mHash.pTable;
  pstr = (__m128i *)StringNode;
  if ( v5.pTable
    && (v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &pInvokeAliases->mHash,
               (const Scaleform::GFx::ASString *)&pstr,
               StringNode->HashFlags & v5.pTable->SizeMask),
        v6 >= 0)
    && (v7 = (int)&v5.pTable[4 * v6 + 2]) != 0 )
  {
    v8 = v7 + 8;
  }
  else
  {
    v8 = 0;
  }
  if ( StringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  return (Scaleform::GFx::AS3::Value *)v8;
}
