void __thiscall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::ASStringNode *psc,
        const Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, "x", params);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "y", params + 1);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "width", params + 2);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "height", params + 3);
}


void __thiscall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // ebp
  Scaleform::GFx::ASStringNode *p_StringContext; // edi
  Scaleform::GFx::AS2::Value v5; // [esp+10h] [ebp-10h] BYREF

  v5.NV.NumberValue = r->x1;
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = (Scaleform::GFx::ASStringNode *)&penv->StringContext;
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&penv->StringContext,
    "x",
    &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = r->y1;
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "y", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = r->x2 - r->x1;
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "width", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = r->y2 - r->y1;
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "height", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
}
