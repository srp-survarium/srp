Scaleform::GFx::AS2::ObjectInterface *__thiscall Scaleform::GFx::AS2::Value::ToObjectInterface(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::AvmCharacter *v2; // eax
  Scaleform::GFx::AS2::Object *v4; // eax

  if ( this->T.Type == 7 )
  {
    v2 = Scaleform::GFx::AS2::Value::ToAvmCharacter(this, penv);
    if ( v2 )
      return &v2->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v4 = Scaleform::GFx::AS2::Value::ToObject(this, penv);
    if ( v4 )
      return &v4->Scaleform::GFx::AS2::ObjectInterface;
  }
  return 0;
}
