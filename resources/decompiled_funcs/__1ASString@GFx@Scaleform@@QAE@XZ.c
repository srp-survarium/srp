void __thiscall Scaleform::GFx::ASString::~ASString(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
