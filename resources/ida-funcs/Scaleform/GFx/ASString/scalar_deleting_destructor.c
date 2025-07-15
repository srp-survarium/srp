Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::`scalar deleting destructor'(
        Scaleform::GFx::ASString *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
