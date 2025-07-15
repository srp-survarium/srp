bool __thiscall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::ASStringNode *fmt)
{
  Scaleform::GFx::AS2::Object *pObject; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool v6; // bl
  Scaleform::GFx::ASStringNode *v7; // eax
  bool v8; // bl
  Scaleform::GFx::AS2::Value v9; // [esp+Ch] [ebp-10h] BYREF

  if ( fmt == (Scaleform::GFx::ASStringNode *)1 )
    return 0;
  pObject = this->pProto.pObject;
  if ( !pObject )
    return this->ActsAsButton(this);
  pContext = this->ASEnvironment.StringContext.pContext;
  v9.T.Type = 0;
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
         &v9);
  v7 = fmt;
  --fmt->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( !v6 || !v9.T.Type || v9.T.Type == 10 )
  {
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
    return this->ActsAsButton(this);
  }
  v8 = Scaleform::GFx::AS2::Value::ToBool(&v9, (int)pObject, &this->ASEnvironment);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
  return v8;
}


bool __thiscall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(char *this, Scaleform::GFx::ASStringNode *a2)
{
  return Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled((Scaleform::GFx::AS2::AvmSprite *)(this - 24), a2);
}
