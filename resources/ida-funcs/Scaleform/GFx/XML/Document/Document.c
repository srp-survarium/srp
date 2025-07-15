void __thiscall Scaleform::GFx::XML::Document::Document(
        Scaleform::GFx::XML::Document *this,
        Scaleform::GFx::XML::ObjectManager *memMgr)
{
  Scaleform::GFx::XML::DOMStringNode *p_EmptyStringNode; // [esp-4h] [ebp-8h]

  Scaleform::GFx::XML::ElementNode::ElementNode(this, memMgr);
  p_EmptyStringNode = &this->MemoryManager.pObject->StringPool.EmptyStringNode;
  this->__vftable = (Scaleform::GFx::XML::Document_vtbl *)&Scaleform::GFx::XML::Document::`vftable';
  Scaleform::GFx::XML::DOMString::DOMString(&this->XMLVersion, p_EmptyStringNode);
  Scaleform::GFx::XML::DOMString::DOMString(&this->Encoding, &this->MemoryManager.pObject->StringPool.EmptyStringNode);
  this->Standalone = -1;
}
