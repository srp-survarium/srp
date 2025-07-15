Scaleform::GFx::XML::DOMString *__thiscall Scaleform::GFx::XML::ObjectManager::CreateString(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString *result,
        char *str,
        unsigned int len)
{
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(&this->StringPool, str, len);
  Scaleform::GFx::XML::DOMString::DOMString(result, StringNode);
  return result;
}
