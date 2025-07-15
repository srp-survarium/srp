void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::tabEnabledSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> e; // [esp+4h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  if ( LOBYTE(value.pNode) )
    pObject[1].Id.Id |= 0x60u;
  else
    pObject[1].Id.Id = pObject[1].Id.Id & 0xFFFFFF9F | 0x40;
  value.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                  "tabEnabledChange",
                  0x10u,
                  0);
  ++value.pNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&e,
    &value,
    1,
    0);
  pNode = value.pNode;
  --value.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(this, e.pObject, this->pDispObj.pObject);
  if ( e.pObject && ((int)e.pObject & 1) == 0 )
  {
    RefCount = e.pObject->RefCount;
    v7 = e.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      e.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
  }
}
