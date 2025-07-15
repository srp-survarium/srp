void __thiscall Scaleform::GFx::AS2::MatrixObject::SetMatrix(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // edi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Value val; // [esp+8h] [ebp-10h] BYREF

  val.NV.NumberValue = m->M[0][0];
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = &penv->StringContext;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "a",
    &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][0];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "b", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[0][1];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "c", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][1];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "d", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[0][3];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "tx", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][3];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "ty", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
