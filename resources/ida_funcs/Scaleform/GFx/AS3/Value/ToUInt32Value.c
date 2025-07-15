Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::ToUInt32Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // edi
  unsigned int r; // [esp+8h] [ebp-4h] BYREF

  v2 = result;
  result->Result = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         (Scaleform::GFx::AS3::Value::V1U *)&r)->Result )
    Scaleform::GFx::AS3::Value::SetUInt32(this, r);
  else
    v2->Result = 0;
  return v2;
}
