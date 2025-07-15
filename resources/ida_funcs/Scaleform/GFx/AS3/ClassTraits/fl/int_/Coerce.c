char __thiscall Scaleform::GFx::AS3::ClassTraits::fl::int_::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::int_ *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  int v; // [esp+0h] [ebp-4h] BYREF

  v = (int)this;
  if ( !Scaleform::GFx::AS3::Value::Convert2Int32(value, (Scaleform::GFx::AS3::CheckResult *)&value, &v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetSInt32(result, v);
  return 1;
}
