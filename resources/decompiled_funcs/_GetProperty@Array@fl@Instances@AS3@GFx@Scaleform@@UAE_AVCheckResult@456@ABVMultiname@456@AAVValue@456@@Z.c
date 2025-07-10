Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v4; // edi
  const Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    v6 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, ind);
    Scaleform::GFx::AS3::Value::Assign(value, v6);
    v7 = result;
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(this, result, v4, value);
    return result;
  }
  return v7;
}
