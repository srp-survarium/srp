Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::ClassTraits::Traits::GetName(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::ASString *result)
{
  this->ITraits.pObject->GetName(this->ITraits.pObject, result);
  return result;
}
