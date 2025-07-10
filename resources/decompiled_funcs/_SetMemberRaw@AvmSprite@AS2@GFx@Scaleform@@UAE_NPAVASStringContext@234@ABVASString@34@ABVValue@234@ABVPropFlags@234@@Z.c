char __thiscall Scaleform::GFx::AS2::AvmSprite::SetMemberRaw(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASStringNode *v6; // eax
  bool v7; // zf
  int StandardMemberConstant; // eax

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_11;
    v6 = Scaleform::GFx::ASConstString::ToLowerNode(name);
    ++v6->RefCount;
    if ( (v6->HashFlags & 0x10000000) == 0 )
    {
      v7 = v6->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      goto LABEL_11;
    }
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 4),
                             name);
  if ( (*(unsigned __int8 (__thiscall **)(Scaleform::GFx::Bool3W *, int, const Scaleform::GFx::AS2::Value *, _DWORD))(*(_DWORD *)&this[-1].TabChildren.Value + 140))(
         &this[-1].TabChildren,
         StandardMemberConstant,
         val,
         0) )
  {
    return 1;
  }
LABEL_11:
  if ( this->Level
    || Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)((char *)this - 4)) )
  {
    return (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *))(*(_DWORD *)(this->Level + 16) + 40))(
             this->Level + 16,
             psc,
             name,
             val,
             flags);
  }
  else
  {
    return 0;
  }
}
