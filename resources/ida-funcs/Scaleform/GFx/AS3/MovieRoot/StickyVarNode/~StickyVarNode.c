void __thiscall Scaleform::GFx::AS3::MovieRoot::StickyVarNode::~StickyVarNode(
        Scaleform::GFx::AS3::MovieRoot::StickyVarNode *this)
{
  Scaleform::GFx::AS3::Value *p_mValue; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx

  p_mValue = &this->mValue;
  if ( (this->mValue.Flags & 0x1F) > 9 )
  {
    if ( (this->mValue.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->mValue.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_mValue->Flags &= 0xFFFFFDE0;
      p_mValue->Bonus.pWeakProxy = 0;
      p_mValue->value.VS._1.VInt = 0;
      p_mValue->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_mValue);
    }
  }
  pNode = this->Name.pNode;
  this->__vftable = (Scaleform::GFx::AS3::MovieRoot::StickyVarNode_vtbl *)&Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
