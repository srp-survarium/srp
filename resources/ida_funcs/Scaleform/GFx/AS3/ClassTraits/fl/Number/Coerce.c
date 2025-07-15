char __thiscall Scaleform::GFx::AS3::ClassTraits::fl::Number::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::Number *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  long double v; // [esp+8h] [ebp-8h] BYREF

  if ( !Scaleform::GFx::AS3::Value::Convert2Number(value, (Scaleform::GFx::AS3::CheckResult *)&value, &v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetNumber(result, v);
  return 1;
}
