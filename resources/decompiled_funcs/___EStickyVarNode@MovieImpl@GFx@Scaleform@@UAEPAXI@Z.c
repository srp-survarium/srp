Scaleform::GFx::MovieImpl::StickyVarNode *__thiscall Scaleform::GFx::MovieImpl::StickyVarNode::`vector deleting destructor'(
        Scaleform::GFx::MovieImpl::StickyVarNode *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->Name.pNode;
  this->__vftable = (Scaleform::GFx::MovieImpl::StickyVarNode_vtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
