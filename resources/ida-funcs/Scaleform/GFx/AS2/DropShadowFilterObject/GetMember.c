char __thiscall Scaleform::GFx::AS2::DropShadowFilterObject::GetMember(
        Scaleform::GFx::AS2::DropShadowFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  unsigned __int8 Alpha; // al
  double v6; // st7
  char result; // al
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  double v9; // st7
  const Scaleform::Render::BlurFilterParams *v12; // eax
  long double Distance; // st7
  const Scaleform::Render::BlurFilterParams *v14; // eax
  const Scaleform::Render::BlurFilterParams *v15; // eax
  const Scaleform::Render::BlurFilterParams *v16; // eax
  const Scaleform::Render::BlurFilterParams *v17; // eax
  float v18; // [esp+24h] [ebp+8h]
  float v19; // [esp+24h] [ebp+8h]
  float BlurX; // [esp+24h] [ebp+8h]
  float BlurY; // [esp+24h] [ebp+8h]
  float v22; // [esp+28h] [ebp+Ch]
  float v23; // [esp+28h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "alpha") )
  {
    Alpha = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->Colors[0].Channels.Alpha;
    if ( Alpha )
      v6 = (double)Alpha / 255.0;
    else
      v6 = 0.0;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    v18 = v6;
    val->NV.NumberValue = v18;
    val->T.Type = 3;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "angle") )
  {
    pLocalFrame = this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame && pLocalFrame->RootIndex <= 5 )
      v9 = *(float *)&pLocalFrame->Caller.T.Type;
    else
      v9 = 0.0;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    v19 = v9;
    val->NV.NumberValue = v19;
    val->T.Type = 3;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    BlurX = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->BlurX;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    v22 = BlurX * 0.05000000074505806;
    val->NV.NumberValue = v22;
  }
  else
  {
    if ( !Scaleform::GFx::ASString::operator==(name, "blurY") )
    {
      if ( Scaleform::GFx::ASString::operator==(name, "color") )
      {
        v12 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
        Scaleform::GFx::AS2::Value::SetInt(val, v12->Colors[0].Raw & 0xFFFFFF);
        return 1;
      }
      if ( Scaleform::GFx::ASString::operator==(name, "distance") )
      {
        Distance = Scaleform::GFx::AS2::BitmapFilterObject::GetDistance((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
      }
      else
      {
        if ( Scaleform::GFx::ASString::operator==(name, "hideObject") )
        {
          v14 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetBool(val, (v14->Mode & 0x40) != 0);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(name, "inner") )
        {
          v15 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetBool(val, (v15->Mode & 0x20) != 0);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
        {
          v16 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetBool(val, (v16->Mode & 0x10) != 0);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(name, "quality") )
        {
          v17 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetInt(val, v17->Passes);
          return 1;
        }
        if ( !Scaleform::GFx::ASString::operator==(name, "strength") )
          return ((int (__thiscall *)(Scaleform::GFx::AS2::DropShadowFilterObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::DropShadowFilterObject)(
                   this,
                   &penv->StringContext,
                   name,
                   val);
        Distance = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->Strength;
      }
      Scaleform::GFx::AS2::Value::SetNumber(val, Distance);
      return 1;
    }
    BlurY = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::DropShadowFilterObject *)((char *)this - 16))->BlurY;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    v23 = BlurY * 0.05000000074505806;
    val->NV.NumberValue = v23;
  }
  return result;
}
