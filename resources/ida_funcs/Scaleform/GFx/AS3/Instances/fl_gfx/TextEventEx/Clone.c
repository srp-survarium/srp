Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx::Clone(
        Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // edi
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::ASStringNode *v5; // ecx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Text.pNode;
  ++pNode->RefCount;
  v5 = (Scaleform::GFx::ASStringNode *)pObject[1].__vftable;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)pNode;
  pObject[1].pRCCRaw = this->controllerIdx;
  pObject[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->buttonIdx;
  return result;
}
