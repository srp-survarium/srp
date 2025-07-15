Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  const Scaleform::GFx::AS3::Multiname *v3; // edi
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v3 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         prop_name,
         (Scaleform::GFx::AS3::Value::V1U *)&ind)->Result )
    Scaleform::GFx::AS3::VectorBase<long>::RemoveAt(&this->V, result, ind);
  else
    Scaleform::GFx::AS3::Object::DeleteProperty(this, result, v3);
  return result;
}
