bool __thiscall Scaleform::GFx::AS2::StringObject::GetMemberRaw(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  volatile int *p_RefCount; // esi
  bool v6; // zf
  int Length; // edi

  p_RefCount = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v6 = *(Scaleform::GFx::ASStringNode **)(*p_RefCount + 8) == name->pNode->pLower;
  }
  else
  {
    v6 = (Scaleform::GFx::ASStringNode *)*p_RefCount == name->pNode;
  }
  if ( !v6 )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val) != 0;
  if ( !Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val) || val->T.Type == 10 )
  {
    Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&this->ResolveHandler.pLocalFrame);
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 4;
    val->NV.Int32Value = Length;
  }
  return 1;
}
