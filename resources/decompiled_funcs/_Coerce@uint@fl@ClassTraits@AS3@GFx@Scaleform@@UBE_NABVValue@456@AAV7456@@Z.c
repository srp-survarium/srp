char __thiscall Scaleform::GFx::AS3::ClassTraits::fl::uint::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::uint *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v; // [esp+0h] [ebp-4h] BYREF

  v = (unsigned int)this;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(value, (Scaleform::GFx::AS3::CheckResult *)&value, &v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetUInt32(result, v);
  return 1;
}
