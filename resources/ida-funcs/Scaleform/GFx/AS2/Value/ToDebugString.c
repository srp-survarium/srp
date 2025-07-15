Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Value::ToDebugString(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, (Scaleform::GFx::ASString)1);
  return result;
}
