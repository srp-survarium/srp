void __thiscall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // ebp
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-10h] BYREF

  val.NV.NumberValue = r->x1;
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = &penv->StringContext;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "x",
    &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = r->y1;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "y", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = r->x2 - r->x1;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "width", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = r->y2 - r->y1;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "height", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
