char __thiscall Scaleform::GFx::AS3::ClassTraits::fl::Boolean::CoerceValue(
        Scaleform::GFx::AS3::ClassTraits::fl::Boolean *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  bool v3; // bl
  unsigned int v4; // edx
  Scaleform::GFx::AS3::Value::V1U v6; // [esp+8h] [ebp-8h]
  Scaleform::GFx::AS3::Value::V2U v7; // [esp+Ch] [ebp-4h]

  v3 = Scaleform::GFx::AS3::Value::Convert2Boolean(value);
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v6.VBool = v3;
  v4 = result->Flags & 0xFFFFFFE0 | 1;
  result->value.VS._1 = v6;
  result->Flags = v4;
  result->value.VS._2 = v7;
  return 1;
}
