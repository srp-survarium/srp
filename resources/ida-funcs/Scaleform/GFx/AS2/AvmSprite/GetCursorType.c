unsigned int __thiscall Scaleform::GFx::AS2::AvmSprite::GetCursorType(Scaleform::GFx::AS2::AvmSprite *this)
{
  const Scaleform::GFx::AS2::Environment *v2; // edi
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value v5; // [esp+Ch] [ebp-10h] BYREF

  if ( !this->ActsAsButton(this) )
    return 0;
  v2 = this->GetASEnvironment(this);
  v5.T.Type = 0;
  if ( this->GetMemberRaw(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         &v2->StringContext,
         (const Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
         &v5) )
  {
    Type = v5.T.Type;
    if ( !v5.T.Type || v5.T.Type == 10 )
    {
LABEL_7:
      if ( Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v5);
      return 0;
    }
    if ( !Scaleform::GFx::AS2::Value::ToBool(&v5, (int)v2, v2) )
    {
      Type = v5.T.Type;
      goto LABEL_7;
    }
  }
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return 1;
}


unsigned int __thiscall Scaleform::GFx::AS2::AvmSprite::GetCursorType(char *this)
{
  return Scaleform::GFx::AS2::AvmSprite::GetCursorType((Scaleform::GFx::AS2::AvmSprite *)(this - 24));
}
