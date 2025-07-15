void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::tabIndexSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::ASStringNode *v4; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> e; // [esp+4h] [ebp-4h] BYREF

  LOWORD(this->pDispObj.pObject[1].Depth) = (_WORD)value;
  value = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
            "tabIndexChange",
            0xEu,
            0);
  ++value->RefCount;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&e,
    (const Scaleform::GFx::ASString *)&value,
    1,
    0);
  v4 = value;
  --value->RefCount;
  if ( !v4->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(this, e.pObject, this->pDispObj.pObject);
  if ( e.pObject && ((int)e.pObject & 1) == 0 )
  {
    RefCount = e.pObject->RefCount;
    pObject = e.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      e.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
