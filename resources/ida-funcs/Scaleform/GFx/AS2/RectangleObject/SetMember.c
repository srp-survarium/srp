char __thiscall Scaleform::GFx::AS2::RectangleObject::SetMember(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Environment *v7; // esi
  Scaleform::GFx::AS2::RectangleObject *v8; // edi
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  long double y; // st7
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::Render::Point<double> pt; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+20h] [ebp-20h] BYREF

  if ( (flags->Flags & 4) != 0 )
    return 0;
  if ( !strcmp(name->pNode->pData, "left") )
  {
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    r.x1 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    return 1;
  }
  if ( !strcmp(name->pNode->pData, "top") )
  {
    r.x1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    r.y1 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "right") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    r.x2 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "bottom") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    r.y2 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "topLeft") )
  {
    v7 = penv;
    r.x1 = 0.0;
    r.y1 = 0.0;
    v8 = (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16);
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v8, penv, &r);
    v9 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
    if ( v9 )
    {
      Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v9, &pt);
      r.x1 = pt.x;
      r.y1 = pt.y;
    }
    goto LABEL_14;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "bottomRight") )
  {
    v7 = penv;
    r.x1 = 0.0;
    r.y1 = 0.0;
    v8 = (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16);
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v8, penv, &r);
    v10 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
    if ( !v10 )
    {
LABEL_14:
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v8, v7, &r);
      return 1;
    }
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v10, &pt);
    r.x2 = pt.x;
    y = pt.y;
LABEL_18:
    r.y2 = y;
    goto LABEL_14;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "size") )
  {
    v7 = penv;
    r.x1 = 0.0;
    r.y1 = 0.0;
    v8 = (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16);
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v8, penv, &r);
    v12 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
    if ( !v12 )
      goto LABEL_14;
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v12, &pt);
    r.x2 = pt.x + r.x1;
    y = r.y1 + pt.y;
    goto LABEL_18;
  }
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}
