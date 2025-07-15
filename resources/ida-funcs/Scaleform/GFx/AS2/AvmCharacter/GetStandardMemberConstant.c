int __thiscall Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::ASString *memberName)
{
  Scaleform::GFx::AS2::GlobalContext *(__thiscall *GetGC)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  Scaleform::GFx::ASStringNode *RefCount; // eax
  char IsStandardMember; // al
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::AS2::GlobalContext *v7; // eax
  bool v8; // zf
  int v9; // esi
  char v11; // [esp+Fh] [ebp-5h] BYREF
  Scaleform::GFx::ASStringNode *v12; // [esp+10h] [ebp-4h] BYREF

  GetGC = this->GetGC;
  v11 = -1;
  RefCount = (Scaleform::GFx::ASStringNode *)GetGC(this)->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  v12 = RefCount;
  IsStandardMember = Scaleform::GFx::AS2::AvmCharacter::IsStandardMember(memberName, (Scaleform::GFx::ASString *)&v12);
  v6 = v12;
  if ( IsStandardMember )
  {
    v7 = this->GetGC(this);
    Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseCheck(
      &v7->StandardMemberMap,
      memberName,
      &v11,
      v6->Size == 0);
  }
  v8 = v6->RefCount-- == 1;
  v9 = v11;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return v9;
}
