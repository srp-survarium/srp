Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::AS2::MatrixObject::GetMatrix(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::Render::Matrix2x4<float> *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // ebx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Value val; // [esp+20h] [ebp-10h] BYREF

  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  p_StringContext = &penv->StringContext;
  result->M[1][3] = 0.0;
  val.T.Type = 0;
  result->M[1][1] = 1.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         &penv->StringContext,
         "a",
         &val) )
  {
    result->M[0][0] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  }
  else
  {
    result->M[0][0] = 1.0;
  }
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "b", &val) )
    result->M[1][0] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  else
    result->M[1][0] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "c", &val) )
    result->M[0][1] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  else
    result->M[0][1] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "d", &val) )
    result->M[1][1] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  else
    result->M[1][1] = 1.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "tx", &val) )
    result->M[0][3] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  else
    result->M[0][3] = 0.0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, p_StringContext, "ty", &val) )
    result->M[1][3] = Scaleform::GFx::AS2::Value::ToNumber(&val, penv);
  else
    result->M[1][3] = 0.0;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return result;
}
