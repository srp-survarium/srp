void __thiscall Scaleform::GFx::AS3::MovieRoot::StickyVarNode::StickyVarNode(
        Scaleform::GFx::AS3::MovieRoot::StickyVarNode *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Value *value,
        bool permanent)
{
  Scaleform::GFx::ASStringNode *pNode; // eax

  this->__vftable = (Scaleform::GFx::AS3::MovieRoot::StickyVarNode_vtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
  pNode = name->pNode;
  this->Name = (Scaleform::GFx::ASString)name->pNode;
  ++pNode->RefCount;
  this->Permanent = permanent;
  this->pNext = 0;
  this->__vftable = (Scaleform::GFx::AS3::MovieRoot::StickyVarNode_vtbl *)&Scaleform::GFx::AS3::MovieRoot::StickyVarNode::`vftable';
  this->mValue = *value;
  if ( (value->Flags & 0x1F) > 9 )
  {
    if ( (value->Flags & 0x200) != 0 )
      ++value->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(value);
  }
}
