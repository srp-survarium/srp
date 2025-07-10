Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  const Scaleform::GFx::AS3::Multiname *v3; // edi
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v3 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         prop_name,
         (Scaleform::GFx::AS3::Value::V1U *)&ind)->Result )
  {
    if ( ind < this->V.ValueA.Data.Size )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->V.ValueA,
        ind);
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
