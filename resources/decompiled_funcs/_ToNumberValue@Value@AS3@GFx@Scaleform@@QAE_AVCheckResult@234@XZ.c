Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::ToNumberValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // esi
  long double resulta; // [esp+10h] [ebp-8h] BYREF

  v2 = result;
  result->Result = 1;
  Scaleform::GFx::AS3::Value::Convert2NumberInline(this, (Scaleform::GFx::AS3::CheckResult *)&result, &resulta);
  if ( (_BYTE)result )
    Scaleform::GFx::AS3::Value::SetNumber(this, resulta);
  else
    v2->Result = 0;
  return v2;
}
