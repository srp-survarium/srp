Scaleform::GFx::XML::ElementNode *__thiscall Scaleform::GFx::XML::ElementNode::`scalar deleting destructor'(
        Scaleform::GFx::XML::ElementNode *this,
        char a2)
{
  Scaleform::GFx::XML::ElementNode::~ElementNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
