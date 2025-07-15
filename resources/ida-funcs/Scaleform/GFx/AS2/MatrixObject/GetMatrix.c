Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::AS2::MatrixObject::GetMatrix(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::Render::Matrix2x4<float> *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // ebx
  Scaleform::GFx::ASStringNode *p_StringContext; // edi
  Scaleform::GFx::AS2::Value v6; // [esp+10h] [ebp-10h] BYREF

  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  p_StringContext = (Scaleform::GFx::ASStringNode *)&penv->StringContext;
  result->M[1][3] = 0.0;
  v6.T.Type = 0;
  result->M[1][1] = 1.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         (Scaleform::GFx::ASStringNode *)&penv->StringContext,
         (char *)&stru_809F70,
         &v6) )
  {
    result->M[0][0] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  }
  else
  {
    result->M[0][0] = 1.0;
  }
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "b", &v6) )
    result->M[1][0] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  else
    result->M[1][0] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "c", &v6) )
    result->M[0][1] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  else
    result->M[0][1] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "d", &v6) )
    result->M[1][1] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  else
    result->M[1][1] = 1.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "tx", &v6) )
    result->M[0][3] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  else
    result->M[0][3] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "ty", &v6) )
    result->M[1][3] = Scaleform::GFx::AS2::Value::ToNumber(&v6, penv);
  else
    result->M[1][3] = 0.0;
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  return result;
}
