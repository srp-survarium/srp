unsigned int __thiscall Scaleform::GFx::AS2::AvmButton::GetCursorType(Scaleform::GFx::AS2::AvmButton *this)
{
  const Scaleform::GFx::AS2::Environment *v2; // edi
  Scaleform::GFx::AS2::ObjectInterface *v3; // ecx
  Scaleform::GFx::AS2::Object *pObject; // esi
  Scaleform::GFx::AS2::Value v6; // [esp+Ch] [ebp-10h] BYREF

  v2 = this->GetASEnvironment(this);
  v6.T.Type = 0;
  if ( !v2 || (this->pDispObj->Flags & 0x10) == 0 )
    return 0;
  if ( this->ASButtonObj.pObject )
  {
    v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    pObject = this->pProto.pObject;
    if ( !pObject )
      goto LABEL_8;
    v3 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
  }
  v3->GetMemberRaw(
    v3,
    &v2->StringContext,
    (const Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v6);
LABEL_8:
  if ( !Scaleform::GFx::AS2::Value::ToBool(&v6, (int)v2, v2) )
  {
    if ( v6.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v6);
    return 0;
  }
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  return 1;
}


unsigned int __thiscall Scaleform::GFx::AS2::AvmButton::GetCursorType(char *this)
{
  return Scaleform::GFx::AS2::AvmButton::GetCursorType((Scaleform::GFx::AS2::AvmButton *)(this - 24));
}
