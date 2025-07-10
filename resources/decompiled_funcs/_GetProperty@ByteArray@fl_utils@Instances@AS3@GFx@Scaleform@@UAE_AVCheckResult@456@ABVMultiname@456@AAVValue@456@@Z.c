Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::GetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v4; // edi
  unsigned __int8 v6; // al
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    if ( ind >= this->Length )
    {
      v7 = result;
      result->Result = 0;
    }
    else
    {
      v6 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(this, ind);
      Scaleform::GFx::AS3::Value::SetUInt32(value, v6);
      v7 = result;
      result->Result = 1;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(this, result, v4, value);
    return result;
  }
  return v7;
}
