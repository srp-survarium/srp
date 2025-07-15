Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::ASStringNode *v5; // ecx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // edi
  Scaleform::GFx::ASStringNode *pRCC; // ecx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Code.pNode;
  ++pNode->RefCount;
  v5 = (Scaleform::GFx::ASStringNode *)pObject[1].__vftable;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)pNode;
  v7 = this->Level.pNode;
  ++v7->RefCount;
  pRCC = (Scaleform::GFx::ASStringNode *)pObject[1]._pRCC;
  v6 = pRCC->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pRCC);
  pObject[1].pRCCRaw = (unsigned int)v7;
  return result;
}
