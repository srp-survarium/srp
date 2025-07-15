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
  bool v10; // al
  bool v11; // al
  long double v12; // st7
  float v13; // [esp+20h] [ebp+Ch]
  float v14; // [esp+20h] [ebp+Ch]
  float v15; // [esp+20h] [ebp+Ch]
  float v16; // [esp+20h] [ebp+Ch]
  float v17; // [esp+20h] [ebp+Ch]
  float v18; // [esp+20h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "alpha") )
  {
    v13 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->Colors[0].Channels.Alpha = (int)(v13 * 255.0);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    v14 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    v15 = v14 * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurX = v15;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    v16 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    v17 = v16 * 20.0;
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurY = v17;
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "color") )
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
    v10 = Scaleform::GFx::AS2::Value::ToBool(val, (int)this, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(
      (Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16),
      v10);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v11 = Scaleform::GFx::AS2::Value::ToBool(val, (int)this, penv);
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
    v18 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->Strength = v18;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
}
