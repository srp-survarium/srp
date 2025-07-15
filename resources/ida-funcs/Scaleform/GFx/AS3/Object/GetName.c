Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Object::GetName(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::ASString *result)
{
  this->pTraits.pObject->GetName(this->pTraits.pObject, result);
  return result;
}
