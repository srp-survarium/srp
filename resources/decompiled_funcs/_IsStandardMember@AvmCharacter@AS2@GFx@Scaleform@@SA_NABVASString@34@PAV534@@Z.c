char __cdecl Scaleform::GFx::AS2::AvmCharacter::IsStandardMember(
        Scaleform::GFx::ASString *memberName,
        Scaleform::GFx::ASString *pcaseInsensitiveName)
{
  Scaleform::GFx::ASString *v2; // esi
  Scaleform::GFx::ASString *v3; // eax
  Scaleform::GFx::ASStringNode *v4; // esi
  unsigned int v5; // edx
  bool v6; // zf

  v2 = memberName;
  if ( (memberName->pNode->HashFlags & 0x20000000) != 0 )
    return 1;
  if ( Scaleform::GFx::ASConstString::GetLength(memberName) && Scaleform::GFx::ASConstString::GetCharAt(v2, 0) == 95 )
  {
    v3 = (Scaleform::GFx::ASString *)Scaleform::GFx::ASConstString::ToLowerNode(v2);
    v4 = (Scaleform::GFx::ASStringNode *)v3;
    ++v3[3].pNode;
    v5 = (unsigned int)v3[4].pNode >> 28;
    memberName = v3;
    if ( (v5 & 1) != 0 )
    {
      if ( pcaseInsensitiveName )
        Scaleform::GFx::ASString::operator=(pcaseInsensitiveName, (const Scaleform::GFx::ASString *)&memberName);
      v6 = v4->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v4);
      return 1;
    }
    v6 = v3[3].pNode-- == (Scaleform::GFx::ASStringNode *)1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v3);
  }
  return 0;
}
