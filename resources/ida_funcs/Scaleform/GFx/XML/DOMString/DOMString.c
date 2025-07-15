void __thiscall Scaleform::GFx::XML::DOMString::DOMString(
        Scaleform::GFx::XML::DOMString *this,
        const Scaleform::GFx::XML::DOMString *src)
{
  Scaleform::GFx::XML::DOMStringNode *pNode; // edx

  pNode = src->pNode;
  this->pNode = src->pNode;
  ++pNode->RefCount;
}


void __thiscall Scaleform::GFx::XML::DOMString::DOMString(
        Scaleform::GFx::XML::DOMString *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  this->pNode = pnode;
  ++pnode->RefCount;
}
