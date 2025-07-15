Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v4; // edi
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         (Scaleform::GFx::AS3::Value::V1U *)&ind)->Result )
    Scaleform::GFx::AS3::VectorBase<unsigned long>::Set(
      (Scaleform::GFx::AS3::VectorBase<long> *)&this->V,
      result,
      ind,
      value,
      this->pTraits.pObject->pVM->TraitsUint.pObject);
  else
    Scaleform::GFx::AS3::Object::SetProperty(this, result, v4, value);
  return result;
}
