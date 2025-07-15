void __thiscall Scaleform::GFx::MovieImpl::StickyVarNode::Assign(
        Scaleform::GFx::MovieImpl::StickyVarNode *this,
        const Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = node->Name.pNode;
  ++pNode->RefCount;
  v4 = this->Name.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Name.pNode = pNode;
  this->Permanent = node->Permanent;
}
