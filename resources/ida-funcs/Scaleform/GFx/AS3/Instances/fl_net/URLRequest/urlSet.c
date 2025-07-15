void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlSet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v5; // ecx

  pNode = value->pNode;
  ++value->pNode->RefCount;
  v5 = this->Url.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->Url.pNode = pNode;
}
