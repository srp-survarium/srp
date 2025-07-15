Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::ClassTraits::Traits::GetQualifiedName(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  this->ITraits.pObject->GetQualifiedName(this->ITraits.pObject, result, f);
  return result;
}
