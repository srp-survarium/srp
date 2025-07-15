char __thiscall Scaleform::GFx::AS2::GlowFilterObject::SetMember(
        Scaleform::GFx::AS2::GlowFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  unsigned int v7; // esi
  Scaleform::Render::BlurFilterParams *v8; // eax
  unsigned __int8 Alpha; // cl
  char v10; // al
  char v11; // al
  long double v12; // st7
  float vala; // [esp+20h] [ebp+Ch]
  float valb; // [esp+20h] [ebp+Ch]
  float valc; // [esp+20h] [ebp+Ch]
  float vald; // [esp+20h] [ebp+Ch]
  float vale; // [esp+20h] [ebp+Ch]
  float valf; // [esp+20h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "alpha") )
  {
    vala = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->Colors[0].Channels.Alpha = (int)(vala * 255.0);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    valb = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    valc = valb * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurX = valc;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    vald = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    vale = vald * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurY = vale;
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, (const char *)&stru_9555EC) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToUInt32(val, penv);
    v8 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Alpha = v8->Colors[0].Channels.Alpha;
    v8->Colors[0].Raw = v7;
    v8->Colors[0].Channels.Alpha = Alpha;
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "inner") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(
      (Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16),
      v10);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v11 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(
      (Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16),
      v11);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "quality") )
  {
    v12 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(
      (Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16),
      (__int64)v12);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "strength") )
  {
    valf = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->Strength = valf;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
}
