char __thiscall Scaleform::GFx::AS2::RectangleObject::GetMember(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *p_v; // eax
  Scaleform::Render::Rect<double> v7; // [esp-24h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+1Ch] [ebp-20h] BYREF

  if ( !strcmp(name->pNode->pData, "left") )
  {
    r.x1 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    v.NV.NumberValue = r.x1;
    v.T.Type = 3;
    p_v = &v;
    goto LABEL_3;
  }
  if ( !strcmp(name->pNode->pData, "right") )
  {
    r.x2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    v.NV.NumberValue = r.x2;
    v.T.Type = 3;
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    if ( v.T.Type >= 5u )
      goto LABEL_14;
    return 1;
  }
  if ( !strcmp(name->pNode->pData, "top") )
  {
    r.y1 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    v.NV.NumberValue = r.y1;
    v.T.Type = 3;
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    if ( v.T.Type >= 5u )
      goto LABEL_14;
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "bottom") )
  {
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    v.NV.NumberValue = r.y2;
    v.T.Type = 3;
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    if ( v.T.Type >= 5u )
    {
LABEL_14:
      Scaleform::GFx::AS2::Value::DropRefs(&v);
      return 1;
    }
    return 1;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "topLeft") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    Scaleform::Render::Rect<double>::Rect<double>((Scaleform::Render::Rect<double> *)((char *)&v7.x1 + 4), &r);
    LODWORD(v7.x1) = &v;
    p_v = Scaleform::GFx::AS2::Rectangle_ComputeTopLeft(penv, v7);
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "bottomRight") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    Scaleform::Render::Rect<double>::Rect<double>((Scaleform::Render::Rect<double> *)((char *)&v7.x1 + 4), &r);
    LODWORD(v7.x1) = &v;
    p_v = Scaleform::GFx::AS2::Rectangle_ComputeBottomRight(penv, v7);
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "size") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 16),
      penv,
      &r);
    Scaleform::Render::Rect<double>::Rect<double>((Scaleform::Render::Rect<double> *)((char *)&v7.x1 + 4), &r);
    LODWORD(v7.x1) = &v;
    p_v = Scaleform::GFx::AS2::Rectangle_ComputeSize(penv, v7);
LABEL_3:
    Scaleform::GFx::AS2::Value::operator=(val, p_v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 1;
  }
  return ((int (__thiscall *)(Scaleform::GFx::AS2::RectangleObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::RectangleObject)(
           this,
           &penv->StringContext,
           name,
           val);
}
