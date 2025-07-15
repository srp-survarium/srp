Scaleform::GFx::XML::DOMString *__thiscall Scaleform::GFx::XML::ObjectManager::EmptyString(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString *result)
{
  Scaleform::GFx::XML::DOMString::DOMString(result, &this->StringPool.EmptyStringNode);
  return result;
}
