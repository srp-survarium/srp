Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  const Scaleform::GFx::AS3::Multiname *v3; // edi
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v3 = prop_name;
  if ( Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    if ( ind < this->SA.Length )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(&this->SA, ind, 1u, opRemove);
      v5 = result;
      result->Result = 1;
    }
    else
    {
      v5 = result;
      result->Result = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::DeleteProperty(this, result, v3);
    return result;
  }
  return v5;
}
