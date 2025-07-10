Scaleform::GFx::AS3::MovieRoot::StickyVarNode *__thiscall Scaleform::GFx::AS3::MovieRoot::StickyVarNode::`scalar deleting destructor'(
        Scaleform::GFx::AS3::MovieRoot::StickyVarNode *this,
        char a2)
{
  Scaleform::GFx::AS3::MovieRoot::StickyVarNode::~StickyVarNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
