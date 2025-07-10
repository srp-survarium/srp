unsigned int __thiscall Scaleform::GFx::AS2::AvmSprite::GetCursorType(Scaleform::GFx::AS2::AvmSprite *this)
{
  const Scaleform::GFx::AS2::Environment *v2; // edi
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  if ( !this->ActsAsButton(this) )
    return 0;
  v2 = this->GetASEnvironment(this);
  val.T.Type = 0;
  if ( this->GetMemberRaw(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         &v2->StringContext,
         (const Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
         &val) )
  {
    Type = val.T.Type;
    if ( !val.T.Type || val.T.Type == 10 )
    {
LABEL_7:
      if ( Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      return 0;
    }
    if ( !Scaleform::GFx::AS2::Value::ToBool(&val, v2) )
    {
      Type = val.T.Type;
      goto LABEL_7;
    }
  }
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return 1;
}
