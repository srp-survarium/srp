Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::ToInt32Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v3; // eax
  Scaleform::GFx::AS3::CheckResult v4; // [esp+Bh] [ebp-5h] BYREF
  int r; // [esp+Ch] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::Value::Convert2Int32(this, &v4, (Scaleform::GFx::AS3::Value::V1U *)&r)->Result )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(this, r);
    v3 = result;
    result->Result = 1;
  }
  else
  {
    v3 = result;
    result->Result = 0;
  }
  return v3;
}
