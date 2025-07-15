void __cdecl Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(Scaleform::GFx::AS2::GlobalContext *pcontext)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::ASStringHash<char> *p_StandardMemberMap; // edi
  Scaleform::GFx::AS2::AvmCharacter::MemberTableType *v4; // esi
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+Ch] [ebp-Ch] BYREF
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
    key.pFirst = (const Scaleform::GFx::ASString *)&ConstStringNode;
    key.pSecond = (const char *)&pcontext;
    do
    {
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          (Scaleform::GFx::ASStringManager *)pMovieImpl,
                          (char *)v4->pName,
                          strlen(v4->pName),
                          (v4->CaseInsensitive ? 0x10000000 : 0) | 0x20000000);
      ++ConstStringNode->RefCount;
      LOBYTE(pcontext) = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        &p_StandardMemberMap->mHash,
        p_StandardMemberMap,
        &key,
        ConstStringNode->HashFlags);
      v5 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v5->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      ++v4;
    }
    while ( v4->pName );
  }
}
