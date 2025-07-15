Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *pRCC; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v7; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Text.pNode;
  ++pNode->RefCount;
  pRCC = (Scaleform::GFx::ASStringNode *)pObject[1]._pRCC;
  if ( pRCC->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pRCC);
  v7 = result;
  pObject[1].pRCCRaw = (unsigned int)pNode;
  return v7;
}
