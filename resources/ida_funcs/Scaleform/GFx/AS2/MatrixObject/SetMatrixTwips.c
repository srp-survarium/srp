void __thiscall Scaleform::GFx::AS2::MatrixObject::SetMatrixTwips(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-10h] BYREF

  val.NV.NumberValue = m->M[0][0];
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, "a", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][0];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "b", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[0][1];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "c", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][1];
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "d", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[0][3] * 0.05;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "tx", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.NV.NumberValue = m->M[1][3] * 0.05;
  val.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "ty", &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
