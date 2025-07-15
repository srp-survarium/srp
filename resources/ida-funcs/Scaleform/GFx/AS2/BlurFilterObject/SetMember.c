char __thiscall Scaleform::GFx::AS2::BlurFilterObject::SetMember(
        Scaleform::GFx::AS2::BlurFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  unsigned int v7; // esi
  float v8; // [esp+18h] [ebp+Ch]
  float v9; // [esp+18h] [ebp+Ch]
  float v10; // [esp+18h] [ebp+Ch]
  float v11; // [esp+18h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "blurX") )
  {
    v8 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    v9 = v8 * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurX = v9;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    v11 = v10 * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurY = v11;
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
