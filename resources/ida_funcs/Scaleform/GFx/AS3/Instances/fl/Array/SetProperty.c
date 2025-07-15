Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&this->SA, ind, value);
    v6 = result;
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::SetProperty(this, result, v4, value);
    return result;
  }
  return v6;
}
