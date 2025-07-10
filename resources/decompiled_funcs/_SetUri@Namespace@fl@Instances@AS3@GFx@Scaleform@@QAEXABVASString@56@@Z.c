void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = value->pNode;
  ++value->pNode->RefCount;
  v4 = this->Uri.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Uri.pNode = pNode;
}
