int __thiscall Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::ASString *memberName)
{
  Scaleform::GFx::AS2::GlobalContext *(__thiscall *GetGC)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  Scaleform::GFx::ASStringNode *RefCount; // eax
  char IsStandardMember; // al
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::AS2::GlobalContext *v7; // eax
  bool v8; // zf
  int v9; // esi
  char memberConstant; // [esp+Fh] [ebp-5h] BYREF
  Scaleform::GFx::ASString lowerCaseName; // [esp+10h] [ebp-4h] BYREF

  GetGC = this->GetGC;
  memberConstant = -1;
  RefCount = (Scaleform::GFx::ASStringNode *)GetGC(this)->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  lowerCaseName.pNode = RefCount;
  IsStandardMember = Scaleform::GFx::AS2::AvmCharacter::IsStandardMember(memberName, &lowerCaseName);
  pNode = lowerCaseName.pNode;
  if ( IsStandardMember )
  {
    v7 = this->GetGC(this);
    Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseCheck(
      &v7->StandardMemberMap,
      memberName,
      &memberConstant,
      pNode->Size == 0);
  }
  v8 = pNode->RefCount-- == 1;
  v9 = memberConstant;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v9;
}
