void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v3; // edi
  unsigned int v4; // edx
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+Ch] [ebp-4h]

  v3.VInt = (char)Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(this, ind.Index);
  if ( (value->Flags & 0x1F) > 9 )
  {
    if ( (value->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(value);
  }
  v4 = value->Flags & 0xFFFFFFE2;
  value->value.VS._1 = v3;
  value->Flags = v4 | 2;
  value->value.VS._2 = v5;
}
