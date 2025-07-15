char __thiscall Scaleform::GFx::AS2::AvmSprite::HasEventHandler(
        Scaleform::GFx::AS2::AvmSprite *this,
        const Scaleform::GFx::EventId *id)
{
  const Scaleform::GFx::EventId *v2; // edi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS2::Value v8; // [esp+Ch] [ebp-10h] BYREF

  v2 = id;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) )
    return 1;
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    (Scaleform::GFx::ASString *)&id,
    (Scaleform::GFx::AS2::StringManager *)&this->pDispObj->pASRoot[8].RefCount,
    v2);
  if ( id[1].Id )
  {
    pObject = this->ASMovieClipObj.pObject;
    v8.T.Type = 0;
    if ( pObject || (pObject = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject) != 0 )
    {
      if ( pObject->GetMemberRaw(
             &pObject->Scaleform::GFx::AS2::ObjectInterface,
             &this->ASEnvironment.StringContext,
             (const Scaleform::GFx::ASString *)&id,
             &v8) )
      {
        if ( v8.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v8);
        v5 = (Scaleform::GFx::ASStringNode *)id;
        --id->TouchID;
        if ( !v5->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        return 1;
      }
      if ( v8.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v8);
    }
  }
  v7 = (Scaleform::GFx::ASStringNode *)id;
  --id->TouchID;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return 0;
}


char __thiscall Scaleform::GFx::AS2::AvmSprite::HasEventHandler(char *this, const Scaleform::GFx::EventId *a2)
{
  return Scaleform::GFx::AS2::AvmSprite::HasEventHandler((Scaleform::GFx::AS2::AvmSprite *)(this - 24), a2);
}
