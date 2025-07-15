char __thiscall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::ASStringNode *fmt)
{
  Scaleform::GFx::AS2::Object *pObject; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool v6; // bl
  Scaleform::GFx::ASStringNode *v7; // eax
  char v8; // bl
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  if ( fmt == (Scaleform::GFx::ASStringNode *)1 )
    return 0;
  pObject = this->pProto.pObject;
  if ( !pObject )
    return this->ActsAsButton(this);
  pContext = this->ASEnvironment.StringContext.pContext;
  val.T.Type = 0;
  fmt = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "focusEnabled",
          0xCu,
          0);
  ++fmt->RefCount;
  v6 = pObject->GetMemberRaw(
         &pObject->Scaleform::GFx::AS2::ObjectInterface,
         &this->ASEnvironment.StringContext,
         (const Scaleform::GFx::ASString *)&fmt,
         &val);
  v7 = fmt;
  --fmt->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( !v6 || !val.T.Type || val.T.Type == 10 )
  {
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    return this->ActsAsButton(this);
  }
  v8 = Scaleform::GFx::AS2::Value::ToBool(&val, &this->ASEnvironment);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return v8;
}


char __thiscall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(char *this, Scaleform::GFx::ASStringNode *a2)
{
  return Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled((Scaleform::GFx::AS2::AvmSprite *)(this - 24), a2);
}
