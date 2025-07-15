char __thiscall Scaleform::GFx::AS2::BevelFilterObject::SetMember(
        Scaleform::GFx::AS2::BevelFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        float val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::Render::BlurFilterParams *v7; // eax
  Scaleform::Render::BlurFilterParams *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  char v11; // al
  long double v12; // st7
  bool v13; // al
  Scaleform::GFx::AS2::BitmapFilterObject *v14; // ecx
  Scaleform::Render::BlurFilterParams *v15; // eax
  Scaleform::Render::BlurFilterParams *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // ecx
  Scaleform::Render::BlurFilterParams *v19; // eax
  float a; // [esp+0h] [ebp-18h]
  float aa; // [esp+0h] [ebp-18h]

  if ( !strcmp(name->pNode->pData, "angle") )
  {
    LODWORD(val) = (__int16)Scaleform::GFx::AS2::Value::ToInt32((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    a = (float)SLODWORD(val);
    Scaleform::GFx::AS2::BitmapFilterObject::SetAngle((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16), a);
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    val = val * 20.0;
    v7 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    v7->BlurX = val;
    return 1;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    val = val * 20.0;
    v8 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    v8->BlurY = val;
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "distance") )
  {
    LODWORD(val) = (__int16)Scaleform::GFx::AS2::Value::ToInt32((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    aa = (float)SLODWORD(val);
    Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      aa);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "highlightAlpha") )
  {
    val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      val);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "highlightColor") )
  {
    v9 = Scaleform::GFx::AS2::Value::ToUInt32((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetColor((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16), v9);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "shadowAlpha") )
  {
    val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha2(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      val);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "shadowColor") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToUInt32((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetColor2(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      v10);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v11 = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      v11);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "quality") )
  {
    v12 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(
      (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16),
      (__int64)v12);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "type") )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(
      (Scaleform::GFx::AS2::Value *)LODWORD(val),
      (Scaleform::GFx::ASString *)&val,
      penv,
      -1,
      0);
    v13 = Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&val, "inner");
    v14 = (Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16);
    if ( v13 )
    {
      v15 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(v14);
      v15->Mode |= 0x20u;
    }
    else
    {
      v16 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(v14);
      v16->Mode &= ~0x20u;
    }
    v17 = (Scaleform::GFx::ASStringNode *)LODWORD(val);
    if ( (*(_DWORD *)(LODWORD(val) + 12))-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "strength") )
  {
    val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), penv);
    v19 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    v19->Strength = val;
    return 1;
  }
  else
  {
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, (Scaleform::GFx::AS2::Value *)LODWORD(val), flags);
  }
}
