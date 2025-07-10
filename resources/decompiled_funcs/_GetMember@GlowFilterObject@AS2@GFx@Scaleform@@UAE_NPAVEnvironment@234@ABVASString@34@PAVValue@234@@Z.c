char __thiscall Scaleform::GFx::AS2::GlowFilterObject::GetMember(
        Scaleform::GFx::AS2::GlowFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  unsigned __int8 Alpha; // al
  double v6; // st7
  char result; // al
  const Scaleform::Render::BlurFilterParams *v10; // eax
  const Scaleform::Render::BlurFilterParams *v11; // eax
  const Scaleform::Render::BlurFilterParams *v12; // eax
  const Scaleform::Render::BlurFilterParams *v13; // eax
  const Scaleform::Render::BlurFilterParams *v14; // eax
  float namec; // [esp+24h] [ebp+8h]
  float namea; // [esp+24h] [ebp+8h]
  float nameb; // [esp+24h] [ebp+8h]
  float vala; // [esp+28h] [ebp+Ch]
  float valb; // [esp+28h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "alpha") )
  {
    Alpha = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->Colors[0].Channels.Alpha;
    if ( Alpha )
      v6 = (double)Alpha / 255.0;
    else
      v6 = 0.0;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    namec = v6;
    val->NV.NumberValue = namec;
    val->T.Type = 3;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    namea = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurX;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    vala = namea * 0.05000000074505806;
    val->NV.NumberValue = vala;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    nameb = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16))->BlurY;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    valb = nameb * 0.05000000074505806;
    val->NV.NumberValue = valb;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, (const char *)&stru_9555EC) )
  {
    v10 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetInt(val, (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v10->Colors[0].Raw);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "inner") )
  {
    v11 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetBool(val, (v11->Mode & 0x20) != 0);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v12 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetBool(val, (v12->Mode & 0x10) != 0);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "quality") )
  {
    v13 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetInt(val, v13->Passes);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "strength") )
  {
    v14 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::GlowFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetNumber(val, v14->Strength);
    return 1;
  }
  else
  {
    return ((int (__thiscall *)(Scaleform::GFx::AS2::GlowFilterObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::GlowFilterObject)(
             this,
             &penv->StringContext,
             name,
             val);
  }
  return result;
}
