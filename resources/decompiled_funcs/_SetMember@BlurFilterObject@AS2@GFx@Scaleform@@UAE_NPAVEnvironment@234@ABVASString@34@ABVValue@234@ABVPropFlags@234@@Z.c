char __thiscall Scaleform::GFx::AS2::BlurFilterObject::SetMember(
        Scaleform::GFx::AS2::BlurFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  unsigned int v7; // esi
  float vala; // [esp+18h] [ebp+Ch]
  float valb; // [esp+18h] [ebp+Ch]
  float valc; // [esp+18h] [ebp+Ch]
  float vald; // [esp+18h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "blurX") )
  {
    vala = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    valb = vala * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurX = valb;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    valc = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    vald = valc * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurY = vald;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "quality") )
  {
    v7 = (__int16)(int)Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    if ( v7 >= 0xF )
      v7 = 15;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->Passes = v7;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
}
