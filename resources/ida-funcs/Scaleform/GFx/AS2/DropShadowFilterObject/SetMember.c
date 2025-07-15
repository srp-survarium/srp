char __thiscall Scaleform::GFx::AS2::DropShadowFilterObject::SetMember(
        Scaleform::GFx::AS2::DropShadowFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  unsigned int v7; // eax
  char v8; // al
  char v9; // al
  char v10; // al
  long double v11; // st7
  float a; // [esp+0h] [ebp-18h]
  float aa; // [esp+0h] [ebp-18h]
  float vala; // [esp+24h] [ebp+Ch]
  float valb; // [esp+24h] [ebp+Ch]
  float valc; // [esp+24h] [ebp+Ch]
  float vald; // [esp+24h] [ebp+Ch]
  float vale; // [esp+24h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "alpha") )
  {
    vala = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->Colors[0].Channels.Alpha = (int)(vala * 255.0);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "angle") )
  {
    a = (float)(__int16)Scaleform::GFx::AS2::Value::ToInt32(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetAngle(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      a);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    valb = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    valc = valb * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->BlurX = valc;
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "blurY") )
  {
    vald = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      vald);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, (const char *)&stru_9555EC) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToUInt32(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetColor(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      v7);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "distance") )
  {
    aa = (float)(__int16)Scaleform::GFx::AS2::Value::ToInt32(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      aa);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "hideObject") )
  {
    v8 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetHideObject(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      v8);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "inner") )
  {
    v9 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      v9);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      v10);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "quality") )
  {
    v11 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(
      (Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16),
      (__int64)v11);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "strength") )
  {
    vale = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->Strength = vale;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
}
