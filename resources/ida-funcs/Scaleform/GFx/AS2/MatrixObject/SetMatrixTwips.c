void __thiscall Scaleform::GFx::AS2::MatrixObject::SetMatrixTwips(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::ASStringNode *psc,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::Value v4; // [esp+10h] [ebp-10h] BYREF

  v4.NV.NumberValue = m->M[0][0];
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (char *)&stru_809F70,
    &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
  v4.NV.NumberValue = m->M[1][0];
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "b", &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
  v4.NV.NumberValue = m->M[0][1];
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "c", &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
  v4.NV.NumberValue = m->M[1][1];
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "d", &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
  v4.NV.NumberValue = m->M[0][3] * 0.05;
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "tx", &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
  v4.NV.NumberValue = m->M[1][3] * 0.05;
  v4.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "ty", &v4);
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
}
