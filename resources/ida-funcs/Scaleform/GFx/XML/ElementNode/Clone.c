Scaleform::GFx::XML::ElementNode *__thiscall Scaleform::GFx::XML::ElementNode::Clone(
        Scaleform::GFx::XML::ElementNode *this,
        BOOL deep)
{
  Scaleform::GFx::XML::ObjectManager *pObject; // edi
  Scaleform::GFx::XML::ElementNode *ElementNode; // edi
  Scaleform::GFx::XML::DOMString v6; // [esp-4h] [ebp-Ch] BYREF

  pObject = this->MemoryManager.pObject;
  v6.pNode = (Scaleform::GFx::XML::DOMStringNode *)this;
  Scaleform::GFx::XML::DOMString::DOMString(&v6, &this->Value);
  ElementNode = Scaleform::GFx::XML::ObjectManager::CreateElementNode(pObject, v6);
  Scaleform::GFx::XML::ElementNode::CloneHelper(this, ElementNode, deep);
  ElementNode->Type = this->Type;
  return ElementNode;
}
