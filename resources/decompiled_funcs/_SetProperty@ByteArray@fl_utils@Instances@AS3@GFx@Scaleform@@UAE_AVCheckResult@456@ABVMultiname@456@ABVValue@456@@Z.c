Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // edi
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
           value,
           (Scaleform::GFx::AS3::CheckResult *)&value,
           (unsigned int *)&prop_name)->Result )
    {
      v7 = (unsigned __int8)prop_name;
      v8 = ind;
      if ( ind >= this->Length )
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, ind + 1);
      v6 = result;
      this->Data.Data.Data[v8] = v7;
      result->Result = 1;
    }
    else
    {
      v6 = result;
      result->Result = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::SetProperty(this, result, v4, value);
    return result;
  }
  return v6;
}
