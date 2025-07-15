void __thiscall Scaleform::GFx::AS2::MatrixObject::SetMatrix(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // edi
  Scaleform::GFx::ASStringNode *p_StringContext; // esi
  Scaleform::GFx::AS2::Value v5; // [esp+8h] [ebp-10h] BYREF

  v5.NV.NumberValue = m->M[0][0];
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = (Scaleform::GFx::ASStringNode *)&penv->StringContext;
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&penv->StringContext,
    (char *)&stru_809F70,
    &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = m->M[1][0];
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "b", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = m->M[0][1];
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "c", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = m->M[1][1];
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "d", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = m->M[0][3];
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "tx", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  v5.NV.NumberValue = m->M[1][3];
  v5.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, p_StringContext, "ty", &v5);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
}
