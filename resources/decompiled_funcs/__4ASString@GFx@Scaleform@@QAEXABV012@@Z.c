void __thiscall Scaleform::GFx::ASString::operator=(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = src->pNode;
  ++src->pNode->RefCount;
  v4 = this->pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->pNode = pNode;
}
