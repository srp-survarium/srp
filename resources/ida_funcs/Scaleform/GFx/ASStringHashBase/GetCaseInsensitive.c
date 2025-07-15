char __thiscall Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
        Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        const Scaleform::GFx::ASString *key,
        char *pvalue)
{
  const Scaleform::GFx::ASString *v3; // edi
  signed int v5; // eax
  unsigned int *v6; // eax

  v3 = key;
  if ( !key->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(key->pNode);
  if ( !this->mHash.pTable )
    return 0;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
         &this->mHash,
         (const Scaleform::GFx::ASString::NoCaseKey *)&key,
         this->mHash.pTable->SizeMask & v3->pNode->HashFlags);
  if ( v5 < 0 )
    return 0;
  v6 = &this->mHash.pTable[1].SizeMask + 3 * v5;
  if ( !v6 )
    return 0;
  if ( pvalue )
    *pvalue = *((_BYTE *)v6 + 4);
  return 1;
}
