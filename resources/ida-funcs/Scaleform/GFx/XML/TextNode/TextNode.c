void __thiscall Scaleform::GFx::XML::TextNode::TextNode(
        Scaleform::GFx::XML::TextNode *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMString src; // [esp+8h] [ebp-4h] BYREF

  Scaleform::GFx::XML::DOMString::DOMString(&src, &value);
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::XML::TextNode_vtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  Scaleform::GFx::XML::DOMString::DOMString(&this->Value, &src);
  this->Parent = 0;
  this->PrevSibling = 0;
  this->NextSibling.pObject = 0;
  this->pShadow = 0;
  this->Type = 3;
  Scaleform::GFx::XML::DOMString::~DOMString(&src);
  this->__vftable = (Scaleform::GFx::XML::TextNode_vtbl *)&Scaleform::GFx::XML::TextNode::`vftable';
  Scaleform::GFx::XML::DOMString::~DOMString(&value);
}
