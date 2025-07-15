void __thiscall Scaleform::GFx::XML::ElementNode::ElementNode(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::ObjectManager *memMgr)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  Scaleform::GFx::XML::DOMString::DOMString(&this->Value, &memMgr->StringPool.EmptyStringNode);
  this->Parent = 0;
  this->PrevSibling = 0;
  this->NextSibling.pObject = 0;
  this->Type = 1;
  this->pShadow = 0;
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  Scaleform::GFx::XML::DOMString::DOMString(&this->Prefix, &memMgr->StringPool.EmptyStringNode);
  Scaleform::GFx::XML::DOMString::DOMString(&this->Namespace, &memMgr->StringPool.EmptyStringNode);
  this->FirstAttribute = 0;
  this->LastAttribute = 0;
  this->FirstChild.pObject = 0;
  this->LastChild = 0;
}


void __thiscall Scaleform::GFx::XML::ElementNode::ElementNode(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMString src; // [esp+10h] [ebp-4h] BYREF

  Scaleform::GFx::XML::DOMString::DOMString(&src, &value);
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  Scaleform::GFx::XML::DOMString::DOMString(&this->Value, &src);
  this->Parent = 0;
  this->PrevSibling = 0;
  this->NextSibling.pObject = 0;
  this->pShadow = 0;
  this->Type = 1;
  Scaleform::GFx::XML::DOMString::~DOMString(&src);
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  Scaleform::GFx::XML::DOMString::DOMString(&this->Prefix, &memMgr->StringPool.EmptyStringNode);
  Scaleform::GFx::XML::DOMString::DOMString(&this->Namespace, &memMgr->StringPool.EmptyStringNode);
  this->FirstAttribute = 0;
  this->LastAttribute = 0;
  this->FirstChild.pObject = 0;
  this->LastChild = 0;
  Scaleform::GFx::XML::DOMString::~DOMString(&value);
}
