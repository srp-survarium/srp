Scaleform::GFx::AS2::MovieRoot::StickyVarNode *__thiscall Scaleform::GFx::AS2::MovieRoot::StickyVarNode::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MovieRoot::StickyVarNode *this,
        char a2)
{
  bool v3; // cf
  Scaleform::GFx::AS2::Value *p_mValue; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v3 = this->mValue.T.Type < 5u;
  p_mValue = &this->mValue;
  if ( !v3 )
    Scaleform::GFx::AS2::Value::DropRefs(p_mValue);
  pNode = this->Name.pNode;
  this->__vftable = (Scaleform::GFx::AS2::MovieRoot::StickyVarNode_vtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
