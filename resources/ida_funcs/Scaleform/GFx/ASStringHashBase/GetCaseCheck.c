char __thiscall Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseCheck(
        Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        const Scaleform::GFx::ASString *key,
        char *pvalue,
        bool caseSensitive)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  int v5; // eax
  unsigned int *v6; // eax

  if ( !caseSensitive )
    return Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
             this,
             key,
             pvalue);
  pTable = this->mHash.pTable;
  if ( !this->mHash.pTable )
    return 0;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this,
         key,
         pTable->SizeMask & key->pNode->HashFlags);
  if ( v5 < 0 )
    return 0;
  v6 = &pTable[1].SizeMask + 3 * v5;
  if ( !v6 )
    return 0;
  if ( pvalue )
    *pvalue = *((_BYTE *)v6 + 4);
  return 1;
}
