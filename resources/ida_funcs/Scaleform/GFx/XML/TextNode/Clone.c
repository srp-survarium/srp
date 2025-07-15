Scaleform::GFx::XML::TextNode *__thiscall Scaleform::GFx::XML::TextNode::Clone(
        Scaleform::GFx::XML::TextNode *this,
        bool deep)
{
  Scaleform::GFx::XML::ObjectManager *pObject; // edi
  Scaleform::GFx::XML::TextNode *result; // eax
  Scaleform::GFx::XML::DOMString v5; // [esp-4h] [ebp-Ch] BYREF

  pObject = this->MemoryManager.pObject;
  v5.pNode = (Scaleform::GFx::XML::DOMStringNode *)this;
  Scaleform::GFx::XML::DOMString::DOMString(&v5, &this->Value);
  result = Scaleform::GFx::XML::ObjectManager::CreateTextNode(pObject, v5);
  result->Type = this->Type;
  return result;
}
