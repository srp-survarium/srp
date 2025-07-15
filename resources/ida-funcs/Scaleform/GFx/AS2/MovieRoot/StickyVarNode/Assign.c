void __thiscall Scaleform::GFx::AS2::MovieRoot::StickyVarNode::Assign(
        Scaleform::GFx::AS2::MovieRoot::StickyVarNode *this,
        const Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = node->Name.pNode;
  ++pNode->RefCount;
  v4 = this->Name.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Name.pNode = pNode;
  this->Permanent = node->Permanent;
  Scaleform::GFx::AS2::Value::operator=(&this->mValue, (const Scaleform::GFx::AS2::Value *)&node[1]);
}
