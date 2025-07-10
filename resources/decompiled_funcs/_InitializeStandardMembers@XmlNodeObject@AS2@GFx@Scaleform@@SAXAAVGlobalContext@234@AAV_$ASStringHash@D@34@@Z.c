void __cdecl Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(
        Scaleform::GFx::AS2::GlobalContext *gc,
        Scaleform::GFx::ASStringHash<char> *hash)
{
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringHash<char> *v3; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // ebx
  Scaleform::GFx::AS2::GASDocument *v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [esp+10h] [ebp-8h] BYREF

  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(gc);
  v3 = hash;
  pStringManager = StringManager->pStringManager;
  if ( !hash->mHash.pTable || hash->mHash.pTable->EntryCount < 0x10 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      &hash->mHash,
      hash,
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >)16);
  v5 = Scaleform::GFx::AS2::XmlNodeObject_MemberTable;
  if ( Scaleform::GFx::AS2::XmlNodeObject_MemberTable[0].pName )
  {
    key.pFirst = &name;
    key.pSecond = (const char *)&hash;
    do
    {
      name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     pStringManager,
                     (char *)v5->pName,
                     strlen(v5->pName),
                     0x20000000u);
      ++name.pNode->RefCount;
      LOBYTE(hash) = v5->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        &v3->mHash,
        v3,
        &key,
        name.pNode->HashFlags);
      pNode = name.pNode;
      --name.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ++v5;
    }
    while ( v5->pName );
  }
}
