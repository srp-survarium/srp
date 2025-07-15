void __cdecl Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(Scaleform::GFx::AS2::GlobalContext *pcontext)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::ASStringHash<char> *p_StandardMemberMap; // edi
  Scaleform::GFx::AS2::AvmCharacter::MemberTableType *v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [esp+10h] [ebp-8h] BYREF

  pTable = pcontext->StandardMemberMap.mHash.pTable;
  pMovieImpl = pcontext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  p_StandardMemberMap = &pcontext->StandardMemberMap;
  if ( !pTable || pTable->EntryCount < 0x92 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      &pcontext->StandardMemberMap.mHash,
      &pcontext->StandardMemberMap,
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >)146);
  v4 = Scaleform::GFx::AS2::AvmCharacter::MemberTable;
  if ( Scaleform::GFx::AS2::AvmCharacter::MemberTable[0].pName )
  {
    key.pFirst = &name;
    key.pSecond = (const char *)&pcontext;
    do
    {
      name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     (Scaleform::GFx::ASStringManager *)pMovieImpl,
                     (char *)v4->pName,
                     strlen(v4->pName),
                     (v4->CaseInsensitive ? 0x10000000 : 0) | 0x20000000);
      ++name.pNode->RefCount;
      LOBYTE(pcontext) = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        &p_StandardMemberMap->mHash,
        p_StandardMemberMap,
        &key,
        name.pNode->HashFlags);
      pNode = name.pNode;
      --name.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ++v4;
    }
    while ( v4->pName );
  }
}
